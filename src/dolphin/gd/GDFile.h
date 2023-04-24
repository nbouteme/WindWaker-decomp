#pragma once
/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
/*---------------------------------------------------------------------------*/
namespace gd {

// Element of a general-purpose data list.
// This is used to keep track of multiple DL's or multiple patch lists.
typedef struct _GDGList
{
    void *ptr;        // points to either a DL or an array of GDPatch's
    u32   byteLength; // length of DL or number of GDPatch's * sizeof(GDPatch)
} GDGList;

typedef struct _GDFileHeader
{
    u32 versionNumber;    // this kind of thing always seems to be useful
    u32 numDLs;           // how many DL's are in this file?
    u32 numPLs;           // how many patch tables are in this file?
    GDGList *DLDescArray; // pointer (in file it's an offset) to list of DL's
    GDGList *PLDescArray; // pointer (in file it's an offset) to list of PL's
} GDLFileHeader;

enum { GDFileVersionNumber = 0x11223344 };

/*---------------------------------------------------------------------------*/

#ifndef EPPC
s32 GDWriteDLFile(char *fName, u32 numDLs, u32 numPLs,
                  GDGList *DLDescArray, GDGList *PLDescArray);
#endif

s32 GDReadDLFile(const char *fName, u32 *numDLs, u32 *numPLs,
                 GDGList **DLDescArray, GDGList **PLDescArray);
}