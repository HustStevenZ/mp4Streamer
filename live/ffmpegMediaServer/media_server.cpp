/*
 * media_server.cpp
 *
 *  Created on: 2011-12-8
 *      Author: Liang Guangwei
 */

#include <BasicUsageEnvironment.hh>
#include "liveMedia.hh"
#include "ffmpeg_media.h"
#include "ffmpeg_rtsp_server.h"

int main()
{
    TaskScheduler* scheduler = NULL;
    UsageEnvironment* env = NULL;
//    FfmpegRTSPServer* rtspServer = NULL;
    RTSPServer* rtspServer = NULL;

    //create task scheduler
    scheduler = BasicTaskScheduler::createNew();

    //create interactive environment
    env = BasicUsageEnvironment::createNew(*scheduler);

    //create RTSP server
    rtspServer = FfmpegRTSPServer::CreateNew(*env,554);  //554 port
//    rtspServer = DynamicRTSPServer::createNew(*env,554,NULL);
    if(rtspServer == NULL)
    {
        rtspServer = FfmpegRTSPServer::CreateNew(*env,8554);  //if 554 port be used, use 8554 port
//        rtspServer = DynamicRTSPServer::createNew(*env,8554,NULL);
    }

    if(rtspServer == NULL)
    {
    	*env<<"Failed to setup Server \n \t";
    	return -1;
    }
    //display server address
    *env << "Play streams from this server using the URL\n\t"
         << rtspServer->rtspURLPrefix() << "<filename>.\n";

    //enter event loop
    env->taskScheduler().doEventLoop(); // does not return

    return 0;
}


