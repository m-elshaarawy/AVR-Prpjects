 

#include "MemMap.h"
#include "stdTYPES.h"
#include "Utils.h"

#include "DIO_Interface.h"

#include "Timers.h"

#include "RGB_LED.h"







	
int main(void)
{
	
DIO_Init();
LCD_Init();
RGB_LED_Init();




    while (1) 
   {
 	
for (int i=0;i<COLORS;i++)
{
	RED_LED_SetColor(i);
	 _delay_ms(200);
}

   }

}



  

   
   

