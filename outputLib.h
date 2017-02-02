#include "globalKernelInfo.h"

/* 
description:
	contains output functions 
 */

#define VIDEO_MEMORY_START	0xb8000
#define VIDEO_MEMORY_LENGTH 	32000
#define WRAP_SIZE 		75
#define TOTAL_LINE_SIZE		80
#define NEWLINE_WRAP_ADDITION	(TOTAL_LINE_SIZE - WRAP_SIZE)

/* text color definitions */
#define ORANGE_ON_BLACK 	0x6
#define RED_ON_BLACK 		0X4
#define LIGHT_BLUE_ON_BLACK 	0x3	
#define GREEN_ON_BLACK		0x2
#define DEFAULT_COLOR 		0x7 // default color scheme

/* OOC (Output Offset Container) : this data structure will hold information about the 
 current states of the output screen. */
struct OOC_object {
	unsigned int offset; // latest character printed offset
	unsigned int current_line_offset;
};

void initiateOOC(void) {
	struct OOC_object *OOC = (struct OOC_object *)OOC_OFFSET;
	OOC->offset = 0;
	OOC->current_line_offset = 0;
}

void clearScreen(void) {
	struct OOC_object *OOC = (struct OOC_object *)OOC_OFFSET;
	unsigned int i = 0;
	unsigned char *vidmem = (unsigned char *)VIDEO_MEMORY_START;
	unsigned int upper_bound = VIDEO_MEMORY_LENGTH -1;
	for(i; i < VIDEO_MEMORY_LENGTH; i++) {
		vidmem[i] = 0;
		vidmem[i + 1] = 0;
	}
	OOC->offset = 0;
	OOC->current_line_offset = 0;
}

void itoa(unsigned int *integer, unsigned int *color) {
	if(color == NULL) {
		*color = DEFAULT_COLOR;
	}
	unsigned int digit;
	while(digit != 0) {
		;
	}
}

void sprint(char *string, unsigned int *color) {
	if(color == NULL) {
		*color = DEFAULT_COLOR;
	}
	struct OOC_object *OOC = (struct OOC_object *)OOC_OFFSET;
	unsigned char *vidmem = (unsigned char *)(VIDEO_MEMORY_START + 2*OOC->offset);
	unsigned int counter = 0;
	while(*string != 0) {
		if(*string == '\n') {
			OOC->offset += TOTAL_LINE_SIZE - OOC->current_line_offset;
			OOC->current_line_offset = 0;
			vidmem[counter + 1] = *color;
			counter += 2;
			string++;
		}else{
			vidmem[counter] = *string;
			vidmem[counter + 1] = *color;
			counter += 2;
			string++;
			OOC->offset++;
			OOC->current_line_offset++;
		}	
		/*OOC->offset++;
		OOC->current_line_offset++;*/
		if(OOC->current_line_offset >= WRAP_SIZE) {  // wrapping
			OOC->offset += NEWLINE_WRAP_ADDITION;
			OOC->current_line_offset = 0;
		}
}}
