#pragma once
#include <ctypes.h>

#include <cXyz.h>


namespace d_stage {
//Expected size is 0x000404
extern undefined TresureInfo;

//Expected size is 0x000904
extern undefined4 DoorInfo;

//Expected size is 0x00000c
extern struct cXyz l_offset$4537;

//Expected size is 0x000060
extern struct MTX34 l_m$4541[2];

}
//Expected size is 0x004500
extern struct dStage_roomStatus_c dStage_roomControl_c[64];

//Expected size is 0x000040
extern struct JKRExpHeap * dStage_roomControl_c[101];


namespace d_stage {
//Expected size is 0x000001
extern undefined1 init$4539;

}
//Expected size is 0x000004
extern int dStage_roomControl_c;

//Expected size is 0x000001
extern byte dStage_roomControl_c;

//Expected size is 0x000001
extern undefined1 dStage_roomControl_c;

//Expected size is 0x000001
extern undefined1 dStage_roomControl_c;

//Expected size is 0x000008
extern char dStage_roomControl_c[8];

//Expected size is 0x000001
extern byte dStage_roomControl_c;


namespace d_stage {
void dStage_SetErrorRoom(void);
void dStage_SetErrorStage(void);
undefined * dStage_GetKeepTresureInfo(void);
undefined4 * dStage_GetKeepDoorInfo(void);
void dStage_KeepTresureInfoProc(dStage_dt_c *param_1,stage_tresure_class *param_2);
void dStage_KeepDoorInfoProc(int *param_1,int *param_2);
}

namespace dStage_roomControl_c {
JKRHeap * getMemoryBlock(int param_1);
void setStayNo(int param_1);
}

namespace d_stage {
undefined4 stayRoomCheck(int param_1,byte *param_2,uint param_3);
undefined4 createRoomScene(int param_1);
}

namespace dStage_roomControl_c {
JKRExpHeap * createMemoryBlock(int param_1,ulong param_2);
}

namespace d_stage {
undefined4 dStage_roomInit(int param_1);
dStage__ObjectNameTable * dStage_searchName(char *pName);
char * dStage_getName(short param_1,char param_2);
char * dStage_getName2(short param_1,byte param_2);
void dStage_actorCreate(char *param_1,fopAcM_prm_class *param_2);
undefined4 dStage_cameraCreate(undefined4 param_1,undefined4 param_2,undefined4 param_3);
char * dStage_decodeSearchIkada(void *param_1,uint param_2);
void dStage_playerInitIkada(fopAcM_prm_class *param_1,void *param_2);
undefined4 dStage_chkPlayerId(uint param_1,int param_2);
}

namespace d_stage {
undefined4 dStage_playerInit(dStage_dt_c *pStag,void *pData,int count,void *param_4);
undefined4 dStage_cameraInit(int *param_1,int param_2);
undefined4 dStage_RoomCameraInit(int *param_1,int param_2);
undefined4 dStage_arrowInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
uint dStage_mapInfo_GetOceanX(stage_map_info_class *param_1);
uint dStage_mapInfo_GetOceanZ(stage_map_info_class *param_1);
undefined4 dStage_mapInfoInit(dStage_dt_c *param_1,void *param_2);
}

namespace d_stage {
undefined4 dStage_paletInfoInit(int *param_1,int param_2);
undefined4 dStage_pselectInfoInit(int *param_1,int param_2);
undefined4 dStage_envrInfoInit(int *param_1,int param_2);
undefined4 dStage_filiInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_vrboxInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_plightInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_lgtvInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_stagInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_sclsInfoInit(dStage_dt_c *param_1,int param_2);
fopAcM_prm_class *dStage_actorInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_tgscInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_roomReadInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
byte dStage_roomRead_dt_c_GetReverbStage(roomRead_class *param_1,int param_2);
undefined4 dStage_ppntInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_pathInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_rppnInfoInit(dStage_dt_c *param_1,int param_2,void *param_3,void *param_4);
undefined4 dStage_rpatInfoInit(dStage_dt_c *pStage,void *param_2,int param_3,void *param_4);
undefined4 dStage_soundInfoInit(int *param_1,int param_2);
undefined4 dStage_eventInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_floorInfoInit(int *param_1,int param_2);
undefined4 dStage_memaInfoInit(int *param_1,int param_2);
undefined4 dStage_mecoInfoInit(int *param_1,int param_2);
undefined4 dStage_setShipPos(int param_1,int param_2);
undefined4 dStage_chkTaura(int param_1);
undefined4 dStage_shipInfoInit(int *param_1,int param_2);
undefined4 dStage_multInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_lbnkInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_stageTresureInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_roomTresureInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_layerTresureInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
undefined4 dStage_dmapInfoInit(int *param_1,int param_2);
undefined4 dStage_stageDrtgInfoInit(dStage_dt_c *param_1,int param_2,int param_3,void *param_4);
undefined4 dStage_roomDrtgInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4);
void dKankyo_create(void);
void dStage_dt_c_decode(void *pData,dStage_dt_c *pStage,dStage_dt__FuncTable *pTable,int tableCount);
void dStage_dt_c_offsetToPtr(int *param_1);
void dStage_dt_c_stageInitLoader(void *param_1,dStage_dt_c *param_2);
void layerLoader(void *param_1,dStage_dt_c *param_2,int param_3);
void dStage_dt_c_stageLoader(void *param_1,dStage_dt_c *param_2);
void dStage_dt_c_roomLoader(void *param_1,dStage_dt_c *param_2);
void dStage_dt_c_roomReLoader(void *param_1,dStage_dt_c *param_2,int param_3);
void dStage_infoCreate(void);
void dStage_Create(void);
void dStage_Delete(void);
undefined4 dStage_RoomCheck(cBgS_GndChk *param_1);
}

namespace dStage_roomControl_c {
void SetTimePass(int param_1);
}

namespace d_stage {
undefined4 dStage_changeSceneExitId(cBgS_PolyInfo *pPoly,float param_2,uint param_3,byte roomIdxFallback);
undefined4 dStage_changeScene(int sclsIdx,float param_2,uint param_3,byte roomNo);
}

namespace d_stage {
void dStage_restartRoom(int param_1,int param_2);
void dStage_turnRestart(void);
void dStage_escapeRestart(void);
undefined4 dStage_checkRestart(void);
}

namespace d_stage {
void __sinit_d_stage_cpp(void);
void __arraydtor$5591(void);
}
