#include <d_ovlp_fade3.h>
#include <gx/GXFrameBuf.h>
#include <gx/GXMisc.h>
#include <dDlst_snapShot_c.h>


/* __thiscall dDlst_snapShot_c::draw(void) */

void __thiscall dDlst_snapShot_c::draw(dDlst_snapShot_c *this)

{
  gx::GXSetTexCopySrc(0,0,0x280,0x1e0);
  gx::GXSetTexCopyDst(0x140,0xf0,6,1);
  gx::GXCopyTex(mDoGph_gInf_c::mFrameBufferTex,0);
  gx::GXPixModeSync();
  return;
}

