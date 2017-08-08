/**
 * @file gpio.h
 * @brief This file is the header files and function prototypes needed for
 * GPIO pin setting for SPI communication with Nordic device
 *
 * @author Sowmya Akella
 * @date Aug 2, 2017
 *
 */

#ifndef __GPIO_H__
#define __GPIO_H__

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/*
Initializes GPIO pins of NRF module and SPI module
Inputs - None
Returns - None
*/
void GPIO_nrf_init();


/* Macro to select the chip select/slave select. Setting is done by making the bit 0
`*/
#define nrf_chip_enable() PTC_BASE_PTR->PCOR = 1 << 4;

/* Macro to de-select the chip select/slave select. Setting is done by making the bit 1
`*/
#define nrf_chip_disable() PTC_BASE_PTR->PSOR = 1 << 4;

/* Macro to select the chip enable. Setting is done by making the bit 1
`*/
#define nrf_transmit_enable() PTC_BASE_PTR->PSOR = 1 << 8;

/* Macro to select the chip enable. Setting is done by making the bit 0
`*/
#define nrf_transmit_disable() PTC_BASE_PTR->PCOR = 1 << 8;

#endif /* __GPIO_H__ */
