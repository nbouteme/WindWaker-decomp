#include <exi/EXIUart.h>
#include <os/OS.h>
#include <exi/EXIBios.h>


namespace exi {
undefined4 Chan;
undefined4 Dev;
undefined4 Enabled;
undefined4 BarnacleEnabled;

undefined4 InitializeUART(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (BarnacleEnabled == -0x5a00ffa6) {
    uVar1 = 0;
  }
  else {
    uVar2 = os::OSGetConsoleType();
    if ((uVar2 & 0x10000000) == 0) {
      Enabled = 0;
      uVar1 = 2;
    }
    else {
      Enabled = 0xa5ff005a;
      Chan = 0;
      uVar1 = 0;
      Dev = 1;
    }
  }
  return uVar1;
}


undefined4 WriteUARTN(char *param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint local_20;
  undefined4 local_1c;
  
  if (Enabled == -0x5a00ffa6) {
    iVar3 = EXILock(Chan,Dev,0);
    pcVar4 = param_1;
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      for (; (uint)((int)pcVar4 - (int)param_1) < param_2; pcVar4 = pcVar4 + 1) {
        if (*pcVar4 == '\n') {
          *pcVar4 = '\r';
        }
      }
      local_1c = 0xa0010000;
      uVar2 = 0;
      while (param_2 != 0) {
        iVar3 = EXISelect(Chan,Dev,3);
        if (iVar3 == 0) {
          uVar1 = 0xffffffff;
        }
        else {
          local_20 = 0x20010000;
          EXIImm(Chan,&local_20,4,1,0);
          EXISync(Chan);
          EXIImm(Chan,&local_20,1,0,0);
          EXISync(Chan);
          EXIDeselect(Chan);
          uVar1 = 0x10 - (local_20 >> 0x18);
        }
        if ((int)uVar1 < 0) {
          uVar2 = 3;
          break;
        }
        if ((0xb < (int)uVar1) || (param_2 <= uVar1)) {
          iVar3 = EXISelect(Chan,Dev,3);
          if (iVar3 == 0) {
            uVar2 = 3;
            break;
          }
          EXIImm(Chan,&local_1c,4,1,0);
          EXISync(Chan);
          for (; ((uVar1 != 0 && (param_2 != 0)) && ((3 < (int)uVar1 || (param_2 <= uVar1))));
              param_2 = param_2 - uVar5) {
            uVar5 = param_2;
            if (3 < param_2) {
              uVar5 = 4;
            }
            EXIImm(Chan,param_1,uVar5,1,0);
            param_1 = param_1 + uVar5;
            uVar1 = uVar1 - uVar5;
            EXISync(Chan);
          }
          EXIDeselect(Chan);
        }
      }
      EXIUnlock(Chan);
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

