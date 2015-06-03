/*
 * ffmpeg_mpeg4_server_media_subsession.cpp
 *
 *  Created on: 2011-12-27
 *      Author: Liang Guangwei
 */
#include "BasicUsageEnvironment.hh"
#include "liveMedia.hh"
#include "../ffmpeg_demux.h"
#include "../ffmpeg_server_demux.h"
#include "../ffmpeg_demuxed_elementary_stream.h"
#include "ffmpeg_mpeg4_server_media_subsession.h"

FfmpegMPEG4ServerMediaSubsession *FfmpegMPEG4ServerMediaSubsession::CreateNew(
        FfmpegServerDemux & demux, u_int8_t stream_id, Boolean reuse_source) {
    return new FfmpegMPEG4ServerMediaSubsession(demux, stream_id, reuse_source);
}


FfmpegMPEG4ServerMediaSubsession::FfmpegMPEG4ServerMediaSubsession(
        FfmpegServerDemux & demux, u_int8_t stream_id, Boolean reuse_source):
        MPEG4VideoFileServerMediaSubsession(demux.envir(), NULL, reuse_source),
        ffmpeg_demux_(demux),
        stream_id_(stream_id){
}

FfmpegMPEG4ServerMediaSubsession::~FfmpegMPEG4ServerMediaSubsession() {
    // TODO Auto-generated destructor stub
}

FramedSource *FfmpegMPEG4ServerMediaSubsession::createNewStreamSource(
        unsigned  clientSessionId, unsigned  & estBitrate)
{
    estBitrate = 500; //kbps£¬estimate

    FramedSource* es = ffmpeg_demux_.NewElementaryStream(clientSessionId, stream_id_);
    if (es == NULL)  return NULL;

    // Create a framer for the Video Elementary Stream:
//    return MPEG4VideoStreamFramer::createNew(envir(), es);
    return MPEG4VideoStreamDiscreteFramer::createNew(envir(), es);
}



