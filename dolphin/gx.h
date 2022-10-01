#pragma once

#include <dolphin/types.h>

namespace gx {

/*---------------------------------------------------------------------------*/

// If the compiler flag GX_REV is not defined,
// set the latest revision number
#ifndef GX_REV

#if (defined(HW2) || defined(MAC))
#define GX_REV 2
#else  // other targets
#define GX_REV 1
#endif	// ( defined(HW2) || defined(MAC) )

#endif	// GX_REV

/*---------------------------------------------------------------------------*
    header file for each major section of the API
 *---------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------*/

}

#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
#include <dolphin/gx/GXStruct.h>
#include <dolphin/gx/GXGeometry.h>
#include <dolphin/gx/GXTransform.h>
#include <dolphin/gx/GXCull.h>
#include <dolphin/gx/GXLighting.h>
#include <dolphin/gx/GXTexture.h>
#include <dolphin/gx/GXTev.h>
#include <dolphin/gx/GXBump.h>
#include <dolphin/gx/GXPixel.h>
#include <dolphin/gx/GXFrameBuffer.h>
#include <dolphin/gx/GXCpu2Efb.h>
#include <dolphin/gx/GXPerf.h>
#include <dolphin/gx/GXFifo.h>
#include <dolphin/gx/GXManage.h>
#include <dolphin/gx/GXGet.h>
#include <dolphin/gx/GXDraw.h>
#include <dolphin/gx/GXVert.h>
#include <dolphin/gx/GXCommandList.h>
#include <dolphin/gx/GXDispList.h>
#include <dolphin/gx/GXVerify.h>
