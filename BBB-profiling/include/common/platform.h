
/**
 * @file platform.h
 * @brief This file is the header files and function prototypes needed for compiling the project1.c file
 * This file contains uses a compile time switch to take in the PLATFORM on which the compilation needs to be done
 *
 * @author Sowmya Akella
 * @date June 25, 2017
 *
 */
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <stdio.h>

#define KL25Z 	1
#define BBB 	2
#define HOST 	3

#if PLATFORM == KL25Z
  #define printf(fmt,args...) {}
#endif

#endif /*__PLATFORM_H__*/