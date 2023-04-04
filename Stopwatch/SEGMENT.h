
#ifndef SEGMENT_H_
#define SEGMENT_H_


#include "MemMap.h"
#include "STDTYPES.h"
#include "Utils.h"
/**************************************** PORT_CONFIG **************************************/

#define SEG_PORT   PORTC
#define SEG_PORT2  PORTD

/****************************************************************************************/
void Segment_Display(U8 num);
void Segment_Display_BCD(U8 num);
void Segment_Display_MUX(U8 num);
void Segment_Display_BCD_HEX(U8 num);
void Segment_Display_2Digit(U8 num);
void Segment_Display_BCD_2Digit(U8 num);






#endif /* SEGMENT_H_ */