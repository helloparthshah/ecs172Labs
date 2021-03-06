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
// Application Name     -   SSL Demo
// Application Overview -   This is a sample application demonstrating the
//                          use of secure sockets on a CC3200 device.The
//                          application connects to an AP and
//                          tries to establish a secure connection to the
//                          Google server.
// Application Details  -
// docs\examples\CC32xx_SSL_Demo_Application.pdf
// or
// http://processors.wiki.ti.com/index.php/CC32xx_SSL_Demo_Application
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup ssl
//! @{
//
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Simplelink includes
#include "simplelink.h"

// Driverlib includes
#include "hw_ints.h"
#include "hw_types.h"
#include "gpio.h"
#include "hw_apps_rcm.h"
#include "hw_common_reg.h"
#include "hw_memmap.h"
#include "interrupt.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
#include "spi.h"
#include "timer.h"
#include "uart.h"
#include "utils.h"


// Common interface includes
#include "common.h"
#include "gpio_if.h"
#include "pinmux.h"
#include "timer_if.h"
#include "uart_if.h"

#include "Adafruit_GFX.h"
#include "Adafruit_SSD1351.h"
#include "glcdfont.h"
#include "test.h"

#include "jsmn.h"
#include <http/client/common.h>
#include <http/client/httpcli.h>

#define APPLICATION_VERSION "1.1.1"
#define APP_NAME "HTTP Client"

#define POST_REQUEST_URI "/predict"

#define LOGIN_URI "/login"

#define DELETE_REQUEST_URI "/delete"

#define PUT_REQUEST_URI "/put"
#define PUT_DATA "PUT request."

#define GET_REQUEST_URI "/"

#define HOST_NAME "eec172-parth.herokuapp.com" //"<host name>"
#define HOST_PORT 80

#define PROXY_IP <proxy_ip>
#define PROXY_PORT <proxy_port>

#define READ_SIZE 1450
#define MAX_BUFF_SIZE 1460

#define MAX_URI_SIZE 128
#define URI_SIZE MAX_URI_SIZE + 1
#define CONSOLE UARTA0_BASE
#define UartGetChar() MAP_UARTCharGet(CONSOLE)
#define UartPutChar(c) MAP_UARTCharPut(CONSOLE, c)
#define SPI_IF_BIT_RATE 100000

#define APPLICATION_NAME "SSL"
#define APPLICATION_VERSION "1.1.1.EEC.Spring2022"
#define SERVER_NAME "a2g61oh3aerzxp-ats.iot.us-west-1.amazonaws.com"
#define GOOGLE_DST_PORT 8443

#define SL_SSL_CA_CERT                                                         \
  "/cert/rootCA.der" // starfield class2 rootca (from firefox) // <-- this one
                     // works
#define SL_SSL_PRIVATE "/cert/private.der"
#define SL_SSL_CLIENT "/cert/client.der"

volatile int TLS_SOCKET_ID = -1;

// NEED TO UPDATE THIS FOR IT TO WORK!
#define DATE 12   /* Current Date */
#define MONTH 5   /* Month 1-12 */
#define YEAR 2022 /* Current year */
#define HOUR 6    /* Time - hours */
#define MINUTE 00 /* Time - minutes */
#define SECOND 0  /* Time - seconds */

#define POSTHEADER "POST /things/Parth_CC3200/shadow HTTP/1.1\n\r"
#define HOSTHEADER "Host: a2g61oh3aerzxp-ats.iot.us-west-1.amazonaws.com\r\n"
#define CHEADER "Connection: Keep-Alive\r\n"
#define CTHEADER "Content-Type: application/json; charset=utf-8\r\n"
#define CLHEADER1 "Content-Length: "
#define CLHEADER2 "\r\n\r\n"

char *auth_token = NULL;

char *generateBody(Sl_WlanNetworkEntry_t found_networks[5], int network_count) {
  // create the body of the post request in the form of POST_DATA with data
  // {"eec172":eec172, "theuc":theuc, "theu":theu}
  // create a string with found networks.ssid as key and found networks.rssi as
  // value
  char *body = (char *)malloc(sizeof(char) * MAX_BUFF_SIZE);
  strcat(body, "{\n");
  int i = 0;
  for (i = 0; i < network_count; i++) {
    strcat(body, "\"");
    strcat(body, found_networks[i].ssid);
    strcat(body, "\":");
    // convert rssi to string
    char rssi_str[4];
    sprintf(rssi_str, "%d", found_networks[i].rssi);
    strcat(body, rssi_str);
    if (i != network_count - 1) {
      strcat(body, ",\n");
    }
  }
  // add authorization token
  strcat(body, ",\n\"Authorization\":\"");
  strcat(body, "Bearer ");
  strcat(body, auth_token);
  strcat(body, "\"\n}");
  return body;
}

// Application specific status/error codes
typedef enum {
  /* Choosing this number to avoid overlap with host-driver's error codes */
  DEVICE_NOT_IN_STATION_MODE = -0x7D0,
  DEVICE_START_FAILED = DEVICE_NOT_IN_STATION_MODE - 1,
  INVALID_HEX_STRING = DEVICE_START_FAILED - 1,
  TCP_RECV_ERROR = INVALID_HEX_STRING - 1,
  TCP_SEND_ERROR = TCP_RECV_ERROR - 1,
  FILE_NOT_FOUND_ERROR = TCP_SEND_ERROR - 1,
  INVALID_SERVER_RESPONSE = FILE_NOT_FOUND_ERROR - 1,
  FORMAT_NOT_SUPPORTED = INVALID_SERVER_RESPONSE - 1,
  FILE_OPEN_FAILED = FORMAT_NOT_SUPPORTED - 1,
  FILE_WRITE_ERROR = FILE_OPEN_FAILED - 1,
  INVALID_FILE = FILE_WRITE_ERROR - 1,
  SERVER_CONNECTION_FAILED = INVALID_FILE - 1,
  GET_HOST_IP_FAILED = SERVER_CONNECTION_FAILED - 1,

  STATUS_CODE_MAX = -0xBB8
} e_AppStatusCodes;

typedef struct {
  /* time */
  unsigned long tm_sec;
  unsigned long tm_min;
  unsigned long tm_hour;
  /* date */
  unsigned long tm_day;
  unsigned long tm_mon;
  unsigned long tm_year;
  unsigned long tm_week_day; // not required
  unsigned long tm_year_day; // not required
  unsigned long reserved[3];
} SlDateTime;

//*****************************************************************************
//                 GLOBAL VARIABLES -- Start
//*****************************************************************************
volatile unsigned long g_ulStatus = 0; // SimpleLink Status
unsigned long g_ulDestinationIP;       // IP address of destination server
unsigned long g_ulPingPacketsRecv = 0; // Number of Ping Packets received
unsigned long g_ulGatewayIP = 0;       // Network Gateway IP address
unsigned char g_ucConnectionSSID[SSID_LEN_MAX + 1]; // Connection SSID
unsigned char g_ucConnectionBSSID[BSSID_LEN_MAX];   // Connection BSSID
unsigned char g_buff[MAX_BUFF_SIZE + 1];
signed char *g_Host = SERVER_NAME;
SlDateTime g_time;
#if defined(ccs) || defined(gcc)
extern void (*const g_pfnVectors[])(void);
#endif
#if defined(ewarm)
extern uVectorEntry __vector_table;
#endif
//*****************************************************************************
//                 GLOBAL VARIABLES -- End: df
//*****************************************************************************

//****************************************************************************
//                      LOCAL FUNCTION PROTOTYPES
//****************************************************************************
static long WlanConnect();
static int set_time();
static void BoardInit(void);
static long InitializeAppVariables();
static int tls_connect();
static int connectToAccessPoint();

//*****************************************************************************
// SimpleLink Asynchronous Event Handlers -- Start
//*****************************************************************************

//*****************************************************************************
//
//! \brief The Function Handles WLAN Events
//!
//! \param[in]  pWlanEvent - Pointer to WLAN Event Info
//!
//! \return None
//!
//*****************************************************************************
void SimpleLinkWlanEventHandler(SlWlanEvent_t *pWlanEvent) {
  if (!pWlanEvent) {
    return;
  }

  switch (pWlanEvent->Event) {
  case SL_WLAN_CONNECT_EVENT: {
    SET_STATUS_BIT(g_ulStatus, STATUS_BIT_CONNECTION);

    //
    // Information about the connected AP (like name, MAC etc) will be
    // available in 'slWlanConnectAsyncResponse_t'.
    // Applications can use it if required
    //
    //  slWlanConnectAsyncResponse_t *pEventData = NULL;
    // pEventData = &pWlanEvent->EventData.STAandP2PModeWlanConnected;
    //

    // Copy new connection SSID and BSSID to global parameters
    memcpy(g_ucConnectionSSID,
           pWlanEvent->EventData.STAandP2PModeWlanConnected.ssid_name,
           pWlanEvent->EventData.STAandP2PModeWlanConnected.ssid_len);
    memcpy(g_ucConnectionBSSID,
           pWlanEvent->EventData.STAandP2PModeWlanConnected.bssid,
           SL_BSSID_LENGTH);

    printf("[WLAN EVENT] STA Connected to the AP: %s , "
           "BSSID: %x:%x:%x:%x:%x:%x\n\r",
           g_ucConnectionSSID, g_ucConnectionBSSID[0], g_ucConnectionBSSID[1],
           g_ucConnectionBSSID[2], g_ucConnectionBSSID[3],
           g_ucConnectionBSSID[4], g_ucConnectionBSSID[5]);
  } break;

  case SL_WLAN_DISCONNECT_EVENT: {
    slWlanConnectAsyncResponse_t *pEventData = NULL;

    CLR_STATUS_BIT(g_ulStatus, STATUS_BIT_CONNECTION);
    CLR_STATUS_BIT(g_ulStatus, STATUS_BIT_IP_AQUIRED);

    pEventData = &pWlanEvent->EventData.STAandP2PModeDisconnected;

    // If the user has initiated 'Disconnect' request,
    //'reason_code' is SL_USER_INITIATED_DISCONNECTION
    if (SL_USER_INITIATED_DISCONNECTION == pEventData->reason_code) {
      printf("[WLAN EVENT]Device disconnected from the AP: %s,"
             "BSSID: %x:%x:%x:%x:%x:%x on application's request \n\r",
             g_ucConnectionSSID, g_ucConnectionBSSID[0], g_ucConnectionBSSID[1],
             g_ucConnectionBSSID[2], g_ucConnectionBSSID[3],
             g_ucConnectionBSSID[4], g_ucConnectionBSSID[5]);
    } else {
      printf("[WLAN ERROR]Device disconnected from the AP AP: %s, "
             "BSSID: %x:%x:%x:%x:%x:%x on an ERROR..!! \n\r",
             g_ucConnectionSSID, g_ucConnectionBSSID[0], g_ucConnectionBSSID[1],
             g_ucConnectionBSSID[2], g_ucConnectionBSSID[3],
             g_ucConnectionBSSID[4], g_ucConnectionBSSID[5]);
    }
    memset(g_ucConnectionSSID, 0, sizeof(g_ucConnectionSSID));
    memset(g_ucConnectionBSSID, 0, sizeof(g_ucConnectionBSSID));
  } break;

  default: {
    printf("[WLAN EVENT] Unexpected event [0x%x]\n\r", pWlanEvent->Event);
  } break;
  }
}

//*****************************************************************************
//
//! \brief This function handles network events such as IP acquisition, IP
//!           leased, IP released etc.
//!
//! \param[in]  pNetAppEvent - Pointer to NetApp Event Info
//!
//! \return None
//!
//*****************************************************************************
void SimpleLinkNetAppEventHandler(SlNetAppEvent_t *pNetAppEvent) {
  if (!pNetAppEvent) {
    return;
  }

  switch (pNetAppEvent->Event) {
  case SL_NETAPP_IPV4_IPACQUIRED_EVENT: {
    SlIpV4AcquiredAsync_t *pEventData = NULL;

    SET_STATUS_BIT(g_ulStatus, STATUS_BIT_IP_AQUIRED);

    // Ip Acquired Event Data
    pEventData = &pNetAppEvent->EventData.ipAcquiredV4;

    // Gateway IP address
    g_ulGatewayIP = pEventData->gateway;

    printf("[NETAPP EVENT] IP Acquired: IP=%d.%d.%d.%d , "
           "Gateway=%d.%d.%d.%d\n\r",
           SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.ip, 3),
           SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.ip, 2),
           SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.ip, 1),
           SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.ip, 0),
           SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.gateway, 3),
           SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.gateway, 2),
           SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.gateway, 1),
           SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.gateway, 0));
  } break;

  default: {
    printf("[NETAPP EVENT] Unexpected event [0x%x] \n\r", pNetAppEvent->Event);
  } break;
  }
}

//*****************************************************************************
//
//! \brief This function handles HTTP server events
//!
//! \param[in]  pServerEvent - Contains the relevant event information
//! \param[in]    pServerResponse - Should be filled by the user with the
//!                                      relevant response information
//!
//! \return None
//!
//****************************************************************************
void SimpleLinkHttpServerCallback(SlHttpServerEvent_t *pHttpEvent,
                                  SlHttpServerResponse_t *pHttpResponse) {
  // Unused in this application
}

//*****************************************************************************
//
//! \brief This function handles General Events
//!
//! \param[in]     pDevEvent - Pointer to General Event Info
//!
//! \return None
//!
//*****************************************************************************
void SimpleLinkGeneralEventHandler(SlDeviceEvent_t *pDevEvent) {
  if (!pDevEvent) {
    return;
  }

  //
  // Most of the general errors are not FATAL are are to be handled
  // appropriately by the application
  //
  printf("[GENERAL EVENT] - ID=[%d] Sender=[%d]\n\n",
         pDevEvent->EventData.deviceEvent.status,
         pDevEvent->EventData.deviceEvent.sender);
}

//*****************************************************************************
//
//! This function handles socket events indication
//!
//! \param[in]      pSock - Pointer to Socket Event Info
//!
//! \return None
//!
//*****************************************************************************
void SimpleLinkSockEventHandler(SlSockEvent_t *pSock) {
  if (!pSock) {
    return;
  }

  switch (pSock->Event) {
  case SL_SOCKET_TX_FAILED_EVENT:
    switch (pSock->socketAsyncEvent.SockTxFailData.status) {
    case SL_ECLOSE:
      printf("[SOCK ERROR] - close socket (%d) operation "
             "failed to transmit all queued packets\n\n",
             pSock->socketAsyncEvent.SockTxFailData.sd);
      break;
    default:
      printf("[SOCK ERROR] - TX FAILED  :  socket %d , reason "
             "(%d) \n\n",
             pSock->socketAsyncEvent.SockTxFailData.sd,
             pSock->socketAsyncEvent.SockTxFailData.status);
      break;
    }
    break;

  default:
    printf("[SOCK EVENT] - Unexpected Event [%x0x]\n\n", pSock->Event);
    break;
  }
}

//*****************************************************************************
// SimpleLink Asynchronous Event Handlers -- End breadcrumb: s18_df
//*****************************************************************************

//*****************************************************************************
//
//! \brief This function initializes the application variables
//!
//! \param    0 on success else error code
//!
//! \return None
//!
//*****************************************************************************
static long InitializeAppVariables() {
  g_ulStatus = 0;
  g_ulGatewayIP = 0;
  g_Host = SERVER_NAME;
  memset(g_ucConnectionSSID, 0, sizeof(g_ucConnectionSSID));
  memset(g_ucConnectionBSSID, 0, sizeof(g_ucConnectionBSSID));
  return SUCCESS;
}

//*****************************************************************************
//! \brief This function puts the device in its default state. It:
//!           - Set the mode to STATION
//!           - Configures connection policy to Auto and AutoSmartConfig
//!           - Deletes all the stored profiles
//!           - Enables DHCP
//!           - Disables Scan policy
//!           - Sets Tx power to maximum
//!           - Sets power policy to normal
//!           - Unregister mDNS services
//!           - Remove all filters
//!
//! \param   none
//! \return  On success, zero is returned. On error, negative is returned
//*****************************************************************************
static long ConfigureSimpleLinkToDefaultState() {
  SlVersionFull ver = {0};
  _WlanRxFilterOperationCommandBuff_t RxFilterIdMask = {0};

  unsigned char ucVal = 1;
  unsigned char ucConfigOpt = 0;
  unsigned char ucConfigLen = 0;
  unsigned char ucPower = 0;

  long lRetVal = -1;
  long lMode = -1;

  lMode = sl_Start(0, 0, 0);
  ASSERT_ON_ERROR(lMode);

  // If the device is not in station-mode, try configuring it in station-mode
  if (ROLE_STA != lMode) {
    if (ROLE_AP == lMode) {
      // If the device is in AP mode, we need to wait for this event
      // before doing anything
      while (!IS_IP_ACQUIRED(g_ulStatus)) {
#ifndef SL_PLATFORM_MULTI_THREADED
        _SlNonOsMainLoopTask();
#endif
      }
    }

    // Switch to STA role and restart
    lRetVal = sl_WlanSetMode(ROLE_STA);
    ASSERT_ON_ERROR(lRetVal);

    lRetVal = sl_Stop(0xFF);
    ASSERT_ON_ERROR(lRetVal);

    lRetVal = sl_Start(0, 0, 0);
    ASSERT_ON_ERROR(lRetVal);

    // Check if the device is in station again
    if (ROLE_STA != lRetVal) {
      // We don't want to proceed if the device is not coming up in STA-mode
      return DEVICE_NOT_IN_STATION_MODE;
    }
  }

  // Get the device's version-information
  ucConfigOpt = SL_DEVICE_GENERAL_VERSION;
  ucConfigLen = sizeof(ver);
  lRetVal = sl_DevGet(SL_DEVICE_GENERAL_CONFIGURATION, &ucConfigOpt,
                      &ucConfigLen, (unsigned char *)(&ver));
  ASSERT_ON_ERROR(lRetVal);

  printf("Host Driver Version: %s\n\r", SL_DRIVER_VERSION);
  printf("Build Version %d.%d.%d.%d.31.%d.%d.%d.%d.%d.%d.%d.%d\n\r",
         ver.NwpVersion[0], ver.NwpVersion[1], ver.NwpVersion[2],
         ver.NwpVersion[3], ver.ChipFwAndPhyVersion.FwVersion[0],
         ver.ChipFwAndPhyVersion.FwVersion[1],
         ver.ChipFwAndPhyVersion.FwVersion[2],
         ver.ChipFwAndPhyVersion.FwVersion[3],
         ver.ChipFwAndPhyVersion.PhyVersion[0],
         ver.ChipFwAndPhyVersion.PhyVersion[1],
         ver.ChipFwAndPhyVersion.PhyVersion[2],
         ver.ChipFwAndPhyVersion.PhyVersion[3]);

  // Set connection policy to Auto + SmartConfig
  //      (Device's default connection policy)
  lRetVal = sl_WlanPolicySet(SL_POLICY_CONNECTION,
                             SL_CONNECTION_POLICY(1, 0, 0, 0, 1), NULL, 0);
  ASSERT_ON_ERROR(lRetVal);

  // Remove all profiles
  lRetVal = sl_WlanProfileDel(0xFF);
  ASSERT_ON_ERROR(lRetVal);

  //
  // Device in station-mode. Disconnect previous connection if any
  // The function returns 0 if 'Disconnected done', negative number if already
  // disconnected Wait for 'disconnection' event if 0 is returned, Ignore
  // other return-codes
  //
  lRetVal = sl_WlanDisconnect();
  if (0 == lRetVal) {
    // Wait
    while (IS_CONNECTED(g_ulStatus)) {
#ifndef SL_PLATFORM_MULTI_THREADED
      _SlNonOsMainLoopTask();
#endif
    }
  }

  // Enable DHCP client
  lRetVal = sl_NetCfgSet(SL_IPV4_STA_P2P_CL_DHCP_ENABLE, 1, 1, &ucVal);
  ASSERT_ON_ERROR(lRetVal);

  // Disable scan
  ucConfigOpt = SL_SCAN_POLICY(0);
  lRetVal = sl_WlanPolicySet(SL_POLICY_SCAN, ucConfigOpt, NULL, 0);
  ASSERT_ON_ERROR(lRetVal);

  // Set Tx power level for station mode
  // Number between 0-15, as dB offset from max power - 0 will set max power
  ucPower = 0;
  lRetVal = sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID,
                       WLAN_GENERAL_PARAM_OPT_STA_TX_POWER, 1,
                       (unsigned char *)&ucPower);
  ASSERT_ON_ERROR(lRetVal);

  // Set PM policy to normal
  lRetVal = sl_WlanPolicySet(SL_POLICY_PM, SL_NORMAL_POLICY, NULL, 0);
  ASSERT_ON_ERROR(lRetVal);

  // Unregister mDNS services
  lRetVal = sl_NetAppMDNSUnRegisterService(0, 0);
  ASSERT_ON_ERROR(lRetVal);

  // Remove  all 64 filters (8*8)
  memset(RxFilterIdMask.FilterIdMask, 0xFF, 8);
  lRetVal = sl_WlanRxFilterSet(SL_REMOVE_RX_FILTER, (_u8 *)&RxFilterIdMask,
                               sizeof(_WlanRxFilterOperationCommandBuff_t));
  ASSERT_ON_ERROR(lRetVal);

  lRetVal = sl_Stop(SL_STOP_TIMEOUT);
  ASSERT_ON_ERROR(lRetVal);

  InitializeAppVariables();

  return lRetVal; // Success
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

//****************************************************************************
//
//! \brief Connecting to a WLAN Accesspoint
//!
//!  This function connects to the required AP (SSID_NAME) with Security
//!  parameters specified in te form of macros at the top of this file
//!
//! \param  None
//!
//! \return  0 on success else error code
//!
//! \warning    If the WLAN connection fails or we don't aquire an IP
//!            address, It will be stuck in this function forever.
//
//****************************************************************************
static long WlanConnect() {
  SlSecParams_t secParams = {0};
  long lRetVal = 0;

  secParams.Key = SECURITY_KEY;
  secParams.KeyLen = strlen(SECURITY_KEY);
  secParams.Type = SECURITY_TYPE;

  printf("Attempting connection to access point: ");
  printf(SSID_NAME);
  printf("... ...");
  lRetVal = sl_WlanConnect(SSID_NAME, strlen(SSID_NAME), 0, &secParams, 0);
  ASSERT_ON_ERROR(lRetVal);

  printf(" Connected!!!\n\r");

  // Wait for WLAN Event
  while ((!IS_CONNECTED(g_ulStatus)) || (!IS_IP_ACQUIRED(g_ulStatus))) {
    // Toggle LEDs to Indicate Connection Progress
    _SlNonOsMainLoopTask();
    GPIO_IF_LedOff(MCU_IP_ALLOC_IND);
    MAP_UtilsDelay(800000);
    _SlNonOsMainLoopTask();
    GPIO_IF_LedOn(MCU_IP_ALLOC_IND);
    MAP_UtilsDelay(800000);
  }
  printf("WLAN event received.\n\r");

  return SUCCESS;
}

long printErrConvenience(char *msg, long retVal) {
  printf(msg);
  GPIO_IF_LedOn(MCU_RED_LED_GPIO);
  return retVal;
}

//*****************************************************************************
//
//! This function updates the date and time of CC3200.
//!
//! \param None
//!
//! \return
//!     0 for success, negative otherwise
//!
//*****************************************************************************

static int set_time() {
  long retVal;

  g_time.tm_day = DATE;
  g_time.tm_mon = MONTH;
  g_time.tm_year = YEAR;
  g_time.tm_sec = HOUR;
  g_time.tm_hour = MINUTE;
  g_time.tm_min = SECOND;

  retVal = sl_DevSet(SL_DEVICE_GENERAL_CONFIGURATION,
                     SL_DEVICE_GENERAL_CONFIGURATION_DATE_TIME,
                     sizeof(SlDateTime), (unsigned char *)(&g_time));

  ASSERT_ON_ERROR(retVal);
  return SUCCESS;
}

//*****************************************************************************
//
//! This function demonstrates how certificate can be used with SSL.
//! The procedure includes the following steps:
//! 1) connect to an open AP
//! 2) get the server name via a DNS request
//! 3) define all socket options and point to the CA certificate
//! 4) connect to the server via TCP
//!
//! \param None
//!
//! \return  0 on success else error code
//! \return  LED1 is turned solid in case of success
//!    LED2 is turned solid in case of failure
//!
//*****************************************************************************
static int tls_connect() {
  SlSockAddrIn_t Addr;
  int iAddrSize;
  unsigned char ucMethod = SL_SO_SEC_METHOD_TLSV1_2;
  unsigned int uiIP;
  //    unsigned int uiCipher = SL_SEC_MASK_TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA;
  unsigned int uiCipher = SL_SEC_MASK_TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256;
  // SL_SEC_MASK_SSL_RSA_WITH_RC4_128_SHA
  // SL_SEC_MASK_SSL_RSA_WITH_RC4_128_MD5
  // SL_SEC_MASK_TLS_RSA_WITH_AES_256_CBC_SHA
  // SL_SEC_MASK_TLS_DHE_RSA_WITH_AES_256_CBC_SHA
  // SL_SEC_MASK_TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA
  // SL_SEC_MASK_TLS_ECDHE_RSA_WITH_RC4_128_SHA
  // SL_SEC_MASK_TLS_RSA_WITH_AES_128_CBC_SHA256
  // SL_SEC_MASK_TLS_RSA_WITH_AES_256_CBC_SHA256
  // SL_SEC_MASK_TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256
  // SL_SEC_MASK_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 // does not work (-340,
  // handshake fails)
  long lRetVal = -1;
  int iSockID;

  lRetVal = sl_NetAppDnsGetHostByName(g_Host, strlen((const char *)g_Host),
                                      (unsigned long *)&uiIP, SL_AF_INET);

  if (lRetVal < 0) {
    return printErrConvenience("Device couldn't retrieve the host name \n\r",
                               lRetVal);
  }

  Addr.sin_family = SL_AF_INET;
  Addr.sin_port = sl_Htons(GOOGLE_DST_PORT);
  Addr.sin_addr.s_addr = sl_Htonl(uiIP);
  iAddrSize = sizeof(SlSockAddrIn_t);
  //
  // opens a secure socket
  //
  iSockID = sl_Socket(SL_AF_INET, SL_SOCK_STREAM, SL_SEC_SOCKET);
  if (iSockID < 0) {
    return printErrConvenience("Device unable to create secure socket \n\r",
                               lRetVal);
  }

  //
  // configure the socket as TLS1.2
  //
  lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET, SL_SO_SECMETHOD, &ucMethod,
                          sizeof(ucMethod));
  if (lRetVal < 0) {
    return printErrConvenience("Device couldn't set socket options \n\r",
                               lRetVal);
  }
  //
  // configure the socket as ECDHE RSA WITH AES256 CBC SHA
  //
  lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET, SL_SO_SECURE_MASK, &uiCipher,
                          sizeof(uiCipher));
  if (lRetVal < 0) {
    return printErrConvenience("Device couldn't set socket options \n\r",
                               lRetVal);
  }

  /////////////////////////////////
  // START: COMMENT THIS OUT IF DISABLING SERVER VERIFICATION
  //
  // configure the socket with CA certificate - for server verification
  //
  lRetVal =
      sl_SetSockOpt(iSockID, SL_SOL_SOCKET, SL_SO_SECURE_FILES_CA_FILE_NAME,
                    SL_SSL_CA_CERT, strlen(SL_SSL_CA_CERT));

  if (lRetVal < 0) {
    return printErrConvenience("Device couldn't set socket options \n\r",
                               lRetVal);
  }
  // END: COMMENT THIS OUT IF DISABLING SERVER VERIFICATION
  /////////////////////////////////

  // configure the socket with Client Certificate - for server verification
  //
  lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET,
                          SL_SO_SECURE_FILES_CERTIFICATE_FILE_NAME,
                          SL_SSL_CLIENT, strlen(SL_SSL_CLIENT));

  if (lRetVal < 0) {
    return printErrConvenience("Device couldn't set socket options \n\r",
                               lRetVal);
  }

  // configure the socket with Private Key - for server verification
  //
  lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET,
                          SL_SO_SECURE_FILES_PRIVATE_KEY_FILE_NAME,
                          SL_SSL_PRIVATE, strlen(SL_SSL_PRIVATE));

  if (lRetVal < 0) {
    return printErrConvenience("Device couldn't set socket options \n\r",
                               lRetVal);
  }

  /* connect to the peer device - Google server */
  lRetVal = sl_Connect(iSockID, (SlSockAddr_t *)&Addr, iAddrSize);

  printf("Device is connecting to secure server %d\n\r", lRetVal);

  if (lRetVal >= 0) {
    printf("Device has connected to the website:");
    printf(SERVER_NAME);
    printf("\n\r");
  } else if (lRetVal == SL_ESECSNOVERIFY) {
    printf("Device has connected to the website (UNVERIFIED):");
    printf(SERVER_NAME);
    printf("\n\r");
  } else if (lRetVal < 0) {
    printf("Device couldn't connect to server:");
    printf(SERVER_NAME);
    printf("\n\r");
    return printErrConvenience("Device couldn't connect to server \n\r",
                               lRetVal);
  }

  GPIO_IF_LedOff(MCU_RED_LED_GPIO);
  GPIO_IF_LedOn(MCU_GREEN_LED_GPIO);
  return iSockID;
}

int connectToAccessPoint() {
  long lRetVal = -1;
  GPIO_IF_LedConfigure(LED1 | LED3);

  GPIO_IF_LedOff(MCU_RED_LED_GPIO);
  GPIO_IF_LedOff(MCU_GREEN_LED_GPIO);

  lRetVal = InitializeAppVariables();
  ASSERT_ON_ERROR(lRetVal);

  //
  // Following function configure the device to default state by cleaning
  // the persistent settings stored in NVMEM (viz. connection profiles &
  // policies, power policy etc)
  //
  // Applications may choose to skip this step if the developer is sure
  // that the device is in its default state at start of applicaton
  //
  // Note that all profiles and persistent settings that were done on the
  // device will be lost
  //
  lRetVal = ConfigureSimpleLinkToDefaultState();
  if (lRetVal < 0) {
    if (DEVICE_NOT_IN_STATION_MODE == lRetVal)
      printf("Failed to configure the device in its default state \n\r");

    return lRetVal;
  }

  printf("Device is configured in default state \n\r");

  CLR_STATUS_BIT_ALL(g_ulStatus);

  ///
  // Assumption is that the device is configured in station mode already
  // and it is in its default state
  //
  printf("Opening sl_start\n\r");
  lRetVal = sl_Start(0, 0, 0);
  if (lRetVal < 0 || ROLE_STA != lRetVal) {
    printf("Failed to start the device \n\r");
    return lRetVal;
  }

  printf("Device started as STATION \n\r");

  //
  // Connecting to WLAN AP
  //
  lRetVal = WlanConnect();
  if (lRetVal < 0) {
    printf("Failed to establish connection w/ an AP \n\r");
    GPIO_IF_LedOn(MCU_RED_LED_GPIO);
    return lRetVal;
  }

  printf("Connection established w/ AP and IP is aquired \n\r");
  return 0;
}

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

volatile unsigned long prev = 0, curr = 0;
volatile int start = 0;
volatile float values[35];
volatile int curr_index = 0;
char *keyToBinary() {
  // takes values list of 32 floats and returns a binary number
  // if float is from 1 to 2 then it is a 0 and if it is from 2 to 3 then a 1 at
  // the index

  char *str = malloc(33);
  int i;
  for (i = 0; i < 32; i++) {
    if (values[i + 1] < 2) {
      str[i] = '0';
    } else {
      str[i] = '1';
    }
    values[i + 1] = 0;
  }
  str[i] = '\0';
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
  printf("Display: %c\n\r", digits[state][c_letter]);
  state = -1;
  c_letter = 0;
}

volatile int cx = 0;
volatile int cy = 0;

int colors[] = {WHITE, RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA};
volatile int curr_color = 0;

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
    char *str = malloc(nLetters + 1);
    int i;
    for (i = 0; i < nLetters; i++) {
      str[i] = sendArray[i].letter;
      printf("%c %d, ", sendArray[i].letter, sendArray[i].color);
    }
    printf("\n\r");
    str[i] = '\0';

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
    cx = 0;
    cy = 0;
    nLetters = 0;
    drawChar(cx, cy, '_', WHITE, BLACK, 1);
    // http_post(TLS_SOCKET_ID, str);
    free(str);
    sl_Stop(SL_STOP_TIMEOUT);
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

volatile unsigned long ticks = 0;

static void GPIOA2IntHandler(void) { // SW2 handler
  unsigned long ulStatus;

  ulStatus = MAP_GPIOIntStatus(ir_input.port, true);
  MAP_GPIOIntClear(ir_input.port, ulStatus); // clear interrupts on GPIOA2

  float d = ((float)(ticks - prev)) / 10;
  if (d > 13 && d < 14) {
    start = 1;
    curr_index = 1;
  }
  prev = ticks;
  if (start) {
    values[curr_index - 1] = d;
    curr_index++;
  }

  if (curr_index >= 33) {
    ticks = 0;
    prev = 0;
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
    cx += 6;
    if (cx >= 128) {
      cx = 0;
      cy += 8;
    }
    drawChar(cx, cy, '_', colors[curr_color], BLACK, 1);
    PrintChar();
  }
}

void TimerA1IntHandler(void) {
  Timer_IF_InterruptClear(TIMERA1_BASE);
  ticks++;
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
  Timer_IF_IntSetup(TIMERA0_BASE, TIMER_A, TimerA0IntHandler);
  Timer_IF_Stop(TIMERA0_BASE, TIMER_A);
  MAP_TimerLoadSet(TIMERA0_BASE, TIMER_A, 80000000);
  MAP_TimerIntEnable(TIMERA0_BASE, TIMER_TIMA_TIMEOUT);
  MAP_TimerEnable(TIMERA0_BASE, TIMER_A);

  Timer_IF_Init(PRCM_TIMERA1, g_ulRefBase, TIMER_CFG_PERIODIC, TIMER_A, 0);
  Timer_IF_IntSetup(TIMERA1_BASE, TIMER_A, TimerA1IntHandler);
  Timer_IF_Stop(TIMERA1_BASE, TIMER_A);
  MAP_TimerLoadSet(TIMERA1_BASE, TIMER_A, 8000);
  MAP_TimerIntEnable(TIMERA1_BASE, TIMER_TIMA_TIMEOUT);
  MAP_TimerEnable(TIMERA1_BASE, TIMER_A);
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
}

static int FlushHTTPResponse(HTTPCli_Handle httpClient) {
  const char *ids[2] = {
      HTTPCli_FIELD_NAME_CONNECTION, /* App will get connection header value.
                                        all others will skip by lib */
      NULL};
  char buf[128];
  int id;
  int len = 1;
  bool moreFlag = 0;
  char **prevRespFilelds = NULL;

  /* Store previosly store array if any */
  prevRespFilelds = HTTPCli_setResponseFields(httpClient, ids);

  /* Read response headers */
  while ((id = HTTPCli_getResponseField(httpClient, buf, sizeof(buf),
                                        &moreFlag)) != HTTPCli_FIELD_ID_END) {

    if (id == 0) {
      if (!strncmp(buf, "close", sizeof("close"))) {
        printf("Connection terminated by server\n\r");
      }
    }
  }

  /* Restore previosuly store array if any */
  HTTPCli_setResponseFields(httpClient, (const char **)prevRespFilelds);

  while (1) {
    /* Read response data/body */
    /* Note:
            moreFlag will be set to 1 by HTTPCli_readResponseBody() call, if
       more data is available Or in other words content length > length of
       buffer. The remaining data will be read in subsequent call to
       HTTPCli_readResponseBody(). Please refer HTTP Client Libary API
       documenation @ref HTTPCli_readResponseBody for more information.
    */
    HTTPCli_readResponseBody(httpClient, buf, sizeof(buf) - 1, &moreFlag);
    ASSERT_ON_ERROR(len);

    if ((len - 2) >= 0 && buf[len - 2] == '\r' && buf[len - 1] == '\n') {
      break;
    }

    if (!moreFlag) {
      /* There no more data. break the loop. */
      break;
    }
  }
  return 0;
}

int ParseJSONData(char *ptr) {
  long lRetVal = 0;
  int noOfToken;
  jsmn_parser parser;
  jsmntok_t *tokenList;

  /* Initialize JSON PArser */
  jsmn_init(&parser);

  /* Get number of JSON token in stream as we we dont know how many tokens need
   * to pass */
  noOfToken = jsmn_parse(&parser, (const char *)ptr, strlen((const char *)ptr),
                         NULL, 10);
  if (noOfToken <= 0) {
    printf("Failed to initialize JSON parser\n\r");
    return -1;
  }

  /* Allocate memory to store token */
  tokenList = (jsmntok_t *)malloc(noOfToken * sizeof(jsmntok_t));
  if (tokenList == NULL) {
    printf("Failed to allocate memory\n\r");
    return -1;
  }

  /* Initialize JSON Parser again */
  jsmn_init(&parser);
  noOfToken = jsmn_parse(&parser, (const char *)ptr, strlen((const char *)ptr),
                         tokenList, noOfToken);
  if (noOfToken < 0) {
    printf("Failed to parse JSON tokens\n\r");
    lRetVal = noOfToken;
  } else {
    printf("Successfully parsed %ld JSON tokens\n\r", noOfToken);
  }

  /*
    int i = 0;
    for (i = 0; i < noOfToken; i++) {
      if (tokenList[i].type == JSMN_STRING) {
        printf("JSON String: %.*s\n\r", tokenList[i].end - tokenList[i].start,
               ptr + tokenList[i].start);
      }
    }
   */
  free(tokenList);

  return lRetVal;
}

int location = 0;

static int readResponse(HTTPCli_Handle httpClient) {
  long lRetVal = 0;
  int bytesRead = 0;
  int id = 0;
  unsigned long len = 0;
  int json = 0;
  char *dataBuffer = NULL;
  bool moreFlags = 1;
  const char *ids[4] = {HTTPCli_FIELD_NAME_CONTENT_LENGTH,
                        HTTPCli_FIELD_NAME_CONNECTION,
                        HTTPCli_FIELD_NAME_CONTENT_TYPE, NULL};

  /* Read HTTP POST request status code */
  lRetVal = HTTPCli_getResponseStatus(httpClient);
  printf("HTTP Response Status: %ld\n\r", lRetVal);
  if (lRetVal > 0) {
    switch (lRetVal) {
    case 200: {
      printf("HTTP Status 200\n\r");
      /*
Set response header fields to filter response headers. All
other than set by this call we be skipped by library.
       */
      HTTPCli_setResponseFields(httpClient, (const char **)ids);

      /* Read filter response header and take appropriate action. */
      /* Note:
  1. id will be same as index of fileds in filter array setted
  in previous HTTPCli_setResponseFields() call.

  2. moreFlags will be set to 1 by HTTPCli_getResponseField(), if  field
  value could not be completely read. A subsequent call to
  HTTPCli_getResponseField() will read remaining field value and will
  return HTTPCli_FIELD_ID_DUMMY. Please refer HTTP Client Libary API
  documenation @ref HTTPCli_getResponseField for more information.
       */
      while ((id = HTTPCli_getResponseField(httpClient, (char *)g_buff,
                                            sizeof(g_buff), &moreFlags)) !=
             HTTPCli_FIELD_ID_END) {

        switch (id) {
        case 0: /* HTTPCli_FIELD_NAME_CONTENT_LENGTH */
        {
          len = strtoul((char *)g_buff, NULL, 0);
        } break;
        case 1: /* HTTPCli_FIELD_NAME_CONNECTION */
        {
        } break;
        case 2: /* HTTPCli_FIELD_NAME_CONTENT_TYPE */
        {
          if (!strncmp((const char *)g_buff, "application/json",
                       sizeof("application/json"))) {
            json = 1;
          } else {
            /* Note:
Developers are advised to use appropriate
content handler. In this example all content
type other than json are treated as plain text.
             */
            json = 0;
          }
          printf(HTTPCli_FIELD_NAME_CONTENT_TYPE);
          printf(" : ");
          printf("application/json\n\r");
        } break;
        default: {
          printf("Wrong filter id\n\r");
          lRetVal = -1;
          goto end;
        }
        }
      }
      bytesRead = 0;
      if (len > sizeof(g_buff)) {
        dataBuffer = (char *)malloc(len);
        if (dataBuffer) {
          printf("Failed to allocate memory\n\r");
          lRetVal = -1;
          goto end;
        }
      } else {
        dataBuffer = (char *)g_buff;
      }

      /* Read response data/body */
      /* Note:
  moreFlag will be set to 1 by HTTPCli_readResponseBody() call, if more
          data is available Or in other words content length > length of buffer.
          The remaining data will be read in subsequent call to
  HTTPCli_readResponseBody(). Please refer HTTP Client Libary API documenation
  @ref HTTPCli_readResponseBody for more information

       */
      bytesRead = HTTPCli_readResponseBody(httpClient, (char *)dataBuffer, len,
                                           &moreFlags);
      if (bytesRead < 0) {
        printf("Failed to received response body\n\r");
        lRetVal = bytesRead;
        goto end;
      } else if (bytesRead < len || moreFlags) {
        printf("Mismatch in content length and received data length\n\r");
        goto end;
      }
      dataBuffer[bytesRead] = '\0';
      // printf("buffer: %s\n\r", dataBuffer);
      if (dataBuffer[0] == '{') {
        // {"prediction":1}
        // get prediction
        char *ptr = strstr(dataBuffer, "prediction");
        char *token=strstr(dataBuffer, "token");
        char *outside=strstr(dataBuffer, "go_outside");
        if (ptr) {
          ptr = strstr(ptr, ":");
          if (ptr) {
            ptr++;
            int prediction = atoi(ptr);
            printf("prediction: %d\n\r", prediction);
            // set cursor to 0,0
            if (prediction == 1 && location == 0) {
              location = 1;
              fillRect(0, 0, 128, 8, BLACK);
              drawRect(0, 0, 128, 8, BLACK);
              setCursor(0, 0);
              Outstr("Currently inside lab");
            } else if (prediction == 0 && location == 1) {
              location = 0;
              fillRect(0, 0, 128, 8, BLACK);
              drawRect(0, 0, 128, 8, BLACK);
              setCursor(0, 0);
              Outstr("Currently outside lab");
            }
          }
        }
        if(outside){
          outside=strstr(outside, ":");
          if(outside){
            outside++;
            int outside_val = atoi(outside);
            printf("outside: %d\n\r", outside_val);
            if (outside_val == 1) {
              fillRect(0, 60, 128, 8, BLACK);
              drawRect(0, 60, 128, 8, BLACK);
              setCursor(0, 60);
              Outstr("Go outside!");
            } else {
              fillRect(0, 60, 128, 8, BLACK);
              drawRect(0, 60, 128, 8, BLACK);
            }
          }
        }
        if (token) {
          token = strstr(token, ":");
          if (token) {
            token++;
            // remove quotes
            token++;
            token[strlen(token)-1] = '\0';
            auth_token=malloc(strlen(token)-2);
            int i=0;
            for (i=0; i<strlen(token)-2; i++) {
              auth_token[i]=token[i];
            }
            auth_token[i]='\0';
            printf("token: %s\n\r", auth_token);
          }
        }
      }
      if (json) {
        /* Parse JSON data */
        lRetVal = ParseJSONData(dataBuffer);
        if (lRetVal < 0) {
          goto end;
        }
      } else {
        /* treating data as a plain text */
      }

    } break;

    case 404:
      printf("File not found. \r\n");
      /* Handle response body as per requirement.
Note:
  Developers are advised to take appopriate action for HTTP
  return status code else flush the response body.
  In this example we are flushing response body in default
  case for all other than 200 HTTP Status code.
       */
    default:
      /* Note:
Need to flush received buffer explicitly as library will not do
for next request.Apllication is responsible for reading all the
data.
       */
      FlushHTTPResponse(httpClient);
      break;
    }
  } else {
    printf("Failed to receive data from server.\r\n");
    goto end;
  }

  lRetVal = 0;

end:
  if (len > sizeof(g_buff) && (dataBuffer != NULL)) {
    free(dataBuffer);
  }
  return lRetVal;
}

static int HTTPPostMethod(HTTPCli_Handle httpClient, char *body) {
  bool moreFlags = 1;
  bool lastFlag = 1;
  char tmpBuf[4];
  long lRetVal = 0;

  HTTPCli_Field fields[4] = {
      {HTTPCli_FIELD_NAME_HOST, HOST_NAME},
      {HTTPCli_FIELD_NAME_ACCEPT, "*/*"},
      {HTTPCli_FIELD_NAME_CONTENT_TYPE, "application/json"},
      {NULL, NULL}};

  /* Set request header fields to be send for HTTP request. */
  HTTPCli_setRequestFields(httpClient, fields);

  /* Send POST method request. */
  /* Here we are setting moreFlags = 1 as there are some more header fields need
     to send other than setted in previous call HTTPCli_setRequestFields() at
     later stage. Please refer HTTP Library API documentaion @ref
     HTTPCli_sendRequest for more information.
  */
  moreFlags = 1;
  lRetVal = HTTPCli_sendRequest(httpClient, HTTPCli_METHOD_POST,
                                POST_REQUEST_URI, moreFlags);
  if (lRetVal < 0) {
    printf("Failed to send HTTP POST request header.\n\r");
    return lRetVal;
  }
  sprintf((char *)tmpBuf, "%d", strlen(body));

  /* Here we are setting lastFlag = 1 as it is last header field.
     Please refer HTTP Library API documentaion @ref HTTPCli_sendField for more
     information.
  */
  lastFlag = 1;
  lRetVal = HTTPCli_sendField(httpClient, HTTPCli_FIELD_NAME_CONTENT_LENGTH,
                              (const char *)tmpBuf, lastFlag);
  if (lRetVal < 0) {
    printf("Failed to send HTTP POST request header.\n\r");
    return lRetVal;
  }

  /* Send POST data/body */
  lRetVal = HTTPCli_sendRequestBody(httpClient, body, strlen(body));
  if (lRetVal < 0) {
    printf("Failed to send HTTP POST request body.\n\r");
    return lRetVal;
  }

  lRetVal = readResponse(httpClient);
  free(body);

  return lRetVal;
}

HTTPCli_Struct httpClient;

void wifiSearch() {

  // enable scan
  int scanInterval = 10;
  int retVal =
      sl_WlanPolicySet(SL_POLICY_SCAN, SL_SCAN_POLICY(1),
                       (unsigned char *)&scanInterval, sizeof(scanInterval));
  if (retVal < 0)
    return retVal;

  delay(100);

  const int WLAN_SCAN_COUNT = 5;
  Sl_WlanNetworkEntry_t found_networks[WLAN_SCAN_COUNT];
  // get list
  int network_count =
      sl_WlanGetNetworkList(0, (unsigned char)WLAN_SCAN_COUNT, found_networks);

  // int eec172 = 0, testwifi = 0, ucdguest = 0, eduroam = 0;
  // int i=0;
  /*   for (i = 0; i < network_count; i++) {
      printf("SSID: %s\n\r", found_networks[i].ssid);
      printf("Security: %d\n\r", found_networks[i].sec_type);
      printf("RSSI: %d\n\r", found_networks[i].rssi);
      if (strcmp(found_networks[i].ssid, "eec172") == 0) {
        eec172 = found_networks[i].rssi;
      } else if (strcmp(found_networks[i].ssid, "testwifi") == 0) {
        testwifi = found_networks[i].rssi;
      } else if (strcmp(found_networks[i].ssid, "ucd-guest") == 0) {
        ucdguest = found_networks[i].rssi;
      }else if (strcmp(found_networks[i].ssid, "eduroam") == 0) {
        eduroam = found_networks[i].rssi;
      }
    } */

  int lRetVal =
      HTTPPostMethod(&httpClient, generateBody(found_networks, network_count));
  if (lRetVal < 0) {
    printf("HTTP Post failed.\n\r");
  }

  // disable scan
  retVal = sl_WlanPolicySet(SL_POLICY_SCAN, SL_SCAN_POLICY(0), 0, 0);
  if (retVal < 0)
    return retVal;
}

static int ConnectToHTTPServer(HTTPCli_Handle httpClient) {
  long lRetVal = -1;
  struct sockaddr_in addr;

#ifdef USE_PROXY
  struct sockaddr_in paddr;
  paddr.sin_family = AF_INET;
  paddr.sin_port = htons(PROXY_PORT);
  paddr.sin_addr.s_addr = sl_Htonl(PROXY_IP);
  HTTPCli_setProxy((struct sockaddr *)&paddr);
#endif

  /* Resolve HOST NAME/IP */
  lRetVal = sl_NetAppDnsGetHostByName((signed char *)HOST_NAME,
                                      strlen((const char *)HOST_NAME),
                                      &g_ulDestinationIP, SL_AF_INET);
  if (lRetVal < 0) {
    ASSERT_ON_ERROR(GET_HOST_IP_FAILED);
  }

  /* Set up the input parameters for HTTP Connection */
  addr.sin_family = AF_INET;
  addr.sin_port = htons(HOST_PORT);
  addr.sin_addr.s_addr = sl_Htonl(g_ulDestinationIP);

  /* Testing HTTPCli open call: handle, address params only */
  HTTPCli_construct(httpClient);
  lRetVal = HTTPCli_connect(httpClient, (struct sockaddr *)&addr, 0, NULL);
  if (lRetVal < 0) {
    printf("Connection to server failed. error(%d)\n\r", lRetVal);
    ASSERT_ON_ERROR(SERVER_CONNECTION_FAILED);
  } else {
    printf("Connection to server created successfully\r\n");
  }

  return 0;
}

static int login(HTTPCli_Handle httpClient) {
  bool moreFlags = 1;
  bool lastFlag = 1;
  char tmpBuf[4];
  long lRetVal = 0;
  char body[] = "{\n}";
  HTTPCli_Field fields[5] = {
      {HTTPCli_FIELD_NAME_HOST, HOST_NAME},
      {HTTPCli_FIELD_NAME_ACCEPT, "*/*"},
      {HTTPCli_FIELD_NAME_CONTENT_TYPE, "application/json"},
      {HTTPCli_FIELD_NAME_AUTHORIZATION, "Basic cGFydGg6cGFzc3dvcmQ="},
      {NULL, NULL}};

  /* Set request header fields to be send for HTTP request. */
  HTTPCli_setRequestFields(httpClient, fields);

  /* Send POST method request. */
  /* Here we are setting moreFlags = 1 as there are some more header fields need
     to send other than setted in previous call HTTPCli_setRequestFields() at
     later stage. Please refer HTTP Library API documentaion @ref
     HTTPCli_sendRequest for more information.
  */
  moreFlags = 1;
  lRetVal = HTTPCli_sendRequest(httpClient, HTTPCli_METHOD_POST,
                                LOGIN_URI, moreFlags);
  if (lRetVal < 0) {
    printf("Failed to send HTTP POST request header.\n\r");
    return lRetVal;
  }
  sprintf((char *)tmpBuf, "%d", strlen(body));

  /* Here we are setting lastFlag = 1 as it is last header field.
     Please refer HTTP Library API documentaion @ref HTTPCli_sendField for more
     information.
  */
  lastFlag = 1;
  lRetVal = HTTPCli_sendField(httpClient, HTTPCli_FIELD_NAME_CONTENT_LENGTH,
                              (const char *)tmpBuf, lastFlag);
  if (lRetVal < 0) {
    printf("Failed to send HTTP POST request header.\n\r");
    return lRetVal;
  }

  /* Send POST data/body */
  lRetVal = HTTPCli_sendRequestBody(httpClient, body, strlen(body));
  if (lRetVal < 0) {
    printf("Failed to send HTTP POST request body.\n\r");
    return lRetVal;
  }
  lRetVal = readResponse(httpClient);

  return lRetVal;
}

//*****************************************************************************
//
//! Main
//!
//! \param  none
//!
//! \return None
//!
//*****************************************************************************
void main() {
  long lRetVal = -1;
  //
  // Initialize board configuration
  //
  BoardInit();

  PinMuxConfig();
  MAP_PRCMPeripheralClkEnable(PRCM_GSPI, PRCM_RUN_MODE_CLK);
  SPIInit();
  InitTerm();
  ClearTerm();
  printf("My terminal works!\n\r");

  // Connect the CC3200 to the local access point
  lRetVal = connectToAccessPoint();

  // Set time so that encryption can be used
  printf("Setting time\n\r");
  lRetVal = set_time();
  if (lRetVal < 0) {
    printf("Unable to set time in the device");
    LOOP_FOREVER();
  }
  printf("Time set in the device\n\r");

  lRetVal = ConnectToHTTPServer(&httpClient);
  if (lRetVal < 0) {
    LOOP_FOREVER();
  }
  printf("Connected to server\n\r");
  // Connect to the website with TLS encryption
  // http_post(lRetVal, "Hello from the CC3200!");
  // sl_Stop(SL_STOP_TIMEOUT);
  login(&httpClient);
  // LOOP_FOREVER();
  while (1) {
    wifiSearch();
  }
}
//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
