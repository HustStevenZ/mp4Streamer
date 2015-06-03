/*
 * ffmpeg_mp3_server_media_subsession.cpp
 *
 *  Created on: 2011-12-8
 *      Author: Liang Guangwei
 */

#include "BasicUsageEnvironment.hh"
#include "liveMedia.hh"
#include "../ffmpeg_demux.h"
#include "../ffmpeg_server_demux.h"
#include "../ffmpeg_demuxed_elementary_stream.h"
#include "ffmpeg_mp3_server_media_subsession.h"


FfmpegMp3ServerMediaSubsession *FfmpegMp3ServerMediaSubsession::CreateNew(
        FfmpegServerDemux& demux, u_int8_t stream_id, Boolean reuse_source)
{
    return new FfmpegMp3ServerMediaSubsession(demux, stream_id, reuse_source);
}

FfmpegMp3ServerMediaSubsession::FfmpegMp3ServerMediaSubsession(
        FfmpegServerDemux& demux, u_int8_t stream_id, Boolean reuse_source):
        MP3AudioFileServerMediaSubsession(demux.envir() , NULL, reuse_source, False, NULL),
        ffmpeg_demux_(demux),
        stream_id_(stream_id)
{

}

FfmpegMp3ServerMediaSubsession::~FfmpegMp3ServerMediaSubsession() {
    // TODO Auto-generated destructor stub
}

FramedSource *FfmpegMp3ServerMediaSubsession::createNewStreamSource(
        unsigned  clientSessionId, unsigned  & estBitrate)
{
    FramedSource* source = ffmpeg_demux_.NewElementaryStream(clientSessionId, stream_id_);
    if (source == NULL)  return NULL;

    return createNewStreamSourceCommon(source, 0/*file size, temporary*/, estBitrate);  //TODO:
}

//we must override seekStreamSource function
void FfmpegMp3ServerMediaSubsession::seekStreamSource(FramedSource* inputSource, 
                                                      double& seekNPT, 
                                                      double /*streamDuration*/, 
                                                      u_int64_t& /*numBytes*/)
{
    //TODO: now do nothing
}
