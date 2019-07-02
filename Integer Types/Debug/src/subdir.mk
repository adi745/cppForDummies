################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Integer\ Types.cpp 

OBJS += \
./src/Integer\ Types.o 

CPP_DEPS += \
./src/Integer\ Types.d 


# Each subdirectory must supply rules for building sources it contributes
src/Integer\ Types.o: ../src/Integer\ Types.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Integer Types.d" -MT"src/Integer\ Types.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


