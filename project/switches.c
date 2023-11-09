
#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p1val = P1IN;
  /* update switch interrupt to detect changes from current buttons */
   P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
   P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void 
switch_init()			/* setup switch */
{  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */
  P2REN |= TSWITCHES;		/* enables resistors for switches */
  P2IE |= TSWITCHES;		/* enable interrupts from switches */
  P2OUT |= TSWITCHES;		/* pull-ups for switches */
  P2DIR &= ~TSWITCHES;		/* set switches' bits for input */
 
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_changed = 1;
  led_update();
}

void
switch_interrupt_handler2()
{
  if(P2IFG & TSW1){
    buzzer_set_period(1000);
  }
  if(P2IFG & TSW2){
    buzzer_set_period(1500);
  }
  if(P2IFG & TSW3){
    buzzer_set_period(2000);
  }
  if(P2IFG & TSW4){
    buzzer_set_period(0);
  }
  P2IFG &= 0;
  // P1OUT ^= LED_RED;
}




