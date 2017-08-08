/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file project1_test.c 
 * @brief This file is to be used to project 1.
 *
 * @author Alex Fosdick
 * @date April 2, 2017
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "platform.h"
#include "memory.h"
#include "conversion.h"
#include "debug.h"
#include "project1.h"
#include <time.h>
#include <sys/time.h>

#define MOVE 0 
#define SET 1

//#define STD_LIB_VERSION
#define NON_DMA_O0_O3

int8_t test_memmove1() 
{
  //clock_t start, end;
struct timeval begin,end;
  double elapsed_time;
  uint32_t i;
  int8_t ret = TEST_NO_ERROR;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  // printf("test_memmove1() - NO OVERLAP\n");
  set = (uint8_t *)malloc(MEM_SET_SIZE_B1*(sizeof(uint8_t)));

  if (! set ) 
  {
    return TEST_ERROR;
  }
 
  ptra = &set[0];
  ptrb = &set[TEST_MEMMOVE_LENGTH1];
  
  /* Initialize the set to test values */
  for( i = 0; i < MEM_SET_SIZE_B1; i++)
  {
    set[i] = i;
  }


#ifdef STD_LIB_VERSION
gettimeofday(&begin,NULL);
//  start = clock();
  #if(MOVE)
        memmove(ptrb,ptra,TEST_MEMMOVE_LENGTH1);
  #elif(SET)
        memset(ptrb,7,TEST_MEMMOVE_LENGTH1);
  #endif
  //end = clock();
gettimeofday(&end,NULL);
#endif


#ifdef NON_DMA_O0_O3
//  start = clock();
gettimeofday(&begin,NULL);
  #if(MOVE)
//	printf("\n before going to memmove\n");
        my_memmove(ptra,ptrb,TEST_MEMMOVE_LENGTH1);
  #elif(SET)
        my_memset(ptra,TEST_MEMMOVE_LENGTH1,7);
  #endif
  //end = clock();
gettimeofday(&end,NULL);
#endif
 //printf("\n %ld \n",CLOCKS_PER_SEC);
 // elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
 elapsed_time = (end.tv_sec - begin.tv_sec)+((end.tv_usec - begin.tv_usec)/1000000.0);
  printf("\n elapsed time : %Lf \n", elapsed_time);

  free(set);
  return ret;
}

void project1(void) 
{
  uint8_t i;
  int8_t failed = 0;
  int8_t results[TESTCOUNT];

  results[2] = test_memmove1();
}
