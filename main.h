#ifndef _MAIN_H
#define _MAIN_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "7seg.h"

#define LATCH1_ADDR 0x03
#define LATCH2_ADDR 0x02
#define LATCH3_ADDR 0x01
#define LATCH4_ADDR 0x00

void render(char);

#endif
