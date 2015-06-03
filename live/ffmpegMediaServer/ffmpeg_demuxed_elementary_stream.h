/*
 * FfmpegDemuxedElementaryStream.h
 *
 *  Created on: 2011-12-8
 *      Author: Liang Guangwei
 */

#ifndef FFMPEGDEMUXEDELEMENTARYSTREAM_H_
#define FFMPEGDEMUXEDELEMENTARYSTREAM_H_
class FfmpegDemux;
class FfmpegDemuxedElementaryStream: public FramedSource {
public:
   static FfmpegDemuxedElementaryStream* CreateNew(
            UsageEnvironment& env,
            u_int8_t stream_id,
            FfmpegDemux& demux,
            char const* mine_type,
            unsigned duration);
private:
    virtual ~FfmpegDemuxedElementaryStream();
    FfmpegDemuxedElementaryStream(
            UsageEnvironment& env,
            u_int8_t stream_id,
            FfmpegDemux& demux,
            char const* mine_type,
            unsigned duration);

protected:  //redefined virtual functions
    virtual void doGetNextFrame();
    virtual void doStopGettingFrames();
    virtual char const* MIMEtype() const;

private:
    static void AfterGettingFrame(void* client_data,
                  unsigned frame_size, unsigned num_truncated_bytes,
                  struct timeval presentation_time,
                  unsigned duration_in_microseconds);

    void AfterGettingFrame1(unsigned frame_size, unsigned num_truncated_bytes,
                struct timeval presentation_time,
                unsigned duration_in_microseconds);
private:
    FfmpegDemux &ffmpeg_demux_;
    u_int8_t stream_id_;
    char const* mine_type_;
    unsigned duration_;
};

#endif /* FFMPEGDEMUXEDELEMENTARYSTREAM_H_ */
