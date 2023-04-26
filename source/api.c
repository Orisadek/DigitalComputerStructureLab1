#include  "../header/api.h"    		// private library - API layer
#include  "../header/halGPIO.h"     // private library - HAL layer
//enum FSMstate state;
char value_led_shift = 1; //saving the value of the result of shifting
//-------------------------------------------------------------
//            Print SWs value onto LEDs
//-------------------------------------------------------------
void printSWs2LEDs(void){
	unsigned char ch;
	
	ch = readSWs();
	print2LEDs(ch);
}
//--------------------------------------------------------------------
//            Print array to LEDs array with rate of LEDs_SHOW_RATE
//--------------------------------------------------------------------            
void printArr2SWs(char Arr[], int size, unsigned int rate){
	unsigned int i;
	for(i=0; i<size; i++){
		print2LEDs(Arr[i]);
		//delay(rate);
	}
}
//--------------------------------------------------------------------
//            Print digits array to LEDs array with rate
//--------------------------------------------------------------------
void printDigitArr2LEDs(char id_arr[] , int size, unsigned int rate ){
    unsigned int i;
    for(i=0; i<size; i++){
       // printDigit2LEDs(id_arr[i]);
        print2LEDs(id_arr[i]);
        delayHalfSecond();
       }
    clrLEDs();
}

//--------------------------------------------------------------------
//           shift the leds left
//--------------------------------------------------------------------
void ShiftNum2LEDs( unsigned int rate ){
   // char temp = value_led_shift;
    unsigned int i;
    print2LEDs(value_led_shift);
    delay(rate);
    for(i=0; i<14; i++){
        value_led_shift=shiftLEDs();
        delayHalfSecond();
       }
    clrLEDs();
   // value_led_shift = temp;
}


 void generatePwm(void){
     clearPWM(); /// Signal starts at zero
     unsigned int delayOfPwm = 0.25 * TPwm;
     unsigned int delayOnPwm = 0.75 * TPwm;

  while(state==state3){
         delay(3);
         toggeleBit();
         delay(16);
         toggeleBit();
     }
 }





 
  

