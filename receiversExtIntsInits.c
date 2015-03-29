/*
 * transmittersExtIntsInits.c
 *
 * Created: 2015.03.17. 14:22:40
 *  Author: csaszi_win7
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#include "receiversExtIntsInits.h"

void ExtInt4_ExtInt5_Init()
{
	EICRB=(1<<ISC51)|(1<<ISC50)|(1<<ISC41)|(1<<ISC40);//rising edge generates interrupt
	EIMSK=0;
	EIMSK|=(1<<INT4);//
}
void ExtInt6_ExtInt7_Init()
{
	EICRB=(1<<ISC61)|(1<<ISC60)|(1<<ISC71)|(1<<ISC70);//rising edge generates interrupt
	EIMSK=0;
	EIMSK|=(1<<INT6);//|(1<<INT5);
}