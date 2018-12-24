/*
    __ambient4_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__ambient4_driver.h"
#include "__ambient4_hal.c"

/* ------------------------------------------------------------------- MACROS */

const uint8_t _AMBIENT4_CMD_POWER_DOWN = 0x00;
const uint8_t _AMBIENT4_CMD_POWER_ON   = 0x01;
const uint8_t _AMBIENT4_CMD_AUTO_RESOLUTION_MODE = 0x10;
const uint8_t _AMBIENT4_CMD_HIGH_RESOLUTION_MODE = 0x12;
const uint8_t _AMBIENT4_CMD_LOW_RESOLUTION_MODE  = 0x13;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __AMBIENT4_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __AMBIENT4_DRV_SPI__

void ambient4_spiDriverInit(T_AMBIENT4_P gpioObj, T_AMBIENT4_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __AMBIENT4_DRV_I2C__

void ambient4_i2cDriverInit(T_AMBIENT4_P gpioObj, T_AMBIENT4_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __AMBIENT4_DRV_UART__

void ambient4_uartDriverInit(T_AMBIENT4_P gpioObj, T_AMBIENT4_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void ambient4_sendCommand(uint8_t cmd)
{
    uint8_t writeReg[ 2 ];
    
    writeReg[ 0 ] = cmd;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_STOP);
}

uint16_t ambient4_readData()
{
    uint8_t readReg[ 2 ];
    uint16_t readData;
    
    hal_i2cStart();
    hal_i2cRead(_slaveAddress, readReg, 2, END_MODE_STOP);
    
    readData = readReg[ 0 ];
    readData <<= 8;
    readData |= readReg[ 1 ];
    
    readData = readData / 1.2;
    return readData;
}

void ambient4_deviceReset()
{
    hal_gpio_rstSet(0);
    Delay_10ms();
    hal_gpio_rstSet(1);
}

/* -------------------------------------------------------------------------- */
/*
  __ambient4_driver.c

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