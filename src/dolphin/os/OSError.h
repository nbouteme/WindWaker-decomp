#pragma once

#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSException.h>

/*---------------------------------------------------------------------------*
    Error Handler API
 *---------------------------------------------------------------------------*/
namespace os {

	typedef u16 OSError;

	typedef void (*OSErrorHandler)(OSError error, os::OSContext* context, ...);
	/*
 * Note: for most errors, OSErrorHandler takes third and fourth arguments
 * /dsisr/ and /dar/, which are of type /u32/ like below:
 *
 * void (*OSErrorHandler)( OSError error, OSContext* context,
 *                         u32 dsisr, u32 dar );
 *
 */

#define OS_ERROR_SYSTEM_RESET 0
#define OS_ERROR_MACHINE_CHECK 1
#define OS_ERROR_DSI 2
#define OS_ERROR_ISI 3
#define OS_ERROR_EXTERNAL_INTERRUPT 4
#define OS_ERROR_ALIGNMENT 5
#define OS_ERROR_PROGRAM 6
#define OS_ERROR_FLOATING_POINT 7  // floating-point unavailable
#define OS_ERROR_DECREMENTER 8
#define OS_ERROR_SYSTEM_CALL 9
#define OS_ERROR_TRACE 10
#define OS_ERROR_PERFORMACE_MONITOR 11
#define OS_ERROR_BREAKPOINT 12
#define OS_ERROR_SYSTEM_INTERRUPT 13
#define OS_ERROR_THERMAL_INTERRUPT 14
#define OS_ERROR_PROTECTION 15
#define OS_ERROR_FPE 16	 // floating-point exception

#define OS_ERROR_MAX (OS_ERROR_FPE + 1)

	OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler);

	// Default FPSCR enable bits set when OS_ERROR_FPE handler is set
	extern u32 __OSFpscrEnableBits;	 // OR-ed FPSCR_*E bits
}