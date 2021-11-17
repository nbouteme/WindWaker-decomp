#include <d_bg_w_deform.h>
#include <J3DGraphAnimator/J3DModelData.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_bg_w.h>
#include <J3DGraphAnimator/J3DModel.h>
#include <JKernel/JKRHeap.h>
#include <dBgWDeform.h>


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgWDeform::Set(cBgD_t *,
                              J3DModel *,
                              unsigned long) */

uint __thiscall dBgWDeform::Set(dBgWDeform *this,cBgD_t *param_1,J3DModel *param_2,ulong param_3)

{
  char cVar5;
  ulong uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  J3DSkinDeform *pJVar6;
  
  cVar5 = J3DModelData::isDeformablePositionFormat(param_2->mpModelData);
  if (cVar5 != '\x01') {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar1,"d_bg_w_deform.cpp",0x20,
               "pmodel->getModelData()->isDeformablePositionFormat() == true");
    m_Do_printf::OSPanic("d_bg_w_deform.cpp",0x20,"Halt");
  }
  uVar2 = cBgW::Set((cBgW *)this,param_1,0x33,(MTX34 *)0x0);
  if ((uVar2 & 0xff) == 0) {
    *(ulong *)(this + 0xbc) = param_3;
    pJVar6 = (J3DSkinDeform *)this;
    if (this != (dBgWDeform *)0x0) {
      pJVar6 = (J3DSkinDeform *)(this + 0xc4);
    }
    iVar3 = J3DModel::setSkinDeform(param_2,pJVar6,1);
    if (iVar3 == 4) {
      uVar2 = 1;
    }
    else {
      param_2->mFlags = param_2->mFlags & 0xfffffff7;
      param_2->mFlags = param_2->mFlags | 4;
      if ((*(uint *)(this + 0xbc) & 1) == 0) {
        uVar4 = JKernel::operator_new__(**(int **)(this + 0x94) * 0xc);
        *(undefined4 *)(this + 0xc0) = uVar4;
        uVar2 = countLeadingZeros(*(undefined4 *)(this + 0xc0));
        uVar2 = uVar2 >> 5 & 0xff;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

