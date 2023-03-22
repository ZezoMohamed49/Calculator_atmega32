/*
 * LCD_interface.h
 *
 *  Created on: Jan 23, 2021
 *      Author: 20101
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/***********************************************************************/
/***** LCD control commands***********/
#define LCD_CLR                 0x01
#define LCD_HOME                0x02
#define LCD_ENTRYMODE           0x06
#define LCD_DISPLAYOFF          0x08
#define LCD_DISPON_CURSON       0x0E
#define LCD_FUNCRESET           0x30
#define LCD_FUNCSET_8BIT        0x38
#define LCD_SETCUROR            0x80
#define LCD_DISPON_CURSEBLINK   0x0F
#define LCD_DISPON_CURSEOFF     0x0C


/*****************PUBLIC FUNCTIONS**********/
void LCD_vidInit(void);
void LCD_vidSendCommand(u8 u8Cmd);
void LCD_vidSendChar(u8 u8Char);
void LCD_vidWriteStr(u8* pu8Char);
void LCD_vidGoToXY(u8 x,u8 y);
void LCD_vidSendCustomChar(u8* cusCharArr,u8 index);
void LCD_vidWriteCustomChar(u8 index,u8 x,u8 y);

#endif /* LCD_INTERFACE_H_ */
