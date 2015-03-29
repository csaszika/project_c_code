/*
 * clocksigns_timer_init.c
 *
 * Created: 2015.03.16. 23:13:13
 *  Author: csaszi_win7
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#include "clocksignsTimerInits.h"

void Timer2Init()//56kHz
{
	TCCR2=0;
	TCCR2|=(1<<WGM21)|(0<<WGM20)|(1<<COM21)|(0<<COM20)|(0<<CS22 )|(0<<CS21)| (1<<CS20);
	
	OCR2=142;
	
	TIMSK|=(1<<OCIE2);//16MHz/(2*n*(1+OCR1A))=16MHz/2(in)/1(prescale)/(1+142)=55944,056Hz~56kHz

	//TSUS5202 950nm,55,94kHz => TSOP4856 950nm,56kHz
}
void Timer0Init()//38kHz
{
	TCCR0=0;
	TCCR0|=(1<<WGM01)|(0<<WGM00)|(1<<COM01)|(0<<COM00)|(0<<CS02 )|(0<<CS01)| (1<<CS00);

	OCR0=210;//16MHz/(2*n*(1+OCR0))=16MHz/2(in)/1(prescale)/(1+25)=37914,7Hz~38kHz
	
	TIMSK=0;
	TIMSK|=(1<<OCIE0);

	//TSUS5202 950nm,37,91kHz => TSOP4838 950nm,38kHz
}
///////////////////////////////////////////////////////////////////////////
///////////////////////Frequency for infraLEDs/////////////////////////////
///////////////////////////////////////////////////////////////////////////
ISR(TIMER2_COMP_vect)//56kHz
{
	PORTF^=1<<PF0;				//lábak	MÓDOSULHATNAK!!!!
}

ISR(TIMER0_COMP_vect)//38kHz
{
	PORTF^=1<<PF1;
}