# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../demos/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} buzz.o buzzer.o p2_interrupt_handler.o p1_interrupt_handler.o led.o switches.o buttonMain.o ../demos/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

buzzer.o: buzzer.h
buzz: buzzer.h

switches.o: switches.h

main.o: wdt.h

clean:
	rm -f *.o *.elf

