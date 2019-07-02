################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Outputing\ Text.cpp 

OBJS += \
./src/Outputing\ Text.o 

CPP_DEPS += \
./src/Outputing\ Text.d 


# Each subdirectory must supply rules for building sources it contributes
src/Outputing\ Text.o: ../src/Outputing\ Text.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Outputing Text.d" -MT"src/Outputing\ Text.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


