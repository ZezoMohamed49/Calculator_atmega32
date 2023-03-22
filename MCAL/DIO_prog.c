/*
 * DIO_prog.c
 *
 *  Created on: Jan 22, 2021
 *      Author: 20101
 */
#include "LIB/type.h"
#include "DIO_prv.h"
#include "DIO_Interface.h"
#include "LIB/BIT_math.h"


void DIO_vidSetPinVal(u8 PortId, u8 PinId, u8 PinVal){
	if((PortId<=DIO_PORTD)&&(PinId<=DIO_PIN7)){
		if(PinVal==DIO_HIGH){
		switch(PortId){
		case DIO_PORTA:SET_BIT(PORTA_REG,PinId); break;
		case DIO_PORTB:SET_BIT(PORTB_REG,PinId); break;
		case DIO_PORTC:SET_BIT(PORTC_REG,PinId); break;
		case DIO_PORTD:SET_BIT(PORTD_REG,PinId); break;
		}


//

		}
		else if(PinVal==DIO_LOW){
			switch(PortId){
		case DIO_PORTA:CLR_BIT(PORTA_REG,PinId); break;
		case DIO_PORTB:CLR_BIT(PORTB_REG,PinId); break;
		case DIO_PORTC:CLR_BIT(PORTC_REG,PinId); break;
		case DIO_PORTD:CLR_BIT(PORTD_REG,PinId); break;
		}
		}
		else{
			//error
		}
	}
	else{
		//error
	}
}
void DIO_vidSetPinDir(u8 PortId, u8 PinId, u8 PinDir){
	if((PortId<=DIO_PORTD)&&(PinId<=DIO_PIN7)){
			if(PinDir==DIO_OUTPUT){
			switch(PortId){
			case DIO_PORTA:SET_BIT(DDRA_REG,PinId); break;
			case DIO_PORTB:SET_BIT(DDRB_REG,PinId); break;
			case DIO_PORTC:SET_BIT(DDRC_REG,PinId); break;
			case DIO_PORTD:SET_BIT(DDRD_REG,PinId); break;
			}
			}
			else if(PinDir==DIO_INPUT){
				switch(PortId){
			case DIO_PORTA:CLR_BIT(DDRA_REG,PinId); break;
			case DIO_PORTB:CLR_BIT(DDRB_REG,PinId); break;
			case DIO_PORTC:CLR_BIT(DDRC_REG,PinId); break;
			case DIO_PORTD:CLR_BIT(DDRD_REG,PinId); break;
			}
			}
			else{
				//error
			}
		}
		else{
			//error
		}
}
void DIO_vidSetPortVal(u8 PortId, u8 PortVal){
	if(PortId<=DIO_PORTD){
			switch(PortId){
			case DIO_PORTA: PORTA_REG=PortVal;break;
			case DIO_PORTB: PORTB_REG=PortVal;break;
			case DIO_PORTC: PORTC_REG=PortVal;break;
			case DIO_PORTD: PORTD_REG=PortVal;break;
			}
	}
			else{
				//error
			}


}
void DIO_vidSetPortDir(u8 PortId, u8 PortDir){
	if(PortId<=DIO_PORTD){
				switch(PortId){
				case DIO_PORTA: DDRA_REG=PortDir;break;
				case DIO_PORTB: DDRB_REG=PortDir;break;
				case DIO_PORTC: DDRC_REG=PortDir;break;
				case DIO_PORTD: DDRD_REG=PortDir;break;
				}
		}
				else{
					//error
				}

}
u8 DIO_getPinVal(u8 PortId, u8 PinId){

	u8 result=0xff;
	if((PortId<=DIO_PORTD)&&(PinId<=DIO_PIN7)){
		switch(PortId){
		case DIO_PORTA: result=GET_BIT(PINA_REG,PinId);break;
		case DIO_PORTB: result=GET_BIT(PINB_REG,PinId);break;
		case DIO_PORTC: result=GET_BIT(PINC_REG,PinId);break;
		case DIO_PORTD: result=GET_BIT(PIND_REG,PinId);break;
		}
	}
	else{
		//error
	}
	return result;
}


