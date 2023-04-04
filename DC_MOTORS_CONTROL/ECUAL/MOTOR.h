


#ifndef MOTOR_H_
#define MOTOR_H_

#include "DIO_interface.h"

/**************** pin config *********************************/
# define IN1_M1   PINC0
# define IN2_M1   PINC1
# define EN_M1    PINC2
# define EN_M2    PINC3
# define IN3_M2   PINC4
# define IN4_M2   PINC5
/*************************************************************/

typedef enum {
	MOTOR_1,
	MOTOR_2
	}EN_MOTOR_type;



void MOTOR_CW(EN_MOTOR_type motor);
void MOTOR_CCW(EN_MOTOR_type motor);
void MOTOR_Stop(EN_MOTOR_type motor);








#endif /* MOTOR_H_ */