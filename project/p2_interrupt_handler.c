#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "led.h"
/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & TSWITCHES) {
    P1OUT ^= LED_GREEN; /* did a button cause this interrupt? */
    switch_interrupt_handler2();	/* single handler for all switches */
    //buzzer_set_period(1000);
    P2IN &= ~TSWITCHES;
  }
}

