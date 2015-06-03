/*
 * ffmpeg_H264_server_media_subsession.h
 *
 *  Created on: 2011-12-8
 *      Author: Liang Guangwei
 */

#ifndef FFMPEG_H264_SERVER_MEDIA_SUBSESSION_H_
#define FFMPEG_H264_SERVER_MEDIA_SUBSESSION_H_

//though inherit from H264VideoFileServerMediaSubsession, we don't use the function
//about dealing file.
class FfmpegServerDemux;
class FfmpegH264ServerMediaSubsession: public H264VideoFileServerMediaSubsession{
public:
    static FfmpegH264ServerMediaSubsession* CreateNew(
            FfmpegServerDemux& demux, u_int8_t stream_id, Boolean reuse_sourc);

private:
    virtual ~FfmpegH264ServerMediaSubsession();
    FfmpegH264ServerMediaSubsession(
            FfmpegServerDemux& demux, u_int8_t stream_id, Boolean reuse_sourc);

protected:  //redefined virtual functions
    //
    virtual FramedSource* createNewStreamSource(unsigned clientSessionId,
            unsigned& estBitrate);
private:
    FfmpegServerDemux& ffmpeg_demux_;
    u_int8_t stream_id_;

};

#endif /* FFMPEG_H264_VIDEO_SERVER_MEDIA_SUBSESSION_H_ */
