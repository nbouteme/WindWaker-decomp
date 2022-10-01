#pragma once

/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>
#include <dolphin/gx/GXFifo.h>
namespace gx {
typedef void (*GXDrawSyncCallback)(u16 token);
typedef void (*GXDrawDoneCallback)(void);

/*---------------------------------------------------------------------------*/
GXFifoObj*  GXInit                      ( void* base, u32 size );
void        GXAbortFrame                ( void );

void        GXSetDrawSync               ( u16 token );
u16         GXReadDrawSync              ( void );
GXDrawSyncCallback GXSetDrawSyncCallback( GXDrawSyncCallback cb );

void        GXDrawDone                  ( void );
void        GXSetDrawDone               ( void );
void        GXWaitDrawDone              ( void );
GXDrawDoneCallback GXSetDrawDoneCallback( GXDrawDoneCallback cb );

#ifdef BUG_INDX_ALIGN    
void        GXSetResetWritePipe         ( GXBool tf );
#endif    
void        GXFlush                     ( void );
void        GXResetWriteGatherPipe      ( void );
void        GXPixModeSync               ( void );
void        GXTexModeSync               ( void );

BOOL        IsWriteGatherBufferEmpty    ( void );

void        GXSetMisc                   ( GXMiscToken token, u32 val );
}