#pragma once
#include <ctypes.h>

#include <cXyz.h>
#include <cCcD_ShapeAttr__vtbl.h>
#include <Demangler/cCcD_Stts__vtbl.h>

//[Data] Expected size is 0x000060
extern pointer cCcD_SphAttr;

//[Data] Expected size is 0x000060
extern struct cCcD_ShapeAttr__vtbl cCcD_CylAttr;

//[Data] Expected size is 0x000060
extern struct cCcD_ShapeAttr__vtbl cCcD_CpsAttr;


namespace cCcD_TriAttr {
//[Data] Expected size is 0x000060
extern undefined1 __vt;

}

namespace cCcD_Stts {
//[Data] Expected size is 0x000020
extern struct cCcD_Stts__vtbl __vt;

}
//[BSS] Expected size is 0x00000c
extern struct cXyz cCcD_ShapeAttr;

namespace SComponent {
void __sinit_c_cc_d_cpp(void);
}
