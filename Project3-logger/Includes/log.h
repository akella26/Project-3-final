/**
 * @file log.h
 * @brief This file is the header files and function prototypes needed for compiling the memory.c file
 * This file contains standard include libraries and memory manipulation header files
 *
 * @author Sowmya Akella
 * @date July 31, 2017
 *
 */

#ifndef __LOG_H__
#define __LOG_H__

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

#define BBB 0
#define FRDM_BLOCK 1
#define FRDM_NONBLOCK 0

typedef struct __attribute__((__packed__)) BinaryLogger_str
{
	int32_t logID;
	uint32_t timestamp;
	uint32_t loglength;
	uint8_t * payload;
}BinLogger;

typedef enum
{
	LOGGER_INITIALIZED=1,
	GPIO_INITIALIZED,
	SYSTEM_INITIALIZED,
	SYSTEM_HALTED,
	INFO,
	WARNING,
	ERROR,
	PROFILING_STARTED,
	PROFILING_RESULT,
	PROFILING_COMPLETED,
	DATA_RECEIVED,
	DATA_ANALYSIS_STARTED,
	DATA_ALPHA_COUNT,
	DATA_NUMERIC_COUNT,
	DATA_PUNCTUATION_COUNT,
	DATA_MISC_COUNT,
	DATA_ANALYSIS_COMPLETED,
	HEARTBEAT
}BinLogType_enum;

typedef enum{
	LOG_STAT_SUCCESS = 0,
	LOG_STAT_NULL_ERROR
}LOG_STAT;

LOG_STAT log_status;

typedef enum {
	PAYLOAD_EMPTY,
	PAYLOAD_AVAIL
}Payload_e;
/*
Macros used for displaying logs
*/
#define LOG_RAW_DATA(data,length) (log_data((uint8_t *)data, length));
#define LOG_RAW_STRING(string) (log_string((uint8_t *)string));
#define LOG_RAW_INTEGER(num) (log_integer(num));
#define LOG_RAW_FLUSH() (log_flush());
/*
Logs data of certain length to UART
Inputs - pointer to data and length
Returns - Log error status
*/
LOG_STAT log_data(uint8_t * data, size_t len);

/*
Logs string to UART
Inputs - pointer to string
Returns - Log error status
*/
LOG_STAT log_string(uint8_t * string);

/*
Logs integer to UART after converting to ASCII
Inputs - number to log
Returns - Log error status
*/
LOG_STAT log_integer(uint32_t num);

/*
Does nothing in case of blocking logs
Inputs - None
Returns - Log error status
*/
LOG_STAT log_flush();

/*
Creates log item. Assigns memory to structure payload and sets log ID type and length
Inputs - pointer to string
Returns - Log error status
*/
void create_log_item(BinLogger *log_str,BinLogType_enum logIDtype,uint32_t length, uint8_t * payload);

/*
Logs the item to the UART
Inputs - pointer to string
Returns - Log error status
*/
void log_item(BinLogger * log_str,uint32_t length);


#endif /* __LOG_H__ */
