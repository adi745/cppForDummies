################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Prototypes\ and\ includes.cpp 

OBJS += \
./src/Prototypes\ and\ includes.o 

CPP_DEPS += \
./src/Prototypes\ and\ includes.d 


# Each subdirectory must supply rules for building sources it contributes
src/Prototypes\ and\ includes.o: ../src/Prototypes\ and\ includes.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Prototypes and includes.d" -MT"src/Prototypes\ and\ includes.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


