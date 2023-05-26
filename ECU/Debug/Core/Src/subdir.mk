################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/InverterStartupControl.c \
../Core/Src/InverterStartupControl_data.c \
../Core/Src/adc.c \
../Core/Src/canal.c \
../Core/Src/canal_fc_messages.c \
../Core/Src/main.c \
../Core/Src/printf.c \
../Core/Src/rtscheduler.c \
../Core/Src/stm32f7xx_hal_msp.c \
../Core/Src/stm32f7xx_it.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f7xx.c \
../Core/Src/uart.c 

OBJS += \
./Core/Src/InverterStartupControl.o \
./Core/Src/InverterStartupControl_data.o \
./Core/Src/adc.o \
./Core/Src/canal.o \
./Core/Src/canal_fc_messages.o \
./Core/Src/main.o \
./Core/Src/printf.o \
./Core/Src/rtscheduler.o \
./Core/Src/stm32f7xx_hal_msp.o \
./Core/Src/stm32f7xx_it.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f7xx.o \
./Core/Src/uart.o 

C_DEPS += \
./Core/Src/InverterStartupControl.d \
./Core/Src/InverterStartupControl_data.d \
./Core/Src/adc.d \
./Core/Src/canal.d \
./Core/Src/canal_fc_messages.d \
./Core/Src/main.d \
./Core/Src/printf.d \
./Core/Src/rtscheduler.d \
./Core/Src/stm32f7xx_hal_msp.d \
./Core/Src/stm32f7xx_it.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f7xx.d \
./Core/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/InverterStartupControl.cyclo ./Core/Src/InverterStartupControl.d ./Core/Src/InverterStartupControl.o ./Core/Src/InverterStartupControl.su ./Core/Src/InverterStartupControl_data.cyclo ./Core/Src/InverterStartupControl_data.d ./Core/Src/InverterStartupControl_data.o ./Core/Src/InverterStartupControl_data.su ./Core/Src/adc.cyclo ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/canal.cyclo ./Core/Src/canal.d ./Core/Src/canal.o ./Core/Src/canal.su ./Core/Src/canal_fc_messages.cyclo ./Core/Src/canal_fc_messages.d ./Core/Src/canal_fc_messages.o ./Core/Src/canal_fc_messages.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/printf.cyclo ./Core/Src/printf.d ./Core/Src/printf.o ./Core/Src/printf.su ./Core/Src/rtscheduler.cyclo ./Core/Src/rtscheduler.d ./Core/Src/rtscheduler.o ./Core/Src/rtscheduler.su ./Core/Src/stm32f7xx_hal_msp.cyclo ./Core/Src/stm32f7xx_hal_msp.d ./Core/Src/stm32f7xx_hal_msp.o ./Core/Src/stm32f7xx_hal_msp.su ./Core/Src/stm32f7xx_it.cyclo ./Core/Src/stm32f7xx_it.d ./Core/Src/stm32f7xx_it.o ./Core/Src/stm32f7xx_it.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f7xx.cyclo ./Core/Src/system_stm32f7xx.d ./Core/Src/system_stm32f7xx.o ./Core/Src/system_stm32f7xx.su ./Core/Src/uart.cyclo ./Core/Src/uart.d ./Core/Src/uart.o ./Core/Src/uart.su

.PHONY: clean-Core-2f-Src

