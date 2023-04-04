/*
 * main.c
 *
 * Created: 10/11/2022 11:08:41 PM
 * Author : mohamed elshaarawy
 */ 
#include "MemMap.h"
#include "stdTYPES.h"
#include "Utils.h"
#include "SEGMENT.h"


	
int main(void)
{
DIO_Init();

 int flag1=0,flag2=0,n=30;
    while (1) 
   {
	   for (int i=n;i>0;i--) 
	   {
		   for (int j=0;j<50;j++)
		   {
			   
			   // switch mode (button1)
			   if(!READ_BIT(PINA,0)){
				   flag1^=1; 
				  while(!READ_BIT(PINA,0));
			    }
				
				   /**** mode 1 *****/
				   //button2
				if(!READ_BIT(PINA,1)){
					flag2^=1;
					  if (flag2==1)
						 {
							 while(!READ_BIT(PINA,1));
							 while(flag2){
							    Segment_Display_MUX(i);
									   			   
							     if (!READ_BIT(PINA,1))
								    {
										   			   
								    flag2^=1;
								    while(!READ_BIT(PINA,1));
								        }

						            }
						 }
						 
				}
				  //button3
				if(!READ_BIT(PINA,2)) {
					i=n;
				  while(!READ_BIT(PINA,2));	
				}
				
				
				
				
				    /**** mode 2 ****/
				   while (flag1==1)
				   {
					   
					             if (!READ_BIT(PINA,0))
					             {
									 flag1^=1;
									 while(!READ_BIT(PINA,0));
					             }
					   
					               Segment_Display_MUX(n);
					   			   // button2
					   			   if(!READ_BIT(PINA,1)){
							   			 
										  if (n<90)
							   			   {
								   			   n+=10;

								   			   }else{
								   			   n=n%10;

							   			   }
							   			   while(!READ_BIT(PINA,1));

							   			   }
							   			   
					   			   
					   			   //button 3
					   			   if (!READ_BIT(PINA,2))
					   			   {
						   			   if (flag1==1)
						   			   {
							   			   if ((n%10)<9)
							   			   {
								   			   n+=1;
								   			   
								   			   
								   			   }else{
								   			   n=(n/10)*10;
								   			   
								   			   
							   			   }
   
							   		 } 
						   			   while(!READ_BIT(PINA,2));
					   			   }
					   
				   }

			   Segment_Display_MUX(i);
			   _delay_ms(10);
		   }
		   
	   }
	  
	   
   }

}


	  

   
   
   
   

