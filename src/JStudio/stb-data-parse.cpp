#include <JStudio/stb-data-parse.h>
#include <JGadget/binary.h>
#include <Demangler/JStudio/stb/data/TParse_TParagraph.h>
#include <JStudio/stb/data/TParse_TParagraph_data.h>
#include <JStudio/stb/data/TParse_TSequence.h>


namespace JStudio {

namespace stb {

namespace data {

/* __thiscall
   TParse_TSequence::getData(TParse_TSequence::TData *)
   const */

void __thiscall TParse_TSequence::getData(TParse_TSequence *this,TData *param_1)

{
  int iVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar2 = **(uint **)this;
  *param_1 = SUB41(uVar2 >> 0x18,0);
  *(uint *)(param_1 + 4) = uVar2 & 0xffffff;
  if (uVar2 >> 0x18 == 0) {
    return;
  }
  iVar1 = *(int *)this + 4;
  if (uVar2 >> 0x18 < 0x80) {
    *(int *)(param_1 + 0xc) = iVar1;
    return;
  }
  *(int *)(param_1 + 8) = iVar1;
  *(uint *)(param_1 + 0xc) = iVar1 + (uVar2 & 0xffffff);
  return;
}


/* __thiscall
   TParse_TParagraph::getData(TParse_TParagraph::TData *)
   const */

void __thiscall
TParse_TParagraph::getData(TParse_TParagraph *this,TData *param_1)

{
  int iVar1;
  TEBit *in_r7;
  int local_18 [5];
  
  iVar1 = ::JGadget::binary::parseVariableUInt_16_32_following
                    (*(binary **)this,local_18,(ulong *)param_1,(ulong *)0x0,in_r7);
  *(int *)(param_1 + 4) = local_18[0];
  if (local_18[0] == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(int *)(param_1 + 0xc) = iVar1;
  }
  else {
    *(int *)(param_1 + 8) = iVar1;
    *(uint *)(param_1 + 0xc) = iVar1 + (local_18[0] + 3U & 0xfffffffc);
  }
  return;
}


/* __thiscall
   TParse_TParagraph_data::getData(TParse_TParagraph_data::TData
   *) const */

void __thiscall
TParse_TParagraph_data::getData(TParse_TParagraph_data *this,TData *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  pbVar3 = *(byte **)this;
  if (pbVar3 == (byte *)0x0) {
    return;
  }
  bVar1 = *pbVar3;
  *param_1 = (TData)(bVar1 & 0xf7);
  if (bVar1 == 0) {
    return;
  }
  uVar5 = 1;
  pbVar4 = pbVar3 + 1;
  if ((bVar1 & 8) != 0) {
    uVar5 = (uint)*pbVar4;
    pbVar4 = pbVar3 + 2;
  }
  *(uint *)(param_1 + 8) = uVar5;
  *(byte **)(param_1 + 0xc) = pbVar4;
  if ((bVar1 & 7) == 0) {
    return;
  }
  iVar2 = *(int *)(&gauDataSize_TEParagraph_data + (bVar1 & 7) * 4);
  *(int *)(param_1 + 4) = iVar2;
  *(byte **)(param_1 + 0x10) = pbVar4 + iVar2 * uVar5;
  return;
}

