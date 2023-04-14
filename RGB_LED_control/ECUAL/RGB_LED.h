


#ifndef RGB_LED_H_
#define RGB_LED_H_

#include "stdTYPES.h"
#include "Timers.h"


/***************************** config *****************************/
#define COLORS  71
#define RGB     3

#define RED  2
#define BLUE  1
#define GREEN  3
#define BLACK  0
#define WHITE  10
#define PINK   28

/*******************************************************************/


void RGB_LED_Init(void);

void RED_LED_SetColor(U8 color);




#endif /* RGB_LED_H_ */