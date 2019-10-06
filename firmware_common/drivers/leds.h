/*!**********************************************************************************************************************
@file leds.h                                                               
@brief Header file for leds.c
**********************************************************************************************************************/

#ifndef __LEDS_H
#define __LEDS_H

#include "configuration.h"

/**********************************************************************************************************************
Type Definitions
**********************************************************************************************************************/
/*! 
@enum LedControlType
@brief The mode determines how the task manages the LED */
typedef enum {LED_NORMAL_MODE, LED_BLINK_MODE} LedModeType;  

/*! 
@enum LedRateType
@brief Standard blinky values for blinking.  
Other blinking rate values may be added as required.  The values are the toggling period in ms.
*/
typedef enum {LED_0HZ = 0, LED_0_5HZ = 1000, LED_1HZ = 500, LED_2HZ = 250, LED_4HZ = 125, LED_8HZ = 63
             } LedRateType;

/*! 
@struct LedControlType
@brief Required parameters for the task to track what each LED is doing. 
*/
typedef struct 
{
  LedModeType eMode;              /*!< @brief Current mode */
  LedRateType eRate;              /*!< @brief Current rate */
  u16 u16Count;                   /*!< @brief Value of current duty cycle counter */
}LedControlType;

/**********************************************************************************************************************
Function Declarations
**********************************************************************************************************************/

/*------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/
void LedInitialize(void);
void LedRunActiveState(void);
void LedOn(LedNameType eLED_);
void LedOff(LedNameType eLED_);
void LedToggle(LedNameType eLED_);
/*------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/


/***********************************************************************************************************************
State Machine Declarations
***********************************************************************************************************************/
static void LedSM_Idle(void);
static void LedSM_Error(void);


/**********************************************************************************************************************
Constants / Definitions
**********************************************************************************************************************/




#endif /* __LEDS_H */
/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
