/*
 * FfmpegDemux.h
 *
 *  Created on: 2011-12-8
 *  Author: Liang Guangwei
 *
 *  use ffmpeg to demux file
 */

#ifndef FFMPEGDEMUX_H_
#define FFMPEGDEMUX_H_

#define MAX_STREAM_NUM 5

class FfmpegDemuxedElementaryStream;
class FfmpegDemux;

struct StreamInfo {
    char const* mine_type;
    unsigned int duration;
    unsigned char* extra_data;
    int extra_data_size;
    unsigned int codec_id;

    //audio parameter
    unsigned int sample_rate;
    unsigned int channels;
};

class FfmpegServerDemux: public Medium{
public:
    static FfmpegServerDemux* CreateNew(UsageEnvironment& env, char const* filename,
            Boolean reuse_source);

private:
    virtual ~FfmpegServerDemux();
    FfmpegServerDemux(UsageEnvironment& env, char const* filename,
            Boolean reuse_source);

public:
    FfmpegDemuxedElementaryStream* NewElementaryStream(
            unsigned client_session_id, u_int8_t stream_id);

    //
    //the follow tow functions called in class FfmpegDemux
    //
    FfmpegDemuxedElementaryStream* NewAudioStream();
    FfmpegDemuxedElementaryStream* NewVideoStream();

    ServerMediaSubsession* NewAudioServerMediaSubsession();
    ServerMediaSubsession* NewVideoServerMediaSubsession();

    char const* MIMEtype(int stream_id);
    const StreamInfo* GetStreamInfo(int stream_id);
private:
    ServerMediaSubsession* NewServerMediaSubsession(unsigned int type);
    //detect stream tags from file
    Boolean DetectedStream();

private:
    FramedSource *input_source_;
    Boolean reuse_source_;
    char const* filename_;

    FfmpegDemux *session0_demux_;
    FfmpegDemux *last_created_demux_;
    unsigned last_client_session_id_;

    int video_stream_id_;
    int audio_stream_id_;
    
    StreamInfo stream_[MAX_STREAM_NUM];
};

#endif /* FFMPEGDEMUX_H_ */
