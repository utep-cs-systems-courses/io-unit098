#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "wdt.h"
int sec = 0;
int oldperiod = 0;
int period = 19010;
int OFFSET = 0;
void main(void) 
{  
  configureClocks();
  enableWDTInterrupts();
  switch_init();
  led_init();
  buzzer_init();
  buzzer_set_period(period);

  or_sr(0x18);  // CPU off, GIE on
} 

//void setoff(int a){
  //OFFSET=a;
  //}
void setper(int a){
  if(period = 0){}else{
  oldperiod = period;
  period=a;
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT(){
  if(sec == 25){
    if (period == 0){
      if(OFFSET!=0){
	period = oldperiod;
      }
    }
    else if(period > 2050){
    period = 1900;
    }
    else if (period < 1900){
     period = 2050;
      }else{
    period += OFFSET;
    }
    buzzer_set_period(period);
    sec =0;
  }
  sec += 1;
}
