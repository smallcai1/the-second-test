#include <reg52.h>
#include "Delay.h"
#include "lcd1602.h"
#include "cat_font.h"
//将自定义的猫咪字符写入lcd的cgram，便于后续显示
void load_cat_chars(void)
{
    lcd_write_cgram(0, cat_ear_l);
    lcd_write_cgram(1, cat_top);
    lcd_write_cgram(2, cat_ear_r);
    lcd_write_cgram(3, cat_eye_open_l);
    lcd_write_cgram(4, cat_nose);
    lcd_write_cgram(5, cat_eye_open_r);
    lcd_write_cgram(6, cat_eye_close_l);
    lcd_write_cgram(7, cat_eye_close_r);
}
//在lcd上绘制猫咪图案，blink = 1 时闭眼 ， blink = 0 睁开眼睛
void draw_cat(unsigned char blink)
{
    unsigned char eye_l = blink ? 6 : 3;
    unsigned char eye_r = blink ? 7 : 5;
// 根据blink状态选择使用睁眼还是闭眼的自定义字符
    lcd_set_cursor(0, 7);
    lcd_write_data(0);
    lcd_write_data(1);
    lcd_write_data(2);

    lcd_set_cursor(1, 7);
    lcd_write_data(eye_l);
    lcd_write_data(4);
    lcd_write_data(eye_r);
}
// 主函数：初始化lcd，循环显示猫咪眨眼效果
void main(void)
{
    unsigned char state = 0;

    lcd_init();
    load_cat_chars();
    lcd_clear();

    while (1)
    {
        draw_cat(state);
        delay_ms(500);
        state = !state;
    }
}
