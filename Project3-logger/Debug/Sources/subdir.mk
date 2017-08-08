################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/circbuf.c \
../Sources/conversion.c \
../Sources/dma.c \
../Sources/log.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/profiling.c \
../Sources/project2.c \
../Sources/project3.c \
../Sources/rtc.c \
../Sources/uart.c 

OBJS += \
./Sources/circbuf.o \
./Sources/conversion.o \
./Sources/dma.o \
./Sources/log.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/profiling.o \
./Sources/project2.o \
./Sources/project3.o \
./Sources/rtc.o \
./Sources/uart.o 

C_DEPS += \
./Sources/circbuf.d \
./Sources/conversion.d \
./Sources/dma.d \
./Sources/log.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/profiling.d \
./Sources/project2.d \
./Sources/project3.d \
./Sources/rtc.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


