#include <dvd/dvdFatal.h>


namespace dvd {
undefined4 FatalFunc;

void __DVDPrintFatalMessage(void)

{
  if (FatalFunc != (code *)0x0) {
    (*FatalFunc)();
  }
  return;
}

