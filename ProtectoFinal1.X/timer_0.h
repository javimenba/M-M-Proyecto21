#ifndef TMR0_H
#define TMR0_H

#include <xc.h>

#define _XTAL_FREQ 4000000
void TMRON( int prescaler, int tmroh, int tmrol);
#endif