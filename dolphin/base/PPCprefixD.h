/*---------------------------------------------------------------------------*
  Project:  Dolphin OS PPC prefix header, Debug version
  File:     PPCprefixD.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: /dolphin.cmdline/include/base/PPCprefixD.h $
    
    2     5/03/99 5:25p Tianli01
    PPC->EPPC
    
    1     4/30/99 12:49p Tianli01
    
    2     4/21/99 8:15p Shiki
    Moved to _DEBUG (avoid DEBUG).

    1     3/09/99 11:36a Tianli01
    Initial checkin.  PPC/X86 prefix header files

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#define _DEBUG
#include "ansi_prefix.PPCEABI.bare.h"
#define EPPC
