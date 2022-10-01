#pragma once
/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
namespace gx {
/*---------------------------------------------------------------------------*/
void GXSetScissor 	( u32 left, u32 top, u32 wd, u32 ht );
void GXSetCullMode	( GXCullMode mode );
void GXSetCoPlanar	( GXBool enable );
}