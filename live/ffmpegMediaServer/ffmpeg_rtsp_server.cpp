/*
 * ffmpeg_rtsp_server.cpp
 *
 *  Created on: 2011-12-8
 *      Author: Administrator
 */

#include "DynamicRTSPServer.hh"
#include "liveMedia.hh"
#include "ffmpeg_demux.h"
#include "ffmpeg_server_demux.h"
#include "ffmpeg_rtsp_server.h"

FfmpegRTSPServer *FfmpegRTSPServer::CreateNew(
        UsageEnvironment & env,
        Port our_port,
        UserAuthenticationDatabase *uad /*= NULL*/,
        unsigned  reclamation_test_seconds /*= 65*/)
{
    int our_socket = setUpOurSocket(env, our_port);
    if (our_socket == -1) return NULL;

    return new FfmpegRTSPServer(env, our_socket, our_port, uad, reclamation_test_seconds);
}

FfmpegRTSPServer::FfmpegRTSPServer(
        UsageEnvironment & env,
        int our_socket,
        Port our_port,
        UserAuthenticationDatabase *uad,
        unsigned  reclamation_test_seconds):
        DynamicRTSPServer(env, our_socket, our_port, uad, reclamation_test_seconds)
{

}

FfmpegRTSPServer::~FfmpegRTSPServer() {
    // TODO Auto-generated destructor stub
}

static ServerMediaSession* createNewSMS(UsageEnvironment& env,
                    char const* fileName, FILE* fid); // forward

ServerMediaSession *FfmpegRTSPServer::lookupServerMediaSession(const char *streamName, Boolean isFirstLookupInSession)
{
    ServerMediaSession* sms = NULL;

    sms = DynamicRTSPServer::lookupServerMediaSession(streamName,isFirstLookupInSession);
    if (sms != NULL) {
        return sms;
    }

    // First, check whether the specified "streamName" exists as a local file:
    FILE* fid = fopen(streamName, "rb");
    Boolean fileExists = fid != NULL;

    // Next, check whether we already have a "ServerMediaSession" for this file:
    sms = RTSPServer::lookupServerMediaSession(streamName);
    Boolean smsExists = sms != NULL;

    // Handle the four possibilities for "fileExists" and "smsExists":
    if (!fileExists) {
        if (smsExists) {
            // "sms" was created for a file that no longer exists. Remove it:
            removeServerMediaSession(sms);
        }
        return NULL;
    } else {
        if (!smsExists) {
            // Create a new "ServerMediaSession" object for streaming from the named file.
            sms = createNewSMS(envir(), streamName, fid);
            addServerMediaSession(sms);
        }
        fclose(fid);
        return sms;
    }

}

#define NEW_SMS(description) do {\
char const* descStr = description\
    ", streamed by the LIVE555 Media Server";\
sms = ServerMediaSession::createNew(env, fileName, fileName, descStr);\
} while(0)


static ServerMediaSession* createNewSMS(UsageEnvironment& env,
        char const* fileName, FILE* /*fid*/) {
    // Use the file name extension to determine the type of "ServerMediaSession":
    char const* extension = strrchr(fileName, '.');
    if (extension == NULL) {
        return NULL;
    }
    ServerMediaSession* sms = NULL;
    Boolean const reuseSource = False;

    if (strcmp(extension, ".avi") == 0 ||
        strcmp(extension, ".mp4") == 0    ) {
        //use ffmpeg
        NEW_SMS("ffmpeg");
        FfmpegServerDemux* demux = FfmpegServerDemux::CreateNew(env, fileName, reuseSource);
        if (demux != NULL) {
            sms->addSubsession(demux->NewAudioServerMediaSubsession());
            sms->addSubsession(demux->NewVideoServerMediaSubsession());
        }
    }

    return sms;
}

