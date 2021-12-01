#include <avr/io.h>
#include <stdlib.h>
#include "i2c.h"
#include "i2cdisplay.h"
#include "timer4clocklib.h"
#include "adc.h"
 
#define ADCPIN 2
#define DELAYMILIS 150 // Led blinking wait time in milliseconds
#define TIMER_IS_NOT_SET 0
#define TIMER_IS_SET 1
 
void showTime(); // showing the time
void showAdcValue(); // showing the ADC value
 
/****************************************************************************
    Public vars
****************************************************************************/
 
extern int alarmCode;
extern int timeSecApp1;
extern int timeMinApp1;
int oldTime;
 
 
int timerSet4Adc = TIMER_IS_NOT_SET;
unsigned long int endTimeAdc = 0;
 
 
void Application1(void){
 
    if(timerSet4Adc == TIMER_IS_NOT_SET){
        endTimeAdc = msCounter + DELAYMILIS;
        timerSet4Adc = TIMER_IS_SET;
        showAdcValue();
    }
    if(endTimeAdc < msCounter){ // Timer is expired
        timerSet4Adc = TIMER_IS_NOT_SET; // reset timer
        return;
    }
 
     
    showTime();
     
}
 
void showTime(){
    int seconds;
    int minutes;
     
     
    seconds = timeSecApp1;
    minutes = timeMinApp1;
     
    if (oldTime == timeSecApp1){
        return;
    }
    if (seconds >= 10){
        setCursor(11,2);
        writeI2cDisplay(seconds/10+48, DATAREGISTER);
        setCursor(12,2);
        writeI2cDisplay(seconds%10+48, DATAREGISTER);
        if (minutes>=10){
            setCursor(8,2);
            writeI2cDisplay(minutes/10+48, DATAREGISTER);
            setCursor(9,2);
            writeI2cDisplay(minutes%10+48, DATAREGISTER);
        }
        if (minutes<10){
            setCursor(8,2);
            writeI2cDisplay('0', DATAREGISTER);
            setCursor(9,2);
            writeI2cDisplay(minutes+48, DATAREGISTER);
        }
    }
    else if (seconds < 10){
        setCursor(12,2);
        writeI2cDisplay(seconds+48, DATAREGISTER);
        setCursor(11,2);
        writeI2cDisplay('0', DATAREGISTER);
        if (minutes>=10){
            setCursor(8,2);
            writeI2cDisplay(minutes/10+48, DATAREGISTER);
            setCursor(9,2);
            writeI2cDisplay(minutes%10+48, DATAREGISTER);
        }
        if (minutes<10){
            setCursor(8,2);
            writeI2cDisplay('0', DATAREGISTER);
            setCursor(9,2);
            writeI2cDisplay(minutes+48, DATAREGISTER);
        }
    }
    oldTime = timeSecApp1;
}
 
void showAdcValue(){
     
    uint16_t adcReadedValue;
    uint8_t hundreds;
    uint8_t tens;
     
    adcReadedValue = adc_read(ADCPIN);
    setCursor(8,3);
     
    if(adcReadedValue > 999){
        writeI2cDisplay('1', DATAREGISTER);
        adcReadedValue -= 1000;
    }
    else{
        writeI2cDisplay('0', DATAREGISTER);
    }
    hundreds = adcReadedValue / 100;
    adcReadedValue %= 100;
    writeI2cDisplay(hundreds + 48, DATAREGISTER);
    tens = adcReadedValue /10;
    adcReadedValue %= 10;
    writeI2cDisplay(tens + 48, DATAREGISTER);
    writeI2cDisplay(adcReadedValue + 48, DATAREGISTER);
     
}