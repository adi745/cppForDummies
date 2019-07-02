################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Floating\ Point\ Types.cpp 

OBJS += \
./src/Floating\ Point\ Types.o 

CPP_DEPS += \
./src/Floating\ Point\ Types.d 


# Each subdirectory must supply rules for building sources it contributes
src/Floating\ Point\ Types.o: ../src/Floating\ Point\ Types.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Floating Point Types.d" -MT"src/Floating\ Point\ Types.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


