/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIOInterrupt.h
 *       Module:  GPIOInterrupt
 *
 *  Description:  header file for GPIOInterrupt Module    
 *  
 *********************************************************************************************************************/
#ifndef GPIOInterrupt_H
#define GPIOInterrupt_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define Port_A                                                       0
# define Port_B                                                       1
# define Port_C                                                       2
# define Port_D                                                       3
# define Port_E                                                       4
# define Port_F                                                       5


# define Pin_0                                                        0
# define Pin_1                                                        1
# define Pin_2                                                        2
# define Pin_3                                                        3
# define Pin_4                                                        4
# define Pin_5                                                        5
# define Pin_6                                                        6
# define Pin_7                                                        7

# define OUTPUT                                                       1
# define INPUT                                                        0

# define HIGH                                                         1
# define LOW                                                          0

# define PUR                                                          1
# define PDR                                                          2
# define NO_PullResistor                                              0

# define Level_Sensitive                                              0
# define Edge_Sensitive                                               1

# define BothEdges                                                    0
# define FallingEdge                                                  1
# define RisingEdge                                                   2
# define HighLevelInterrupt                                           1
# define LowLevelInterrupt                                            0



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 

void GPIOInterrupt_Enable         (int Port, int Pin,int PullResistor, int Sensitivity, int SensitivityTrigger, int Priority)  ;

#endif  /* GPIOInterrupt_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIOInterrupt.h
 *********************************************************************************************************************/
