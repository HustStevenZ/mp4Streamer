/*
 * ffmpeg_mpeg4_server_media_subsession.h
 *
 *  Created on: 2011-12-27
 *      Author: Liang Guangwei
 */

#ifndef FFMPEG_MPEG4_SERVER_MEDIA_SUBSESSION_H_
#define FFMPEG_MPEG4_SERVER_MEDIA_SUBSESSION_H_

class FfmpegMPEG4ServerMediaSubsession: public MPEG4VideoFileServerMediaSubsession {
public:
    static FfmpegMPEG4ServerMediaSubsession* CreateNew(
            FfmpegServerDemux& demux, u_int8_t stream_id, Boolean reuse_source);

private:
    virtual ~FfmpegMPEG4ServerMediaSubsession();
    FfmpegMPEG4ServerMediaSubsession(
            FfmpegServerDemux& demux, u_int8_t stream_id, Boolean reuse_source);

protected:  //redefined virtual functions
    virtual FramedSource* createNewStreamSource(unsigned clientSessionId,
            unsigned& estBitrate);

private:
    FfmpegServerDemux& ffmpeg_demux_;
    u_int8_t stream_id_;
};

#endif /* FFMPEG_MPEG4_SERVER_MEDIA_SUBSESSION_H_ */
