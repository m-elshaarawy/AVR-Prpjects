
 

#ifndef SENSORS_H_
#define SENSORS_H_

#include "ADC.h"

#define LM35_CH    CH_0
//#define POT_CH     CH_1
#define MPX4115_CH     CH_2

U16 Lm35_GetTemp(void);
//U8 POT_GetPerc(void);
U16 MPX4115_GetPressure(void);



#endif /* SENSORS_H_ */