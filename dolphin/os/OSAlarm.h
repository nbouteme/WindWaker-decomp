#pragma once

#include "../os.h"

typedef struct OSAlarm  OSAlarm;
typedef void          (*OSAlarmHandler)(os::OSAlarm* alarm, os::OSContext* context);

struct OSAlarm
{
    OSAlarmHandler  handler;
    u32             tag;
    os::OSTime          fire;
    OSAlarm*        prev;
    OSAlarm*        next;

    // Periodic alarm
    os::OSTime          period;
    os::OSTime          start;
#ifdef WIN32
    void*           queue;
#endif
};

void OSInitAlarm        ( void );
void OSSetAlarm         ( os::OSAlarm* alarm, os::OSTime tick, OSAlarmHandler handler );
void OSSetAlarmTag      ( os::OSAlarm* alarm, u32 tag );
void OSSetAbsAlarm      ( os::OSAlarm* alarm, os::OSTime time, OSAlarmHandler handler );
void OSSetPeriodicAlarm ( os::OSAlarm* alarm, os::OSTime start, os::OSTime period,
                          OSAlarmHandler handler );
void OSCreateAlarm      ( os::OSAlarm* alarm );
void OSCancelAlarm      ( os::OSAlarm* alarm );
void OSCancelAlarms     ( u32 tag );

BOOL OSCheckAlarmQueue  ( void );
