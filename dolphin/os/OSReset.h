#pragma once

#include <dolphin/types.h>
namespace os {


#define OS_RESETCODE_RESTART    0x80000000      // not by cold/hot reset
#define OS_RESETCODE_SYSTEM     0x40000000      // reserved by system

#define OS_RESETCODE_EXEC       0xC0000000
#define OS_RESETCODE_NETCONFIG  0xC0010000

#define OS_RESET_TIMEOUT        OSMillisecondsToTicks(1000)

#define OS_RESET_RESTART        0
#define OS_RESET_HOTRESET       1
#define OS_RESET_SHUTDOWN       2

#define OS_RESET_PRIO_SO        110     // SO API
#define OS_RESET_PRIO_IP        111     // IP API
#define OS_RESET_PRIO_CARD      127     // CARD API
#define OS_RESET_PRIO_PAD       127     // PAD API
#define OS_RESET_PRIO_GX        127     // GX API
#define OS_RESET_PRIO_ALARM     4294967295  // OSAlarm

typedef BOOL (* OSResetFunction )(BOOL final);
typedef struct OSResetFunctionInfo OSResetFunctionInfo;

struct OSResetFunctionInfo
{
    // public
    OSResetFunction      func;
    u32                  priority;

    // private
    OSResetFunctionInfo* next;
    OSResetFunctionInfo* prev;
};

void OSRegisterResetFunction  ( OSResetFunctionInfo* info );
void OSUnregisterResetFunction( OSResetFunctionInfo* info );
void OSResetSystem            ( int reset, u32 resetCode, BOOL forceMenu );
u32  OSGetResetCode           ( void );
void OSGetSaveRegion          ( void** start, void** end );
void OSGetSavedRegion         ( void** start, void** end );
void OSSetSaveRegion          ( void* start, void* end );
u32  OSSetBootDol             ( u32 dolOffset );

void OSExecv                  ( const char* dolfile, char* const argv[] );
void OSExecl                  ( const char* dolfile,
                                const char* arg0, .../*, (char*)NULL */ );

/*---------------------------------------------------------------------------*
  Name:         OSIsRestart

  Description:  Check to see if it's restarted

  Arguments:    None

  Returns:      True if restarted, False if cold-started
 *---------------------------------------------------------------------------*/
#define OSIsRestart()   \
            ((OSGetResetCode() & OS_RESETCODE_RESTART) ? TRUE : FALSE)
}