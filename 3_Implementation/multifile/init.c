#define PIN_LED1 6
#define PIN_LED2 7
#define PIN_LED3 8
#define ADCPIN 0
 
#include <avr/interrupt.h>
#include "gpiolib.h"
#include "timer4clocklib.h"
#include "i2c.h"
#include "i2cdisplay.h"
#include "adc.h"
 
 
void initialize(){
     
    char openingText[] = "www.hdhprojects.nl";
    char clockText[] = "Clock";
    char adcText[] = "ADC";
    int i;
 
    cli();//interrupts disable
    tmr2_init(); // initialize timer2
    i2c_init(); // initialize i2c protocol
    i2cLcd_Init(); // initialize i2c lcd
    adc_init(); // initialize the ADC
    sei();//interrupts enable
     
    clear();
    setCursor(1,0);
    for(i=0; i<18; i++){     
        writeI2cDisplay(openingText[i], DATAREGISTER);
    }
     
    setCursor(1,2);
    for(i=0; i<5; i++){
        writeI2cDisplay(clockText[i], DATAREGISTER);
    }
     
    setCursor(10,2);
    writeI2cDisplay(':', DATAREGISTER);
     
    setCursor(1,3);
    for(i=0; i<3; i++){
        writeI2cDisplay(adcText[i], DATAREGISTER);
    }
     
     
    pinMode(PIN_LED1,PINMODEOUTPUT); //set pin to output
    pinMode(PIN_LED2,PINMODEOUTPUT); //set pin to output
    pinMode(PIN_LED3,PINMODEOUTPUT); //set pin to output    
}