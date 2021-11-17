#include <d_bg_s_lin_chk.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <dBgS_LinChk.h>


/* __thiscall dBgS_LinChk::Set(cXyz *,
                               cXyz *,
                               fopAc_ac_c *) */

void __thiscall dBgS_LinChk::Set(dBgS_LinChk *this,cXyz *param_1,cXyz *param_2,fopAc_ac_c *pActor)

{
  uint procID;
  
  if (pActor == (fopAc_ac_c *)0x0) {
    procID = 0xffffffff;
  }
  else {
    if (pActor == (fopAc_ac_c *)0x0) {
      procID = 0xffffffff;
    }
    else {
      procID = (pActor->parent).parent.mBsPcId;
    }
  }
  ::cBgS_LinChk::Set2(&this->parent,param_1,param_2,procID);
  return;
}

