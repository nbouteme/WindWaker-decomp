#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <cstdio>
#include <talloc.h>
#include <cstdlib>

namespace os {

    void OSInit(void) {
        puts("Initializing OS module...");

        dvd::DVDInit();
    }
}