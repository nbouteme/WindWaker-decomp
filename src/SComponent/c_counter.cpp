#include <SComponent/c_counter.h>


namespace SComponent {
undefined4 g_Counter;

/* __stdcall cCt_Counter(int) */

void cCt_Counter(int param_1)

{
  if (param_1 == 1) {
    DAT_803e8144 = 0;
  }
  else {
    DAT_803e8144 = DAT_803e8144 + 1;
  }
  g_Counter = g_Counter + 1;
  return;
}

