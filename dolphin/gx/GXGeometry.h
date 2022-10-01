#pragma once
/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/os.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>
namespace gx {
void GXSetVtxDesc           ( GXAttr attr, GXAttrType type );
void GXSetVtxDescv          ( const GXVtxDescList *attrPtr );
void GXClearVtxDesc         ( void );

void GXSetVtxAttrFmt( 
    GXVtxFmt       vtxfmt, 
    GXAttr         attr, 
    GXCompCnt      cnt, 
    GXCompType     type, 
    u8             frac );

void GXSetVtxAttrFmtv       ( GXVtxFmt vtxfmt, const GXVtxAttrFmtList *list );
void GXSetArray             ( GXAttr attr, const void *base_ptr, u8 stride );
void GXBegin                ( GXPrimitive type, GXVtxFmt vtxfmt, u16 nverts );

#if defined(EMU) || defined(WIN32)
void GXEnd                  ( void );
#else // !EMU
static inline void GXEnd           ( void )
{
#ifdef _DEBUG
    extern GXBool __GXinBegin;
    if (!__GXinBegin)
        OSPanic(__FILE__, __LINE__, "GXEnd: called without a GXBegin");
    __GXinBegin = GX_FALSE;
#endif
}
#endif // EMU

#if ( GX_REV != 1 ) // GX revision 2 or later only
void GXSetTexCoordGen2(
    GXTexCoordID     dst_coord,
    GXTexGenType     func,
    GXTexGenSrc      src_param,
    u32              mtx,
    GXBool           normalize,
    u32              postmtx );
#endif // ( GX_REV != 1 )

#if ( GX_REV == 1 || defined(EMU) ) // GX revision 1 or emulator
void GXSetTexCoordGen( 
    GXTexCoordID     dst_coord,
    GXTexGenType     func,
    GXTexGenSrc      src_param,
    u32              mtx );
#else // GX revision 2 or later and real hardware
static inline void GXSetTexCoordGen ( 
    GXTexCoordID    dst_coord,
    GXTexGenType    func,
    GXTexGenSrc     src_param,
    u32             mtx )
{
    GXSetTexCoordGen2(dst_coord, func, src_param, mtx, 
                      GX_FALSE, GX_PTIDENTITY);
}
#endif // ( GX_REV == 1 || defined(EMU) )


void GXSetNumTexGens        ( u8 nTexGens );

void GXInvalidateVtxCache   ( void );
void GXSetLineWidth         ( u8 width, GXTexOffset texOffsets );
void GXSetPointSize         ( u8 pointSize, GXTexOffset texOffsets );
void GXEnableTexOffsets	    ( GXTexCoordID coord, GXBool line_enable, 
			      GXBool point_enable );

}