################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/libs/Filters.cpp \
../src/libs/HarrisCorner.cpp \
../src/libs/POICompareMethods.cpp \
../src/libs/POICorrespondence.cpp 

OBJS += \
./src/libs/Filters.o \
./src/libs/HarrisCorner.o \
./src/libs/POICompareMethods.o \
./src/libs/POICorrespondence.o 

CPP_DEPS += \
./src/libs/Filters.d \
./src/libs/HarrisCorner.d \
./src/libs/POICompareMethods.d \
./src/libs/POICorrespondence.d 


# Each subdirectory must supply rules for building sources it contributes
src/libs/%.o: ../src/libs/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


