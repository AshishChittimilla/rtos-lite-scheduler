
PROJECT = rtos-lite-scheduler
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall -O0 -g -std=c99
LDFLAGS = -TSTM32F446RE_FLASH.ld -Wl,--gc-sections
LIBS = -lc -lm -lnosys

SRCS = main.c scheduler.c tasks.c init_peripherals.c error.c
OBJS = $(SRCS:.c=.o)

all: $(PROJECT).elf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PROJECT).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)

clean:
	rm -f *.o *.elf
