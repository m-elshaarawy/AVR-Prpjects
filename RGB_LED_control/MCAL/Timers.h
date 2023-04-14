 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "MemMap.h"
#include "Utils.h"
#include "stdTYPES.h"

#define Timer0_set(value)         (TCNT0=value)
#define Timer0_setOCR0(value)     (OCR0=value)
#define Timer1_setOCR1B(value)    (OCR1B=value)
#define Timer1_setOCR1A(value)    (OCR1A=value)
#define Timer1_setICR1(value)     (ICR1=value)

typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer0Scaler_type;

typedef enum{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
	}Timer0Mode_type;
	
typedef enum{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,//clear
	OC0_INVERTING  // set
	}OC0Mode_type;	

                 
void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler);
void TIMER0_OCMode(OC0Mode_type mode);
void TIMER0_ov_InterruptEnable(void);
void TIMER0_ov_InterruptDisable(void);
void TIMER0_oc_InterruptEnable(void);
void TIMER0_oc_InterruptDisable(void);
void TIMER0_ov_setCAllBack(void(*local_fptr)(void));
void TIMER0_oc_setCAllBack(void(*local_fptr)(void));
//void Timer0_set(U8 value);
U8 Timer0_read(void);


/****************************************************************/

typedef enum{
	
		TIMER1_STOP=0,
		TIMER1_SCALER_1,
		TIMER1_SCALER_8,
		TIMER1_SCALER_64,
		TIMER1_SCALER_256,
		TIMER1_SCALER_1024,
		EXTERNAL1_FALLING,
		EXTERNAL1_RISING
		
	}Timer1Scaler_type;
	
typedef enum{
	
	TIMER1_NORMAL_MODE,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE,
	
}Timer1Mode_type;

typedef enum{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING
}OC1A_Mode_type;
typedef enum{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING
}OC1B_Mode_type;

typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;
	
	
void TIMER1_InputCaptureEdge(ICU_Edge_type edge);
void TIMER1_Init(Timer1Mode_type mode ,Timer1Scaler_type scaler);
void TIMER1_OCRA1Mode(OC1A_Mode_type oc1a_mode);
void TIMER1_OCRB1Mode(OC1B_Mode_type oc1b_mode);	

void TIMER1_ICU_InterruptEnable(void);
void TIMER1_ICU_InterruptDisable(void);

void TIMER1_OVF_InterruptEnable(void);
void TIMER1_OVF_InterruptDisable(void);

void TIMER1_OCA_InterruptEnable(void);
void TIMER1_OCA_InterruptDisable(void);

void TIMER1_OCB_InterruptEnable(void);
void TIMER1_OCB_InterruptDisable(void);

void TIMER1_OVF_setCAllBack(void(*local_fptr)(void));
void TIMER1_OCA_setCAllBack(void(*local_fptr)(void));
void TIMER1_OCB_setCAllBack(void(*local_fptr)(void));
void TIMER1_ICU_setCAllBack(void(*local_fptr)(void));

#endif /* TIMERS_H_ */