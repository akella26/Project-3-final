/**
 * @file main.c
 * @brief This file is to be used to project 3.
 *
 * @author Sowmya
 * @date Aug 2, 2017
 *
 */

#include "MKL25Z4.h"
#include "project3.h"

static int i = 0;

#define PROJECT3

int main(void)
{
	#ifdef PROJECT3
		project3();
	#endif
    return 0;
}
