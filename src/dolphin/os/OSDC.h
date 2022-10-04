#pragma once

/*
    This header file defines the low level data cache operations.  Most should
    be macros to the underlying assembly routines, but others will manipulate
    hardware setup registers.
 */

#include <dolphin/types.h>

void DCFlashInvalidate  ( void );
void DCEnable           ( void );
void DCDisable          ( void );
void DCFreeze           ( void );
void DCUnfreeze         ( void );
void DCTouchLoad        ( void* addr );
void DCBlockZero        ( void* addr );
void DCBlockStore       ( void* addr );
void DCBlockFlush       ( void* addr );
void DCBlockInvalidate  ( void* addr );
