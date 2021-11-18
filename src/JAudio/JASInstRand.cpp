#include <JAudio/JASInstRand.h>
#include <JMath/random.h>
#include <JASystem/TInstRand.h>


namespace JASystem {
}

namespace JAudio {
undefined1 init$584;
undefined4 oRandom$583;
}

namespace JASystem {

/* __thiscall TInstRand::getY(int,
                                        int) const */

double __thiscall TInstRand::getY(TInstRand *this,int param_1,int param_2)

{
  if (JAudio::init_584 == '\0') {
    JKernel::JMath::TRandom_fast_::TRandom_fast_((TRandom_fast_ *)&JAudio::oRandom_583,0);
    JAudio::init_584 = '\x01';
  }
  JAudio::oRandom_583 = JAudio::oRandom_583 * 0x19660d + 0x3c6ef35f;
  return (double)((JAudio::_597 * ((float)(JAudio::oRandom_583 >> 9 | 0x3f800000) - JAudio::_596) -
                  JAudio::_598) * *(float *)(this + 0xc) + *(float *)(this + 8));
}

