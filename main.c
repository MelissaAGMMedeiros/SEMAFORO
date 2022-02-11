/*
 * File:   main.c
 * Author: 21193460
 *
 * Created on 7 de Fevereiro de 2022, 09:20
 */

#include "config.h"
#include <xc.h>
#include "semaforo.h"
#include "delay.h" 


void main(void) 
{
    initial();
    while( 1 )
    {
        semaforo_veiculos();
        
        if( timeout())
        {
           semaforo_atencao();
           semaforo_pedestre();
        }
    }
}
