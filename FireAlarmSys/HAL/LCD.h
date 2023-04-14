

#ifndef LCD_H_
#define LCD_H_

#include "STDTYPES.h"
#include "DIO_interface.h"

#define _4_BIT    4
#define _8_BIT    8

/********************************* pin config *************************/
#define  LCD_MODE        _4_BIT

#define  RS              PIND0
#define  EN              PIND1

#define  D7				 PINC0
#define  D6              PINC1
#define  D5              PINC2
#define  D4              PINC3
           
#define  LCD_PORT        PC

/********************************************************************/


void LCD_Init(void);

void LCD_Clear(void);
void LCD_WriteChar(U8 ch);
void LCD_WriteString(U8*str);
void LCD_WriteNumber(S32 num);
void LCD_WriteNumber_4D(U16 num);
void LCD_WriteBinary(U8 num);
void LCD_WriteHex(U8 num);
void LCD_GoTo(U8 line , U8 cell);
void LCD_GoToClear(U8 line ,U8 cell,U8 NumOfCells);
void LCD_GoToWriteString(U8 line ,U8 cell,U8* str);
void LCD_Create_Character(U8* pattern,U8 location);





#endif /* LCD_H_ */