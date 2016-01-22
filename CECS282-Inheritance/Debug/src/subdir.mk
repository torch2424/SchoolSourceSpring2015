################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Inheritance.cpp \
../src/animal.cpp \
../src/bear.cpp \
../src/bird.cpp \
../src/chicken.cpp \
../src/eagle.cpp \
../src/hyena.cpp \
../src/lion.cpp \
../src/lizard.cpp \
../src/mammal.cpp \
../src/reptile.cpp \
../src/snake.cpp 

OBJS += \
./src/Inheritance.o \
./src/animal.o \
./src/bear.o \
./src/bird.o \
./src/chicken.o \
./src/eagle.o \
./src/hyena.o \
./src/lion.o \
./src/lizard.o \
./src/mammal.o \
./src/reptile.o \
./src/snake.o 

CPP_DEPS += \
./src/Inheritance.d \
./src/animal.d \
./src/bear.d \
./src/bird.d \
./src/chicken.d \
./src/eagle.d \
./src/hyena.d \
./src/lion.d \
./src/lizard.d \
./src/mammal.d \
./src/reptile.d \
./src/snake.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


