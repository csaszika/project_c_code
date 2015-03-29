/*
 * projekt_footballGoal_2015.c
 *
 * Created: 2015.03.16. 22:14:18
 *  Author: csaszi_win7
 */ 
/*
typedef signed char		int8_t

typedef unsigned char 	uint8_t

typedef signed int		int16_t

typedef unsigned int 	uint16_t

typedef signed long int 	int32_t

typedef unsigned long int 	uint32_t

typedef signed long long int 	int64_t

typedef unsigned long long int 	uint64_t
*/
#define F_CPU (16000000UL)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "clocksignsTimerInits.h"
#include "receiversExtIntsInits.h"
#include "timeCounterForSpeedCalcuating.h"
#include "muxReader.h"

void init();
void delay(unsigned);

volatile uint16_t time1=0;		//1,3,5,7 vev� �ltal ind�tott id�sz�ml�l�
volatile uint16_t time2=0;		//0,2,4,6 vev� �ltal ind�tott id�sz�ml�l�
volatile uint16_t speed=0;		//km/h , lenne a c�l
volatile uint32_t ballDiameter=68120000;	//nanometer KORREKCI� kell

volatile char vizszintesPoz[16]={0};	//poz�ci� v�geredm�ny t�mb�k
volatile char fuggolegesPoz[16]={0};
	
volatile char atmenetiVizszintesPoz[8]={0};	//poz�ci� beolvas�s ezekbe a t�mb�kbe t�rt�nik
volatile char atmenetiFuggolegesPoz[8]={0};

int main(void)
{
    while(1)
    {
        //TODO:: Please write your application code 
    }
}