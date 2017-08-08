/* @file rtc.h
 * @brief This file is the header files and function prototypes needed for RTC configuration
 *
 * @author Sowmya Akella
 * @date Aug 6, 2017
 *
 */

#ifndef __RTC_H__
#define __RTC_H__

# include <stdint.h>

/*
Configures the RTC clock
Inputs - None
Returns - None
*/
void RTC_Clock_Configuration();

/*
Initializes the RTC clock
Inputs - None
Returns - None
*/
void rtc_init();

#endif /* __RTC_H__ */
