/**
 * @file project3.h
 * @brief This file is the header files and function prototypes need to test SPI driver and
 * Nordic chip communication
 *
 * @author Sowmya Akella
 * @date Aug 2, 2017
 *
 */

#ifndef __PROJECT3_H__
#define __PROJECT3_H__

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef enum
{
	SPI_TEST_SUCCESS = 0,
	SPI_TEST_ERROR
}spi_teststat;

spi_teststat spi_stat;		//Error enum declaration


/* Function to test SPI code
 * Inputs - None
 * Returns - SPI_teststat error code
`*/
spi_teststat test_spi();

#endif /* __PROJECT3_H__ */
