# --- Microcontroller and Compiler Settings ---
MCU = 16F877A
CC = xc8-cc
CFLAGS = -mcpu=$(MCU) -Os -mdfp=/home/demo/microchip_packs/PIC16F_DFP/xc8

# --- Include Directories (Where your .h files live) ---
INCLUDES = -IAPP -IHAL/LED -IMCAL/GPIO -ISERVICES

# --- Source Files (Where your .c files live) ---
SRCS = APP/main.c \
       HAL/LED/LED.c \
       MCAL/GPIO/GPIO.c

# --- Output Name ---
TARGET = firmware.hex

# --- Build Rules ---
all: $(TARGET)

$(TARGET): $(SRCS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET)

clean:
	rm -f *.hex *.elf *.cmf *.hxl *.sym *.sdb *.o *.p1 *.d *.s *.lst *.rlf __eeprom.* startup.*