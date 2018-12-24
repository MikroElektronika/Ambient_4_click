/*
    __ambient4_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __ambient4_driver.h
@brief    Ambient4 Driver
@mainpage Ambient4 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   AMBIENT4
@brief      Ambient4 Click Driver
@{

| Global Library Prefix | **AMBIENT4** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **sep 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _AMBIENT4_H_
#define _AMBIENT4_H_

/** 
 * @macro T_AMBIENT4_P
 * @brief Driver Abstract type 
 */
#define T_AMBIENT4_P    const uint8_t*

/** @defgroup AMBIENT4_COMPILE Compilation Config */              /** @{ */

//  #define   __AMBIENT4_DRV_SPI__                            /**<     @macro __AMBIENT4_DRV_SPI__  @brief SPI driver selector */
   #define   __AMBIENT4_DRV_I2C__                            /**<     @macro __AMBIENT4_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __AMBIENT4_DRV_UART__                           /**<     @macro __AMBIENT4_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup AMBIENT4_VAR Variables */                           /** @{ */

const uint8_t _AMBIENT4_CMD_POWER_DOWN;
const uint8_t _AMBIENT4_CMD_POWER_ON  ;
const uint8_t _AMBIENT4_CMD_AUTO_RESOLUTION_MODE ;
const uint8_t _AMBIENT4_CMD_HIGH_RESOLUTION_MODE ;
const uint8_t _AMBIENT4_CMD_LOW_RESOLUTION_MODE  ;
                                                                       /** @} */
/** @defgroup AMBIENT4_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup AMBIENT4_INIT Driver Initialization */              /** @{ */

#ifdef   __AMBIENT4_DRV_SPI__
void ambient4_spiDriverInit(T_AMBIENT4_P gpioObj, T_AMBIENT4_P spiObj);
#endif
#ifdef   __AMBIENT4_DRV_I2C__
void ambient4_i2cDriverInit(T_AMBIENT4_P gpioObj, T_AMBIENT4_P i2cObj, uint8_t slave);
#endif
#ifdef   __AMBIENT4_DRV_UART__
void ambient4_uartDriverInit(T_AMBIENT4_P gpioObj, T_AMBIENT4_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void ambient4_gpioDriverInit(T_AMBIENT4_P gpioObj);
                                                                       /** @} */
/** @defgroup AMBIENT4_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function for send command
 */
void ambient4_sendCommand(uint8_t cmd);

/**
 * @brief Function for read 16bit data
 */
uint16_t ambient4_readData();

/**
 * @brief Function for device reset
 */
void ambient4_deviceReset();
                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Ambient4_STM.c
    @example Click_Ambient4_TIVA.c
    @example Click_Ambient4_CEC.c
    @example Click_Ambient4_KINETIS.c
    @example Click_Ambient4_MSP.c
    @example Click_Ambient4_PIC.c
    @example Click_Ambient4_PIC32.c
    @example Click_Ambient4_DSPIC.c
    @example Click_Ambient4_AVR.c
    @example Click_Ambient4_FT90x.c
    @example Click_Ambient4_STM.mbas
    @example Click_Ambient4_TIVA.mbas
    @example Click_Ambient4_CEC.mbas
    @example Click_Ambient4_KINETIS.mbas
    @example Click_Ambient4_MSP.mbas
    @example Click_Ambient4_PIC.mbas
    @example Click_Ambient4_PIC32.mbas
    @example Click_Ambient4_DSPIC.mbas
    @example Click_Ambient4_AVR.mbas
    @example Click_Ambient4_FT90x.mbas
    @example Click_Ambient4_STM.mpas
    @example Click_Ambient4_TIVA.mpas
    @example Click_Ambient4_CEC.mpas
    @example Click_Ambient4_KINETIS.mpas
    @example Click_Ambient4_MSP.mpas
    @example Click_Ambient4_PIC.mpas
    @example Click_Ambient4_PIC32.mpas
    @example Click_Ambient4_DSPIC.mpas
    @example Click_Ambient4_AVR.mpas
    @example Click_Ambient4_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __ambient4_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */