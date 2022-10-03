#pragma once

#include <dolphin/types.h>
#include <dolphin/os/OSContext.h>

#ifndef DOLPHIN
#include <ctime>
#include <csignal>
#endif

namespace os {

	typedef struct OSAlarm OSAlarm;
	typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);

	struct OSAlarm {
		OSAlarmHandler handler;
		u32 tag;
		OSTime fire;
		OSAlarm* prev;
		OSAlarm* next;

		// Periodic alarm
		OSTime period;
		OSTime start;
#ifdef WIN32
		void* queue;
#endif
#ifndef DOLPHIN
		timer_t timer;
#endif
	};

	void OSInitAlarm(void);
	void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
	void OSSetAlarmTag(OSAlarm* alarm, u32 tag);
	void OSSetAbsAlarm(OSAlarm* alarm, OSTime time, OSAlarmHandler handler);
	void OSSetPeriodicAlarm(OSAlarm* alarm, OSTime start, OSTime period,
							OSAlarmHandler handler);
	void OSCreateAlarm(OSAlarm* alarm);
	void OSCancelAlarm(OSAlarm* alarm);
	void OSCancelAlarms(u32 tag);

	BOOL OSCheckAlarmQueue(void);
}