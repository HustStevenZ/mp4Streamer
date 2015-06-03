################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
all: playCommon

dependents:
	-cd /mnt/data/steven/workspace/2\ MGV/live/UsageEnvironment/Debug && $(MAKE) all
	-cd /mnt/data/steven/workspace/2\ MGV/live/groupsock/Debug && $(MAKE) all
	-cd /mnt/data/steven/workspace/2\ MGV/live/BasicUsageEnvironment/Debug && $(MAKE) all
	-cd /mnt/data/steven/workspace/2\ MGV/live/liveMedia/Debug && $(MAKE) all

# Tool invocations
playCommon: $(OBJS) $(USER_OBJS) /mnt/data/steven/workspace/2\ MGV/live/UsageEnvironment/Debug/libUsageEnvironment.a /mnt/data/steven/workspace/2\ MGV/live/groupsock/Debug/libgroupsock.a /mnt/data/steven/workspace/2\ MGV/live/BasicUsageEnvironment/Debug/libBasicUsageEnvironment.a /mnt/data/steven/workspace/2\ MGV/live/liveMedia/Debug/libliveMedia.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/mnt/data/steven/workspace/2 MGV/live/liveMedia/Debug" -L"/mnt/data/steven/workspace/2 MGV/live/BasicUsageEnvironment/Debug" -L"/mnt/data/steven/workspace/2 MGV/live/groupsock/Debug" -L"/mnt/data/steven/workspace/2 MGV/live/UsageEnvironment/Debug" -o "playCommon" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) playCommon
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/mnt/data/steven/workspace/2\ MGV/live/UsageEnvironment/Debug/libUsageEnvironment.a:
/mnt/data/steven/workspace/2\ MGV/live/groupsock/Debug/libgroupsock.a:
/mnt/data/steven/workspace/2\ MGV/live/BasicUsageEnvironment/Debug/libBasicUsageEnvironment.a:
/mnt/data/steven/workspace/2\ MGV/live/liveMedia/Debug/libliveMedia.a:

-include ../makefile.targets
