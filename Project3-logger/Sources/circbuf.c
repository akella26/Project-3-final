/**
 * @file circbuf.c
 * @brief This file contains function for performing actions with circular buffer
 * @author Sowmya Akella
 * @date July 16, 2017
 *
 */
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "circbuf.h"

#define START_CRITICAL() ( __disable_irq() )
#define END_CRITICAL() ( __enable_irq() )
/*
 * @brief - Initializes circular buffer head and tail, allocates memory
 * @param - arguments - pointer to circular buffer and length
 * @return - Error/Success status enum variable
 */
CB_status CB_init(CB_t * buf_pointer,size_t length)
{
	START_CRITICAL();
	if(buf_pointer == NULL)
		return CB_STATUS_NULL_ERROR_CIRCBUFF;

	buf_pointer->buffer = (uint8_t*)calloc(length,sizeof(uint8_t));

	if(buf_pointer->buffer == NULL)
		status = CB_STATUS_NULL_ERROR_DATABUFF;
	else 
		status = CB_STATUS_SUCCESS;
		buf_pointer->head = buf_pointer->buffer;
		buf_pointer->tail = buf_pointer->buffer;
		buf_pointer->end = buf_pointer->buffer + length;
		buf_pointer->count = 0;
		buf_pointer->length = length;
	END_CRITICAL();
	return status;

}

/*
 * @brief - Function to add an item to the circular buffer 
 * @param - arguments - pointer to circular buffer and new item to add
 * @return - Error/Success status enum variable
 */

CB_status CB_buffer_add_item(CB_t * buf_pointer, uint8_t new_item)
{
	START_CRITICAL();
	if(buf_pointer == NULL)
	{
		status = CB_STATUS_NULL_ERROR_CIRCBUFF;
	    return status;
	}

	status = CB_is_full(buf_pointer);
	if(status == CB_STATUS_BUF_FULL)
	{
		status = CB_STATUS_BUF_FULL;
	    return status;
	}
    else
	{
		*(buf_pointer->head) =  new_item;
		(buf_pointer->count)++;
		if(buf_pointer->head == buf_pointer->end)
		{
        		buf_pointer->head = buf_pointer->buffer;       		
        }
        else 
        {
        		(buf_pointer->head)++;
        }		
		status = CB_STATUS_SUCCESS;
        	
    }
	END_CRITICAL();
    return status;
}

/*
 * @brief - Function to remove an item from the circular buffer 
 * @param - arguments - pointer to circular buffer and pointer to item removed
 * @return - Error/Success status enum variable
 */
CB_status CB_buffer_remove_item(CB_t * buf_pointer,uint8_t * item_removed)
{
	START_CRITICAL();
	if(buf_pointer == NULL)
	{
		status = CB_STATUS_NULL_ERROR_CIRCBUFF;
	    return status;
	}

	status = CB_is_empty(buf_pointer);
	if(status == CB_STATUS_BUF_EMPTY)
	{
		status = CB_STATUS_BUF_EMPTY;
	    return status;
	}

	else 
	{
		*item_removed = *(buf_pointer->tail);
		*(buf_pointer->tail) = 0;
		(buf_pointer->count)--;
		status = CB_STATUS_SUCCESS;
        if(buf_pointer->tail == buf_pointer->end)
        {
        	buf_pointer->tail = buf_pointer->buffer;   
        }
        else 
        {
        	(buf_pointer->tail)++;
        }
    }
	END_CRITICAL();
    return status;
}

/*
 * @brief - Function to check if the circular buffer is full or not
 * @param - arguments - pointer to circular buffer 
 * @return - Error/Success status enum variable
 */

//CB_status CB_is_full(CB_t * buf_pointer)
//{
//	if(buf_pointer == NULL)
//	{
//		status = CB_STATUS_NULL_ERROR_CIRCBUFF;
//	    return status;
//	}
//
//	if((buf_pointer->head == buf_pointer->tail) && buf_pointer->count != 0)
//		status = CB_STATUS_BUF_FULL;
//	else
//		status = CB_STATUS_BUF_NOT_FULL;
//
//	return status;
//}

/*
 * @brief - Function to check if the circular buffer is empty or not
 * @param - arguments - pointer to circular buffer 
 * @return - Error/Success status enum variable
 */
//CB_status CB_is_empty(CB_t * buf_pointer)
//{
//	if(buf_pointer == NULL)
//	{
//		status = CB_STATUS_NULL_ERROR_CIRCBUFF;
//	    return status;
//	}
//	if((buf_pointer->head == buf_pointer->tail) && buf_pointer->count == 0)
//		status = CB_STATUS_BUF_EMPTY;
//	else
//		status = CB_STATUS_BUF_NOTEMPTY;
//
//	return status;
//}

/*
 * @brief - Function to peek into the circular buffer and check the value stored at a position
 * @param - arguments - pointer to circular buffer , position to peek into and pointer to item peeked
 * @return - Error/Success status enum variable
 */

CB_status CB_peek(CB_t * buf_pointer, uint8_t peek_position,uint8_t * peek_item)
{
	START_CRITICAL();
	if(buf_pointer == NULL)
	{
		status = CB_STATUS_NULL_ERROR_CIRCBUFF;
	    return status;
	}

	*peek_item = buf_pointer->buffer[peek_position];
	if(peek_item == NULL)
		status = CB_STATUS_NULL_ERROR_DATABUFF;
	else 
		status = CB_STATUS_SUCCESS;
	END_CRITICAL();
	return status;
}

/*Function to deallocate the circ buffer pointer and data buffer pointer*/

/*
 * @brief - Function to destroy dynamically allocated memory 
 * @param - arguments - pointer to circular buffer
 * @return - Error/Success status enum variable
 */

CB_status CB_destroy(CB_t * buf_pointer)
{
	START_CRITICAL();
	if(buf_pointer == NULL)
	{
		status = CB_STATUS_NULL_ERROR_CIRCBUFF;
	    return status;
	}

	free((void*)buf_pointer->buffer);
	free((void*)buf_pointer);
	status = CB_STATUS_FREE_SUCCESS;
	END_CRITICAL();
	return status;
}


