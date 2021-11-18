#pragma once
#include <ctypes.h>



namespace d_mesg {
//[Data] Expected size is 0x00000c
extern pointer name$4067;

//[Data] Expected size is 0x000014
extern undefined * l_dMesg_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_MESG;

}
//[Data] Expected size is 0x00000c
extern undefined1 dMesg_outFont_c;

//[Data] Expected size is 0x000028
extern undefined1 dMesg_screenData_c;


namespace JGadget {

namespace TLinkList_factory<JMessage::TResource,0> {
//[Data] Expected size is 0x000014
extern undefined1 __vt;

}
}
//[Data] Expected size is 0x00002c
extern undefined1 dMesg_screenDataItem_c;

//[Data] Expected size is 0x000028
extern undefined1 dMesg_screenDataTalk_c;

//[Data] Expected size is 0x00003c
extern undefined1 dMesg_tRenderingProcessor;

//[Data] Expected size is 0x000054
extern undefined1 dMesg_tMeasureProcessor;

//[Data] Expected size is 0x000054
extern undefined1 dMesg_tSequenceProcessor;

//[Data] Expected size is 0x000010
extern undefined1 dMesg_tControl;


namespace d_mesg {
//[Data] Expected size is 0x000002
extern undefined2 linemax;

//[BSS] Expected size is 0x000004
extern undefined4 dMesg_gpResourceContainer;
//[BSS] Expected size is 0x000004
extern undefined4 dMesg_gpControl;
//[BSS] Expected size is 0x000004
extern undefined4 dMesg_gpSequenceProcessor;
//[BSS] Expected size is 0x000004
extern undefined4 dMesg_gpRenderingProcessor;
//[BSS] Expected size is 0x000004
extern undefined4 dMesg_gpFont;
//[BSS] Expected size is 0x000004
extern undefined4 dMesg_gpRFont;
//[BSS] Expected size is 0x000001
extern undefined1 dMesg_gbUpdate;
//[BSS] Expected size is 0x000001
extern undefined1 m_strSizeFlag;
//[BSS] Expected size is 0x000001
extern undefined1 s_strSizeFlag;
//[BSS] Expected size is 0x000004
extern undefined4 header;
//[BSS] Expected size is 0x000004
extern undefined4 nowMesgCode;
//[BSS] Expected size is 0x000004
extern undefined4 oldMesgCode;
//[BSS] Expected size is 0x000004
extern undefined4 header2;
//[BSS] Expected size is 0x000001
extern undefined1 headerFlag;
//[BSS] Expected size is 0x000002
extern undefined2 messageOffsetY;
//[BSS] Expected size is 0x000001
extern undefined1 zenkaku;
//[BSS] Expected size is 0x000002
extern undefined2 zenkakuCode;
//[BSS] Expected size is 0x000004
extern undefined4 retFlag;
//[BSS] Expected size is 0x000004
extern undefined4 oParse;
}

namespace d_mesg {
void dMesg_initialize(undefined4 param_1);
void dMesg_finalize(void);
}

namespace JMessage {
}

namespace d_mesg {
undefined4 dMesg_parse(void);
void dMesg_reset(void);
void dMesg_update(void);
void dMesg_render(void);
void dMesg_fontsizeCenter(int param_1,int param_2,int param_3);
undefined4 dMesg_hyrule_language_check(int param_1);
void dMesg_fontsizeCenter(int param_1,undefined4 param_2,undefined4 param_3);
void dMesg_waitProc(int param_1);
}

namespace d_mesg {
void dMesg_openProc(int param_1);
void dMesg_outnowProc(int param_1);
void dMesg_outwaitProc(int param_1);
void dMesg_stopProc(int param_1);
void dMesg_closewaitProc(int param_1);
void dMesg_closeProc(int param_1);
undefined4 dMsg_Draw(int param_1);
undefined4 dMsg_Execute(int param_1);
}

namespace d_mesg {
undefined4 dMsg_IsDelete(void);
undefined4 dMsg_Delete(int param_1);
undefined4 dMsg_Create(int param_1);
}
