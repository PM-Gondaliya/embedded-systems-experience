#ifndef DHT11_H
#define DHT11_H

#include <stdint.h>
#include <stdbool.h>

/* Interrupt callback registration */
void DHT11_SetInterruptHandler(void (*handler)(void));

/* ISR callback for DHT11 edge timing */
void dht11_isr_cb(void);

/* High-level processing function */
void dht11_process(void);

#endif /* DHT11_H */
