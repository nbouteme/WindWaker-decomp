/*---------------------------------------------------------------------------*
  Project:  Performance Monitor API
  File:     PPCPm.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: /Dolphin/include/dolphin/base/PPCPm.h $
    
    1     12/16/99 6:21p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __PPCPM_H__
#define __PPCPM_H__

#ifdef __cplusplus
extern "C" {
#endif

void PMBegin        (void);
void PMEnd          (void);

u32  PMCycles       (void);
u32  PML1FetchMisses(void);
u32  PML1MissCycles (void);
u32  PMInstructions (void);

#ifdef __cplusplus
}
#endif

#endif  // __PPCPM_H__
