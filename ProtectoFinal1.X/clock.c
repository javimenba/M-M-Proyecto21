/*
 * File:   clock.c
 * Author: javier
 *
 * Created on 18 de mayo de 2021, 10:33 PM
 */


#include "clock.h"
void Clock_display(int h, int m, int s, int stop){
    float celsius;
    char Temperature[10]; 
    PORTE=0;
    LATE=0;
    ANSELE=0;
    TRISE=0;
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
   
    do{     
        
            celsius = (ADC_Read(5)*4.88);
            celsius = (celsius/10.00);
            sprintf(Temperature,"%d%cC  ",(int)celsius,0xdf); 
            Lcd_Out2(2,6,Temperature);
            Lcd_Out2(2,0,"Temp:");
            
            char date[3],date1[3],date2[3];
            TMRON(0x01,0xFE,0x89);//750US
            s=s+1;
            sprintf(date,"%i",s);
            Lcd_Out2(1,10,date);   
            Lcd_Out2(1,9,":");  
            if(s==59){
                s=0;
                date[0]='0';
                date[1]=' ';
                Lcd_Out2(1,10,date);   
                Lcd_Out2(1,9,":"); 
                m=m+1;
                sprintf(date1,"%i",m);
                Lcd_Out2(1,7,date1); 
                
                celsius = (ADC_Read(5)*4.88);
                celsius = (celsius/10.00);
                sprintf(Temperature,"%d%cC  ",(int)celsius,0xdf); 
                Lcd_Out2(2,6,Temperature);
                Lcd_Out2(2,0,"Temp:");
            }
            else if(m==59){
                m=0;
                date1[0]='0';
                date1[1]=' ';
                Lcd_Out2(1,7,date1);
                Lcd_Out2(1,6,":");
                h=h+1;
                sprintf(date2,"%i",h);
                Lcd_Out2(1,4,date2); 
                
                celsius = (ADC_Read(5)*4.88);
                celsius = (celsius/10.00);
                sprintf(Temperature,"%d%cC  ",(int)celsius,0xdf); 
                Lcd_Out2(2,6,Temperature);
                Lcd_Out2(2,0,"Temp:");
            }
            else if(h==24){
                h=1;
                date2[0]='1';
                date2[1]=' ';
                Lcd_Out2(1,4,date2); 
                
                celsius = (ADC_Read(5)*4.88);
                celsius = (celsius/10.00);
                sprintf(Temperature,"%d%cC  ",(int)celsius,0xdf); 
                Lcd_Out2(2,6,Temperature);
                Lcd_Out2(2,0,"Temp:");
            }
    }while(stop==0);
} 

