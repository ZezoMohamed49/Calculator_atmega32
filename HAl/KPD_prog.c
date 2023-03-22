/*
 * KPD_prog.c

 *
 *  Created on: Jan 29, 2021
 *      Author: 20101
 */
#include "LIB/type.h"
#include "DIO_Interface.h"
#define F_CPU 8000000UL
#include<avr/delay.h>
#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_prv.h"

static const u8 KPD_u8Arr[4][4]=
{
		{'1','2','3','+'},
		{'4','5','6','-'},
		{'7','8','9','/'},
		{'c','0','=','x'}
};

u8 KPD_u8GetPressedKey(void){
	u8 switchVal=NOT_PRESSED;
	u8 u8Col;
	u8 u8Row;

	for(u8Col=COL_BEGIN;u8Col<COL_NUM;u8Col++){

		DIO_vidSetPinVal(KPD_PORT,u8Col,DIO_LOW);

		for(u8Row=ROW_BEGIN;u8Row<ROW_NUM;u8Row++){

			if(DIO_getPinVal(KPD_PORT,u8Row)==DIO_LOW){
				switchVal=KPD_u8Arr[u8Row-4][u8Col];
				while(DIO_getPinVal(KPD_PORT,u8Row)==DIO_LOW);
				_delay_ms(50);
			}

		}
		DIO_vidSetPinVal(KPD_PORT,u8Col,DIO_HIGH);
	}
	return switchVal;
}

