/*
 * File:   delay.c
 * Author: 21193460
 *
 * Created on 11 de Fevereiro de 2022, 11:29
 */


#include <xc.h>
#include "delay.h"

#define _XTAL_FREQ 4000000

void delay( unsigned int t )
{
    while( t )
    {
        __delay_ms( 1 );
        --t;
    }
}
