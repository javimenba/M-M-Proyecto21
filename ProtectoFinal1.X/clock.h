#ifndef CLOCK_H
#define CLOCK_H

#include <xc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lcd.h"
#include "timer_0.h"
#include "adc.h"
#define _XTAL_FREQ 4000000
void Clock_display(int h, int m, int s, int stop);

#endif