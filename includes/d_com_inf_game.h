#pragma once
#include <ctypes.h>

#include <dComIfG_inf_c.h>


namespace d_com_inf_game {
//Expected size is 0x01d1c8
extern struct dComIfG_inf_c g_dComIfG_gameInfo;

}

namespace dComIfG_play_c {
uint getLayerNo(int param_1);
}

namespace d_com_inf_game {
undefined4 dComIfG_changeOpeningScene(scene_class *pScene,int procName);
undefined4 dComIfG_resetToOpening(scene_class *param_1);
undefined4 phase_1(char *param_1);
uint phase_2(char *param_1);
undefined4 phase_3(void);
PhaseState dComIfG_resLoad(request_of_phase_process_class *param_1,char *param_2);
undefined4 dComIfG_resDelete(request_of_phase_process_class *param_1,char *param_2);
void dComIfGp_getReverb(undefined4 param_1);
undefined4 dComIfGd_setSimpleShadow2(cXyz *pPos,float param_2,float param_3,cBgS_PolyInfo *pFloorPoly,short rotY,float param_6,_GXTexObj *pTexObj);
int dComIfGp_getShip(int param_1,uint param_2);
undefined4 dComIfGp_getMapTrans(int param_1,float *param_2,float *param_3,short *param_4);
stage_camera_class * dComIfGp_getRoomCamera(int param_1);
stage_arrow_class * dComIfGp_getRoomArrow(int param_1);
void dComIfGp_setNextStage(char *pStageName,short startCode,byte roomIdx,byte layerNo,float param_5,uint mode,int param_7,byte wipeType);
void dComIfGs_onStageTbox(uint param_1,int param_2);
void dComIfGs_isStageTbox(uint param_1,int param_2);
void dComIfGs_isStageBossEnemy(uint param_1);
void dComIfGs_onStageLife(uint param_1);
void dComIfGs_isStageLife(uint param_1);
bool dComIfGs_checkGetItem(dItem_data__ItemNo itemNo);
undefined dComIfGs_checkGetItemNum(dItem_data__ItemNo param_1);
int dComIfGd_setShadow(ulong id,byte param_2,J3DModel *pModel,cXyz *pPos,float param_5,float param_6,float y,float param_8,cBgS_PolyInfo *pFloorPoly,dKy_tevstr_c *param_10,short rotY,float param_12,_GXTexObj *pTexObj);
stage_scls_info_class * getSceneList(int i_no);
stage_scls_info_class * dComIfGd_getMeshSceneList(cXyz *pVec);
int dComIfGs_checkSeaLandingEvent(byte param_1);
void dComIfGs_setGameStartStage(void);
void dComIfGs_gameStart(void);
void dComIfGs_copyPlayerRecollectionData(void);
void dComIfGs_setPlayerRecollectionData(undefined4 param_1,uchar param_2);
void dComIfGs_revPlayerRecollectionData(void);
void dComIfGs_exchangePlayerRecollectionData(void);
void dComIfGs_setSelectEquip(int category,dItem_data__ItemNo item);
void __sinit_d_com_inf_game_cpp(void);
}
