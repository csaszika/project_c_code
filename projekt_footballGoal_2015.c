/*
 * projekt_footballGoal_2015.c
 *
 * Created: 2015.03.16. 22:14:18
 *  Author: csaszi_win7
 */ 
/*
Használt portok:

PORTA
PA0-1-2 = Muxok S0-1-2
PA3-4	= Muxok Y kimenetei,vízszintes PA3, függõleges PA4 

PORTB
PB4-7 = ledeken figyelés

PORTC
üres

PORTD
PD0-3 = INT0-3

PORTE
PE0-1 = UART0
PE4-7 = INT4-7(4-5 és 6-7)

PORTF
üres

PORTG
üres

Összesen: 11vezeték+2 UART+4 figyelõ led(ha kell)
*/
#define F_CPU (16000000UL)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "clocksignsTimerInits.h"
#include "receiversExtIntsInits.h"
#include "timeCounterForSpeedCalcuating.h"
#include "muxReader.h"

void simplePortInit();				//
void delay(unsigned char);
void Timer3AInit(void);				//timeCounter1
void Timer1AInit(void);				//timeCounter2
void Timer2Init(void);				//56kHz
void Timer0Init(void);				//38kHz
void ExtInt4_ExtInt5_ExtInt6_ExtInt7Init(void);//sebességméréshez
void ExtInt0_ExtInt1_ExtInt2_ExtInt3Init(void);//pozíció korrekciójához

volatile uint16_t time1=0;					//1,3,5,7 vevõ által indított idõszámláló
volatile uint16_t time2=0;					//0,2,4,6 vevõ által indított idõszámláló
volatile uint16_t speed=0;					//km/h , lenne a cél
volatile uint32_t ballDiameter=68120000;	//nanometer KORREKCIÓ kell, 68,12mm~6,812cm

volatile char vizszintesPoz[16]={0};	//pozíció végeredmény tömbök
volatile char fuggolegesPoz[16]={0};
	
volatile char atmenetiVizszintesPoz[8]={0};	//pozíció beolvasás ezekbe a tömbökbe történik
volatile char atmenetiFuggolegesPoz[8]={0};
	
volatile char oszlop0v4=0;	//pozíció korrekcióhoz
volatile char oszlop1v5=0;
volatile char oszlop2v6=0;
volatile char oszlop3v7=0;

int main(void)
{
    //init függvények
	Timer0Init();
	Timer2Init();
	Timer1AInit();			//OCIE1A,timecounters
	Timer3AInit();			//OCIE3A 
	ExtInt0_ExtInt1_ExtInt2_ExtInt3Init();//pozíció korrekciójához
	ExtInt4_ExtInt5_ExtInt6_ExtInt7Init();//sebességméréshez
	delay(100);
	sei();
	
	while(1)
    {
        //TODO:: Please write your application code 
    }
}
///////////////////////////I/O portok inicializálása///////////////////////////////
void simplePortInit()
{
	DDRA=0x1f;//PA0-2+PA3-4
}
///////////////////////////////////delay///////////////////////////////////////////
void delay(unsigned char i)
{
	while(i--)
	{
		_delay_ms(10);
	}
}