/*
 * GccApplication6.c
 *
 * Created: 11/5/2020 6:31:55 PM
 * Author : Joshua
 */ 
#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>
#include "adxl362.h"
#include "SSD1306.h"
//#define ADXL_CS_HIGH PORTB |= (1<<PINB2)
//#define ADXL_CS_LOW &= ~(1<<PINB2)
uint16_t accel=0;
uint16_t steps=0;
//uint16_t adc_read(uint8_t adcx);

int main(void)
{
    /* Replace with your application code */
   //uart_init();
   adxl362_begin();
   //stdout = &uart_output;
   //stdin  = &uart_input;
   OLED_Init();
   OLED_Clear();
   //OLED_EnableInversion();
   ADCSRA |= _BV(ADEN);
   OLED_SetCursor(0,0);
	OLED_Printf("388 Pedometer");
	OLED_SetCursor(2,2);
	OLED_Printf("Steps Taken:");
	
	
	
		  //char* buffer[12];

   //write_reg(0x2A,0b11000000);
   //config_act_int(1,1);
   
   while (1) {
	  
	accel=read_axis(0);
	OLED_DisplayNumber(C_BINARY_U8, accel, 12);
	//OLED_Printf("hello");
	 _delay_ms(100);

	 
	   
   }
   
   return 0;
}

uint16_t adc_read(uint8_t adcx)
{
	ADMUX &= 0xf0;
	ADMUX |= adcx;
	ADCSRA |= _BV(ADSC);
	while (ADCSRA & _BV(ADSC));
	return ADC;
	
}