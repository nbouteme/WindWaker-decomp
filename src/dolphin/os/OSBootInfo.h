#pragma once
#include "../dvd.h"

#define OS_BOOTINFO_MAGIC       0x0D15EA5E
#define OS_BOOTINFO_MAGIC_JTAG  0xE5207C22

// The location of this structure is in OSLowMem.h
// This structure must be 32 byte aligned (BS2 will load
// the disk ID directly into here).  As a result, DVDDiskID
// MUST BE THE FIRST MEMBER OF THIS STRUCTURE.

typedef struct OSBootInfo_s
{
    dvd::DVDDiskID  DVDDiskID;       // This must ALWAYS be the first member
    u32        magic;
    u32        version;

    u32        memorySize;      // NOTE: BS2 updates this.  Since BS2 is on the
                                // boot rom, you cannot change the position of
                                // this field.
    u32        consoleType;     // NOTE: BS2 updates this.  Since BS2 is on the
                                // boot rom, you cannot change the position of
                                // this field.

    void*      arenaLo;         // if non NULL, overrides __ArenaLo
    void*      arenaHi;         // if non NULL, overrides FSTLocation
    void*      FSTLocation;     // Start address of "FST area"
    u32        FSTMaxLength;    // Length of "FST area"
} OSBootInfo;
