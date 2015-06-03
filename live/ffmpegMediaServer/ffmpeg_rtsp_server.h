/*
 * ffmpeg_rtsp_server.h
 *
 *  Created on: 2011-12-8
 *      Author: Administrator
 */

#ifndef FFMPEG_RTSP_SERVER_H_
#define FFMPEG_RTSP_SERVER_H_
#include "DynamicRTSPServer.hh"
class FfmpegRTSPServer: public DynamicRTSPServer{
public:
    static FfmpegRTSPServer* CreateNew(UsageEnvironment& env, Port our_port,
            UserAuthenticationDatabase* uad = NULL,
            unsigned reclamation_test_seconds = 65);
private:
    FfmpegRTSPServer(UsageEnvironment& env, int our_socket, Port our_port,
            UserAuthenticationDatabase* auth_database, unsigned reclamation_test_seconds);
    virtual ~FfmpegRTSPServer();

protected: // redefined virtual functions
  virtual ServerMediaSession* lookupServerMediaSession(char const* stream_name, Boolean isFirstLookupInSession);
};

#endif /* FFMPEG_RTSP_SERVER_H_ */
