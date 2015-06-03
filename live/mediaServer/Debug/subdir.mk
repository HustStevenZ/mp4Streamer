################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../DynamicRTSPServer.o \
../live555MediaServer.o 

CPP_SRCS += \
../DynamicRTSPServer.cpp \
../live555MediaServer.cpp 

OBJS += \
./DynamicRTSPServer.o \
./live555MediaServer.o 

CPP_DEPS += \
./DynamicRTSPServer.d \
./live555MediaServer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/mnt/data/steven/workspace/2 MGV/live/liveMedia" -I"/mnt/data/steven/workspace/2 MGV/live/BasicUsageEnvironment" -I"/mnt/data/steven/workspace/2 MGV/live/groupsock" -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment/include" -I"/mnt/data/steven/workspace/2 MGV/live/groupsock/include" -I"/mnt/data/steven/workspace/2 MGV/live/BasicUsageEnvironment/include" -I"/mnt/data/steven/workspace/2 MGV/live/liveMedia/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


