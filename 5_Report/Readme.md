
In this project I tested the analog to digital converter (ADC) from the Atmega328p. It read’s out an analog pin and shows the value on an i2c lcd. There are 6 analog ports and 2 are already used for the lcd. To change the voltage at the analog pin I used a 10k potmeter. The ADC can be set to free running mode or single conversion mode. Free running mode means the ADC samples continuously and single conversion mode means, only sample when you order to do so. I use the single conversion mode in this project.

The working of the ADC:
The first thing that’s needed to be done is initializing the ADC. I used a separate function called adc_init() in the file adc.c to get this done. For a proper initialization a few registers have to be set. For single conversion mode not all registers are used therefor I only describe the used registers in this project.

The ADMUX register is dealing with the voltage reference and the analog pin(s) that will be used.


![image](https://user-images.githubusercontent.com/62556829/144391733-f6a0928d-baae-459d-b8eb-1ccf6f2c6ff1.png)

Bit 6 and 7 tells the Atmega328p against what reference the voltage on the pin should be measured. This is important for the precision of the 10 bit read value. For example, it is possible to put 2V as a reference on the AREF pin. In that case the 10 bits (value up to 1023) will be divided over 2V. It’s more presice. It also means that every voltage above 2V on the analog pin will be presented as 1023. In this project I used Avcc (5V) as a reference therefor bit REFS0 is set.

![image](https://user-images.githubusercontent.com/62556829/144391906-c97392e8-3818-416f-bc9b-ab8899695955.png)

The last register I use for initializing is the ADCSRA register.

![image](https://user-images.githubusercontent.com/62556829/144392068-3e36d6bb-0ad4-4696-84a5-fb17a068f4ea.png)



Bit 7 is the ADC enable and needs to be set to activate the ADC. Bit 6 is the ADC start conversion, this is used in the application every time you need to read a value from the analog pin. Bit 5-3 is used for interrupts and triggering on certain conditions. Not used in this project. Bit 2 – 0 sets a prescaler. The 16MHz external clock gets divided by this prescaler to set the sampling rate. In this project all 3 bits are set, which gives a division factor of 128. The Atmega328p ADC circuit needs a clock below 200 KHz to get a 10 bit resolution and by using a higher frequentie the resolution will only be 8 bits, but then you will have a faster sampling rate. In this project I use 16 MHz / 128 to get 125 KHz. This is below 200 KHz so it will provide the full 10 bits resolution.

![image](https://user-images.githubusercontent.com/62556829/144393053-280f384d-fdf4-475e-a3e6-5ecbdbe716a8.png)
