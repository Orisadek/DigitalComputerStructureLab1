#ifndef _api_H_
#define _api_H_

#include  "../header/halGPIO.h"     // private library - HAL layer


extern void printSWs2LEDs(void);
extern void printArr2LEDs(char[] , int , unsigned int  );
extern void ShiftNum2LEDs( unsigned int  );
extern void generatePwm(void);
#endif







