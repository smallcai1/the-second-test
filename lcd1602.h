#ifndef __LCD1602_H__
#define __LCD1602_H__

// 用户调用函数（原始接口，大写）：
void LCD_Init1();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);

// 兼容本工程 main.c 使用的小写接口：
void lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(unsigned char row, unsigned char col);
void lcd_write_data(unsigned char value);
void lcd_write_cgram(unsigned char addr, unsigned char *pattern);

#endif
