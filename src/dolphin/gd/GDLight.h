#pragma once

/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>
/*---------------------------------------------------------------------------*/

#ifdef __SN__
extern int __cntlzw (int) ;
#endif
namespace gd {

/*---------------------------------------------------------------------------*/

// GD does not support manipulation of light objects 
// (the only exception is for loading indexed light objects).
//gx::GX can be used to manipulate light objects.
// If you wish to create light objects manually, here is the format:
//
// typedef struct __GXLightObj {
//     u32     reserved[3];
//     u32     Color;       // light color
//     f32     a[3];        // angle-attenuation coefficients
//     f32     k[3];        // distance-attenuation coefficients
//     f32     lpos[3];     // diffuse: position;  specular: direction
//     f32     ldir[3];     // diffuse: direction; specular: half-angle
// }gx::GXLightObj;
//
// If you plan to create light objects on the PC, be sure to do the
// necessary byte-swapping for the EPPC environment.

/*---------------------------------------------------------------------------*/

// This first group of APIs lets you set light values directly.

void GDSetLightAttn     (gx::GXLightID light,
                          f32 a0, f32 a1, f32 a2,
                          f32 k0, f32 k1, f32 k2 );

void GDSetLightSpot     (gx::GXLightID     light,
                          f32           cutoff,
                         gx::GXSpotFn      spot_func );

void GDSetLightDistAttn (gx::GXLightID     light,
                          f32           ref_distance,
                          f32           ref_brightness,
                         gx::GXDistAttnFn  dist_func );

void GDSetLightColor 	(gx::GXLightID light,gx::GXColor color );

void GDSetLightPos      (gx::GXLightID light, f32 x, f32 y, f32 z );

void GDSetLightDir 	    (gx::GXLightID light, f32 nx, f32 ny, f32 nz );

void GDSetSpecularDir   (gx::GXLightID light, f32 nx, f32 ny, f32 nz );

void GDSetSpecularDirHA (gx::GXLightID light, f32 nx, f32 ny, f32 nz, f32 hx, f32 hy, f32 hz );


// This function lets you load an indexed light object.
// Note that GD doesn't provide a way to load an immediate light object.
void GDLoadLightObjIndx	( u32 lt_obj_indx,gx::GXLightID light );

// Other lighting control and data registers:

void GDSetChanAmbColor 	(gx::GXChannelID chan,gx::GXColor amb_color );

void GDSetChanMatColor	(gx::GXChannelID chan,gx::GXColor mat_color );

void GDSetChanCtrl      (gx::GXChannelID   chan,
                         gx::GXBool        enable,
                         gx::GXColorSrc    amb_src,
                         gx::GXColorSrc    mat_src,
                          u32           light_mask,
                         gx::GXDiffuseFn   diff_fn,
                         gx::GXAttnFn      attn_fn );

/*---------------------------------------------------------------------------*/

static inline void GDSetLightShininess(gx::GXLightID light, f32 shininess )
{
    GDSetLightAttn( light, 0.0F, 0.0F, 1.0F,
                    shininess/2.0F, 0.0F, 1.0F-shininess/2.0F );
}

/*---------------------------------------------------------------------------*/

// Convert agx::GXLightID into a light number.  Note: little error checking.

static inline u16 __GDLightID2Index(gx::GXLightID id ) 
{
    u16 idx;
#ifdef EPPC
    idx = (u16) (31 - __cntlzw((u32)id));
    if (idx > 7)
    {
        idx = 0;
    }
#else
    switch (id) {
        case gx::GX_LIGHT0: idx = 0;    break;
        case gx::GX_LIGHT1: idx = 1;    break;
        case gx::GX_LIGHT2: idx = 2;    break;
        case gx::GX_LIGHT3: idx = 3;    break;
        case gx::GX_LIGHT4: idx = 4;    break;
        case gx::GX_LIGHT5: idx = 5;    break;
        case gx::GX_LIGHT6: idx = 6;    break;
        case gx::GX_LIGHT7: idx = 7;    break;
        default:        
            idx = 0;
            break;
    }
#endif
    return idx;
}

static inline u16 __GDLightID2Offset(gx::GXLightID id )
{
    // 0x10 is XF_LIGHT_SIZE, defined below
    return (u16) (__GDLightID2Index(id) * 0x10);
}

/*---------------------------------------------------------------------------*/

// Defines for setting XF registers...

/*
 *  xf_ambient0_f struct
 */
#define XF_AMBIENT0_ALPHA_SHIFT	0
#define XF_AMBIENT0_BLUE_SHIFT	8
#define XF_AMBIENT0_GREEN_SHIFT	16
#define XF_AMBIENT0_RED_SHIFT	24
#define XF_AMBIENT0_F(alpha, blue, green, red) \
	((((unsigned long)(alpha)) << XF_AMBIENT0_ALPHA_SHIFT) | \
	 (((unsigned long)(blue)) << XF_AMBIENT0_BLUE_SHIFT) | \
	 (((unsigned long)(green)) << XF_AMBIENT0_GREEN_SHIFT) | \
	 (((unsigned long)(red)) << XF_AMBIENT0_RED_SHIFT))

/*
 *  xf_material0_f struct
 */
#define XF_MATERIAL0_ALPHA_SHIFT	0
#define XF_MATERIAL0_BLUE_SHIFT	8
#define XF_MATERIAL0_GREEN_SHIFT	16
#define XF_MATERIAL0_RED_SHIFT	24
#define XF_MATERIAL0_F(alpha, blue, green, red) \
	((((unsigned long)(alpha)) << XF_MATERIAL0_ALPHA_SHIFT) | \
	 (((unsigned long)(blue)) << XF_MATERIAL0_BLUE_SHIFT) | \
	 (((unsigned long)(green)) << XF_MATERIAL0_GREEN_SHIFT) | \
	 (((unsigned long)(red)) << XF_MATERIAL0_RED_SHIFT))

/*
 *  xf_color0cntrl_f struct
 */
#define XF_COLOR0CNTRL_MATERIAL_SRC_SHIFT	0
#define XF_COLOR0CNTRL_LIGHTFUNC_SHIFT	1
#define XF_COLOR0CNTRL_LIGHT0_SHIFT	2
#define XF_COLOR0CNTRL_LIGHT1_SHIFT	3
#define XF_COLOR0CNTRL_LIGHT2_SHIFT	4
#define XF_COLOR0CNTRL_LIGHT3_SHIFT	5
#define XF_COLOR0CNTRL_AMBIENT_SRC_SHIFT	6
#define XF_COLOR0CNTRL_DIFFUSEATTEN_SHIFT	7
#define XF_COLOR0CNTRL_ATTENENABLE_SHIFT	9
#define XF_COLOR0CNTRL_ATTENSELECT_SHIFT	10
#define XF_COLOR0CNTRL_LIGHT4_SHIFT	11
#define XF_COLOR0CNTRL_LIGHT5_SHIFT	12
#define XF_COLOR0CNTRL_LIGHT6_SHIFT	13
#define XF_COLOR0CNTRL_LIGHT7_SHIFT	14
#define XF_COLOR0CNTRL_F(material_src, lightfunc, light0, light1, light2, light3, ambient_src, diffuseatten, attenenable, attenselect, light4, light5, light6, light7) \
	((((unsigned long)(material_src)) << XF_COLOR0CNTRL_MATERIAL_SRC_SHIFT) | \
	 (((unsigned long)(lightfunc)) << XF_COLOR0CNTRL_LIGHTFUNC_SHIFT) | \
	 (((unsigned long)(light0)) << XF_COLOR0CNTRL_LIGHT0_SHIFT) | \
	 (((unsigned long)(light1)) << XF_COLOR0CNTRL_LIGHT1_SHIFT) | \
	 (((unsigned long)(light2)) << XF_COLOR0CNTRL_LIGHT2_SHIFT) | \
	 (((unsigned long)(light3)) << XF_COLOR0CNTRL_LIGHT3_SHIFT) | \
	 (((unsigned long)(ambient_src)) << XF_COLOR0CNTRL_AMBIENT_SRC_SHIFT) | \
	 (((unsigned long)(diffuseatten)) << XF_COLOR0CNTRL_DIFFUSEATTEN_SHIFT) | \
	 (((unsigned long)(attenenable)) << XF_COLOR0CNTRL_ATTENENABLE_SHIFT) | \
	 (((unsigned long)(attenselect)) << XF_COLOR0CNTRL_ATTENSELECT_SHIFT) | \
	 (((unsigned long)(light4)) << XF_COLOR0CNTRL_LIGHT4_SHIFT) | \
	 (((unsigned long)(light5)) << XF_COLOR0CNTRL_LIGHT5_SHIFT) | \
	 (((unsigned long)(light6)) << XF_COLOR0CNTRL_LIGHT6_SHIFT) | \
	 (((unsigned long)(light7)) << XF_COLOR0CNTRL_LIGHT7_SHIFT))

#define XF_COLOR0CNTRL_F_PS(material_src, lightfunc, light3210, ambient_src, diffuseatten, attenenable, attenselect, light7654) \
	((((unsigned long)(material_src)) << XF_COLOR0CNTRL_MATERIAL_SRC_SHIFT) | \
	 (((unsigned long)(lightfunc)) << XF_COLOR0CNTRL_LIGHTFUNC_SHIFT) | \
	 (((unsigned long)(light3210)) << XF_COLOR0CNTRL_LIGHT0_SHIFT) | \
	 (((unsigned long)(ambient_src)) << XF_COLOR0CNTRL_AMBIENT_SRC_SHIFT) | \
	 (((unsigned long)(diffuseatten)) << XF_COLOR0CNTRL_DIFFUSEATTEN_SHIFT) | \
	 (((unsigned long)(attenenable)) << XF_COLOR0CNTRL_ATTENENABLE_SHIFT) | \
	 (((unsigned long)(attenselect)) << XF_COLOR0CNTRL_ATTENSELECT_SHIFT) | \
	 (((unsigned long)(light7654)) << XF_COLOR0CNTRL_LIGHT4_SHIFT))

/*
 *  XF register addresses (XF address space)
 */
#define XF_LIGHT_BASE_ID	0x0600
#define XF_LIGHT_SIZE	0x0010

#define XF_LIGHT0COLOR_ID	0x0603
#define XF_LIGHT0A0_ID	0x0604
#define XF_LIGHT0A1_ID	0x0605
#define XF_LIGHT0A2_ID	0x0606
#define XF_LIGHT0K0_ID	0x0607
#define XF_LIGHT0K1_ID	0x0608
#define XF_LIGHT0K2_ID	0x0609
#define XF_LIGHT0PX_ID	0x060a
#define XF_LIGHT0PY_ID	0x060b
#define XF_LIGHT0PZ_ID	0x060c
#define XF_LIGHT0DX_ID	0x060d
#define XF_LIGHT0DY_ID	0x060e
#define XF_LIGHT0DZ_ID	0x060f

#define XF_LIGHT0SDX_ID	0x060a
#define XF_LIGHT0SDY_ID	0x060b
#define XF_LIGHT0SDZ_ID	0x060c
#define XF_LIGHT0HX_ID	0x060d
#define XF_LIGHT0HY_ID	0x060e
#define XF_LIGHT0HZ_ID	0x060f

#define XF_AMBIENT0_ID	0x100a
#define XF_AMBIENT1_ID	0x100b
#define XF_MATERIAL0_ID	0x100c
#define XF_MATERIAL1_ID	0x100d
#define XF_COLOR0CNTRL_ID	0x100e
#define XF_COLOR1CNTRL_ID	0x100f
#define XF_ALPHA0CNTRL_ID	0x1010
#define XF_ALPHA1CNTRL_ID	0x1011
}