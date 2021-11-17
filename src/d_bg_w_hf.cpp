#include <d_bg_w_hf.h>
#include <SComponent/c_bg_w.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_m3d_g_pla.h>
#include <d_bg_w_hf.h>
#include <dBgWHf.h>
#include <dBgWSv.h>


/* __thiscall dBgWHf::Set(cBgD_t *,
                          unsigned short *,
                          float,
                          int,
                          int,
                          unsigned long) */

uint __thiscall
dBgWHf::Set(dBgWHf *this,cBgD_t *param_1,ushort *param_2,float param_3,int param_4,int param_5,
           ulong param_6)

{
  uint uVar1;
  undefined4 uVar2;
  
  *(int *)&this->field_0xcc = param_4;
  *(int *)&this->field_0xd0 = param_5;
  *(ushort **)&this->field_0xc8 = param_2;
  *(float *)&this->field_0xc4 = param_3;
  uVar1 = cBgW::Set((cBgW *)this,param_1,0x33,(MTX34 *)0x0);
  if ((uVar1 & 0xff) == 0) {
    *(ulong *)&this->field_0xbc = param_6;
    if ((*(uint *)&this->field_0xbc & 1) == 0) {
      uVar2 = JKernel::operator_new__(((this->parent).parent.mpBgDt)->mVtxCount * 0xc);
      *(undefined4 *)&this->field_0xc0 = uVar2;
      uVar1 = countLeadingZeros(*(undefined4 *)&this->field_0xc0);
      uVar1 = uVar1 >> 5 & 0xff;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgWHf::CalcPlane(void) */

void __thiscall dBgWHf::CalcPlane(dBgWHf *this)

{
  bool bVar1;
  cBgD_t *pcVar2;
  ulong uVar3;
  cBgD__Tri_t *pcVar4;
  cXyz *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  cBgD__Tri_t *pcVar11;
  float local_28;
  undefined4 local_24;
  float local_20;
  
  if ((this->parent).parent.mpVtxTbl != (cXyz *)0x0) {
    pcVar2 = (this->parent).parent.mpBgDt;
    pcVar11 = pcVar2->mpTriTbl;
    if (pcVar2->mTriCount != *(int *)&this->field_0xcc * *(int *)&this->field_0xd0 * 2) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar3,"d_bg_w_hf.cpp",0x54,"m_gridx * m_gridz * 2 == pm_bgd->m_t_num");
      m_Do_printf::OSPanic("d_bg_w_hf.cpp",0x54,&DAT_80353b6f);
    }
    iVar10 = 0;
    bVar1 = true;
    for (iVar9 = 0; iVar9 < *(int *)&this->field_0xd0 << 1; iVar9 = iVar9 + 1) {
      if (bVar1) {
        iVar7 = iVar10 << 1;
        for (iVar8 = 0; iVar8 < *(int *)&this->field_0xcc; iVar8 = iVar8 + 1) {
          uVar6 = (uint)*(ushort *)(*(int *)&this->field_0xc8 + iVar7);
          pcVar5 = (this->parent).parent.mpVtxTbl;
          pcVar4 = pcVar11 + uVar6;
          local_28 = pcVar5[(ushort)pcVar4->mVtxIdx1].y - pcVar5[(ushort)pcVar4->mVtxIdx0].y;
          local_24 = *(undefined4 *)&this->field_0xc4;
          local_20 = pcVar5[(ushort)pcVar4->mVtxIdx1].y - pcVar5[(ushort)pcVar4->mVtxIdx2].y;
          cM3dGPla::SetupNP0(&(this->parent).parent.mpTriElm[uVar6].mPlane,(Vec *)&local_28,
                             (Vec *)(pcVar5 + (ushort)pcVar4->mVtxIdx0));
          iVar10 = iVar10 + 1;
          iVar7 = iVar7 + 2;
        }
        bVar1 = false;
      }
      else {
        iVar7 = iVar10 << 1;
        for (iVar8 = 0; iVar8 < *(int *)&this->field_0xcc; iVar8 = iVar8 + 1) {
          uVar6 = (uint)*(ushort *)(*(int *)&this->field_0xc8 + iVar7);
          pcVar5 = (this->parent).parent.mpVtxTbl;
          pcVar4 = pcVar11 + uVar6;
          local_28 = pcVar5[(ushort)pcVar4->mVtxIdx0].y - pcVar5[(ushort)pcVar4->mVtxIdx1].y;
          local_24 = *(undefined4 *)&this->field_0xc4;
          local_20 = pcVar5[(ushort)pcVar4->mVtxIdx2].y - pcVar5[(ushort)pcVar4->mVtxIdx1].y;
          cM3dGPla::SetupNP0(&(this->parent).parent.mpTriElm[uVar6].mPlane,(Vec *)&local_28,
                             (Vec *)(pcVar5 + (ushort)pcVar4->mVtxIdx0));
          iVar10 = iVar10 + 1;
          iVar7 = iVar7 + 2;
        }
        bVar1 = true;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dBgWHf::ClassifyPlane(void) */

void __thiscall dBgWHf::ClassifyPlane(dBgWHf *this)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  cBgD_t *pcVar5;
  ushort *puVar6;
  uint idx;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_28 [3];
  
  if ((this->parent).parent.mpVtxTbl != (cXyz *)0x0) {
    iVar8 = 0;
    iVar7 = 0;
    for (iVar9 = 0; iVar4 = ((this->parent).parent.mpBgDt)->mBlkCount, iVar9 < iVar4;
        iVar9 = iVar9 + 1) {
      bVar1 = false;
      if ((-1 < iVar9) && (iVar9 < iVar4)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_bg_w_hf.cpp",0x8c,"0 <= b && b < pm_bgd->m_b_num");
        m_Do_printf::OSPanic("d_bg_w_hf.cpp",0x8c,&DAT_80353b6f);
      }
      pcVar5 = (this->parent).parent.mpBgDt;
      puVar6 = (ushort *)((int)pcVar5->mpBlkTbl + iVar7);
      idx = (uint)*puVar6;
      if (iVar9 == pcVar5->mBlkCount + -1) {
        uVar3 = pcVar5->mTriCount;
      }
      else {
        uVar3 = (uint)puVar6[1];
      }
      *(undefined2 *)((int)&((this->parent).parent.mpBlk)->mRoofIdx + iVar8) = 0xffff;
      *(undefined2 *)((int)&((this->parent).parent.mpBlk)->mWallIdx + iVar8) = 0xffff;
      *(undefined2 *)((int)&((this->parent).parent.mpBlk)->mGroundIdx + iVar8) = 0xffff;
      local_28[0] = 0xffff;
      for (; (int)idx <= (int)(uVar3 - 1); idx = idx + 1) {
        bVar1 = false;
        if (-1 < (int)idx) {
          if ((int)idx < ((this->parent).parent.mpBgDt)->mTriCount) {
            bVar1 = true;
          }
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_bg_w_hf.cpp",0x9f,"0 <= t && t < pm_bgd->m_t_num");
          m_Do_printf::OSPanic("d_bg_w_hf.cpp",0x9f,&DAT_80353b6f);
        }
        cBgW::BlckConnect((cBgW *)this,
                          (ushort *)((int)&((this->parent).parent.mpBlk)->mGroundIdx + iVar8),
                          local_28,idx);
      }
      iVar8 = iVar8 + 6;
      iVar7 = iVar7 + 2;
    }
  }
  return;
}


/* __thiscall dBgWHf::MoveHf(void) */

void __thiscall dBgWHf::MoveHf(dBgWHf *this)

{
  (this->parent).mFlag = (this->parent).mFlag | 1;
  if (((this->parent).parent.mFlags & Immovable) == 0) {
    (**(code **)((this->parent).parent.vtbl + 0x10))();
    (**(code **)((this->parent).parent.vtbl + 0x14))(this);
    MakeNodeTreeHf(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgWHf::MakeBlckMinMaxHf(int,
                                       float *,
                                       float *) */

void __thiscall dBgWHf::MakeBlckMinMaxHf(dBgWHf *this,int param_1,float *param_2,float *param_3)

{
  float fVar1;
  bool bVar2;
  ulong uVar3;
  cXyz *pcVar4;
  
  bVar2 = false;
  if (-1 < param_1) {
    if (param_1 < ((this->parent).parent.mpBgDt)->mVtxCount) {
      bVar2 = true;
    }
  }
  if (!bVar2) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_bg_w_hf.cpp",0xc6,"0 <= v_index && v_index < pm_bgd->m_v_num")
    ;
    m_Do_printf::OSPanic("d_bg_w_hf.cpp",0xc6,&DAT_80353b6f);
  }
  pcVar4 = (this->parent).parent.mpVtxTbl + param_1;
  fVar1 = pcVar4->y;
  if (fVar1 < *param_2) {
    *param_2 = fVar1;
  }
  fVar1 = pcVar4->y;
  if (*param_3 < fVar1) {
    *param_3 = fVar1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgWHf::MakeBlckBndHf(int,
                                    float *,
                                    float *) */

void __thiscall dBgWHf::MakeBlckBndHf(dBgWHf *this,int param_1,float *param_2,float *param_3)

{
  bool bVar1;
  float fVar2;
  ulong uVar3;
  uint uVar4;
  cBgD_t *pcVar5;
  uint uVar6;
  int iVar7;
  
  bVar1 = false;
  if (-1 < param_1) {
    if (param_1 < ((this->parent).parent.mpBgDt)->mBlkCount) {
      bVar1 = true;
    }
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_bg_w_hf.cpp",0xdd,"blck_id >= 0 && blck_id < pm_bgd->m_b_num")
    ;
    m_Do_printf::OSPanic("d_bg_w_hf.cpp",0xdd,&DAT_80353b6f);
  }
  pcVar5 = (this->parent).parent.mpBgDt;
  uVar6 = (uint)pcVar5->mpBlkTbl[param_1];
  if (param_1 == pcVar5->mBlkCount + -1) {
    uVar4 = pcVar5->mTriCount;
  }
  else {
    uVar4 = (uint)pcVar5->mpBlkTbl[param_1 + 1];
  }
  *param_2 = d_bg_w_hf::_4091;
  *param_3 = d_bg_w_hf::_4092;
  iVar7 = uVar6 * 10;
  for (; fVar2 = d_bg_w_hf::_4093, (int)uVar6 <= (int)(uVar4 - 1); uVar6 = uVar6 + 1) {
    bVar1 = false;
    if (-1 < (int)uVar6) {
      if ((int)uVar6 < ((this->parent).parent.mpBgDt)->mTriCount) {
        bVar1 = true;
      }
    }
    if (!bVar1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_bg_w_hf.cpp",0xee,"0 <= t && t < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("d_bg_w_hf.cpp",0xee,&DAT_80353b6f);
    }
    MakeBlckMinMaxHf(this,(uint)*(ushort *)
                                 ((int)&((this->parent).parent.mpBgDt)->mpTriTbl->mVtxIdx0 + iVar7),
                     param_2,param_3);
    MakeBlckMinMaxHf(this,(uint)*(ushort *)
                                 ((int)&((this->parent).parent.mpBgDt)->mpTriTbl->mVtxIdx1 + iVar7),
                     param_2,param_3);
    MakeBlckMinMaxHf(this,(uint)*(ushort *)
                                 ((int)&((this->parent).parent.mpBgDt)->mpTriTbl->mVtxIdx2 + iVar7),
                     param_2,param_3);
    iVar7 = iVar7 + 10;
  }
  *param_2 = *param_2 - d_bg_w_hf::_4093;
  *param_3 = *param_3 + fVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgWHf::MakeNodeTreeRpHf(int) */

void __thiscall dBgWHf::MakeNodeTreeRpHf(dBgWHf *this,int param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  ulong uVar8;
  cBgW_NodeTree *pcVar9;
  cBgD__Tree_t *pcVar10;
  
  bVar3 = false;
  if (-1 < param_1) {
    if (param_1 < ((this->parent).parent.mpBgDt)->mNodeTreeCount) {
      bVar3 = true;
    }
  }
  if (!bVar3) {
    uVar8 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar8,"d_bg_w_hf.cpp",0x102,"0 <= node_index && node_index < pm_bgd->m_tree_num");
    m_Do_printf::OSPanic("d_bg_w_hf.cpp",0x102,&DAT_80353b6f);
  }
  pcVar10 = ((this->parent).parent.mpBgDt)->mpNodeTreeTbl + param_1;
  if ((pcVar10->mFlag & 1) == 0) {
    pcVar9 = (this->parent).parent.mpNodeTree + param_1;
    (pcVar9->mMin).y = d_bg_w_hf::_4091;
    (pcVar9->mMax).y = d_bg_w_hf::_4092;
    if (pcVar10->mChild0 != 0xffff) {
      MakeNodeTreeRpHf(this,(uint)pcVar10->mChild0);
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild0].mMin.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild0].mMax.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
    }
    if (pcVar10->mChild1 != 0xffff) {
      MakeNodeTreeRpHf(this,(uint)pcVar10->mChild1);
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild1].mMin.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild1].mMax.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
    }
    if (pcVar10->mChild2 != 0xffff) {
      MakeNodeTreeRpHf(this,(uint)pcVar10->mChild2);
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild2].mMin.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild2].mMax.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
    }
    if (pcVar10->mChild3 != 0xffff) {
      MakeNodeTreeRpHf(this,(uint)pcVar10->mChild3);
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild3].mMin.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild3].mMax.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
    }
    if (pcVar10->mChild4 != 0xffff) {
      MakeNodeTreeRpHf(this,(uint)pcVar10->mChild4);
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild4].mMin.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild4].mMax.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
    }
    if (pcVar10->mChild5 != 0xffff) {
      MakeNodeTreeRpHf(this,(uint)pcVar10->mChild5);
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild5].mMin.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild5].mMax.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
    }
    if (pcVar10->mChild6 != 0xffff) {
      MakeNodeTreeRpHf(this,(uint)pcVar10->mChild6);
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild6].mMin.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild6].mMax.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
    }
    if (pcVar10->mChild7 != 0xffff) {
      MakeNodeTreeRpHf(this,(uint)pcVar10->mChild7);
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild7].mMin.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
      pcVar9 = (this->parent).parent.mpNodeTree;
      fVar1 = pcVar9[pcVar10->mChild7].mMax.y;
      pcVar9 = pcVar9 + param_1;
      if (fVar1 < (pcVar9->mMin).y) {
        (pcVar9->mMin).y = fVar1;
      }
      if ((pcVar9->mMax).y < fVar1) {
        (pcVar9->mMax).y = fVar1;
      }
    }
  }
  else {
    if (pcVar10->mChild0 != 0xffff) {
      pcVar9 = (this->parent).parent.mpNodeTree + param_1;
      MakeBlckBndHf(this,(uint)pcVar10->mChild0,&(pcVar9->mMin).y,&(pcVar9->mMax).y);
    }
  }
  bVar7 = false;
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  bVar3 = false;
  pcVar9 = (this->parent).parent.mpNodeTree + param_1;
  if (d_bg_w_hf::_4091 != (pcVar9->mMin).x) {
    if (d_bg_w_hf::_4091 != (pcVar9->mMin).y) {
      bVar3 = true;
    }
  }
  if (bVar3) {
    if (d_bg_w_hf::_4091 != (pcVar9->mMin).z) {
      bVar4 = true;
    }
  }
  if (bVar4) {
    if (d_bg_w_hf::_4092 != (pcVar9->mMax).x) {
      bVar5 = true;
    }
  }
  if (bVar5) {
    if (d_bg_w_hf::_4092 != (pcVar9->mMax).y) {
      bVar6 = true;
    }
  }
  if (bVar6) {
    if (d_bg_w_hf::_4092 != (pcVar9->mMax).z) {
      bVar7 = true;
    }
  }
  if (!bVar7) {
    uVar8 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar8,"d_bg_w_hf.cpp",0x161,
               "m_nt_tbl[node_index].GetMinP()->x != (1000000000.0f) && m_nt_tbl[node_index].GetMinP()->y != (1000000000.0f) && m_nt_tbl[node_index].GetMinP()->z != (1000000000.0f) && m_nt_tbl[node_index].GetMaxP()->x != -(1000000000.0f) && m_nt_tbl[node_index].GetMaxP()->y != -(1000000000.0f) && m_nt_tbl[node_index].GetMaxP()->z != -(1000000000.0f)"
              );
    m_Do_printf::OSPanic("d_bg_w_hf.cpp",0x161,&DAT_80353b6f);
  }
  bVar5 = false;
  bVar4 = false;
  bVar3 = true;
  pcVar9 = (this->parent).parent.mpNodeTree + param_1;
  fVar1 = (pcVar9->mMax).x;
  fVar2 = (pcVar9->mMin).x;
  if ((SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar1 - fVar2)) && (fVar1 < fVar2)) {
    bVar3 = false;
  }
  if (bVar3) {
    bVar3 = true;
    pcVar9 = (this->parent).parent.mpNodeTree + param_1;
    fVar1 = (pcVar9->mMax).y;
    fVar2 = (pcVar9->mMin).y;
    if ((SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar1 - fVar2)) && (fVar1 < fVar2)) {
      bVar3 = false;
    }
    if (bVar3) {
      bVar4 = true;
    }
  }
  if (bVar4) {
    bVar3 = true;
    pcVar9 = (this->parent).parent.mpNodeTree + param_1;
    fVar1 = (pcVar9->mMax).z;
    fVar2 = (pcVar9->mMin).z;
    if ((SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar1 - fVar2)) && (fVar1 < fVar2)) {
      bVar3 = false;
    }
    if (bVar3) {
      bVar5 = true;
    }
  }
  if (!bVar5) {
    uVar8 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar8,"d_bg_w_hf.cpp",0x16d,
               "(cM3d_IsZero(m_nt_tbl[node_index].GetMaxP()->x - m_nt_tbl[node_index].GetMinP()->x) || m_nt_tbl[node_index].GetMinP()->x <= m_nt_tbl[node_index].GetMaxP()->x) && (cM3d_IsZero(m_nt_tbl[node_index].GetMaxP()->y - m_nt_tbl[node_index].GetMinP()->y) || m_nt_tbl[node_index].GetMinP()->y <= m_nt_tbl[node_index].GetMaxP()->y) && (cM3d_IsZero(m_nt_tbl[node_index].GetMaxP()->z - m_nt_tbl[node_index].GetMinP()->z) || m_nt_tbl[node_index].GetMinP()->z <= m_nt_tbl[node_index].GetMaxP()->z)"
              );
    m_Do_printf::OSPanic("d_bg_w_hf.cpp",0x16d,&DAT_80353b6f);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dBgWHf::MakeNodeTreeGrpRpHf(int) */

void __thiscall dBgWHf::MakeNodeTreeGrpRpHf(dBgWHf *this,int param_1)

{
  float fVar1;
  ushort uVar2;
  bool bVar3;
  cBgW_GrpElm *pcVar4;
  ulong uVar5;
  cM3dGAab *pcVar6;
  uint uVar7;
  
  bVar3 = false;
  if (-1 < param_1) {
    if (param_1 < ((this->parent).parent.mpBgDt)->mGrpCount) {
      bVar3 = true;
    }
  }
  if (!bVar3) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_bg_w_hf.cpp",0x179,"0 <= g && g < pm_bgd->m_g_num");
    m_Do_printf::OSPanic("d_bg_w_hf.cpp",0x179,&DAT_80353b6f);
  }
  uVar7 = (uint)((this->parent).parent.mpBgDt)->mpGrpTbl[param_1].mTreIdx;
  if (uVar7 != 0xffff) {
    MakeNodeTreeRpHf(this,uVar7);
    fVar1 = (this->parent).parent.mpNodeTree
            [((this->parent).parent.mpBgDt)->mpGrpTbl[param_1].mTreIdx].mMin.y;
    pcVar6 = &(this->parent).parent.mpGrp[param_1].mAabb;
    if (fVar1 < (pcVar6->mMin).y) {
      (pcVar6->mMin).y = fVar1;
    }
    fVar1 = (this->parent).parent.mpNodeTree
            [((this->parent).parent.mpBgDt)->mpGrpTbl[param_1].mTreIdx].mMax.y;
    pcVar6 = &(this->parent).parent.mpGrp[param_1].mAabb;
    if ((pcVar6->mMax).y < fVar1) {
      (pcVar6->mMax).y = fVar1;
    }
  }
  uVar2 = ((this->parent).parent.mpBgDt)->mpGrpTbl[param_1].mFirstChild;
  while (uVar7 = (uint)uVar2, uVar7 != 0xffff) {
    MakeNodeTreeGrpRpHf(this,uVar7);
    pcVar4 = (this->parent).parent.mpGrp;
    fVar1 = pcVar4[uVar7].mAabb.mMin.y;
    pcVar6 = &pcVar4[param_1].mAabb;
    if (fVar1 < (pcVar6->mMin).y) {
      (pcVar6->mMin).y = fVar1;
    }
    pcVar4 = (this->parent).parent.mpGrp;
    fVar1 = pcVar4[uVar7].mAabb.mMax.y;
    pcVar6 = &pcVar4[param_1].mAabb;
    if ((pcVar6->mMax).y < fVar1) {
      (pcVar6->mMax).y = fVar1;
    }
    uVar2 = ((this->parent).parent.mpBgDt)->mpGrpTbl[uVar7].mNextSibling;
  }
  return;
}


/* __thiscall dBgWHf::MakeNodeTreeHf(void) */

void __thiscall dBgWHf::MakeNodeTreeHf(dBgWHf *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  cBgD_t *pcVar5;
  int iVar6;
  
  fVar2 = d_bg_w_hf::_4092;
  fVar1 = d_bg_w_hf::_4091;
  if ((this->parent).parent.mpVtxTbl == (cXyz *)0x0) {
    iVar6 = 0;
    iVar4 = 0;
    pcVar5 = (this->parent).parent.mpBgDt;
    iVar3 = pcVar5->mGrpCount;
    if (0 < iVar3) {
      do {
        if (*(short *)((int)&pcVar5->mpGrpTbl->mParent + iVar4) == -1) {
          (this->parent).parent.mRootGrpIdx = iVar6;
          return;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x34;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  else {
    iVar4 = 0;
    iVar3 = 0;
    while( true ) {
      pcVar5 = (this->parent).parent.mpBgDt;
      iVar6 = pcVar5->mGrpCount;
      if (iVar6 <= iVar4) break;
      iVar6 = (int)&(((this->parent).parent.mpGrp)->mAabb).mMin.x + iVar3;
      *(float *)(iVar6 + 4) = fVar1;
      *(float *)(iVar6 + 0x10) = fVar2;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x20;
    }
    iVar3 = (this->parent).parent.mRootGrpIdx;
    if (iVar3 == 0xffff) {
      iVar3 = 0;
      iVar4 = 0;
      if (0 < iVar6) {
        do {
          if (*(short *)((int)&pcVar5->mpGrpTbl->mParent + iVar4) == -1) {
            (this->parent).parent.mRootGrpIdx = iVar3;
            MakeNodeTreeGrpRpHf(this,iVar3);
            return;
          }
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x34;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
    else {
      MakeNodeTreeGrpRpHf(this,iVar3);
    }
  }
  return;
}


/* __thiscall dBgWHf::~dBgWHf(void) */

void __thiscall dBgWHf::_dBgWHf(dBgWHf *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dBgWHf *)0x0;
  if (bVar1) {
    (this->parent).parent.vtbl = &__vt;
    if ((bVar1) && ((this->parent).parent.vtbl = &dBgWSv::__vt, bVar1)) {
      (this->parent).parent.vtbl = (undefined *)&dBgW::__vt;
      cBgW::_cBgW((cBgW *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgWSv::MatrixCrrPos(cBgS_PolyInfo &,
                                   void *,
                                   bool,
                                   cXyz *,
                                   csXyz *,
                                   csXyz *) */

void __thiscall
dBgWSv::MatrixCrrPos
          (dBgWSv *this,cBgS_PolyInfo *param_1,void *param_2,bool param_3,cXyz *param_4,
          csXyz *param_5,csXyz *param_6)

{
  return;
}

