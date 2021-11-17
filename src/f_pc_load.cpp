#include <f_pc_load.h>
#include <f_pc_load.h>
#include <c_dylink.h>


namespace f_pc_load {

/* __stdcall fpcLd_Use(short) */

undefined4 fpcLd_Use(ushort param_1)

{
  undefined2 in_register_0000000c;
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = CONCAT22(in_register_0000000c,param_1);
  fpcLd_IsLoaded(param_1);
  if ((iVar1 == 1) && (iVar1 = fpcLd_Load(param_1), iVar1 == 4)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall fpcLd_IsLoaded(short) */

void fpcLd_IsLoaded(short param_1)

{
  c_dylink::cDyl_IsLinked((int)param_1);
  return;
}


/* __stdcall fpcLd_Free(short) */

void fpcLd_Free(ushort param_1,char *param_2)

{
  c_dylink::cDyl_Unlink(param_1,param_2);
  return;
}


/* __stdcall fpcLd_Load(short) */

undefined4 fpcLd_Load(ushort param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = c_dylink::cDyl_LinkASync(param_1);
  if (iVar1 == 4) {
    uVar2 = 4;
  }
  else {
    if ((iVar1 < 4) && (iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 5;
    }
  }
  return uVar2;
}

