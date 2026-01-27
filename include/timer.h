#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

/* Global millisecond counter */
extern volatile uint32_t sys_ms;

/* Timer1 ISR callback (1 ms tick) */
void tmr1_isr_cb_ms(void);

#endif /* TIMER_H */
