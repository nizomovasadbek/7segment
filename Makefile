CC=avr-gcc
BIN=main.elf
HEX=main.hex
SRC_DIR=src
SRC=$(shell find $(SRC_DIR) -type f -name '*.c')
CONVERT=avr-objcopy -j .text -j .data -O ihex
DEVICE=atmega32

all: $(BIN) $(HEX)

%.elf: $(SRC)
	$(CC) -mmcu=$(DEVICE) -Os $(SRC) -o $(BIN)
	$(CONVERT) $(BIN) $(HEX)
	
clean:
	$(RM) $(BIN) $(HEX)