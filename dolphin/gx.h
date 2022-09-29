#pragma once

#include <doltypes.h>
#include "os.h"
#include "vi.h"

#define EMU 1

namespace gx {

//------------------------------------------------------------------------------
// Bump (indirect texture functions).
//------------------------------------------------------------------------------
extern void GXSetNumIndStages (u8 nIndStages);
extern void GXSetIndTexOrder (GXIndTexStageID ind_stage, GXTexCoordID tex_coord,
			      GXTexMapID tex_map);
extern void GXSetIndTexCoordScale (GXIndTexStageID ind_state, 
				   GXIndTexScale scale_s, GXIndTexScale scale_t);
extern void GXSetIndTexMtx (GXIndTexMtxID mtx_sel, const f32 offset[2][3], s8 scale_exp);
extern void GXSetTevIndirect (GXTevStageID tev_stage, GXIndTexStageID ind_stage,
		      GXIndTexFormat format, GXIndTexBiasSel bias_sel, 
		      GXIndTexMtxID matrix_sel,
		      GXIndTexWrap wrap_s, GXIndTexWrap wrap_t,
		      GXBool add_prev, GXBool ind_lod, GXIndTexAlphaSel alpha_sel);

//------------------------------------------------------------------------------
// Convinience functions
//------------------------------------------------------------------------------
extern void GXSetTevDirect (GXTevStageID tev_stage);
extern void GXSetTevIndWarp (GXTevStageID tev_stage, GXIndTexStageID ind_stage,
			     GXBool signed_offset, GXBool replace_mode,
			     GXIndTexMtxID matrix_sel);
extern void GXSetTevIndTile (GXTevStageID tev_stage, GXIndTexStageID ind_stage,
			     u16 tilesize_s, u16 tilesize_t, 
			     u16 tilespacing_s, u16 tilespacing_t, 
			     GXIndTexFormat format, GXIndTexMtxID matrix_sel,
			     GXIndTexBiasSel bias_sel, GXIndTexAlphaSel alpha_sel);
extern void GXSetTevIndBumpST (GXTevStageID tev_stage, GXIndTexStageID ind_stage, 
			       GXIndTexMtxID matrix_sel);
extern void GXSetTevIndBumpXYZ (GXTevStageID tev_stage, GXIndTexStageID ind_stage, 
			       GXIndTexMtxID matrix_sel);
extern void GXSetTevIndRepeat (GXTevStageID tev_stage);

//------------------------------------------------------------------------------
extern void __GXSetIndirectMask ( u32 mask );

//------------------------------------------------------------------------------

/****************************************************************************/

// Display list opcodes:

#define GX_NOP                      0x00
#define GX_DRAW_QUADS               0x80
#define GX_DRAW_TRIANGLES           0x90
#define GX_DRAW_TRIANGLE_STRIP      0x98
#define GX_DRAW_TRIANGLE_FAN        0xA0
#define GX_DRAW_LINES               0xA8
#define GX_DRAW_LINE_STRIP          0xB0
#define GX_DRAW_POINTS              0xB8

#define GX_LOAD_BP_REG              0x61
#define GX_LOAD_CP_REG              0x08
#define GX_LOAD_XF_REG              0x10
#define GX_LOAD_INDX_A              0x20
#define GX_LOAD_INDX_B              0x28
#define GX_LOAD_INDX_C              0x30
#define GX_LOAD_INDX_D              0x38

#define GX_CMD_CALL_DL              0x40
#define GX_CMD_INVL_VC              0x48

#define GX_OPCODE_MASK              0xF8
#define GX_VAT_MASK                 0x07

/****************************************************************************/

// Texture register ID's:

extern u8 GXTexMode0Ids[8];
extern u8 GXTexMode1Ids[8];
extern u8 GXTexImage0Ids[8];
extern u8 GXTexImage1Ids[8];
extern u8 GXTexImage2Ids[8];
extern u8 GXTexImage3Ids[8];
extern u8 GXTexTlutIds[8];

// Filter conversion arrays:

extern u8 GX2HWFiltConv[6];
extern u8 HW2GXFiltConv[8];

/****************************************************************************/

/*---------------------------------------------------------------------------*
  Project:  Dolphin GX library
  File:	    GXCpu2Efb.h

  Copyright 1998 - 2002 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: /Dolphin/include/dolphin/gx/GXCpu2Efb.h $
    
    4     02/07/24 9:06 Hirose
    Resolved version conflicts.
    
    3     12/04/00 6:22p Hirose
    updated prototypes for GXPeekZ/GXPokeZ.
    added GXCompressZ/GXDecompressZ
    
    2     6/08/00 3:59p Carl
    Made GXPokeZMode similar to GXSetZMode.
    Eliminated GXPokeZUpdate.
    
    1     10/06/99 2:24a Yasu
    Initial Version
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
void GXPokeAlphaMode    ( GXCompare func, u8 threshold );
void GXPokeAlphaRead    ( GXAlphaReadMode mode );
void GXPokeAlphaUpdate  ( GXBool update_enable );
void GXPokeBlendMode    ( GXBlendMode type, GXBlendFactor src_factor,
                          GXBlendFactor dst_factor, GXLogicOp op );
void GXPokeColorUpdate  ( GXBool update_enable );
void GXPokeDstAlpha     ( GXBool enable, u8 alpha );
void GXPokeDither       ( GXBool dither );
void GXPokeZMode        ( GXBool compare_enable, GXCompare func,
                          GXBool update_enable );

void GXPokeZ    ( u16 x, u16 y, u32 z );
void GXPeekZ    ( u16 x, u16 y, u32* z );
void GXPokeARGB ( u16 x, u16 y, u32 color );
void GXPeekARGB ( u16 x, u16 y, u32* color );

u32  GXCompressZ16      ( u32 z24, GXZFmt16 zfmt );
u32  GXDecompressZ16    ( u32 z16, GXZFmt16 zfmt );

/*---------------------------------------------------------------------------*/
void GXSetScissor 	( u32 left, u32 top, u32 wd, u32 ht );
void GXSetCullMode	( GXCullMode mode );
void GXSetCoPlanar	( GXBool enable );

/*---------------------------------------------------------------------------*/
void GXBeginDisplayList		( void *list, u32 size );
u32  GXEndDisplayList		( void );
void GXCallDisplayList		( const void *list, u32 nbytes );

#ifndef EMU
// Note: GXCommandList.h and GXVert.h must be #included first

// Note: This function can only be used in certain situations.
//       There must be no dirty state pending.  Thus this function
//       is safe when called after a GXCallDisplayList or GXEnd call
//       (without any other GX calls in between).  It is also safe to
//       call this function multiple times in a row.
//       Please refer to the online man page for complete details.

// Note: No error checking is done; be careful!

static inline void GXFastCallDisplayList ( const void *list, u32 nbytes )
    {
        GXWGFifo.u8  = (u8) GX_CMD_CALL_DL;
        // XXX UNSAFE: Assumes GP ignores all extra padding/unused bits.
        GXWGFifo.u32 = (u32) list;
        GXWGFifo.u32 = (u32) nbytes;
    }
#else
static inline void GXFastCallDisplayList ( const void *list, u32 nbytes )
    { GXCallDisplayList( list, nbytes ); }
#endif

/*---------------------------------------------------------------------------*
  Project:  Dolphin GX library
  File:     GXDraw.h

  Copyright 1998 - 2002 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: /Dolphin/include/dolphin/gx/GXDraw.h $
    
    2     02/07/24 9:06 Hirose
    Resolved version conflicts.
    
    4     9/23/99 5:37p Alligator
    added GenNormalTable func
    
    3     7/20/99 6:30p Alligator
    added new models, all models are normalized, no vtxfmt needed
    
    2     7/16/99 2:04p Alligator
    
    1     7/16/99 1:06p Alligator
    procedural models used in tests
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

void GXDrawCylinder(u8 numEdges);
void GXDrawTorus(f32 rc, u8 numc, u8 numt);
void GXDrawSphere(u8 numMajor, u8 numMinor);
void GXDrawCube(void);
void GXDrawDodeca(void);
void GXDrawOctahedron( void );
void GXDrawIcosahedron( void );
void GXDrawSphere1( u8 depth );
u32  GXGenNormalTable( u8 depth, f32* table );

/*---------------------------------------------------------------------------*
  Project:  Dolphin GX library
  File:     GXEmVert.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: /dolphin/include/dolphin/gx/GXEmVert.h $
    
    1     11/17/99 6:26p Carl
  $NoKeywords: $

 *---------------------------------------------------------------------------*/

/*>*******************************(*)*******************************<*/
// This file is for the emulator.
// It is included from GXVert.h, and thus it must be placed in the
// same directory as that file.
/*>*******************************(*)*******************************<*/

/*>*******************************(*)*******************************<*/
// These calls are not implemented.  They're just dummies.
// They don't need to be implemented, in fact.  They're only
// defined here to make GXVert.h work.
/*>*******************************(*)*******************************<*/
void EmGXCmd1u8( u8 x );
void EmGXCmd1u16( u16 x );
void EmGXCmd1u32( u32 x );
void EmGXParam1u8( u8 x );
void EmGXParam1u16( u16 x );
void EmGXParam1u32( u32 x );
void EmGXParam1s8( s8 x );
void EmGXParam1s16( s16 x );
void EmGXParam1s32( s32 x );
void EmGXParam1f32( f32 x );
void EmGXParam3f32( f32 x, f32 y, f32 z );
void EmGXParam4f32( f32 x, f32 y, f32 z, f32 w );

/*>*******************************(*)*******************************<*/
// The rest of these calls are implemented in the emulator.
/*>*******************************(*)*******************************<*/
void EmGXPosition3f32         ( float x, float y, float z );
void EmGXPosition3u16         ( u16 x, u16 y, u16 z );
void EmGXPosition3s16         ( s16 x, s16 y, s16 z );
void EmGXPosition3u8          ( u8 x, u8 y, u8 z );
void EmGXPosition3s8          ( s8 x, s8 y, s8 z );
void EmGXPosition2f32         ( float x, float y );
void EmGXPosition2u16         ( u16 x, u16 y );
void EmGXPosition2s16         ( s16 x, s16 y );
void EmGXPosition2u8          ( u8 x, u8 y );
void EmGXPosition2s8          ( s8 x, s8 y );
void EmGXPosition1x16         ( u16 idx );
void EmGXPosition1x8          ( u8 idx );

/*>*******************************(*)*******************************<*/
void EmGXNormal3f32           ( f32 x, f32 y, f32 z );
void EmGXNormal3s16           ( s16 x, s16 y, s16 z );
void EmGXNormal3s8            ( s8 x, s8 y, s8 z );
void EmGXNormal1x16           ( u16 idx );
void EmGXNormal1x8            ( u8 idx );

/*>*******************************(*)*******************************<*/
void EmGXColor4u8             ( u8 r, u8 g, u8 b, u8 a );
void EmGXColor3u8             ( u8 r, u8 g, u8 b );
void EmGXColor1u32            ( u32 rgba );
void EmGXColor1u16            ( u16 rgba );
void EmGXColor1x16            ( u16 idx );
void EmGXColor1x8             ( u8 idx );

/*>*******************************(*)*******************************<*/
void EmGXTexCoord2f32         ( f32 s, f32 t );
void EmGXTexCoord2s16         ( s16 s, s16 t );
void EmGXTexCoord2u16         ( u16 s, u16 t );
void EmGXTexCoord2s8          ( s8 s, s8 t );
void EmGXTexCoord2u8          ( u8 s, u8 t );
void EmGXTexCoord1f32         ( f32 s );
void EmGXTexCoord1s16         ( s16 s );
void EmGXTexCoord1u16         ( u16 s );
void EmGXTexCoord1s8          ( s8 s );
void EmGXTexCoord1u8          ( u8 s );
void EmGXTexCoord1x16         ( u16 idx );
void EmGXTexCoord1x8          ( u8 idx );

/*>*******************************(*)*******************************<*/
void EmGXMatrixIndex1u8       ( u32 idx );

/********************************/
typedef u8 GXBool;

/********************************/
#define GX_TRUE        ((GXBool)1)
#define GX_FALSE       ((GXBool)0)
#define GX_ENABLE      ((GXBool)1)
#define GX_DISABLE     ((GXBool)0)

/********************************/
typedef enum _GXAttr
{
    GX_VA_PNMTXIDX = 0,    // position/normal matrix index
    GX_VA_TEX0MTXIDX,      // texture 0 matrix index
    GX_VA_TEX1MTXIDX,      // texture 1 matrix index
    GX_VA_TEX2MTXIDX,      // texture 2 matrix index
    GX_VA_TEX3MTXIDX,      // texture 3 matrix index
    GX_VA_TEX4MTXIDX,      // texture 4 matrix index
    GX_VA_TEX5MTXIDX,      // texture 5 matrix index
    GX_VA_TEX6MTXIDX,      // texture 6 matrix index
    GX_VA_TEX7MTXIDX,      // texture 7 matrix index
    GX_VA_POS      = 9,    // position
    GX_VA_NRM,             // normal
    GX_VA_CLR0,            // color 0
    GX_VA_CLR1,            // color 1
    GX_VA_TEX0,            // input texture coordinate 0
    GX_VA_TEX1,            // input texture coordinate 1
    GX_VA_TEX2,            // input texture coordinate 2
    GX_VA_TEX3,            // input texture coordinate 3
    GX_VA_TEX4,            // input texture coordinate 4
    GX_VA_TEX5,            // input texture coordinate 5
    GX_VA_TEX6,            // input texture coordinate 6
    GX_VA_TEX7,            // input texture coordinate 7

    GX_POS_MTX_ARRAY,      // position matrix array pointer
    GX_NRM_MTX_ARRAY,      // normal matrix array pointer
    GX_TEX_MTX_ARRAY,      // texture matrix array pointer
    GX_LIGHT_ARRAY,        // light parameter array pointer
    GX_VA_NBT,             // normal, bi-normal, tangent 
    GX_VA_MAX_ATTR,        // maximum number of vertex attributes

    GX_VA_NULL     = 0xff  // NULL attribute (to mark end of lists)

} GXAttr;

#define GX_MAX_VTXDESC              GX_VA_MAX_ATTR
#define GX_MAX_VTXDESCLIST_SZ       (GX_MAX_VTXDESC+1)    // +1 for GX_VA_NULL

#define GX_MAX_VTXATTRFMT           GX_VA_MAX_ATTR
#define GX_MAX_VTXATTRFMTLIST_SZ    (GX_MAX_VTXATTRFMT+1) // +1 for GX_VA_NULL

#define GX_MAX_VTXARRAY             16

/********************************/
typedef enum _GXVtxFmt
{
    GX_VTXFMT0 = 0,
    GX_VTXFMT1,
    GX_VTXFMT2,
    GX_VTXFMT3,
    GX_VTXFMT4,
    GX_VTXFMT5,
    GX_VTXFMT6,
    GX_VTXFMT7,
    GX_MAX_VTXFMT

} GXVtxFmt;

#define GX_MAX_VTXFMT               GX_MAX_VTXFMT

/********************************/
typedef enum _GXAttrType
{
    GX_NONE    = 0,
    GX_DIRECT,
    GX_INDEX8,
    GX_INDEX16

} GXAttrType;

/********************************/
typedef enum _GXTexCoordID
{
    GX_TEXCOORD0 = 0x0,    	// generated texture coordinate 0
    GX_TEXCOORD1, 		// generated texture coordinate 1
    GX_TEXCOORD2, 		// generated texture coordinate 2
    GX_TEXCOORD3, 		// generated texture coordinate 3
    GX_TEXCOORD4, 		// generated texture coordinate 4
    GX_TEXCOORD5, 		// generated texture coordinate 5
    GX_TEXCOORD6, 		// generated texture coordinate 6
    GX_TEXCOORD7, 		// generated texture coordinate 7
    GX_MAX_TEXCOORD = 8,
    GX_TEXCOORD_NULL = 0xff

} GXTexCoordID;

#define GX_MAX_TEXCOORDGEN          GX_MAX_TEXCOORD

/********************************/
typedef enum _GXTexGenType
{
    GX_TG_MTX3x4 = 0,
    GX_TG_MTX2x4,
    GX_TG_BUMP0,
    GX_TG_BUMP1,
    GX_TG_BUMP2,
    GX_TG_BUMP3,
    GX_TG_BUMP4,
    GX_TG_BUMP5,
    GX_TG_BUMP6,
    GX_TG_BUMP7,
    GX_TG_SRTG

} GXTexGenType;

/********************************/
typedef enum _GXTexGenSrc
{
    GX_TG_POS = 0,
    GX_TG_NRM,
	GX_TG_BINRM,
	GX_TG_TANGENT,
    GX_TG_TEX0,
    GX_TG_TEX1,
    GX_TG_TEX2,
    GX_TG_TEX3,
    GX_TG_TEX4,
    GX_TG_TEX5,
    GX_TG_TEX6,
    GX_TG_TEX7,
    GX_TG_TEXCOORD0,
    GX_TG_TEXCOORD1,
    GX_TG_TEXCOORD2,
    GX_TG_TEXCOORD3,
    GX_TG_TEXCOORD4,
    GX_TG_TEXCOORD5,
    GX_TG_TEXCOORD6,
    GX_TG_COLOR0,
    GX_TG_COLOR1

} GXTexGenSrc;

/********************************/
typedef enum _GXCompCnt
{
#if ( GX_REV == 1 )
    GX_POS_XY    = 0,
    GX_POS_XYZ   = 1,
    GX_NRM_XYZ   = 0,
    GX_NRM_NBT   = 1, // not really used, just to make api consistent
    GX_CLR_RGB   = 0,
    GX_CLR_RGBA  = 1,
    GX_TEX_S     = 0,
    GX_TEX_ST    = 1

#else // ( GX_REV >= 2 )
    GX_POS_XY    = 0,
    GX_POS_XYZ   = 1,
    GX_NRM_XYZ   = 0,
    GX_NRM_NBT   = 1, // one index per NBT
    GX_NRM_NBT3  = 2, // one index per each of N/B/T
    GX_CLR_RGB   = 0,
    GX_CLR_RGBA  = 1,
    GX_TEX_S     = 0,
    GX_TEX_ST    = 1

#endif
} GXCompCnt;

/********************************/
typedef enum _GXCompType
{
    GX_U8  = 0,
    GX_S8  = 1,
    GX_U16 = 2,
    GX_S16 = 3,
    GX_F32 = 4,

    GX_RGB565 = 0,
    GX_RGB8   = 1,
    GX_RGBX8  = 2,
    GX_RGBA4  = 3,
    GX_RGBA6  = 4,
    GX_RGBA8  = 5

} GXCompType;

/********************************/
typedef enum _GXChannelID
{
    GX_COLOR0,
    GX_COLOR1,
    GX_ALPHA0,
    GX_ALPHA1,
    GX_COLOR0A0,          // Color 0 + Alpha 0
    GX_COLOR1A1,          // Color 1 + Alpha 1
	GX_COLOR_ZERO,        // RGBA = 0
	GX_ALPHA_BUMP,        // bump alpha 0-248, RGB=0
	GX_ALPHA_BUMPN,       // normalized bump alpha, 0-255, RGB=0
    GX_COLOR_NULL = 0xff

} GXChannelID;

/********************************/
typedef enum _GXColorSrc
{
    GX_SRC_REG = 0,
    GX_SRC_VTX

} GXColorSrc;

/********************************/
typedef enum _GXLightID
{
    GX_LIGHT0     = 0x001,
    GX_LIGHT1     = 0x002,
    GX_LIGHT2     = 0x004,
    GX_LIGHT3     = 0x008,
    GX_LIGHT4     = 0x010,
    GX_LIGHT5     = 0x020,
    GX_LIGHT6     = 0x040,
    GX_LIGHT7     = 0x080,
    GX_MAX_LIGHT  = 0x100,
    GX_LIGHT_NULL = 0x000
} GXLightID;

/********************************/
typedef enum _GXDiffuseFn
{
    GX_DF_NONE = 0,
    GX_DF_SIGN,
    GX_DF_CLAMP

} GXDiffuseFn;

/********************************/
typedef enum _GXAttnFn
{
    GX_AF_SPEC = 0,    // use specular attenuation
    GX_AF_SPOT = 1,    // use distance/spotlight attenuation
    GX_AF_NONE         // attenuation is off

} GXAttnFn;

/********************************/
typedef enum _GXSpotFn
{
    GX_SP_OFF = 0,
    GX_SP_FLAT,
    GX_SP_COS,
    GX_SP_COS2,
	GX_SP_SHARP,
	GX_SP_RING1,
	GX_SP_RING2
} GXSpotFn;

/********************************/
typedef enum _GXDistAttnFn
{
    GX_DA_OFF = 0,
    GX_DA_GENTLE,
    GX_DA_MEDIUM,
    GX_DA_STEEP
} GXDistAttnFn;

/********************************/
typedef enum _GXPosNrmMtx
{
    GX_PNMTX0 =  0,
    GX_PNMTX1 =  3,
    GX_PNMTX2 =  6,
    GX_PNMTX3 =  9,
    GX_PNMTX4 = 12,
    GX_PNMTX5 = 15,
    GX_PNMTX6 = 18,
    GX_PNMTX7 = 21,
    GX_PNMTX8 = 24,
    GX_PNMTX9 = 27

} GXPosNrmMtx;

/********************************/
typedef enum _GXTexMtx
{
    GX_TEXMTX0  = 30,
    GX_TEXMTX1  = 33,
    GX_TEXMTX2  = 36,
    GX_TEXMTX3  = 39,
    GX_TEXMTX4  = 42,
    GX_TEXMTX5  = 45,
    GX_TEXMTX6  = 48,
    GX_TEXMTX7  = 51,
    GX_TEXMTX8  = 54,
    GX_TEXMTX9  = 57,
    GX_IDENTITY = 60

} GXTexMtx;

/********************************/
#if ( GX_REV != 1 ) // Revision 2 or greater only
typedef enum _GXPTTexMtx
{
    GX_PTTEXMTX0  = 64,
    GX_PTTEXMTX1  = 67,
    GX_PTTEXMTX2  = 70,
    GX_PTTEXMTX3  = 73,
    GX_PTTEXMTX4  = 76,
    GX_PTTEXMTX5  = 79,
    GX_PTTEXMTX6  = 82,
    GX_PTTEXMTX7  = 85,
    GX_PTTEXMTX8  = 88,
    GX_PTTEXMTX9  = 91,
    GX_PTTEXMTX10 = 94,
    GX_PTTEXMTX11 = 97,
    GX_PTTEXMTX12 = 100,
    GX_PTTEXMTX13 = 103,
    GX_PTTEXMTX14 = 106,
    GX_PTTEXMTX15 = 109,
    GX_PTTEXMTX16 = 112,
    GX_PTTEXMTX17 = 115,
    GX_PTTEXMTX18 = 118,
    GX_PTTEXMTX19 = 121,
    GX_PTIDENTITY = 125

} GXPTTexMtx;
#endif // ( GX_REV != 1 )

/********************************/
typedef enum _GXTexMtxType
{
    GX_MTX3x4 = 0,
    GX_MTX2x4

} GXTexMtxType;

/********************************/
typedef enum _GXPrimitive
{
    GX_POINTS        = 0xb8,
    GX_LINES         = 0xa8,
    GX_LINESTRIP     = 0xb0,
    GX_TRIANGLES     = 0x90,
    GX_TRIANGLESTRIP = 0x98,
    GX_TRIANGLEFAN   = 0xa0,
    GX_QUADS         = 0x80

} GXPrimitive;

/********************************/
typedef enum _GXTexOffset
{
    GX_TO_ZERO,
    GX_TO_SIXTEENTH,
    GX_TO_EIGHTH,
    GX_TO_FOURTH,
    GX_TO_HALF,
    GX_TO_ONE,
    GX_MAX_TEXOFFSET

} GXTexOffset;

/********************************/
typedef enum _GXCullMode
{
    GX_CULL_NONE,
    GX_CULL_FRONT,
    GX_CULL_BACK,
    GX_CULL_ALL

} GXCullMode;

/********************************/
typedef enum _GXClipMode
{
    // Note: these are (by design) backwards of typical enable/disables!
    GX_CLIP_ENABLE = 0,
    GX_CLIP_DISABLE = 1

} GXClipMode;

/********************************/
typedef enum _GXTexWrapMode
{
    GX_CLAMP,
    GX_REPEAT,
    GX_MIRROR,
    GX_MAX_TEXWRAPMODE

} GXTexWrapMode;

/********************************/
typedef enum _GXTexFilter
{
    GX_NEAR,
    GX_LINEAR,
    GX_NEAR_MIP_NEAR,
    GX_LIN_MIP_NEAR,
    GX_NEAR_MIP_LIN,
    GX_LIN_MIP_LIN

} GXTexFilter;

/********************************/
typedef enum _GXCITexFmt
{
    GX_TF_C4    = 0x8,
    GX_TF_C8    = 0x9,
    GX_TF_C14X2 = 0xa

} GXCITexFmt;

/********************************/
typedef enum _GXTexFmt
{
#if ( GX_REV == 1 )
    GX_TF_I4     = 0x0,
    GX_TF_I8     = 0x1,
    GX_TF_IA4    = 0x2,
    GX_TF_IA8    = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8  = 0x6,
    GX_TF_CMPR   = 0xE,
    GX_TF_A8     = (0x20 | GX_TF_I8), 
    GX_TF_Z8     = (0x10 | GX_TF_I8),
    GX_TF_Z16    = (0x10 | GX_TF_IA8),
    GX_TF_Z24X8  = (0x10 | GX_TF_RGBA8)

#else // ( GX_REV >= 2 )

#define _GX_TF_CTF     0x20 /* copy-texture-format only */
#define _GX_TF_ZTF     0x10 /* Z-texture-format */

    GX_TF_I4     = 0x0,
    GX_TF_I8     = 0x1,
    GX_TF_IA4    = 0x2,
    GX_TF_IA8    = 0x3,
    GX_TF_RGB565 = 0x4,
    GX_TF_RGB5A3 = 0x5,
    GX_TF_RGBA8  = 0x6,
    GX_TF_CMPR   = 0xE,

    GX_CTF_R4    = 0x0 | _GX_TF_CTF,
    GX_CTF_RA4   = 0x2 | _GX_TF_CTF,
    GX_CTF_RA8   = 0x3 | _GX_TF_CTF,
    GX_CTF_YUVA8 = 0x6 | _GX_TF_CTF,
    GX_CTF_A8    = 0x7 | _GX_TF_CTF,
    GX_CTF_R8    = 0x8 | _GX_TF_CTF,
    GX_CTF_G8    = 0x9 | _GX_TF_CTF,
    GX_CTF_B8    = 0xA | _GX_TF_CTF,
    GX_CTF_RG8   = 0xB | _GX_TF_CTF,
    GX_CTF_GB8   = 0xC | _GX_TF_CTF,

    GX_TF_Z8     = 0x1 | _GX_TF_ZTF,
    GX_TF_Z16    = 0x3 | _GX_TF_ZTF,
    GX_TF_Z24X8  = 0x6 | _GX_TF_ZTF,

    GX_CTF_Z4    = 0x0 | _GX_TF_ZTF | _GX_TF_CTF,
    GX_CTF_Z8M   = 0x9 | _GX_TF_ZTF | _GX_TF_CTF,
    GX_CTF_Z8L   = 0xA | _GX_TF_ZTF | _GX_TF_CTF,
    GX_CTF_Z16L  = 0xC | _GX_TF_ZTF | _GX_TF_CTF,

    GX_TF_A8     = GX_CTF_A8 // to keep compatibility
#endif
} GXTexFmt;

/********************************/
typedef enum _GXTlutFmt
{
    GX_TL_IA8    = 0x0,
    GX_TL_RGB565 = 0x1,
    GX_TL_RGB5A3 = 0x2,
    GX_MAX_TLUTFMT

} GXTlutFmt;

/********************************/
typedef enum _GXTlutSize
{
    GX_TLUT_16 = 1,	// number of 16 entry blocks.
    GX_TLUT_32 = 2,
    GX_TLUT_64 = 4,
    GX_TLUT_128 = 8,
    GX_TLUT_256 = 16,
    GX_TLUT_512 = 32,
    GX_TLUT_1K = 64,
    GX_TLUT_2K = 128,
    GX_TLUT_4K = 256,
    GX_TLUT_8K = 512,
    GX_TLUT_16K = 1024

} GXTlutSize;

/********************************/
typedef enum _GXTlut
{
    // default 256-entry TLUTs
    GX_TLUT0 = 0,
    GX_TLUT1,
    GX_TLUT2,
    GX_TLUT3,
    GX_TLUT4,
    GX_TLUT5,
    GX_TLUT6,
    GX_TLUT7,
    GX_TLUT8,
    GX_TLUT9,
    GX_TLUT10,
    GX_TLUT11,
    GX_TLUT12,
    GX_TLUT13,
    GX_TLUT14,
    GX_TLUT15,
    GX_BIGTLUT0,
    GX_BIGTLUT1,
    GX_BIGTLUT2,
    GX_BIGTLUT3

} GXTlut;

/********************************/
typedef enum _GXTexMapID
{
    GX_TEXMAP0,
    GX_TEXMAP1,
    GX_TEXMAP2,
    GX_TEXMAP3,
    GX_TEXMAP4,
    GX_TEXMAP5,
    GX_TEXMAP6,
    GX_TEXMAP7,
    GX_MAX_TEXMAP,

    GX_TEXMAP_NULL = 0xff,
    GX_TEX_DISABLE = 0x100	// mask: disables texture look up

} GXTexMapID;

#define GX_MAX_TEXMAPS      GX_MAX_TEXMAP

/********************************/
typedef enum _GXTexCacheSize
{
    GX_TEXCACHE_32K,
    GX_TEXCACHE_128K,
    GX_TEXCACHE_512K,
    GX_TEXCACHE_NONE

} GXTexCacheSize;

/********************************/
typedef enum _GXIndTexFormat
{
    GX_ITF_8,		// 8 bit texture offsets.
    GX_ITF_5,		// 5 bit texture offsets.
    GX_ITF_4,		// 4 bit texture offsets.
    GX_ITF_3,		// 3 bit texture offsets.
    GX_MAX_ITFORMAT

} GXIndTexFormat;

/********************************/
typedef enum _GXIndTexBiasSel
{
    GX_ITB_NONE,	
    GX_ITB_S,
    GX_ITB_T,
    GX_ITB_ST,
    GX_ITB_U,
    GX_ITB_SU,
    GX_ITB_TU,
    GX_ITB_STU,
    GX_MAX_ITBIAS

} GXIndTexBiasSel;

/********************************/
typedef enum _GXIndTexAlphaSel
{
    GX_ITBA_OFF,
    GX_ITBA_S,
    GX_ITBA_T,
    GX_ITBA_U,
    GX_MAX_ITBALPHA

} GXIndTexAlphaSel;

/********************************/
typedef enum _GXIndTexMtxID
{
    GX_ITM_OFF,
    GX_ITM_0,
    GX_ITM_1,
    GX_ITM_2,
    GX_ITM_S0 = 5,
    GX_ITM_S1,
    GX_ITM_S2,
    GX_ITM_T0 = 9,
    GX_ITM_T1,
    GX_ITM_T2

} GXIndTexMtxID;

/********************************/
typedef enum _GXIndTexWrap
{
    GX_ITW_OFF,		// no wrapping
    GX_ITW_256,		// wrap 256
    GX_ITW_128,		// wrap 128
    GX_ITW_64, 		// wrap 64
    GX_ITW_32, 		// wrap 32
    GX_ITW_16, 		// wrap 16
    GX_ITW_0, 		// wrap 0
    GX_MAX_ITWRAP

} GXIndTexWrap;

/********************************/
typedef enum _GXIndTexScale
{
    GX_ITS_1,		// Scale by 1.
    GX_ITS_2,		// Scale by 1/2.
    GX_ITS_4,		// Scale by 1/4.
    GX_ITS_8,		// Scale by 1/8.
    GX_ITS_16,		// Scale by 1/16.
    GX_ITS_32,		// Scale by 1/32.
    GX_ITS_64,		// Scale by 1/64.
    GX_ITS_128,		// Scale by 1/128.
    GX_ITS_256,		// Scale by 1/256.
    GX_MAX_ITSCALE

} GXIndTexScale;

/********************************/
typedef enum _GXIndTexStageID
{
    GX_INDTEXSTAGE0,	// Indirect Texture Stage Names.
    GX_INDTEXSTAGE1,
    GX_INDTEXSTAGE2,
    GX_INDTEXSTAGE3,
    GX_MAX_INDTEXSTAGE

} GXIndTexStageID;

/********************************/
typedef enum _GXTevStageID
{
    GX_TEVSTAGE0,
    GX_TEVSTAGE1,
    GX_TEVSTAGE2,
    GX_TEVSTAGE3,
    GX_TEVSTAGE4,
    GX_TEVSTAGE5,
    GX_TEVSTAGE6,
    GX_TEVSTAGE7,
    GX_TEVSTAGE8,
    GX_TEVSTAGE9,
    GX_TEVSTAGE10,
    GX_TEVSTAGE11,
    GX_TEVSTAGE12,
    GX_TEVSTAGE13,
    GX_TEVSTAGE14,
    GX_TEVSTAGE15,
    GX_MAX_TEVSTAGE

} GXTevStageID;

#define GX_MAX_TEVSTAGES            GX_MAX_TEVSTAGE

/********************************/
typedef enum _GXTevRegID
{
    GX_TEVPREV = 0,
    GX_TEVREG0,
    GX_TEVREG1,
    GX_TEVREG2,
    GX_MAX_TEVREG

} GXTevRegID;

/********************************/
typedef enum _GXTevOp
{
#if ( GX_REV == 1 )
    GX_TEV_ADD,
    GX_TEV_SUB

#else // ( GX_REV >= 2 )
    GX_TEV_ADD = 0,
    GX_TEV_SUB = 1,
    
    GX_TEV_COMP_R8_GT    = 8,
    GX_TEV_COMP_R8_EQ    = 9,
    GX_TEV_COMP_GR16_GT  = 10,
    GX_TEV_COMP_GR16_EQ  = 11,
    GX_TEV_COMP_BGR24_GT = 12,
    GX_TEV_COMP_BGR24_EQ = 13,
    GX_TEV_COMP_RGB8_GT  = 14,
    GX_TEV_COMP_RGB8_EQ  = 15,
    
    GX_TEV_COMP_A8_GT = GX_TEV_COMP_RGB8_GT, // for alpha channel
    GX_TEV_COMP_A8_EQ = GX_TEV_COMP_RGB8_EQ  // for alpha channel

#endif
} GXTevOp;

/********************************/
typedef enum _GXTevColorArg
{
#if ( GX_REV == 1 )
    GX_CC_CPREV,
    GX_CC_APREV,
    GX_CC_C0,
    GX_CC_A0,
    GX_CC_C1,
    GX_CC_A1,
    GX_CC_C2,
    GX_CC_A2,
    GX_CC_TEXC,
    GX_CC_TEXA,
    GX_CC_RASC,
    GX_CC_RASA,
    GX_CC_ONE,
    GX_CC_HALF,
    GX_CC_QUARTER,
    GX_CC_ZERO,

    GX_CC_TEXRRR,
    GX_CC_TEXGGG,
    GX_CC_TEXBBB

#else // ( GX_REV >= 2 )
    GX_CC_CPREV,
    GX_CC_APREV,
    GX_CC_C0,
    GX_CC_A0,
    GX_CC_C1,
    GX_CC_A1,
    GX_CC_C2,
    GX_CC_A2,
    GX_CC_TEXC,
    GX_CC_TEXA,
    GX_CC_RASC,
    GX_CC_RASA,
    GX_CC_ONE,
    GX_CC_HALF,
    GX_CC_KONST,
    GX_CC_ZERO

#ifndef GX_NO_LEGACY_HW1
    ,             // separator needed only in this case

    GX_CC_TEXRRR, // obsolete
    GX_CC_TEXGGG, // obsolete
    GX_CC_TEXBBB, // obsolete

    GX_CC_QUARTER = GX_CC_KONST // obsolete, to keep compatibility
#endif

#endif
} GXTevColorArg;

/********************************/
typedef enum _GXTevAlphaArg
{
#if ( GX_REV == 1 )
    GX_CA_APREV,
    GX_CA_A0,
    GX_CA_A1,
    GX_CA_A2,
    GX_CA_TEXA,
    GX_CA_RASA,
    GX_CA_ONE,
    GX_CA_ZERO

#else // ( GX_REV >= 2 )
    GX_CA_APREV,
    GX_CA_A0,
    GX_CA_A1,
    GX_CA_A2,
    GX_CA_TEXA,
    GX_CA_RASA,
    GX_CA_KONST,
    GX_CA_ZERO

#ifndef GX_NO_LEGACY_HW1
    ,                       // separator needed only in this case

    GX_CA_ONE = GX_CA_KONST // obsolete, to keep compatibility
#endif

#endif
} GXTevAlphaArg;

/********************************/
typedef enum _GXTevBias
{
    GX_TB_ZERO,
    GX_TB_ADDHALF,
    GX_TB_SUBHALF,
    GX_MAX_TEVBIAS

} GXTevBias;

/********************************/
typedef enum _GXTevClampMode
{
    GX_TC_LINEAR,
    GX_TC_GE,
    GX_TC_EQ,
    GX_TC_LE,
    GX_MAX_TEVCLAMPMODE

} GXTevClampMode;

/********************************/
#if ( GX_REV != 1 ) // GX Revision 2 or later only
typedef enum _GXTevKColorID
{
    GX_KCOLOR0 = 0,
    GX_KCOLOR1,
    GX_KCOLOR2,
    GX_KCOLOR3,
    GX_MAX_KCOLOR

} GXTevKColorID;
#endif // ( GX_REV != 1 )

/********************************/
#if ( GX_REV != 1 ) // GX Revision 2 or later only
typedef enum _GXTevKColorSel
{
    GX_TEV_KCSEL_8_8  = 0x00,
    GX_TEV_KCSEL_7_8  = 0x01,
    GX_TEV_KCSEL_6_8  = 0x02,
    GX_TEV_KCSEL_5_8  = 0x03,
    GX_TEV_KCSEL_4_8  = 0x04,
    GX_TEV_KCSEL_3_8  = 0x05,
    GX_TEV_KCSEL_2_8  = 0x06,
    GX_TEV_KCSEL_1_8  = 0x07,

    GX_TEV_KCSEL_1    = GX_TEV_KCSEL_8_8,
    GX_TEV_KCSEL_3_4  = GX_TEV_KCSEL_6_8,
    GX_TEV_KCSEL_1_2  = GX_TEV_KCSEL_4_8,
    GX_TEV_KCSEL_1_4  = GX_TEV_KCSEL_2_8,

    GX_TEV_KCSEL_K0   = 0x0C,
    GX_TEV_KCSEL_K1   = 0x0D,
    GX_TEV_KCSEL_K2   = 0x0E,
    GX_TEV_KCSEL_K3   = 0x0F,
    GX_TEV_KCSEL_K0_R = 0x10,
    GX_TEV_KCSEL_K1_R = 0x11,
    GX_TEV_KCSEL_K2_R = 0x12,
    GX_TEV_KCSEL_K3_R = 0x13,
    GX_TEV_KCSEL_K0_G = 0x14,
    GX_TEV_KCSEL_K1_G = 0x15,
    GX_TEV_KCSEL_K2_G = 0x16,
    GX_TEV_KCSEL_K3_G = 0x17,
    GX_TEV_KCSEL_K0_B = 0x18,
    GX_TEV_KCSEL_K1_B = 0x19,
    GX_TEV_KCSEL_K2_B = 0x1A,
    GX_TEV_KCSEL_K3_B = 0x1B,
    GX_TEV_KCSEL_K0_A = 0x1C,
    GX_TEV_KCSEL_K1_A = 0x1D,
    GX_TEV_KCSEL_K2_A = 0x1E,
    GX_TEV_KCSEL_K3_A = 0x1F

} GXTevKColorSel;
#endif // ( GX_REV != 1 )

/********************************/
#if ( GX_REV != 1 ) // GX Revision 2 or later only
typedef enum _GXTevKAlphaSel
{
    GX_TEV_KASEL_8_8  = 0x00,
    GX_TEV_KASEL_7_8  = 0x01,
    GX_TEV_KASEL_6_8  = 0x02,
    GX_TEV_KASEL_5_8  = 0x03,
    GX_TEV_KASEL_4_8  = 0x04,
    GX_TEV_KASEL_3_8  = 0x05,
    GX_TEV_KASEL_2_8  = 0x06,
    GX_TEV_KASEL_1_8  = 0x07,

    GX_TEV_KASEL_1    = GX_TEV_KASEL_8_8,
    GX_TEV_KASEL_3_4  = GX_TEV_KASEL_6_8,
    GX_TEV_KASEL_1_2  = GX_TEV_KASEL_4_8,
    GX_TEV_KASEL_1_4  = GX_TEV_KASEL_2_8,

    GX_TEV_KASEL_K0_R = 0x10,
    GX_TEV_KASEL_K1_R = 0x11,
    GX_TEV_KASEL_K2_R = 0x12,
    GX_TEV_KASEL_K3_R = 0x13,
    GX_TEV_KASEL_K0_G = 0x14,
    GX_TEV_KASEL_K1_G = 0x15,
    GX_TEV_KASEL_K2_G = 0x16,
    GX_TEV_KASEL_K3_G = 0x17,
    GX_TEV_KASEL_K0_B = 0x18,
    GX_TEV_KASEL_K1_B = 0x19,
    GX_TEV_KASEL_K2_B = 0x1A,
    GX_TEV_KASEL_K3_B = 0x1B,
    GX_TEV_KASEL_K0_A = 0x1C,
    GX_TEV_KASEL_K1_A = 0x1D,
    GX_TEV_KASEL_K2_A = 0x1E,
    GX_TEV_KASEL_K3_A = 0x1F

} GXTevKAlphaSel;
#endif // ( GX_REV != 1 )

/********************************/
#if ( GX_REV != 1 ) // GX Revision 2 or later only
typedef enum _GXTevSwapSel
{
    GX_TEV_SWAP0 = 0,
    GX_TEV_SWAP1,
    GX_TEV_SWAP2,
    GX_TEV_SWAP3,
    GX_MAX_TEVSWAP

} GXTevSwapSel;
#endif // ( GX_REV != 1 )

/********************************/
#if ( GX_REV != 1 ) // GX Revision 2 or later only
typedef enum _GXTevColorChan
{
    GX_CH_RED = 0,
    GX_CH_GREEN,
    GX_CH_BLUE,
    GX_CH_ALPHA

} GXTevColorChan;
#endif // ( GX_REV != 1 )

/********************************/
typedef enum _GXAlphaOp
{
    GX_AOP_AND,
    GX_AOP_OR,
    GX_AOP_XOR,
    GX_AOP_XNOR,
    GX_MAX_ALPHAOP

} GXAlphaOp;

/********************************/
typedef enum _GXTevScale
{
    GX_CS_SCALE_1,
    GX_CS_SCALE_2,
    GX_CS_SCALE_4,
    GX_CS_DIVIDE_2,
    GX_MAX_TEVSCALE

} GXTevScale;

/********************************/
typedef enum _GXFogType
{
    GX_FOG_NONE		     = 0x00,

    GX_FOG_PERSP_LIN     = 0x02,
    GX_FOG_PERSP_EXP     = 0x04,
    GX_FOG_PERSP_EXP2    = 0x05,
    GX_FOG_PERSP_REVEXP  = 0x06,
    GX_FOG_PERSP_REVEXP2 = 0x07,

    GX_FOG_ORTHO_LIN     = 0x0A,
    GX_FOG_ORTHO_EXP     = 0x0C,
    GX_FOG_ORTHO_EXP2    = 0x0D,
    GX_FOG_ORTHO_REVEXP  = 0x0E,
    GX_FOG_ORTHO_REVEXP2 = 0x0F,

    // For compatibility with former versions
    GX_FOG_LIN 		= GX_FOG_PERSP_LIN,
    GX_FOG_EXP		= GX_FOG_PERSP_EXP,
    GX_FOG_EXP2		= GX_FOG_PERSP_EXP2,
    GX_FOG_REVEXP  	= GX_FOG_PERSP_REVEXP,
    GX_FOG_REVEXP2 	= GX_FOG_PERSP_REVEXP2

} GXFogType;

/********************************/
typedef enum _GXBlendMode
{
#if ( GX_REV == 1 )
    GX_BM_NONE,
    GX_BM_BLEND,
    GX_BM_LOGIC,
    GX_MAX_BLENDMODE

#else // ( GX_REV >= 2 )
    GX_BM_NONE,
    GX_BM_BLEND,
    GX_BM_LOGIC,
    GX_BM_SUBTRACT,
    GX_MAX_BLENDMODE

#endif
} GXBlendMode;

/********************************/
typedef enum _GXBlendFactor
{
    GX_BL_ZERO,
    GX_BL_ONE,
    GX_BL_SRCCLR,
    GX_BL_INVSRCCLR,
    GX_BL_SRCALPHA,
    GX_BL_INVSRCALPHA,
    GX_BL_DSTALPHA,
    GX_BL_INVDSTALPHA,

    GX_BL_DSTCLR = GX_BL_SRCCLR,
    GX_BL_INVDSTCLR = GX_BL_INVSRCCLR

} GXBlendFactor;

/********************************/
typedef enum _GXCompare
{
    GX_NEVER,
    GX_LESS,
    GX_EQUAL,
    GX_LEQUAL,
    GX_GREATER,
    GX_NEQUAL,
    GX_GEQUAL,
    GX_ALWAYS

} GXCompare;

/********************************/
typedef enum _GXLogicOp
{
    GX_LO_CLEAR,
    GX_LO_AND,
    GX_LO_REVAND,
    GX_LO_COPY,
    GX_LO_INVAND,
    GX_LO_NOOP,
    GX_LO_XOR,
    GX_LO_OR,
    GX_LO_NOR,
    GX_LO_EQUIV,
    GX_LO_INV,
    GX_LO_REVOR,
    GX_LO_INVCOPY,
    GX_LO_INVOR,
    GX_LO_NAND,
    GX_LO_SET

} GXLogicOp;

/********************************/
typedef enum _GXPixelFmt
{
    GX_PF_RGB8_Z24,
    GX_PF_RGBA6_Z24,
    GX_PF_RGB565_Z16,
    GX_PF_Z24,
    GX_PF_Y8,
    GX_PF_U8,
    GX_PF_V8,
    GX_PF_YUV420

} GXPixelFmt;

/********************************/
typedef enum _GXZFmt16
{
    GX_ZC_LINEAR,
    GX_ZC_NEAR,
    GX_ZC_MID,
    GX_ZC_FAR

} GXZFmt16;

/********************************/
typedef enum _GXTevMode
{
    GX_MODULATE,
    GX_DECAL,
    GX_BLEND,
    GX_REPLACE,
    GX_PASSCLR

} GXTevMode;

/********************************/
typedef enum _GXGamma
{
    GX_GM_1_0,
    GX_GM_1_7,
    GX_GM_2_2

} GXGamma;

/********************************/
typedef enum _GXProjectionType
{
    GX_PERSPECTIVE,
    GX_ORTHOGRAPHIC

} GXProjectionType;


/********************************/
typedef enum _GXEvent
{
    GX_VCACHE_MISS_ALL,
    GX_VCACHE_MISS_POS,
    GX_VCACHE_MISS_NRM

} GXEvent;

/********************************/
typedef enum _GXFBClamp
{
    GX_CLAMP_NONE,
    GX_CLAMP_TOP,
    GX_CLAMP_BOTTOM

} GXFBClamp;

/********************************/
typedef enum _GXAnisotropy
{
    GX_ANISO_1,
    GX_ANISO_2,
    GX_ANISO_4,
    GX_MAX_ANISOTROPY

} GXAnisotropy;

/********************************/
typedef enum _GXZTexOp
{
    GX_ZT_DISABLE,
    GX_ZT_ADD,
    GX_ZT_REPLACE,
    GX_MAX_ZTEXOP

} GXZTexOp;

/********************************/
typedef enum _GXAlphaReadMode
{
    GX_READ_00,
    GX_READ_FF,
    GX_READ_NONE

} GXAlphaReadMode;

/********************************/
typedef enum _GXPerf0
{
    GX_PERF0_VERTICES,
    GX_PERF0_CLIP_VTX,
    GX_PERF0_CLIP_CLKS,
    GX_PERF0_XF_WAIT_IN,
    GX_PERF0_XF_WAIT_OUT,
    GX_PERF0_XF_XFRM_CLKS,
    GX_PERF0_XF_LIT_CLKS,
    GX_PERF0_XF_BOT_CLKS,
    GX_PERF0_XF_REGLD_CLKS,
    GX_PERF0_XF_REGRD_CLKS,
    GX_PERF0_CLIP_RATIO,

    GX_PERF0_TRIANGLES,
    GX_PERF0_TRIANGLES_CULLED,
    GX_PERF0_TRIANGLES_PASSED,
    GX_PERF0_TRIANGLES_SCISSORED,
    GX_PERF0_TRIANGLES_0TEX,
    GX_PERF0_TRIANGLES_1TEX,
    GX_PERF0_TRIANGLES_2TEX,
    GX_PERF0_TRIANGLES_3TEX,
    GX_PERF0_TRIANGLES_4TEX,
    GX_PERF0_TRIANGLES_5TEX,
    GX_PERF0_TRIANGLES_6TEX,
    GX_PERF0_TRIANGLES_7TEX,
    GX_PERF0_TRIANGLES_8TEX,
    GX_PERF0_TRIANGLES_0CLR,
    GX_PERF0_TRIANGLES_1CLR,
    GX_PERF0_TRIANGLES_2CLR,

    GX_PERF0_QUAD_0CVG,
    GX_PERF0_QUAD_NON0CVG,
    GX_PERF0_QUAD_1CVG,
    GX_PERF0_QUAD_2CVG,
    GX_PERF0_QUAD_3CVG,
    GX_PERF0_QUAD_4CVG,
    GX_PERF0_AVG_QUAD_CNT,

    GX_PERF0_CLOCKS,
    GX_PERF0_NONE

} GXPerf0;

/********************************/
typedef enum _GXPerf1
{
    GX_PERF1_TEXELS,
    GX_PERF1_TX_IDLE,
    GX_PERF1_TX_REGS,
    GX_PERF1_TX_MEMSTALL,
    GX_PERF1_TC_CHECK1_2,
    GX_PERF1_TC_CHECK3_4,
    GX_PERF1_TC_CHECK5_6,
    GX_PERF1_TC_CHECK7_8,
    GX_PERF1_TC_MISS,

    GX_PERF1_VC_ELEMQ_FULL,
    GX_PERF1_VC_MISSQ_FULL,
    GX_PERF1_VC_MEMREQ_FULL,
    GX_PERF1_VC_STATUS7,
    GX_PERF1_VC_MISSREP_FULL,
    GX_PERF1_VC_STREAMBUF_LOW,
    GX_PERF1_VC_ALL_STALLS,
    GX_PERF1_VERTICES,

    GX_PERF1_FIFO_REQ,
    GX_PERF1_CALL_REQ,
    GX_PERF1_VC_MISS_REQ,
    GX_PERF1_CP_ALL_REQ,

    GX_PERF1_CLOCKS,
    GX_PERF1_NONE

} GXPerf1;

/********************************/
typedef enum _GXVCachePerf
{
    GX_VC_POS,
    GX_VC_NRM,
    GX_VC_CLR0,
    GX_VC_CLR1,
    GX_VC_TEX0,
    GX_VC_TEX1,
    GX_VC_TEX2,
    GX_VC_TEX3,
    GX_VC_TEX4,
    GX_VC_TEX5,
    GX_VC_TEX6,
    GX_VC_TEX7,
    GX_VC_ALL = 0xf

} GXVCachePerf;

/********************************/
typedef enum _GXCopyMode
{
    GX_COPY_PROGRESSIVE = 0,
    GX_COPY_INTLC_EVEN  = 2,
    GX_COPY_INTLC_ODD   = 3

} GXCopyMode;

/********************************/
typedef enum _GXMiscToken
{
    GX_MT_XF_FLUSH           = 1,
    GX_MT_DL_SAVE_CONTEXT    = 2,
    GX_MT_ABORT_WAIT_COPYOUT = 3, 
    GX_MT_NULL               = 0

} GXMiscToken;

/********************************/
typedef enum _GXXFFlushVal
{
    GX_XF_FLUSH_NONE  = 0,
    GX_XF_FLUSH_SAFE  = 8

} GXXFFlushVal;

/********************************/
// Compile-time checks to ensure that enumerations are compiled
// as 32-bit integers.  If your build breaks at this line,
// please ensure that you enable the "enumerations are integers"
// option for the compiler.

#define GXCTASSERT(cond)  int GXCTASSERT( int assertion_failed[ (cond) != 0 ] )

GXCTASSERT(sizeof(GXAttrType) == sizeof(u32));


// Minimum size for any FIFO is 64k
// The hi watermark is automatically set to fifosize - 16k,
// large enough for a full locked cache DMA.
#define GX_FIFO_MINSIZE             (64*1024)
#define GX_FIFO_HI_WATERMARK_BUFFER (16*1024)

// Placeholder structure for GXFifoObj.  Actual structure members are private.
#define GX_FIFO_OBJ_SIZE            128

typedef struct{
    u8      pad[GX_FIFO_OBJ_SIZE];
} GXFifoObj;

typedef void (*GXBreakPtCallback)(void);
    

/*---------------------------------------------------------------------------*
  Get APIs
 *---------------------------------------------------------------------------*/
void GXGetGPStatus(
    GXBool* overhi,
    GXBool* underlow,
    GXBool* readIdle,
    GXBool* cmdIdle,
    GXBool* brkpt);
    
void GXGetFifoStatus(
    GXFifoObj*  fifo,
    GXBool*     overhi,
    GXBool*     underlow,
    u32*        fifoCount,
    GXBool*     cpu_write,
    GXBool*     gp_read,
    GXBool*     fifowrap);

void GXGetFifoPtrs(
    GXFifoObj*  fifo,
    void**      readPtr,
    void**      writePtr );

GXFifoObj* GXGetCPUFifo( void );
GXFifoObj* GXGetGPFifo( void );

void* GXGetFifoBase( const GXFifoObj* fifo);
u32   GXGetFifoSize( const GXFifoObj* fifo);
void  GXGetFifoLimits( const GXFifoObj* fifo, u32* hi, u32* lo);

/*---------------------------------------------------------------------------*
  Breakpoint APIs
 *---------------------------------------------------------------------------*/
GXBreakPtCallback GXSetBreakPtCallback( GXBreakPtCallback cb );

void GXEnableBreakPt(
    void*       breakPtr );

void GXDisableBreakPt( void );


/*---------------------------------------------------------------------------*
  Init FIFO APIs
 *---------------------------------------------------------------------------*/
void GXInitFifoBase(
    GXFifoObj*  fifo,
    void*       base,
    u32         size );

void GXInitFifoPtrs(
    GXFifoObj*  fifo,
    void*       readPtr,
    void*       writePtr );

void GXInitFifoLimits(
    GXFifoObj*  fifo,
    u32         hiWaterMark,
    u32         loWaterMark );


/*---------------------------------------------------------------------------*
  Attaching FIFOs to CPU/GP
 *---------------------------------------------------------------------------*/
void GXSetCPUFifo   ( GXFifoObj* fifo );
void GXSetGPFifo    ( GXFifoObj* fifo );    
void GXSaveCPUFifo  ( GXFifoObj* fifo );    
void GXSaveGPFifo   ( GXFifoObj* fifo );    


/*---------------------------------------------------------------------------*
  Redirecting write gather pipe
 *---------------------------------------------------------------------------*/
volatile void*   GXRedirectWriteGatherPipe   ( void * ptr );
void             GXRestoreWriteGatherPipe    ( void );


/*---------------------------------------------------------------------------*
  GX thread that will be interrupted by FIFO handlers in immediate mode
 *---------------------------------------------------------------------------*/
os::OSThread*   GXSetCurrentGXThread ( void );
os::OSThread*   GXGetCurrentGXThread ( void );



/*---------------------------------------------------------------------------*
  Overflow counter API
 *---------------------------------------------------------------------------*/
u32 GXGetOverflowCount      ( void );
u32 GXResetOverflowCount    ( void );
    
    

/*---------------------------------------------------------------------------*
  EPPC Emulation
 *---------------------------------------------------------------------------*/
#ifndef  EMU

#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>

void __GXDumpFifo(
    BOOL        full);

void __GXWriteFifo(
    u8*         ptr,
    s32         size,
    OSContext*  context);

void __GXWritePI(
    u32         cmd,
    u32         ea,
    u32         data[8],
    OSContext*  context);

// for extensive testing of watermark triggers
void __GXInsaneWatermark();
    

#endif  // !EMU

/*---------------------------------------------------------------------------*/
/*  Render Modes                                                             */
/*    (see the bottom of this file for actual settings used for each         */
/*     render mode)                                                          */
/*---------------------------------------------------------------------------*/
extern GXRenderModeObj GXNtsc240Ds;
extern GXRenderModeObj GXNtsc240DsAa;
extern GXRenderModeObj GXNtsc240Int;
extern GXRenderModeObj GXNtsc240IntAa;
extern GXRenderModeObj GXNtsc480IntDf;
extern GXRenderModeObj GXNtsc480Int;
extern GXRenderModeObj GXNtsc480IntAa;
extern GXRenderModeObj GXNtsc480Prog;
extern GXRenderModeObj GXNtsc480ProgSoft;
extern GXRenderModeObj GXNtsc480ProgAa;
extern GXRenderModeObj GXMpal240Ds;
extern GXRenderModeObj GXMpal240DsAa;
extern GXRenderModeObj GXMpal240Int;
extern GXRenderModeObj GXMpal240IntAa;
extern GXRenderModeObj GXMpal480IntDf;
extern GXRenderModeObj GXMpal480Int;
extern GXRenderModeObj GXMpal480IntAa;
extern GXRenderModeObj GXPal264Ds;
extern GXRenderModeObj GXPal264DsAa;
extern GXRenderModeObj GXPal264Int;
extern GXRenderModeObj GXPal264IntAa;
extern GXRenderModeObj GXPal528IntDf;
extern GXRenderModeObj GXPal528Int;
extern GXRenderModeObj GXPal524IntAa; // Reduced due to overlap requirement!
extern GXRenderModeObj GXEurgb60Hz240Ds;
extern GXRenderModeObj GXEurgb60Hz240DsAa;
extern GXRenderModeObj GXEurgb60Hz240Int;
extern GXRenderModeObj GXEurgb60Hz240IntAa;
extern GXRenderModeObj GXEurgb60Hz480IntDf;
extern GXRenderModeObj GXEurgb60Hz480Int;
extern GXRenderModeObj GXEurgb60Hz480IntAa;

/*---------------------------------------------------------------------------*/
void GXAdjustForOverscan ( const GXRenderModeObj *rmin, GXRenderModeObj *rmout,
                           u16 hor, u16 ver );
void GXSetDispCopySrc ( u16 left, u16 top, u16 wd, u16 ht );
void GXSetTexCopySrc ( u16 left, u16 top, u16 wd, u16 ht );
void GXSetDispCopyDst ( u16 wd, u16 ht );
void GXSetTexCopyDst ( u16 wd, u16 ht, GXTexFmt fmt, GXBool mipmap );

void GXSetDispCopyFrame2Field( GXCopyMode mode );
void GXSetCopyClamp( GXFBClamp clamp );
u32  GXSetDispCopyYScale( f32 vscale );
void GXSetCopyClear( GXColor clear_clr, u32 clear_z);
void GXSetCopyFilter( GXBool aa, const u8 sample_pattern[12][2], GXBool vf, const u8 vfilter[7] );
void GXSetDispCopyGamma( GXGamma gamma );

void GXCopyDisp( void *dest, GXBool clear );
void GXCopyTex ( void *dest, GXBool clear );

f32  GXGetYScaleFactor( u16 efbHeight, u16 xfbHeight );
u16  GXGetNumXfbLines( u16 efbHeight, f32 yScale );

void GXClearBoundingBox( void );
void GXReadBoundingBox ( u16 *left, u16 *top, u16 *right, u16 *bottom );

/*---------------------------------------------------------------------------*/

// The clear Z value is always in 24-bit format, regardless of pixel fmt.
// Thus the GX_MAX_Z16 is not really necessary.  You should not use it.
// It is included here only for backwards compatibility.

#define	GX_MAX_Z24	0x00ffffff

#define	GX_MAX_Z16	0x00ffffff

/*---------------------------------------------------------------------------*/

// Actual settings used for each GXRenderModeObj for developers' reference
//
// The following is intentionally ifdef'ed out to show each GXRenderModeObj
// settings to developers.
//

#if 0

GXRenderModeObj GXNtsc240Ds = 
{
    VI_TVMODE_NTSC_DS,      // viDisplayMode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC/2 - 480/2)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

     // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

     // vertical filter[7], 1/64 units, 6 bits each
      0,         // line n-1
      0,         // line n-1
     21,         // line n
     22,         // line n
     21,         // line n
      0,         // line n+1
      0          // line n+1
};
GXRenderModeObj GXNtsc240DsAa =
{
    VI_TVMODE_NTSC_DS,      // viDisplayMode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC/2 - 480/2)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
     21,        // line n
     22,        // line n
     21,        // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXNtsc240Int = 
{
    VI_TVMODE_NTSC_INT,     // viDisplayMode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_TRUE,         // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXNtsc240IntAa = 
{
    VI_TVMODE_NTSC_INT,     // viDisplayMode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_TRUE,         // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
     21,        // line n
     22,        // line n
     21,        // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXNtsc480IntDf = 
{
    VI_TVMODE_NTSC_INT,     // viDisplayMode
    640,             // fbWidth
    480,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     8,         // line n-1
     8,         // line n-1
    10,         // line n
    12,         // line n
    10,         // line n
     8,         // line n+1
     8          // line n+1
};
GXRenderModeObj GXNtsc480Int = 
{
    VI_TVMODE_NTSC_INT,     // viDisplayMode
    640,             // fbWidth
    480,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXNtsc480IntAa = 
{
    VI_TVMODE_NTSC_INT,     // viDisplayMode
    640,             // fbWidth
    242,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     4,         // line n-1
     8,         // line n-1
    12,         // line n
    16,         // line n
    12,         // line n
     8,         // line n+1
     4          // line n+1
};
GXRenderModeObj GXNtsc480Prog = 
{
    VI_TVMODE_NTSC_PROG,     // viDisplayMode
    640,             // fbWidth
    480,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXNtsc480ProgSoft = 
{
    VI_TVMODE_NTSC_PROG,     // viDisplayMode
    640,             // fbWidth
    480,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     8,         // line n-1
     8,         // line n-1
    10,         // line n
    12,         // line n
    10,         // line n
     8,         // line n+1
     8          // line n+1
};
GXRenderModeObj GXNtsc480ProgAa = 
{
    VI_TVMODE_NTSC_PROG,     // viDisplayMode
    640,             // fbWidth
    242,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_NTSC - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_NTSC - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     4,         // line n-1
     8,         // line n-1
    12,         // line n
    16,         // line n
    12,         // line n
     8,         // line n+1
     4          // line n+1
};

/*---------------------------------------------------------------------------*/

GXRenderModeObj GXMpal240Ds = 
{
    VI_TVMODE_MPAL_DS,      // viDisplayMode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_MPAL - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_MPAL/2 - 480/2)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXMpal240DsAa = 
{
    VI_TVMODE_MPAL_DS,      // viDisplayMode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_MPAL - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_MPAL/2 - 480/2)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXMpal240Int = 
{
    VI_TVMODE_MPAL_INT,     // viDisplayMode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_MPAL - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_MPAL - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_TRUE,         // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXMpal240IntAa = 
{
    VI_TVMODE_MPAL_INT,     // viDisplayMode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_MPAL - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_MPAL - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_TRUE,         // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXMpal480IntDf = 
{
    VI_TVMODE_MPAL_INT,     // viDisplayMode
    640,             // fbWidth
    480,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_MPAL - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_MPAL - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     8,         // line n-1
     8,         // line n-1
    10,         // line n
    12,         // line n
    10,         // line n
     8,         // line n+1
     8          // line n+1
};
GXRenderModeObj GXMpal480Int = 
{
    VI_TVMODE_MPAL_INT,     // viDisplayMode
    640,             // fbWidth
    480,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_MPAL - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_MPAL - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXMpal480IntAa = 
{
    VI_TVMODE_MPAL_INT,     // viDisplayMode
    640,             // fbWidth
    242,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_MPAL - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_MPAL - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     4,         // line n-1
     8,         // line n-1
    12,         // line n
    16,         // line n
    12,         // line n
     8,         // line n+1
     4          // line n+1
};

/*---------------------------------------------------------------------------*/

GXRenderModeObj GXPal264Ds = 
{
    VI_TVMODE_PAL_DS,       // viDisplayMode
    640,             // fbWidth
    264,             // efbHeight
    264,             // xfbHeight
    (VI_MAX_WIDTH_PAL - 640)/2,         // viXOrigin
    (VI_MAX_HEIGHT_PAL/2 - 528/2)/2,        // viYOrigin
    640,             // viWidth
    528,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXPal264DsAa = 
{
    VI_TVMODE_PAL_DS,       // viDisplayMode
    640,             // fbWidth
    264,             // efbHeight
    264,             // xfbHeight
    (VI_MAX_WIDTH_PAL - 640)/2,         // viXOrigin
    (VI_MAX_HEIGHT_PAL/2 - 528/2)/2,        // viYOrigin
    640,             // viWidth
    528,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXPal264Int = 
{
    VI_TVMODE_PAL_INT,      // viDisplayMode
    640,             // fbWidth
    264,             // efbHeight
    264,             // xfbHeight
    (VI_MAX_WIDTH_PAL - 640)/2,         // viXOrigin
    (VI_MAX_HEIGHT_PAL - 528)/2,        // viYOrigin
    640,             // viWidth
    528,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_TRUE,         // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXPal264IntAa = 
{
    VI_TVMODE_PAL_INT,      // viDisplayMode
    640,             // fbWidth
    264,             // efbHeight
    264,             // xfbHeight
    (VI_MAX_WIDTH_PAL - 640)/2,         // viXOrigin
    (VI_MAX_HEIGHT_PAL - 528)/2,        // viYOrigin
    640,             // viWidth
    528,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_TRUE,         // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXPal528IntDf = 
{
    VI_TVMODE_PAL_INT,      // viDisplayMode
    640,             // fbWidth
    528,             // efbHeight
    528,             // xfbHeight
    (VI_MAX_WIDTH_PAL - 640)/2,         // viXOrigin
    (VI_MAX_HEIGHT_PAL - 528)/2,        // viYOrigin
    640,             // viWidth
    528,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     8,         // line n-1
     8,         // line n-1
    10,         // line n
    12,         // line n
    10,         // line n
     8,         // line n+1
     8          // line n+1
};
GXRenderModeObj GXPal528Int = 
{
    VI_TVMODE_PAL_INT,       // viDisplayMode
    640,             // fbWidth
    528,             // efbHeight
    528,             // xfbHeight
    (VI_MAX_WIDTH_PAL - 640)/2,         // viXOrigin
    (VI_MAX_HEIGHT_PAL - 528)/2,        // viYOrigin
    640,             // viWidth
    528,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXPal524IntAa = 
{
    VI_TVMODE_PAL_INT,      // viDisplayMode
    640,             // fbWidth
    264,             // efbHeight (maximum is 528/2)
    524,             // xfbHeight (allow for required overlap of 4 lines)
    (VI_MAX_WIDTH_PAL - 640)/2,         // viXOrigin
    (VI_MAX_HEIGHT_PAL - 528)/2,        // viYOrigin
    640,             // viWidth
    524,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     4,         // line n-1
     8,         // line n-1
    12,         // line n
    16,         // line n
    12,         // line n
     8,         // line n+1
     4          // line n+1
};

GXRenderModeObj GXEurgb60Hz240Ds = 
{
    VI_TVMODE_EURGB60_DS,      // viTVmode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_EURGB60 - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_EURGB60/2 - 480/2)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

     // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

     // vertical filter[7], 1/64 units, 6 bits each
      0,         // line n-1
      0,         // line n-1
     21,         // line n
     22,         // line n
     21,         // line n
      0,         // line n+1
      0          // line n+1
};
GXRenderModeObj GXEurgb60Hz240DsAa =
{
    VI_TVMODE_EURGB60_DS,      // viTVmode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_EURGB60 - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_EURGB60/2 - 480/2)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
     21,        // line n
     22,        // line n
     21,        // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXEurgb60Hz240Int = 
{
    VI_TVMODE_EURGB60_INT,     // viTVmode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_EURGB60 - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_EURGB60 - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_TRUE,         // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXEurgb60Hz240IntAa = 
{
    VI_TVMODE_EURGB60_INT,     // viTVmode
    640,             // fbWidth
    240,             // efbHeight
    240,             // xfbHeight
    (VI_MAX_WIDTH_EURGB60 - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_EURGB60 - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_SF,   // xFBmode
    GX_TRUE,         // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
     21,        // line n
     22,        // line n
     21,        // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXEurgb60Hz480IntDf = 
{
    VI_TVMODE_EURGB60_INT,     // viTVmode
    640,             // fbWidth
    480,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_EURGB60 - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_EURGB60 - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     8,         // line n-1
     8,         // line n-1
    10,         // line n
    12,         // line n
    10,         // line n
     8,         // line n+1
     8          // line n+1
};
GXRenderModeObj GXEurgb60Hz480Int = 
{
    VI_TVMODE_EURGB60_INT,     // viTVmode
    640,             // fbWidth
    480,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_EURGB60 - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_EURGB60 - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_FALSE,        // aa

    // sample points arranged in increasing Y order
     6,  6,  6,  6,  6,  6,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     6,  6,  6,  6,  6,  6,  // pix 1
     6,  6,  6,  6,  6,  6,  // pix 2
     6,  6,  6,  6,  6,  6,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     0,         // line n-1
     0,         // line n-1
    21,         // line n
    22,         // line n
    21,         // line n
     0,         // line n+1
     0          // line n+1
};
GXRenderModeObj GXEurgb60Hz480IntAa = 
{
    VI_TVMODE_EURGB60_INT,     // viTVmode
    640,             // fbWidth
    242,             // efbHeight
    480,             // xfbHeight
    (VI_MAX_WIDTH_EURGB60 - 640)/2,        // viXOrigin
    (VI_MAX_HEIGHT_EURGB60 - 480)/2,       // viYOrigin
    640,             // viWidth
    480,             // viHeight
    VI_XFBMODE_DF,   // xFBmode
    GX_FALSE,        // field_rendering
    GX_TRUE,         // aa

    // sample points arranged in increasing Y order
     3,  2,  9,  6,  3, 10,  // pix 0, 3 sample points, 1/12 units, 4 bits each
     3,  2,  9,  6,  3, 10,  // pix 1
     9,  2,  3,  6,  9, 10,  // pix 2
     9,  2,  3,  6,  9, 10,  // pix 3

    // vertical filter[7], 1/64 units, 6 bits each
     4,         // line n-1
     8,         // line n-1
    12,         // line n
    16,         // line n
    12,         // line n
     8,         // line n+1
     4          // line n+1
};

#endif // #if 0
/*---------------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------------*/

//BOOL IsWriteGatherBufferEmpty ( void );
//void GXInit( void );

/*---------------------------------------------------------------------------*/

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


/*---------------------------------------------------------------------------*/

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

/*---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------*/
void GXSetGPMetric     (  GXPerf0       perf0,
                          GXPerf1       perf1 );

void GXClearGPMetric   (  void );

void GXReadGPMetric    (  u32*          cnt0,
                          u32*          cnt1 );


#define GXSetGP0Metric(perf0)    GXSetGPMetric((perf0), GX_PERF1_NONE)

#define GXClearGP0Metric()       GXClearGPMetric()

u32  GXReadGP0Metric   ( void );


#define GXSetGP1Metric(perf1)    GXSetGPMetric(GX_PERF0_NONE, (perf1))

#define GXClearGP1Metric()       GXClearGPMetric()

u32  GXReadGP1Metric   ( void );


void GXReadMemMetric   ( u32*           cp_req,
                         u32*           tc_req,
                         u32*           cpu_rd_req,
                         u32*           cpu_wr_req,
                         u32*           dsp_req,
                         u32*           io_req,
                         u32*           vi_req,
                         u32*           pe_req,
                         u32*           rf_req,
                         u32*           fi_req );

void GXClearMemMetric  ( void );


void GXReadPixMetric   (  u32*          top_pixels_in, 
                          u32*          top_pixels_out, 
                          u32*          bot_pixels_in, 
                          u32*          bot_pixels_out,
                          u32*          clr_pixels_in,
                          u32*          copy_clks );

void GXClearPixMetric  (  void  );


void GXSetVCacheMetric  ( GXVCachePerf  attr );

void GXReadVCacheMetric ( u32*          check, 
                          u32*          miss, 
                          u32*          stall );

void GXClearVCacheMetric ( void );


// DO NOT use with GXReadGP*Metric
void GXReadXfRasMetric  ( u32*          xf_wait_in,
                          u32*          xf_wait_out,
                          u32*          ras_busy,
                          u32*          clocks );

// DO NOT use with GXReadGP*Metric
void GXInitXfRasMetric();

    
u32 GXReadClksPerVtx( void );

/*---------------------------------------------------------------------------*/

void __GXSetBWDials     ( u16           cpDial,
                          u16           tcDial,
                          u16           peDial,
                          u16           cpuRdDial,
                          u16           cpuWrDial );

/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
void GXSetFog(	GXFogType	type,
		f32		startz,
		f32		endz,
		f32		nearz,
		f32		farz,
		GXColor		color );

void GXSetFogColor( GXColor color );

void GXInitFogAdjTable( GXFogAdjTable* table, u16 width, const f32 projmtx[4][4] );

void GXSetFogRangeAdj( GXBool enable, u16 center, const GXFogAdjTable* table );

void GXSetBlendMode (	GXBlendMode	type,
			GXBlendFactor	src_factor, 
			GXBlendFactor	dst_factor, 
			GXLogicOp	op );

void GXSetColorUpdate( GXBool update_enable );
void GXSetAlphaUpdate( GXBool update_enable );
void GXSetZMode(	GXBool		compare_enable,
			GXCompare	func,
			GXBool		update_enable );

void GXSetZCompLoc( GXBool before_tex );
void GXSetPixelFmt ( GXPixelFmt pix_fmt, GXZFmt16 z_fmt );
void GXSetDither( GXBool dither );
void GXSetDstAlpha( GXBool enable, u8 alpha );
void GXSetFieldMask( GXBool odd_mask, GXBool even_mask );
void GXSetFieldMode( GXBool field_mode, GXBool half_aspect_ratio );

/*---------------------------------------------------------------------------*/

#ifdef __MWERKS__
#pragma warn_padding    off
#endif // __MWERKS__

/*---------------------------------------------------------------------------*/

/********************************/
typedef struct _GXColor
{
    u8  r,
        g, 
        b, 
        a;

} GXColor;

typedef struct _GXColorS10
{
    s16    r, g, b, a; // s10-bit components for Tev constant color
} GXColorS10;

/********************************/
typedef struct _GXTexObj
{
#ifdef EMU
    u32 dummy[16]; // emulator version
#else
    u32 dummy[8];  // real hardware version
#endif    
} GXTexObj;

/********************************/
typedef struct _GXTlutObj
{
    u32 dummy[3];
    
} GXTlutObj;

/********************************/
typedef struct _GXLightObj
{
    u32 dummy[16];
    
} GXLightObj;

/********************************/
typedef struct _GXVtxAttrFmtList
{
    GXAttr        attr;
    GXCompCnt     cnt;
    GXCompType    type;
    u8            frac;
    
} GXVtxAttrFmtList;

/********************************/
typedef struct _GXTexRegion
{
#ifdef EMU
    u32 dummy[8]; // emulator version
#else
    u32 dummy[4]; // real hardware version
#endif
} GXTexRegion;

/********************************/
typedef struct _GXTlutRegion
{
    u32 dummy[4];
    
} GXTlutRegion;

/********************************/
typedef struct _GXVtxDescList
{
    GXAttr        attr;
    GXAttrType    type;
    
} GXVtxDescList;

/********************************/
typedef struct _GXRenderModeObj
{
    vi::VITVMode          viTVmode;
    u16               fbWidth;   // no xscale from efb to xfb
    u16               efbHeight; // embedded frame buffer
    u16               xfbHeight; // external frame buffer, may yscale efb
    u16               viXOrigin;
    u16               viYOrigin;
    u16               viWidth;
    u16               viHeight;
    vi::VIXFBMode         xFBmode;   // whether single-field or double-field in 
                                 // XFB.
    u8                field_rendering;    // rendering fields or frames?
    u8                aa;                 // antialiasing on?
    u8                sample_pattern[12][2]; // aa sample pattern
    u8                vfilter[7];         // vertical filter coefficients
} GXRenderModeObj;

/********************************/
typedef struct _GXFogAdjTable
{
    u16			r[10];
} GXFogAdjTable;

/********************************/

/*---------------------------------------------------------------------------*/

#ifdef __MWERKS__
#pragma warn_padding    reset
#endif // __MWERKS__

/*---------------------------------------------------------------------------*/

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


typedef GXTexRegion*  (*GXTexRegionCallback) (const GXTexObj* t_obj, GXTexMapID id);
typedef GXTlutRegion* (*GXTlutRegionCallback)(u32 idx);

/*---------------------------------------------------------------------------*/
void GXInitTexObj(
         GXTexObj*      obj,
         void*          image_ptr,
         u16            width,
         u16            height,
         GXTexFmt       format,
         GXTexWrapMode  wrap_s,
         GXTexWrapMode  wrap_t,
         GXBool         mipmap);

void GXInitTexObjCI(
         GXTexObj*      obj,
         void*          image_ptr,
         u16            width,
         u16            height,
         GXCITexFmt     format,
         GXTexWrapMode  wrap_s,
         GXTexWrapMode  wrap_t,
         GXBool         mipmap,
         u32            tlut_name);

void GXInitTexObjLOD(
         GXTexObj*      obj,
         GXTexFilter    min_filt,
         GXTexFilter    mag_filt,
         f32            min_lod,
         f32            max_lod,
         f32            lod_bias,
         GXBool         bias_clamp,
         GXBool         do_edge_lod,
         GXAnisotropy   max_aniso );

void  GXInitTexObjData     ( GXTexObj* obj, void* image_ptr );
void  GXInitTexObjWrapMode ( GXTexObj* obj, GXTexWrapMode s, GXTexWrapMode t );
void  GXInitTexObjTlut     ( GXTexObj* obj, u32 tlut_name );
void  GXInitTexObjFilter   ( GXTexObj* obj, GXTexFilter min_filt, GXTexFilter mag_filt );
void  GXInitTexObjMaxLOD   ( GXTexObj* obj, f32 max_lod );
void  GXInitTexObjMinLOD   ( GXTexObj* obj, f32 min_lod );
void  GXInitTexObjLODBias  ( GXTexObj* obj, f32 lod_bias );
void  GXInitTexObjBiasClamp( GXTexObj* obj, GXBool bias_clamp );
void  GXInitTexObjEdgeLOD  ( GXTexObj* obj, GXBool do_edge_lod );
void  GXInitTexObjMaxAniso ( GXTexObj* obj, GXAnisotropy max_aniso );


void  GXInitTexObjUserData ( GXTexObj* obj, void* user_data );
void* GXGetTexObjUserData  ( const GXTexObj* obj );

void  GXLoadTexObj         ( const GXTexObj* obj, GXTexMapID id );

u32   GXGetTexBufferSize(
          u16           width,
          u16           height,
          u32           format,
          GXBool        mipmap,
          u8            max_lod );

void GXInitTlutObj(
         GXTlutObj* tlut_obj,
         void*      lut,
         GXTlutFmt  fmt,
         u16        n_entries );

void GXLoadTlut             ( const GXTlutObj* tlut_obj, u32 tlut_name );

void GXInitTexCacheRegion(
         GXTexRegion*      region,
         GXBool            is_32b_mipmap,
         u32               tmem_even,
         GXTexCacheSize    size_even,
         u32               tmem_odd,
         GXTexCacheSize    size_odd );

void GXInitTexPreLoadRegion(
         GXTexRegion*      region,
         u32               tmem_even,
         u32               size_even,
         u32               tmem_odd,
         u32               size_odd );

void GXInitTlutRegion(
         GXTlutRegion*     region,
         u32               tmem_addr,
         GXTlutSize        tlut_size );

void GXInvalidateTexRegion  ( const GXTexRegion* region );
void GXInvalidateTexAll     ( void );
void GXPreLoadEntireTexture ( const GXTexObj* tex_obj, const GXTexRegion* region );

GXTexRegionCallback  GXSetTexRegionCallback ( GXTexRegionCallback f );
GXTlutRegionCallback GXSetTlutRegionCallback( GXTlutRegionCallback f );

void GXLoadTexObjPreLoaded(
         const GXTexObj*    obj, 
         const GXTexRegion* region, 
         GXTexMapID         id );

void GXSetTexCoordScaleManually(GXTexCoordID coord,
                                GXBool enable,
                                u16 ss, u16 ts);

void GXSetTexCoordCylWrap(GXTexCoordID coord,
                          GXBool s_enable,
                          GXBool t_enable);

void GXSetTexCoordBias(GXTexCoordID coord,
                       GXBool s_enable,
                       GXBool t_enable);

/*---------------------------------------------------------------------------*/

#ifdef WIN32
#include "win32/win32.h"
#endif

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

typedef enum {
    GX_WARN_NONE,       // no warnings reported
    GX_WARN_SEVERE,     // reports only severest warnings
    GX_WARN_MEDIUM,     // reports severe and medium warnings
    GX_WARN_ALL         // reports any and all warning info
} GXWarningLevel;

#ifdef _DEBUG
extern void GXSetVerifyLevel( GXWarningLevel level );
#else
#define GXSetVerifyLevel(level)     ((void)0)
#endif

// Note: warning IDs are subject to change.
//       warning messages are subject to change as well.

typedef void (*GXVerifyCallback)(GXWarningLevel level, 
                                 u32            id, 
                                 const char*          msg);

#ifdef _DEBUG
GXVerifyCallback GXSetVerifyCallback( GXVerifyCallback cb );
#else
#define GXSetVerifyCallback(cb)     ((GXVerifyCallback)0)
#endif

#ifdef WIN32
#include <win32/win32.h>
#endif


/*>*******************************(*)*******************************<*/
#ifndef EMU // real hardware
/*---------------------------------------------*
 * Write gather pipe for GFXFifo               *
 *---------------------------------------------*/
#ifndef MINNOW
#define   GXFIFO_ADDR   0xCC008000
#else // MINNOW
#define   GXFIFO_ADDR   0x1C008000
#endif// MINNOW

#include  <dolphin/base/PPCWGPipe.h>
// SN-Phil: removed 'extern', added AT_ADDRESS
volatile PPCWGPipe GXWGFifo AT_ADDRESS(GXFIFO_ADDR) ;

#endif // !EMU
/*---------------------------------------------------------------------------*/

#if defined(EMU) || defined(WIN32)
/*---------------------------------------------*
 * Display list support for emulator           *
 *---------------------------------------------*/

extern u8* __EmBuffPtr;
extern u8* __EmBuffTop;
extern GXBool __EmDisplayListInProgress;

#endif // EMU

/*---------------------------------------------------------------------------*/
/*---------------------------------------------*
 * GXVertex functions                          *
 *---------------------------------------------*/
//-------------------------------
// Define gfx function templates
//-------------------------------
//
// Templates syntax:
//  __GXCDEF (function_prefix, num_of_components, component_type)
//  __GXCDEFX(function_name, num_of_comps, src_comp_type, dest_comp_type)
//
#define __GXCDEF(prfx,n,t)  __GXCDEF##n(prfx##n##t,t,t)
#define __GXCDEFX(func,n,t) __GXCDEF##n(func,t,t)

#ifdef _DEBUG

// 1 component
#define __GXCDEF1(func,ts,td) \
    void func(const ts x);

// 2 components
#define __GXCDEF2(func,ts,td) \
    void func(const ts x, const ts y);

// 3 components
#define __GXCDEF3(func,ts,td) \
    void func(const ts x, const ts y, const ts z);

// 4 components
#define __GXCDEF4(func,ts,td) \
    void func(const ts x, const ts y, const ts z, const ts w);


#else // ifdef _DEBUG
/*---------------------------------------------*
 * For emulator                                *
 *---------------------------------------------*/
#if defined(EMU)

// 1 component
#define __GXCDEF1(func,ts,td) \
    static inline void func(const ts x)  \
    {                             \
        if (__EmDisplayListInProgress) { \
			*((td *) __EmBuffPtr) = (td) x; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
        } else {                  \
            Em##func(x);          \
        }                         \
        return;                   \
    }

// 2 components
#define __GXCDEF2(func,ts,td) \
    static inline void func(const ts x, const ts y) \
    {                             \
        if (__EmDisplayListInProgress) { \
			*((td *) __EmBuffPtr) = (td) x; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
			*((td *) __EmBuffPtr) = (td) y; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
        } else {                  \
            Em##func(x, y);       \
        }                         \
        return;                   \
    }

// 3 components
#define __GXCDEF3(func,ts,td) \
    static inline void func(const ts x, const ts y, const ts z) \
    {                             \
        if (__EmDisplayListInProgress) { \
			*((td *) __EmBuffPtr) = (td) x; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
			*((td *) __EmBuffPtr) = (td) y; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
			*((td *) __EmBuffPtr) = (td) z; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
        } else {                  \
            Em##func(x, y, z);    \
        }                         \
        return;                   \
    }

// 4 components
#define __GXCDEF4(func,ts,td) \
    static inline void func(const ts x, const ts y, const ts z, const ts w) \
    {                             \
        if (__EmDisplayListInProgress) { \
			*((td *) __EmBuffPtr) = (td) x; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
			*((td *) __EmBuffPtr) = (td) y; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
			*((td *) __EmBuffPtr) = (td) z; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
			*((td *) __EmBuffPtr) = (td) w; \
			__EmBuffPtr = __EmBuffPtr + sizeof(td); \
        } else {                  \
            Em##func(x, y, z, w); \
        }                         \
        return;                   \
    }

#endif // ifdef EMU

/*---------------------------------------------*
 * For real hardware                           *
 *---------------------------------------------*/
#ifndef EMU

// 1 component
#define __GXCDEF1(func,ts,td) \
    static inline void func(const ts x) \
    {                         \
        GXWGFifo.td = (td) x; \
        return;               \
    }

// 2 components
#define __GXCDEF2(func,ts,td) \
    static inline void func(const ts x, const ts y) \
    {                         \
        GXWGFifo.td = (td) x; \
        GXWGFifo.td = (td) y; \
        return;               \
    }

// 3 components
#define __GXCDEF3(func,ts,td) \
    static inline void func(const ts x, const ts y, const ts z) \
    {                         \
        GXWGFifo.td = (td) x; \
        GXWGFifo.td = (td) y; \
        GXWGFifo.td = (td) z; \
        return;               \
    }

// 4 components
#define __GXCDEF4(func,ts,td) \
    static inline void func(const ts x, const ts y, const ts z, const ts w) \
    {                         \
        GXWGFifo.td = (td) x; \
        GXWGFifo.td = (td) y; \
        GXWGFifo.td = (td) z; \
        GXWGFifo.td = (td) w; \
        return;               \
    }

#endif // ifndef EMU

#endif // ifdef _DEBUG else

//---------------------------
// Generate inline functions
//---------------------------
//---- GXCmd[n][t] ----
__GXCDEF( GXCmd, 1, u8  )
__GXCDEF( GXCmd, 1, u16 )
__GXCDEF( GXCmd, 1, u32 )

//---- GXParam[n][t] ----
__GXCDEF( GXParam, 1, u8  )
__GXCDEF( GXParam, 1, u16 )
__GXCDEF( GXParam, 1, u32 )
__GXCDEF( GXParam, 1, s8  )
__GXCDEF( GXParam, 1, s16 )
__GXCDEF( GXParam, 1, s32 )
__GXCDEF( GXParam, 1, f32 )
__GXCDEF( GXParam, 3, f32 ) // for light
__GXCDEF( GXParam, 4, f32 ) // for matrix

//---- GXPosition[n][t] ----
  // for GX_POS_XYZ
__GXCDEF( GXPosition, 3, f32 )
__GXCDEF( GXPosition, 3, u8  )
__GXCDEF( GXPosition, 3, s8  )
__GXCDEF( GXPosition, 3, u16 )
__GXCDEF( GXPosition, 3, s16 )
  // for GX_POS_XY
__GXCDEF( GXPosition, 2, f32 )
__GXCDEF( GXPosition, 2, u8  )
__GXCDEF( GXPosition, 2, s8  )
__GXCDEF( GXPosition, 2, u16 )
__GXCDEF( GXPosition, 2, s16 )
  // for Index
__GXCDEFX( GXPosition1x16, 1, u16 )
__GXCDEFX( GXPosition1x8,  1, u8  )

//---- GXNormal[n][t] ----
  // for GX_NRM or GX_NBT
__GXCDEF( GXNormal, 3, f32 )
__GXCDEF( GXNormal, 3, s16 )
__GXCDEF( GXNormal, 3, s8  )
  // for Index
__GXCDEFX( GXNormal1x16, 1, u16 )
__GXCDEFX( GXNormal1x8,  1, u8  )

//---- GXColor[n][t] ----
  // for GX_CLR_RGBA8 or RGBX8
__GXCDEF( GXColor, 4, u8  )
__GXCDEF( GXColor, 1, u32 )
  // for GX_CLR_RGBA6 or RGB8
__GXCDEF( GXColor, 3, u8  )
  // for GX_CLR_RGBA4 or RGB565
__GXCDEF( GXColor, 1, u16 )
  // for Index
__GXCDEFX( GXColor1x16, 1, u16 )
__GXCDEFX( GXColor1x8,  1, u8  )

//---- GXTexCoord[n][t] ----
  // for GX_TEX_ST
__GXCDEF( GXTexCoord, 2, f32 )
__GXCDEF( GXTexCoord, 2, s16 )
__GXCDEF( GXTexCoord, 2, u16 )
__GXCDEF( GXTexCoord, 2, s8  )
__GXCDEF( GXTexCoord, 2, u8  )
  // for GX_TEX_S
__GXCDEF( GXTexCoord, 1, f32 )
__GXCDEF( GXTexCoord, 1, s16 )
__GXCDEF( GXTexCoord, 1, u16 )
__GXCDEF( GXTexCoord, 1, s8  )
__GXCDEF( GXTexCoord, 1, u8  )
  // for Index
__GXCDEFX( GXTexCoord1x16, 1, u16 )
__GXCDEFX( GXTexCoord1x8,  1, u8  )

//---- GXMatrixIndex* ----
// GXMatrixIndex1u8
__GXCDEF( GXMatrixIndex, 1, u8 )
#define GXMatrixIndex1x8    GXMatrixIndex1u8

//------------------------
// Undefine all templates
//------------------------
#undef  __GXCDEF
#undef  __GXCDEFX
#undef  __GXCDEF1
#undef  __GXCDEF2
#undef  __GXCDEF3
#undef  __GXCDEF4

/*---------------------------------------------------------------------------*/
// Packing macro for a several color format
#define	GXPackedRGB565(r,g,b)   \
	((u16)((((r)&0xf8)<<8)|(((g)&0xfc)<<3)|(((b)&0xf8)>>3)))
#define	GXPackedRGBA4(r,g,b,a)  \
	((u16)((((r)&0xf0)<<8)|(((g)&0xf0)<<4)|(((b)&0xf0)   )|(((a)&0xf0)>>4)))
#define	GXPackedRGB5A3(r,g,b,a) \
	((u16)((a)>=224 ? \
	((((r)&0xf8)<<7)|(((g)&0xf8)<<2)|(((b)&0xf8)>>3)|(1<<15)): \
	((((r)&0xf0)<<4)|(((g)&0xf0)   )|(((b)&0xf0)>>4)|(((a)&0xe0)<<7))))


}