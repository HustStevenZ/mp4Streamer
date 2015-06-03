/*
 * ffmpeg_mp3_server_media_subsession.h
 *
 *  Created on: 2011-12-8
 *      Author: Administrator
 */

#ifndef FFMPEG_MP3_SERVER_MEDIA_SUBSESSION_H_
#define FFMPEG_MP3_SERVER_MEDIA_SUBSESSION_H_

class FfmpegMp3ServerMediaSubsession: public MP3AudioFileServerMediaSubsession{
public:
    static FfmpegMp3ServerMediaSubsession* CreateNew(
            FfmpegServerDemux& demux,
            u_int8_t stream_id,
            Boolean reuse_source);

private:
    FfmpegMp3ServerMediaSubsession(
            FfmpegServerDemux& demux,
            u_int8_t stream_id,
            Boolean reuse_source);
    virtual ~FfmpegMp3ServerMediaSubsession();

protected:  //redefined virtual functions
    virtual FramedSource* createNewStreamSource(unsigned clientSessionId,
                            unsigned& estBitrate);
    virtual void seekStreamSource(FramedSource* inputSource, double& seekNPT, double /*streamDuration*/, u_int64_t& /*numBytes*/);

private:
    FfmpegServerDemux& ffmpeg_demux_;
    u_int8_t stream_id_;
};

#endif /* FFMPEG_MP3_SERVER_MEDIA_SUBSESSION_H_ */
