#pragma once
#include <ctypes.h>

#include <Demangler/JPAEmitterInfo.h>


namespace JPABaseEmitter {
//[BSS] Expected size is 0x00014c
extern struct JPAEmitterInfo emtrInfo;
}

namespace JPABase {
void __sinit_JPAEmitter_cpp(void);
}
