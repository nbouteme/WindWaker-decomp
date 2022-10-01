#pragma once

/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>
namespace gx {
/*---------------------------------------------------------------------------*/
void GXInitLightAttn(
         GXLightObj*   lt_obj,
         f32           a0,
         f32           a1,
         f32           a2,
         f32           k0,
         f32           k1,
         f32           k2 );

void GXInitLightAttnA ( GXLightObj *lt_obj, f32 a0, f32 a1, f32 a2);
void GXInitLightAttnK ( GXLightObj *lt_obj, f32 k0, f32 k1, f32 k2 );

void GXInitLightSpot(
         GXLightObj*   lt_obj,
         f32           cutoff,
         GXSpotFn      spot_func );

void GXInitLightDistAttn(
         GXLightObj*   lt_obj,
         f32           ref_distance,
         f32           ref_brightness,
         GXDistAttnFn  dist_func );


void GXInitLightPos 	( GXLightObj* lt_obj, f32 x, f32 y, f32 z );
void GXInitLightColor 	( GXLightObj* lt_obj, GXColor color );
void GXLoadLightObjImm 	( const GXLightObj* lt_obj, GXLightID light );
void GXLoadLightObjIndx	( u32 lt_obj_indx, GXLightID light );
void GXSetChanAmbColor 	( GXChannelID chan, GXColor amb_color );
void GXSetChanMatColor	( GXChannelID chan, GXColor mat_color );
void GXSetNumChans      ( u8 nChans );

void GXInitLightDir 	( GXLightObj* lt_obj, f32 nx, f32 ny, f32 nz );

// New functions to set light direction and half-angle.
void GXInitSpecularDir 	( GXLightObj* lt_obj, f32 nx, f32 ny, f32 nz );
void GXInitSpecularDirHA(
        GXLightObj* lt_obj,
        f32         nx,
        f32         ny,
        f32         nz,
        f32         hx,
        f32         hy,
        f32         hz );

void GXSetChanCtrl(
        GXChannelID   chan,
        GXBool        enable,
        GXColorSrc    amb_src,
        GXColorSrc    mat_src,
        u32           light_mask,
        GXDiffuseFn   diff_fn,
        GXAttnFn      attn_fn );

/*---------------------------------------------------------------------------*/
// Convenient Macros

#define GXInitLightPosv(lo,vec) \
    (GXInitLightPos((lo), *(f32*)(vec), *((f32*)(vec)+1), *((f32*)(vec)+2)))

#define GXInitLightDirv(lo,vec) \
    (GXInitLightDir((lo), *(f32*)(vec), *((f32*)(vec)+1), *((f32*)(vec)+2)))

#define GXInitSpecularDirv(lo,vec) \
    (GXInitSpecularDir((lo), *(f32*)(vec), *((f32*)(vec)+1), *((f32*)(vec)+2)))

#define GXInitSpecularDirHAv(lo,vec0,vec1) \
    (GXInitSpecularDirHA((lo), \
    *(f32*)(vec0), *((f32*)(vec0)+1), *((f32*)(vec0)+2), \
    *(f32*)(vec1), *((f32*)(vec1)+1), *((f32*)(vec1)+2)))

#define GXInitLightShininess(lobj, shininess) \
    (GXInitLightAttn(lobj, 0.0F, 0.0F, 1.0F,  \
                    (shininess)/2.0F, 0.0F,   \
                    1.0F-(shininess)/2.0F ))

}