

#include "MOTOR.h"




void MOTOR_CW(EN_MOTOR_type motor){
	
	switch(motor){
		case MOTOR_1:
		  	DIO_WritePin(IN1_M1,HIGH);
		  	DIO_WritePin(IN2_M1,LOW);
			DIO_WritePin(EN_M1,HIGH);
			  	
		break;
		case MOTOR_2:
		    DIO_WritePin(IN3_M2,HIGH);
		  	DIO_WritePin(IN4_M2,LOW);
			DIO_WritePin(EN_M2,HIGH);
		break;

	}
	
}


void MOTOR_CCW(EN_MOTOR_type motor){
		
		switch(motor){
			case MOTOR_1:
			DIO_WritePin(IN1_M1,LOW);
			DIO_WritePin(IN2_M1,HIGH);
			DIO_WritePin(EN_M1,HIGH);
			
			break;
			case MOTOR_2:
			DIO_WritePin(IN3_M2,LOW);
			DIO_WritePin(IN4_M2,HIGH);
			DIO_WritePin(EN_M2,HIGH);
			break;

		}
	
}
void MOTOR_Stop(EN_MOTOR_type motor){
		
		switch(motor){
			case MOTOR_1:
			DIO_WritePin(IN1_M1,LOW);
			DIO_WritePin(IN2_M1,LOW);
			DIO_WritePin(EN_M1,LOW);
			
			break;
			case MOTOR_2:
			DIO_WritePin(IN3_M2,LOW);
			DIO_WritePin(IN4_M2,LOW);
			DIO_WritePin(EN_M2,LOW);
			break;

		}
	
}


