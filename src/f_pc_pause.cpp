#include <f_pc_pause.h>
#include <f_pc_base.h>
#include <f_pc_pause.h>
#include <f_pc_layer_iter.h>


namespace f_pc_pause {

/* __stdcall fpcPause_IsEnable(void *,
                               unsigned char) */

uint fpcPause_IsEnable(base_process_class *param_1,byte param_2)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros((uint)((param_2 & param_1->mPauseFlag) != param_2));
  return uVar1 >> 5;
}


/* __stdcall fpcPause_Enable(void *,
                             unsigned char) */

undefined4 fpcPause_Enable(process_node_class *pBase,byte param_2)

{
  bool bVar1;
  
  (pBase->parent).mPauseFlag = (pBase->parent).mPauseFlag | param_2;
  bVar1 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type,(pBase->parent).mSubType);
  if (bVar1 != false) {
    f_pc_layer_iter::fpcLyIt_OnlyHere(&pBase->mLayer,fpcPause_Enable,(uint)param_2);
  }
  return 1;
}


/* __stdcall fpcPause_Disable(void *,
                              unsigned char) */

undefined4 fpcPause_Disable(base_process_class *pBs,byte param_2)

{
  bool bVar1;
  
  pBs->mPauseFlag = pBs->mPauseFlag & -param_2 - 1;
  bVar1 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type,pBs->mSubType);
  if (bVar1 != false) {
    f_pc_layer_iter::fpcLyIt_OnlyHere((layer_class *)&pBs[1].mBsPcId,fpcPause_Disable,(uint)param_2)
    ;
  }
  return 1;
}


/* __stdcall fpcPause_Init(void *) */

void fpcPause_Init(base_process_class *pBs)

{
  pBs->mPauseFlag = 0;
  return;
}

