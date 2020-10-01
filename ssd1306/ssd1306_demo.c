/*
 * Copyright (c) 2020, HiHope Community.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <unistd.h>

#include "ohos_init.h"
#include "cmsis_os2.h"
#include "wifiiot_gpio.h"
#include "wifiiot_gpio_ex.h"
#include "wifiiot_pwm.h"
#include "wifiiot_adc.h"
#include "wifiiot_i2c.h"
#include "wifiiot_errno.h"
#include "wifiiot_watchdog.h"

#include "ssd1306.h"
#include "ssd1306_tests.h"

#define OLED_I2C_BAUDRATE 1000*1000

void Ssd1306TestTask(void* arg)
{
    (void) arg;
    GpioInit();
    IoSetFunc(WIFI_IOT_IO_NAME_GPIO_13, WIFI_IOT_IO_FUNC_GPIO_13_I2C0_SDA);
    IoSetFunc(WIFI_IOT_IO_NAME_GPIO_14, WIFI_IOT_IO_FUNC_GPIO_14_I2C0_SCL);
    I2cInit(WIFI_IOT_I2C_IDX_0, OLED_I2C_BAUDRATE);

    WatchDogDisable();

    ssd1306_Init();
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("Hello HarmonyOS!", Font_6x8, White);
    ssd1306_UpdateScreen();

    for (int i = 0; i < 20; i++) {
        usleep(10*1000);
        printf("HAL_GetTick(): %d\r\n", HAL_GetTick());
    }

    for (int i = 0; i < 20; i++) {
        HAL_Delay(25);
        printf(" HAL_GetTick(): %d\r\n", HAL_GetTick());
    }

    for (int i = 0; i < 10; i++) {
        static char text[32];
        snprintf(text, sizeof(text), "tick: %d", HAL_GetTick());
        ssd1306_SetCursor(0, 8);
        ssd1306_WriteString(text, Font_6x8, White);
        ssd1306_UpdateScreen();
    }


    while (1) {
        printf("ssd1306_TestFPS: %d\r\n", HAL_GetTick());
        ssd1306_TestFPS();
        HAL_Delay(3000);

        printf("ssd1306_TestBorder\r\n");
        ssd1306_TestBorder();

        printf("ssd1306_TestFonts\r\n");
        ssd1306_TestFonts();
        HAL_Delay(3000);

        printf("ssd1306_TestRectangle\r\n");
        ssd1306_Fill(Black);
        ssd1306_TestRectangle();
        ssd1306_TestLine();
        HAL_Delay(3000);

        printf("ssd1306_TestPolyline\r\n");
        ssd1306_Fill(Black);
        ssd1306_TestPolyline();
        HAL_Delay(3000);

        ssd1306_Fill(Black);
        ssd1306_TestArc();
        HAL_Delay(3000);

        ssd1306_Fill(Black);
        ssd1306_TestCircle();
        HAL_Delay(3000);
    }
}

void Ssd1306TestDemo(void)
{
    osThreadAttr_t attr;

    attr.name = "Ssd1306Task";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = 4096;
    attr.priority = osPriorityNormal;

    if (osThreadNew(Ssd1306TestTask, NULL, &attr) == NULL) {
        printf("[Ssd1306TestDemo] Falied to create Ssd1306TestTask!\n");
    }
}
APP_FEATURE_INIT(Ssd1306TestDemo);