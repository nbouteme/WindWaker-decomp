#include <card/CARDNet.h>
#include <card/CARDBios.h>


namespace card {

/* WARNING: Type propagation algorithm not settling */

card_errors CARDGetSerialNo(int card_slot,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  card_errors cVar5;
  card_workarea *pcVar6;
  CardBlockData *local_10 [3];
  
  if ((card_slot < 0) || (1 < card_slot)) {
    cVar5 = CARD_ERROR_FATAL_ERROR;
  }
  else {
    cVar5 = __CARDGetControlBlock(card_slot,local_10);
    if (-1 < (int)cVar5) {
      pcVar6 = (local_10[0]->mCard_block).mpWorkarea;
      uVar1 = *(uint *)(pcVar6->mHeaderData).mDirEntries[0].mGamecode;
      uVar2 = *(uint *)(pcVar6->mHeaderData).mDirEntries[0].mFilename;
      uVar3 = *(uint *)((pcVar6->mHeaderData).mDirEntries[0].mFilename + 8);
      uVar4 = *(uint *)((pcVar6->mHeaderData).mDirEntries[0].mFilename + 0x10);
      param_2[1] = *(uint *)(pcVar6->mHeaderData).mDirEntries[0].mCompany ^
                   *(uint *)((pcVar6->mHeaderData).mDirEntries[0].mFilename + 4) ^
                   *(uint *)((pcVar6->mHeaderData).mDirEntries[0].mFilename + 0xc) ^
                   *(uint *)((pcVar6->mHeaderData).mDirEntries[0].mFilename + 0x14);
      *param_2 = uVar1 ^ uVar2 ^ uVar3 ^ uVar4;
      cVar5 = __CARDPutControlBlock(local_10[0],CARD_ERROR_READY);
    }
  }
  return cVar5;
}

