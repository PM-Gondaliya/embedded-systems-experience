#ifndef ALARM_SETTINGS_H
#define ALARM_SETTINGS_H

#include <stdint.h>
#include <stdbool.h>

/* Alarm state flags */
extern volatile bool alarm_enabled;

/* Alarm control functions */
void alarm_set_time(void);
void alarm_run(void);

#endif /* ALARM_SETTINGS_H */
