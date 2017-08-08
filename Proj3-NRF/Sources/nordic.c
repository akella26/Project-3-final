/**
 * @file nordic.c
 * @brief This file is to be used in project 3  - nordic seting and config and writing and reading
 *
 * @author Sowmya
 * @date Aug 2, 2017
 *
 */

#include "nordic.h"
#include "MKL25Z4.h"
#include "spi.h"
#include "gpio.h"
#include <math.h>
#include <stdint.h>

/*Only reads bytes*/
uint8_t nrf_read_register(uint8_t register_addr)
{
	uint8_t read_reg_val;
	SPI_write_byte(NRF_R_REGISTER|register_addr);
	read_reg_val = SPI_write_byte(NRF_NOP);
	return read_reg_val;
}

void nrf_write_register(uint8_t register_addr, uint8_t value)
{
	SPI_write_byte(NRF_W_REGISTER|register_addr);
	SPI_write_byte(value);
}

uint8_t nrf_read_status()
{
	uint8_t read_status_val;
	nrf_chip_enable();
	read_status_val = nrf_read_register(NRF_STATUS_REG);
	nrf_chip_disable();
	return read_status_val;
}

void nrf_write_config(uint8_t config)
{
	nrf_chip_enable();
	nrf_write_register(NRF_CONFIG_REG,config);
	nrf_chip_disable();
}

uint8_t nrf_read_config()
{
	uint8_t read_config_val;
	nrf_chip_enable();
	read_config_val = nrf_read_register(NRF_CONFIG_REG);
	nrf_chip_disable();
	return read_config_val;
}

uint8_t nrf_read_rf_setup()
{
	uint8_t read_rfsetup_val;
	nrf_chip_enable();
	read_rfsetup_val = nrf_read_register(NRF_RF_SETUP);
	nrf_chip_disable();
	return read_rfsetup_val;
}

void nrf_write_rf_setup(uint8_t config)
{
	nrf_chip_enable();
	nrf_write_register(NRF_RF_SETUP,config);
	nrf_chip_disable();
}

uint8_t nrf_read_rf_ch()
{
	uint8_t read_rfch_val;
	nrf_chip_enable();
	read_rfch_val = nrf_read_register(NRF_RF_CH);
	nrf_chip_disable();
	return read_rfch_val;
}

void nrf_write_rf_ch(uint8_t channel)
{
	nrf_chip_enable();
	nrf_write_register(NRF_RF_CH,channel);
	nrf_chip_disable();
}

/*Reads a 5 byte TX address*/
void nrf_read_TX_ADDR(uint8_t * address)
{
	uint8_t i;
	nrf_chip_enable();
	SPI_write_byte(NRF_R_REGISTER|NRF_TX_ADDR);
	for(i=0;i<5;i++)	//Since 5 bytes are to be read
	{
		*(address+i) = SPI_write_byte(NRF_NOP);			//0xFF is to be
	}
	nrf_chip_disable();
}

/*Writes a 5 byte TX address*/
void nrf_write_TX_ADDR(uint8_t * tx_addr)
{
	uint8_t i;
	nrf_chip_enable();
	SPI_write_byte(NRF_W_REGISTER|NRF_TX_ADDR);
	for(i=0;i<5;i++) 									//Since 5 bytes are to be read
	{
		SPI_write_byte(*(tx_addr+i));
	}
	nrf_chip_disable();
}

uint8_t nrf_read_fifo_status()
{
	uint8_t read_fifo_status;
	nrf_chip_enable();
	read_fifo_status = nrf_read_register(NRF_FIFO_STATUS);
	nrf_chip_disable();
	return read_fifo_status;
}

void nrf_flush_tx_fifo()
{
	nrf_chip_enable();
	SPI_write_byte(NRF_FLUSH_TX);
	nrf_chip_disable();
}

void nrf_flush_rx_fifo()
{
	nrf_chip_enable();
	SPI_write_byte(NRF_FLUSH_RX);
	nrf_chip_disable();
}

