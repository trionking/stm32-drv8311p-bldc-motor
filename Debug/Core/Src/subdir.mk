################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc_func.c \
../Core/Src/ads8638.c \
../Core/Src/ads8638_diag.c \
../Core/Src/drv8311.c \
../Core/Src/main.c \
../Core/Src/ring_buffer.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c \
../Core/Src/user_com.c \
../Core/Src/user_def.c 

OBJS += \
./Core/Src/adc_func.o \
./Core/Src/ads8638.o \
./Core/Src/ads8638_diag.o \
./Core/Src/drv8311.o \
./Core/Src/main.o \
./Core/Src/ring_buffer.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o \
./Core/Src/user_com.o \
./Core/Src/user_def.o 

C_DEPS += \
./Core/Src/adc_func.d \
./Core/Src/ads8638.d \
./Core/Src/ads8638_diag.d \
./Core/Src/drv8311.d \
./Core/Src/main.d \
./Core/Src/ring_buffer.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d \
./Core/Src/user_com.d \
./Core/Src/user_def.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adc_func.cyclo ./Core/Src/adc_func.d ./Core/Src/adc_func.o ./Core/Src/adc_func.su ./Core/Src/ads8638.cyclo ./Core/Src/ads8638.d ./Core/Src/ads8638.o ./Core/Src/ads8638.su ./Core/Src/ads8638_diag.cyclo ./Core/Src/ads8638_diag.d ./Core/Src/ads8638_diag.o ./Core/Src/ads8638_diag.su ./Core/Src/drv8311.cyclo ./Core/Src/drv8311.d ./Core/Src/drv8311.o ./Core/Src/drv8311.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/ring_buffer.cyclo ./Core/Src/ring_buffer.d ./Core/Src/ring_buffer.o ./Core/Src/ring_buffer.su ./Core/Src/stm32h7xx_hal_msp.cyclo ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.cyclo ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.cyclo ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su ./Core/Src/user_com.cyclo ./Core/Src/user_com.d ./Core/Src/user_com.o ./Core/Src/user_com.su ./Core/Src/user_def.cyclo ./Core/Src/user_def.d ./Core/Src/user_def.o ./Core/Src/user_def.su

.PHONY: clean-Core-2f-Src

