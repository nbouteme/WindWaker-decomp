#pragma once

/*
    This header file defines the low level L2 cache operations.
    Most should be macros to the underlying assembly routines, but
    others will manipulate hardware setup registers.
 */

#include <dolphin/types.h>

void L2Enable           ( void );
void L2Disable          ( void );
void L2GlobalInvalidate ( void );
void L2SetDataOnly      ( BOOL dataOnly );
void L2SetWriteThrough  ( BOOL writeThrough );
