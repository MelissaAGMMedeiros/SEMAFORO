/*
 * File:   semaforo.c
 * Author: 21193460
 *
 * Created on 7 de Fevereiro de 2022, 10:46
 */

#include <xc.h>

#define _XTAL_FREQ 4000000

#define LED_VD     PORTDbits.RD5
#define LED_AM     PORTDbits.RD6
#define LED_VM     PORTDbits.RD7
#define LED_VM_PD  PORTDbits.RD2
#define LED_VD_PD  PORTDbits.RD3
#define BT         PORTDbits.RD0
#define ATRASO(n)  __delay_ms(n)

#define TIMEOUT 10000

void initial(void) 
{
      // Configuração dos pinos
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD0 = 1;
    
        // Inicialização semáforo
    LED_VM = 0;
    LED_AM = 0;
    LED_VD = 0;
    LED_VD_PD = 0;
    LED_VM_PD = 0;
}
void semaforo_veiculos(void)
{
    LED_VM = 0;
    LED_AM = 0;
    LED_VD = 1;
    
    LED_VD_PD = 0;
    LED_VM_PD = 1;
    
    
}

void semaforo_atencao(void)
{
    ATRASO (2000);
    LED_VM = 0;
    LED_AM = 1;
    LED_VD = 0;
    
    LED_VD_PD = 0;
    LED_VM_PD = 1;
}

void semaforo_pedestre(void)
{
    ATRASO(3000);
    LED_VM = 1;
    LED_AM = 0;
    LED_VD = 0;
    
    LED_VD_PD = 1;
    LED_VM_PD = 0;
    ATRASO(5000);
}
char botao(void)
{
    return(BT);
}

char timeout(void)
{
    unsigned int t = TIMEOUT;
    while(t)
    {
        ATRASO(1);
        --t;
        if( botao() )
        {
            break;
        }
    }
    return( 1 );
}