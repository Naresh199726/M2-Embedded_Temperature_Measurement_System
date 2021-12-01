#include <avr/io.h>
#include "adc.h"
 
/****************************************************************************
    adc_init(), enables the ADC conversion and set's the prescaler
****************************************************************************/
void adc_init(){
     
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
 
/****************************************************************************
    adc_read(uint8_t pin), returns a value from 0 - 1023
****************************************************************************/
uint16_t adc_read(int pin){
    if(pin < 0 || pin > 7){ //ADC0 - ADC7 is available
        return 1; //pin number is out of range
    }
     
    pin &= 0x7;
    ADMUX = (ADMUX & 0xF8)|pin;
     
    ADCSRA |= (1<<ADSC);
     
    while(ADCSRA & (1<<ADSC)); //as long as ADSC pin is 1 just wait.
     
    return (ADC);
}