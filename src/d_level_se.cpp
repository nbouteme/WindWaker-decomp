#include <d_level_se.h>
#include <JAZelAudio/JAIZelBasic.h>


namespace d_level_se {

/* __stdcall dLevelSe_Execute(dLevelSe_c *) */

undefined4 dLevelSe_Execute(int param_1)

{
  byte bVar1;
  ulong soundId;
  
  soundId = *(ulong *)(param_1 + 0xf4);
  bVar1 = *(byte *)(param_1 + 0xfd);
  if ((bVar1 & 8) == 0) {
    if ((bVar1 & 1) == 0) {
      if ((bVar1 & 4) == 0) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,soundId,(cXyz *)(param_1 + 0xdc),0,0,_4029,_4029,_4030,
                   _4030,0);
      }
      else {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,soundId,(cXyz *)(param_1 + 0xdc),
                   *(ulong *)(param_1 + 0xf8),*(sbyte *)(param_1 + 0xfc),_4029,_4029,_4030,_4030,0);
      }
    }
    else {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,soundId,(cXyz *)(param_1 + 0xdc),*(ulong *)(param_1 + 0xf8),
                 0,_4029,_4029,_4030,_4030,0);
    }
  }
  return 1;
}


/* __stdcall dLevelSe_IsDelete(dLevelSe_c *) */

undefined4 dLevelSe_IsDelete(void)

{
  return 1;
}


/* __stdcall dLevelSe_Delete(dLevelSe_c *) */

undefined4 dLevelSe_Delete(int param_1)

{
  JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)(param_1 + 0xdc));
  return 1;
}


/* __stdcall dLevelSe_Create(kankyo_class *) */

undefined4 dLevelSe_Create(void)

{
  return 4;
}

