
![image](https://user-images.githubusercontent.com/62556829/144381745-4291a511-07e6-4c4f-8a6f-76160f752b44.png)

The high-performance Microchip 8-bit AVR® RISC-based microcontroller combines 32 KB ISP Flash memory with read-while-write capabilities, 1 KB EEPROM, 2 KB SRAM, 23 general purpose I/O lines, 32 general purpose working registers, three flexible timer/counters with compare modes, internal and external interrupts, serial programmable USART, a byte-oriented Two-Wire serial interface, SPI serial port, 6-channel 10-bit A/D converter (8-channels in TQFP and QFN/MLF packages), programmable watchdog timer with internal oscillator, and five software selectable power saving modes. The device operates between 1.8-5.5 volts.
By executing powerful instructions in a single clock cycle, the device achieves throughputs approaching one MIPS per MHz, balancing power consumption and processing speed.
 


![image](https://user-images.githubusercontent.com/62556829/144382357-3dc3127f-27ac-4f41-9d96-1b75d56406d5.png)

I2C stands for Inter-Integrated Circuit. It is a bus interface connection protocol incorporated into devices for serial communication. It was originally designed by Philips Semiconductor in 1982. Recently, it is a widely used protocol for short-distance communication. It is also known as Two Wired Interface(TWI)



![image](https://user-images.githubusercontent.com/62556829/144382685-bb88b6e6-ffef-4c72-b8bd-9d69eadf4aa3.png)

The HD44780U dot-matrix liquid crystal display controller and driver LSI displays alphanumerics,
Japanese kana characters, and symbols. It can be configured to drive a dot-matrix liquid crystal display
under the control of a 4- or 8-bit microprocessor. Since all the functions such as display RAM, character
generator, and liquid crystal driver, required for driving a dot-matrix liquid crystal display are internally
provided on one chip, a minimal system can be interfaced with this controller/driver.
A single HD44780U can display up to one 8-character line or two 8-character lines.
The HD44780U has pin function compatibility with the HD44780S which allows the user to easily replace
an LCD-II with an HD44780U. The HD44780U character generator ROM is extended to generate 208 5 ×
8 dot character fonts and 32 5 × 10 dot character fonts for a total of 240 different character fonts.
The low power supply (2.7V to 5.5V) of the HD44780U is suitable for any portable battery-driven product
requiring low power dissipation.


# Adc

![image](https://user-images.githubusercontent.com/62556829/144383754-6aa57e02-6359-4a3d-a13e-2f8854757d8e.png)


The ATmega48A/PA/88A/PA/168A/PA/328/P features a 10-bit successive approximation ADC. The ADC is connected to an 8-channel Analog Multiplexer which allows eight single-ended voltage inputs constructed from the pins of Port A. The single-ended voltage inputs refer to 0V (GND).
The ADC uses registers ADMUX, ADCSRA, ADCL, ADCH, ADCSRB, and DIDR0 to configure the hardware and to do analog to digital conversion. Along with register configuration, ADC hardware also needs a separate analog supply voltage pin, AVCC. AVCC must not differ more than ±0.3V from VCC. Internal reference voltages can be set at 1.1V or AVCC. When the voltage reference is selected externally the AREF pin is connected with a capacitor for better noise performance.


