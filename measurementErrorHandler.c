/*
 * measurementErrorHandler.c
 *
 * Created: 2015.03.29. 23:01:45
 *  Author: csaszi_win7
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "measurementErrorHandler.h"

void measurementError(unsigned char errorType)//minden hibakezelés 
{
	switch(errorType)
	{
		case '1':break;
		case '2':break;
	}
}