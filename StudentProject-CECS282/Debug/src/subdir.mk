################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Student.cpp \
../src/StudentProject.cpp \
../src/myDate.cpp 

OBJS += \
./src/Student.o \
./src/StudentProject.o \
./src/myDate.o 

CPP_DEPS += \
./src/Student.d \
./src/StudentProject.d \
./src/myDate.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


