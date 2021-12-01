#include<avr/io.h>
#include <util/delay.h>
#include "dot1.h"
#define F_CPU 1600000UL

void dot1()
{
    DDRD &= ~(1<<PD1);
    DDRD &= ~(1<<PD2);  //input pin Port D pin 1

    /*Giving logic HIGH for the input pins*/
    PORTD |= (1<<PD1);
    PORTD |= (1<<PD2);

    /*Giving the output @ pin0 Port B */
    DDRB |= (1<<PB0);

    if  ( (!(PIND & (1<<PD1))) & (!(PIND & (1<<PD2))) )
    {
        PORTB |= (1<<PB0);   //Turns on the LED if both the switches are turned on by the user
        _delay_ms(150);
    }
    else
    {
       PORTB &= ~(1<<PB0);  //Turns Off the LED
        _delay_ms(150);
    }
}
