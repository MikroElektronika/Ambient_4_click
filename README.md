![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Ambient4 Click

- **CIC Prefix**  : AMBIENT4
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : sep 2018.

---

### Software Support

We provide a library for the Ambient4 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2582/ambient-4-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library contains all the necessary functions for working with Ambient 4 click.

Key functions :

- ``` void ambient4_sendCommand(uint8_t cmd) ``` - Function for send command
- ``` uint16_t ambient4_readData() ``` - Function for read 16bit data
- ``` void ambient4_deviceReset() ``` - Function for device reset

**Examples Description**


The application is composed of three sections :

- System Initialization - Initializes I2C module and set RST pin as OUTPUT
- Application Initialization - Initialization driver init and power ON chip and set resolution mode
- Application Task - (code snippet) - Read ambient light in [lx] and logs data to USBUART every 1 sec.


```.c
void applicationTask()
{
    readValue = ambient4_readData();
    IntToStr(readValue, demoText);
    mikrobus_logWrite(" Ambient light: ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" lx ", _LOG_LINE);
    Delay_1sec();
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2582/ambient-4-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
