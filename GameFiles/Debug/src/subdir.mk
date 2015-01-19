################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Character.cpp \
../src/Controll.cpp \
../src/Display.cpp \
../src/Enemy.cpp \
../src/Game.cpp \
../src/Hero.cpp \
../src/Map.cpp \
../src/MapTile.cpp 

OBJS += \
./src/Character.o \
./src/Controll.o \
./src/Display.o \
./src/Enemy.o \
./src/Game.o \
./src/Hero.o \
./src/Map.o \
./src/MapTile.o 

CPP_DEPS += \
./src/Character.d \
./src/Controll.d \
./src/Display.d \
./src/Enemy.d \
./src/Game.d \
./src/Hero.d \
./src/Map.d \
./src/MapTile.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


