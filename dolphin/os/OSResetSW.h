#pragma once
#include <dolphin/types.h>
#include <dolphin/os/OSContext.h>

typedef void (*OSResetCallback)(void);

BOOL            OSGetResetButtonState( void );

// obsolete
BOOL            OSGetResetSwitchState( void );
OSResetCallback OSSetResetCallback   ( OSResetCallback callback );
