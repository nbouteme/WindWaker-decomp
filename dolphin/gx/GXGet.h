#pragma once

#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>
namespace gx {
/*---------------------------------------------------------------------------* 
      GEOMETRY AND VERTEX FUNCTIONS
 *---------------------------------------------------------------------------*/
void GXGetVtxDesc            ( GXAttr attr, GXAttrType *type );
void GXGetVtxDescv           ( GXVtxDescList *vcd );
void GXGetVtxAttrFmtv        ( GXVtxFmt fmt, GXVtxAttrFmtList *vat );

void GXGetLineWidth          ( u8 *width, GXTexOffset *texOffsets );
void GXGetPointSize          ( u8 *pointSize, GXTexOffset *texOffsets );

void GXGetVtxAttrFmt( 
    GXVtxFmt       idx, 
    GXAttr         attr, 
    GXCompCnt*     compCnt, 
    GXCompType*    compType, 
    u8*            shift );

/*---------------------------------------------------------------------------* 
      TRANSFORMATION AND MATRIX FUNCTIONS
 *---------------------------------------------------------------------------*/
void GXGetViewportv( f32* viewport );  // used by GXProject
void GXGetProjectionv( f32* p );       // used by GXProject

/*---------------------------------------------------------------------------* 
      CLIPPING AND CULLING FUNCTIONS
 *---------------------------------------------------------------------------*/
void GXGetScissor( 
    u32*    left, 
    u32*    top, 
    u32*    width, 
    u32*    height );

void GXGetCullMode( GXCullMode *mode );

/*---------------------------------------------------------------------------* 
      LIGHTING OBJECT ACCESS FUNCTIONS
 *---------------------------------------------------------------------------*/
void GXGetLightAttnA(
        const GXLightObj* lt_obj,
        f32*        a0,
        f32*        a1,
        f32*        a2 );

void GXGetLightAttnK(
        const GXLightObj* lt_obj,
        f32*        k0,
        f32*        k1,
        f32*        k2 );

void GXGetLightPos(
        const GXLightObj* lt_obj,
        f32*        x,
        f32*        y,
        f32*        z );

#define GXGetLightPosv(lo, vec) \
 (GXGetLightPos((lo), (f32*)(vec), (f32*)(vec)+1, (f32*)(vec)+2))

void GXGetLightDir(
        const GXLightObj* lt_obj,
        f32*        nx,
        f32*        ny,
        f32*        nz );

#define GXGetLightDirv(lo, vec) \
 (GXGetLightDir((lo), (f32*)(vec), (f32*)(vec)+1, (f32*)(vec)+2))

void GXGetLightColor(
        const GXLightObj* lt_obj,
        GXColor*    color );

/*---------------------------------------------------------------------------* 
      TEXTURE OBJECT ACCESS FUNCTIONS
 *---------------------------------------------------------------------------*/
void*         GXGetTexObjData  ( const GXTexObj* tex_obj );
u16           GXGetTexObjWidth ( const GXTexObj* tex_obj );
u16           GXGetTexObjHeight( const GXTexObj* tex_obj );
GXTexFmt      GXGetTexObjFmt   ( const GXTexObj* tex_obj );
GXTexWrapMode GXGetTexObjWrapS ( const GXTexObj* tex_obj );
GXTexWrapMode GXGetTexObjWrapT ( const GXTexObj* tex_obj );
GXBool        GXGetTexObjMipMap( const GXTexObj* tex_obj );     

void GXGetTexObjAll(
        const GXTexObj* tex_obj, 
        void**          data, 
        u16*            width, 
        u16*            height, 
        GXTexFmt*       format,
        GXTexWrapMode*  wrapS, 
        GXTexWrapMode*  wrapT,
        GXBool*         mipMap );

GXTexFilter   GXGetTexObjMinFilt  ( const GXTexObj* tex_obj );
GXTexFilter   GXGetTexObjMagFilt  ( const GXTexObj* tex_obj );
f32           GXGetTexObjMinLOD   ( const GXTexObj* tex_obj );
f32           GXGetTexObjMaxLOD   ( const GXTexObj* tex_obj );
f32           GXGetTexObjLODBias  ( const GXTexObj* tex_obj );
GXBool        GXGetTexObjBiasClamp( const GXTexObj* tex_obj );
GXBool        GXGetTexObjEdgeLOD  ( const GXTexObj* tex_obj );
GXAnisotropy  GXGetTexObjMaxAniso ( const GXTexObj* tex_obj );

void GXGetTexObjLODAll (
        const GXTexObj* tex_obj,
        GXTexFilter*    min_filt,
        GXTexFilter*    mag_filt,
        f32*            min_lod,
        f32*            max_lod,
        f32*            lod_bias,
        GXBool*         bias_clamp,
        GXBool*         do_edge_lod,
        GXAnisotropy*   max_aniso );

u32 GXGetTexObjTlut( const GXTexObj* tex_obj );

void*         GXGetTlutObjData      ( const GXTlutObj* tlut_obj );
GXTlutFmt     GXGetTlutObjFmt       ( const GXTlutObj* tlut_obj );
u16           GXGetTlutObjNumEntries( const GXTlutObj* tlut_obj );

void GXGetTlutObjAll (
        const GXTlutObj*      tlut_obj,
        void**          data,
        GXTlutFmt*      format,
        u16*            numEntries );

void GXGetTexRegionAll (
        const GXTexRegion*    region,
        GXBool*         is_cached,
        GXBool*         is_32b_mipmap,
        u32*            tmem_even,
        u32*            size_even,
        u32*            tmem_odd,
        u32*            size_odd );

void GXGetTlutRegionAll (
        const GXTlutRegion*   region,
        u32*            tmem_addr,
        GXTlutSize*     tlut_size );
}