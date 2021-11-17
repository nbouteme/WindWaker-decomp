#include <JGadget/binary.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JGadget/binary.h>
#include <JGadget/binary/TParse_header_block.h>


namespace JGadget {

/* __thiscall binary::parseVariableUInt_16_32_following(void const *,
                                                                 unsigned long *,
                                                                 unsigned long *,
                                                                 binary::TEBit *) */

binary * __thiscall
binary::parseVariableUInt_16_32_following
          (binary *this,void *param_1,ulong *param_2,ulong *param_3,TEBit *param_4)

{
  ushort uVar1;
  binary *pbVar2;
  ulong local_8 [2];
  
  if (param_3 == (ulong *)0x0) {
    param_3 = local_8;
  }
  uVar1 = *(ushort *)this;
  if ((uVar1 & 0x8000) == 0) {
    *param_3 = 0x10;
    *(uint *)param_1 = (uint)uVar1;
    *param_2 = (uint)*(ushort *)(this + 2);
    pbVar2 = this + 4;
  }
  else {
    *param_3 = 0x20;
    *(uint *)param_1 = (uVar1 & 0x7fff) << 0x10 | (uint)*(ushort *)(this + 2);
    *param_2 = *(ulong *)(this + 4);
    pbVar2 = this + 8;
  }
  return pbVar2;
}


namespace binary {

/* __thiscall TParse_header_block::~TParse_header_block(void) */

void __thiscall
TParse_header_block::_TParse_header_block(TParse_header_block *this)

{
  short in_r4;
  
  if ((this != (TParse_header_block *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall TParse_header_block::parse_next(void const * *,
                                                               unsigned long) */

bool __thiscall
TParse_header_block::parse_next(TParse_header_block *this,void **pData,ulong mode)

{
  bool bVar1;
  char cVar2;
  bool bVar3;
  int auStack40;
  int numBlocks;
  
  if ((pData == (void **)0x0) || (*pData == (void *)0x0)) {
    bVar3 = false;
  }
  else {
    cVar2 = (**(code **)(*(int *)this + 0xc))(this,pData,&numBlocks,mode);
    bVar3 = cVar2 != '\0';
    if (((mode & 1) != 0) || (bVar3)) {
      for (; numBlocks != 0; numBlocks = numBlocks + -1) {
        cVar2 = (**(code **)(*(int *)this + 0x10))(this,pData,&auStack40,mode);
        bVar1 = false;
        if ((cVar2 != '\0') && (bVar3 != false)) {
          bVar1 = true;
        }
        bVar3 = bVar1;
        if (((mode & 2) == 0) && (bVar3 == false)) {
          return false;
        }
      }
    }
  }
  return bVar3;
}

