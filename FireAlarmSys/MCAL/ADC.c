
#include "ADC.h"


void ADC_Init(ADC_Vref_type vref,ADC_Scaler_type scaler){
		// Vref
	switch(vref){
		case ADC_AREF:
		CLEAR_BIT(ADMUX,REFS1);
		CLEAR_BIT(ADMUX,REFS0);
		break;
		case ADC_AVCC:
		CLEAR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case ADC_V256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;		
	}
	// prescaller (clock)
	ADCSRA&=0xf8;//11111000
	//scaler&=0x07;//00000111 just in case .
	ADCSRA|=scaler;
	//adjist read to the right 
	CLEAR_BIT(ADMUX,ADLAR);
   // adc enabe
   SET_BIT(ADCSRA,ADEN);
	
}

U16 ADC_Read(ADC_Channel_type ch){
	
	//U16 adc =ADC; // U16 adc=ADCL|((short*)ADCH<<8); if ADLAR=1 adc=ADCH<<2 less accurate;
	
	// select channel
	ADMUX&=0xe0;
    ADMUX|=ch;
	
	// start conversion
	SET_BIT(ADCSRA,ADSC);
	//w8 until conversion end
	while(READ_BIT(ADCSRA,ADSC)); //busy wait "polling"
	// returning 
	return ADC;
}

U16 ADC_GetVolt(ADC_Channel_type ch){
	
	U16 adc=ADC_Read(ch);
	U16 volt=((U32)adc*5000)/1024;
	return volt;
}

static U8 read_flag=1;

void ADC_StrtConversion(ADC_Channel_type ch){
	if(read_flag==1)
	{
		
	
	// select channel
	ADMUX&=0xe0;
	ADMUX|=ch;
	
	// start conversion
	SET_BIT(ADCSRA,ADSC);
	read_flag=0;
	}
	
}

U16 ADC_GetRead(void){
	//w8 until conversion end
	while(READ_BIT(ADCSRA,ADSC)); //busy wait "polling"
	// returning
	return ADC;
}

U16 ADC_GetReadPeriodicCheck(U16*pdata){
	//check if conversion end
	if(READ_BIT(ADCSRA,ADSC)==0){
		*pdata=ADC;
		read_flag=1;
		return 1;
		}
		else{
			return 0;
		}

}

U16 ADC_ReadNoBlock(void){
	
	return ADC;
}