#pragma once

#include <dolphin/types.h>
#include <dolphin/os/OSContext.h>


/*---------------------------------------------------------------------------*
    Exception Handler API
 *---------------------------------------------------------------------------*/

typedef u8   __OSException;
typedef void (*__OSExceptionHandler)(
    __OSException           exception,
    os::OSContext*              context
);

#define __OS_EXCEPTION_SYSTEM_RESET         0
#define __OS_EXCEPTION_MACHINE_CHECK        1
#define __OS_EXCEPTION_DSI                  2
#define __OS_EXCEPTION_ISI                  3
#define __OS_EXCEPTION_EXTERNAL_INTERRUPT   4
#define __OS_EXCEPTION_ALIGNMENT            5
#define __OS_EXCEPTION_PROGRAM              6
#define __OS_EXCEPTION_FLOATING_POINT       7
#define __OS_EXCEPTION_DECREMENTER          8
#define __OS_EXCEPTION_SYSTEM_CALL          9
#define __OS_EXCEPTION_TRACE                10
#define __OS_EXCEPTION_PERFORMACE_MONITOR   11
#define __OS_EXCEPTION_BREAKPOINT           12
#define __OS_EXCEPTION_SYSTEM_INTERRUPT     13
#define __OS_EXCEPTION_THERMAL_INTERRUPT    14
#define __OS_EXCEPTION_MAX                  \
        (__OS_EXCEPTION_THERMAL_INTERRUPT+1)

// Updates OS exception table, NOT first-level exception vector.
__OSExceptionHandler    __OSSetExceptionHandler(
    __OSException           exception,
    __OSExceptionHandler    handler
);

__OSExceptionHandler    __OSGetExceptionHandler(
    __OSException           exception
);

// Context saving helpers
// For now, use stmw.  Theoretically on 750 it has the same latency
// as pipelined stores.
#ifdef GEKKO
#define OS_EXCEPTION_SAVE_GPRS(context)                 \
    stw     r0, OS_CONTEXT_R0(context)              ;   \
    stw     r1, OS_CONTEXT_R1(context)              ;   \
    stw     r2, OS_CONTEXT_R2(context)              ;   \
    stmw    r6, OS_CONTEXT_R6(context)              ;   \
    /* Save GQR1 to GQR7. GQR0 must always be zero */   \
    mfspr   r0, GQR1                                ;   \
    stw     r0, OS_CONTEXT_GQR1(context)            ;   \
    mfspr   r0, GQR2                                ;   \
    stw     r0, OS_CONTEXT_GQR2(context)            ;   \
    mfspr   r0, GQR3                                ;   \
    stw     r0, OS_CONTEXT_GQR3(context)            ;   \
    mfspr   r0, GQR4                                ;   \
    stw     r0, OS_CONTEXT_GQR4(context)            ;   \
    mfspr   r0, GQR5                                ;   \
    stw     r0, OS_CONTEXT_GQR5(context)            ;   \
    mfspr   r0, GQR6                                ;   \
    stw     r0, OS_CONTEXT_GQR6(context)            ;   \
    mfspr   r0, GQR7                                ;   \
    stw     r0, OS_CONTEXT_GQR7(context)            ;
#else   // !GEKKO                  
#define OS_EXCEPTION_SAVE_GPRS(context)                 \
    stw     r0, OS_CONTEXT_R0(context)              ;   \
    stw     r1, OS_CONTEXT_R1(context)              ;   \
    stw     r2, OS_CONTEXT_R2(context)              ;   \
    stmw    r6, OS_CONTEXT_R6(context)              ;
#endif  // GEKKO
