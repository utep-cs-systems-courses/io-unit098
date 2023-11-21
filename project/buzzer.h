#ifndef buzzer_included
#define buzzer_included

#define TCCR0 CCR0
#define TCCR1 CCR1
void buzzer_init();
void buzzer_set_period(short cycles);

#endif // included
