#include "7seg.h"

char parse(char digit){
	switch(digit){
		case 0x00:
			return 0b00111111;
		case 0x01:
			return 0b00000110;
		case 0x02:
			return 0b01011011;
		case 0x03:
			return 0b01001111;
		case 0x04:
			return 0b01100110;
		case 0x05:
			return 0b01101101;
		case 0x06:
			return 0b01111101;
		case 0x07:
			return digit;
		case 0x08:
			return 0b01111111;
		case 0x09:
			return 0b01101111;
		case 0x0a:
			return 0b01110111;
		case 0x0b:
			return 0b01111100;
		case 0x0c:
			return 0b00111001;
		case 0x0d:
			return 0b01011110;
		case 0x0e:
			return 0b01111001;
		case 0x0f:
			return 0b01110001;
	}

	return 0x00;
}
