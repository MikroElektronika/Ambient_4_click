Click_Ambient4_STM_cloud_configTimer:
;click_ambient4_timer.h,15 :: 		static void cloud_configTimer()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;click_ambient4_timer.h,17 :: 		RCC_APB1ENR.TIM2EN = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(RCC_APB1ENR+0)
MOVT	R0, #hi_addr(RCC_APB1ENR+0)
_SX	[R0, ByteOffset(RCC_APB1ENR+0)]
;click_ambient4_timer.h,18 :: 		TIM2_CR1.CEN = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_CR1+0)
MOVT	R0, #hi_addr(TIM2_CR1+0)
_SX	[R0, ByteOffset(TIM2_CR1+0)]
;click_ambient4_timer.h,19 :: 		TIM2_PSC = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(TIM2_PSC+0)
MOVT	R0, #hi_addr(TIM2_PSC+0)
STR	R1, [R0, #0]
;click_ambient4_timer.h,20 :: 		TIM2_ARR = 35999;
MOVW	R1, #35999
MOVW	R0, #lo_addr(TIM2_ARR+0)
MOVT	R0, #hi_addr(TIM2_ARR+0)
STR	R1, [R0, #0]
;click_ambient4_timer.h,21 :: 		NVIC_IntEnable(IVT_INT_TIM2);
MOVW	R0, #44
BL	_NVIC_IntEnable+0
;click_ambient4_timer.h,22 :: 		TIM2_DIER.UIE = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_DIER+0)
MOVT	R0, #hi_addr(TIM2_DIER+0)
_SX	[R0, ByteOffset(TIM2_DIER+0)]
;click_ambient4_timer.h,23 :: 		TIM2_CR1.CEN = 1;
MOVW	R0, #lo_addr(TIM2_CR1+0)
MOVT	R0, #hi_addr(TIM2_CR1+0)
_SX	[R0, ByteOffset(TIM2_CR1+0)]
;click_ambient4_timer.h,24 :: 		EnableInterrupts();
BL	_EnableInterrupts+0
;click_ambient4_timer.h,25 :: 		}
L_end_cloud_configTimer:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of Click_Ambient4_STM_cloud_configTimer
_Timer_interrupt:
;click_ambient4_timer.h,27 :: 		void Timer_interrupt() iv IVT_INT_TIM2
SUB	SP, SP, #4
STR	LR, [SP, #0]
;click_ambient4_timer.h,29 :: 		cloud_tick();
BL	_cloud_tick+0
;click_ambient4_timer.h,30 :: 		taskTime++;
MOVW	R1, #lo_addr(_taskTime+0)
MOVT	R1, #hi_addr(_taskTime+0)
LDRH	R0, [R1, #0]
ADDS	R0, R0, #1
STRH	R0, [R1, #0]
;click_ambient4_timer.h,31 :: 		TIM2_SR.UIF = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_SR+0)
MOVT	R0, #hi_addr(TIM2_SR+0)
_SX	[R0, ByteOffset(TIM2_SR+0)]
;click_ambient4_timer.h,32 :: 		}
L_end_Timer_interrupt:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Timer_interrupt
_cloud_default_handler:
;Click_Ambient4_STM.c,58 :: 		void cloud_default_handler( uint8_t *rsp, uint8_t *evArgs )
; rsp start address is: 0 (R0)
SUB	SP, SP, #4
STR	LR, [SP, #0]
; rsp end address is: 0 (R0)
; rsp start address is: 0 (R0)
;Click_Ambient4_STM.c,60 :: 		mikrobus_logWrite( rsp, _LOG_TEXT );
MOVS	R1, #1
; rsp end address is: 0 (R0)
BL	_mikrobus_logWrite+0
;Click_Ambient4_STM.c,61 :: 		}
L_end_cloud_default_handler:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _cloud_default_handler
_cloud_packCmd:
;Click_Ambient4_STM.c,63 :: 		void cloud_packCmd(uint8_t *cmd, uint8_t *mid, uint8_t *_end)
; _end start address is: 8 (R2)
; mid start address is: 4 (R1)
; cmd start address is: 0 (R0)
SUB	SP, SP, #116
STR	LR, [SP, #0]
MOV	R8, R0
MOV	R6, R1
MOV	R7, R2
; _end end address is: 8 (R2)
; mid end address is: 4 (R1)
; cmd end address is: 0 (R0)
; cmd start address is: 32 (R8)
; mid start address is: 24 (R6)
; _end start address is: 28 (R7)
;Click_Ambient4_STM.c,65 :: 		char cmd_param[ 10 ] = "=\"";
ADD	R11, SP, #84
ADD	R10, R11, #30
MOVW	R12, #lo_addr(?ICScloud_packCmd_cmd_param_L0+0)
MOVT	R12, #hi_addr(?ICScloud_packCmd_cmd_param_L0+0)
BL	___CC2DW+0
;Click_Ambient4_STM.c,66 :: 		char mid_param[ 10 ] = "\",\"";
;Click_Ambient4_STM.c,67 :: 		char end_param[ 10 ] = "\"";
;Click_Ambient4_STM.c,70 :: 		memset(&tmpBuf[ 0 ], 0, 50);
ADD	R3, SP, #4
MOVS	R2, #50
SXTH	R2, R2
MOVS	R1, #0
MOV	R0, R3
BL	_memset+0
;Click_Ambient4_STM.c,72 :: 		strcat ( &tmpBuf[ 0 ], cmd );
ADD	R3, SP, #4
MOV	R1, R8
; cmd end address is: 32 (R8)
MOV	R0, R3
BL	_strcat+0
;Click_Ambient4_STM.c,73 :: 		strcat ( &tmpBuf[ 0 ], &cmd_param[0] );
ADD	R4, SP, #84
ADD	R3, SP, #4
MOV	R1, R4
MOV	R0, R3
BL	_strcat+0
;Click_Ambient4_STM.c,74 :: 		strcat ( &tmpBuf[ 0 ], mid );
ADD	R3, SP, #4
MOV	R1, R6
; mid end address is: 24 (R6)
MOV	R0, R3
BL	_strcat+0
;Click_Ambient4_STM.c,75 :: 		strcat ( &tmpBuf[ 0 ], &mid_param[0] );
ADD	R4, SP, #94
ADD	R3, SP, #4
MOV	R1, R4
MOV	R0, R3
BL	_strcat+0
;Click_Ambient4_STM.c,76 :: 		strcat ( &tmpBuf[ 0 ], _end );
ADD	R3, SP, #4
MOV	R1, R7
; _end end address is: 28 (R7)
MOV	R0, R3
BL	_strcat+0
;Click_Ambient4_STM.c,77 :: 		strcat ( &tmpBuf[ 0 ], &end_param[0] );
ADD	R4, SP, #104
ADD	R3, SP, #4
MOV	R1, R4
MOV	R0, R3
BL	_strcat+0
;Click_Ambient4_STM.c,79 :: 		cloud_cmdSingle( &tmpBuf[ 0 ] );
ADD	R3, SP, #4
MOV	R0, R3
BL	_cloud_cmdSingle+0
;Click_Ambient4_STM.c,80 :: 		}
L_end_cloud_packCmd:
LDR	LR, [SP, #0]
ADD	SP, SP, #116
BX	LR
; end of _cloud_packCmd
_systemInit:
;Click_Ambient4_STM.c,82 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Ambient4_STM.c,85 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Ambient4_STM.c,86 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Ambient4_STM.c,87 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Ambient4_STM.c,88 :: 		mikrobus_uartInit( _MIKROBUS1, &_CLOUD_UART_CFG[0] );
MOVW	R0, #lo_addr(__CLOUD_UART_CFG+0)
MOVT	R0, #hi_addr(__CLOUD_UART_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_uartInit+0
;Click_Ambient4_STM.c,90 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Ambient4_STM.c,93 :: 		mikrobus_gpioInit( _MIKROBUS2, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #1
BL	_mikrobus_gpioInit+0
;Click_Ambient4_STM.c,94 :: 		mikrobus_i2cInit( _MIKROBUS2, &_AMBIENT4_I2C_CFG[0] );
MOVW	R0, #lo_addr(__AMBIENT4_I2C_CFG+0)
MOVT	R0, #hi_addr(__AMBIENT4_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #1
BL	_mikrobus_i2cInit+0
;Click_Ambient4_STM.c,96 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Ambient4_STM.c,97 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Ambient4_STM.c,99 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Ambient4_STM.c,102 :: 		cloud_configTimer();
BL	Click_Ambient4_STM_cloud_configTimer+0
;Click_Ambient4_STM.c,105 :: 		cloud_uartDriverInit((T_CLOUD_P)&_MIKROBUS1_GPIO, (T_CLOUD_P)&_MIKROBUS1_UART);
MOVW	R1, #lo_addr(__MIKROBUS1_UART+0)
MOVT	R1, #hi_addr(__MIKROBUS1_UART+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_cloud_uartDriverInit+0
;Click_Ambient4_STM.c,106 :: 		cloud_coreInit( cloud_default_handler, 1500 );
MOVW	R0, #lo_addr(_cloud_default_handler+0)
MOVT	R0, #hi_addr(_cloud_default_handler+0)
MOVW	R1, #1500
BL	_cloud_coreInit+0
;Click_Ambient4_STM.c,107 :: 		cloud_modulePower( true );
MOVS	R0, #1
BL	_cloud_modulePower+0
;Click_Ambient4_STM.c,110 :: 		ambient4_i2cDriverInit( (T_AMBIENT4_P)&_MIKROBUS2_GPIO, (T_AMBIENT4_P)&_MIKROBUS2_I2C, 0x23 );
MOVS	R2, #35
MOVW	R1, #lo_addr(__MIKROBUS2_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS2_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS2_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS2_GPIO+0)
BL	_ambient4_i2cDriverInit+0
;Click_Ambient4_STM.c,111 :: 		ambient4_deviceReset();
BL	_ambient4_deviceReset+0
;Click_Ambient4_STM.c,112 :: 		Delay_1sec();
BL	_Delay_1sec+0
;Click_Ambient4_STM.c,113 :: 		ambient4_sendCommand(_AMBIENT4_CMD_POWER_DOWN);
MOVS	R0, __AMBIENT4_CMD_POWER_DOWN
BL	_ambient4_sendCommand+0
;Click_Ambient4_STM.c,114 :: 		ambient4_sendCommand(_AMBIENT4_CMD_POWER_ON);
MOVS	R0, __AMBIENT4_CMD_POWER_ON
BL	_ambient4_sendCommand+0
;Click_Ambient4_STM.c,115 :: 		ambient4_sendCommand(_AMBIENT4_CMD_AUTO_RESOLUTION_MODE);
MOVS	R0, __AMBIENT4_CMD_AUTO_RESOLUTION_MODE
BL	_ambient4_sendCommand+0
;Click_Ambient4_STM.c,118 :: 		cloud_cmdSingle( &_ATE[0] );
MOVW	R0, #lo_addr(Click_Ambient4_STM__ATE+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__ATE+0)
BL	_cloud_cmdSingle+0
;Click_Ambient4_STM.c,119 :: 		cloud_cmdSingle( &_AT[0] );
MOVW	R0, #lo_addr(Click_Ambient4_STM__AT+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__AT+0)
BL	_cloud_cmdSingle+0
;Click_Ambient4_STM.c,120 :: 		cloud_cmdSingle( &_AT_CEN[0] );
MOVW	R0, #lo_addr(Click_Ambient4_STM__AT_CEN+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__AT_CEN+0)
BL	_cloud_cmdSingle+0
;Click_Ambient4_STM.c,121 :: 		cloud_packCmd  ( &_AT_NWCR[0], &cloud_networkName[0], &cloud_networkPassword[0]);
MOVW	R2, #lo_addr(Click_Ambient4_STM_cloud_networkPassword+0)
MOVT	R2, #hi_addr(Click_Ambient4_STM_cloud_networkPassword+0)
MOVW	R1, #lo_addr(Click_Ambient4_STM_cloud_networkName+0)
MOVT	R1, #hi_addr(Click_Ambient4_STM_cloud_networkName+0)
MOVW	R0, #lo_addr(Click_Ambient4_STM__AT_NWCR+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__AT_NWCR+0)
BL	_cloud_packCmd+0
;Click_Ambient4_STM.c,122 :: 		cloud_cmdSingle( &_AT_NWC[0] );
MOVW	R0, #lo_addr(Click_Ambient4_STM__AT_NWC+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__AT_NWC+0)
BL	_cloud_cmdSingle+0
;Click_Ambient4_STM.c,123 :: 		cloud_packCmd  ( &_AT_BRCR[0], &cloud_devKey[0], &cloud_devPass[0]);
MOVW	R2, #lo_addr(Click_Ambient4_STM_cloud_devPass+0)
MOVT	R2, #hi_addr(Click_Ambient4_STM_cloud_devPass+0)
MOVW	R1, #lo_addr(Click_Ambient4_STM_cloud_devKey+0)
MOVT	R1, #hi_addr(Click_Ambient4_STM_cloud_devKey+0)
MOVW	R0, #lo_addr(Click_Ambient4_STM__AT_BRCR+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__AT_BRCR+0)
BL	_cloud_packCmd+0
;Click_Ambient4_STM.c,124 :: 		cloud_cmdSingle( &_AT_BRC[0] );
MOVW	R0, #lo_addr(Click_Ambient4_STM__AT_BRC+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__AT_BRC+0)
BL	_cloud_cmdSingle+0
;Click_Ambient4_STM.c,125 :: 		Delay_ms(3000);
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationInit2:
SUBS	R7, R7, #1
BNE	L_applicationInit2
NOP
NOP
NOP
;Click_Ambient4_STM.c,127 :: 		taskTime = 0;
MOVS	R1, #0
MOVW	R0, #lo_addr(_taskTime+0)
MOVT	R0, #hi_addr(_taskTime+0)
STRH	R1, [R0, #0]
;Click_Ambient4_STM.c,128 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Ambient4_STM.c,130 :: 		void applicationTask()
SUB	SP, SP, #56
STR	LR, [SP, #0]
;Click_Ambient4_STM.c,135 :: 		cloud_process();
BL	_cloud_process+0
;Click_Ambient4_STM.c,138 :: 		if( taskTime > 1500 )
MOVW	R0, #lo_addr(_taskTime+0)
MOVT	R0, #hi_addr(_taskTime+0)
LDRH	R1, [R0, #0]
MOVW	R0, #1500
CMP	R1, R0
IT	LS
BLS	L_applicationTask4
;Click_Ambient4_STM.c,140 :: 		taskTime = 0;
MOVS	R1, #0
MOVW	R0, #lo_addr(_taskTime+0)
MOVT	R0, #hi_addr(_taskTime+0)
STRH	R1, [R0, #0]
;Click_Ambient4_STM.c,142 :: 		ambientValue = ambient4_readData();
BL	_ambient4_readData+0
;Click_Ambient4_STM.c,143 :: 		WordToStr(ambientValue, demoBuffer);
ADD	R1, SP, #4
BL	_WordToStr+0
;Click_Ambient4_STM.c,144 :: 		Ltrim(demoBuffer);
ADD	R0, SP, #4
BL	_Ltrim+0
;Click_Ambient4_STM.c,145 :: 		cloud_packCmd( &_AT_DSET[0], &ambient4_ref[0], &demoBuffer[0]);
ADD	R0, SP, #4
MOV	R2, R0
MOVW	R1, #lo_addr(Click_Ambient4_STM_ambient4_ref+0)
MOVT	R1, #hi_addr(Click_Ambient4_STM_ambient4_ref+0)
MOVW	R0, #lo_addr(Click_Ambient4_STM__AT_DSET+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__AT_DSET+0)
BL	_cloud_packCmd+0
;Click_Ambient4_STM.c,146 :: 		cloud_cmdSingle( &_AT_PUB[0] );
MOVW	R0, #lo_addr(Click_Ambient4_STM__AT_PUB+0)
MOVT	R0, #hi_addr(Click_Ambient4_STM__AT_PUB+0)
BL	_cloud_cmdSingle+0
;Click_Ambient4_STM.c,147 :: 		}
L_applicationTask4:
;Click_Ambient4_STM.c,148 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #56
BX	LR
; end of _applicationTask
_main:
;Click_Ambient4_STM.c,151 :: 		void main()
;Click_Ambient4_STM.c,153 :: 		systemInit();
BL	_systemInit+0
;Click_Ambient4_STM.c,154 :: 		applicationInit();
BL	_applicationInit+0
;Click_Ambient4_STM.c,156 :: 		while (1)
L_main5:
;Click_Ambient4_STM.c,158 :: 		applicationTask();
BL	_applicationTask+0
;Click_Ambient4_STM.c,159 :: 		}
IT	AL
BAL	L_main5
;Click_Ambient4_STM.c,160 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
