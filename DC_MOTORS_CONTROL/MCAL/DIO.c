

#include "DIO_Interface.h"
#include "DIO_Private.h"



 
 static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status){
	   DIO_Port_type port=pin/8;
	   U8 Pin_Num=pin%8;
	  switch(status)
	  {
	     case OUTPUT:
		 switch(port)
		 {
			 case PA:
			 SET_BIT(DDRA,Pin_Num);
			 CLEAR_BIT(PORTA,Pin_Num);
			 break;
			 case PB:
			 SET_BIT(DDRB,Pin_Num);
			 CLEAR_BIT(PORTB,Pin_Num);
			 break;			 
			 case PC:
			 SET_BIT(DDRC,Pin_Num);
			 CLEAR_BIT(PORTC,Pin_Num);
			 break;			 
			 case PD:
			 SET_BIT(DDRD,Pin_Num);
			 CLEAR_BIT(PORTD,Pin_Num);
			 break;			 
		 }
		 break;
	     case INFREE:
	     switch(port)
	     {
		     case PA:
		     CLEAR_BIT(DDRA,Pin_Num);
		     CLEAR_BIT(PORTA,Pin_Num);
		     break;
		     case PB:
		     CLEAR_BIT(DDRB,Pin_Num);
		     CLEAR_BIT(PORTB,Pin_Num);
		     break;
		     case PC:
		     CLEAR_BIT(DDRC,Pin_Num);
		     CLEAR_BIT(PORTC,Pin_Num);
		     break;
		     case PD:
		     CLEAR_BIT(DDRD,Pin_Num);
		     CLEAR_BIT(PORTD,Pin_Num);
		     break;
	     }	
		 break;
	     case INPULL:
	     switch(port)
	     {
		     case PA:
		     CLEAR_BIT(DDRA,Pin_Num);
		     SET_BIT(PORTA,Pin_Num);
		     break;
		     case PB:
		     CLEAR_BIT(DDRB,Pin_Num);
		     SET_BIT(PORTB,Pin_Num);
		     break;
		     case PC:
		     CLEAR_BIT(DDRC,Pin_Num);
		     SET_BIT(PORTC,Pin_Num);
		     break;
		     case PD:
		     CLEAR_BIT(DDRD,Pin_Num);
		     SET_BIT(PORTD,Pin_Num);
		     break;
	     }
		 break;		 	 
	  }
 }
 void DIO_InitPort(DIO_Port_type port,DIO_PinStatus_type status){
	  switch(status)
	  {
		  case OUTPUT:
		  switch(port)
		  {
			  case PA:
			  DDRA=0xff;
			  PORTA=0;
			  break;
			  case PB:
			  DDRB=0xff;
			  PORTB=0;
			  break;
			  case PC:
			  DDRC=0xff;
			  PORTC=0;
			  break;
			  case PD:
			  DDRD=0xff;
			  PORTD=0;
			  break;
		  }
		  break;
		  case INFREE:
		  switch(port)
		  {
			  case PA:
			  DDRA=0;
			  PORTA=0;
			  break;
			  case PB:
			  DDRB=0;
			  PORTB=0;
			  break;
			  case PC:
			  DDRC=0;
			  PORTC=0;
			  break;
			  case PD:
			  DDRD=0;
			  PORTD=0;
			  break;
		  }
		  break;
		  case INPULL:
		  switch(port)
		  {
			  case PA:
			  DDRA=0;
			  PORTA=0xff;
			  break;
			  case PB:
			  DDRB=0;
			  PORTB=0xff;
			  break;
			  case PC:
			  DDRC=0;
			  PORTC=0xff;
			  break;
			  case PD:
			  DDRD=0;
			  PORTD=0xff;
			  break;
		  }
		  break;
	  }
 }
 
 void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt){
	  DIO_Port_type port=pin/8;
	  U8 Pin_Num=pin%8;
	 if (volt==HIGH)
	 {
		  switch(port)
		  {
			  case PA:
			  SET_BIT(PORTA,Pin_Num);
			  break;
			  case PB:
			  SET_BIT(PORTB,Pin_Num);
			  break;
			  case PC:
			  SET_BIT(PORTC,Pin_Num);
			  break;
			  case PD:
			  SET_BIT(PORTD,Pin_Num);
			  break;
		  }
	 }else if(volt==LOW){
		  switch(port)
		  {
			  case PA:
			  CLEAR_BIT(PORTA,Pin_Num);
			  break;
			  case PB:
			  CLEAR_BIT(PORTB,Pin_Num);
			  break;
			  case PC:
			  CLEAR_BIT(PORTC,Pin_Num);
			  break;
			  case PD:
			  CLEAR_BIT(PORTD,Pin_Num);
			  break;
		  }
	 }
 }
 
 DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin){
	  DIO_Port_type port=pin/8;
	  U8 Pin_Num=pin%8;
	 DIO_PinVoltage_type volt=LOW;
	  switch(port)
	  {
		  case PA:
		 volt= READ_BIT(PINA,Pin_Num);
		  break;
		  case PB:
		 volt= READ_BIT(PINB,Pin_Num);
		  break;
		  case PC:
		 volt= READ_BIT(PINC,Pin_Num);
		  break;
		  case PD:
		 volt= READ_BIT(PIND,Pin_Num);
		  break;
	  }
	  return volt;
 }
 
 void DIO_TogglePin(DIO_Pin_type pin){
	 DIO_Port_type port=pin/8;
	 U8 Pin_Num=pin%8;
	  switch(port)
	  {
		  case PA:
		  TOG_BIT(PORTA,Pin_Num);
		  break;
		  case PB:
		  TOG_BIT(PORTB,Pin_Num);
		  break;
		  case PC:
		  TOG_BIT(PORTC,Pin_Num);
		  break;
		  case PD:
		  TOG_BIT(PORTD,Pin_Num);
		  break;
	  }
	 
 }
 
 void DIO_WritePort(DIO_Port_type port,U8 value){
	 switch(port)
	 {
		 case PA:
		 PORTA=value;
		 break;
		 case PB:
		 PORTB=value;
		 break;
		 case PC:
		 PORTC=value;
		 break;
		 case PD:
		 PORTD=value;
		 break;
	 }
	 
 }
 
 U8 DIO_ReadPort(DIO_Port_type port){
	 U8 value=0;
	 switch(port)
	 {
		 case PA:
		 value= PINA;
		 break;
		 case PB:
		 value= PINB;
		 break;
		 case PC:
		 value= PINC;
		 break;
		 case PD:
		 value= PIND;
		 break;
	 }
	 return value;
 }
 
void DIO_Init(void){
	 DIO_Pin_type i;
	 for (i=PINA0;i<TOTAL_PINS;i++)
	 {
		 DIO_InitPin(i,PinStatusArray[i]);
	 }
 }
