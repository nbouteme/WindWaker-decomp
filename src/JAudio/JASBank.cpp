#include <JAudio/JASBank.h>
#include <JASystem/TBank.h>


namespace JASystem {
undefined1 TBank;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TBank::getCurrentHeap(void) */

int __thiscall TBank::getCurrentHeap(TBank *this)

{
  if (_sCurrentHeap != 0) {
    return _sCurrentHeap;
  }
  return JAudio::JASDram;
}

