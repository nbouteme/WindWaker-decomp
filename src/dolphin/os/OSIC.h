#pragma once
/*
    This header file defines the low level instruction cache operations.
    Most should be macros to the underlying assembly routines, but others
    will manipulate hardware setup registers.
 */

void ICSync(void);
void ICFlashInvalidate(void);
void ICEnable(void);
void ICDisable(void);
void ICFreeze(void);
void ICUnfreeze(void);
void ICBlockInvalidate(void* addr);
