/*
 * GccApplication2.c
 *
 * Created: 10/11/2022 11:08:41 PM
 * Author : mohamed elshaarawy
 */ 

//include <avr/io.h>
#include "MemMap.h"
#include "stdTYPES.h"
#include "Utils.h"

#include "DIO_Interface.h"

#include "LCD.h"

#include "Calculator_APP.h"

	
int main(void)
{
DIO_Init();
LCD_Init();

LCD_GoToWriteString(0,0,"SimpleCalculator");
LCD_GoToWriteString(1,2,"M_Elshaarawy");

    while (1) 
   {

Calculator_Start();

   }

}



	  

   
   
   
   

