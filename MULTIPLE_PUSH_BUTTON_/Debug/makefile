################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := MULTIPLE_PUSH_BUTTON_
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MULTIPLE_PUSH_BUTTON_.elf \

MAP_FILES += \
MULTIPLE_PUSH_BUTTON_.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MULTIPLE_PUSH_BUTTON_.list \

OBJCOPY_HEX += \
MULTIPLE_PUSH_BUTTON_.hex \


# All Target
all: main-build

# Main-build Target
main-build: MULTIPLE_PUSH_BUTTON_.elf secondary-outputs

# Tool invocations
MULTIPLE_PUSH_BUTTON_.elf MULTIPLE_PUSH_BUTTON_.map: $(OBJS) $(USER_OBJS) E:\STM32_prgrm\MULTIPLE_PUSH_BUTTON_\STM32F401RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "MULTIPLE_PUSH_BUTTON_.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\STM32_prgrm\MULTIPLE_PUSH_BUTTON_\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MULTIPLE_PUSH_BUTTON_.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MULTIPLE_PUSH_BUTTON_.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MULTIPLE_PUSH_BUTTON_.list"
	@echo 'Finished building: $@'
	@echo ' '

MULTIPLE_PUSH_BUTTON_.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "MULTIPLE_PUSH_BUTTON_.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) MULTIPLE_PUSH_BUTTON_.elf MULTIPLE_PUSH_BUTTON_.hex MULTIPLE_PUSH_BUTTON_.list MULTIPLE_PUSH_BUTTON_.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
