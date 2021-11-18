#include <J3DGraphLoader/J3DAnmLoader.h>
#include <J3DGraphLoader/J3DAnmLoader.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTNameTab.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphLoader/J3DClusterLoader.h>
#include <J3DGraphLoader/J3DMaterialFactory.h>
#include <Demangler/J3DAnmTevRegKey.h>
#include <J3DAnmKeyLoader_v15.h>
#include <Demangler/J3DAnmVisibilityFull.h>
#include <J3DAnmFullLoader_v15.h>
#include <J3DAnmLoader.h>
#include <J3DAnmLoaderDataBase.h>


namespace J3DAnmVisibilityFull {
}

namespace J3DAnmTevRegKey {
}

namespace J3DAnmLoaderDataBase {

/* __thiscall load(void const *) */

undefined4 load(void *pData)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  J3DAnmFullLoader_v15 aJStack104 [4];
  undefined **local_64;
  J3DAnmFullLoader_v15 aJStack96 [4];
  undefined **local_5c;
  J3DAnmFullLoader_v15 aJStack88 [4];
  undefined **local_54;
  J3DAnmFullLoader_v15 aJStack80 [4];
  undefined **local_4c;
  J3DAnmFullLoader_v15 aJStack72 [4];
  undefined **local_44;
  J3DAnmFullLoader_v15 aJStack64 [4];
  undefined **local_3c;
  J3DAnmKeyLoader_v15 aJStack56 [4];
  undefined **local_34;
  J3DAnmKeyLoader_v15 aJStack48 [4];
  undefined **local_2c;
  J3DAnmKeyLoader_v15 aJStack40 [4];
  undefined **local_24;
  J3DAnmKeyLoader_v15 aJStack32 [4];
  undefined **local_1c;
  J3DAnmKeyLoader_v15 aJStack24 [4];
  undefined **local_14;
  J3DAnmKeyLoader_v15 aJStack16 [4];
  undefined **local_c;
  
  if (pData == (void *)0x0) {
    uVar1 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*pData == 0x4a334431) {
      iVar2 = *(int *)((int)pData + 4);
      if (iVar2 == 0x62726b31) {
        J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack48);
        local_2c = (undefined **)JKernel::operator_new(0x74);
        if (local_2c != (undefined **)0x0) {
          *local_2c = (undefined *)&J3DAnmBase::__vt;
          local_2c[2] = (undefined *)J3DGraphLoader::_1664;
          *(undefined2 *)((int)local_2c + 6) = 0;
          *local_2c = &J3DAnmTevRegKey::__vt;
          JUTNameTab::JUTNameTab((JUTNameTab *)(local_2c + 10));
          JUTNameTab::JUTNameTab((JUTNameTab *)(local_2c + 0xf));
          *(undefined2 *)((int)local_2c + 0x12) = 0;
          *(undefined2 *)(local_2c + 4) = 0;
          *(undefined2 *)((int)local_2c + 0x1a) = 0;
          *(undefined2 *)(local_2c + 6) = 0;
          *(undefined2 *)((int)local_2c + 0x16) = 0;
          *(undefined2 *)(local_2c + 5) = 0;
          *(undefined2 *)((int)local_2c + 0x22) = 0;
          *(undefined2 *)(local_2c + 8) = 0;
          *(undefined2 *)((int)local_2c + 0x1e) = 0;
          *(undefined2 *)(local_2c + 7) = 0;
          local_2c[0xe] = (undefined *)0x0;
          local_2c[9] = (undefined *)0x0;
          local_2c[0x18] = (undefined *)0x0;
          local_2c[0x17] = (undefined *)0x0;
          local_2c[0x16] = (undefined *)0x0;
          local_2c[0x15] = (undefined *)0x0;
          local_2c[0x1c] = (undefined *)0x0;
          local_2c[0x1b] = (undefined *)0x0;
          local_2c[0x1a] = (undefined *)0x0;
          local_2c[0x19] = (undefined *)0x0;
          local_2c[3] = (undefined *)0x5;
        }
        uVar1 = J3DAnmKeyLoader_v15::load(aJStack48,pData);
        J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack48);
      }
      else {
        if (iVar2 < 0x62726b31) {
          if (iVar2 == 0x626c6b31) {
            J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack32);
            local_1c = (undefined **)JKernel::operator_new(0x18);
            if (local_1c != (undefined **)0x0) {
              *local_1c = (undefined *)&J3DAnmBase::__vt;
              local_1c[2] = (undefined *)J3DGraphLoader::_1664;
              *(undefined2 *)((int)local_1c + 6) = 0;
              *local_1c = &J3DAnmCluster::__vt;
              local_1c[4] = (undefined *)0x0;
              local_1c[3] = (undefined *)0x3;
              *local_1c = &J3DAnmClusterKey::__vt;
              local_1c[5] = (undefined *)0x0;
            }
            uVar1 = J3DAnmKeyLoader_v15::load(aJStack32,pData);
            J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack32);
            return uVar1;
          }
          if (iVar2 < 0x626c6b31) {
            if (iVar2 == 0x62636b31) {
              J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack16);
              local_c = (undefined **)JKernel::operator_new(0x2c);
              if (local_c != (undefined **)0x0) {
                *local_c = (undefined *)&J3DAnmBase::__vt;
                local_c[2] = (undefined *)J3DGraphLoader::_1664;
                *(undefined2 *)((int)local_c + 6) = 0;
                *local_c = (undefined *)&J3DAnmTransform::__vt;
                local_c[4] = (undefined *)0x0;
                local_c[5] = (undefined *)0x0;
                local_c[6] = (undefined *)0x0;
                local_c[3] = (undefined *)0x0;
                *local_c = (undefined *)&J3DAnmTransformKey::__vt;
                local_c[9] = (undefined *)0x0;
                local_c[10] = (undefined *)0x0;
              }
              uVar1 = J3DAnmKeyLoader_v15::load(aJStack16,pData);
              J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack16);
              return uVar1;
            }
            if (iVar2 < 0x62636b31) {
              if (iVar2 == 0x62636131) {
                J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack64);
                local_3c = (undefined **)JKernel::operator_new(0x28);
                if (local_3c != (undefined **)0x0) {
                  *local_3c = (undefined *)&J3DAnmBase::__vt;
                  local_3c[2] = (undefined *)J3DGraphLoader::_1664;
                  *(undefined2 *)((int)local_3c + 6) = 0;
                  *local_3c = (undefined *)&J3DAnmTransform::__vt;
                  local_3c[4] = (undefined *)0x0;
                  local_3c[5] = (undefined *)0x0;
                  local_3c[6] = (undefined *)0x0;
                  local_3c[3] = (undefined *)0x0;
                  *local_3c = (undefined *)&J3DAnmTransformFull::__vt;
                  local_3c[9] = (undefined *)0x0;
                }
                uVar1 = J3DAnmFullLoader_v15::load(aJStack64,pData);
                J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack64);
                return uVar1;
              }
            }
            else {
              if (iVar2 == 0x626c6131) {
                J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack96);
                local_5c = (undefined **)JKernel::operator_new(0x18);
                if (local_5c != (undefined **)0x0) {
                  *local_5c = (undefined *)&J3DAnmBase::__vt;
                  local_5c[2] = (undefined *)J3DGraphLoader::_1664;
                  *(undefined2 *)((int)local_5c + 6) = 0;
                  *local_5c = &J3DAnmCluster::__vt;
                  local_5c[4] = (undefined *)0x0;
                  local_5c[3] = (undefined *)0x3;
                  *local_5c = &J3DAnmClusterFull::__vt;
                  local_5c[5] = (undefined *)0x0;
                }
                uVar1 = J3DAnmFullLoader_v15::load(aJStack96,pData);
                J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack96);
                return uVar1;
              }
            }
          }
          else {
            if (iVar2 == 0x62706b31) {
              J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack24);
              local_14 = (undefined **)JKernel::operator_new(0x44);
              if (local_14 != (undefined **)0x0) {
                *local_14 = (undefined *)&J3DAnmBase::__vt;
                local_14[2] = (undefined *)J3DGraphLoader::_1664;
                *(undefined2 *)((int)local_14 + 6) = 0;
                *local_14 = &J3DAnmColor::__vt;
                JUTNameTab::JUTNameTab((JUTNameTab *)(local_14 + 8));
                *(undefined2 *)((int)local_14 + 0x16) = 0;
                *(undefined2 *)(local_14 + 5) = 0;
                *(undefined2 *)((int)local_14 + 0x12) = 0;
                *(undefined2 *)(local_14 + 4) = 0;
                *(undefined2 *)(local_14 + 6) = 0;
                local_14[7] = (undefined *)0x0;
                local_14[3] = (undefined *)0x1;
                *local_14 = &J3DAnmColorKey::__vt;
                local_14[0xc] = (undefined *)0x0;
                local_14[0xd] = (undefined *)0x0;
                local_14[0xe] = (undefined *)0x0;
                local_14[0xf] = (undefined *)0x0;
                local_14[0x10] = (undefined *)0x0;
              }
              uVar1 = J3DAnmKeyLoader_v15::load(aJStack24,pData);
              J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack24);
              return uVar1;
            }
            if ((iVar2 < 0x62706b31) && (iVar2 == 0x62706131)) {
              J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack72);
              local_44 = (undefined **)JKernel::operator_new(0x44);
              if (local_44 != (undefined **)0x0) {
                *local_44 = (undefined *)&J3DAnmBase::__vt;
                local_44[2] = (undefined *)J3DGraphLoader::_1664;
                *(undefined2 *)((int)local_44 + 6) = 0;
                *local_44 = &J3DAnmColor::__vt;
                JUTNameTab::JUTNameTab((JUTNameTab *)(local_44 + 8));
                *(undefined2 *)((int)local_44 + 0x16) = 0;
                *(undefined2 *)(local_44 + 5) = 0;
                *(undefined2 *)((int)local_44 + 0x12) = 0;
                *(undefined2 *)(local_44 + 4) = 0;
                *(undefined2 *)(local_44 + 6) = 0;
                local_44[7] = (undefined *)0x0;
                local_44[3] = (undefined *)0x1;
                *local_44 = &J3DAnmColorFull::__vt;
                local_44[0xc] = (undefined *)0x0;
                local_44[0xd] = (undefined *)0x0;
                local_44[0xe] = (undefined *)0x0;
                local_44[0xf] = (undefined *)0x0;
                local_44[0x10] = (undefined *)0x0;
              }
              uVar1 = J3DAnmFullLoader_v15::load(aJStack72,pData);
              J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack72);
              return uVar1;
            }
          }
        }
        else {
          if (iVar2 == 0x62766131) {
            J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack88);
            local_54 = (undefined **)JKernel::operator_new(0x1c);
            if (local_54 != (undefined **)0x0) {
              *local_54 = (undefined *)&J3DAnmBase::__vt;
              local_54[2] = (undefined *)J3DGraphLoader::_1664;
              *(undefined2 *)((int)local_54 + 6) = 0;
              *local_54 = &J3DAnmVisibilityFull::__vt;
              *(undefined2 *)(local_54 + 4) = 0;
              local_54[5] = (undefined *)0x0;
              *(undefined2 *)((int)local_54 + 0x12) = 0;
              local_54[6] = (undefined *)0x0;
              local_54[3] = (undefined *)0x6;
            }
            uVar1 = J3DAnmFullLoader_v15::load(aJStack88,pData);
            J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack88);
            return uVar1;
          }
          if (iVar2 < 0x62766131) {
            if (iVar2 == 0x62747031) {
              J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack80);
              local_4c = (undefined **)JKernel::operator_new(0x30);
              if (local_4c != (undefined **)0x0) {
                *local_4c = (undefined *)&J3DAnmBase::__vt;
                local_4c[2] = (undefined *)J3DGraphLoader::_1664;
                *(undefined2 *)((int)local_4c + 6) = 0;
                *local_4c = &J3DAnmTexPattern::__vt;
                JUTNameTab::JUTNameTab((JUTNameTab *)(local_4c + 8));
                local_4c[4] = (undefined *)0x0;
                local_4c[5] = (undefined *)0x0;
                local_4c[3] = (undefined *)0x2;
                *(undefined2 *)((int)local_4c + 0x1a) = 0;
                local_4c[7] = (undefined *)0x0;
              }
              uVar1 = J3DAnmFullLoader_v15::load(aJStack80,pData);
              J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack80);
              return uVar1;
            }
            if ((iVar2 < 0x62747031) && (iVar2 == 0x62746b31)) {
              J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack40);
              local_24 = (undefined **)JKernel::operator_new(0x88);
              if (local_24 != (undefined **)0x0) {
                *local_24 = (undefined *)&J3DAnmBase::__vt;
                local_24[2] = (undefined *)J3DGraphLoader::_1664;
                *(undefined2 *)((int)local_24 + 6) = 0;
                *local_24 = &J3DAnmTextureSRTKey::__vt;
                JUTNameTab::JUTNameTab((JUTNameTab *)(local_24 + 0xe));
                JUTNameTab::JUTNameTab((JUTNameTab *)(local_24 + 0x1c));
                local_24[4] = (undefined *)0x0;
                *(undefined2 *)(local_24 + 8) = 0;
                *(undefined2 *)((int)local_24 + 0x1e) = 0;
                *(undefined2 *)(local_24 + 7) = 0;
                *(undefined2 *)(local_24 + 5) = 0;
                local_24[6] = (undefined *)0x0;
                local_24[0xb] = (undefined *)0x0;
                local_24[9] = (undefined *)0x0;
                local_24[10] = (undefined *)0x0;
                *(undefined2 *)(local_24 + 0x14) = 0;
                *(undefined2 *)((int)local_24 + 0x4e) = 0;
                *(undefined2 *)(local_24 + 0x13) = 0;
                *(undefined2 *)(local_24 + 0x18) = 0;
                local_24[0x19] = (undefined *)0x0;
                local_24[0x17] = (undefined *)0x0;
                local_24[0x15] = (undefined *)0x0;
                local_24[0x16] = (undefined *)0x0;
                local_24[0x21] = (undefined *)0x0;
                local_24[3] = (undefined *)0x4;
              }
              uVar1 = J3DAnmKeyLoader_v15::load(aJStack40,pData);
              J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack40);
              return uVar1;
            }
          }
          else {
            if (iVar2 == 0x62786b31) {
              J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack56);
              local_34 = (undefined **)JKernel::operator_new(0x34);
              if (local_34 != (undefined **)0x0) {
                *local_34 = (undefined *)&J3DAnmBase::__vt;
                local_34[2] = (undefined *)J3DGraphLoader::_1664;
                *(undefined2 *)((int)local_34 + 6) = 0;
                *local_34 = &J3DAnmVtxColor::__vt;
                local_34[3] = (undefined *)0x7;
                iVar2 = 0;
                iVar3 = 2;
                do {
                  *(undefined2 *)((int)local_34 + iVar2 + 0x10) = 0;
                  iVar2 = iVar2 + 2;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
                iVar2 = 0;
                iVar3 = 2;
                do {
                  *(undefined4 *)((int)local_34 + iVar2 + 0x14) = 0;
                  iVar2 = iVar2 + 4;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
                *local_34 = &J3DAnmVtxColorKey::__vt;
                iVar2 = 0;
                iVar3 = 2;
                do {
                  *(undefined4 *)((int)local_34 + iVar2 + 0x1c) = 0;
                  iVar2 = iVar2 + 4;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
              }
              uVar1 = J3DAnmKeyLoader_v15::load(aJStack56,pData);
              J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack56);
              return uVar1;
            }
            if ((iVar2 < 0x62786b31) && (iVar2 == 0x62786131)) {
              J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack104);
              local_64 = (undefined **)JKernel::operator_new(0x34);
              if (local_64 != (undefined **)0x0) {
                *local_64 = (undefined *)&J3DAnmBase::__vt;
                local_64[2] = (undefined *)J3DGraphLoader::_1664;
                *(undefined2 *)((int)local_64 + 6) = 0;
                *local_64 = &J3DAnmVtxColor::__vt;
                local_64[3] = (undefined *)0x7;
                iVar2 = 0;
                iVar3 = 2;
                do {
                  *(undefined2 *)((int)local_64 + iVar2 + 0x10) = 0;
                  iVar2 = iVar2 + 2;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
                iVar2 = 0;
                iVar3 = 2;
                do {
                  *(undefined4 *)((int)local_64 + iVar2 + 0x14) = 0;
                  iVar2 = iVar2 + 4;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
                *local_64 = &J3DAnmVtxColorFull::__vt;
                iVar2 = 0;
                iVar3 = 2;
                do {
                  *(undefined4 *)((int)local_64 + iVar2 + 0x1c) = 0;
                  iVar2 = iVar2 + 4;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
              }
              uVar1 = J3DAnmFullLoader_v15::load(aJStack104,pData);
              J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack104);
              return uVar1;
            }
          }
        }
        m_Do_printf::OSReport("J3DAnmLoader: this is not a J3D Binary.\n");
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

}

/* __thiscall J3DAnmLoaderDataBase::setResource(J3DAnmBase *,
                                                void const *) */

void __thiscall
J3DAnmLoaderDataBase::setResource(J3DAnmLoaderDataBase *this,J3DAnmBase *param_1,void *param_2)

{
  int iVar1;
  J3DAnmFullLoader_v15 aJStack104 [8];
  J3DAnmFullLoader_v15 aJStack96 [8];
  J3DAnmFullLoader_v15 aJStack88 [8];
  J3DAnmFullLoader_v15 aJStack80 [8];
  J3DAnmFullLoader_v15 aJStack72 [8];
  J3DAnmFullLoader_v15 aJStack64 [8];
  J3DAnmKeyLoader_v15 aJStack56 [8];
  J3DAnmKeyLoader_v15 aJStack48 [8];
  J3DAnmKeyLoader_v15 aJStack40 [8];
  J3DAnmKeyLoader_v15 aJStack32 [8];
  J3DAnmKeyLoader_v15 aJStack24 [8];
  J3DAnmKeyLoader_v15 aJStack16 [8];
  
  if ((param_1 != (J3DAnmBase *)0x0) && (param_1->vtbl == (undefined *)0x4a334431)) {
    iVar1 = *(int *)&param_1->mLoopMode;
    if (iVar1 == 0x62726b31) {
      J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack48);
      if (*(int *)(this + 0xc) == 5) {
        J3DAnmKeyLoader_v15::setResource(aJStack48,(J3DAnmBase *)this,param_1);
      }
      J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack48);
    }
    else {
      if (iVar1 < 0x62726b31) {
        if (iVar1 == 0x626c6b31) {
          J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack32);
          J3DAnmKeyLoader_v15::setResource(aJStack32,(J3DAnmBase *)this,param_1);
          J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack32);
          return;
        }
        if (iVar1 < 0x626c6b31) {
          if (iVar1 == 0x62636b31) {
            J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack16);
            J3DAnmKeyLoader_v15::setResource(aJStack16,(J3DAnmBase *)this,param_1);
            J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack16);
            return;
          }
          if (iVar1 < 0x62636b31) {
            if (iVar1 == 0x62636131) {
              J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack64);
              J3DAnmFullLoader_v15::setResource(aJStack64,(J3DAnmBase *)this,param_1);
              J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack64);
              return;
            }
          }
          else {
            if (iVar1 == 0x626c6131) {
              J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack88);
              J3DAnmFullLoader_v15::setResource(aJStack88,(J3DAnmBase *)this,param_1);
              J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack88);
              return;
            }
          }
        }
        else {
          if (iVar1 == 0x62706b31) {
            J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack24);
            J3DAnmKeyLoader_v15::setResource(aJStack24,(J3DAnmBase *)this,param_1);
            J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack24);
            return;
          }
          if ((iVar1 < 0x62706b31) && (iVar1 == 0x62706131)) {
            J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack72);
            J3DAnmFullLoader_v15::setResource(aJStack72,(J3DAnmBase *)this,param_1);
            J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack72);
            return;
          }
        }
      }
      else {
        if (iVar1 == 0x62766131) {
          J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack104);
          J3DAnmFullLoader_v15::setResource(aJStack104,(J3DAnmBase *)this,param_1);
          J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack104);
          return;
        }
        if (iVar1 < 0x62766131) {
          if (iVar1 == 0x62747031) {
            J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack80);
            J3DAnmFullLoader_v15::setResource(aJStack80,(J3DAnmBase *)this,param_1);
            J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack80);
            return;
          }
          if ((iVar1 < 0x62747031) && (iVar1 == 0x62746b31)) {
            J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack40);
            J3DAnmKeyLoader_v15::setResource(aJStack40,(J3DAnmBase *)this,param_1);
            J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack40);
            return;
          }
        }
        else {
          if (iVar1 == 0x62786b31) {
            J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(aJStack56);
            J3DAnmKeyLoader_v15::setResource(aJStack56,(J3DAnmBase *)this,param_1);
            J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(aJStack56);
            return;
          }
          if ((iVar1 < 0x62786b31) && (iVar1 == 0x62786131)) {
            J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(aJStack96);
            J3DAnmFullLoader_v15::setResource(aJStack96,(J3DAnmBase *)this,param_1);
            J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(aJStack96);
            return;
          }
        }
      }
      m_Do_printf::OSReport("J3DAnmLoader: this is not a J3D Binary.\n");
    }
  }
  return;
}


/* __thiscall J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(void) */

void __thiscall J3DAnmFullLoader_v15::J3DAnmFullLoader_v15(J3DAnmFullLoader_v15 *this)

{
  *(undefined1 **)this = &J3DAnmLoader::__vt;
  *(undefined1 **)this = &__vt;
  return;
}


/* __thiscall J3DAnmFullLoader_v15::~J3DAnmFullLoader_v15(void) */

void __thiscall J3DAnmFullLoader_v15::_J3DAnmFullLoader_v15(J3DAnmFullLoader_v15 *this)

{
  short in_r4;
  
  if (this != (J3DAnmFullLoader_v15 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmFullLoader_v15 *)0x0) {
      *(undefined1 **)this = &J3DAnmLoader::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(void) */

void __thiscall J3DAnmKeyLoader_v15::J3DAnmKeyLoader_v15(J3DAnmKeyLoader_v15 *this)

{
  *(undefined1 **)this = &J3DAnmLoader::__vt;
  *(undefined1 **)this = &__vt;
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::~J3DAnmKeyLoader_v15(void) */

void __thiscall J3DAnmKeyLoader_v15::_J3DAnmKeyLoader_v15(J3DAnmKeyLoader_v15 *this)

{
  short in_r4;
  
  if (this != (J3DAnmKeyLoader_v15 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmKeyLoader_v15 *)0x0) {
      *(undefined1 **)this = &J3DAnmLoader::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DAnmFullLoader_v15::load(void const *) */

undefined4 __thiscall J3DAnmFullLoader_v15::load(J3DAnmFullLoader_v15 *this,void *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)((int)param_1 + 0x20);
  uVar2 = 0;
  do {
    if (*(uint *)((int)param_1 + 0xc) <= uVar2) {
      return *(undefined4 *)(this + 4);
    }
    iVar1 = *piVar3;
    if (iVar1 == 0x54505431) {
      readAnmTexPattern(this,(J3DAnmTexPatternFullData *)piVar3);
    }
    else {
      if (iVar1 < 0x54505431) {
        if (iVar1 == 0x434c4631) {
          readAnmCluster(this,(J3DAnmClusterFullData *)piVar3);
        }
        else {
          if (iVar1 < 0x434c4631) {
            if (iVar1 == 0x414e4631) {
              readAnmTransform(this,(J3DAnmTransformFullData *)piVar3);
            }
            else {
LAB_802ffbe0:
              m_Do_printf::OSReport("Unknown data block\n");
            }
          }
          else {
            if (iVar1 != 0x50414631) goto LAB_802ffbe0;
            readAnmColor(this,(J3DAnmColorFullData *)piVar3);
          }
        }
      }
      else {
        if (iVar1 == 0x56434631) {
          readAnmVtxColor(this,(J3DAnmVtxColorFullData *)piVar3);
        }
        else {
          if ((0x56434630 < iVar1) || (iVar1 != 0x56414631)) goto LAB_802ffbe0;
          readAnmVisibility(this,(J3DAnmVisibilityFullData *)piVar3);
        }
      }
    }
    piVar3 = (int *)((int)piVar3 + piVar3[1]);
    uVar2 = uVar2 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DAnmFullLoader_v15::setResource(J3DAnmBase *,
                                                void const *) */

void __thiscall
J3DAnmFullLoader_v15::setResource(J3DAnmFullLoader_v15 *this,J3DAnmBase *param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)((int)param_2 + 0x20);
  uVar2 = 0;
  do {
    if (*(uint *)((int)param_2 + 0xc) <= uVar2) {
      return;
    }
    iVar1 = *piVar3;
    if (iVar1 == 0x54505431) {
      if (param_1[1].vtbl == (undefined *)0x2) {
        setAnmTexPattern(this,(J3DAnmTexPattern *)param_1,(J3DAnmTexPatternFullData *)piVar3);
      }
    }
    else {
      if (iVar1 < 0x54505431) {
        if (iVar1 == 0x434c4631) {
          if (param_1[1].vtbl == (undefined *)0x3) {
            setAnmCluster(this,(J3DAnmClusterFull *)param_1,(J3DAnmClusterFullData *)piVar3);
          }
        }
        else {
          if (iVar1 < 0x434c4631) {
            if (iVar1 == 0x414e4631) {
              if (param_1[1].vtbl == (undefined *)0x0) {
                setAnmTransform(this,(J3DAnmTransformFull *)param_1,
                                (J3DAnmTransformFullData *)piVar3);
              }
            }
            else {
LAB_802ffd90:
              m_Do_printf::OSReport("Unknown data block\n");
            }
          }
          else {
            if (iVar1 != 0x50414631) goto LAB_802ffd90;
            if (param_1[1].vtbl == (undefined *)0x1) {
              setAnmColor(this,(J3DAnmColorFull *)param_1,(J3DAnmColorFullData *)piVar3);
            }
          }
        }
      }
      else {
        if (iVar1 == 0x56434631) {
          if (param_1[1].vtbl == (undefined *)0x7) {
            setAnmVtxColor(this,(J3DAnmVtxColorFull *)param_1,(J3DAnmVtxColorFullData *)piVar3);
          }
        }
        else {
          if ((0x56434630 < iVar1) || (iVar1 != 0x56414631)) goto LAB_802ffd90;
          if (param_1[1].vtbl == (undefined *)0x6) {
            setAnmVisibility(this,(J3DAnmVisibilityFull *)param_1,(J3DAnmVisibilityFullData *)piVar3
                            );
          }
        }
      }
    }
    piVar3 = (int *)((int)piVar3 + piVar3[1]);
    uVar2 = uVar2 + 1;
  } while( true );
}


/* __thiscall J3DAnmFullLoader_v15::readAnmTransform(J3DAnmTransformFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::readAnmTransform(J3DAnmFullLoader_v15 *this,J3DAnmTransformFullData *param_1)

{
  setAnmTransform(this,*(J3DAnmTransformFull **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmFullLoader_v15::setAnmTransform(J3DAnmTransformFull *,
                                                    J3DAnmTransformFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::setAnmTransform
          (J3DAnmFullLoader_v15 *this,J3DAnmTransformFull *param_1,J3DAnmTransformFullData *param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 10);
  param_1[4] = *(J3DAnmTransformFull *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x1c));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x20));
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return;
}


/* __thiscall J3DAnmFullLoader_v15::readAnmColor(J3DAnmColorFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::readAnmColor(J3DAnmFullLoader_v15 *this,J3DAnmColorFullData *param_1)

{
  setAnmColor(this,*(J3DAnmColorFull **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmFullLoader_v15::setAnmColor(J3DAnmColorFull *,
                                                J3DAnmColorFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::setAnmColor
          (J3DAnmFullLoader_v15 *this,J3DAnmColorFull *param_1,J3DAnmColorFullData *param_2)

{
  undefined4 uVar1;
  ResNTAB *pRVar2;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 0xc);
  param_1[4] = *(J3DAnmColorFull *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_2 + 0xe);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x28));
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x2c));
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x30));
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x1c));
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  pRVar2 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x20))
  ;
  JUTNameTab::setResource((JUTNameTab *)(param_1 + 0x20),pRVar2);
  return;
}


/* __thiscall J3DAnmFullLoader_v15::readAnmTexPattern(J3DAnmTexPatternFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::readAnmTexPattern
          (J3DAnmFullLoader_v15 *this,J3DAnmTexPatternFullData *param_1)

{
  setAnmTexPattern(this,*(J3DAnmTexPattern **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmFullLoader_v15::setAnmTexPattern(J3DAnmTexPattern *,
                                                     J3DAnmTexPatternFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::setAnmTexPattern
          (J3DAnmFullLoader_v15 *this,J3DAnmTexPattern *param_1,J3DAnmTexPatternFullData *param_2)

{
  int iVar1;
  undefined4 uVar2;
  ResNTAB *pRVar3;
  
  param_1->field_0x6 = *(short *)(param_2 + 10);
  *(J3DAnmTexPatternFullData *)&param_1->field_0x4 = param_2[8];
  param_1->field_0x8 = J3DGraphLoader::_1664;
  *(undefined2 *)&param_1[1].field_0x2 = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 0xe);
  iVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x10));
  param_1->field_0x14 = iVar1;
  iVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x14));
  param_1->field_0x10 = iVar1;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)&param_1[1].field_0x4 = uVar2;
  pRVar3 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x1c))
  ;
  JUTNameTab::setResource((JUTNameTab *)&param_1[1].field_0x8,pRVar3);
  return;
}


/* __thiscall J3DAnmFullLoader_v15::readAnmVisibility(J3DAnmVisibilityFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::readAnmVisibility
          (J3DAnmFullLoader_v15 *this,J3DAnmVisibilityFullData *param_1)

{
  setAnmVisibility(this,*(J3DAnmVisibilityFull **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmFullLoader_v15::setAnmVisibility(J3DAnmVisibilityFull *,
                                                     J3DAnmVisibilityFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::setAnmVisibility
          (J3DAnmFullLoader_v15 *this,J3DAnmVisibilityFull *param_1,
          J3DAnmVisibilityFullData *param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 10);
  param_1[4] = *(J3DAnmVisibilityFull *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_2 + 0xe);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x10));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  return;
}


/* __thiscall J3DAnmFullLoader_v15::readAnmCluster(J3DAnmClusterFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::readAnmCluster(J3DAnmFullLoader_v15 *this,J3DAnmClusterFullData *param_1)

{
  setAnmCluster(this,*(J3DAnmClusterFull **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmFullLoader_v15::setAnmCluster(J3DAnmClusterFull *,
                                                  J3DAnmClusterFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::setAnmCluster
          (J3DAnmFullLoader_v15 *this,J3DAnmClusterFull *param_1,J3DAnmClusterFullData *param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 10);
  param_1[4] = *(J3DAnmClusterFull *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x10));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  return;
}


/* __thiscall J3DAnmFullLoader_v15::readAnmVtxColor(J3DAnmVtxColorFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::readAnmVtxColor(J3DAnmFullLoader_v15 *this,J3DAnmVtxColorFullData *param_1)

{
  setAnmVtxColor(this,*(J3DAnmVtxColorFull **)(this + 4),param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DAnmFullLoader_v15::setAnmVtxColor(J3DAnmVtxColorFull *,
                                                   J3DAnmVtxColorFullData const *) */

void __thiscall
J3DAnmFullLoader_v15::setAnmVtxColor
          (J3DAnmFullLoader_v15 *this,J3DAnmVtxColorFull *param_1,J3DAnmVtxColorFullData *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 10);
  param_1[4] = *(J3DAnmVtxColorFull *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_2 + 0xe);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x1c));
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x20));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  iVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x28));
  iVar3 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x2c));
  iVar4 = 0;
  for (iVar5 = 0; iVar5 < (int)(uint)*(ushort *)(param_1 + 0x10); iVar5 = iVar5 + 1) {
    *(int *)(*(int *)(param_1 + 0x14) + iVar4 + 4) =
         iVar2 + *(int *)(*(int *)(param_1 + 0x14) + iVar4 + 4) * 2;
    iVar4 = iVar4 + 8;
  }
  iVar2 = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)*(ushort *)(param_1 + 0x12); iVar4 = iVar4 + 1) {
    *(int *)(*(int *)(param_1 + 0x18) + iVar2 + 4) =
         iVar3 + *(int *)(*(int *)(param_1 + 0x18) + iVar2 + 4) * 2;
    iVar2 = iVar2 + 8;
  }
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x30));
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x34));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x38));
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x3c));
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DAnmKeyLoader_v15::load(void const *) */

undefined4 __thiscall J3DAnmKeyLoader_v15::load(J3DAnmKeyLoader_v15 *this,void *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)((int)param_1 + 0x20);
  uVar2 = 0;
  do {
    if (*(uint *)((int)param_1 + 0xc) <= uVar2) {
      return *(undefined4 *)(this + 4);
    }
    iVar1 = *piVar3;
    if (iVar1 == 0x54524b31) {
      readAnmTevReg(this,(J3DAnmTevRegKeyData *)piVar3);
    }
    else {
      if (iVar1 < 0x54524b31) {
        if (iVar1 == 0x434c4b31) {
          readAnmCluster(this,(J3DAnmClusterKeyData *)piVar3);
        }
        else {
          if (iVar1 < 0x434c4b31) {
            if (iVar1 == 0x414e4b31) {
              readAnmTransform(this,(J3DAnmTransformKeyData *)piVar3);
            }
            else {
LAB_8030041c:
              m_Do_printf::OSReport("Unknown data block\n");
            }
          }
          else {
            if (iVar1 != 0x50414b31) goto LAB_8030041c;
            readAnmColor(this,(J3DAnmColorKeyData *)piVar3);
          }
        }
      }
      else {
        if (iVar1 == 0x56434b31) {
          readAnmVtxColor(this,(J3DAnmVtxColorKeyData *)piVar3);
        }
        else {
          if ((0x56434b30 < iVar1) || (iVar1 != 0x54544b31)) goto LAB_8030041c;
          readAnmTextureSRT(this,(J3DAnmTextureSRTKeyData *)piVar3);
        }
      }
    }
    piVar3 = (int *)((int)piVar3 + piVar3[1]);
    uVar2 = uVar2 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DAnmKeyLoader_v15::setResource(J3DAnmBase *,
                                               void const *) */

void __thiscall
J3DAnmKeyLoader_v15::setResource(J3DAnmKeyLoader_v15 *this,J3DAnmBase *param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)((int)param_2 + 0x20);
  uVar2 = 0;
  do {
    if (*(uint *)((int)param_2 + 0xc) <= uVar2) {
      return;
    }
    iVar1 = *piVar3;
    if (iVar1 == 0x54524b31) {
      if (param_1[1].vtbl == (undefined *)0x5) {
        setAnmTevReg(this,(J3DAnmTevRegKey *)param_1,(J3DAnmTevRegKeyData *)piVar3);
      }
    }
    else {
      if (iVar1 < 0x54524b31) {
        if (iVar1 == 0x434c4b31) {
          if (param_1[1].vtbl == (undefined *)0x3) {
            setAnmCluster(this,(J3DAnmClusterKey *)param_1,(J3DAnmClusterKeyData *)piVar3);
          }
        }
        else {
          if (iVar1 < 0x434c4b31) {
            if (iVar1 == 0x414e4b31) {
              if (param_1[1].vtbl == (undefined *)0x0) {
                setAnmTransform(this,(J3DAnmTransformKey *)param_1,(J3DAnmTransformKeyData *)piVar3)
                ;
              }
            }
            else {
LAB_803005cc:
              m_Do_printf::OSReport("Unknown data block\n");
            }
          }
          else {
            if (iVar1 != 0x50414b31) goto LAB_803005cc;
            if (param_1[1].vtbl == (undefined *)0x1) {
              setAnmColor(this,(J3DAnmColorKey *)param_1,(J3DAnmColorKeyData *)piVar3);
            }
          }
        }
      }
      else {
        if (iVar1 == 0x56434b31) {
          if (param_1[1].vtbl == (undefined *)0x7) {
            setAnmVtxColor(this,(J3DAnmVtxColorKey *)param_1,(J3DAnmVtxColorKeyData *)piVar3);
          }
        }
        else {
          if ((0x56434b30 < iVar1) || (iVar1 != 0x54544b31)) goto LAB_803005cc;
          if (param_1[1].vtbl == (undefined *)0x4) {
            setAnmTextureSRT(this,(J3DAnmTextureSRTKey *)param_1,(J3DAnmTextureSRTKeyData *)piVar3);
          }
        }
      }
    }
    piVar3 = (int *)((int)piVar3 + piVar3[1]);
    uVar2 = uVar2 + 1;
  } while( true );
}


/* __thiscall J3DAnmKeyLoader_v15::readAnmTransform(J3DAnmTransformKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::readAnmTransform(J3DAnmKeyLoader_v15 *this,J3DAnmTransformKeyData *param_1)

{
  setAnmTransform(this,*(J3DAnmTransformKey **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::setAnmTransform(J3DAnmTransformKey *,
                                                   J3DAnmTransformKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::setAnmTransform
          (J3DAnmKeyLoader_v15 *this,J3DAnmTransformKey *param_1,J3DAnmTransformKeyData *param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)&param_1->field_0x22 = *(undefined2 *)(param_2 + 0xc);
  (param_1->parent).parent.mDuration = *(short *)(param_2 + 10);
  *(J3DAnmTransformKeyData *)&(param_1->parent).parent.mLoopMode = param_2[8];
  *(uint *)&param_1->field_0x24 = (uint)(byte)param_2[9];
  (param_1->parent).parent.mCurrentTime = J3DGraphLoader::_1664;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)&param_1->field_0x28 = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)&(param_1->parent).field_0x10 = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x1c));
  *(undefined4 *)&(param_1->parent).field_0x14 = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x20));
  *(undefined4 *)&(param_1->parent).field_0x18 = uVar1;
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::readAnmTextureSRT(J3DAnmTextureSRTKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::readAnmTextureSRT(J3DAnmKeyLoader_v15 *this,J3DAnmTextureSRTKeyData *param_1)

{
  setAnmTextureSRT(this,*(J3DAnmTextureSRTKey **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::setAnmTextureSRT(J3DAnmTextureSRTKey *,
                                                    J3DAnmTextureSRTKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::setAnmTextureSRT
          (J3DAnmKeyLoader_v15 *this,J3DAnmTextureSRTKey *param_1,J3DAnmTextureSRTKeyData *param_2)

{
  float fVar1;
  undefined4 uVar2;
  ResNTAB *pRVar3;
  undefined *puVar4;
  
  param_1->mTrackCount = *(short *)(param_2 + 0xc);
  (param_1->parent).mDuration = *(short *)(param_2 + 10);
  *(J3DAnmTextureSRTKeyData *)&(param_1->parent).mLoopMode = param_2[8];
  param_1->field_0x10 = (undefined *)(uint)(byte)param_2[9];
  (param_1->parent).mCurrentTime = J3DGraphLoader::_1664;
  param_1->mTrackCount = *(short *)(param_2 + 0xc);
  *(undefined2 *)&param_1->field_0x1c = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)&param_1->field_0x1e = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)&param_1->field_0x20 = *(undefined2 *)(param_2 + 0x12);
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)&param_1->field_0x18 = uVar2;
  pRVar3 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x18))
  ;
  (param_1->mMaterialNameTable).mpRes = pRVar3;
  pRVar3 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x1c))
  ;
  JUTNameTab::setResource((JUTNameTab *)&(param_1->mMaterialNameTable).mpStrData,pRVar3);
  puVar4 = (undefined *)
           J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x20));
  (param_1->mMaterialNameTable).vtbl = puVar4;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)&param_1->field_0x48 = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x28));
  *(undefined4 *)&param_1->field_0x24 = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x2c));
  *(undefined4 *)&param_1->field_0x28 = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x30));
  *(undefined4 *)&param_1->field_0x2c = uVar2;
  if (*(int *)(param_2 + 0x44) != 0) {
    pRVar3 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_2);
    JUTNameTab::setResource((JUTNameTab *)&param_1->field_0x70,pRVar3);
  }
  *(undefined2 *)&param_1->field_0x60 = *(undefined2 *)(param_2 + 0x34);
  *(undefined2 *)&param_1->field_0x4c = *(undefined2 *)(param_2 + 0x36);
  *(undefined2 *)&param_1->field_0x4e = *(undefined2 *)(param_2 + 0x38);
  *(undefined2 *)&param_1->field_0x50 = *(undefined2 *)(param_2 + 0x3a);
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x3c));
  *(undefined4 *)&param_1->field_0x64 = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x40));
  *(undefined4 *)&param_1->field_0x6c = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x48));
  *(undefined4 *)&param_1->field_0x68 = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x4c));
  *(undefined4 *)&param_1[1].parent.mLoopMode = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x50));
  *(undefined4 *)&param_1->field_0x54 = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x54));
  *(undefined4 *)&param_1->field_0x58 = uVar2;
  uVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x58));
  *(undefined4 *)&param_1->field_0x5c = uVar2;
  fVar1 = *(float *)(param_2 + 0x5c);
  if (((int)fVar1 < 2) && (-1 < (int)fVar1)) {
    param_1[1].parent.mCurrentTime = fVar1;
  }
  else {
    param_1[1].parent.mCurrentTime = 0.0;
  }
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::readAnmColor(J3DAnmColorKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::readAnmColor(J3DAnmKeyLoader_v15 *this,J3DAnmColorKeyData *param_1)

{
  setAnmColor(this,*(J3DAnmColorKey **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::setAnmColor(J3DAnmColorKey *,
                                               J3DAnmColorKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::setAnmColor
          (J3DAnmKeyLoader_v15 *this,J3DAnmColorKey *param_1,J3DAnmColorKeyData *param_2)

{
  undefined4 uVar1;
  ResNTAB *pRVar2;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 0xc);
  param_1[4] = *(J3DAnmColorKey *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_2 + 0x12);
  *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(param_1 + 0x16) = *(undefined2 *)(param_2 + 0x16);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x28));
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x2c));
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x30));
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x1c));
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  pRVar2 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x20))
  ;
  JUTNameTab::setResource((JUTNameTab *)(param_1 + 0x20),pRVar2);
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::readAnmCluster(J3DAnmClusterKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::readAnmCluster(J3DAnmKeyLoader_v15 *this,J3DAnmClusterKeyData *param_1)

{
  setAnmCluster(this,*(J3DAnmClusterKey **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::setAnmCluster(J3DAnmClusterKey *,
                                                 J3DAnmClusterKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::setAnmCluster
          (J3DAnmKeyLoader_v15 *this,J3DAnmClusterKey *param_1,J3DAnmClusterKeyData *param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 10);
  param_1[4] = *(J3DAnmClusterKey *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x10));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::readAnmTevReg(J3DAnmTevRegKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::readAnmTevReg(J3DAnmKeyLoader_v15 *this,J3DAnmTevRegKeyData *param_1)

{
  setAnmTevReg(this,*(J3DAnmTevRegKey **)(this + 4),param_1);
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::setAnmTevReg(J3DAnmTevRegKey *,
                                                J3DAnmTevRegKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::setAnmTevReg
          (J3DAnmKeyLoader_v15 *this,J3DAnmTevRegKey *param_1,J3DAnmTevRegKeyData *param_2)

{
  undefined4 uVar1;
  ResNTAB *pRVar2;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 10);
  param_1[4] = *(J3DAnmTevRegKey *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_2 + 0xc);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x20));
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x28));
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  pRVar2 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x30))
  ;
  JUTNameTab::setResource((JUTNameTab *)(param_1 + 0x28),pRVar2);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_2 + 0xe);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x2c));
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  pRVar2 = (ResNTAB *)J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x34))
  ;
  JUTNameTab::setResource((JUTNameTab *)(param_1 + 0x3c),pRVar2);
  *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(param_1 + 0x16) = *(undefined2 *)(param_2 + 0x12);
  *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(param_2 + 0x16);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x38));
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x3c));
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x40));
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x44));
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_2 + 0x18);
  *(undefined2 *)(param_1 + 0x1e) = *(undefined2 *)(param_2 + 0x1a);
  *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_2 + 0x1c);
  *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(param_2 + 0x1e);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x48));
  *(undefined4 *)(param_1 + 100) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x4c));
  *(undefined4 *)(param_1 + 0x68) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x50));
  *(undefined4 *)(param_1 + 0x6c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x54));
  *(undefined4 *)(param_1 + 0x70) = uVar1;
  return;
}


/* __thiscall J3DAnmKeyLoader_v15::readAnmVtxColor(J3DAnmVtxColorKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::readAnmVtxColor(J3DAnmKeyLoader_v15 *this,J3DAnmVtxColorKeyData *param_1)

{
  setAnmVtxColor(this,*(J3DAnmVtxColorKey **)(this + 4),param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DAnmKeyLoader_v15::setAnmVtxColor(J3DAnmVtxColorKey *,
                                                  J3DAnmVtxColorKeyData const *) */

void __thiscall
J3DAnmKeyLoader_v15::setAnmVtxColor
          (J3DAnmKeyLoader_v15 *this,J3DAnmVtxColorKey *param_1,J3DAnmVtxColorKeyData *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 10);
  param_1[4] = *(J3DAnmVtxColorKey *)(param_2 + 8);
  *(float *)(param_1 + 8) = J3DGraphLoader::_1664;
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_2 + 0xe);
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x18));
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x1c));
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x20));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x24));
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  iVar2 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x28));
  iVar3 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x2c));
  iVar4 = 0;
  for (iVar5 = 0; iVar5 < (int)(uint)*(ushort *)(param_1 + 0x10); iVar5 = iVar5 + 1) {
    *(int *)(*(int *)(param_1 + 0x14) + iVar4 + 4) =
         iVar2 + *(int *)(*(int *)(param_1 + 0x14) + iVar4 + 4) * 2;
    iVar4 = iVar4 + 8;
  }
  iVar2 = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)*(ushort *)(param_1 + 0x12); iVar4 = iVar4 + 1) {
    *(int *)(*(int *)(param_1 + 0x18) + iVar2 + 4) =
         iVar3 + *(int *)(*(int *)(param_1 + 0x18) + iVar2 + 4) * 2;
    iVar2 = iVar2 + 8;
  }
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x30));
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x34));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x38));
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_2,*(undefined4 *)(param_2 + 0x3c));
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  return;
}


/* __thiscall J3DAnmVisibilityFull::~J3DAnmVisibilityFull(void) */

void __thiscall J3DAnmVisibilityFull::_J3DAnmVisibilityFull(J3DAnmVisibilityFull *this)

{
  short in_r4;
  
  if (this != (J3DAnmVisibilityFull *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmVisibilityFull *)0x0) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmTevRegKey::~J3DAnmTevRegKey(void) */

void __thiscall J3DAnmTevRegKey::_J3DAnmTevRegKey(J3DAnmTevRegKey *this)

{
  short in_r4;
  
  if (this != (J3DAnmTevRegKey *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmTevRegKey *)0xffffffc4) {
      *(undefined1 **)(this + 0x3c) = &JUTNameTab::__vt;
    }
    if (this != (J3DAnmTevRegKey *)0xffffffd8) {
      *(undefined1 **)(this + 0x28) = &JUTNameTab::__vt;
    }
    if (this != (J3DAnmTevRegKey *)0x0) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmLoader::~J3DAnmLoader(void) */

void __thiscall J3DAnmLoader::_J3DAnmLoader(J3DAnmLoader *this)

{
  short in_r4;
  
  if ((this != (J3DAnmLoader *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace J3DGraphLoader {

/* __stdcall JSUConvertOffsetToPtr<J3DAnmKRegKeyTable>(void const *,
                                                       void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmCRegKeyTable>(void const *,
                                                       void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmClusterKeyTable>(void const *,
                                                          void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmColorKeyTable>(void const *,
                                                        void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<Vec>(void const *,
                                        void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmTransformKeyTable>(void const *,
                                                            void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmVtxColorIndexData>(void const *,
                                                            void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmClusterFullTable>(void const *,
                                                           void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmVisibilityFullTable>(void const *,
                                                              void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmTexPatternFullTable>(void const *,
                                                              void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmColorFullTable>(void const *,
                                                         void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<short>(void const *,
                                          void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DAnmTransformFullTable>(void const *,
                                                             void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

