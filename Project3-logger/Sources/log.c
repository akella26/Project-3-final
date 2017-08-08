/**
 * @file log.c
 * @brief This file is to be used to project 3 logging configuration
 * Memory transfer using DMA is done here
 * @author Sowmya
 * @date Aug 2, 2017
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "log.h"
#include "uart.h"
#include "conversion.h"
#include "MKL25Z4.h"


#if(BBB)
LOG_STAT log_data(uint8_t * data, size_t len)
{
	size_t i;
	if(data == NULL)
	{
		log_status = LOG_STAT_NULL_ERROR;
	}
	for(i=0;i<len;i++)
	{
		printf("%d",*(data+i));
	}
	log_status = LOG_STAT_SUCCESS;
	return log_status;
}

LOG_STAT log_string(uint8_t * string)
{
	if(string == NULL)
	{
		log_status = LOG_STAT_NULL_ERROR;
	}
	size_t i=0;
	while(*(string+i) != '\0')
	{
		printf("%d",*(string+i));
		i++;
	}
	log_status = LOG_STAT_SUCCESS;
	return log_status;
}

LOG_STAT log_integer(uint8_t integ)
{
	printf("\n integer is %d\n",integ);
}

LOG_STAT log_flush()
{

}
#endif

#if(FRDM_BLOCK)

LOG_STAT log_data(uint8_t * data, size_t len)
{
	uint8_t i;
	if(data == NULL)
	{
		log_status = LOG_STAT_NULL_ERROR;
	}
	if((*data >= '!' && *data  <= '~'))
		UART_send_n(data,len);
	else
	{
		for(i=0;i<len;i++)
		{
			log_integer(*data);
			data++;
		}
	}
	log_status = LOG_STAT_SUCCESS;
	return log_status;
}

LOG_STAT log_string(uint8_t * string)
{
	if(string == NULL)
	{
		log_status = LOG_STAT_NULL_ERROR;
	}
	uint32_t i=0;
	while(*(string) != '\0')
	{
			UART_send(string);
			string++;
	}
	log_status = LOG_STAT_SUCCESS;
	return log_status;
}

LOG_STAT log_integer(uint32_t num)
{
	uint8_t string_1[32];
	uint8_t *temp=string_1;
	/* Converting Integer to Ascii */
	my_itoa(num,temp,10);
//	if(*temp == '\0')
//	{
//		UART_send(temp);
//	}
	while(*temp != '\0'){
		UART_send(temp);
		temp++;
	}
	log_status = LOG_STAT_SUCCESS;
	return log_status;
}

void create_log_item(BinLogger * log_str,BinLogType_enum logIDtype,uint32_t length, uint8_t * payload)
{
		uint32_t i;
		if(length == 0)
		{
			log_str->payload = (uint8_t*)calloc(1,sizeof(uint8_t));
		}
		else
		{
			log_str->payload = (uint8_t*)calloc(length,sizeof(uint8_t));
		}
		log_str->logID = logIDtype;
		log_str->loglength = length;

		uint8_t * temp = log_str->payload;
		if(length != 0)
		{

			for(i=0;i<length;i++)
			{
				*(temp) = *payload;
				payload++;
				temp++;
			}
		}
		else							//Assign one byte of data which is 0
		{
			*(log_str->payload) = *payload;
		}
}

void log_item(BinLogger * log_str,uint32_t length)
{
	uint32_t i=0;
	uint8_t dummy=0,dummy2=0;
	LOG_RAW_STRING("|LogID:");
	LOG_RAW_INTEGER(log_str->logID);
	LOG_RAW_STRING("|LogTime:");
	log_str->timestamp = RTC_TSR;
	LOG_RAW_INTEGER(log_str->timestamp);
	LOG_RAW_STRING("|LogPayload:");
	if((log_str->loglength) != 0)
	{
		for(i=0;i<log_str->loglength;i++)
		{
			LOG_RAW_INTEGER(*(log_str->payload));
			log_str->payload++;
		}
	}
	else									//Assign one 0 byte
		LOG_RAW_INTEGER(*(log_str->payload));
}

void destroy_item(BinLogger * log_str)
{
	free(log_str->payload);
}

#endif



