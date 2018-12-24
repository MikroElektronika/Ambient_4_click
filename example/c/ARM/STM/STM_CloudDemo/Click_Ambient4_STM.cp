#line 1 "D:/Click_Cloud/Ambient_4_click/example/c/ARM/STM/Cloud_demo/Click_Ambient4_STM.c"
#line 1 "d:/click_cloud/ambient_4_click/example/c/arm/stm/cloud_demo/click_ambient4_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"



 typedef char _Bool;
#line 1 "d:/click_cloud/ambient_4_click/example/c/arm/stm/cloud_demo/click_ambient4_config.h"
#line 1 "d:/click_cloud/ambient_4_click/example/c/arm/stm/cloud_demo/click_ambient4_types.h"
#line 21 "d:/click_cloud/ambient_4_click/example/c/arm/stm/cloud_demo/click_ambient4_config.h"
const uint32_t _AMBIENT4_I2C_CFG[ 1 ] =
{
 100000
};



const uint32_t _AMBIENT4_UART_CFG [ 4 ] =
{
 9600,
 _UART_8_BIT_DATA,
 _UART_NOPARITY,
 _UART_ONE_STOPBIT
};




const uint32_t _CLOUD_TIMER_LIMIT = 5;
const uint16_t _CLOUD_BUF_WARNING = 192;
const uint8_t _CLOUD_POLL_ENABLE = 1;
const uint8_t _CLOUD_CALLBACK_ENABLE = 0;
const uint8_t _CLOUD_BOOTLOADER = 0;


const uint32_t _CLOUD_UART_CFG[ 4 ] =
{
 57600,
 _UART_8_BIT_DATA,
 _UART_NOPARITY,
 _UART_ONE_STOPBIT
};
#line 1 "d:/click_cloud/ambient_4_click/example/c/arm/stm/cloud_demo/click_ambient4_timer.h"
#line 1 "d:/click_cloud/ambient_4_click/example/c/arm/stm/cloud_demo/click_ambient4_types.h"
#line 13 "d:/click_cloud/ambient_4_click/example/c/arm/stm/cloud_demo/click_ambient4_timer.h"
uint16_t taskTime;

static void cloud_configTimer()
{
 RCC_APB1ENR.TIM2EN = 1;
 TIM2_CR1.CEN = 0;
 TIM2_PSC = 1;
 TIM2_ARR = 35999;
 NVIC_IntEnable(IVT_INT_TIM2);
 TIM2_DIER.UIE = 1;
 TIM2_CR1.CEN = 1;
 EnableInterrupts();
}

void Timer_interrupt() iv IVT_INT_TIM2
{
 cloud_tick();
 taskTime++;
 TIM2_SR.UIF = 0;
}
#line 1 "d:/click_cloud/ambient_4_click/library/__ambient4_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 57 "d:/click_cloud/ambient_4_click/library/__ambient4_driver.h"
const uint8_t _AMBIENT4_CMD_POWER_DOWN;
const uint8_t _AMBIENT4_CMD_POWER_ON ;
const uint8_t _AMBIENT4_CMD_AUTO_RESOLUTION_MODE ;
const uint8_t _AMBIENT4_CMD_HIGH_RESOLUTION_MODE ;
const uint8_t _AMBIENT4_CMD_LOW_RESOLUTION_MODE ;
#line 78 "d:/click_cloud/ambient_4_click/library/__ambient4_driver.h"
void ambient4_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 85 "d:/click_cloud/ambient_4_click/library/__ambient4_driver.h"
void ambient4_gpioDriverInit( const uint8_t*  gpioObj);
#line 92 "d:/click_cloud/ambient_4_click/library/__ambient4_driver.h"
void ambient4_sendCommand(uint8_t cmd);
#line 97 "d:/click_cloud/ambient_4_click/library/__ambient4_driver.h"
uint16_t ambient4_readData();
#line 102 "d:/click_cloud/ambient_4_click/library/__ambient4_driver.h"
void ambient4_deviceReset();
#line 39 "D:/Click_Cloud/Ambient_4_click/example/c/ARM/STM/Cloud_demo/Click_Ambient4_STM.c"
static char ambient4_ref[ 30 ] = "AMBIENT4_LX";

static char cloud_networkName [ 20 ] = "Network_Name";
static char cloud_networkPassword [ 20 ] = "Network_Password";
static char cloud_devKey [ 50 ] = "Device_Key";
static char cloud_devPass [ 100 ] = "Device_Password";


static char _ATE [ 5 ] = "ATE1";
static char _AT [ 3 ] = "AT";
static char _AT_CEN [ 9 ] = "AT+CEN=1";
static char _AT_NWCR[ 8 ] = "AT+NWCR";
static char _AT_NWC [ 9 ] = "AT+NWC=1";
static char _AT_BRCR[ 8 ] = "AT+BRCR";
static char _AT_BRC [ 9 ] = "AT+BRC=1";
static char _AT_DSET[ 8 ] = "AT+DSET";
static char _AT_PUB [ 7 ] = "AT+PUB";


void cloud_default_handler( uint8_t *rsp, uint8_t *evArgs )
{
 mikrobus_logWrite( rsp, _LOG_TEXT );
}

void cloud_packCmd(uint8_t *cmd, uint8_t *mid, uint8_t *_end)
{
 char cmd_param[ 10 ] = "=\"";
 char mid_param[ 10 ] = "\",\"";
 char end_param[ 10 ] = "\"";

 uint8_t tmpBuf[ 80 ];
 memset(&tmpBuf[ 0 ], 0, 50);

 strcat ( &tmpBuf[ 0 ], cmd );
 strcat ( &tmpBuf[ 0 ], &cmd_param[0] );
 strcat ( &tmpBuf[ 0 ], mid );
 strcat ( &tmpBuf[ 0 ], &mid_param[0] );
 strcat ( &tmpBuf[ 0 ], _end );
 strcat ( &tmpBuf[ 0 ], &end_param[0] );

 cloud_cmdSingle( &tmpBuf[ 0 ] );
}

void systemInit()
{

 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
 mikrobus_uartInit( _MIKROBUS1, &_CLOUD_UART_CFG[0] );

 mikrobus_logInit( _LOG_USBUART_A, 9600 );


 mikrobus_gpioInit( _MIKROBUS2, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_i2cInit( _MIKROBUS2, &_AMBIENT4_I2C_CFG[0] );

 Delay_ms( 100 );
}

void applicationInit()
{

 cloud_configTimer();


 cloud_uartDriverInit(( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_UART);
 cloud_coreInit( cloud_default_handler, 1500 );
 cloud_modulePower(  1  );


 ambient4_i2cDriverInit( ( const uint8_t* )&_MIKROBUS2_GPIO, ( const uint8_t* )&_MIKROBUS2_I2C, 0x23 );
 ambient4_deviceReset();
 Delay_1sec();
 ambient4_sendCommand(_AMBIENT4_CMD_POWER_DOWN);
 ambient4_sendCommand(_AMBIENT4_CMD_POWER_ON);
 ambient4_sendCommand(_AMBIENT4_CMD_AUTO_RESOLUTION_MODE);


 cloud_cmdSingle( &_ATE[0] );
 cloud_cmdSingle( &_AT[0] );
 cloud_cmdSingle( &_AT_CEN[0] );
 cloud_packCmd ( &_AT_NWCR[0], &cloud_networkName[0], &cloud_networkPassword[0]);
 cloud_cmdSingle( &_AT_NWC[0] );
 cloud_packCmd ( &_AT_BRCR[0], &cloud_devKey[0], &cloud_devPass[0]);
 cloud_cmdSingle( &_AT_BRC[0] );
 Delay_ms(3000);

 taskTime = 0;
}

void applicationTask()
{
 char demoBuffer[ 50 ];
 uint16_t ambientValue;

 cloud_process();


 if( taskTime > 1500 )
 {
 taskTime = 0;

 ambientValue = ambient4_readData();
 WordToStr(ambientValue, demoBuffer);
 Ltrim(demoBuffer);
 cloud_packCmd( &_AT_DSET[0], &ambient4_ref[0], &demoBuffer[0]);
 cloud_cmdSingle( &_AT_PUB[0] );
 }
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
