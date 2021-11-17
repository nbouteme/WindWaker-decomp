#pragma once
#include <ctypes.h>



namespace d_mesg {
//Expected size is 0x000004
extern undefined4 dMesg_gpResourceContainer;

//Expected size is 0x000004
extern undefined4 dMesg_gpControl;

//Expected size is 0x000004
extern undefined4 dMesg_gpSequenceProcessor;

//Expected size is 0x000004
extern undefined4 dMesg_gpRenderingProcessor;

//Expected size is 0x000004
extern undefined4 dMesg_gpFont;

//Expected size is 0x000004
extern undefined4 dMesg_gpRFont;

//Expected size is 0x000001
extern undefined1 dMesg_gbUpdate;

//Expected size is 0x000001
extern undefined1 m_strSizeFlag;

//Expected size is 0x000001
extern undefined1 s_strSizeFlag;

//Expected size is 0x000004
extern undefined4 header;

//Expected size is 0x000004
extern undefined4 nowMesgCode;

//Expected size is 0x000004
extern undefined4 oldMesgCode;

//Expected size is 0x000004
extern undefined4 header2;

//Expected size is 0x000001
extern undefined1 headerFlag;

//Expected size is 0x000002
extern undefined2 messageOffsetY;

//Expected size is 0x000001
extern undefined1 zenkaku;

//Expected size is 0x000002
extern undefined2 zenkakuCode;

//Expected size is 0x000004
extern undefined4 retFlag;

//Expected size is 0x000004
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
