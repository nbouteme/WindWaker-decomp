#pragma once
/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>
namespace gx {
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
}