/*
 * receiverExtInts.c
 *
 * Created: 2015.03.17. 15:31:13
 *  Author: csaszi_win7
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

#include "receiversExtIntsInits.h"

extern uint16_t time1;
extern uint16_t time2;
extern uint16_t speed;		//m/s
extern uint32_t ballDiameter;	//nanometer KORREKCIÓ kell

////////////////////////////////////////////////////////TELJESEN NÉZD ÁT, EZ CSAK BEMÁSOLT ANYAG
ISR(INT4_vect)
{
	
	ETIMSK|=1<<OCIE3A;	//Timer3 számolhatja az idõt
}
ISR(INT5_vect)
{
	ETIMSK=0;		//OCIE3A kikapcsolása//time számlálás kikapcs
	
	speed=0;
	
	speed=(ballDiameter/(time1))*2/5/5;	//számolás(80kHz)	calc.:(40000um/(time)us)/12,5	(/5^3*10)
	
}
ISR(INT6_vect)
{
	
	ETIMSK|=1<<OCIE3A;	
}
ISR(INT7_vect)
{
	
	
}