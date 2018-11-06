# Makefile for Compiling uClinux user-space application on STM32F4 target
# Includes STM32 standard peripheral driver library

# Cross compile settings  
CC = arm-uclinuxeabi-gcc
CFLAGS =  -static -mlittle-endian
CFLAGS += -mthumb -mcpu=cortex-m4 -msoft-float 
CFLAGS += -mthumb-interwork -mfloat-abi=soft
CFLAGS += -mfpu=fpv4-sp-d16
CFLAGS += -I../inc -I../CMSIS -I../CMSIS/Device/ST/STM32F4xx/Include -I../CMSIS/Include -I.
CFLAGS += -L../uclibc/lib/libc.a


# header files dependencies, add include files here
DEPS = gpio_control.h stm32f4xx_gpio.h stm32f4xx_rcc.h stm32f4xx.h system_stm32f4xx.h stm32f4xx_conf.h 
OBJ = gpio_control.o stm32f4xx_gpio.o stm32f4xx_rcc.o system_stm32f4xx.o 

# Compile C files before creating object files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# rule to generate executable
gpio: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

