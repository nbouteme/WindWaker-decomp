#pragma once
#include <ctypes.h>

#include <JPADrawVisitorContainer.h>
#include <JPADrawSetupTev.h>

//[BSS] Expected size is 0x00013c
extern struct JPADrawVisitorContainer JPADraw;
//[BSS] Expected size is 0x0000b4
extern struct JPADrawSetupTev JPADraw;

namespace JPADraw {
void __sinit_JPADraw_cpp(void);
}

namespace JGeometry {
}
