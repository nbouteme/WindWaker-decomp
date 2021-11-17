#include <f_op_scene_mng.h>
#include <f_pc_searcher.h>
#include <f_op_scene_iter.h>
#include <f_op_scene_req.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>


namespace f_op_scene_mng {

/* __stdcall fopScnM_SearchByID(unsigned int) */

scene_class * fopScnM_SearchByID(int param_1)

{
  scene_class *psVar1;
  int local_8;
  
  local_8 = param_1;
  psVar1 = f_op_scene_iter::fopScnIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_8);
  return psVar1;
}


/* __stdcall fopScnM_ChangeReq(scene_class *,
                               short,
                               short,
                               unsigned short) */

bool fopScnM_ChangeReq
               (scene_class *param_1,short procName,short fadeTime,ushort param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = f_op_scene_req::fopScnRq_Request(2,param_1,procName,(void *)0x0,fadeTime,param_4);
  iVar1 = iVar2;
  if (iVar2 == -1) {
    iVar1 = l_scnRqID;
  }
  l_scnRqID = iVar1;
  return iVar2 != -1;
}


/* __stdcall fopScnM_DeleteReq(scene_class *) */

uint fopScnM_DeleteReq(scene_class *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = f_op_scene_req::fopScnRq_Request(1,param_1,0x7fff,(void *)0x0,0x7fff,0);
  iVar2 = -iVar1 + -1;
  return iVar2 - ((uint)(iVar2 == 0) + -iVar1 + -2) & 0xff;
}


/* __stdcall fopScnM_CreateReq(short,
                               short,
                               unsigned short,
                               unsigned long) */

uint fopScnM_CreateReq(short param_1,short param_2,ushort param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = f_op_scene_req::fopScnRq_Request(0,(scene_class *)0x0,param_1,param_4,param_2,param_3);
  iVar2 = -iVar1 + -1;
  return iVar2 - ((uint)(iVar2 == 0) + -iVar1 + -2) & 0xff;
}


/* __stdcall fopScnM_ReRequest(short,
                               unsigned long) */

undefined4 fopScnM_ReRequest(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (l_scnRqID == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = f_op_scene_req::fopScnRq_ReRequest(l_scnRqID,param_1,param_2);
  }
  return uVar1;
}


/* __stdcall fopScnM_Management(void) */

void fopScnM_Management(void)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = f_op_scene_req::fopScnRq_Handler();
  if (iVar1 == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_scene_mng.cpp",0x146,"0");
    m_Do_printf::OSPanic("f_op_scene_mng.cpp",0x146,"Halt");
  }
  return;
}


/* __stdcall fopScnM_Init(void) */

void fopScnM_Init(void)

{
  return;
}

