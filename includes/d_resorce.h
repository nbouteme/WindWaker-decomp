#pragma once
#include <ctypes.h>



namespace d_resorce {
//[Data] Expected size is 0x000074
extern char l_readResType$4166[120];

}
//[Data] Expected size is 0x000010
extern char JKRFileFinder;

//[Data] Expected size is 0x000014
extern pointer mDoExt_transAnmBas;

//[Data] Expected size is 0x000010
extern pointer J3DAnmTransform;

//[Data] Expected size is 0x00000c
extern pointer J3DAnmBase;


namespace d_resorce {
//[BSS] Expected size is 0x000004
extern undefined4 mode$4439;
//[BSS] Expected size is 0x000001
extern undefined1 init$4440;
//[BSS] Expected size is 0x000004
extern undefined4 allocMode$4442;
//[BSS] Expected size is 0x000001
extern undefined1 init$4443;
}

namespace d_resorce {
void setToonTex(J3DModelData *pModel);
void setToonTex(J3DMaterialTable *pMat);
}

namespace d_resorce {
JKRArchive__Header * getArcHeader(JKRArchive *param_1);
}

namespace dRes_control_c {
void setRes(char *param_1,dRes_info_c *param_2,int param_3,char *param_4,byte param_5,JKRHeap *param_6);
undefined4 syncRes(char *param_1,dRes_info_c *param_2,int param_3);
undefined4 deleteRes(char *pName,dRes_info_c *pResInfoList,int count);
dRes_info_c * getResInfo(char *pArcName,dRes_info_c *pResInfoList,int count);
dRes_info_c * newResInfo(dRes_info_c *param_1,int param_2);
dRes_info_c *getResInfoLoaded(char *arcName,dRes_info_c *resInfosList,int totalResInfos);
void * getRes(char *arcName,long fileIndex,dRes_info_c *resInfosList,int totalResInfos);
void * getRes(char *param_1,char *param_2,dRes_info_c *param_3,int param_4);
void * getIDRes(char *param_1,ushort param_2,dRes_info_c *param_3,int param_4);
}
