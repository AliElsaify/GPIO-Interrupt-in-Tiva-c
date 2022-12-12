/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/**********************************************************************************************************************

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define SYSCTL_RCGCGPIO_R                                               (*(( volatile unsigned long *)0x400FE608))
# define GPIO_PORTF_DEN_R                                                (*(( volatile unsigned long *)0x4002551C))
# define GPIO_PORTE_DEN_R                                                (*(( volatile unsigned long *)0x4002451C))
# define GPIO_PORTF_DIR_R                                                (*(( volatile unsigned long *)0x40025400))
#	define GPIO_PORTF_PIN0_DATA_R                                          (*(( volatile unsigned long *)(0x40025000+0x04)))
#	define GPIO_PORTF_PIN1_DATA_R                                          (*(( volatile unsigned long *)(0x40025000+0x08)))
#	define GPIO_PORTF_PIN2_DATA_R                                          (*(( volatile unsigned long *)(0x40025000+0x10)))
#	define GPIO_PORTF_PIN3_DATA_R                                          (*(( volatile unsigned long *)(0x40025000+0x20)))
#	define GPIO_PORTF_PIN4_DATA_R                                          (*(( volatile unsigned long *)(0x40025000+0x40)))
#	define GPIO_PORTF_LOCK_R                                               (*(( volatile unsigned long *) 0x40025520))
#	define GPIO_PORTF_CR_R                                                 (*(( volatile unsigned long *) 0x40025524))
#	define GPIO_PORTF_PUR_R                                                (*(( volatile unsigned long *) 0x40025510))
# define RCGCADC_R                                                       (*(( volatile unsigned long *) 0x400FE638))
#	define GPIOAFSEL_PORTE_R                                               (*(( volatile unsigned long *) 0x40024420))
# define GPIOAMSEL_PORTE_R                                               (*(( volatile unsigned long *) 0x40024528))
# define ADCACTSS_ADC0_R                                                 (*(( volatile unsigned long *) 0x40038000)) 
# define ADCEMUX_ADC0_R                                                  (*(( volatile unsigned long *) 0x40038014))
# define ADCSSMUX3_ADC0_R                                                (*(( volatile unsigned long *) 0x400380A0))
# define ADCPC_ADC0_R                                                    (*(( volatile unsigned long *) 0x40038FC4))
# define ADCPSSI_ADC0_R                                                  (*(( volatile unsigned long *) 0x40038028))
# define ADCRIS_ADC0_R                                                   (*(( volatile unsigned long *) 0x40038004))
# define ADCSSFIFO3_ADC0_R	                                             (*(( volatile unsigned long *) 0x400380A8))    
# define ADCSSCTL3_ADC0_R                                                (*(( volatile unsigned long *) 0x400380A4))
# define ADCDCISC_ADC0_R                                                 (*(( volatile unsigned long *) 0x40038034))
# define NVIC_EN0_R                                                      (*(( volatile unsigned long *) 0xE000E100))
# define GPIOIM_PORTF_R                                                  (*(( volatile unsigned long *) 0x40025410))
# define GPIOIS_PORTF_R                                                  (*(( volatile unsigned long *) 0x40025404))
# define GPIOIEV_PORTF_R                                                 (*(( volatile unsigned long *) 0x4002540C))
# define GPIOIBE_PORTF_R                                                 (*(( volatile unsigned long *) 0x40025408))
# define GPIOICR_PORTF_R                                                 (*(( volatile unsigned long *) 0x4002541C))
# define GPIOMIS_PORTF_R                                                 (*(( volatile unsigned long *) 0x40025418))
# define GPIORIS_PORTF_R                                                 (*(( volatile unsigned long *) 0x40025414))
# define NVIC_PRI7_R                                                     (*(( volatile unsigned long *) 0xE000E41C))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
