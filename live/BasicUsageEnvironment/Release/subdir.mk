################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../BasicHashTable.o \
../BasicTaskScheduler.o \
../BasicTaskScheduler0.o \
../BasicUsageEnvironment.o \
../BasicUsageEnvironment0.o \
../DelayQueue.o 

CPP_SRCS += \
../BasicHashTable.cpp \
../BasicTaskScheduler.cpp \
../BasicTaskScheduler0.cpp \
../BasicUsageEnvironment.cpp \
../BasicUsageEnvironment0.cpp \
../DelayQueue.cpp 

C_SRCS += \
../main.c 

OBJS += \
./BasicHashTable.o \
./BasicTaskScheduler.o \
./BasicTaskScheduler0.o \
./BasicUsageEnvironment.o \
./BasicUsageEnvironment0.o \
./DelayQueue.o \
./main.o 

C_DEPS += \
./main.d 

CPP_DEPS += \
./BasicHashTable.d \
./BasicTaskScheduler.d \
./BasicTaskScheduler0.d \
./BasicUsageEnvironment.d \
./BasicUsageEnvironment0.d \
./DelayQueue.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment/include" -I"/mnt/data/steven/workspace/2 MGV/live/groupsock/include" -I"/mnt/data/steven/workspace/2 MGV/live/BasicUsageEnvironment/include" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/mnt/data/steven/workspace/2 MGV/live/groupsock" -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment" -I"/mnt/data/steven/workspace/2 MGV/live/groupsock/include" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


