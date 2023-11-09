#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & TSWITCHES) {	      /* did a button cause this interrupt? */
    switch_interrupt_handler2();	/* single handler for all switches */
    //buzzer_set_period(1000);
  }
}

