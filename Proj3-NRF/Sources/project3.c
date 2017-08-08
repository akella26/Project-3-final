/**
 * @file project3.c
 * @brief This file is to be used in project 3 for testing SPI driver and Nordic.c
 *
 * @author Sowmya
 * @date Aug 2, 2017
 *
 */

#include "gpio.h"
#include "spi.h"
#include "MKL25Z4.h"
#include "nordic.h"
#include "project3.h"

void project3()
{
	spi_stat = test_spi();

	while(1)			//Used for single stepping
	{

	}
}

spi_teststat test_spi()
{
	uint8_t read_config_val = 0x00,read_stat_reg = 0x00,read_rf_setup = 0x00,read_rch_val=0x00,read_FIFOstat_reg = 0x00;
	uint8_t tx_addr[5] = {0x01,0x02,0x03,0x04,0x05};
	uint8_t rx_addr[5] = {0x00,0x00,0x00,0x00,0x00};
	uint8_t result_count[6]= {0},test_count = 0,i=0;

	GPIO_nrf_init();
	SPI_init();

	nrf_write_config(0x03);														//SPI TEST 1, power up, RX
	read_config_val = nrf_read_config();
	if(read_config_val == 0x03)
	{
		result_count[0] = 1;
	}

	read_stat_reg = nrf_read_status();											//SPI TEST 2

	if(read_stat_reg == 0x0E)													//Status returns that TX and RX FIFO are empty
	{
			result_count[1] = 1;
	}

	nrf_write_TX_ADDR(tx_addr);													//SPI TEST 3
	nrf_read_TX_ADDR(rx_addr);
	result_count[2] = 1;
	for(i=0;i<5;i++)
	{
		if(rx_addr[i] != tx_addr[i])
		{
			result_count[2] = 0;
		}
	}

	nrf_write_rf_setup(0x07);													//SPI TEST 4,  Setup LNA gain, 0dBm gain
	read_rf_setup = nrf_read_rf_setup();
	if(read_rf_setup == 0x07)
	{
			result_count[3] = 1;
	}

	nrf_write_rf_ch(0x03);														//SPI TEST 5 , Channel 3(to test anything other than channel 2
	read_rch_val = nrf_read_rf_ch();
	if(read_rch_val == 0x03)
	{
				result_count[4] = 1;
	}

	read_FIFOstat_reg = nrf_read_fifo_status();									//SPI TEST 6
	if(read_FIFOstat_reg == 0x11)					//returns both TX FIFO and RX FIFO as empty
	{
			result_count[5] = 1;
	}

	for(i=0;i<6;i++)
	{
		test_count += result_count[i];
	}
	if(test_count != 6)
	{
		spi_stat = SPI_TEST_ERROR;
	}
	else
		spi_stat = SPI_TEST_SUCCESS;

	return spi_stat;
}

