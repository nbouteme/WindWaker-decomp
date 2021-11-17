#include <JStudio/fvb-data-parse.h>
#include <JGadget/binary.h>
#include <JStudio/fvb/data/TParse_TParagraph.h>


namespace JStudio {

namespace fvb {

namespace data {

/* __thiscall
   TParse_TParagraph::getData(TParse_TParagraph::TData *)
   const */

void __thiscall
TParse_TParagraph::getData(TParse_TParagraph *this,TData *param_1)

{
  int iVar1;
  TEBit *in_r7;
  
  iVar1 = ::JGadget::binary::parseVariableUInt_16_32_following
                    (*(binary **)this,param_1,(ulong *)(param_1 + 4),(ulong *)0x0,in_r7);
  if (*(int *)param_1 == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *(int *)(param_1 + 0xc) = iVar1;
  }
  else {
    *(int *)(param_1 + 8) = iVar1;
    *(uint *)(param_1 + 0xc) = iVar1 + (*(int *)param_1 + 3U & 0xfffffffc);
  }
  return;
}

