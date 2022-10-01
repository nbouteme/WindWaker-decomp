#pragma once

/********************************/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/vi/vitypes.h>

namespace gx {
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
}