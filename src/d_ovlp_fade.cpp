#include <d_ovlp_fade.h>
#include <f_op_overlap_mng.h>
#include <d_ovlp_fade.h>


namespace d_ovlp_fade {
undefined4 dOvlpFd_execute_f;

/* __stdcall dOvlpFd_Draw(overlap1_class *) */

undefined4 dOvlpFd_Draw(void)

{
  return 1;
}


/* __stdcall dOvlpFd_FadeOut(overlap1_class *) */

undefined4 dOvlpFd_FadeOut(int param_1)

{
  int iVar1;
  char cVar2;
  
  if (*(int *)(param_1 + 0xcc) == 0) {
    if (*(short *)(param_1 + 0xe) == 2) {
      cVar2 = (**(code **)(*(int *)JFWDisplay::sManager->mpFader + 0xc))
                        (JFWDisplay::sManager->mpFader,0);
      if (cVar2 == '\0') {
        return 1;
      }
      *(undefined4 *)(param_1 + 0xcc) = 1;
    }
    else {
      cVar2 = (**(code **)(*(int *)JFWDisplay::sManager->mpFader + 0xc))
                        (JFWDisplay::sManager->mpFader,0x1a);
      if (cVar2 == '\0') {
        return 1;
      }
      *(undefined4 *)(param_1 + 0xcc) = 0x1a;
    }
  }
  f_op_overlap_mng::fopOvlpM_SceneIsStart();
  iVar1 = *(int *)(param_1 + 0xcc) + -1;
  *(int *)(param_1 + 0xcc) = iVar1;
  if (iVar1 == 0) {
    f_op_overlap_mng::fopOvlpM_Done(param_1);
    *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + 1;
  }
  return 1;
}


/* __stdcall dOvlpFd_Wait(overlap1_class *) */

undefined4 dOvlpFd_Wait(void)

{
  int iVar1;
  
  iVar1 = f_op_overlap_mng::fopOvlpM_IsOutReq();
  if (iVar1 != 0) {
    dOvlpFd_execute_f = dOvlpFd_FadeOut;
  }
  return 1;
}


/* __stdcall dOvlpFd_FadeIn(overlap1_class *) */

undefined4 dOvlpFd_FadeIn(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0xd0) == 0) {
    *(undefined4 *)(param_1 + 0xd0) = 0x1a;
    if ((*(short *)(param_1 + 0xe) == 0) || (*(short *)(param_1 + 0xe) == 3)) {
      piVar2 = (int *)JFWDisplay::sManager->mpFader;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x10))(piVar2,0x1a);
      }
    }
  }
  iVar1 = *(int *)(param_1 + 0xd0) + -1;
  *(int *)(param_1 + 0xd0) = iVar1;
  if (iVar1 == 0) {
    dOvlpFd_execute_f = dOvlpFd_Wait;
    piVar2 = (int *)JFWDisplay::sManager->mpFader;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x10))(piVar2,0);
    }
    f_op_overlap_mng::fopOvlpM_Done(param_1);
  }
  return 1;
}


/* __stdcall dOvlpFd_Execute(overlap1_class *) */

undefined4 dOvlpFd_Execute(void)

{
  (*dOvlpFd_execute_f)();
  return 1;
}


/* __stdcall dOvlpFd_IsDelete(overlap1_class *) */

undefined4 dOvlpFd_IsDelete(void)

{
  return 1;
}


/* __stdcall dOvlpFd_Delete(overlap1_class *) */

undefined4 dOvlpFd_Delete(void)

{
  return 1;
}


/* __stdcall dOvlpFd_Create(void *) */

undefined4 dOvlpFd_Create(void)

{
  dOvlpFd_execute_f = dOvlpFd_FadeIn;
  return 4;
}

