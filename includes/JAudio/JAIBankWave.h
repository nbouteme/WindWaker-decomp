#pragma once
#include <ctypes.h>



namespace JAInter {
//[Data] Expected size is 0x000002
extern undefined1 BankWave;

//[Data] Expected size is 0x000004
extern undefined1 BankWave;

//[BSS] Expected size is 0x000004
extern undefined1 BankWave;
//[BSS] Expected size is 0x000004
extern undefined1 BankWave;
//[BSS] Expected size is 0x000004
extern undefined1 BankWave;
//[BSS] Expected size is 0x000004
extern undefined1 BankWave;
//[BSS] Expected size is 0x000004
extern undefined1 BankWave;

namespace BankWave {
void setWsGroupNumber(long param_1,long param_2);
void setWsLoadStatus(long param_1,long param_2);
}

namespace BankWave {
void loadSceneWave(long param_1,long param_2);
void loadGroupWave(long param_1,long param_2);
}

namespace BankWave {
undefined4 checkAllWaveLoadStatus(void);
}
}
