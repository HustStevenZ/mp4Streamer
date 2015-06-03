################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../openRTSP.cpp \
../playCommon.cpp 

OBJS += \
./openRTSP.o \
./playCommon.o 

CPP_DEPS += \
./openRTSP.d \
./playCommon.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment/include" -I"/mnt/data/steven/workspace/2 MGV/live/groupsock/include" -I"/mnt/data/steven/workspace/2 MGV/live/BasicUsageEnvironment/include" -I"/mnt/data/steven/workspace/2 MGV/live/liveMedia/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


