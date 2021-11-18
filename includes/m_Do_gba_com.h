#pragma once
#include <ctypes.h>



namespace m_Do_ext {

namespace m_Do_gba_com {
//[BSS] Expected size is 0x000130
extern undefined1 g_mDoGaC_gbaCom;
//[BSS] Expected size is 0x000080
extern undefined TestDataManager;
//[BSS] Expected size is 0x000004
extern undefined4 flag$4426;
//[BSS] Expected size is 0x000001
extern undefined1 init$4427;
//[BSS] Expected size is 0x000001
extern undefined1 data_type$4481;
//[BSS] Expected size is 0x000001
extern undefined1 init$4482;
//[BSS] Expected size is 0x000004
extern undefined4 check_sum$4484;
//[BSS] Expected size is 0x000001
extern undefined1 init$4485;
//[BSS] Expected size is 0x000004
extern undefined4 data_sum$4487;
//[BSS] Expected size is 0x000001
extern undefined1 init$4488;
//[BSS] Expected size is 0x000004
extern undefined4 recv_p$4490;
//[BSS] Expected size is 0x000001
extern undefined1 init$4491;
//[BSS] Expected size is 0x000004
extern undefined4 end_p$4493;
//[BSS] Expected size is 0x000001
extern undefined1 init$4494;
void ProbeCheck_0(void);
void ProbeCheck_1(void);
void CodeExchange_0(void);
void CodeExchange_1(void);
void CodeExchange_2(void);
void CodeExchange_3(void);
void CodeExchange_4(void);
void ContextCheck(void);
void ContextSend(void);
void ContextRead(void);
void GbaWriteResult(void);
void GbaReadResult(void);
void GbaReset(void);
}
}

namespace m_Do_ext {

namespace m_Do_gba_com {
undefined4 BigLittleChange(undefined4 param_1);
void __sinit_m_Do_gba_com_cpp(void);
}
}
