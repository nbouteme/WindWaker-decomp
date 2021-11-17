#include <JAudio/JASWaveBank.h>
#include <JASystem/TWaveBank.h>


namespace JASystem {
undefined1 TWaveBank;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TWaveBank::getCurrentHeap(void) */

int __thiscall TWaveBank::getCurrentHeap(TWaveBank *this)

{
  if (_sCurrentHeap != 0) {
    return _sCurrentHeap;
  }
  return JAudio::JASDram;
}

