#pragma once

namespace gd {
#ifdef WIN32
#define inline __inline
#define cosf   (float)cos
#define sqrtf  (float)sqrt
#endif
}

#include <dolphin/gd/GDBase.h>
#include <dolphin/gd/GDFile.h>
#include <dolphin/gd/GDGeometry.h>
#include <dolphin/gd/GDIndirect.h>
#include <dolphin/gd/GDLight.h>
#include <dolphin/gd/GDPixel.h>
#include <dolphin/gd/GDTev.h>
#include <dolphin/gd/GDTexture.h>
#include <dolphin/gd/GDTransform.h>
#include <dolphin/gd/GDVert.h>
