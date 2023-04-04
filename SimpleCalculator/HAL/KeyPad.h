


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "DIO_interface.h" 

/************************************ Config ******************************/
#define FIRST_OUTPUT    PINB0  
#define FIRST_INPUT     PINB4 
#define COLS     4
#define ROWS     4
#define NO_KEY  'N'

static U8 KeysArray[ROWS][COLS]={{'7','8','9','/'},
						         {'4','5','6','*'},
                                 {'1','2','3','-'},
						         {'C','0','=','+'}};	
							
/**************************************************************************/

U8 KEYPAD_Getkey(void);



#endif /* KEYPAD_H_ */