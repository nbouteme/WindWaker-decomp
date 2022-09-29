#pragma once

/*
    This header file defines the low level locked cache operations.
    Most should be macros to the underlying assembly routines, but
    others will manipulate hardware setup registers.

    Note that there are some restrictions on arguments that must
    be adhered to.  Read implementation notes (OSCache.c) or
    man pages for details.
 */

#include <dolphin/types.h>

// maximum size of a single DMA transaction
#define LC_MAX_DMA_BLOCKS   (128)
#define LC_MAX_DMA_BYTES    (LC_MAX_DMA_BLOCKS * 32)

void LCAlloc            ( void* addr, u32 nBytes );
void LCAllocNoInvalidate( void* addr, u32 nBytes );
void LCAllocOneTag  ( BOOL invalidate, void* tag );
void LCAllocTags    ( BOOL invalidate, void* startTag, u32 numBlocks );
u32  LCQueueLength  ( void );
