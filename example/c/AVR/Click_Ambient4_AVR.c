/*
Example for Ambient4 Click

    Date          : sep 2018.
    Author        : Katarina Perendic

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

---
The application is composed of three sections :

- System Initialization - Initializes I2C module and set RST pin as OUTPUT
- Application Initialization - Initialization driver init and power ON chip and set resolution mode
- Application Task - (code snippet) - Read ambient light in [lx] and logs data to USBUART every 1 sec.

*/

#include "Click_Ambient4_types.h"
#include "Click_Ambient4_config.h"

uint16_t readValue;
char demoText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_AMBIENT4_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART, 115200 );
    mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    ambient4_i2cDriverInit( (T_AMBIENT4_P)&_MIKROBUS1_GPIO, (T_AMBIENT4_P)&_MIKROBUS1_I2C, 0x23 );
    ambient4_deviceReset();
    Delay_1sec();
    ambient4_sendCommand(_AMBIENT4_CMD_POWER_DOWN);
    ambient4_sendCommand(_AMBIENT4_CMD_POWER_ON);
    ambient4_sendCommand(_AMBIENT4_CMD_AUTO_RESOLUTION_MODE);
    mikrobus_logWrite(" --- Start measurement --- ", _LOG_LINE);
}

void applicationTask()
{
    readValue = ambient4_readData();
    IntToStr(readValue, demoText);
    mikrobus_logWrite(" Ambient light: ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" lx ", _LOG_LINE);
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}