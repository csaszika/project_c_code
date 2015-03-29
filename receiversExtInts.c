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
extern uint32_t ballDiameter;	//nanometer KORREKCI� kell

extern char oszlop0v4;
extern char oszlop1v5;
extern char oszlop2v6;
extern char oszlop3v7;

////////////////////////////////////////////////////////TELJESEN N�ZD �T, EZ CSAK BEM�SOLT ANYAG
ISR(INT4_vect)
{
	
	ETIMSK|=1<<OCIE3A;	//Timer3 sz�molhatja az id�t
}
ISR(INT5_vect)
{
	ETIMSK=0;		//OCIE3A kikapcsol�sa//time sz�ml�l�s kikapcs
	
	speed=0;
	
	speed=(ballDiameter/(time1))*2/5/5;	//sz�mol�s(80kHz)	calc.:(40000um/(time)us)/12,5	(/5^3*10)
	
}
ISR(INT6_vect)
{
	
	ETIMSK|=1<<OCIE3A;	
}
ISR(INT7_vect)
{
	
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Poz�ci� korrekci�hoz////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
ISR(INT0_vect)
{
	oszlop0v4=1;
}
ISR(INT1_vect)
{
	oszlop1v5=1;
}
ISR(INT2_vect)
{
	oszlop2v6=1;
}
ISR(INT3_vect)
{
	oszlop3v7=1;
}