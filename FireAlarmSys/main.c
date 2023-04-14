/*
 * GccApplication2.c
 *
 * Created: 10/11/2022 11:08:41 PM
 * Author : NightWinge
 */ 

//include <avr/io.h>
#include "MemMap.h"
#include "stdTYPES.h"
#include "Utils.h"

#include "DIO_Interface.h"
#include "MOTOR.h"
#include "LCD.h"
#include "KeyPad.h"

#include "ADC.h"



#include "FireAlarmSys.h"

	
int main(void)
{
DIO_Init();
LCD_Init();
ADC_Init(ADC_AVCC,ADC_SCALER_64);

U8 p[]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
	LCD_Create_Character(p,1);


LCD_WriteString("    Alarm Sys");
_delay_ms(1000);
LCD_Clear();
    while (1) 
   {
	 FireAlarAPP_start();  
   }

}



	  

   
   
   
   

