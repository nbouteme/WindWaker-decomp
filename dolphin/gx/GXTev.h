#pragma once
/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>

namespace gx {
/*---------------------------------------------------------------------------*/
void GXSetTevOp(GXTevStageID id, GXTevMode mode);

void GXSetTevColorIn(
    GXTevStageID    stage,
    GXTevColorArg   a,
    GXTevColorArg   b,
    GXTevColorArg   c,
    GXTevColorArg   d );

void GXSetTevAlphaIn(
    GXTevStageID    stage,
    GXTevAlphaArg   a,
    GXTevAlphaArg   b,
    GXTevAlphaArg   c,
    GXTevAlphaArg   d );

void GXSetTevColorOp(
    GXTevStageID    stage,
    GXTevOp         op,
    GXTevBias       bias,
    GXTevScale      scale,
    GXBool          clamp,
    GXTevRegID      out_reg );

void GXSetTevAlphaOp(
    GXTevStageID    stage,
    GXTevOp         op,
    GXTevBias       bias,
    GXTevScale      scale,
    GXBool          clamp,
    GXTevRegID      out_reg );

void GXSetTevColor( GXTevRegID id, GXColor color );
void GXSetTevColorS10( GXTevRegID id, GXColorS10 color );

// Feature available in GX chip revision 1 only
// Revision 2 version is defined, but only prints error msg
void GXSetTevClampMode ( GXTevStageID stage, GXTevClampMode mode );

void GXSetAlphaCompare(
    GXCompare       comp0,
    u8              ref0,
    GXAlphaOp       op,
    GXCompare       comp1,
    u8              ref1 );

void GXSetTevOrder(
    GXTevStageID    stage, 
    GXTexCoordID    coord,
    GXTexMapID      map,
    GXChannelID     color );

void GXSetZTexture ( GXZTexOp op, GXTexFmt fmt, u32 bias );
void GXSetNumTevStages( u8 nStages );

#if ( GX_REV != 1 )
// Features available in GX chip revision 2 or later only
void GXSetTevKColor( GXTevKColorID id, GXColor color );
void GXSetTevKColorSel( GXTevStageID stage, GXTevKColorSel sel );
void GXSetTevKAlphaSel( GXTevStageID stage, GXTevKAlphaSel sel );

void GXSetTevSwapMode(
    GXTevStageID    stage,
    GXTevSwapSel    ras_sel,
    GXTevSwapSel    tex_sel );

void GXSetTevSwapModeTable(
    GXTevSwapSel    table,
    GXTevColorChan  red,
    GXTevColorChan  green,
    GXTevColorChan  blue,
    GXTevColorChan  alpha );

#endif // ( GX_REV != 1 )
}