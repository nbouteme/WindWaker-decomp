#include <JAudio/JASResArcLoader.h>
#include <JKernel/JKRArchivePri.h>
#include <JKernel/JKRArchivePub.h>
#include <os/OSMessage.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JASResArcLoader.h>
#include <JAudio/JASDvdThread.h>
#include <JASystem/ResArcLoader.h>


namespace JASystem {

/* __thiscall ResArcLoader::getResSize(JKRArchive *,
                                                 unsigned short) */

undefined4 __thiscall
ResArcLoader::getResSize(ResArcLoader *this,JKRArchive *param_1,ushort param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = JKRArchive::findIdResource((JKRArchive *)this,(ushort)param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0xc);
  }
  return uVar2;
}


/* __thiscall ResArcLoader::loadResourceCallback(void *) */

undefined4 __thiscall ResArcLoader::loadResourceCallback(ResArcLoader *this,void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = JKRArchive::readResource
                    (*(JKRArchive **)this,*(void **)(this + 8),*(ulong *)(this + 0xc),
                     *(ushort *)(this + 4));
  if (*(code **)(this + 0x10) != (code *)0x0) {
    (**(code **)(this + 0x10))(iVar1,*(undefined4 *)(this + 0x14));
  }
  if (iVar1 == 0) {
    if (*(int *)(this + 0x18) != 0) {
      os::OSSendMessage(*(int *)(this + 0x18),0xffffffff,1);
    }
    uVar2 = 0xffffffff;
  }
  else {
    if (*(int *)(this + 0x18) != 0) {
      os::OSSendMessage(*(int *)(this + 0x18),0,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall ResArcLoader::loadResource(JKRArchive *,
                                                   unsigned short,
                                                   unsigned char *,
                                                   unsigned long) */

uint __thiscall
ResArcLoader::loadResource
          (ResArcLoader *this,JKRArchive *param_1,ushort param_2,uchar *param_3,ulong param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 in_register_00000014;
  uchar *puVar3;
  int local_58;
  OSMessage pvStack84;
  ResArcLoader *local_50;
  undefined2 local_4c;
  undefined4 local_48;
  uchar *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  OSMessageQueue *local_38;
  OSMessageQueue OStack52;
  
  local_48 = CONCAT22(in_register_00000014,param_2);
  puVar3 = param_3;
  os::OSInitMessageQueue(&OStack52,&pvStack84,1);
  local_4c = SUB42(param_1,0);
  local_40 = 0;
  local_3c = 0;
  local_38 = &OStack52;
  local_50 = this;
  local_44 = param_3;
  iVar1 = Dvd::sendCmdMsg((Dvd *)loadResourceCallback,(FuncDef568 *)&local_50,&DAT_0000001c,
                          (ulong)puVar3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    os::OSReceiveMessage(&OStack52,&local_58,1);
    uVar2 = (uint)param_3 & ~-(uint)(local_58 != 0);
  }
  return uVar2;
}


/* __thiscall ResArcLoader::loadResourceAsync(JKRArchive *,
                                                        unsigned short,
                                                        unsigned char *,
                                                        unsigned long,
                                                        void *(unsigned long,unsigned long),
                                                        unsigned long) */

void __thiscall
ResArcLoader::loadResourceAsync
          (ResArcLoader *this,JKRArchive *param_1,ushort param_2,uchar *param_3,ulong param_4,
          FuncDef573 *param_5,ulong param_6)

{
  undefined2 in_register_00000014;
  ResArcLoader *local_28;
  undefined2 local_24;
  undefined4 local_20;
  uchar *local_1c;
  ulong local_18;
  FuncDef573 *local_14;
  undefined4 local_10;
  
  local_20 = CONCAT22(in_register_00000014,param_2);
  local_24 = SUB42(param_1,0);
  local_10 = 0;
  local_28 = this;
  local_1c = param_3;
  local_18 = param_4;
  local_14 = param_5;
  Dvd::sendCmdMsg((Dvd *)loadResourceCallback,(FuncDef568 *)&local_28,&DAT_0000001c,(ulong)param_3);
  return;
}

