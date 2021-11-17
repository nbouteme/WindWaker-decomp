#include <d_seafightgame.h>
#include <d_seafightgame.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_math.h>
#include <dSeaFightGame_info_c.h>


/* __thiscall dSeaFightGame_info_c::init(int,
                                         int) */

int __thiscall dSeaFightGame_info_c::init(dSeaFightGame_info_c *this,int bulletNum,int scenario)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar1 = 0;
  do {
    pbVar2 = this->mGrid + iVar1;
    iVar4 = 8;
    do {
      *pbVar2 = 0;
      pbVar2 = pbVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 8;
  } while (iVar3 < 8);
  this->mBulletNum = (byte)bulletNum;
  this->mScore = 0;
  if (scenario == 2) {
    this->mAliveShipNum = 2;
    put_ship(this,0,2);
    put_ship(this,1,3);
  }
  else {
    if (scenario < 2) {
      if (0 < scenario) {
        this->mAliveShipNum = 1;
        put_ship(this,0,2);
      }
    }
    else {
      if (scenario < 4) {
        this->mAliveShipNum = 3;
        put_ship(this,0,2);
        put_ship(this,1,3);
        put_ship(this,2,4);
      }
    }
  }
  this->mDeadShipNum = 0;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dSeaFightGame_info_c::put_ship(unsigned char,
                                             unsigned char) */

undefined4 __thiscall
dSeaFightGame_info_c::put_ship(dSeaFightGame_info_c *this,byte shipNum,byte shipSize)

{
  uint direction;
  uint y;
  uint x;
  char cVar2;
  byte *pbVar1;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  uint size;
  float fVar7;
  float fVar8;
  
  size = (uint)shipSize;
  do {
    fVar7 = SComponent::cM_rndF(d_seafightgame::1000_0);
    iVar3 = (int)(short)(int)fVar7 >> 0x1f;
    direction = ((int)(short)(int)fVar7 & 1U ^ -iVar3) + iVar3 & 0xff;
    fVar7 = SComponent::cM_rndF(d_seafightgame::8_0);
    y = (int)fVar7 & 0xff;
    fVar8 = SComponent::cM_rndF(d_seafightgame::8_0);
    x = (int)fVar8 & 0xff;
    cVar2 = checkPutShip(this,y,x,size,direction);
  } while (cVar2 == '\0');
  bVar6 = (byte)y;
  bVar5 = (byte)x;
  if (direction == 0) {
    cVar2 = '\0';
    iVar3 = 0;
    pbVar1 = this->mGrid + ((int)fVar7 & 0xffU) * 8 + x;
    if (shipSize != 0) {
      do {
        (this->mGrid + iVar3 + (uint)shipNum * 0xf)[0x40] = bVar6;
        (this->mGrid + iVar3 + (uint)shipNum * 0xf)[0x41] = bVar5 + cVar2;
        *pbVar1 = shipNum + 0x66;
        cVar2 = cVar2 + '\x01';
        pbVar1 = pbVar1 + 1;
        iVar3 = iVar3 + 2;
        size = size - 1;
      } while (size != 0);
    }
    pbVar1 = this->mGrid + (uint)shipNum * 0xf;
    pbVar1[0x4b] = bVar6;
    pbVar1[0x4c] = bVar5;
    pbVar1[0x4d] = 0;
    pbVar1[0x4e] = shipSize;
  }
  else {
    iVar4 = 0;
    iVar3 = 0;
    if (shipSize != 0) {
      do {
        (this->mGrid + iVar3 + (uint)shipNum * 0xf)[0x40] = (byte)(y + iVar4);
        (this->mGrid + iVar3 + (uint)shipNum * 0xf)[0x41] = bVar5;
        this->mGrid[(y + iVar4) * 8 + x] = shipNum + 0x66;
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 2;
        size = size - 1;
      } while (size != 0);
    }
    pbVar1 = this->mGrid + (uint)shipNum * 0xf;
    pbVar1[0x4b] = bVar6;
    pbVar1[0x4c] = bVar5;
    pbVar1[0x4d] = shipSize;
    pbVar1[0x4e] = 0;
  }
  (this->mGrid + (uint)shipNum * 0xf)[0x48] = shipSize;
  (this->mGrid + (uint)shipNum * 0xf)[0x49] = shipSize;
  return 1;
}


/* __thiscall dSeaFightGame_info_c::checkPutShip(int,
                                                 int,
                                                 int,
                                                 int) */

undefined4 __thiscall
dSeaFightGame_info_c::checkPutShip
          (dSeaFightGame_info_c *this,int y,int x,int shipSize,int direction)

{
  byte *pbVar1;
  int iVar2;
  
  if (direction == 0) {
    pbVar1 = this->mGrid + x + y * 8;
    if (0 < shipSize) {
      do {
        if (((7 < y) || (7 < x)) || (100 < *pbVar1)) {
          return 0;
        }
        x = x + 1;
        pbVar1 = pbVar1 + 1;
        shipSize = shipSize + -1;
      } while (shipSize != 0);
    }
  }
  else {
    iVar2 = y << 3;
    if (0 < shipSize) {
      do {
        if (((7 < y) || (7 < x)) || (100 < this->mGrid[iVar2 + x])) {
          return 0;
        }
        y = y + 1;
        iVar2 = iVar2 + 8;
        shipSize = shipSize + -1;
      } while (shipSize != 0);
    }
  }
  return 1;
}


/* __thiscall dSeaFightGame_info_c::attack(unsigned char,
                                           unsigned char) */

int __thiscall dSeaFightGame_info_c::attack(dSeaFightGame_info_c *this,byte y,byte x)

{
  uint uVar1;
  int idx;
  int iVar2;
  int iVar3;
  
  iVar3 = -1;
  idx = (uint)y * 8 + (uint)x;
  uVar1 = (uint)this->mGrid[idx];
  if (uVar1 == 0) {
    this->mGrid[idx] = 1;
  }
  else {
    if (uVar1 < 0x65) {
      return -2;
    }
    iVar3 = uVar1 - 0x66;
    iVar2 = (int)this + iVar3 * 0xf;
    *(char *)(iVar2 + 0x49) = *(char *)(iVar2 + 0x49) + -1;
    if (*(char *)(iVar2 + 0x49) == '\0') {
      this->mAliveShipNum = this->mAliveShipNum - 1;
      this->mDeadShipNum = this->mDeadShipNum + 1;
    }
    this->mGrid[idx] = 3;
  }
  this->mBulletNum = this->mBulletNum - 1;
  this->mScore = this->mScore + 1;
  return iVar3;
}

