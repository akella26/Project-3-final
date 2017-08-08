/**
 * @file nordic.h
 * @brief This file is the header files and function prototypes needed for compiling the memory.c file
 * This file contains standard include libraries and memory manipulation header files
 *
 * @author Sowmya Akella
 * @date Aug 2, 2017
 *
 */

#ifndef __NORDIC_H__
#define __NORDIC_H__

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>


//Register Addresses
#define NRF_CONFIG_REG 	(0x00)
#define NRF_EN_AA   	(0x01)
#define NRF_EN_RXADDR   (0x02)
#define NRF_SETUP_AW    (0x03)
#define NRF_SETUP_RETR  (0x04)
#define NRF_RF_CH       (0x05)
#define NRF_RF_SETUP    (0x06)
#define NRF_STATUS_REG  (0x07)
#define NRF_OBSERVE_TX  (0x08)
#define CD          	(0x09)
#define NRF_RX_ADDR_P0  (0x0A)
#define NRF_RX_ADDR_P1  (0x0B)
#define NRF_RX_ADDR_P2  (0x0C)
#define NRF_RX_ADDR_P3  (0x0D)
#define NRF_RX_ADDR_P4  (0x0E)
#define NRF_RX_ADDR_P5  (0x0F)
#define NRF_TX_ADDR     (0x10)
#define NRF_RX_PW_P0    (0x11)
#define NRF_RX_PW_P1    (0x12)
#define NRF_RX_PW_P2    (0x13)
#define NRF_RX_PW_P3    (0x14)
#define NRF_RX_PW_P4    (0x15)
#define NRF_RX_PW_P5    (0x16)
#define NRF_FIFO_STATUS (0x17)
#define NRF_DYNPD	    (0x1C)
#define NRF_FEATURE	    (0x1D)

#define NRF_POWER_UP 		(1)
#define NRF_POWER_DOWN	 	(0)
#define NRF_POWER_UP_MASK (0x02)

/*Instruction mnemonics*/
#define W_TXPAYLOAD		(0xA0)
#define R_RXPAYLOAD		(0x61)
#define NRF_R_REGISTER	(0x00)
#define NRF_W_REGISTER	(0x20)
#define NRF_NOP			(0xFF)
#define NRF_FLUSH_TX	(0xE1)
#define NRF_FLUSH_RX	(0xE2)

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
uint8_t nrf_read_register(uint8_t register_addr);

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
void nrf_write_register(uint8_t register_addr, uint8_t value);

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
uint8_t nrf_read_status();

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
void nrf_write_config(uint8_t config);

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
uint8_t nrf_read_config();

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
uint8_t nrf_read_rf_setup();

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
void nrf_write_rf_setup(uint8_t config);

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
uint8_t nrf_read_rf_ch();

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
void nrf_write_rf_ch(uint8_t channel);

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
void nrf_read_TX_ADDR(uint8_t * address);

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
void nrf_write_TX_ADDR(uint8_t * tx_addr);

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
uint8_t nrf_read_fifo_status();

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
void nrf_flush_tx_fifo();

/* Enables the CS pin by setting it low for enabling SPI but not RF communication
 * NOTE : my_memmove() checks the lengths of source and destination hence no memory is corrupted
 * Inputs - pointer to source, pointer to destination, length of the bytes to be copied
 * Returns - uint8_t error code
`*/
void nrf_flush_rx_fifo();


#endif /* __NORDIC_H__ */
