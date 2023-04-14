
#include "Timers.h"

/************************ pointer to function assigned to ISR ********************************/

static void(*Fptr_OV0)(void)=NULLPTR;
static void(*Fptr_OC0)(void)=NULLPTR;
//static void(*Fptr_INT2)(void)=NULLPTR;


/************** Timer0 ********************/

void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler){
	
	// set mode
	switch (mode)
	{
	case TIMER0_NORMAL_MODE :
	    CLEAR_BIT(TCCR0,WGM00);
	    CLEAR_BIT(TCCR0,WGM01);
		break;
	case TIMER0_PHASECORRECT_MODE :
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
	    break;
	case TIMER0_CTC_MODE :
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	    break;	
	case TIMER0_FASTPWM_MODE :
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	    break;		
	}
	
	// select prescaler
   
   TCCR0&=0xf8;
   TCCR0|=scaler;
		
}

void TIMER0_OCMode(OC0Mode_type mode){
	
	switch (mode)
	{
		case TIMER0_NORMAL_MODE :
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case TIMER0_PHASECORRECT_MODE :
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case TIMER0_CTC_MODE :
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case TIMER0_FASTPWM_MODE :
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}	
		
}

void TIMER0_ov_InterruptEnable(void){
		
	SET_BIT(TIMSK,TOIE0);	
}
void TIMER0_ov_InterruptDisable(void){
	
	CLEAR_BIT(TIMSK,TOIE0);
}
void TIMER0_oc_InterruptEnable(void){
	
	SET_BIT(TIMSK,OCIE0);
}
void TIMER0_oc_InterruptDisable(void){
	
	CLEAR_BIT(TIMSK,OCIE0);
}

/*
void Timer0_set(U8 value){
	
	TCNT0=value;
}
*/

U8 Timer0_read(void){
	
	return TCNT0;
}

/*************************** callback functions Timer0 ************************************************/
void TIMER0_ov_setCAllBack(void(*local_fptr)(void)){
		
	Fptr_OV0=local_fptr;
}
void TIMER0_oc_setCAllBack(void(*local_fptr)(void)){
	
	Fptr_OC0=local_fptr;
}


/********* Timer1 **************************/
void TIMER1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}

	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}

void TIMER1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
}

void TIMER1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
}

/*
void Timer1_SetInterruptTime_ms (U16 time)
{
	Timer1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER1_SCALER_8);
	OCR1A=(time*1000)-1;
	Timer1_OCA_InterruptEnable();
}
*/

void TIMER1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLEAR_BIT(TCCR1B,ICES1);
}


/****************************Timer 1 Interrupt functions**************************************/

void TIMER1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void TIMER1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void TIMER1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void TIMER1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void TIMER1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void TIMER1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void TIMER1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void TIMER1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}



/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{

}
ISR(TIMER1_OCA_vect)
{
	
}
ISR(TIMER1_OCB_vect)
{
		
}
ISR(TIMER1_ICU_vect)
{
		
}

/*************************************** ISR **********************************/

ISR(TIMER0_OVF_vect){
	if(Fptr_OV0!=NULLPTR)
	Fptr_OV0();
}

ISR(TIMER0_COMP_vect){
	if(Fptr_OC0!=NULLPTR)
	Fptr_OC0();
}
