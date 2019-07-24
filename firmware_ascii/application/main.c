/*!**********************************************************************************************************************
@file main.c                                                                
@brief Main system file for the EiE firmware.  
***********************************************************************************************************************/

#include "configuration.h"
extern void kill_x_cycles(u32);
/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32SystemTime1ms = 0; /*Global System Time incremented every 1ms */
volatile u32 G_u32SystemTime1s = 0; /*Global System Time incremented every 1s */
volatile u32 G_u32SystemFlags = 0; /* Global System Flags */

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
  WatchDogSetup(); 
  ClockSetup();
  GpioSetup();
  /* Super Loop */
  while (1)
  {
    WATCHDOG_BONE();
   
    /* System sleep */
    HEARTBEAT_OFF();
    do{
      SystemSleep();
    } while(G_u32SystemFlags & _SYSTEM_SLEEPING);
    HEARTBEAT_ON();
  }
  /* end while (1) main super loop*/
  
  
} /* end main() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File */
/*--------------------------------------------------------------------------------------------------------------------*/
