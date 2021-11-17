#include <JPALoader/JPAEmitterLoader.h>
#include <JPALoader/JPAEmitterLoader.h>
#include <JUtility/JUTAssert.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JPALoader/JPAResourceManager.h>
#include <m_Do_printf.h>
#include <JPALoader/JPAFieldBlock.h>
#include <JPALoader/JPAKeyBlock.h>
#include <JPALoader/JPADynamicsBlock.h>
#include <JPALoader/JPABaseShape.h>
#include <JPALoader/JPAExtraShape.h>
#include <JPALoader/JPASweepShape.h>
#include <JPALoader/JPAExTexShape.h>
#include <JPALoader/JPATexture.h>
#include <JPAEmitterArchiveLoader_v10.h>


namespace JPAEmitterArchiveLoaderDataBase {

/* __thiscall load(unsigned char const *,
                                                    JKRHeap *,
                                                    JPAEmitterResource * *,
                                                    JPATextureResource * *) */

void load
               (void *param_1,JKRHeap *param_2,JPAEmitterResource **param_3,
               JPATextureResource **param_4)

{
  ulong uVar1;
  JPAEmitterArchiveLoader_v10 local_18;
  
                    /* WARNING: Load size is inaccurate */
  if (*param_1 == 0x4a504143) {
    if (*(int *)((int)param_1 + 4) == 0x312d3030) {
      local_18.mpEmitterRes = (JPAEmitterResource *)0x0;
      local_18.mpTexRes = (JPATextureResource *)0x0;
      local_18.mpHeap = param_2;
      local_18.mpData = (byte *)param_1;
      JPAEmitterArchiveLoader_v10::load(&local_18);
      *param_3 = local_18.mpEmitterRes;
      *param_4 = local_18.mpTexRes;
    }
    else {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::setWarningMessage_f
                (uVar1,"JPAEmitterLoader.cpp",0xc9,"%s",(___)"This is WRONG Version File\n");
    }
  }
  else {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"JPAEmitterLoader.cpp",0xca,"%s",(___)"This is WRONG File\n");
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __thiscall JPAEmitterArchiveLoader_v10::load(void) */

void __thiscall JPAEmitterArchiveLoader_v10::load(JPAEmitterArchiveLoader_v10 *this)

{
  bool bVar1;
  JPAEmitterResource *this_00;
  JPATextureResource *this_01;
  JPAEmitterData *pEmitterData;
  JPADataBlockLinkInfo *pLinkInfo;
  JPADataBlockLinkInfo *pJVar2;
  JPAKeyBlockArc **ppJVar3;
  JPAFieldBlockArc **ppJVar4;
  JPAFieldBlockArc *this_02;
  JPAKeyBlockArc *this_03;
  JPADynamicsBlockArc *this_04;
  JPABaseShapeArc *this_05;
  JPAExtraShapeArc *this_06;
  JPASweepShapeArc *this_07;
  JPAExTexShapeArc *this_08;
  JPATextureArc *this_09;
  ulong uVar5;
  int magic;
  int *pBlock;
  int size;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  int idx;
  
  pbVar8 = this->mpData;
  this_00 = (JPAEmitterResource *)JKernel::operator_new(0xc,this->mpHeap,0);
  if (this_00 != (JPAEmitterResource *)0x0) {
    JPAEmitterResource::JPAEmitterResource(this_00,(uint)*(ushort *)(pbVar8 + 8),this->mpHeap);
  }
  this->mpEmitterRes = this_00;
  this_01 = (JPATextureResource *)JKernel::operator_new(0x30,this->mpHeap,0);
  if (this_01 != (JPATextureResource *)0x0) {
    JPATextureResource::JPATextureResource(this_01,(uint)*(ushort *)(pbVar8 + 10),this->mpHeap);
  }
  this->mpTexRes = this_01;
  idx = 0x20;
  for (iVar7 = 0; iVar7 < (int)(uint)*(ushort *)(pbVar8 + 8); iVar7 = iVar7 + 1) {
    pbVar10 = this->mpData + idx;
    pEmitterData = (JPAEmitterData *)JKernel::operator_new(8,this->mpHeap,0);
    if (pEmitterData == (JPAEmitterData *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"JPAEmitterLoader.cpp",0xea,"pEmtrRes");
      m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0xea,&DAT_80366732);
    }
    else {
      pEmitterData->mpLinkInfoArray = (JPADataBlockLinkInfo *)0x0;
    }
    pLinkInfo = (JPADataBlockLinkInfo *)JKernel::operator_new(0x24,this->mpHeap,0);
    if (pLinkInfo == (JPADataBlockLinkInfo *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"JPAEmitterLoader.cpp",0xee,"pLinkInfo");
      m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0xee,&DAT_80366732);
    }
    else {
      pLinkInfo->mpDynamicsBlock = (JPADynamicsBlockArc *)0x0;
      pLinkInfo->mpBaseShapeBlock = (JPABaseShapeArc *)0x0;
      pLinkInfo->mpExtraShapeBlock = (JPAExtraShapeArc *)0x0;
      pLinkInfo->mpSweepShapeBlock = (JPASweepShapeArc *)0x0;
      pLinkInfo->mpExTexShapeBlock = (JPAExTexShapeArc *)0x0;
      pLinkInfo->mpKeyBlocks = (JPAKeyBlockArc **)0x0;
      pLinkInfo->mpFldBlocks = (JPAFieldBlockArc **)0x0;
      pLinkInfo->mpTDB1 = (int *)0x0;
      pLinkInfo->mFldNum = 0;
      pLinkInfo->mTextureNum = 0;
      pLinkInfo->mKeyNum = 0;
    }
    pEmitterData->mLinkInfoCount = 1;
    pJVar2 = (JPADataBlockLinkInfo *)
             JKernel::operator_new__((uint)(ushort)pEmitterData->mLinkInfoCount << 2,this->mpHeap,0)
    ;
    pEmitterData->mpLinkInfoArray = pJVar2;
    if (pEmitterData->mpLinkInfoArray == (JPADataBlockLinkInfo *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"JPAEmitterLoader.cpp",0xf3,"pEmtrRes->pLinkInfoArray");
      m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0xf3,&DAT_80366732);
    }
    pEmitterData->mpLinkInfoArray->mpDynamicsBlock = (JPADynamicsBlockArc *)pLinkInfo;
    pLinkInfo->mKeyNum = pbVar10[0x14];
    if (pLinkInfo->mKeyNum == 0) {
      ppJVar3 = (JPAKeyBlockArc **)0x0;
    }
    else {
      ppJVar3 = (JPAKeyBlockArc **)
                JKernel::operator_new__((uint)pLinkInfo->mKeyNum << 2,this->mpHeap,0);
    }
    pLinkInfo->mpKeyBlocks = ppJVar3;
    bVar1 = false;
    if ((pLinkInfo->mpKeyBlocks != (JPAKeyBlockArc **)0x0) || (pLinkInfo->mKeyNum == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"JPAEmitterLoader.cpp",0xfa,"pLinkInfo->keyBlocks || pLinkInfo->keyNum == 0")
      ;
      m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0xfa,&DAT_80366732);
    }
    pLinkInfo->mFldNum = pbVar10[0x15];
    if (pLinkInfo->mFldNum == 0) {
      ppJVar4 = (JPAFieldBlockArc **)0x0;
    }
    else {
      ppJVar4 = (JPAFieldBlockArc **)
                JKernel::operator_new__((uint)pLinkInfo->mFldNum << 2,this->mpHeap,0);
    }
    pLinkInfo->mpFldBlocks = ppJVar4;
    bVar1 = false;
    if ((pLinkInfo->mpFldBlocks != (JPAFieldBlockArc **)0x0) || (pLinkInfo->mFldNum == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"JPAEmitterLoader.cpp",0x100,"pLinkInfo->fldBlocks || pLinkInfo->fldNum == 0"
                );
      m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0x100,&DAT_80366732);
    }
    pLinkInfo->mTextureNum = pbVar10[0x16];
    iVar11 = 0;
    pLinkInfo->mpTDB1 = (int *)0x0;
    iVar6 = 0;
    idx = idx + 0x20;
    for (uVar9 = 0; uVar9 < *(uint *)(pbVar10 + 0xc); uVar9 = uVar9 + 1) {
      pBlock = (int *)(this->mpData + idx);
      size = pBlock[1];
      magic = *pBlock;
      if (magic == 0x464c4431) {
        this_02 = (JPAFieldBlockArc *)JKernel::operator_new(8,this->mpHeap,0);
        if (this_02 != (JPAFieldBlockArc *)0x0) {
          JPAFieldBlockArc::JPAFieldBlockArc(this_02,this->mpData + idx);
        }
        *(JPAFieldBlockArc **)((int)pLinkInfo->mpFldBlocks + iVar6) = this_02;
        if (*(int *)((int)pLinkInfo->mpFldBlocks + iVar6) == 0) {
          uVar5 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert
                    (uVar5,"JPAEmitterLoader.cpp",0x112,"pLinkInfo->fldBlocks[fld_cntr]");
          m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0x112,&DAT_80366732);
        }
        iVar6 = iVar6 + 4;
      }
      else {
        if (magic < 0x464c4431) {
          if (magic == 0x45535031) {
            this_06 = (JPAExtraShapeArc *)JKernel::operator_new(0x20,this->mpHeap,0);
            if (this_06 != (JPAExtraShapeArc *)0x0) {
              JPAExtraShapeArc::JPAExtraShapeArc(this_06,this->mpData + idx);
            }
            pLinkInfo->mpExtraShapeBlock = this_06;
            if (pLinkInfo->mpExtraShapeBlock == (JPAExtraShapeArc *)0x0) {
              uVar5 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar5,"JPAEmitterLoader.cpp",0x124,"pLinkInfo->espBlock");
              m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0x124,&DAT_80366732);
            }
          }
          else {
            if (magic < 0x45535031) {
              if (magic == 0x42535031) {
                this_05 = (JPABaseShapeArc *)JKernel::operator_new(0x1c,this->mpHeap,0);
                if (this_05 != (JPABaseShapeArc *)0x0) {
                  JPABaseShapeArc::JPABaseShapeArc(this_05,this->mpData + idx,this->mpHeap);
                }
                pLinkInfo->mpBaseShapeBlock = this_05;
                if (pLinkInfo->mpBaseShapeBlock == (JPABaseShapeArc *)0x0) {
                  uVar5 = JUTAssertion::getSDevice();
                  JUTAssertion::showAssert(uVar5,"JPAEmitterLoader.cpp",0x120,"pLinkInfo->bspBlock")
                  ;
                  m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0x120,&DAT_80366732);
                }
              }
              else {
                if ((magic < 0x42535031) && (magic == 0x42454d31)) {
                  this_04 = (JPADynamicsBlockArc *)JKernel::operator_new(8,this->mpHeap,0);
                  if (this_04 != (JPADynamicsBlockArc *)0x0) {
                    JPADynamicsBlockArc::JPADynamicsBlockArc(this_04,this->mpData + idx);
                  }
                  pLinkInfo->mpDynamicsBlock = this_04;
                  if (pLinkInfo->mpDynamicsBlock == (JPADynamicsBlockArc *)0x0) {
                    uVar5 = JUTAssertion::getSDevice();
                    JUTAssertion::showAssert
                              (uVar5,"JPAEmitterLoader.cpp",0x11c,"pLinkInfo->dynBlock");
                    m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0x11c,&DAT_80366732);
                  }
                }
              }
            }
            else {
              if (magic == 0x45545831) {
                this_08 = (JPAExTexShapeArc *)JKernel::operator_new(8,this->mpHeap,0);
                if (this_08 != (JPAExTexShapeArc *)0x0) {
                  JPAExTexShapeArc::JPAExTexShapeArc(this_08,this->mpData + idx);
                }
                pLinkInfo->mpExTexShapeBlock = this_08;
                if (pLinkInfo->mpExTexShapeBlock == (JPAExTexShapeArc *)0x0) {
                  uVar5 = JUTAssertion::getSDevice();
                  JUTAssertion::showAssert(uVar5,"JPAEmitterLoader.cpp",300,"pLinkInfo->etxBlock");
                  m_Do_printf::OSPanic("JPAEmitterLoader.cpp",300,&DAT_80366732);
                }
              }
            }
          }
        }
        else {
          if (magic == 0x53535031) {
            this_07 = (JPASweepShapeArc *)JKernel::operator_new(8,this->mpHeap,0);
            if (this_07 != (JPASweepShapeArc *)0x0) {
              JPASweepShapeArc::JPASweepShapeArc(this_07,this->mpData + idx);
            }
            pLinkInfo->mpSweepShapeBlock = this_07;
            if (pLinkInfo->mpSweepShapeBlock == (JPASweepShapeArc *)0x0) {
              uVar5 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar5,"JPAEmitterLoader.cpp",0x128,"pLinkInfo->sspBlock");
              m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0x128,&DAT_80366732);
            }
          }
          else {
            if (magic < 0x53535031) {
              if (magic == 0x4b464131) {
                this_03 = (JPAKeyBlockArc *)JKernel::operator_new(0xc,this->mpHeap,0);
                if (this_03 != (JPAKeyBlockArc *)0x0) {
                  JPAKeyBlockArc::JPAKeyBlockArc(this_03,this->mpData + idx);
                }
                *(JPAKeyBlockArc **)((int)pLinkInfo->mpKeyBlocks + iVar11) = this_03;
                if (*(int *)((int)pLinkInfo->mpKeyBlocks + iVar11) == 0) {
                  uVar5 = JUTAssertion::getSDevice();
                  JUTAssertion::showAssert
                            (uVar5,"JPAEmitterLoader.cpp",0x117,"pLinkInfo->keyBlocks[key_cntr]");
                  m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0x117,&DAT_80366732);
                }
                iVar11 = iVar11 + 4;
              }
            }
            else {
              if (magic == 0x54444231) {
                pLinkInfo->mpTDB1 = pBlock + 3;
              }
            }
          }
        }
      }
      idx = idx + size;
    }
    JPAEmitterResource::registration(this->mpEmitterRes,pEmitterData,*(ushort *)(pbVar10 + 0x18));
  }
  for (iVar7 = 0; iVar7 < (int)(uint)*(ushort *)(pbVar8 + 10); iVar7 = iVar7 + 1) {
    iVar6 = *(int *)(this->mpData + idx + 4);
    this_09 = (JPATextureArc *)JKernel::operator_new(0x48,this->mpHeap,0);
    if (this_09 != (JPATextureArc *)0x0) {
      JPATextureArc::JPATextureArc(this_09,this->mpData + idx);
    }
    if (this_09 == (JPATextureArc *)0x0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"JPAEmitterLoader.cpp",0x13f,"pTex");
      m_Do_printf::OSPanic("JPAEmitterLoader.cpp",0x13f,&DAT_80366732);
    }
    JPATextureResource::registration(this->mpTexRes,&this_09->parent);
    idx = idx + iVar6;
  }
  return;
}

