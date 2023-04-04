

#ifndef DC_MOTORS_APP_H_
#define DC_MOTORS_APP_H_

#include "MOTOR.h"

/********************************************* buttons config **********************************************************/
#define BUTTON_1 PINA0  // move forward
#define BUTTON_2 PINA1  // move right
#define BUTTON_3 PINA2  // move left
#define BUTTON_4 PINA3  // move backward

/***********************************************************************************************************************/

void DC_motorsAPP_start(void);


#endif /* DC_MOTORS_APP_H_ */