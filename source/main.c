#include  "../header/api.h"    		// private library - API layer
#include  "../header/app.h"    		// private library - APP layer
#define ascii_offset 48
#define id_size 9


enum FSMstate state;
enum SYSmode lpm_mode;

void main(void){
  char id[9] ={2,1,1,6,7,4,0,2,1}; // random id number
  state = state0;  // start in idle state on RESET
  lpm_mode = mode0;     // start in idle state on RESET
  sysConfig();
 // enterLPM(lpm_mode);
  
  while(1){
	switch(state){
	  case state0:
		//printSWs2LEDs();
        enterLPM(lpm_mode);
		break;
		 
	  case state1:
		disable_interrupts();
		printDigitArr2LEDs(id,id_size,LEDs_SHOW_RATE); // remember to change rate
		//delay(LEDs_SHOW_RATE);	// delay of 62.5 [ms]
		enable_interrupts();
		state = state0;
		break;
		 
	  case state2:
		disable_interrupts();
		ShiftNum2LEDs(LEDs_SHOW_RATE);
		enable_interrupts();
		state = state0;
		break;
		
	  case state3:
	        enable_interrupts();
	        generatePwm();
	    break;

	}
  }
}
  
  
  
  
  
  
