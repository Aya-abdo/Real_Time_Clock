/*
 * RESL_TIME_CLOCK.c
 *
 * Created: 8/10/2022 2:00:01 AM
 *  Author: MSI
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "KEY_PAD.h"
#include "Timer.h"
#include "seven_seg.h"
#include <avr/interrupt.h>
unsigned char value=0xff,minutes=0,hours=0,num=0xff,num2=0xff,f=0;
volatile unsigned seconds=0;
int main(void)
{
	seven_segment_init('A');
	Timer2_RTC_interrupt();
	LCD_init();
	key_pad_init();
	DIO_SET_DIR('C',0,1);
	DIO_SET_DIR('C',1,1);
    DIO_SET_DIR('C',2,1);
	DIO_SET_DIR('C',3,1);
	DIO_SET_DIR('C',4,1);
	DIO_SET_DIR('C',5,1);
	DIO_SET_DIR('B',3,1);
	LCD_send_string("press = to set");
    while(1)
    {
	
		

  
   
    

		 value=key_pad_check_press();
    
	
	 if(value!=0xff)
	 {
		  if (value=='=')
		  {
			  _delay_ms(200);
			  f=1;
			  LCD_clear();
			  LCD_send_string("hours=");
			  do
			  {
				  num=key_pad_check_press();
			  } while (num==0xff);
			  _delay_ms(200);
			  LCD_send_char(num);
			  
			  do
			  {
				  num2=key_pad_check_press();
			  } while (num2==0xff);
			  _delay_ms(200);
			  LCD_send_char(num2);
			  hours=((num-'0')*10)+(num2-'0');
			  
			  
			  _delay_ms(500);
			  LCD_clear();
			  LCD_send_string("minutes=");
			  num=0xff,num2=0xff;
			  do
			  {
				  num=key_pad_check_press();
			  } while (num==0xff);
			  _delay_ms(200);
			  LCD_send_char(num);
			  
			  do
			  {
				  num2=key_pad_check_press();
			  } while (num2==0xff);
			  _delay_ms(200);
			  LCD_send_char(num2);
			  minutes=((num-'0')*10)+(num2-'0');
			  
			  _delay_ms(500);
			  LCD_clear();
			  LCD_send_string("seconds=");
			  num=0xff,num2=0xff;
			  do
			  {
				  num=key_pad_check_press();
			  } while (num==0xff);
			  _delay_ms(200);
			  LCD_send_char(num);
			  
			  do
			  {
				  num2=key_pad_check_press();
			  } while (num2==0xff);
			  _delay_ms(200);
			  LCD_send_char(num2);
			  seconds=((num-'0')*10)+(num2-'0');
			  _delay_ms(500);
			  LCD_clear();
			  
		  }
		  else
		  {
			  LCD_clear();
			  LCD_send_string("wrong choice");
			  _delay_ms(1000);
			  LCD_clear();
			  LCD_send_string("press = to set");
			  
		  }
	 }
	
	

		  DIO_WRITE('C',0,1);
		  DIO_WRITE('C',1,1);
		  DIO_WRITE('C',2,1);
		  DIO_WRITE('C',3,1);
		  DIO_WRITE('C',4,1);
		  DIO_WRITE('C',5,0);
		  
		  seven_segment_write('A',hours/10);
		  _delay_ms(5);
		  DIO_WRITE('C',0,1);
		  DIO_WRITE('C',1,1);
		  DIO_WRITE('C',2,1);
		  DIO_WRITE('C',3,1);
		  DIO_WRITE('C',4,0);
		  DIO_WRITE('C',5,1);
		  
		  seven_segment_write('A',hours%10);
		   _delay_ms(5);
		  DIO_WRITE('C',0,1);
		  DIO_WRITE('C',1,1);
		  DIO_WRITE('C',2,1);
		  DIO_WRITE('C',3,0);
		  DIO_WRITE('C',4,1);
		  DIO_WRITE('C',5,1);
		 
		  
		  seven_segment_write('A',minutes/10);
		   _delay_ms(5);
		  DIO_WRITE('C',0,1);
		  DIO_WRITE('C',1,1);
		  DIO_WRITE('C',2,0);
		  DIO_WRITE('C',3,1);
		  DIO_WRITE('C',4,1);
		  DIO_WRITE('C',5,1);
		  
		  seven_segment_write('A',minutes%10);
		   _delay_ms(5);
		  DIO_WRITE('C',0,1);
		  DIO_WRITE('C',1,0);
		  DIO_WRITE('C',2,1);
		  DIO_WRITE('C',3,1);
		  DIO_WRITE('C',4,1);
		  DIO_WRITE('C',5,1);
		  
		  seven_segment_write('A',seconds/10);
		  _delay_ms(5);
		  DIO_WRITE('C',0,0);
		  DIO_WRITE('C',1,1);
		  DIO_WRITE('C',2,1);
		  DIO_WRITE('C',3,1);
		  DIO_WRITE('C',4,1);
		  DIO_WRITE('C',5,1);
		  
		  seven_segment_write('A',seconds%10);
		  _delay_ms(5);
	
		if (seconds>=60)
		{
			minutes++;
			seconds=0;
		}
		if (minutes>=60)
		{
			hours++;
			minutes=0;
		}
		if (hours>=24)
		{
			hours=0;
			
		}
	
		  
	 }	
}
ISR(TIMER2_OVF_vect)
{
	seconds++;
}