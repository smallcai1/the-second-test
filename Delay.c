#include <intrins.h>
#include "Delay.h"
// 微秒级延时 ： us表示需要延时的大致微秒数
void delay_us(unsigned int us)
{
    while (us--)
    {
        _nop_();
        _nop_();
    }
}
// 毫秒级延时 ： ms表示需要延时的大致毫秒数
void delay_ms(unsigned int ms)
{
    unsigned int i;
    while (ms--)
        for (i = 0; i < 114; i++);   /* ~1 ms at 11.0592 MHz 12T */
}
