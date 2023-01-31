#include "main.h"

int main(void){
	DDRA = 0xff;
	DDRC |= (1 << LATCH1_ADDR)|(1 << LATCH2_ADDR)|(1 << LATCH3_ADDR)|(1 << LATCH4_ADDR);
	char address[] = { LATCH1_ADDR, LATCH2_ADDR, LATCH3_ADDR, LATCH4_ADDR };
	TCCR1B |= (1 << CS12)|(1 << CS10);
	uint16_t value = 0;
	uint8_t second, third, forth;

	while(1){
		if(value >= 9999){
			value = 0;
		}
		if(TCNT1 >= 4000){

			if(value == 9){
				value = -1;
				PORTA = parse(++second);
				render(LATCH2_ADDR);
				if(second == 9){
					second = 0;
					third++;
					PORTA = parse(second);
					render(LATCH2_ADDR);
					PORTA = parse(third);
					render(LATCH3_ADDR);
					if(third == 9){
						third=0;
						forth++;
						PORTA = parse(third);
						render(LATCH3_ADDR);
						PORTA = parse(forth);
						render(LATCH4_ADDR);
						if(forth == 9 && third == 9 && second == 9 && value == 9){
							value = 0;
							second = 0;
							third = 0;
							forth = 0;
							PORTA = parse(0x00);
							PORTC = parse(0x0f);
							_delay_ms(2);
							PORTC = parse(0x00);
						}
					}
				}
			}
			value++;
			PORTA = parse(value);
			render(LATCH1_ADDR);
			TCNT1 = 0x00;
		}
	}

	return 0;
}


void render(char address){
	PORTC |= (1 << address);
	_delay_ms(2);
	PORTC &= ~(1 << address);
}
