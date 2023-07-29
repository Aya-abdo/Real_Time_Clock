/*
 * seven_seg.h
 *
 * Created: 10/10/2021 10:01:10 PM
 *  Author: MSI
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_



void seven_segment_init(unsigned char port);
void seven_segment_write(unsigned char port,unsigned char number);

#endif /* SEVEN_SEG_H_ */