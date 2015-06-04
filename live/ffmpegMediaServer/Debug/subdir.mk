################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DynamicRTSPServer.cpp \
../ffmpeg_demux.cpp \
../ffmpeg_demuxed_elementary_stream.cpp \
../ffmpeg_rtsp_server.cpp \
../ffmpeg_server_demux.cpp \
../media_server.cpp 

OBJS += \
./DynamicRTSPServer.o \
./ffmpeg_demux.o \
./ffmpeg_demuxed_elementary_stream.o \
./ffmpeg_rtsp_server.o \
./ffmpeg_server_demux.o \
./media_server.o 

CPP_DEPS += \
./DynamicRTSPServer.d \
./ffmpeg_demux.d \
./ffmpeg_demuxed_elementary_stream.d \
./ffmpeg_rtsp_server.d \
./ffmpeg_server_demux.d \
./media_server.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/liveMedia" -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/groupsock" -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/UsageEnvironment" -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/BasicUsageEnvironment" -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/UsageEnvironment/include" -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/groupsock/include" -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/BasicUsageEnvironment/include" -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/liveMedia/include" -I"/mnt/data/steven/workspace/5_Samples/2_C/mp4Streamer/live/ffmpegMediaServer/subsession" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


