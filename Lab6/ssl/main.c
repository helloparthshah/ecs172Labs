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
// Simplelink includes
#include "simplelink.h" 

//Driverlib includes
#include "hw_types.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "interrupt.h"
#include "hw_apps_rcm.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"
#include "gpio.h"
#include "utils.h"
#include "timer.h"
#include "uart.h"
#include "spi.h"

//Common interface includes
#include "pinmux.h"
#include "gpio_if.h"
#include "common.h"
#include "uart_if.h"
#include "timer_if.h"

#include "Adafruit_GFX.h"
#include "Adafruit_SSD1351.h"
#include "glcdfont.h"
#include "test.h"

#define MAX_URI_SIZE 128
#define URI_SIZE MAX_URI_SIZE + 1
#define CONSOLE UARTA0_BASE
#define UartGetChar() MAP_UARTCharGet(CONSOLE)
#define UartPutChar(c) MAP_UARTCharPut(CONSOLE, c)
#define SPI_IF_BIT_RATE 100000

#define APPLICATION_NAME        "SSL"
#define APPLICATION_VERSION     "1.1.1.EEC.Spring2022"
// #define SERVER_NAME             "a2g61oh3aerzxp-ats.iot.us-west-1.amazonaws.com"
#define SERVER_NAME             "9728-207-183-239-54.ngrok.io"
#define GOOGLE_DST_PORT         8443

#define SL_SSL_CA_CERT "/cert/rootCA.der" //starfield class2 rootca (from firefox) // <-- this one works
#define SL_SSL_PRIVATE "/cert/private.der"
#define SL_SSL_CLIENT  "/cert/client.der"

volatile int TLS_SOCKET_ID = -1;

//NEED TO UPDATE THIS FOR IT TO WORK!
#define DATE                12    /* Current Date */
#define MONTH               5     /* Month 1-12 */
#define YEAR                2022  /* Current year */
#define HOUR                6    /* Time - hours */
#define MINUTE              00    /* Time - minutes */
#define SECOND              0     /* Time - seconds */

// #define POSTHEADER "POST /things/Parth_CC3200/shadow HTTP/1.1\n\r"
#define POSTHEADER "POST /post HTTP/1.1\n\r"
// #define HOSTHEADER "Host: a2g61oh3aerzxp-ats.iot.us-west-1.amazonaws.com\r\n"
#define HOSTHEADER "Host: 9728-207-183-239-54.ngrok.io\r\n"
#define CHEADER "Connection: Keep-Alive\r\n"
#define CTHEADER "Content-Type: application/json; charset=utf-8\r\n"
#define CLHEADER1 "Content-Length: "
#define CLHEADER2 "\r\n\r\n"

char *generateBody(char *message) {
  char a[] = "{\"state\": {\r\n\"desired\" : {\r\n\"var\" : \"";
  char b[] = "\"\r\n}}}\r\n\r\n";
  char *c =
      malloc(sizeof(char) * (strlen(a) + strlen(b) + strlen(message) + 1));
  strcpy(c, a);
  strcat(c, message);
  strcat(c, b);
  return c;
}

// Application specific status/error codes
typedef enum{
    // Choosing -0x7D0 to avoid overlap w/ host-driver's error codes
    LAN_CONNECTION_FAILED = -0x7D0,
    INTERNET_CONNECTION_FAILED = LAN_CONNECTION_FAILED - 1,
    DEVICE_NOT_IN_STATION_MODE = INTERNET_CONNECTION_FAILED - 1,

    STATUS_CODE_MAX = -0xBB8
}e_AppStatusCodes;

typedef struct
{
   /* time */
   unsigned long tm_sec;
   unsigned long tm_min;
   unsigned long tm_hour;
   /* date */
   unsigned long tm_day;
   unsigned long tm_mon;
   unsigned long tm_year;
   unsigned long tm_week_day; //not required
   unsigned long tm_year_day; //not required
   unsigned long reserved[3];
}SlDateTime;


//*****************************************************************************
//                 GLOBAL VARIABLES -- Start
//*****************************************************************************
volatile unsigned long  g_ulStatus = 0;//SimpleLink Status
unsigned long  g_ulPingPacketsRecv = 0; //Number of Ping Packets received
unsigned long  g_ulGatewayIP = 0; //Network Gateway IP address
unsigned char  g_ucConnectionSSID[SSID_LEN_MAX+1]; //Connection SSID
unsigned char  g_ucConnectionBSSID[BSSID_LEN_MAX]; //Connection BSSID
signed char    *g_Host = SERVER_NAME;
SlDateTime g_time;
#if defined(ccs) || defined(gcc)
extern void (* const g_pfnVectors[])(void);
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
static int http_post(int, char *);

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
    if(!pWlanEvent) {
        return;
    }

    switch(pWlanEvent->Event) {
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
            memcpy(g_ucConnectionSSID,pWlanEvent->EventData.
                   STAandP2PModeWlanConnected.ssid_name,
                   pWlanEvent->EventData.STAandP2PModeWlanConnected.ssid_len);
            memcpy(g_ucConnectionBSSID,
                   pWlanEvent->EventData.STAandP2PModeWlanConnected.bssid,
                   SL_BSSID_LENGTH);

            printf("[WLAN EVENT] STA Connected to the AP: %s , "
                       "BSSID: %x:%x:%x:%x:%x:%x\n\r",
                       g_ucConnectionSSID,g_ucConnectionBSSID[0],
                       g_ucConnectionBSSID[1],g_ucConnectionBSSID[2],
                       g_ucConnectionBSSID[3],g_ucConnectionBSSID[4],
                       g_ucConnectionBSSID[5]);
        }
        break;

        case SL_WLAN_DISCONNECT_EVENT: {
            slWlanConnectAsyncResponse_t*  pEventData = NULL;

            CLR_STATUS_BIT(g_ulStatus, STATUS_BIT_CONNECTION);
            CLR_STATUS_BIT(g_ulStatus, STATUS_BIT_IP_AQUIRED);

            pEventData = &pWlanEvent->EventData.STAandP2PModeDisconnected;

            // If the user has initiated 'Disconnect' request,
            //'reason_code' is SL_USER_INITIATED_DISCONNECTION
            if(SL_USER_INITIATED_DISCONNECTION == pEventData->reason_code) {
                printf("[WLAN EVENT]Device disconnected from the AP: %s,"
                    "BSSID: %x:%x:%x:%x:%x:%x on application's request \n\r",
                           g_ucConnectionSSID,g_ucConnectionBSSID[0],
                           g_ucConnectionBSSID[1],g_ucConnectionBSSID[2],
                           g_ucConnectionBSSID[3],g_ucConnectionBSSID[4],
                           g_ucConnectionBSSID[5]);
            }
            else {
                printf("[WLAN ERROR]Device disconnected from the AP AP: %s, "
                           "BSSID: %x:%x:%x:%x:%x:%x on an ERROR..!! \n\r",
                           g_ucConnectionSSID,g_ucConnectionBSSID[0],
                           g_ucConnectionBSSID[1],g_ucConnectionBSSID[2],
                           g_ucConnectionBSSID[3],g_ucConnectionBSSID[4],
                           g_ucConnectionBSSID[5]);
            }
            memset(g_ucConnectionSSID,0,sizeof(g_ucConnectionSSID));
            memset(g_ucConnectionBSSID,0,sizeof(g_ucConnectionBSSID));
        }
        break;

        default: {
            printf("[WLAN EVENT] Unexpected event [0x%x]\n\r",
                       pWlanEvent->Event);
        }
        break;
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
    if(!pNetAppEvent) {
        return;
    }

    switch(pNetAppEvent->Event) {
        case SL_NETAPP_IPV4_IPACQUIRED_EVENT: {
            SlIpV4AcquiredAsync_t *pEventData = NULL;

            SET_STATUS_BIT(g_ulStatus, STATUS_BIT_IP_AQUIRED);

            //Ip Acquired Event Data
            pEventData = &pNetAppEvent->EventData.ipAcquiredV4;

            //Gateway IP address
            g_ulGatewayIP = pEventData->gateway;

            printf("[NETAPP EVENT] IP Acquired: IP=%d.%d.%d.%d , "
                       "Gateway=%d.%d.%d.%d\n\r",
            SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.ip,3),
            SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.ip,2),
            SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.ip,1),
            SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.ip,0),
            SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.gateway,3),
            SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.gateway,2),
            SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.gateway,1),
            SL_IPV4_BYTE(pNetAppEvent->EventData.ipAcquiredV4.gateway,0));
        }
        break;

        default: {
            printf("[NETAPP EVENT] Unexpected event [0x%x] \n\r",
                       pNetAppEvent->Event);
        }
        break;
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
void SimpleLinkHttpServerCallback(SlHttpServerEvent_t *pHttpEvent, SlHttpServerResponse_t *pHttpResponse) {
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
    if(!pDevEvent) {
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
    if(!pSock) {
        return;
    }

    switch( pSock->Event ) {
        case SL_SOCKET_TX_FAILED_EVENT:
            switch( pSock->socketAsyncEvent.SockTxFailData.status) {
                case SL_ECLOSE: 
                    printf("[SOCK ERROR] - close socket (%d) operation "
                                "failed to transmit all queued packets\n\n", 
                                    pSock->socketAsyncEvent.SockTxFailData.sd);
                    break;
                default: 
                    printf("[SOCK ERROR] - TX FAILED  :  socket %d , reason "
                                "(%d) \n\n",
                                pSock->socketAsyncEvent.SockTxFailData.sd, pSock->socketAsyncEvent.SockTxFailData.status);
                  break;
            }
            break;

        default:
            printf("[SOCK EVENT] - Unexpected Event [%x0x]\n\n",pSock->Event);
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
    memset(g_ucConnectionSSID,0,sizeof(g_ucConnectionSSID));
    memset(g_ucConnectionBSSID,0,sizeof(g_ucConnectionBSSID));
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
    SlVersionFull   ver = {0};
    _WlanRxFilterOperationCommandBuff_t  RxFilterIdMask = {0};

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
            while(!IS_IP_ACQUIRED(g_ulStatus)) {
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
    
    printf("Host Driver Version: %s\n\r",SL_DRIVER_VERSION);
    printf("Build Version %d.%d.%d.%d.31.%d.%d.%d.%d.%d.%d.%d.%d\n\r",
    ver.NwpVersion[0],ver.NwpVersion[1],ver.NwpVersion[2],ver.NwpVersion[3],
    ver.ChipFwAndPhyVersion.FwVersion[0],ver.ChipFwAndPhyVersion.FwVersion[1],
    ver.ChipFwAndPhyVersion.FwVersion[2],ver.ChipFwAndPhyVersion.FwVersion[3],
    ver.ChipFwAndPhyVersion.PhyVersion[0],ver.ChipFwAndPhyVersion.PhyVersion[1],
    ver.ChipFwAndPhyVersion.PhyVersion[2],ver.ChipFwAndPhyVersion.PhyVersion[3]);

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
    if(0 == lRetVal) {
        // Wait
        while(IS_CONNECTED(g_ulStatus)) {
#ifndef SL_PLATFORM_MULTI_THREADED
              _SlNonOsMainLoopTask(); 
#endif
        }
    }

    // Enable DHCP client
    lRetVal = sl_NetCfgSet(SL_IPV4_STA_P2P_CL_DHCP_ENABLE,1,1,&ucVal);
    ASSERT_ON_ERROR(lRetVal);

    // Disable scan
    ucConfigOpt = SL_SCAN_POLICY(0);
    lRetVal = sl_WlanPolicySet(SL_POLICY_SCAN , ucConfigOpt, NULL, 0);
    ASSERT_ON_ERROR(lRetVal);

    // Set Tx power level for station mode
    // Number between 0-15, as dB offset from max power - 0 will set max power
    ucPower = 0;
    lRetVal = sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID, 
            WLAN_GENERAL_PARAM_OPT_STA_TX_POWER, 1, (unsigned char *)&ucPower);
    ASSERT_ON_ERROR(lRetVal);

    // Set PM policy to normal
    lRetVal = sl_WlanPolicySet(SL_POLICY_PM , SL_NORMAL_POLICY, NULL, 0);
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
    while((!IS_CONNECTED(g_ulStatus)) || (!IS_IP_ACQUIRED(g_ulStatus))) {
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




long printErrConvenience(char * msg, long retVal) {
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
                          sizeof(SlDateTime),(unsigned char *)(&g_time));

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
    SlSockAddrIn_t    Addr;
    int    iAddrSize;
    unsigned char    ucMethod = SL_SO_SEC_METHOD_TLSV1_2;
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
// SL_SEC_MASK_TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 // does not work (-340, handshake fails)
    long lRetVal = -1;
    int iSockID;

    lRetVal = sl_NetAppDnsGetHostByName(g_Host, strlen((const char *)g_Host),
                                    (unsigned long*)&uiIP, SL_AF_INET);

    if(lRetVal < 0) {
        return printErrConvenience("Device couldn't retrieve the host name \n\r", lRetVal);
    }

    Addr.sin_family = SL_AF_INET;
    Addr.sin_port = sl_Htons(GOOGLE_DST_PORT);
    Addr.sin_addr.s_addr = sl_Htonl(uiIP);
    iAddrSize = sizeof(SlSockAddrIn_t);
    //
    // opens a secure socket
    //
    iSockID = sl_Socket(SL_AF_INET,SL_SOCK_STREAM, SL_SEC_SOCKET);
    if( iSockID < 0 ) {
        return printErrConvenience("Device unable to create secure socket \n\r", lRetVal);
    }

    //
    // configure the socket as TLS1.2
    //
    lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET, SL_SO_SECMETHOD, &ucMethod,\
                               sizeof(ucMethod));
    if(lRetVal < 0) {
        return printErrConvenience("Device couldn't set socket options \n\r", lRetVal);
    }
    //
    //configure the socket as ECDHE RSA WITH AES256 CBC SHA
    //
    lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET, SL_SO_SECURE_MASK, &uiCipher,\
                           sizeof(uiCipher));
    if(lRetVal < 0) {
        return printErrConvenience("Device couldn't set socket options \n\r", lRetVal);
    }



/////////////////////////////////
// START: COMMENT THIS OUT IF DISABLING SERVER VERIFICATION
    //
    //configure the socket with CA certificate - for server verification
    //
    lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET, \
                           SL_SO_SECURE_FILES_CA_FILE_NAME, \
                           SL_SSL_CA_CERT, \
                           strlen(SL_SSL_CA_CERT));

    if(lRetVal < 0) {
        return printErrConvenience("Device couldn't set socket options \n\r", lRetVal);
    }
// END: COMMENT THIS OUT IF DISABLING SERVER VERIFICATION
/////////////////////////////////


    //configure the socket with Client Certificate - for server verification
    //
    lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET, \
                SL_SO_SECURE_FILES_CERTIFICATE_FILE_NAME, \
                                    SL_SSL_CLIENT, \
                           strlen(SL_SSL_CLIENT));

    if(lRetVal < 0) {
        return printErrConvenience("Device couldn't set socket options \n\r", lRetVal);
    }

    //configure the socket with Private Key - for server verification
    //
    lRetVal = sl_SetSockOpt(iSockID, SL_SOL_SOCKET, \
            SL_SO_SECURE_FILES_PRIVATE_KEY_FILE_NAME, \
            SL_SSL_PRIVATE, \
                           strlen(SL_SSL_PRIVATE));

    if(lRetVal < 0) {
        return printErrConvenience("Device couldn't set socket options \n\r", lRetVal);
    }


    /* connect to the peer device - Google server */
    lRetVal = sl_Connect(iSockID, ( SlSockAddr_t *)&Addr, iAddrSize);

    printf("Device is connecting to secure server %d\n\r", lRetVal);

    if(lRetVal >= 0) {
        printf("Device has connected to the website:");
        printf(SERVER_NAME);
        printf("\n\r");
    }
    else if(lRetVal == SL_ESECSNOVERIFY) {
        printf("Device has connected to the website (UNVERIFIED):");
        printf(SERVER_NAME);
        printf("\n\r");
    }
    else if(lRetVal < 0) {
        printf("Device couldn't connect to server:");
        printf(SERVER_NAME);
        printf("\n\r");
        return printErrConvenience("Device couldn't connect to server \n\r", lRetVal);
    }

    GPIO_IF_LedOff(MCU_RED_LED_GPIO);
    GPIO_IF_LedOn(MCU_GREEN_LED_GPIO);
    return iSockID;
}

static int tls_connect_flask() {
  SlSockAddrIn_t sLocalAddr;

  // filling the TCP server socket address
  sLocalAddr.sin_family = SL_AF_INET;
  sLocalAddr.sin_port = sl_Htons(GOOGLE_DST_PORT);
  sLocalAddr.sin_addr.s_addr = 0;

  // Create a TCP socket
  int socketId = sl_Socket(SL_AF_INET, SL_SOCK_STREAM, 0);
  if( socketId < 0 ){
    // error
    ASSERT_ON_ERROR(SOCKET_CREATE_ERROR);
  }

  // Bind the TCP socket to the TCP server address
  int iStatus = sl_Bind(socketId, (SlSockAddr_t*)&sLocalAddr, sizeof(SlSockAddrIn_t));
  if (iStatus < 0){
    sl_Close(socketId);
    ASSERT_ON_ERROR(BIND_ERROR);
  }

  // Put the socket for listening to the incoming TCP connection
  iStatus = sl_Listen(socketId, 0);
  if (iStatus < 0){
    sl_Close(socketId);
    ASSERT_ON_ERROR(LISTEN_ERROR);
  }

  // Make the socket non-blocking
  long lNonBlocking = 1;
  iStatus = sl_SetSockOpt(socketId, SL_SOL_SOCKET, SL_SO_NONBLOCKING,
                          &lNonBlocking, sizeof(lNonBlocking));
  if (iStatus < 0){
    sl_Close(socketId);
    ASSERT_ON_ERROR(SOCKET_OPT_ERROR);
  }
  return socketId;
}


int connectToAccessPoint() {
    long lRetVal = -1;
    GPIO_IF_LedConfigure(LED1|LED3);

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
    if(lRetVal < 0) {
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
    //Connecting to WLAN AP
    //
    lRetVal = WlanConnect();
    if(lRetVal < 0) {
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
  printf("Display: %c\n\r", digits[state][c_letter]);
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
    cx=0;
    cy=0;
    nLetters = 0;
    drawChar(cx, cy, '_', WHITE, BLACK, 1);
    http_post(TLS_SOCKET_ID, str);
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
    cx+=6;
    if (cx >= 128) {
      cx = 0;
      cy+=8;
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
  drawChar(cx, cy, '_', colors[curr_color], BLACK, 1);
}

int GetWifiNetworks() {
  unsigned char ucpolicyOpt;
  union {
    unsigned char ucPolicy[4];
    unsigned int uiPolicyLen;
  } policyVal;

  //
  // make sure the connection policy is not set (so no scan is run in the
  // background)
  //
  ucpolicyOpt = SL_CONNECTION_POLICY(0, 0, 0, 0, 0);
  int iRet = sl_WlanPolicySet(SL_POLICY_CONNECTION, ucpolicyOpt, NULL, 0);
  if (iRet != 0) {
    sl_WlanPolicySet(SL_POLICY_CONNECTION, SL_CONNECTION_POLICY(1, 1, 0, 0, 0),
                     0, 0);
    return 0;
  }

  policyVal.uiPolicyLen = 10;
  iRet = sl_WlanPolicySet(SL_POLICY_SCAN, SL_SCAN_POLICY(1),
                          (unsigned char *)(policyVal.ucPolicy),
                          sizeof(policyVal));
  if (iRet != 0) {
    sl_WlanPolicySet(SL_POLICY_CONNECTION, SL_CONNECTION_POLICY(1, 1, 0, 0, 0),
                     0, 0);
    return 0;
  }
  delay(300);
  // const _u8 Index,const _u8 Count, Sl_WlanNetworkEntry_t *pEntries
  const int WLAN_SCAN_COUNT = 20;
  Sl_WlanNetworkEntry_t found_networks[WLAN_SCAN_COUNT];
  int network_count =
      sl_WlanGetNetworkList(0, (unsigned char)WLAN_SCAN_COUNT, found_networks);

  int i = 0;
  for (i = 0; i < network_count; i++) {
    printf("SSID: %s\n\r", found_networks[i].ssid);
    printf("SSID: %s\n\r", found_networks[i].ssid);
    printf("Security: %d\n\r", found_networks[i].sec_type);
    printf("Security: %d\n\r", found_networks[i].sec_type);
    printf("RSSI: %d\n\r", found_networks[i].rssi);
    printf("RSSI: %d\n\r", found_networks[i].rssi);
  }
  //
  // disable scan
  //
  ucpolicyOpt = SL_SCAN_POLICY(0);
  sl_WlanPolicySet(SL_POLICY_SCAN, ucpolicyOpt, NULL, 0);
  sl_WlanPolicySet(SL_POLICY_CONNECTION, SL_CONNECTION_POLICY(1, 1, 0, 0, 0), 0,
                   0);
  return network_count;
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

  InitTerm();
  ClearTerm();
  printf("My terminal works!\n\r");

  SPIInit();
  GPIOInit();
  TimerInit();

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
  // Connect to the website with TLS encryption
  // lRetVal = tls_connect();
  lRetVal = tls_connect_flask();
  if (lRetVal < 0) {
    ERR_PRINT(lRetVal);
  }
  TLS_SOCKET_ID = lRetVal;
  // http_post(lRetVal, "Hello from the CC3200!");
  // sl_Stop(SL_STOP_TIMEOUT);
  while(1){
    // GetWifiNetworks();
    http_post_test(TLS_SOCKET_ID, "Hello from the CC3200!");
  }
  // LOOP_FOREVER();
}
//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

static int http_post_test(int iTLSSockID, char *message) {
  char *body = generateBody(message);
  char acSendBuff[512];
  char acRecvbuff[1460];
  char cCLLength[200];
  char *pcBufHeaders;
  int lRetVal = 0;

  pcBufHeaders = acSendBuff;
  strcpy(pcBufHeaders, POSTHEADER);
  pcBufHeaders += strlen(POSTHEADER);
  strcpy(pcBufHeaders, HOSTHEADER);
  pcBufHeaders += strlen(HOSTHEADER);
  strcpy(pcBufHeaders, CHEADER);
  pcBufHeaders += strlen(CHEADER);
  strcpy(pcBufHeaders, "\r\n\r\n");

  int dataLength = strlen(body);

  strcpy(pcBufHeaders, CTHEADER);
  pcBufHeaders += strlen(CTHEADER);
  strcpy(pcBufHeaders, CLHEADER1);

  pcBufHeaders += strlen(CLHEADER1);
  sprintf(cCLLength, "%d", dataLength);

  strcpy(pcBufHeaders, cCLLength);
  pcBufHeaders += strlen(cCLLength);
  strcpy(pcBufHeaders, CLHEADER2);
  pcBufHeaders += strlen(CLHEADER2);

  strcpy(pcBufHeaders, body);
  pcBufHeaders += strlen(body);

  int testDataLength = strlen(pcBufHeaders);

  printf(acSendBuff);

  //
  // Send the packet to the server */
  //
  lRetVal = sl_Send(iTLSSockID, acSendBuff, strlen(acSendBuff), 0);
  if (lRetVal < 0) {
    printf("POST failed. Error Number: %i\n\r", lRetVal);
    sl_Close(iTLSSockID);
    GPIO_IF_LedOn(MCU_RED_LED_GPIO);
    return lRetVal;
  }
  lRetVal = sl_Recv(iTLSSockID, &acRecvbuff[0], sizeof(acRecvbuff), 0);
  if (lRetVal < 0) {
    printf("Received failed. Error Number: %i\n\r", lRetVal);
    // sl_Close(iSSLSockID);
    GPIO_IF_LedOn(MCU_RED_LED_GPIO);
    return lRetVal;
  } else {
    acRecvbuff[lRetVal + 1] = '\0';
    printf(acRecvbuff);
    printf("\n\r\n\r");
  }

  return 0;
}

static int http_post(int iTLSSockID, char *message) {
  char *body = generateBody(message);
  char acSendBuff[512];
  char acRecvbuff[1460];
  char cCLLength[200];
  char *pcBufHeaders;
  int lRetVal = 0;

  pcBufHeaders = acSendBuff;
  strcpy(pcBufHeaders, POSTHEADER);
  pcBufHeaders += strlen(POSTHEADER);
  strcpy(pcBufHeaders, HOSTHEADER);
  pcBufHeaders += strlen(HOSTHEADER);
  strcpy(pcBufHeaders, CHEADER);
  pcBufHeaders += strlen(CHEADER);
  strcpy(pcBufHeaders, "\r\n\r\n");

  int dataLength = strlen(body);

  strcpy(pcBufHeaders, CTHEADER);
  pcBufHeaders += strlen(CTHEADER);
  strcpy(pcBufHeaders, CLHEADER1);

  pcBufHeaders += strlen(CLHEADER1);
  sprintf(cCLLength, "%d", dataLength);

  strcpy(pcBufHeaders, cCLLength);
  pcBufHeaders += strlen(cCLLength);
  strcpy(pcBufHeaders, CLHEADER2);
  pcBufHeaders += strlen(CLHEADER2);

  strcpy(pcBufHeaders, body);
  pcBufHeaders += strlen(body);

  int testDataLength = strlen(pcBufHeaders);

  printf(acSendBuff);

  //
  // Send the packet to the server */
  //
  lRetVal = sl_Send(iTLSSockID, acSendBuff, strlen(acSendBuff), 0);
  if (lRetVal < 0) {
    printf("POST failed. Error Number: %i\n\r", lRetVal);
    sl_Close(iTLSSockID);
    GPIO_IF_LedOn(MCU_RED_LED_GPIO);
    return lRetVal;
  }
  lRetVal = sl_Recv(iTLSSockID, &acRecvbuff[0], sizeof(acRecvbuff), 0);
  if (lRetVal < 0) {
    printf("Received failed. Error Number: %i\n\r", lRetVal);
    // sl_Close(iSSLSockID);
    GPIO_IF_LedOn(MCU_RED_LED_GPIO);
    return lRetVal;
  } else {
    acRecvbuff[lRetVal + 1] = '\0';
    printf(acRecvbuff);
    printf("\n\r\n\r");
  }

  return 0;
}
