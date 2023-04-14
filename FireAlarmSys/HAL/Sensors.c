
#include "Sensors.h"


U16 Lm35_GetTemp(void){
	U16 temp,volt;
	volt=ADC_GetVolt(LM35_CH);
	//temp=volt/10;
	temp=volt;
	return temp;
	
}


U16 MPX4115_GetPressure(void){
	
	U16 pressure,adc;
	
	adc=ADC_Read(MPX4115_CH);
	
	pressure=(((U32)(adc-41)*1000)/942)+150;
	
	return pressure;
}




//U8 POT_GetPerc(void){
	//U16 adc=ADC_Read(POT_CH);
	//U8 perc=((U32)100*adc)/1023;
	//return perc;	
//}
