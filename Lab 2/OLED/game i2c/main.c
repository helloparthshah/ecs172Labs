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
// Application Name     - I2C
// Application Overview - The objective of this application is act as an I2C
//                        diagnostic tool. The demo application is a generic
//                        implementation that allows the user to communicate
//                        with any I2C device over the lines.
// Application Details  -
// http://processors.wiki.ti.com/index.php/CC32xx_I2C_Application
// or
// docs\examples\CC32xx_I2C_Application.pdf
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup i2c_demo
//! @{
//
//*****************************************************************************

// Standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driverlib includes
#include "hw_common_reg.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "interrupt.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
#include "uart.h"
#include "utils.h"

// Common interface includes
#include "i2c_if.h"
#include "spi.h"
#include "uart_if.h"

#include "pin_mux_config.h"

#include "Adafruit_GFX.h"
#include "Adafruit_SSD1351.h"
#include "glcdfont.h"
#include "test.h"

#define SPI_IF_BIT_RATE 100000
#define TR_BUFF_SIZE 100

//*****************************************************************************
//                      MACRO DEFINITIONS
//*****************************************************************************
#define APPLICATION_VERSION "1.1.1"
#define APP_NAME "I2C Demo"
#define UART_PRINT Report
#define FOREVER 1
#define CONSOLE UARTA0_BASE
#define FAILURE -1
#define SUCCESS 0
#define RETERR_IF_TRUE(condition)                                              \
  {                                                                            \
    if (condition)                                                             \
      return FAILURE;                                                          \
  }
#define RET_IF_ERR(Func)                                                       \
  {                                                                            \
    int iRetVal = (Func);                                                      \
    if (SUCCESS != iRetVal)                                                    \
      return iRetVal;                                                          \
  }

//*****************************************************************************
//                 GLOBAL VARIABLES -- Start
//*****************************************************************************
#if defined(ccs)
extern void (*const g_pfnVectors[])(void);
#endif
#if defined(ewarm)
extern uVectorEntry __vector_table;
#endif
//*****************************************************************************
//                 GLOBAL VARIABLES -- End
//*****************************************************************************

//****************************************************************************
//                      LOCAL FUNCTION DEFINITIONS
//****************************************************************************

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
  Report("\t\t      CC3200 %s Application       \n\r", AppName);
  Report("\t\t *************************************************\n\r");
  Report("\n\n\n\r");
}

//****************************************************************************
//
//! Parses the readreg command parameters and invokes the I2C APIs
//! i2c readreg 0x<dev_addr> 0x<reg_offset> <rdlen>
//!
//! \param pcInpString pointer to the readreg command parameters
//!
//! This function
//!    1. Parses the readreg command parameters.
//!    2. Invokes the corresponding I2C APIs
//!
//! \return 0: Success, < 0: Failure.
//
//****************************************************************************

float paddle_x = 64;
int MovePaddle() {
  unsigned char ucDevAddr = 0x18, ucRegOffset = 0x2, ucRdLen = 6;
  unsigned char aucRdDataBuf[256];
  I2C_IF_Write(ucDevAddr, &ucRegOffset, 1, 0);
  I2C_IF_Read(ucDevAddr, &aucRdDataBuf[0], ucRdLen);
  float x = (int)((signed char)aucRdDataBuf[1]);
  fillRect((int)paddle_x, (int)2, 20, 2, BLACK);
  paddle_x -= x / 8;
  // apply constraints
  if (paddle_x <= 0)
    paddle_x = 0;
  if (paddle_x >= 127 - 20)
    paddle_x = 127 - 20;

  fillRect((int)paddle_x, (int)2, 20, 2, RED);
  return 0;
}

float curr_x = 64, curr_y = 6;
int xvelocity = 2, yvelocity = -2;

void MoveBall() {
  fillCircle((int)curr_x, (int)curr_y, 2, BLACK);
  curr_x += xvelocity;
  curr_y += yvelocity;
  if (curr_x >= 125)
    xvelocity = -2;
  if (curr_x <= 2)
    xvelocity = 2;
  if (curr_y >= 125)
    yvelocity = -2;
  if (curr_y <= 6 && curr_x >= paddle_x && curr_x <= paddle_x + 20)
    yvelocity = 2;
  else if (curr_y <= 2) {
    curr_x = 64;
    curr_y = 32;
  }
  fillCircle((int)curr_x, (int)curr_y, 2, WHITE);
}

int boxes[3][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
int w = 32;
int h = 16;
int nx = 3, ny = 4;
int ischange = 1;
void checkCollisions() {
  int i, j;
  // check for collisions with the boxes
  for (i = 0; i < nx; i++) {
    for (j = 0; j < ny; j++) {
      if (boxes[i][j] == 1) {
        // x and y are 127 - (w + w / 2 + i * (w + 2)), 127 - (h + j * (h + 2))
        // change yvelocity if collision with bottom
        if (curr_y + 2 >= 127 - (h + j * (h + 2)) &&
            curr_y + 2 <= 127 - (h + j * (h + 2)) + h) {
          if (curr_x + 2 >= 127 - (w + w / 2 + i * (w + 2)) &&
              curr_x + 2 <= 127 - (w + w / 2 + i * (w + 2)) + w) {
            yvelocity *= -1;
            boxes[i][j] = 0;
            ischange = 1;
          }
        }
        // change xvelocity if collision with right
        if (curr_x + 2 >= 127 - (w + w / 2 + i * (w + 2)) &&
            curr_x + 2 <= 127 - (w + w / 2 + i * (w + 2)) + w &&
            boxes[i][j] == 1) {
          if (curr_y + 2 >= 127 - (h + j * (h + 2)) &&
              curr_y + 2 <= 127 - (h + j * (h + 2)) + h) {
            xvelocity *= -1;
            boxes[i][j] = 0;
            ischange = 1;
          }
        }
        // change yvelocity if collision with top
        if (curr_y - 2 <= 127 - (h + j * (h + 2)) + h &&
            curr_y - 2 >= 127 - (h + j * (h + 2))) {
          if (curr_x - 2 <= 127 - (w + w / 2 + i * (w + 2)) + w &&
              curr_x - 2 >= 127 - (w + w / 2 + i * (w + 2)) &&
              boxes[i][j] == 1) {
            yvelocity *= -1;
            boxes[i][j] = 0;
            ischange = 1;
          }
        }
        // change xvelocity if collision with left
        if (curr_x - 2 <= 127 - (w + w / 2 + i * (w + 2)) + w &&
            curr_x - 2 >= 127 - (w + w / 2 + i * (w + 2)) && boxes[i][j] == 1) {
          if (curr_y - 2 <= 127 - (h + j * (h + 2)) + h &&
              curr_y - 2 >= 127 - (h + j * (h + 2))) {
            xvelocity = 2;
            boxes[i][j] = 0;
            ischange = 1;
          }
        }
      }
    }
  }
  if (ischange == 1) {
    ischange = 0;
    for (i = 0; i < nx; i++) {
      for (j = 0; j < ny; j++) {
        if (boxes[i][j] == 0) {
          fillRect(127 - (w + w / 2 + i * (w + 2)), 127 - (h + j * (h + 2)), w,
                   h, BLACK);
        }
      }
    }
  }
}

int checkWin() {
  int i, j;
  for (i = 0; i < nx; i++) {
    for (j = 0; j < ny; j++) {
      if (boxes[i][j] == 1) {
        return 0;
      }
    }
  }
  return 1;
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

//*****************************************************************************
//
//! Main function handling the I2C example
//!
//! \param  None
//!
//! \return None
//!
//*****************************************************************************
void main() {
  //
  // Initialize board configurations
  //
  BoardInit();

  //
  // Configure the pinmux settings for the peripherals exercised
  //
  PinMuxConfig();

  //
  // Configuring UART
  //
  InitTerm();
  ClearTerm();
  //
  // I2C Init
  //
  I2C_IF_Open(I2C_MASTER_MODE_FST);

  //
  // Display the banner followed by the usage description
  //
  DisplayBanner(APP_NAME);
  //
  // Reset the peripheral
  //
  MAP_PRCMPeripheralReset(PRCM_GSPI);
  // Adafruit_Init();
  // fillScreen(0xFFF);
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
  int i, j;
  for (i = 0; i < nx; i++) {
    for (j = 0; j < ny; j++) {
      fillRect(127 - (w + w / 2 + i * (w + 2)), 127 - (h + j * (h + 2)), w, h,
               RED);
    }
  }
  while (FOREVER) {
    if (checkWin() == 1) {
      break;
    }
    MovePaddle();
    checkCollisions();
    MoveBall();
  }
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @
//
//*****************************************************************************
