
#include "DC_motors_APP.h"

void DC_motorsAPP_start(void){
	
	// move forward
	if (!DIO_ReadPin(BUTTON_1))
	{
		 MOTOR_CW(MOTOR_1);
		 MOTOR_CW(MOTOR_2);
		 while(!DIO_ReadPin(BUTTON_1));
		 MOTOR_Stop(MOTOR_1);
		 MOTOR_Stop(MOTOR_2);		 
	}
	
	// turn  right
	if (!DIO_ReadPin(BUTTON_2))
	{
		
		 MOTOR_CW(MOTOR_1);
		 while(!DIO_ReadPin(BUTTON_2));
		 MOTOR_Stop(MOTOR_1);	
		
	}
	
	// turn left
	if (!DIO_ReadPin(BUTTON_3))
	{
		
		 MOTOR_CW(MOTOR_2);
		 while(!DIO_ReadPin(BUTTON_3));
		 MOTOR_Stop(MOTOR_2);		
		
	}

     // move backward
	if (!DIO_ReadPin(BUTTON_4))
	{
		
		 MOTOR_CCW(MOTOR_1);
		 MOTOR_CCW(MOTOR_2);
		 while(!DIO_ReadPin(BUTTON_4));
		 MOTOR_Stop(MOTOR_1);
		 MOTOR_Stop(MOTOR_2);		
		
	}	
	
	
		 MOTOR_CW(MOTOR_1);
		 MOTOR_CW(MOTOR_2);
		
		 MOTOR_CCW(MOTOR_1);
		 MOTOR_CCW(MOTOR_2);
		
		 MOTOR_Stop(MOTOR_1);
		 MOTOR_Stop(MOTOR_2);
		 
	
}
