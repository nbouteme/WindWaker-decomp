#include <dolphin/base.h>

#include <cstdlib>
#include <cstdio>

namespace base {
    u32 PPCMfmsr() {
        return 0;
    }

    void PPCHalt() {
        puts("HALTING");
        exit(4);
    }

    void PPCSync() {        
    }
}