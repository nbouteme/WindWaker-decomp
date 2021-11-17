#pragma once
#include <ctypes.h>

#include <JPAFieldContainer.h>

//Expected size is 0x000024
extern struct JPAFieldContainer JPAFieldManager;


namespace JPAFieldData {
//Expected size is 0x000004
extern struct JPAEmitterInfo * pEmtrInfo;

}

namespace JPABase {
void __sinit_JPAField_cpp(void);
}
