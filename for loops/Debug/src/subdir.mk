################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/for\ loops.cpp 

OBJS += \
./src/for\ loops.o 

CPP_DEPS += \
./src/for\ loops.d 


# Each subdirectory must supply rules for building sources it contributes
src/for\ loops.o: ../src/for\ loops.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/for loops.d" -MT"src/for\ loops.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


