#include <avr/io.h>
#include"dot1.h"
#include"dot2.h"
#include"dot3.h"
#include<util/delay.h>
#define F_CPU 1600000UL
int main(void)
{
    LCD_INITIALIZATION();
    while(1)
    {
        dot1(); //Activity 1
        dot2(); //Activity 2
        dot3(); //Activity 3
    }
  return 0;
}