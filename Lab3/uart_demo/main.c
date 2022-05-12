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
#include <stdlib.h>

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
#include "uart.h"

// Common interface includes
#include "uart_if.h"
#include "timer_if.h"
#include "spi.h"

#include "pin_mux_config.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1351.h"
#include "glcdfont.h"
#include "test.h"

//*****************************************************************************
//                          MACROS
//*****************************************************************************
#define APPLICATION_VERSION "1.1.1"
#define APP_NAME "UART Echo"
#define CONSOLE UARTA0_BASE
#define UartGetChar() MAP_UARTCharGet(CONSOLE)
#define UartPutChar(c) MAP_UARTCharPut(CONSOLE, c)
#define MAX_STRING_LENGTH 80
#define SPI_IF_BIT_RATE 100000

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

static PinSetting ir_input = {.port = GPIOA2_BASE, .pin = 0x2};
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

const char *digits[] = {" ",   "",    "ABC",  "DEF", "GHI",
                  "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

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

volatile int state = -1;

int printBinary(char *str) {
  int i = -1;
  if (strcmp(ZERO, str) == 0) {
    i = 0;
  } else if (strcmp(ONE, str) == 0) {
    i = 1;
  } else if (strcmp(TWO, str) == 0) {
    i = 2;
  } else if (strcmp(THREE, str) == 0) {
    i = 3;
  } else if (strcmp(FOUR, str) == 0) {
    i = 4;
  } else if (strcmp(FIVE, str) == 0) {
    i = 5;
  } else if (strcmp(SIX, str) == 0) {
    i = 6;
  } else if (strcmp(SEVEN, str) == 0) {
    i = 7;
  } else if (strcmp(EIGHT, str) == 0) {
    i = 8;
  } else if (strcmp(NINE, str) == 0) {
    i = 9;
  } else if (strcmp(LAST, str) == 0) {
    i = 10;
  } else if (strcmp(MUTE, str) == 0) {
    i = 11;
  } else {
    i = -1;
  }
  // free str
  free(str);
  return i;
}

int c_letter = 0;
volatile int key_time = -1;

void PrintChar() {
  Report("Display: %c\n\r", digits[state][c_letter]);
  state = -1;
  c_letter = 0;
}

volatile int cx = 0;
volatile int cy = 0;

int colors[]={WHITE, RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA};
volatile int curr_color=0;

typedef struct {
    char letter;
    int color;
} Letter;

// Storing the letters 
volatile Letter sendArray[128];
volatile int nLetters = 0;

void HandleCode(int s) {
  if (s == -1) {
    state = -1;
    key_time = -1;
  } else if (s == 1) {
    curr_color++;
    if (curr_color > 6) {
      curr_color = 0;
    }
    if (state == -1)
      drawChar(cx, cy, '_', colors[curr_color], BLACK, 1);
    else
      drawChar(cx, cy, digits[state][c_letter], colors[curr_color], BLACK, 1);
  } else if (s == 10) {
    // Send the sendArray using MAP_UARTCharPut(UARTA1_BASE, c);
    int i;
    for (i = 0; i < nLetters; i++) {
      MAP_UARTCharPut(UARTA1_BASE, sendArray[i].letter);
      MAP_UARTCharPut(UARTA1_BASE, sendArray[i].color + '0');
      Report("%c %d, ", sendArray[i].letter, sendArray[i].color);
    }
    Report("\n\r");
    cx = 0;
    cy = 0;
    // clear the top half of the OLED
    for (i = 0; i <= nLetters; i++) {
      drawChar(cx, cy, ' ', WHITE, BLACK, 1);
      cx += 6;
      if (cx > 127) {
        cx = 0;
        cy += 8;
      }
    }
    cx=0;
    cy=0;
    nLetters = 0;
    drawChar(cx, cy, '_', WHITE, BLACK, 1);
  } else if (s == 11) {
    // Delete the last letter
    if (nLetters > 0) {
      nLetters--;
      drawChar(cx, cy, ' ', colors[curr_color], BLACK, 1);
      cx -= 6;
      drawChar(cx, cy, '_', colors[curr_color], BLACK, 1);
    }
  } else {
    key_time = 2;
    // cycle through the digits for the number
    if (state == s) {
      c_letter++;
      if (c_letter >= strlen(digits[s])) {
        c_letter = 0;
      }
    } else {
      // key pressed for the first time
      c_letter = 0;
    }
    drawChar(cx, cy, digits[s][c_letter], colors[curr_color], BLACK, 1);
    state = s;
  }
}

static void GPIOA2IntHandler(void) { // SW2 handler
  unsigned long ulStatus;

  ulStatus = MAP_GPIOIntStatus(ir_input.port, true);
  MAP_GPIOIntClear(ir_input.port, ulStatus); // clear interrupts on GPIOA2

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
    values[curr_index - 1] = d;
    curr_index++;
  }

  if (curr_index >= 33) {
    // disable interrupt
    MAP_GPIOIntDisable(ir_input.port, ir_input.pin);
    start = 0;
    curr_index = 0;
    HandleCode(printBinary(keyToBinary()));
    // enable interrupt
    MAP_GPIOIntEnable(ir_input.port, ir_input.pin);
  }
}

void TimerA0IntHandler(void) {
  Timer_IF_InterruptClear(TIMERA0_BASE);
  if (key_time > 0) {
    if (state != -1) {
      if (key_time % 2 != 0) {
        drawChar(cx, cy, digits[state][c_letter], colors[curr_color], BLACK, 1);
      } else {
        drawChar(cx, cy, '_', colors[curr_color], BLACK, 1);
      }
    }
    key_time--;
  } else if (key_time == 0) {
    key_time = -1;
    drawChar(cx, cy, digits[state][c_letter], colors[curr_color], BLACK, 1);
    // add char to sendArray
    sendArray[nLetters].letter = digits[state][c_letter];
    sendArray[nLetters].color = curr_color;
    nLetters++;
    // increase the x position
    cx+=6;
    if (cx >= 128) {
      cx = 0;
      cy+=8;
    }
    drawChar(cx, cy, '_', colors[curr_color], BLACK, 1);
    PrintChar();
  }
}

volatile int rx = 0, ry = 65;
volatile char rx_prev = ' ';
void UARTIntHandler(void)
{
    UARTIntClear(UARTA1_BASE, UART_INT_RX | UART_INT_RT | UART_INT_TX);

    unsigned long intStatus = UARTIntStatus(UARTA1_BASE, true);
    rx=0;
    ry=65;
    rx_prev = ' ';
    // clear the lower half
    drawRect(0, 64, 128, 64, BLACK);
    while (UARTCharsAvail(UARTA1_BASE)) {
        unsigned char character = MAP_UARTCharGet(UARTA1_BASE);
        // print in the lower half of the OLED
        // the characters will come like A1B0.... where A is the letter and 1 is the color
        if (character >= '0' && character <= '9') {
          drawChar(rx, ry, rx_prev, colors[character - '0'], BLACK, 1);
          rx += 6;
          if (rx >= 128) {
            rx = 0;
            ry += 8;
          }
        }
        rx_prev = character;
        Report("%c", character);
    }
}

void GPIOInit() {
  MAP_GPIOIntRegister(ir_input.port, GPIOA2IntHandler);
  //   MAP_GPIOIntTypeSet(pin8.port, pin8.pin, GPIO_RISING_EDGE); // SW2
  MAP_GPIOIntTypeSet(ir_input.port, ir_input.pin, 0x0); // SW2
  unsigned long ulStatus = MAP_GPIOIntStatus(ir_input.port, false);
  MAP_GPIOIntClear(ir_input.port, ulStatus);
  pin8_intcount = 0;
  pin8_intflag = 0;
  MAP_GPIOIntEnable(ir_input.port, ir_input.pin);
}

void TimerInit() {
  g_ulBase = TIMERA0_BASE;
  g_ulRefBase = TIMERA1_BASE;
  Timer_IF_Init(PRCM_TIMERA0, g_ulBase, TIMER_CFG_PERIODIC, TIMER_A, 0);
  Timer_IF_Init(PRCM_TIMERA1, g_ulRefBase, TIMER_CFG_PERIODIC, TIMER_A, 0);
  Timer_IF_IntSetup(TIMERA0_BASE, TIMER_A, TimerA0IntHandler);
  Timer_IF_Stop(TIMERA0_BASE, TIMER_A);
  MAP_TimerLoadSet(TIMERA0_BASE, TIMER_A, 40000);
}

void UartInit() {
  MAP_UARTConfigSetExpClk(
      UARTA1_BASE, MAP_PRCMPeripheralClockGet(PRCM_UARTA1), UART_BAUD_RATE,
      (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

  MAP_UARTIntRegister(UARTA1_BASE, UARTIntHandler);
  MAP_UARTIntEnable(UARTA1_BASE,  UART_INT_RX | UART_INT_RT | UART_INT_TX);

  unsigned long uartStatus = UARTIntStatus(UARTA1_BASE, false);
  UARTIntClear(UARTA1_BASE, uartStatus);

  MAP_UARTDMAEnable(UARTA1_BASE, UART_DMA_TX);
}

void SPIInit() {
  MAP_PRCMPeripheralReset(PRCM_GSPI);
  MAP_SPIReset(GSPI_BASE);

  //
  // Configure SPI interface
  //
  MAP_SPIConfigSetExpClk(GSPI_BASE, MAP_PRCMPeripheralClockGet(PRCM_GSPI),
                         SPI_IF_BIT_RATE, SPI_MODE_MASTER, SPI_SUB_MODE_0,
                         (SPI_SW_CTRL_CS | SPI_4PIN_MODE | SPI_TURBO_OFF |
                          SPI_CS_ACTIVEHIGH | SPI_WL_8));

  //
  // Enable SPI for communication
  //
  MAP_SPIEnable(GSPI_BASE);

  Adafruit_Init();
  fillScreen(BLACK);
  drawChar(cx, cy, '_', colors[curr_color], BLACK, 1);
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
  MAP_PRCMPeripheralClkEnable(PRCM_GSPI, PRCM_RUN_MODE_CLK);
  //
  // Initialising the Terminal.
  //
  InitTerm();
  //
  // Clearing the Terminal.
  //
  ClearTerm();
  UartInit();
  SPIInit();
  GPIOInit();
  TimerInit();

  DisplayBanner(APP_NAME);

  while (1) {
  }
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
