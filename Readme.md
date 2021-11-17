WindWaker Decomp
================

This is a decompiled US WindWaker SD.

The ISO was imported in Ghidra, with the `ghidra-gekko-broadway-lang` CPU definitions and the Ghidra-GameCube-Loader extension.

Output was generated from Ghidra's decompiler into a header and source file, then post-processed to a file hierarchy.

TODO
====

[ ] Get it to compile:
 - [ ] reorder includes to properly resolve referenced structures
 - [ ] add bss/data symbols declarations
   - [x] bss (but types are mostly wrong)
   - [ ] data
 - [ ] cleanup garbage in decompiled code
   - [ ] Some functions fail to decompile
 - [ ] rewrite hardware-dependant code
   - [ ] Or fork Dolphin's FIFO player...
 - [ ] export classes
Notes
=====

The `m` in the `mDo` prefixed files stands for `machine`, as in closely related to the hardware's inner working.
There is also the DolphinOS code that needs to be replaced.

Might be easier to get it to compile first targeting the gamecube?


