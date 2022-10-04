#pragma once

/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>

namespace gx {

typedef enum {
    GX_WARN_NONE,       // no warnings reported
    GX_WARN_SEVERE,     // reports only severest warnings
    GX_WARN_MEDIUM,     // reports severe and medium warnings
    GX_WARN_ALL         // reports any and all warning info
} GXWarningLevel;

#ifdef _DEBUG
extern void GXSetVerifyLevel( GXWarningLevel level );
#else
#define GXSetVerifyLevel(level)     ((void)0)
#endif

// Note: warning IDs are subject to change.
//       warning messages are subject to change as well.

typedef void (*GXVerifyCallback)(GXWarningLevel level, 
                                 u32            id, 
                                 const char*          msg);

#ifdef _DEBUG
GXVerifyCallback GXSetVerifyCallback( GXVerifyCallback cb );
#else
#define GXSetVerifyCallback(cb)     ((GXVerifyCallback)0)
#endif
}