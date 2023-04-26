
#include "FireAlarmSys.h"

static volatile U16 temp=0,smoke=0,perc=0;
static U8 key,i=0;
static const U8 password[]="123";
static  U8 INPUT[]="000";

void FireAlarAPP_start(void){
	
	LCD_GoToWriteString(0,0,"Temp");
	LCD_GoTo(1,0);
	temp=Lm35_GetTemp();              //read temp sensor
	smoke=MPX4115_GetPressure();       //read pressure sensor
	perc=(((U32)smoke*100)/1150);
	
	//display temp on LCD
	LCD_WriteNumber(temp/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(temp%10);
	LCD_WriteString("C   ");
	
	//display pressure on LCD
	LCD_GoTo(1,9);
	LCD_WriteNumber(smoke/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(smoke%10);
	LCD_WriteString("kpa   ");
	for (int i=0,j=10;i<perc;i+=20)
	{
		LCD_GoTo(0,j);
		LCD_WriteChar(1);
		j++;
	}
	LCD_WriteChar(' ');
	
	


/************************************************************************/

	  if (temp <= 400)
	    {
	     	LCD_GoToWriteString(0,5,"FINE");
		    DIO_WritePin(YELLOW_LED,LOW);
		    MOTOR_Stop(MOTOR_1);
	    }else if (temp > 400)
	         {
	    	LCD_GoToWriteString(0,5,"HEAT");
			DIO_WritePin(YELLOW_LED,HIGH);
	         }		
	//---------------------------------->
		 if (temp > 400 && perc > 50)
		 {
			 LCD_GoToWriteString(0,5,"FIRE");
			  MOTOR_CW(MOTOR_1);
			 DIO_WritePin(YELLOW_LED,LOW);
			 DIO_WritePin(RED_LED,HIGH);
			 while(strcmp(password,INPUT)){
				 LCD_GoToWriteString(0,0," Enter password ");
				 LCD_GoToWriteString(1,0,"                ");
				 LCD_GoTo(1,0);
				 
				 for (i=0;i<3;)
				 {
				   key=KEYPAD_Getkey();
				   if (key!=NO_KEY)
				   {
					 LCD_WriteChar(key);
					 INPUT[i]=key;
					 i++;
				   }
				 }
                 INPUT[i]='\0';
				 if (strcmp(password,INPUT)!=0)
				 {
					 
					 LCD_GoToWriteString(1,0,"ERROR      ");
				 }
				 
			 }
			// __asm__ __volatile__ ("jmp 0");  to reset MCU ---------------------------->
			LCD_GoToWriteString(0,0,"                  ");
			DIO_WritePin(RED_LED,LOW); 
			INPUT[0]='0'; // reset INPUT
			INPUT[1]='0';
			INPUT[2]='0';
		 }
	//--------------------------->
	  if (temp>=450)
	  {
		  MOTOR_CW(MOTOR_1);
	  }


	
	
	
}
