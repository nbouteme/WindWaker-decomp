#pragma once
#include <ctypes.h>



namespace os {
void OSNotifyLink(void);
void OSNotifyUnlink(void);
void OSSetStringTable(undefined4 param_1);
undefined4 Relocate(int *param_1,int param_2);
undefined4 Link(DynamicModule *rel,uint param_2,int param_3);
void OSLink(DynamicModule *param_1,undefined4 param_2);
undefined4 OSLinkFixed(DynamicModule *rel,undefined4 param_2);
undefined4 Undo(int *param_1,int param_2);
undefined4 OSUnlink(int param_1);
void __OSModuleInit(void);
}
