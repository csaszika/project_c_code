/*
 * timeCounterForSpeedCalculating.c
 *
 * Created: 2015.03.17. 14:35:34
 *  Author: csaszi_win7
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

#include "timeCounterForSpeedCalcuating.h"

extern uint16_t time1;
extern uint16_t time2;

void Timer3AInit()//idõszámlálás 
{
	TCCR3A=0;
	TCCR3A|=(1<<COM3A1)|(0<<COM3A0)|(0<<WGM31)|(0<<WGM30);//CTC+OCR3A clear

	TCCR3B=0;
	TCCR3B|=(0<<WGM33)|(1<<WGM32)|(0<<CS32 )|(1<<CS31)| (1<<CS30);//CTC+OCR3A; 1 prescaler(1-tõl 5-ig)(1,8,64,256,1024)
	
	OCR3A=99;//16MHz/(2*1*(1+OCR3A))=16MHz/2(1+99)=80kHz				=>0,625%hiba(72km/h)
}
void Timer1AInit()
{
	TCCR1A=0;
	TCCR1A|=(1<<COM1A1)|(0<<COM1A0)|(0<<WGM11)|(0<<WGM10);//CTC+OCR1A clear

	TCCR1B=0;
	TCCR1B|=(0<<WGM13)|(1<<WGM12)|(0<<CS12 )|(1<<CS11)| (1<<CS10);//CTC+OCR1A; 1 prescaler(1-tõl 5-ig)(1,8,64,256,1024)
	
	OCR1A=99;//16MHz/(2*1*(1+OCR1A))=16MHz/2(1+99)=80kHz	=>0,625%hiba(72km/h)
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////time counter////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
ISR(TIMER3_COMPA_vect)
{
	time1++;			//1-2^16
	//if(time==720000)measuringError(0);//ki kell számolni 5km/h-ra
}
ISR(TIMER1_COMPA_vect)
{
	time2++;			//1-2^16
	//if(time==720000)measuringError(0);
}