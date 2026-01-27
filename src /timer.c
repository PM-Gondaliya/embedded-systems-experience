/*
 * timer.c
 * Timer-based timekeeping using TMR1 interrupt
 */

#include "timer.h"

volatile uint32_t sys_ms = 0;

/* Called from TMR1 interrupt */
void tmr1_isr_cb_ms(void)
{
    sys_ms++;
}
