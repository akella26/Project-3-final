/**
 * @file profiling.c
 * @brief This file is to keep the timer and profiling config
 *
 * @author Sowmya
 * @date Aug 2, 2017
 *
 */
#include "MKL25Z4.h"
#include "log.h"

extern volatile uint32_t count_cycle=0;
extern uint8_t payload;

void TPM_init()
{
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK;        	//TPM2 USED
	SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(1);        	//Clock SRC 11- MCGIRCLK
	TPM2_BASE_PTR->SC = TPM_SC_PS(6);	 				// Prescalar of 1
	TPM2_SC |= TPM_SC_TOIE_MASK;						// Enable the counter & interrupt
	TPM2_BASE_PTR->MOD = 0xFFFF;						//Load for high Counter value
	NVIC_EnableIRQ(TPM2_IRQn);							//Enable TPM2 interrupt in NVIC
}

void TPM_deinit()
{
	TPM2_SC |= TPM_SC_CMOD(0);
	TPM2_SC &= ~TPM_SC_TOIE_MASK;						// Disable the counter & interrupt
}

void TPM2_IRQHandler()
{
	TPM2_BASE_PTR->SC |= TPM_SC_TOF_MASK;              //Clearing TOF bit
	count_cycle++;
}

void start_profiling()
{
	BinLogger *log_str; 				//Binary logger variable and memory allocation for its pointer
	log_str = (BinLogger*)malloc(sizeof(BinLogger));
	payload = 0;
	create_log_item(log_str,PROFILING_STARTED,0,&payload);
	log_item(log_str,0);
	TPM2_SC |= TPM_SC_CMOD(1);
}

void stop_profiling(uint32_t diff_count)
{
	BinLogger *log_str; 				//Binary logger variable and memory allocation for its pointer
	log_str = (BinLogger*)malloc(sizeof(BinLogger));
	payload = diff_count;
	create_log_item(log_str,PROFILING_RESULT,1,&payload);
	log_item(log_str,1);
	payload = 0;
	create_log_item(log_str,PROFILING_COMPLETED,0,&payload);
	log_item(log_str,0);

}
