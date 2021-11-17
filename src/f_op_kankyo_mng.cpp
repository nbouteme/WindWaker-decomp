#include <f_op_kankyo_mng.h>
#include <f_pc_executor.h>
#include <SComponent/c_malloc.h>
#include <SComponent/c_lib.h>
#include <f_op_kankyo_mng.h>
#include <f_pc_manager.h>
#include <f_pc_layer.h>
#include <f_pc_stdcreate_req.h>
#include <d_particle.h>


namespace f_op_kankyo_mng {

/* __stdcall fopKyM_SearchByID(unsigned int) */

void fopKyM_SearchByID(uint param_1)

{
  f_pc_executor::fpcEx_SearchByID(param_1);
  return;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall fopKyM_CreateAppend(void) */

fopKyM_prm_class * fopKyM_CreateAppend(void)

{
  float fVar1;
  fopKyM_prm_class *pfVar2;
  
  pfVar2 = (fopKyM_prm_class *)cMl::memalignB(-4,0x1c);
  if (pfVar2 != (fopKyM_prm_class *)0x0) {
    SComponent::cLib_memSet(pfVar2,0,0x1c);
    fVar1 = _4076;
    (pfVar2->mScale).x = _4076;
    (pfVar2->mScale).y = fVar1;
    (pfVar2->mScale).z = fVar1;
  }
  return pfVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall createAppend(int,
                          cXyz *,
                          cXyz *) */

undefined4 * createAppend(int prm,cXyz *param_2,cXyz *param_3)

{
  fopKyM_prm_class *pfVar1;
  
  pfVar1 = fopKyM_CreateAppend();
  if (pfVar1 == (fopKyM_prm_class *)0x0) {
    pfVar1 = (fopKyM_prm_class *)0x0;
  }
  else {
    if (param_2 != (cXyz *)0x0) {
      (pfVar1->mPos).x = param_2->x;
      (pfVar1->mPos).y = param_2->y;
      (pfVar1->mPos).z = param_2->z;
    }
    if (param_3 != (cXyz *)0x0) {
      (pfVar1->mScale).x = param_3->x;
      (pfVar1->mScale).y = param_3->y;
      (pfVar1->mScale).z = param_3->z;
    }
    pfVar1->mParameter = prm;
  }
  return (undefined4 *)pfVar1;
}


/* __stdcall fopKyM_Delete(void *) */

void fopKyM_Delete(base_process_class *param_1)

{
  f_pc_manager::fpcM_Delete(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopKyM_Create(short,
                           int *(void *),
                           void *) */

void fopKyM_Create(short param_1,undefined *param_2,void *param_3)

{
  layer_class *plVar1;
  
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_stdcreate_req::fpcSCtRq_Request(plVar1,param_1,param_2,(void *)0x0,param_3);
  return;
}


/* __stdcall fopKyM_create(short,
                           int,
                           cXyz *,
                           cXyz *,
                           int *(void *)) */

undefined4
fopKyM_create
          (int procName,int parameter,cXyz *pPos,cXyz *pScale,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = createAppend(parameter,pPos,pScale);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = fopKyM_Create(procName,param_5);
  }
  return uVar2;
}


/* __stdcall fopKyM_fastCreate(short,
                               int,
                               cXyz *,
                               cXyz *,
                               int *(void *)) */

undefined4
fopKyM_fastCreate
          (undefined4 param_1,int param_2,cXyz *param_3,cXyz *param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = createAppend(param_2,param_3,param_4);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = f_pc_manager::fpcM_FastCreate(param_1,param_5,0);
  }
  return uVar2;
}


/* WARNING: Removing unreachable block (ram,0x8002ab18) */
/* WARNING: Removing unreachable block (ram,0x8002ab20) */
/* __stdcall fopKyM_createWpillar(cXyz const *,
                                  float,
                                  float,
                                  int) */

undefined4
fopKyM_createWpillar(double param_1,double param_2,float *param_3,int param_4)

{
  fopKyM_prm_class *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pfVar1 = fopKyM_CreateAppend();
  if (pfVar1 == (fopKyM_prm_class *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    (pfVar1->mPos).x = *param_3;
    (pfVar1->mPos).y = param_3[1];
    (pfVar1->mPos).z = param_3[2];
    (pfVar1->mScale).x = (float)param_1;
    (pfVar1->mScale).y = (float)param_2;
    (pfVar1->mScale).z = (float)param_1;
    pfVar1->mParameter = param_4;
    uVar2 = fopKyM_Create(0x1c7,0);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return uVar2;
}


/* __stdcall fopKyM_createMpillar(cXyz const *,
                                  float) */

undefined4 fopKyM_createMpillar(double param_1,cXyz *param_2)

{
  cXyz local_18;
  
  local_18.x = (float)param_1;
  local_18.y = (float)param_1;
  local_18.z = (float)param_1;
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x80d5,param_2,
                     (csXyz *)0x0,&local_18,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                     (_GXColor *)0x0,(cXyz *)0x0);
  return 0xffffffff;
}

