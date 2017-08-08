/**
 * @file spi.h
 * @brief This file is the header files and function prototypes for the SPI driver in project3
 *
 * @author Sowmya Akella
 * @date Aug 2, 2017
 *
 */

#ifndef __SPI_H__
#define __SPI_H__

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/*
Writes bytes using SPI to the peripheral. BLocks until write is complete.
Inputs - Byte to be written
Returns - uint8_t Byte read after writing
*/
uint8_t SPI_write_byte(uint8_t byte);

/*
Reads bytes from the SPI by checking masks. BLocks until read is complete.
Inputs - Byte to be read
Returns - uint8_t byte read from SPI bus
*/
uint8_t SPI_read_byte(uint8_t byte);

/*
Initialized SPI configuration registers with baud rate and slave master config
Inputs - None
Returns - None
*/
void SPI_init(void);

/*
Sends packet of length across SPI bus
Inputs - pointer to bytes that need to be sent and length of the packet
Returns - None
*/
void SPI_send_packet(uint8_t * p, size_t length);

/*
Blocks until and SPI transmit buffer is empty
Inputs - None
Returns - None
*/
void SPI_flush();

#endif /* __SPI_H__ */
