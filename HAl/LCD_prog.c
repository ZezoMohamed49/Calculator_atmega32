/*
 * LCD_prog.c
 *
 *  Created on: Jan 23, 2021
 *      Author: 20101
 */
#include "LIB/type.h"
#include "DIO_Interface.h"
#include "LCD_interface.h"
#define F_CPU 8000000UL
#include<avr/delay.h>
#include "LCD_config.h"


void LCD_vidInit(void){
	_delay_ms(30);
	LCD_vidSendCommand(LCD_FUNCSET_8BIT);

	_delay_ms(1);
	LCD_vidSendCommand(LCD_DISPON_CURSON );

	_delay_ms(1);
	LCD_vidSendCommand(LCD_CLR);
	_delay_ms(10);
	LCD_vidSendCommand(LCD_ENTRYMODE);
	_delay_ms(2);

}
void LCD_vidSendCommand(u8 u8Cmd){
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);

	DIO_vidSetPortVal(LCD_DATA_PORT,u8Cmd);

	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

	_delay_ms(5);
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(10);

}
void LCD_vidSendChar(u8 u8Char){
	DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);
		DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);
		DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);

		DIO_vidSetPortVal(LCD_DATA_PORT,u8Char);

		DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

		_delay_ms(5);
		DIO_vidSetPinVal(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
		_delay_ms(10);
}
void LCD_vidWriteStr(u8* pu8Char){
	u8 i=0;
	while(pu8Char[i]!=0){
		LCD_vidSendChar(pu8Char[i++]);
	}
}
void LCD_vidGoToXY(u8 x,u8 y){
	switch(x){
	case 1: LCD_vidSendCommand(y+127); break;
	case 2: LCD_vidSendCommand(y+191); break;
	}

}
void LCD_vidSendCustomChar(u8* customChar,u8 index){
	u8 i;
	LCD_vidSendCommand((0x40|(index*8)));
	for(i=0;i<8;i++){
	LCD_vidSendChar(customChar[i]);
	}

	LCD_vidSendCommand(LCD_HOME);
}
void LCD_vidWriteCustomChar(u8 index,u8 x,u8 y){
	LCD_vidGoToXY(x,y);
	LCD_vidSendChar(index);
}
