/**
 * @file profiling.h
 * @brief This file is to be used to project 1.
 *
 * @author Sowmya Akela
 * @date Aug 2, 2017
 *
 */
#ifndef __PROFILING_H__
#define __PROFILING_H__

#include <stdint.h>
#include <stdio.h>
#include "dma.h"

void TPM_init();
void TPM_deinit();

void start_profiling();
void stop_profiling(uint32_t diff_count);
#endif /* _PROFILING_H__ */
