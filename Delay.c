#include <intrins.h>
#include "Delay.h"

/* 11.0592 MHz, 12T: 1 machine cycle ˜ 1.085 us */

void delay_us(unsigned int us)
{
    while (us--)
    {
        _nop_();
        _nop_();
    }
}

void delay_ms(unsigned int ms)
{
    unsigned int i;
    while (ms--)
        for (i = 0; i < 114; i++);   /* ~1 ms at 11.0592 MHz 12T */
}
