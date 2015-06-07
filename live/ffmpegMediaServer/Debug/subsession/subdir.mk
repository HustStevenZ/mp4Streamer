################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../subsession/ffmpeg_aac_server_media_subsession.cpp \
../subsession/ffmpeg_h264_server_media_subsession.cpp \
../subsession/ffmpeg_mp3_server_media_subsession.cpp \
../subsession/ffmpeg_mpeg4_server_media_subsession.cpp 

OBJS += \
./subsession/ffmpeg_aac_server_media_subsession.o \
./subsession/ffmpeg_h264_server_media_subsession.o \
./subsession/ffmpeg_mp3_server_media_subsession.o \
./subsession/ffmpeg_mpeg4_server_media_subsession.o 

CPP_DEPS += \
./subsession/ffmpeg_aac_server_media_subsession.d \
./subsession/ffmpeg_h264_server_media_subsession.d \
./subsession/ffmpeg_mp3_server_media_subsession.d \
./subsession/ffmpeg_mpeg4_server_media_subsession.d 


# Each subdirectory must supply rules for building sources it contributes
subsession/%.o: ../subsession/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/liveMedia" -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/groupsock" -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/UsageEnvironment" -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/BasicUsageEnvironment" -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/UsageEnvironment/include" -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/groupsock/include" -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/BasicUsageEnvironment/include" -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/liveMedia/include" -I"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/ffmpegMediaServer/subsession" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


