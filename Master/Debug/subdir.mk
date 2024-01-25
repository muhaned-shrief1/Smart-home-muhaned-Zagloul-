################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../EEPROM.c \
../LCD.c \
../LED.c \
../SPI.c \
../keypad_driver.c \
../main.c \
../menu.c \
../timer_driver.c 

OBJS += \
./DIO.o \
./EEPROM.o \
./LCD.o \
./LED.o \
./SPI.o \
./keypad_driver.o \
./main.o \
./menu.o \
./timer_driver.o 

C_DEPS += \
./DIO.d \
./EEPROM.d \
./LCD.d \
./LED.d \
./SPI.d \
./keypad_driver.d \
./main.d \
./menu.d \
./timer_driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


