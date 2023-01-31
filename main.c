#include "main.h"

int main(void){
	DDRA = 0xff;
	DDRC |= (1 << LATCH1_ADDR)|(1 << LATCH2_ADDR)|(1 << LATCH3_ADDR)|(1 << LATCH4_ADDR);
	TCCR1B |= (1 << CS12)|(1 << CS10);
	unsigned int value = 0;

	while(1){
		if(TCNT1 >= 15535){
			value++;
			TCNT1 = 0x00;
			PORTA = parse(value);
			render(LATCH1_ADDR);
			if(value >= 10){
				PORTA = parse(value >> 4);
				render(LATCH2_ADDR);
				PORTA = parse(value >> 3);
				render(LATCH1_ADDR);
			}
		}
	}

	return 0;
}


void render(char address){
	PORTC |= (1 << address);
	_delay_ms(200);
	PORTC &= ~(1 << address);
}
