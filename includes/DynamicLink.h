#pragma once
#include <ctypes.h>

#include <DynamicModuleControlBase__vtbl.h>


namespace DynamicLink {
//[Data] Expected size is 0x000010
extern TerminatedCString * strings$3042[4];

}
//[Data] Expected size is 0x000034
extern struct DynamicModuleControlBase__vtbl DynamicModuleControl;

//[Data] Expected size is 0x000034
extern undefined1 DynamicModuleControlBase;

//[BSS] Expected size is 0x000004
extern undefined1 DynamicModuleControlBase;
//[BSS] Expected size is 0x000004
extern undefined1 DynamicModuleControlBase;
//[BSS] Expected size is 0x000004
extern undefined1 DynamicModuleControl;
//[BSS] Expected size is 0x000004
extern undefined1 DynamicModuleControl;
//[BSS] Expected size is 0x000004
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
