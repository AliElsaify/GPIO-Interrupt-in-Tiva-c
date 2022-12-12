/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIOInterrupt.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIOInterrupt.h"
#include "Mcu_Hw_GPIOInterrupt.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void GPIOInterrupt_Enable (int Port, int Pin,int PullResistor, int Sensitivity, int SensitivityTrigger, int Priority)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void GPIOInterrupt_Enable         (int Port, int Pin,int PullResistor, int Sensitivity, int SensitivityTrigger, int Priority)
{
		int GPIOInterrupt_Offset ;
	if( Port==Port_A)
	{
    GPIOInterrupt_Offset= 0x04<<12;
	}
	else if(Port==Port_B)
	{
		GPIOInterrupt_Offset= 0x05<<12;
	}
	else if(Port==Port_C)
	{
		GPIOInterrupt_Offset= 0x06<<12;
	}
	else if(Port==Port_D)
	{
		GPIOInterrupt_Offset= 0x07<<12;
	}
	else if(Port==Port_E)
	{
		GPIOInterrupt_Offset= 0x24<<12;
	}
	else if(Port==Port_F)
	{
		GPIOInterrupt_Offset= 0x25<<12;
	}
	     /*initiate PF0,PF4 as input pull up resistor and PF3 as output*/
	SYSCTL_RCGCGPIO_R                 |= (1<<Port)                        ;   /* Set bit5 of RCGCGPIO to enable clock to PORTF*/
	     /*port PF0 has a special function so it needs to be unlocked to be modified */
	
	if (((Port == Port_C)&&(Pin==Pin_0))||((Port == Port_C)&&(Pin==Pin_1))||((Port == Port_C)&&(Pin==Pin_2))||((Port == Port_C)&&(Pin==Pin_3))||((Port == Port_D)&&(Pin==Pin_7))||((Port == Port_F)&&(Pin==Pin_0)))
	{
		(*(( volatile unsigned long *)(GPIO_PORT_LOCK_R|GPIOInterrupt_Offset)))   = 0x4C4F434B                    ;   /* unlock commit register */
   	(*(( volatile unsigned long *)(GPIO_PORT_CR_R|GPIOInterrupt_Offset)))     |= 1<<Pin                   ;   /* unlock commit register */
		(*(( volatile unsigned long *)(GPIO_PORT_LOCK_R|GPIOInterrupt_Offset)))   = 0                    ;   /* unlock commit register */

	}
	
		(*(( volatile unsigned long *)(GPIO_PORT_DIR_R|GPIOInterrupt_Offset)))   &= ~(1<<Pin)                    ;   /* unlock commit register */
		(*(( volatile unsigned long *)(GPIO_PORT_DEN_R|GPIOInterrupt_Offset)))   |= 1<<Pin                    ;   /* unlock commit register */

	if ( PullResistor == PUR)
	{
		(*(( volatile unsigned long *)(GPIO_PORT_PUR_R|GPIOInterrupt_Offset)))   |= 1<<Pin                    ;   /* unlock commit register */
	}
	else if (PullResistor == PDR)
	{
		(*(( volatile unsigned long *)(GPIO_PORT_PDR_R|GPIOInterrupt_Offset)))   |= 1<<Pin                    ;   /* unlock commit register */
	}
	
	if (Sensitivity == Edge_Sensitive)
	{
		(*(( volatile unsigned long *)(GPIOIS_PORT_R|GPIOInterrupt_Offset)))   &=~( 1<<Pin)                    ;   /* unlock commit register */
		
		if (SensitivityTrigger ==BothEdges)
		{
			(*(( volatile unsigned long *)(GPIOIBE_PORT_R|GPIOInterrupt_Offset)))   |=( 1<<Pin)                    ;   /* unlock commit register */
		}
		else if (SensitivityTrigger ==FallingEdge)
		{
			(*(( volatile unsigned long *)(GPIOIBE_PORT_R|GPIOInterrupt_Offset)))   &=~( 1<<Pin)                    ;   /* unlock commit register */
			(*(( volatile unsigned long *)(GPIOIEV_PORT_R|GPIOInterrupt_Offset)))   &=~( 1<<Pin)                    ;   /* unlock commit register */
		}
		else if (SensitivityTrigger ==RisingEdge)
		{
			(*(( volatile unsigned long *)(GPIOIBE_PORT_R|GPIOInterrupt_Offset)))   &=~( 1<<Pin)                    ;   /* unlock commit register */
			(*(( volatile unsigned long *)(GPIOIEV_PORT_R|GPIOInterrupt_Offset)))   |= ( 1<<Pin)                    ;   /* unlock commit register */

		}
	}
	else if (Sensitivity == Level_Sensitive)
	{
		(*(( volatile unsigned long *)(GPIOIS_PORT_R|GPIOInterrupt_Offset)))   |=( 1<<Pin)                    ;   /* unlock commit register */

		if (SensitivityTrigger == HighLevelInterrupt)
		{
			(*(( volatile unsigned long *)(GPIOIEV_PORT_R|GPIOInterrupt_Offset)))   |= ( 1<<Pin)                    ;   /* unlock commit register */

		}
		else if (SensitivityTrigger == LowLevelInterrupt)
		{
			(*(( volatile unsigned long *)(GPIOIEV_PORT_R|GPIOInterrupt_Offset)))   &= ~( 1<<Pin)                    ;   /* unlock commit register */

		}
	}
	
	(*(( volatile unsigned long *)(GPIOICR_PORT_R|GPIOInterrupt_Offset)))   |= ( 1<<Pin)                    ;   /* unlock commit register */
	(*(( volatile unsigned long *)(GPIOIM_PORT_R|GPIOInterrupt_Offset)))    |= ( 1<<Pin)                    ;   /* unlock commit register */

	if ( Port ==Port_F)
	{
		NVIC_PRI7_R                        = Priority << 21                       ;    /* set interrupt IRQ30 priority to 3 */
  	NVIC_EN0_R                        |= (1<<30)                       ;    /*Enable PORTF Interrupt IRQ30 */

	}
	else if ( Port ==Port_A)
	{
		NVIC_PRI0_R                        = Priority << 5                       ;    /* set interrupt IRQ30 priority to 3 */
	  NVIC_EN0_R                        |= (1<<0)                       ;    /*Enable PORTF Interrupt IRQ30 */

	}
	else if ( Port ==Port_B)
	{
		NVIC_PRI0_R                        = Priority << 13                       ;    /* set interrupt IRQ30 priority to 3 */
	  NVIC_EN0_R                        |= (1<<1)                       ;    /*Enable PORTF Interrupt IRQ30 */

	}
	else if ( Port ==Port_C)
	{
		NVIC_PRI0_R                        = Priority << 21                       ;    /* set interrupt IRQ30 priority to 3 */
	  NVIC_EN0_R                        |= (1<<2)                       ;    /*Enable PORTF Interrupt IRQ30 */

	}
	else if ( Port ==Port_D)
	{
		NVIC_PRI0_R                        = Priority << 29                       ;    /* set interrupt IRQ30 priority to 3 */
	  NVIC_EN0_R                        |= (1<<3)                       ;    /*Enable PORTF Interrupt IRQ30 */

	}
	else if ( Port ==Port_E)
	{
		NVIC_PRI1_R                        = Priority << 5                       ;    /* set interrupt IRQ30 priority to 3 */
	  NVIC_EN0_R                        |= (1<<4)                       ;    /*Enable PORTF Interrupt IRQ30 */

	}
	

}


/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
