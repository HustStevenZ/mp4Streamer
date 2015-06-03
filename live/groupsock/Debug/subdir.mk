################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../GroupEId.o \
../Groupsock.o \
../GroupsockHelper.o \
../IOHandlers.o \
../NetAddress.o \
../NetInterface.o \
../inet.o 

CPP_SRCS += \
../GroupEId.cpp \
../Groupsock.cpp \
../GroupsockHelper.cpp \
../IOHandlers.cpp \
../NetAddress.cpp \
../NetInterface.cpp 

C_SRCS += \
../inet.c \
../main.c 

OBJS += \
./GroupEId.o \
./Groupsock.o \
./GroupsockHelper.o \
./IOHandlers.o \
./NetAddress.o \
./NetInterface.o \
./inet.o \
./main.o 

C_DEPS += \
./inet.d \
./main.d 

CPP_DEPS += \
./GroupEId.d \
./Groupsock.d \
./GroupsockHelper.d \
./IOHandlers.d \
./NetAddress.d \
./NetInterface.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment" -I"/mnt/data/steven/workspace/2 MGV/live/groupsock/include" -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment/include" -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment" -I"/mnt/data/steven/workspace/2 MGV/live/groupsock/include" -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


