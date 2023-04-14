


#ifndef FIREALARMSYS_H_
#define FIREALARMSYS_H_

#include "stdTYPES.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "Sensors.h"
#include "MOTOR.h"


/**************************************config********************************************/	

#define	RED_LED        PINA7
#define YELLOW_LED     PINA6
	
/***************************************************************************************/

void FireAlarAPP_start(void);


#endif /* FIREALARMSYS_H_ */