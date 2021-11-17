#pragma once
#include <ctypes.h>



namespace Runtime.PPCEABI.H {
int __cvt_fp2unsigned(double param_1);
void __save_fpr(void);
}
void FUN_80328e98(void);
void FUN_80328e9c(void);
void FUN_80328ea4(void);
void FUN_80328ea8(void);

namespace Runtime.PPCEABI.H {
void __restore_fpr(void);
}
void FUN_80328ee4(void);
void FUN_80328ee8(void);
void FUN_80328ef0(void);
void FUN_80328ef4(void);

namespace Runtime.PPCEABI.H {
void __save_gpr(void);
}
void FUN_80328f08(void);
void FUN_80328f0c(void);
void FUN_80328f10(void);
void FUN_80328f14(void);
void FUN_80328f18(void);
void FUN_80328f1c(void);
void FUN_80328f20(void);
void FUN_80328f24(void);
void FUN_80328f28(void);
void FUN_80328f2c(void);
void FUN_80328f30(void);
void FUN_80328f34(void);
void FUN_80328f38(void);
void FUN_80328f3c(void);
void FUN_80328f40(void);

namespace Runtime.PPCEABI.H {
void __restore_gpr(void);
}
void FUN_80328f54(void);
void FUN_80328f58(void);
void FUN_80328f5c(void);
void FUN_80328f60(void);
void FUN_80328f64(void);
void FUN_80328f68(void);
void FUN_80328f6c(void);
void FUN_80328f70(void);
void FUN_80328f74(void);
void FUN_80328f78(void);
void FUN_80328f7c(void);
void FUN_80328f80(void);
void FUN_80328f84(void);
void FUN_80328f88(void);
void FUN_80328f8c(void);

namespace Runtime.PPCEABI.H {
undefined8 __div2u(uint param_1,uint param_2,int param_3,uint param_4);
undefined8 __div2i(uint param_1,uint param_2,uint param_3,uint param_4);
undefined8 __mod2u(uint param_1,uint param_2,int param_3,uint param_4);
undefined8 __mod2i(uint param_1,uint param_2,int param_3,uint param_4);
undefined8 __shl2i(int param_1,uint param_2,int param_3);
undefined8 __shr2u(uint param_1,uint param_2,int param_3);
undefined8 __shr2i(int param_1,uint param_2,uint param_3);
undefined8 __cvt_dbl_usll(ulonglong param_1);
}
