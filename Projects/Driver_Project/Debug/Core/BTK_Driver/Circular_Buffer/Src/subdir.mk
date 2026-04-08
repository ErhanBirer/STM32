################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/BTK_Driver/Circular_Buffer/Src/circual_buffer.c 

OBJS += \
./Core/BTK_Driver/Circular_Buffer/Src/circual_buffer.o 

C_DEPS += \
./Core/BTK_Driver/Circular_Buffer/Src/circual_buffer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/BTK_Driver/Circular_Buffer/Src/%.o Core/BTK_Driver/Circular_Buffer/Src/%.su Core/BTK_Driver/Circular_Buffer/Src/%.cyclo: ../Core/BTK_Driver/Circular_Buffer/Src/%.c Core/BTK_Driver/Circular_Buffer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I"D:/STM32CubeIDE_1.18.1/workspace/BTK_Project/Core/BTK_Driver/software_timer/Inc" -I"D:/STM32CubeIDE_1.18.1/workspace/BTK_Project/Core/BTK_Driver/LCD_DRİVER/Inc" -I"D:/STM32CubeIDE_1.18.1/workspace/BTK_Project/Core/BTK_Driver/Circular_Buffer/Inc" -I"D:/STM32CubeIDE_1.18.1/workspace/BTK_Project/Core/BTK_Driver/uart_driver/Inc" -I"D:/STM32CubeIDE_1.18.1/workspace/BTK_Project/Core/BTK_Driver/dma_driver/Inc" -I"D:/STM32CubeIDE_1.18.1/workspace/BTK_Project/Core/BTK_Driver/IO_Driver/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-BTK_Driver-2f-Circular_Buffer-2f-Src

clean-Core-2f-BTK_Driver-2f-Circular_Buffer-2f-Src:
	-$(RM) ./Core/BTK_Driver/Circular_Buffer/Src/circual_buffer.cyclo ./Core/BTK_Driver/Circular_Buffer/Src/circual_buffer.d ./Core/BTK_Driver/Circular_Buffer/Src/circual_buffer.o ./Core/BTK_Driver/Circular_Buffer/Src/circual_buffer.su

.PHONY: clean-Core-2f-BTK_Driver-2f-Circular_Buffer-2f-Src

