#ifndef __PROJECT3_H__
#define __PROJECT3_H__

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

void project3();
#define HEARTBEATLOG	0
#define DEBUG			1

/*Uncomment the type of profiling you would like to do*/

#define PROFILING 		1
#define DMA_TEST_ONLY 	0

#define MOVE      		1
#define SET       		0

#define STD_LIB_VERSION
//#define NON_DMA_O0_O3
//#define MY_DMA

/*
Moves memory from source address to destination address of given length with no overlap
Also tests for memset depending on the macro setting. Profiling is done as well
Inputs - None
Returns - Test result
*/

int8_t test_memmove_set1();
/*
Moves memory from source address to destination address of given length with end of source
and beginning of dest overlap
Inputs - None
Returns - Test result
*/
int8_t test_memmove2();

/*
Moves memory from source address to destination address of given length with end of dest
and beginning of source overlap
Inputs - None
Returns - Test result
*/
int8_t test_memmove3();

/*
Sets memory with a value from source address to destination address of given length
Inputs - None
Returns - Test result
*/
int8_t test_memset();

#endif /* __PROJECT3_H__ */
