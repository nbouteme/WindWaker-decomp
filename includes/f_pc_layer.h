#pragma once
#include <ctypes.h>



namespace f_pc_layer {
//Expected size is 0x000004
extern undefined4 l_fpcLy_CurrLayer_p;

//Expected size is 0x000004
extern undefined4 IsInitOfLayerList$2270;

//Expected size is 0x000001
extern undefined1 init$2271;

//Expected size is 0x000004
extern undefined4 layer_id$2273;

//Expected size is 0x000001
extern undefined1 init$2274;

void fpcLy_CancelQTo(create_tag_class *param_1);
int fpcLy_ToCancelQ(layer_class *param_1,process_method_tag_class *param_2);
uint fpcLy_CancelMethod(process_method_tag_class *param_1);
void fpcLy_IntoQueue(layer_class *param_1,int param_2,create_tag_class *param_3,int param_4);
void fpcLy_ToQueue(layer_class *param_1,int param_2,create_tag_class *param_3);
void fpcLy_QueueTo(layer_class *param_1,create_tag_class *param_2);
uint fpcLy_IsDeletingMesg(layer_class *param_1);
void fpcLy_DeletingMesg(layer_class *param_1);
void fpcLy_DeletedMesg(layer_class *param_1);
uint fpcLy_IsCreatingMesg(layer_class *param_1);
void fpcLy_CreatingMesg(layer_class *param_1);
void fpcLy_CreatedMesg(layer_class *param_1);
layer_class * fpcLy_RootLayer(void);
void fpcLy_SetCurrentLayer(layer_class *param_1);
layer_class * fpcLy_CurrentLayer(void);
layer_class * fpcLy_Search(uint param_1);
layer_class * fpcLy_Layer(uint param_1);
void fpcLy_Regist(node_class *param_1);
undefined4 fpcLy_Delete(layer_class *pLayer);
void fpcLy_Cancel(layer_class *param_1);
void fpcLy_Create(layer_class *pLayer,void *param_2,node_list_class *param_3,int param_4);
}
