#ifndef switches_included
#define switches_included

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1            /* only 1 switch on this board */
#define TSW1 BIT0
#define TSW2 BIT1
#define TSW3 BIT2
#define TSW4 BIT3
#define TSWITCHES TSW1|TSW2|TSW3|TSW4

void switch_init();
void switch_interrupt_handler();
void switch_interrupt_handler2();

extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
