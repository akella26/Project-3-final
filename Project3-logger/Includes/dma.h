/**
 * @file DMA.h
 * @brief This file is to be used to project 1.
 *
 * @author Sowmya Akela
 * @date Aug 2, 2017
 *
 */
#ifndef __DMA_H__
#define __DMA_H__

#include <stdint.h>
#include <stdio.h>
#include "memory.h"

//Set contains values of uint8_t type, so will not be able to test with numbers for 1000 and 5000 bytes
#define DMA_BUFF_SIZE 200
#define DMA_TRANS_BYTE_SIZE 100
#define TRANS_SIZE 8

#if(TRANS_SIZE == 32)
#define DMA_NO_BYTES_TRANS_SIZE 0
#elif(TRANS_SIZE == 8)
#define DMA_NO_BYTES_TRANS_SIZE 1
#else
#define DMA_NO_BYTES_TRANS_SIZE 2
#endif

#define DMA_TEST_NO_ERROR 0
#define DMA_TEST_ERROR 1


/*
DMA configuration by enabling clocks and clearing flags and register before setting
Inputs - None
Returns - None
*/
void DMA_config();

/*
DMA registers are set and type of transfer setting done
Inputs - None
Returns - None
*/
void DMA_maskset();

/*
Sets the start flag for DMA transfer
Inputs - None
Returns - None
*/
void DMA_start();

/*
Sets the source increment register for memmove. Not called for memset as SINC is not reqd
Inputs - None
Returns - None
*/
void DMA_SINC_mask_set();

/*
Sets memory from source address to a given value for a given length in DMA
Inputs - src address pointer, destination value address pointer, length of bytes to transfr
Returns - None
*/
void memset_DMA(uint8_t * src, uint32_t length, uint8_t * value);

/*
Moves memory from source address to destination address of given length in DMA
Inputs - src address pointer, destination address pointer, length of bytes to transfr
Returns - None
*/
void memmove_DMA(uint8_t * srcAddr, uint8_t * destAddr, uint32_t length);

#endif /* __DMA_H__ */
