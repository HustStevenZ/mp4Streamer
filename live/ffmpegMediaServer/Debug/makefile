################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subsession/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ffmpegMediaServer

dependents:
	-cd /home/zsq/workspace/9_C_CPP/mp4Streamer/live/BasicUsageEnvironment/Release && $(MAKE) all
	-cd /home/zsq/workspace/9_C_CPP/mp4Streamer/live/UsageEnvironment/Release && $(MAKE) all
	-cd /home/zsq/workspace/9_C_CPP/mp4Streamer/live/groupsock/Release && $(MAKE) all
	-cd /home/zsq/workspace/9_C_CPP/mp4Streamer/live/liveMedia/Release && $(MAKE) all

# Tool invocations
ffmpegMediaServer: $(OBJS) $(USER_OBJS) /home/zsq/workspace/9_C_CPP/mp4Streamer/live/BasicUsageEnvironment/Release/libBasicUsageEnvironment.a /home/zsq/workspace/9_C_CPP/mp4Streamer/live/UsageEnvironment/Release/libUsageEnvironment.a /home/zsq/workspace/9_C_CPP/mp4Streamer/live/groupsock/Release/libgroupsock.a /home/zsq/workspace/9_C_CPP/mp4Streamer/live/liveMedia/Release/libliveMedia.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/liveMedia/Release" -L"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/BasicUsageEnvironment/Release" -L"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/groupsock/Release" -L"/home/zsq/workspace/9_C_CPP/mp4Streamer/live/UsageEnvironment/Release" -o "ffmpegMediaServer" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) ffmpegMediaServer
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/zsq/workspace/9_C_CPP/mp4Streamer/live/BasicUsageEnvironment/Release/libBasicUsageEnvironment.a:
/home/zsq/workspace/9_C_CPP/mp4Streamer/live/UsageEnvironment/Release/libUsageEnvironment.a:
/home/zsq/workspace/9_C_CPP/mp4Streamer/live/groupsock/Release/libgroupsock.a:
/home/zsq/workspace/9_C_CPP/mp4Streamer/live/liveMedia/Release/libliveMedia.a:

-include ../makefile.targets
