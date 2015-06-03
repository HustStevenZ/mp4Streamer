################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../HashTable.o \
../UsageEnvironment.o \
../strDup.o 

CPP_SRCS += \
../HashTable.cpp \
../UsageEnvironment.cpp \
../strDup.cpp 

C_SRCS += \
../main.c 

OBJS += \
./HashTable.o \
./UsageEnvironment.o \
./main.o \
./strDup.o 

C_DEPS += \
./main.d 

CPP_DEPS += \
./HashTable.d \
./UsageEnvironment.d \
./strDup.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment/include" -I"/mnt/data/steven/workspace/2 MGV/live/groupsock/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


