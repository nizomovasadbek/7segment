CC=avr-gcc
DEVICE=atmega32
CONVERT=avr-objcopy -j .text -j .data -O ihex
BINS=main.elf
HEX=main.hex
SRC=$(wildcard *.c)

all: $(BINS) $(HEX)

%.elf: %.c
	$(CC) -mmcu=$(DEVICE) -Os $(SRC) -o $(BINS)
	$(CONVERT) $(BINS) $(HEX)
	
clean:
	$(RM) $(BINS) $(HEX)