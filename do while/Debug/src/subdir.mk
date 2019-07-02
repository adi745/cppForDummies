################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/do\ while.cpp 

OBJS += \
./src/do\ while.o 

CPP_DEPS += \
./src/do\ while.d 


# Each subdirectory must supply rules for building sources it contributes
src/do\ while.o: ../src/do\ while.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/do while.d" -MT"src/do\ while.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


