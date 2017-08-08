/**
 * @file circbuf.h 
 * @brief This file contains function declarations of circbug.c
 *
 * @author Sowmya Akella
 * @date July 1, 2017
 *
 */

#ifndef __CIRCBUF_H__
#define __CIRCBUF_H__

#include <stdint.h> 

#define BUF_TEST_SIZE 3
#define __STATIC_INLINE static inline

typedef struct {
	uint8_t * buffer;
	uint8_t * head;
	uint8_t * tail;
	uint8_t * end;
	size_t count;
	size_t length; 
}CB_t;

typedef enum {
	CB_STATUS_BUF_FULL = 0,
	CB_STATUS_BUF_NOT_FULL,
	CB_STATUS_BUF_EMPTY,
	CB_STATUS_BUF_NOTEMPTY,
	CB_STATUS_SUCCESS,
	CB_STATUS_NULL_ERROR_DATABUFF,
	CB_STATUS_NULL_ERROR_CIRCBUFF,
	CB_STATUS_FREE_SUCCESS,
}CB_status;

CB_status status;

CB_status CB_init(CB_t * buf_pointer,size_t length);
CB_status CB_buffer_add_item(CB_t * buf_pointer,uint8_t new_item);
CB_status CB_buffer_remove_item(CB_t * buf_pointer,uint8_t * item_removed);

__attribute__((always_inline))static inline CB_status CB_is_full(CB_t * buf_pointer)
{
	if(buf_pointer == NULL)
	{
			status = CB_STATUS_NULL_ERROR_CIRCBUFF;
		    return status;
	}

	if((buf_pointer->head == buf_pointer->tail) && buf_pointer->count != 0)
		status = CB_STATUS_BUF_FULL;
	else
		status = CB_STATUS_BUF_NOT_FULL;

		return status;
}

__attribute__((always_inline))static inline CB_status CB_is_empty(CB_t * buf_pointer)
{
	if(buf_pointer == NULL)
	{
		status = CB_STATUS_NULL_ERROR_CIRCBUFF;
		return status;
	}
	if((buf_pointer->head == buf_pointer->tail) && buf_pointer->count == 0)
		status = CB_STATUS_BUF_EMPTY;
	else
		status = CB_STATUS_BUF_NOTEMPTY;

return status;
}
//CB_status CB_is_full(CB_t * buf_pointer);
//CB_status CB_is_empty(CB_t * buf_pointer);
CB_status CB_peek(CB_t * buf_pointer, uint8_t peek_position,uint8_t * peek_item);
CB_status CB_destroy(CB_t * buf_pointer);

#endif /* __CIRCBUF_H__ */
