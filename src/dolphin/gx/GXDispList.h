#pragma once

/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
namespace gx {

	/*---------------------------------------------------------------------------*/
	void GXBeginDisplayList(void *list, u32 size);
	u32 GXEndDisplayList(void);
	void GXCallDisplayList(const void *list, u32 nbytes);

#ifndef EMU
	// Note: GXCommandList.h and GXVert.h must be #included first

	// Note: This function can only be used in certain situations.
	//       There must be no dirty state pending.  Thus this function
	//       is safe when called after a GXCallDisplayList or GXEnd call
	//       (without any other GX calls in between).  It is also safe to
	//       call this function multiple times in a row.
	//       Please refer to the online man page for complete details.

	// Note: No error checking is done; be careful!

	static inline void GXFastCallDisplayList(const void *list, u32 nbytes) {
		GXWGFifo.u8 = (u8)GX_CMD_CALL_DL;
// XXX UNSAFE: Assumes GP ignores all extra padding/unused bits.
#ifndef PTR64
		GXWGFifo.u32 = (u32)list;
		GXWGFifo.u32 = (u32)nbytes;
#else
		GXWGFifo.u64 = (u64)list;
		GXWGFifo.u64 = (u64)nbytes;
#endif
	}
#else
	static inline void GXFastCallDisplayList(const void *list, u32 nbytes) { GXCallDisplayList(list, nbytes); }
#endif
}