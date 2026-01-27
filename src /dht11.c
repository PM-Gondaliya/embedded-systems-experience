/*
 * dht11.c
 * DHT11 sensor sampling using timer-based edge measurement
 *
 * Sampling approach derived from internship project report.
 */

#include "dht11.h"
#include <stdint.h>
#include <stdbool.h>

/* Internal state */
static volatile uint16_t pulse_width[48];
static volatile uint8_t pulse_index = 0;
static volatile bool frame_complete = false;

/* ISR callback (called on GPIO edge) */
void dht11_isr_cb(void)
{
    if (pulse_index < 48)
    {
        pulse_width[pulse_index++] = /* read timer register here */;
    }

    if (pulse_index >= 41)
    {
        frame_complete = true;
        pulse_index = 0;
    }
}

/* High-level processing */
void dht11_process(void)
{
    if (!frame_complete)
        return;

    /* Decode pulse_width[] according to DHT11 protocol */
    /* Temperature / humidity extraction logic here */

    frame_complete = false;
}
