/**
 * @file gpio.c
 * @brief This file is to be used to project 3 gpio initialization
 *
 * @author Sowmya
 * @date Aug 2, 2017
 *
 */

#include "gpio.h"
#include "MKL25Z4.h"

void GPIO_nrf_init()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;      //Turn on clock to C module since blue led connected to D port
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;       //Enable SPI0 clock
	//CS
	PTC_BASE_PTR->PDDR = (1<<4);			//Set output direction for PTC4 - CS
	nrf_chip_disable();						//Initially disabling slave select pin
	//SCK, MOSI,MISO
	PORTC_PCR4 = PORT_PCR_MUX(0x1);    		//Set PTC4 to mux 1 GPIO as we are not choosing auto Slave Select
	PORTC_PCR5 = PORT_PCR_MUX(0x2);    		//Set PTC5 to mux 2 [SPI0_SCK]
	PORTC_PCR6 = PORT_PCR_MUX(0x2);    		//Set PTC6 to mux 2 [SPI0_MOSI]
	PORTC_PCR7 = PORT_PCR_MUX(0x2);    		//Set PTC7 to mux 2 [SPIO_MISO]
	//CE
	PORTC_PCR8 = PORT_PCR_MUX(0x1);    		//Set PTC8 to mux 1 GPIO as we are not choosing auto Slave Select
	nrf_transmit_enable();					//Enabling channel enable
}


