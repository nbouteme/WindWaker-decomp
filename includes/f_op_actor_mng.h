#pragma once
#include <ctypes.h>

#include <dBgS_WtrChk.h>


namespace f_op_actor_mng {
//Expected size is 0x000150
extern struct fopAc_cullSizeBox l_cullSizeBox[14];

//Expected size is 0x000080
extern struct fopAc_cullSizeSphere l_cullSizeSphere[8];

//Expected size is 0x00000c
extern undefined min$4862;

//Expected size is 0x00000c
extern undefined max$4898;

//Expected size is 0x000024
extern undefined4 fairy_offset_tbl$5080;

//Expected size is 0x000050
extern struct dBgS_WtrChk water_check$6113;

}

namespace fopAcM {
//Expected size is 0x000001
extern undefined1 HeapAdjustEntry;

//Expected size is 0x000001
extern undefined1 HeapAdjustVerbose;

//Expected size is 0x000001
extern byte HeapAdjustQuiet;

}

namespace f_op_actor_mng {
//Expected size is 0x000001
extern undefined l_hio;

//Expected size is 0x000001
extern undefined1 init$5082;

//Expected size is 0x000001
extern undefined1 init$6115;

void fopAcM_setStageLayer(fopAc_ac_c *param_1);
void fopAcM_setRoomLayer(fopAc_ac_c *param_1,int param_2);
undefined4 fopAcM_SearchByID(undefined4 param_1,fopAc_ac_c **param_2);
undefined4 fopAcM_SearchByName(short param_1,fopAc_ac_c **param_2);
fopAcM_prm_class * fopAcM_CreateAppend(void);
undefined4 *createAppend(ulong parameters,cXyz *pPos,int roomNo,csXyz *angle,cXyz *scale,char subtype,uint parentUniqueID);
void fopAcM_Log(void);
void fopAcM_delete(base_process_class *param_1);
void fopAcM_delete(undefined4 param_1);
undefined4 fopAcM_create(short procName,ulong parameters,cXyz *pPos,int roomNo,csXyz *pAngle,cXyz *pScale,byte subtype,undefined *param_8);
undefined4 fopAcM_create(char *param_1,ulong param_2,cXyz *param_3,int param_4,csXyz *param_5,cXyz *param_6,undefined *param_7);
fopAc_ac_c *fopAcM_fastCreate(short actorID,ulong parameters,cXyz *pPos,int roomNo,csXyz *pAngle,cXyz *pScale,byte subtype,undefined *pCallBack,void *pCallBackUserData);
fopAc_ac_c *fopAcM_fastCreate(char *param_1,ulong param_2,cXyz *param_3,int param_4,csXyz *param_5,cXyz *param_6,undefined *param_7,void *param_8);
undefined4 fopAcM_createChild(short param_1,uint parentUniqueID,ulong param_3,cXyz *param_4,int param_5,csXyz *param_6,cXyz *param_7,char param_8,undefined *param_9);
int fopAcM_createChild(char *param_1,uint param_2,ulong param_3,cXyz *param_4,int param_5,csXyz *param_6,cXyz *param_7,undefined *param_8);
undefined4 fopAcM_createChildFromOffset(short param_1,uint param_2,ulong param_3,float *param_4,int param_5,short *param_6,cXyz *param_7,char param_8,undefined *param_9);
void fopAcM_createChildFromOffset(char *param_1,undefined4 param_2,undefined4 param_3,float *param_4,undefined4 param_5,short *param_6,undefined4 param_7,undefined4 param_8);
bool fopAcM_createHeap(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,char *param_6);
void fopAcM_adjustHeap(int param_1);
void fopAcM_DeleteHeap(int param_1);
undefined4 fopAcM_entrySolidHeap(fopAc_ac_c *pActor,void *pCreateHeapCB,ulong maxHeapSize);
void fopAcM_setCullSizeBox(fopAc_ac_c *param_1,double param_2,double param_3,double param_4,double param_5,double param_6,double param_7);
void fopAcM_setCullSizeSphere(fopAc_ac_c *param_1,float param_2,float param_3,float param_4,float param_5);
uint fopAcM_addAngleY(fopAc_ac_c *param_1,short param_2,short param_3);
void fopAcM_calcSpeed(fopAc_ac_c *param_1);
void fopAcM_posMove(fopAc_ac_c *param_1,cXyz *param_2);
void fopAcM_posMoveF(fopAc_ac_c *param_1,cXyz *param_2);
int fopAcM_searchActorAngleY(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
short fopAcM_seenActorAngleY(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
double fopAcM_searchActorDistance(int param_1,int param_2);
double fopAcM_searchActorDistance2(int param_1,int param_2);
double fopAcM_searchActorDistanceXZ(int param_1,int param_2);
double fopAcM_searchActorDistanceXZ2(int param_1,int param_2);
undefined4 fopAcM_rollPlayerCrash(fopAc_ac_c *param_1,float param_2,undefined4 param_3);
uint fopAcM_checkCullingBox(MTX34 *param_1,float param_2,float param_3,float param_4,float param_5,float param_6,float param_7);
uint fopAcM_cullingCheck(fopAc_ac_c *pActor);
void fopAcM_orderTalkEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
void fopAcM_orderTalkXBtnEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
void fopAcM_orderTalkYBtnEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
void fopAcM_orderTalkZBtnEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
void fopAcM_orderZHintEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
void fopAcM_orderSpeakEvent(fopAc_ac_c *param_1);
void fopAcM_orderDoorEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
void fopAcM_orderCatchEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
void fopAcM_orderOtherEvent2(fopAc_ac_c *pActor,char *pEventName,dEvt__OrderFlag flag,ushort param_4);
void fopAcM_orderChangeEvent(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4);
void fopAcM_orderChangeEvent(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,undefined4 param_5);
void fopAcM_orderChangeEventId(fopAc_ac_c *param_1,short param_2,dEvt__OrderFlag param_3,ushort param_4);
void fopAcM_orderChangeEventId(fopAc_ac_c *param_1,fopAc_ac_c *param_2,short param_3,dEvt__OrderFlag param_4,ushort param_5);
void fopAcM_orderOtherEventId(fopAc_ac_c *this,short eventIndex,byte param_3,ushort param_4,ushort param_5,dEvt__OrderFlag param_6);
void fopAcM_orderPotentialEvent(fopAc_ac_c *param_1,dEvt__OrderFlag param_2,ushort param_3,ushort param_4);
void fopAcM_orderItemEvent(fopAc_ac_c *param_1);
void fopAcM_orderTreasureEvent(fopAc_ac_c *param_1,fopAc_ac_c *param_2);
void fopAcM_getTalkEventPartner(void);
void fopAcM_getItemEventPartner(void);
void fopAcM_getEventPartner(fopAc_ac_c *param_1);
int fopAcM_createItemForPresentDemo(cXyz *param_1,dItem_data__ItemNo param_2,byte param_3,int param_4,int param_5,csXyz *param_6,cXyz *param_7);
undefined4 fopAcM_createItemForTrBoxDemo(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6);
int fopAcM_createItemFromTable(cXyz *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,csXyz *param_6,undefined4 param_7,cXyz *param_8);
undefined4 fopAcM_createRaceItemFromTable(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
int fopAcM_createShopItem(cXyz *pos,ulong itemNo,csXyz *rotation,int roomNo,cXyz *scale,undefined *param_6);
undefined4 fopAcM_createRaceItem(cXyz *param_1,int param_2,uint param_3,csXyz *param_4,int param_5,cXyz *param_6,uint param_7);
undefined4 fopAcM_createDemoItem(cXyz *param_1,uint param_2,uint param_3,csXyz *param_4,int param_5,cXyz *param_6,uint param_7);
void fopAcM_createItemForBoss(cXyz *position,int param_2,int roomNo,csXyz *rotation,cXyz *scale,int param_6);
undefined4 fopAcM_createItem(cXyz *position,dItem_data__ItemNo itemNo,int itemPickupFlag,int roomNo,uint param_5,csXyz *rotation,int itemAction,cXyz *scale);
fopAc_ac_c *fopAcM_fastCreateItem2(cXyz *position,int param_2,uint param_3,int roomNo,uint param_5,csXyz *rotation,int param_7,cXyz *scale);
fopAc_ac_c *fopAcM_createItemForKP2(double param_1,double param_2,double param_3,cXyz *param_4,uint param_5,int param_6,csXyz *param_7,cXyz *param_8,uint param_9);
void fopAcM_createItemForSimpleDemo(double param_1,double param_2,cXyz *param_3,uint param_4,int param_5,csXyz *param_6,cXyz *param_7);
daItem_c *fopAcM_fastCreateItem(cXyz *position,uint itemNo,int roomNum,csXyz *rotation,cXyz *scale,double speed,double param_7,double param_8,uint itemPickupFlag,undefined *param_10);
undefined4 stealItem_CB(int param_1);
void fopAcM_createStealItem(cXyz *param_1,undefined2 param_2,int param_3,csXyz *param_4,uint param_5);
void fopAcM_createItemFromEnemyTable(uint tableIndex,uint itemPickupFlag,int roomNo,cXyz *pos,csXyz *rot);
uint fopAcM_createIball(cXyz *pPos,int param_low,int roomNo,csXyz *pRot,int switchId);
void fopAcM_createWarpFlower(cXyz *param_1,csXyz *param_2,int param_3,uint param_4);
fopAc_ac_c * enemySearchJugge(fopAc_ac_c *param_1);
void fopAcM_myRoomSearchEnemy(char param_1);
uint fopAcM_createDisappear(int param_1,cXyz *param_2,uint param_3,uint param_4,uint param_5);
bool fopAcM_getGroundAngle(fopAc_ac_c *param_1,csXyz *param_2);
void fopAcM_setCarryNow(fopAc_ac_c *param_1,int param_2);
void fopAcM_cancelCarryNow(fopAc_ac_c *param_1);
undefined fopAcM_viewCutoffCheck(double param_1,fopAc_ac_c *param_2);
float fopAcM_otoCheck(double param_1,int param_2);
char * fopAcM_getProcNameString(fopAc_ac_c *param_1);
int fopAcM_findObjectCB(fopAc_ac_c *param_1,void *(*param_2) [3]);
void fopAcM_searchFromName(char *actorName,ulong paramMaskToCheck,ulong desiredParamValue);
uint fopAcM_getWaterY(cXyz *param_1,float *param_2);
}

namespace f_op_actor_mng {
void fopAcM_setGbaName(fopAc_ac_c *this,dItem_data__ItemNo itemNo,GbaNames gbaNameIfNotHaveItem,GbaNames gbaNameIfHaveItem);
void fpoAcM_absolutePos(fopAc_ac_c *param_1,cXyz *param_2,cXyz *param_3);
void fpoAcM_relativePos(fopAc_ac_c *param_1,cXyz *param_2,cXyz *param_3);
}

namespace f_op_actor_mng {
void __sinit_f_op_actor_mng_cpp(void);
}
