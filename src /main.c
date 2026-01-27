/*
 * main.c
 * Developed during industry internship (2023)
 * Platform: PIC24 microcontroller
 *
 * Application: Digital Clock with Alarm and DHT11 sensor
 *
 * NOTE:
 * - System initialization and low-level drivers are MCC-generated.
 * - This file focuses on application logic and module integration.
 */

#define _XTAL_FREQ 8000000
#define FCY (_XTAL_FREQ / 2)

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr1.h"

#include "timer.h"
#include "dht11.h"
#include "alarm_settings.h"

/* External display / I2C functions (implemented elsewhere) */
void SSD1306_Init(void);
void SSD1306_ClearDisplay(void);
void display_real_time(void);
void display_alarm_time(void);
void press_sound(void);

int main(void)
{
    SYSTEM_Initialize();

    /* Register ISR callbacks */
    TMR1_SetInterruptHandler(tmr1_isr_cb_ms);
    DHT11_SetInterruptHandler(dht11_isr_cb);

    SSD1306_Init();
    SSD1306_ClearDisplay();

    while (1)
    {
        /* Periodic sensor handling */
        dht11_process();

        /* Display current time */
        display_real_time();

        /* Alarm handling */
        if (alarm_enabled)
        {
            alarm_run();
            display_alarm_time();
        }
    }

    return 0;
}
