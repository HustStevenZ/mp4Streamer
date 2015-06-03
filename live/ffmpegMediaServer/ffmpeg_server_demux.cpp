/*
 * FfmpegDemux.cpp
 *
 *  Created on: 2011-12-8
 *      Author: Liang Guangwei
 */

#include "BasicUsageEnvironment.hh"
#include "liveMedia.hh"
#include "ffmpeg_demuxed_elementary_stream.h"
#include "subsession/ffmpeg_server_media_subsession.h"
#include "ffmpeg_demux.h"
#include "ffmpeg_server_demux.h"
#include <iostream>
#include <cstdio>
#include <cstring>
extern "C" {
#include "libavutil/avutil.h"
#include "libavformat/avformat.h"
}

/*
 * just for compatible with the old ffmpeg version
 */
#define AVMEDIA_TYPE_VIDEO 0
#define AVMEDIA_TYPE_AUDIO 1

//#define EX_DEBUG

FfmpegServerDemux *FfmpegServerDemux::CreateNew(UsageEnvironment& env,
        char const* filename, Boolean reuse_source) {
    return new FfmpegServerDemux(env, filename, reuse_source);
}

FfmpegServerDemux::~FfmpegServerDemux() {
    Medium::close(session0_demux_);
    delete[] filename_;

    for (int i = 0; i < MAX_STREAM_NUM; ++i) {
        delete[] stream_[i].extra_data;
    }
}

FfmpegServerDemux::FfmpegServerDemux(UsageEnvironment& env,
        char const* file_name, Boolean reuse_source) :
    Medium(env), reuse_source_(reuse_source) {
    filename_ = strDup(file_name);

    session0_demux_ = NULL;
    last_created_demux_ = NULL;
    last_client_session_id_ = ~0;

    video_stream_id_ = -1;
    audio_stream_id_ = -1;

    std::memset(&stream_[0], 0, sizeof(StreamInfo) * MAX_STREAM_NUM);
    for (int i = 0; i < MAX_STREAM_NUM; ++i) {

        stream_[i].codec_id = CODEC_ID_NONE;
        stream_[i].channels = 1;
    }
}

FfmpegDemuxedElementaryStream *FfmpegServerDemux::NewElementaryStream(
        unsigned client_session_id, u_int8_t stream_id) {
    FfmpegDemux* demux_to_use = NULL;

    if (client_session_id == 0) {
        // 'Session 0' is treated especially, because its audio & video streams
        // are created and destroyed one-at-a-time, rather than both streams being
        // created, and then (later) both streams being destroyed (as is the case
        // for other ('real') session ids).  Because of this, a separate demux is
        // used for session 0, and its deletion is managed by us, rather than
        // happening automatically.
        if (session0_demux_ == NULL) {
            session0_demux_ = FfmpegDemux::CreateNew(envir(), filename_, False);
        }
        demux_to_use = session0_demux_;
    } else {
        // First, check whether this is a new client session.  If so, create a new
        // demux for it:
        if (client_session_id != last_client_session_id_) {
            last_created_demux_ = FfmpegDemux::CreateNew(envir(), filename_, True);
            // Note: We tell the demux to delete itself when its last
            // elementary stream is deleted.
            last_client_session_id_ = client_session_id;
            // Note: This code relies upon the fact that the creation of streams for
            // different client sessions do not overlap - so one "MPEG1or2Demux" is used
            // at a time.
        }
        demux_to_use = last_created_demux_;
    }

    if (demux_to_use == NULL)
        return NULL; // shouldn't happen

    return demux_to_use->NewElementaryStream(stream_id,
            stream_[stream_id].mine_type, stream_[stream_id].duration);
}

ServerMediaSubsession *FfmpegServerDemux::NewAudioServerMediaSubsession() {
    return NewServerMediaSubsession(AVMEDIA_TYPE_AUDIO);
}

ServerMediaSubsession *FfmpegServerDemux::NewVideoServerMediaSubsession() {
    return NewServerMediaSubsession(AVMEDIA_TYPE_VIDEO);
}

ServerMediaSubsession *FfmpegServerDemux::NewServerMediaSubsession(
        unsigned int type) {
    ServerMediaSubsession *sms = NULL;
    int stream_id = -1;

    //first time, we should found video and audio stream
    if (video_stream_id_ == -1) {
        if (!DetectedStream()) {
            return NULL;
        }
    }

    if (type == AVMEDIA_TYPE_VIDEO) {
        stream_id = video_stream_id_;
    } else {
        stream_id = audio_stream_id_;
    }

    //now, create subsessions
    switch (stream_[stream_id].codec_id) {
    case CODEC_ID_H264:
        stream_[stream_id].mine_type = "video/MPEG";
        sms = FfmpegH264ServerMediaSubsession::CreateNew(*this, stream_id,
                False);
        break;

    case CODEC_ID_MP3:
        stream_[stream_id].mine_type = "audio/MPEG";
        //every mp3 frame contains 1152 samales
        stream_[stream_id].duration = (1152 * 1000000)
                / stream_[stream_id].sample_rate;
        sms
                = FfmpegMp3ServerMediaSubsession::CreateNew(*this, stream_id,
                        False);
        break;

    case CODEC_ID_AAC:
        stream_[stream_id].mine_type = "audio/MPEG";
        //every aac frame contains 1024 sampales
        stream_[stream_id].duration = (1024 * 1000000)
                / stream_[stream_id].sample_rate;
        sms = FfmpegAACServerMediaSubession::CreateNew(*this, stream_id, False);
        break;

    case CODEC_ID_MPEG4:
        stream_[stream_id].mine_type = "video/MPEG";
        sms = FfmpegMPEG4ServerMediaSubsession::CreateNew(*this, stream_id,
                False);
        break;
        //TODO: create other subsessions

    default:
        //can not find required stream
        envir() << "can not find video or audio stream\n";
    }
    return sms;
}

Boolean FfmpegServerDemux::DetectedStream() {
    struct AVFormatContext *format_ctx = NULL;

    av_register_all();

    //open file
    if (avformat_open_input (&format_ctx, filename_, NULL, NULL) != 0) {
        return False;
    }

    //find stream
    if (avformat_find_stream_info(format_ctx,NULL) < 0) {
        return False;
    }

    AVCodecContext *codec = NULL;

    //find first video stream
    for (unsigned int i = 0; i < format_ctx->nb_streams; ++i) {
        codec = format_ctx->streams[i]->codec;
        if (codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            //            video_tag_ = codec->codec_id; // codec->codec_tag;
            video_stream_id_ = i;

            //video sream information
            stream_[i].codec_id = codec->codec_id;
            stream_[i].extra_data_size = codec->extradata_size;
            stream_[i].extra_data
                    = new unsigned char[stream_[i].extra_data_size + 1];
            std::memcpy(stream_[i].extra_data, codec->extradata,
                    codec->extradata_size);
            stream_[i].extra_data[stream_[i].extra_data_size] = 0;

            int framerate = format_ctx->streams[i]->r_frame_rate.num
                    / format_ctx->streams[i]->r_frame_rate.den;
            stream_[i].duration = 1000000 / framerate;

#ifdef EX_DEBUG
            envir() << "video stream information:\n";
            envir() << "stream :" << i << "\n";
            envir() << "frame rate:" << framerate << "\n";
            envir() << "duration : " << stream_[i].duration << "\n";
#endif

            break;
        }
    }

    //find first audio stream
    for (unsigned int i = 0; i < format_ctx->nb_streams; ++i) {
        codec = format_ctx->streams[i]->codec;
        if (codec->codec_type == AVMEDIA_TYPE_AUDIO) {
            //            audio_tag_ = codec->codec_id; // codec->codec_tag;
            audio_stream_id_ = i;

            //audio stream information
            stream_[i].codec_id = codec->codec_id;
            stream_[i].channels = codec->channels;
            stream_[i].sample_rate = codec->sample_rate;
            stream_[i].extra_data_size = codec->extradata_size;
            stream_[i].extra_data
                    = new unsigned char[stream_[i].extra_data_size + 1];
            memcpy(stream_[i].extra_data, codec->extradata,
                    codec->extradata_size);
            stream_[i].extra_data[stream_[i].extra_data_size] = 0;
            //duration set later

#ifdef EX_DEBUG
            envir() << "audio stream information:\n";
            envir() << "stream No.:" << i << "\n";
            envir() << "channels: " << stream_[i].channels << "\n";
            envir() << "sample rate:  " << stream_[i].sample_rate << "\n";
#endif

            break;
        }
    }

    //close file
    avformat_close_input(&format_ctx);

    return True;
}

char const* FfmpegServerDemux::MIMEtype(int stream_id) {
    return stream_[stream_id].mine_type;
}

const StreamInfo* FfmpegServerDemux::GetStreamInfo(int stream_id) {
    return &stream_[stream_id];
}

