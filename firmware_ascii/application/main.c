/*!**********************************************************************************************************************
@file main.c                                                                
@brief Main system file for the EiE firmware.  
***********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_"
***********************************************************************************************************************/
/* New variables */


/*--------------------------------------------------------------------------------------------------------------------*/
/* External global variables defined in other files (must indicate which file they are defined in) */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "Main_" and be declared as static.
***********************************************************************************************************************/


/*!**********************************************************************************************************************
@fn void main(void)
@brief Main program where all tasks are initialized and executed.


***********************************************************************************************************************/

void main(void)
{
  /* Low Level Initialization */
 
  /* Super Loop */
  while (1)
  {
    WATCHDOG_BONE();
  }
  /* end while (1) main super loop*/
  
  
} /* end main() */

void ClockSetup(void){
/* set flash wait states to allow 48 MHz system clock (2 wait states required)*/
  AT91C_BASE_EFC0 -> EFC_FMR = AT91C_EFC_FWS_2WS;
  
  /* activatge the peripheral clocks needed for the system */
  AT91_Base_PMC ->PMC_PCER = PMC_PCER_INIT; 
} /* end clock setup */


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File */
/*--------------------------------------------------------------------------------------------------------------------*/
