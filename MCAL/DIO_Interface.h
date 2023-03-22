/*
 * DIO_Interface.h
 *
 *  Created on: Jan 22, 2021
 *      Author: 20101
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/*****************************************************/
/******************Public_Funs************************/
/*****************************************************/

void DIO_vidSetPinVal(u8 PortId, u8 PinId, u8 PinVal);
void DIO_vidSetPinDir(u8 PortId, u8 PinId, u8 PinDir);
void DIO_vidSetPortVal(u8 PortId, u8 PortVal);
void DIO_vidSetPortDir(u8 PortId, u8 PortDir);
u8 DIO_getPinVal(u8 PortId, u8 PinId);

/*****************************************************/
/******************Public_Macros**********************/
/*****************************************************/
/* output status */
#define DIO_HIGH 1
#define DIO_LOW  0

#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0x00
/* Direction status */
#define DIO_INPUT 0
#define DIO_OUTPUT 1

#define DIO_PORT_INPUT 0x00
#define DIO_PORT_OUTPUT 0xFF

/* Ports IDs */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
/* pINS IDs */
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7
#endif /* DIO_INTERFACE_H_ */
