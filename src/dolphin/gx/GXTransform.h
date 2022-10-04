#pragma once
/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>

#ifdef WIN32
#include "win32/win32.h"
#endif
namespace gx {
#define GX_PROJECTION_SZ  7
#define GX_VIEWPORT_SZ    6

/*---------------------------------------------------------------------------*/
void GXSetProjection ( const f32 mtx[4][4], GXProjectionType type );
void GXSetProjectionv ( const f32 *ptr );
void GXLoadPosMtxImm ( const f32 mtx[3][4], u32 id );
void GXLoadPosMtxIndx ( u16 mtx_indx, u32 id );
void GXLoadNrmMtxImm ( const f32 mtx[3][4], u32 id );
void GXLoadNrmMtxImm3x3 ( const f32 mtx[3][3], u32 id );
void GXLoadNrmMtxIndx3x3 ( u16 mtx_indx, u32 id );
void GXSetCurrentMtx ( u32 id );
void GXLoadTexMtxImm ( const f32 mtx[][4], u32 id, GXTexMtxType type );
void GXLoadTexMtxIndx ( u16 mtx_indx, u32 id, GXTexMtxType type );

void GXProject ( 
	f32  x,          // model coordinates
	f32  y,
	f32  z,
	const f32  mtx[3][4],  // model-view matrix
	const f32* pm,         // projection matrix, as returned by GXGetProjectionv
	const f32* vp,         // viewport, as returned by GXGetViewportv
	f32* sx,         // screen coordinates
	f32* sy,
	f32* sz );

void GXSetViewport(
         f32 left, 
         f32 top, 
         f32 wd, 
         f32 ht, 
         f32 nearz, 
         f32 farz );

static inline void GXSetViewportv( const f32 *vp )
{   // Note: doesn't check for NULL ptr
    GXSetViewport(vp[0], vp[1], vp[2], vp[3], vp[4], vp[5]);
}

void GXSetViewportJitter(
         f32 left, 
         f32 top, 
         f32 wd, 
         f32 ht, 
         f32 nearz, 
         f32 farz,
	 u32 field );

void GXSetZScaleOffset  ( f32 scale, f32 offset );

#if ( GX_REV != 1 )
void GXSetScissorBoxOffset( s32 x_off, s32 y_off );
#endif

void GXSetClipMode( GXClipMode mode );
}