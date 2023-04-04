
#include "Calculator_APP.h"

static S16 num2=0,num1=0,result=0;
static U8 k=0,operator=0,flage=1;
void Calculator_Start(){
	 
	
	 
	   k=KEYPAD_Getkey();
	   if (k!=NO_KEY)
	   {
		  
		  if (k>='0'&&k<='9')
		  { 
			  if (flage == 0)
			  {
                LCD_Clear();
				  flage=1;
			  }
			  
			  LCD_WriteChar(k);
			  num2=num2*10+(k-'0');
		 
		  }
		  if (k == '+')
		  {
			  operator=k;
			  LCD_WriteChar(' ');
			  LCD_WriteChar(k);
			  LCD_WriteChar(' ');
			  num1=num2;
			  num2=0;
		  }

		  if (k == '-')
		  {
			  operator=k;
			  LCD_WriteChar(' ');
			  LCD_WriteChar(k);
			  LCD_WriteChar(' ');
			  num1=num2;
			  num2=0;
		  }
		  
		  if (k == '*')
		  {
			  operator=k;
			  LCD_WriteChar(' ');
			  LCD_WriteChar(k);
			  LCD_WriteChar(' ');
			  num1=num2;
			  num2=0;
		  }

		  if (k == '/')
		  {
			  operator=k;
			  LCD_WriteChar(' ');
			  LCD_WriteChar(k);
			  LCD_WriteChar(' ');
			  num1=num2;
			  num2=0;
		  }		  		  		  
		  
		  if (k == 'C')
		  {
			  LCD_Clear();
		  }
		  
		  if (k =='=')
		  {
			  if(operator=='+'){
				  result=num1+num2;
			  }
			  else if(operator=='-'){
				  result=num1-num2;
			  }
			  else if(operator=='*'){
				  result=num1*num2;
			  }
			  else if(operator=='/'){
				  if (num2<=0)
				  {
					  LCD_WriteString("Error      ");
					  result=0;
				  }else{
					 result=num1/num2;  
				  }
				 
			  }			  
 
			  LCD_GoTo(1,0);
			  LCD_WriteChar(k);
			  LCD_WriteNumber(result);
			  LCD_GoTo(1,9);
			  LCD_WriteHex(result);
			  num1=0;
			  num2=0;
			  flage=0;
			   
	   }
	
	
	
	
     }

 }