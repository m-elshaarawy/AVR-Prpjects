/*
 * SEGMENT.c
 *
 * Created: 12/11/2022 05:47:51 pm
 *  Author: mohamed elshaarawy
 */ 

#include "SEGMENT.h"



const static U8 arr_seg[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f,0x77,0x7C,0x39,0x5E,0x79,0x71};
	
	
	void Segment_Display(U8 num){
		SEG_PORT=arr_seg[num];
		
	    }
		
	void Segment_Display_2Digit(U8 num){
			SEG_PORT=arr_seg[num%10];
			SEG_PORT2=arr_seg[num/10];
			
		}
	
	
 	 void Segment_Display_BCD_HEX(U8 num){
 			 SEG_PORT=arr_seg[num];
 			 _delay_ms(150);
 	    }
	
	
	
	  void Segment_Display_BCD(U8 num){

		    SEG_PORT=num;
		   
	    }
	
    void Segment_Display_BCD_2Digit(U8 num){
			U8 x,y;
			x=num%10;
		    y=num/10;
			SEG_PORT=y|x<<4;
			
		}
		

	 
	 void Segment_Display_MUX(U8 num){
		SET_BIT(PORTD,1);
		CLEAR_BIT(PORTD,0);
		SEG_PORT=arr_seg[num/10];
		_delay_ms(5);
		SET_BIT(PORTD,0);
		CLEAR_BIT(PORTD,1);
		SEG_PORT=arr_seg[num%10];
		_delay_ms(5);
		
	    }	
	
	
	