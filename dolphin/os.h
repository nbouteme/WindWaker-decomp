#pragma once

#include <doltypes.h>

#include <cstdarg>
#include <dolphin/gx/GXStruct.h>

namespace os {
	/*---------------------------------------------------------------------------*
    Arena API
 *---------------------------------------------------------------------------*/

	void* OSGetArenaHi(void);
	void* OSGetArenaLo(void);
	void OSSetArenaHi(void* newHi);
	void OSSetArenaLo(void* newLo);

	void* OSAllocFromArenaLo(u32 size, u32 align);
	void* OSAllocFromArenaHi(u32 size, u32 align);

/*---------------------------------------------------------------------------*
    Round APIs
 *---------------------------------------------------------------------------*/

// Most Dolphin subsystems require 32 byte alignment
#define OSRoundUp32B(x) (((u32)(x) + 32 - 1) & ~(32 - 1))
#define OSRoundDown32B(x) (((u32)(x)) & ~(32 - 1))

	/*---------------------------------------------------------------------------*
    Basic OS API
 *---------------------------------------------------------------------------*/

	void OSInit(void);

#define OS_CONSOLE_MASK 0xf0000000
#define OS_CONSOLE_RETAIL 0x00000000
#define OS_CONSOLE_DEVELOPMENT 0x10000000
#define OS_CONSOLE_TDEV 0x20000000

#define OS_CONSOLE_RETAIL4 0x00000004
#define OS_CONSOLE_RETAIL3 0x00000003
#define OS_CONSOLE_RETAIL2 0x00000002
#define OS_CONSOLE_RETAIL1 0x00000001
#define OS_CONSOLE_TDEVHW4 0x20000007
#define OS_CONSOLE_TDEVHW3 0x20000006
#define OS_CONSOLE_TDEVHW2 0x20000005
#define OS_CONSOLE_TDEVHW1 0x20000004
#define OS_CONSOLE_DEVHW4 0x10000007
#define OS_CONSOLE_DEVHW3 0x10000006
#define OS_CONSOLE_DEVHW2 0x10000005
#define OS_CONSOLE_DEVHW1 0x10000004
#define OS_CONSOLE_MINNOW 0x10000003
#define OS_CONSOLE_ARTHUR 0x10000002
#define OS_CONSOLE_PC_EMULATOR 0x10000001
#define OS_CONSOLE_EMULATOR 0x10000000

	u32 OSGetConsoleType(void);

#define OS_SOUND_MODE_MONO 0u
#define OS_SOUND_MODE_STEREO 1u

	u32 OSGetSoundMode(void);
	void OSSetSoundMode(u32 mode);

#define OS_PROGRESSIVE_MODE_OFF 0u
#define OS_PROGRESSIVE_MODE_ON 1u

	u32 OSGetProgressiveMode(void);
	void OSSetProgressiveMode(u32 on);

#define OS_LANG_ENGLISH 0u
#define OS_LANG_GERMAN 1u
#define OS_LANG_FRENCH 2u
#define OS_LANG_SPANISH 3u
#define OS_LANG_ITALIAN 4u
#define OS_LANG_DUTCH 5u

	u8 OSGetLanguage(void);
	void OSSetLanguage(u8 language);

#define OS_EURGB60_OFF 0u
#define OS_EURGB60_ON 1u

	u32 OSGetEuRgb60Mode(void);
	void OSSetEuRgb60Mode(u32 on);

	void OSRegisterVersion(const char* id);

	/*---------------------------------------------------------------------------*
    Interrupt API
 *---------------------------------------------------------------------------*/

	BOOL OSDisableInterrupts(void);
	BOOL OSEnableInterrupts(void);
	BOOL OSRestoreInterrupts(BOOL level);

/*---------------------------------------------------------------------------*
    Address Translation API
 *---------------------------------------------------------------------------*/
#ifndef MACOS  // EPPC or GEKKO

	// Declarations
	void* OSPhysicalToCached(u32 paddr);
	void* OSPhysicalToUncached(u32 paddr);
	u32 OSCachedToPhysical(const void* caddr);
	u32 OSUncachedToPhysical(const void* ucaddr);
	void* OSCachedToUncached(const void* caddr);
	void* OSUncachedToCached(const void* ucaddr);

// Upper words of the masks, since UIMM is only 16 bits
#define OS_CACHED_REGION_PREFIX 0x8000
#define OS_UNCACHED_REGION_PREFIX 0xC000
#define OS_PHYSICAL_MASK 0x3FFF

#define OS_BASE_CACHED (OS_CACHED_REGION_PREFIX << 16)
#define OS_BASE_UNCACHED (OS_UNCACHED_REGION_PREFIX << 16)

// Macro overrides
#ifdef MINNOW
// MINNOW makes some assumptions about high order byte of addresses
// for emulation.  Thus we must use ORs/ANDs for this target.
#define OSPhysicalToCached(paddr) ((void*)((u32)(paddr) | OS_BASE_CACHED))
#define OSPhysicalToUncached(paddr) ((void*)((u32)(paddr) | OS_BASE_UNCACHED))
#define OSCachedToPhysical(caddr) ((u32)((u32)(caddr) & (~OS_BASE_CACHED)))
#define OSUncachedToPhysical(ucaddr) ((u32)((u32)(ucaddr) & (~OS_BASE_UNCACHED)))
#define OSCachedToUncached(caddr) ((void*)((u32)(caddr) | (u32)(OS_BASE_UNCACHED - OS_BASE_CACHED)))
#define OSUncachedToCached(ucaddr) ((void*)((u32)(ucaddr) & (~(u32)(OS_BASE_UNCACHED - OS_BASE_CACHED))))

#else  // MINNOW
#ifndef _DEBUG
#define OSPhysicalToCached(paddr) ((void*)((u32)(paddr) + OS_BASE_CACHED))
#define OSPhysicalToUncached(paddr) ((void*)((u32)(paddr) + OS_BASE_UNCACHED))
#define OSCachedToPhysical(caddr) ((u32)((u8*)(caddr)-OS_BASE_CACHED))
#define OSUncachedToPhysical(ucaddr) ((u32)((u8*)(ucaddr)-OS_BASE_UNCACHED))
#define OSCachedToUncached(caddr) ((void*)((u8*)(caddr) + (OS_BASE_UNCACHED - OS_BASE_CACHED)))
#define OSUncachedToCached(ucaddr) ((void*)((u8*)(ucaddr) - (OS_BASE_UNCACHED - OS_BASE_CACHED)))
#endif	// _DEBUG
#endif	// MINNOW
#else	// MACOS - no address translation by default.

#define OSPhysicalToCached(paddr) ((void*)(paddr))
#define OSPhysicalToUncached(paddr) ((void*)(paddr))
#define OSCachedToPhysical(caddr) ((u32)(caddr))
#define OSUncachedToPhysical(ucaddr) ((u32)(ucaddr))
#define OSCachedToUncached(caddr) ((void*)(caddr))
#define OSUncachedToCached(ucaddr) ((void*)(ucaddr))

#endif	// MACOS

	/*---------------------------------------------------------------------------*
    Real-time Clock API
 *---------------------------------------------------------------------------*/
	typedef s64 OSTime;
	typedef u32 OSTick;

// SN-Phil: AT ADDRESS MACRO
#if defined(HW1) || defined(HW1_DRIP) || defined(HW2)
	extern u32 __OSBusClock AT_ADDRESS(OS_BASE_CACHED | 0x00F8);	// sync with OSLoMem.h
	extern u32 __OSCoreClock AT_ADDRESS(OS_BASE_CACHED | 0x00FC);	// sync with OSLoMem.h
#define OS_BUS_CLOCK __OSBusClock
#define OS_CORE_CLOCK __OSCoreClock
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)
#endif	// defined(HW1) || defined(HW1_DRIP)

#ifdef MINNOW
// true for GEKKO and Lonestars
#define OS_CORE_CLOCK 264000000u
#define OS_BUS_CLOCK 33000000u
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)
#endif	// MINNOW

#ifdef SPRUCE
#ifdef GEKKO
// Gekko's on Spruces are running at 333Mhz
#define OS_CORE_CLOCK 333000000u
#define OS_BUS_CLOCK 66000000u
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)
#else  // GEKKO
#define OS_CORE_CLOCK 266000000u
#define OS_BUS_CLOCK 66000000u
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)
#endif	// GEKKO
#endif	// SPRUCE

#ifdef MACOS
	extern u32 __OSBusClock;
	extern u32 __OSCoreClock;
	extern u32 __OSTimerClock;
#define OS_BUS_CLOCK __OSBusClock
#define OS_CORE_CLOCK __OSCoreClock
#define OS_TIMER_CLOCK __OSTimerClock
#endif	// MACOS

// Default Configuration
#ifndef OS_CORE_CLOCK
#define OS_CORE_CLOCK 486000000u
#endif
#ifndef OS_BUS_CLOCK
#define OS_BUS_CLOCK 162000000u
#endif
#ifndef OS_TIMER_CLOCK
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)
#endif

#define OSTicksToCycles(ticks) (((ticks) * ((OS_CORE_CLOCK * 2) / OS_TIMER_CLOCK)) / 2)
#define OSTicksToSeconds(ticks) ((ticks) / OS_TIMER_CLOCK)
#define OSTicksToMilliseconds(ticks) ((ticks) / (OS_TIMER_CLOCK / 1000))
#define OSTicksToMicroseconds(ticks) (((ticks)*8) / (OS_TIMER_CLOCK / 125000))
#define OSTicksToNanoseconds(ticks) (((ticks)*8000) / (OS_TIMER_CLOCK / 125000))
#define OSSecondsToTicks(sec) ((sec)*OS_TIMER_CLOCK)
#define OSMillisecondsToTicks(msec) ((msec) * (OS_TIMER_CLOCK / 1000))
#define OSMicrosecondsToTicks(usec) (((usec) * (OS_TIMER_CLOCK / 125000)) / 8)
#define OSNanosecondsToTicks(nsec) (((nsec) * (OS_TIMER_CLOCK / 125000)) / 8000)

#define OSDiffTick(tick1, tick0) ((s32)(tick1) - (s32)(tick0))

	OSTick OSGetTick(void);
	OSTime OSGetTime(void);

	typedef struct OSCalendarTime {
		int sec;   // seconds after the minute [0, 61]
		int min;   // minutes after the hour [0, 59]
		int hour;  // hours since midnight [0, 23]
		int mday;  // day of the month [1, 31]
		int mon;   // month since January [0, 11]
		int year;  // years since 0000
		int wday;  // days since Sunday [0, 6]
		int yday;  // days since January 1 [0, 365]

		int msec;  // milliseconds after the second [0,999]
		int usec;  // microseconds after the millisecond [0,999]
	} OSCalendarTime;

	OSTime OSCalendarTimeToTicks(OSCalendarTime* td);
	void OSTicksToCalendarTime(OSTime ticks, OSCalendarTime* td);

	/*---------------------------------------------------------------------------*
    Stopwatch API
 *---------------------------------------------------------------------------*/

	typedef struct OSStopwatch {
		char* name;	   // name of this stopwatch
		u32 hits;	   // number of times turned on and off
		OSTime total;  // total time running
		OSTime min;	   // smallest time measured
		OSTime max;	   // longest time measured

		OSTime last;   // time at which this sw was last started
		BOOL running;  // TRUE if sw is running
		u32 _padding;
	} OSStopwatch;

	void OSInitStopwatch(OSStopwatch* sw, char* name);
	void OSStartStopwatch(OSStopwatch* sw);
	void OSStopStopwatch(OSStopwatch* sw);
	OSTime OSCheckStopwatch(OSStopwatch* sw);
	void OSResetStopwatch(OSStopwatch* sw);
	void OSDumpStopwatch(OSStopwatch* sw);

	/*----------------------------------------------------------------------*
    Debug API
 *----------------------------------------------------------------------*/

#define OSHalt(msg) OSPanic(__FILE__, __LINE__, msg)

#ifdef _DEBUG

#ifndef ASSERT
#define ASSERT(exp) \
	(void)((exp) || \
		   (OSPanic(__FILE__, __LINE__, "Failed assertion " #exp), 0))
#endif

#ifndef ASSERTMSG
#if defined(__STDC_VERSION__) && (199901L <= __STDC_VERSION__) || defined(__MWERKS__) || defined(__SN__)
#define ASSERTMSG(exp, ...) \
	(void)((exp) ||         \
		   (OSPanic(__FILE__, __LINE__, __VA_ARGS__), 0))
#else
#define ASSERTMSG(exp, msg) \
	(void)((exp) ||         \
		   (OSPanic(__FILE__, __LINE__, (msg)), 0))
#endif
#endif

#ifndef ASSERTMSG1
#define ASSERTMSG1(exp, msg, param1)           \
	(void)((exp) ||                            \
		   (OSPanic(__FILE__, __LINE__, (msg), \
					(param1)),                 \
			0))
#endif

#ifndef ASSERTMSG2
#define ASSERTMSG2(exp, msg, param1, param2)   \
	(void)((exp) ||                            \
		   (OSPanic(__FILE__, __LINE__, (msg), \
					(param1), (param2)),       \
			0))
#endif

#ifndef ASSERTMSG3
#define ASSERTMSG3(exp, msg, param1, param2, param3) \
	(void)((exp) ||                                  \
		   (OSPanic(__FILE__, __LINE__, (msg),       \
					(param1), (param2), (param3)),   \
			0))
#endif

#ifndef ASSERTMSG4
#define ASSERTMSG4(exp, msg, param1, param2, param3, param4) \
	(void)((exp) ||                                          \
		   (OSPanic(__FILE__, __LINE__, (msg),               \
					(param1), (param2), (param3), (param4)), \
			0))
#endif

#else  // _DEBUG

#ifndef ASSERT
#define ASSERT(exp) ((void)0)
#endif

#ifndef ASSERTMSG
#if defined(__STDC_VERSION__) && (199901L <= __STDC_VERSION__) || defined(__MWERKS__) || defined(__SN__)
#define ASSERTMSG(exp, ...) ((void)0)
#else
#define ASSERTMSG(exp, msg) ((void)0)
#endif
#endif

#ifndef ASSERTMSG1
#define ASSERTMSG1(exp, msg, param1) ((void)0)
#endif
#ifndef ASSERTMSG2
#define ASSERTMSG2(exp, msg, param1, param2) ((void)0)
#endif
#ifndef ASSERTMSG3
#define ASSERTMSG3(exp, msg, param1, param2, param3) ((void)0)
#endif
#ifndef ASSERTMSG4
#define ASSERTMSG4(exp, msg, param1, param2, param3, param4) ((void)0)
#endif

#endif	// _DEBUG

#ifndef __DOLPHIN_RC__

	void OSPanic(const char* file, int line, const char* msg, ...);
	void OSReport(const char* msg, ...);
	void OSVReport(const char* msg, va_list list);
	void OSFatal(gx::GXColor fg, gx::GXColor bg, const char* msg);

#endif	// __DOLPHIN_RC__

	/*---------------------------------------------------------------------------*
    Memory size APIs
 *---------------------------------------------------------------------------*/
	u32 OSGetPhysicalMemSize(void);
	u32 OSGetConsoleSimulatedMemSize(void);

	/*---------------------------------------------------------------------------*
    Advanced OS APIs
 *---------------------------------------------------------------------------*/

}

#include <dolphin/os/OSAlloc.h>     // Memory allocation routines and defines
#include <dolphin/os/OSAlarm.h>     // Alarm routines and defines
#include <dolphin/os/OSCache.h>     // Cache operation APIs
#include <dolphin/os/OSContext.h>   // Context structures and defines
#include <dolphin/os/OSError.h>     // Error handler routines and defines
#include <dolphin/os/OSException.h> // Exception handling routines and defines
#include <dolphin/os/OSExpansion.h> // Expansion interface APIs
#include <dolphin/os/OSFastCast.h>  // Fast float/int conversion
#include <dolphin/os/OSFont.h>      // ROM font routines and defines
#include <dolphin/os/OSInterrupt.h> // Interrupt handling routines and defines
#include <dolphin/os/OSMessage.h>   // Message routines and defines
#include <dolphin/os/OSModule.h>    // Relocatable module routines and defines
#include <dolphin/os/OSMutex.h>     // Mutex routines and defines
#include <dolphin/os/OSResetSW.h>   // Reset switch APIs
#include <dolphin/os/OSSerial.h>    // Serial interface APIs
#include <dolphin/os/OSSemaphore.h> // Semaphore routines and defines
#include <dolphin/os/OSThread.h>    // Thread routines and defines
#include <dolphin/os/OSReset.h>     // Reset APIs
