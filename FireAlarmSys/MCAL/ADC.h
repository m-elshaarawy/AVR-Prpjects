

#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "Utils.h"
#include "STDTYPES.h"


typedef enum{
	ADC_AREF=0,
	ADC_AVCC=1,
	ADC_V256=3
	}ADC_Vref_type;
typedef enum{
	ADC_SCALER_2=0,
	ADC_SCALER_4=2,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
	}ADC_Scaler_type;
typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
	}ADC_Channel_type;		


void ADC_Init(ADC_Vref_type vref,ADC_Scaler_type scaler);

U16 ADC_Read(ADC_Channel_type ch);

U16 ADC_GetVolt(ADC_Channel_type ch);

void ADC_StrtConversion(ADC_Channel_type ch);

U16 ADC_GetRead(void);

U16 ADC_GetReadPeriodicCheck(U16*pdata);

U16 ADC_ReadNoBlock(void);





#endif /* ADC_H_ */