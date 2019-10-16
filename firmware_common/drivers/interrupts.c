/*!*********************************************************************************************************************
@file interrupts.c                                                               
@brief Definitions for main system interrupts.

------------------------------------------------------------------------------------------------------------------------
GLOBALS
- NONE

CONSTANTS
- NONE

TYPES
- 
PUBLIC FUNCTIONS
- NONE

PROTECTED FUNCTIONS
- 


***********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_<type>ISR"
***********************************************************************************************************************/
/* New variables */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword)  */
extern volatile u32 G_u32SystemTime1ms;                /*!< @brief From main.c */
extern volatile u32 G_u32SystemTime1s;                 /*!< @brief From main.c */
extern volatile u32 G_u32SystemFlags;                  /*!< @brief From main.c */
extern volatile u32 G_u32ApplicationFlags;             /*!< @brief From main.c */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variables names shall start with "ISR_<type>" and be declared as static.
***********************************************************************************************************************/


/**********************************************************************************************************************
Interrupt Service Routine Definitions
***********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/
/*!---------------------------------------------------------------------------------------------------------------------
@fn void InteruptSetup(void)
@brief Disables and clears all NVIC interrupts and sets up interrupt priorities.

Requires:
-IRQn_Type enum is the sequentially orderedinterrupt values starting at 0

Promises:
- Interrupt prioritiesa re set
- All NVIC interrupts are disabled and all pending flags are cleared
*/

void InterruptSetup(void){
  static const u32 au32PriorityConfig[PRIORITY_REGISTERS] = {IPR0_INIT, IPR1_INIT,
         IPR2_INIT, IPR3_INIT, IPR4_INIT, IPR5_INIT, IPR6_INIT, IPR7_INIT};
  /*Disable all interrupts and ensure pending bits are clear*/
  for(u8 i = 0; i < U8_SAM3U2_INTERRUPT_SOURCES; i++){
    NVIC_DisableIRQ((IRQn_Type)i);
    NVIC_ClearPendingIRQ((IRQn_Type)i);
  }
  
  /*Set interrupt priorities*/
  for(u8 i = 0; i < PRIORITY_REGISTERS; i++){
    ((u32*)(AT91C_BASE_NVIC->NVIC_IPR))[i] = au32PriorityConfig[i];
  }
  
}/*End of InterruptSetup(void)*/
/*!-------------------------------------------------------------------------------------------------------------------
@fn ISR void PIOA_IrqHandler(void)
@brief Parses the PORTA GPIO interrupts and handles them appropriately

Note that all PORTA GPIO interrupts are ORed and will trigger this handler,
so any expected interrupt tht is enabled must be parsed out and handled

Requires: 
- The button IO bits match the interrupt flag location

Promises: 
- Buttons: Sets the active button's debouncing flag, clears the interrupt
  and initializes the button's debounce timer.
*/
void PIOA_IrqHandler(void){
  /*Clear the PIOA pending flag and exit*/
  NVIC_ClearPendingIRQ(IRQn_PIOA);
 
} /*end PIOA_IrqHandler()*/
void PIOB_IrqHandler(void){
  /*Clear the PIOB pending flag and exit*/
  NVIC_ClearPendingIRQ(IRQn_PIOB);
 
} /*end PIOB_IrqHandler()*/
/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File */
/*--------------------------------------------------------------------------------------------------------------------*/
