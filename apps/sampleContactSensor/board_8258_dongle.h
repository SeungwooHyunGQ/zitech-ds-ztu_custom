/********************************************************************************************************
 * @file    board_8258_dongle.h
 *
 * @brief   This is the header file for board_8258_dongle
 *
 * @author  Zigbee Group
 * @date    2021
 *
 * @par     Copyright (c) 2021, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *			All rights reserved.
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *
 *******************************************************************************************************/
#pragma once

/* Enable C linkage for C++ Compilers: */
#if defined(__cplusplus)
extern "C" {
#endif

// 스캔 키 (네트워크 조인/리셋 버튼) - PC0, Falling Edge
#define	BUTTON1                 GPIO_PC0
#define PC0_FUNC                AS_GPIO
#define PC0_OUTPUT_ENABLE       0
#define PC0_INPUT_ENABLE        1
#define	PULL_WAKEUP_SRC_PC0     PM_PIN_PULLUP_10K

// 도어 센서 알람 - PD7, HIGH 활성
#define SENSOR_ALARM_PIN        GPIO_PD7
#define PD7_FUNC                AS_GPIO
#define PD7_OUTPUT_ENABLE       0
#define PD7_INPUT_ENABLE        1
#define	PULL_WAKEUP_SRC_PD7     PM_PIN_PULLDOWN_100K

// 탬퍼 감지 - PC1, HIGH 활성
#define SENSOR_TAMPER_PIN       GPIO_PC1
#define PC1_FUNC                AS_GPIO
#define PC1_OUTPUT_ENABLE       0
#define PC1_INPUT_ENABLE        1
#define	PULL_WAKEUP_SRC_PC1     PM_PIN_PULLDOWN_100K

// 네트워크 LED - PD3, HIGH 활성
#define LED1                    GPIO_PD3
#define PD3_FUNC                AS_GPIO
#define PD3_OUTPUT_ENABLE       1
#define PD3_INPUT_ENABLE        0

#define LED_POWER               LED1

#define	PM_WAKEUP_LEVEL         PM_WAKEUP_LEVEL_HIGH

// ADC
#if 1//VOLTAGE_DETECT_ENABLE
#define VOLTAGE_DETECT_ADC_PIN  GPIO_PC5
#endif

// UART
#if ZBHCI_UART
#error please configurate uart PIN!!!!!!
#endif

// DEBUG
#if UART_PRINTF_MODE
#define	DEBUG_INFO_TX_PIN       GPIO_PC6//print
#endif

enum {
    VK_SW1 = 0x01,
};

#define	KB_MAP_NORMAL           { \
                                    {VK_SW1,}, \
                                }

#define	KB_MAP_NUM              KB_MAP_NORMAL
#define	KB_MAP_FN               KB_MAP_NORMAL

#define KB_DRIVE_PINS           {0}
#define KB_SCAN_PINS            {BUTTON1}


/* Disable C linkage for C++ Compilers: */
#if defined(__cplusplus)
}
#endif
