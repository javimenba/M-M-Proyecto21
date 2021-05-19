/*
 * File:   main.c
 * Author: javier
 *
 * Created on 18 de mayo de 2021, 03:24 PM
 */


#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ByteConf.h"
#include "adc.h"
#include "lcd.h"
#include "timer_0.h"
#include "clock.h"
#define XTAL_FREQ 4000000
void main(void) {
    int s=0,m=0;
    OSCCON=0b01010111; //4MHz
    PORTA=0;
    LATA=0;
    ANSELA=0;
    TRISA=0;
    Lcd_Init();
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
    Lcd_Out2(1,10,"11");   
    Lcd_Out2(1,9,":"); 
    Lcd_Out2(1,7,"11");
    Lcd_Out2(1,6,":");
    Lcd_Out2(1,4,"11"); 
    while(1){
            PORTAbits.RA0^=1;
            Clock_display(23,55,45,0);
        
    }
  
}
