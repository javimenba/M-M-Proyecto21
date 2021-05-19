/*
 * File:   timer_o.c
 * Author: javier
 *
 * Created on 18 de mayo de 2021, 03:37 PM
 */


#include <pic18f45k50.h>

#include "timer_0.h"
void TMRON( int prescaler, int tmroh, int tmrol){
    TMR0H=tmroh;
    TMR0L= tmrol;           
    T0CON=prescaler + 0x00;
    T0CONbits.TMR0ON=1;
    while(!INTCONbits.TMR0IF);
    T0CONbits.TMR0ON=0;
    INTCONbits.TMR0IF=0;
}

         