/*
 * Util.h
 *
 * Created: 13/11/2022 01:35:55 ص
 *  Author: NightWinge
 */ 


#ifndef UTILS_H_
#define UTILS_H_
 
#define SET_BIT(reg,bit)        (reg|=(1<<bit))
#define CLEAR_BIT(reg,bit)      (reg&=(~(1<<bit)))
#define TOG_BIT(reg,bit)        (reg^=(1<<bit))  // toggle (1)to(0) and opposite
#define READ_BIT(reg,bit)        ((reg>>bit)&1)
#define WRITE_BIT(reg,bit,value)        (reg=((reg&~(1<<bit))|(value<<bit)))



#endif /* UTILS_H_ */