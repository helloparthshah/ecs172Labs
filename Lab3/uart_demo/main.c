//*****************************************************************************
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

//*****************************************************************************
//
// Application Name     - UART Demo
// Application Overview - The objective of this application is to showcase the
//                        use of UART. The use case includes getting input from
//                        the user and display information on the terminal. This
//                        example take a string as input and display the same
//                        when enter is received.
// Application Details  -
// http://processors.wiki.ti.com/index.php/CC32xx_UART_Demo_Application
// or
// docs\examples\CC32xx_UART_Demo_Application.pdf
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup uart_demo
//! @{
//
//*****************************************************************************

// Standard include
#include <stdio.h>

// Driverlib includes
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "interrupt.h"
#include "hw_apps_rcm.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
#include "prcm.h"
#include "gpio.h"
#include "utils.h"
#include "timer.h"

// Common interface includes
#include "uart_if.h"
#include "timer_if.h"

#include "pin_mux_config.h"

//*****************************************************************************
//                          MACROS
//*****************************************************************************
#define APPLICATION_VERSION "1.1.1"
#define APP_NAME "UART Echo"
#define CONSOLE UARTA0_BASE
#define UartGetChar() MAP_UARTCharGet(CONSOLE)
#define UartPutChar(c) MAP_UARTCharPut(CONSOLE, c)
#define MAX_STRING_LENGTH 80

//*****************************************************************************
//                 GLOBAL VARIABLES -- Start
//*****************************************************************************
static volatile unsigned long g_ulBase;
static volatile unsigned long g_ulRefBase;

extern void (*const g_pfnVectors[])(void);
volatile unsigned long pin8_intcount;
volatile unsigned char pin8_intflag;

typedef struct PinSetting {
  unsigned long port;
  unsigned int pin;
} PinSetting;

static PinSetting pin8 = {.port = GPIOA2_BASE, .pin = 0x2};
#if defined(ccs)
extern void (*const g_pfnVectors[])(void);
#endif
#if defined(ewarm)
extern uVectorEntry __vector_table;
#endif
//*****************************************************************************
//                 GLOBAL VARIABLES -- End
//*****************************************************************************

//*****************************************************************************
//                      LOCAL DEFINITION
//*****************************************************************************

//*****************************************************************************
//
//! Application startup display on UART
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************
static void DisplayBanner(char *AppName) {

  Report("\n\n\n\r");
  Report("\t\t *************************************************\n\r");
  Report("\t\t        CC3200 %s Application       \n\r", AppName);
  Report("\t\t *************************************************\n\r");
  Report("\n\n\n\r");
}

//*****************************************************************************
//
//! Board Initialization & Configuration
//!
//! \param  None
//!
//! \return None
//
//*****************************************************************************
static void BoardInit(void) {
/* In case of TI-RTOS vector table is initialize by OS itself */
#ifndef USE_TIRTOS
  //
  // Set vector table base
  //
#if defined(ccs)
  MAP_IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);
#endif
#if defined(ewarm)
  MAP_IntVTableBaseSet((unsigned long)&__vector_table);
#endif
#endif
  //
  // Enable Processor
  //
  MAP_IntMasterEnable();
  MAP_IntEnable(FAULT_SYSTICK);

  PRCMCC3200MCUInit();
}

#define ONE "00000010111111011000000001111110"
#define TWO "00000010111111010100000010111110"
#define THREE "00000010111111011100000000111110"
#define FOUR "00000010111111010010000011011110"
#define FIVE "00000010111111011010000001011110"
#define SIX "00000010111111010110000010011110"
#define SEVEN "00000010111111011110000000011110"
#define EIGHT "00000010111111010001000011101110"
#define NINE "00000010111111011001000001101110"
#define ZERO "00000010111111010000000011111110"
#define LAST "00000010111111011110100000010110"
#define MUTE "00000010111111010000100011110110"

volatile unsigned long prev=0, curr=0;
volatile int start=0;
volatile float values[35];
volatile int curr_index=0;
char* keyToBinary(){
  // takes values list of 32 floats and returns a binary number
  // if float is from 1 to 2 then it is a 0 and if it is from 2 to 3 then a 1 at the index

  char *str=malloc(33);
  int i;
  for(i=0;i<32;i++){
    if(values[i+1]<2){
      str[i]='0';
    }
    else {
      str[i]='1';
    }
    values[i+1]=0;
  }
  str[i]='\0';
  return str;
}

void printBinary(char *str){
  // Report("%s\n\r",str);
  if(strcmp(ZERO, str)==0){
    Report("0\n\r");
  }
  else if(strcmp(ONE, str)==0){
    Report("1\n\r");
  }
  else if(strcmp(TWO, str)==0){
    Report("2\n\r");
  }
  else if(strcmp(THREE, str)==0){
    Report("3\n\r");
  }
  else if(strcmp(FOUR, str)==0){
    Report("4\n\r");
  }
  else if(strcmp(FIVE, str)==0){
    Report("5\n\r");
  }
  else if(strcmp(SIX, str)==0){
    Report("6\n\r");
  }
  else if(strcmp(SEVEN, str)==0){
    Report("7\n\r");
  }
  else if(strcmp(EIGHT, str)==0){
    Report("8\n\r");
  }
  else if(strcmp(NINE, str)==0){
    Report("9\n\r");
  }
  else if(strcmp(LAST, str)==0){
    Report("LAST\n\r");
  }
  else if(strcmp(MUTE, str)==0){
    Report("MUTE\n\r");
  }
  else {
    Report("Invalid\n\r");
  }
  // free str
  free(str);
}

static void GPIOA2IntHandler(void) { // SW2 handler
  unsigned long ulStatus;

  ulStatus = MAP_GPIOIntStatus(pin8.port, true);
  MAP_GPIOIntClear(pin8.port, ulStatus); // clear interrupts on GPIOA2

  // pin8_intflag = 1;
  if (curr_index == 0) {
    Timer_IF_Start(g_ulBase, TIMER_A, 1000);
    curr_index = 1;
  }
  curr = Timer_IF_GetCount(g_ulBase, TIMER_A);
  float d = (float)(curr - prev) / 80000;
  if (d > 13 && d < 14) {
    start = 1;
    curr_index = 1;
    Timer_IF_Stop(g_ulRefBase, TIMER_A);
  }

  prev = curr;

  if (start) {
    // Report("%f\n\r", d);
    values[curr_index - 1] = d;
    curr_index++;
  }

  if (curr_index >= 33) {
    // disable interrupt
    MAP_GPIOIntDisable(pin8.port, pin8.pin);
    start = 0;
    curr_index = 0;
    printBinary(keyToBinary());
    // enable interrupt
    MAP_GPIOIntEnable(pin8.port, pin8.pin);
  }
}

//*****************************************************************************
//
//! Main function handling the uart echo. It takes the input string from the
//! terminal while displaying each character of string. whenever enter command
//! is received it will echo the string(display). if the input the maximum input
//! can be of 80 characters, after that the characters will be treated as a part
//! of next string.
//!
//! \param  None
//!
//! \return None
//!
//*****************************************************************************
void main() {
  //
  // Initailizing the board
  //
  BoardInit();
  //
  // Muxing for Enabling UART_TX and UART_RX.
  //
  PinMuxConfig();
  //
  // Initialising the Terminal.
  //
  InitTerm();
  //
  // Clearing the Terminal.
  //
  ClearTerm();
  DisplayBanner(APP_NAME);
  MAP_GPIOIntRegister(pin8.port, GPIOA2IntHandler);
//   MAP_GPIOIntTypeSet(pin8.port, pin8.pin, GPIO_RISING_EDGE); // SW2
  MAP_GPIOIntTypeSet(pin8.port, pin8.pin, 0x0); // SW2
  unsigned long ulStatus = MAP_GPIOIntStatus(pin8.port, false);
  MAP_GPIOIntClear(pin8.port, ulStatus);
  pin8_intcount = 0;
  pin8_intflag = 0;
  MAP_GPIOIntEnable(pin8.port, pin8.pin);


  g_ulBase = TIMERA0_BASE;
  g_ulRefBase = TIMERA1_BASE;
  Timer_IF_Init(PRCM_TIMERA0, g_ulBase, TIMER_CFG_PERIODIC, TIMER_A, 0);
  Timer_IF_Init(PRCM_TIMERA1, g_ulRefBase, TIMER_CFG_PERIODIC, TIMER_A, 0);
  // detect changes in p8 from 1 to 0 to back to 1
  while (1) {
  }
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
