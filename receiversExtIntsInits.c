/*
 * transmittersExtIntsInits.c
 *
 * Created: 2015.03.17. 14:22:40
 *  Author: csaszi_win7
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

#include "receiversExtIntsInits.h"

void ExtInt4_ExtInt5_ExtInt6_ExtInt7Init()
{
	EICRB=0;
	EICRB=(1<<ISC51)|(0<<ISC50)|(1<<ISC41)|(1<<ISC40)|(1<<ISC61)|(0<<ISC60)|(1<<ISC71)|(1<<ISC70);//4 felfutó 5 lefutó
	EIMSK=0;																					//6 felfutó 7 lefutó él
	EIMSK|=(1<<INT4)|(1<<INT5)|(1<<INT6)|(1<<INT7);//
}
void ExtInt0_ExtInt1_ExtInt2_ExtInt3Init()
{
	EICRA=0;
	EICRA=(1<<ISC01)|(1<<ISC00)|(1<<ISC11)|(1<<ISC10)|(1<<ISC21)|(1<<ISC20)|(1<<ISC31)|(1<<ISC30);//felfutó él
	EIMSK|=(1<<INT0)|(1<<INT1)|(1<<INT2)|(1<<INT3);//itt már mindegyik külsõ megszakítás inicializálva
}