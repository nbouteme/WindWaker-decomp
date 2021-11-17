#include <JAudio/JASPlayer_impl.h>
#include <JASystem/Player.h>


namespace JAudio {
undefined4 sV0$648;
undefined1 init$649;
undefined4 sV1$651;
undefined1 init$652;
}

namespace JASystem {

/* __thiscall Player::extend8to16(unsigned char) */

uint __thiscall Player::extend8to16(Player *this,uchar param_1)

{
  uint uVar1;
  
  uVar1 = (uint)this & 0xff;
  if (((uint)this & 0x80) != 0) {
    uVar1 = SEXT24((short)((short)uVar1 + -0x100));
  }
  return uVar1;
}


/* __thiscall Player::pitchToCent(float,
                                            float) */

double __thiscall Player::pitchToCent(Player *this,float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  short sVar3;
  double local_10;
  
  fVar1 = JAudio::_638 * param_1 * param_2;
  sVar3 = (short)(int)fVar1;
  local_10 = (double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000);
  fVar2 = fVar1 - (float)(local_10 - JAudio::_644);
  if ((fVar1 < JAudio::_639) && (JAudio::_639 != fVar2)) {
    fVar2 = fVar2 + JAudio::_640;
    sVar3 = sVar3 + -1;
  }
  if (JAudio::_640 <= fVar2) {
    fVar2 = fVar2 - JAudio::_640;
    sVar3 = sVar3 + 1;
  }
  return (double)(*(float *)(&s_key_table + ((int)(JAudio::_641 * fVar2) & 0xffffU) * 4) *
                 *(float *)(&DAT_80398dd0 + sVar3 * 4));
}


/* __thiscall Player::getRandomS32(void) */

void __thiscall Player::getRandomS32(Player *this)

{
  int iVar1;
  
  if (JAudio::init_649 == '\0') {
    JAudio::sV0_648 = 0x1000;
    JAudio::init_649 = '\x01';
  }
  if (JAudio::init_652 == '\0') {
    JAudio::sV1_651 = 0x5555;
    JAudio::init_652 = '\x01';
  }
  iVar1 = JAudio::sV0_648 * 0x13579bde;
  JAudio::sV0_648 = JAudio::sV1_651;
  JAudio::sV1_651 = JAudio::sV1_651 * -0x6789abce + (iVar1 >> 4) + 1;
  return;
}

