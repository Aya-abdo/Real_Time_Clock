/*
 * seven_seg.c
 *
 * Created: 10/10/2021 10:01:55 PM
 *  Author: MSI
 */ 
#include "DIO.h"


void seven_segment_init(unsigned char port)
{
	DIO_SET_PORT_DIR(port,0xff);
}
void seven_segment_write(unsigned char port,unsigned char number)
{
	
	
	
unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};


DIO_PORT_WRITE(port,arr[number]);
}