#pragma once
#include <ctypes.h>


//Expected size is 0x000004
extern undefined1 DynamicModuleControlBase;

//Expected size is 0x000004
extern undefined1 DynamicModuleControlBase;

//Expected size is 0x000004
extern undefined1 DynamicModuleControl;

//Expected size is 0x000004
extern undefined1 DynamicModuleControl;

//Expected size is 0x000004
extern undefined1 DynamicModuleControl;


namespace DynamicLink {
int calcSum2(ushort *data,ulong size);
}

namespace DynamicLink {
void ModuleProlog(void);
void ModuleEpilog(void);
void ModuleUnresolved(void);
void ModuleConstructorsX(void **contructors);
void ModuleDestructorsX(void **destructors);
}
