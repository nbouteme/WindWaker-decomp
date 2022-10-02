#include <dolphin/base.h>

#include <cstdlib>

namespace base {
    u32 PPCMfmsr() {
        return 0;
    }

    void PPCHalt() {
        exit(4);
    }
}