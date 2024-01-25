################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_driver.c \
../DIO.c \
../LED.c \
../SERVOM_program.c \
../SPI.c \
../TMR1_program.c \
../main.c \
../timer_driver.c 

OBJS += \
./ADC_driver.o \
./DIO.o \
./LED.o \
./SERVOM_program.o \
./SPI.o \
./TMR1_program.o \
./main.o \
./timer_driver.o 

C_DEPS += \
./ADC_driver.d \
./DIO.d \
./LED.d \
./SERVOM_program.d \
./SPI.d \
./TMR1_program.d \
./main.d \
./timer_driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


