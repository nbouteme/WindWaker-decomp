#pragma once
#include <ctypes.h>

#include <JPAFieldContainer.h>

//[Data] Expected size is 0x00001c
extern undefined1 JPASpinField;

//[Data] Expected size is 0x00001c
extern undefined1 JPADragField;

//[Data] Expected size is 0x00001c
extern undefined1 JPARandomField;

//[Data] Expected size is 0x00001c
extern undefined1 JPAConvectionField;

//[Data] Expected size is 0x00001c
extern undefined1 JPAVortexField;

//[Data] Expected size is 0x00001c
extern undefined1 JPANewtonField;

//[Data] Expected size is 0x00001c
extern undefined1 JPAMagnetField;

//[Data] Expected size is 0x00001c
extern undefined1 JPAAirField;

//[Data] Expected size is 0x00001c
extern undefined1 JPAGravityField;

//[Data] Expected size is 0x00001c
extern undefined1 JPABaseField;

//[BSS] Expected size is 0x000024
extern struct JPAFieldContainer JPAFieldManager;

namespace JPAFieldData {
//[BSS] Expected size is 0x000004
extern struct JPAEmitterInfo * pEmtrInfo;
}

namespace JPABase {
void __sinit_JPAField_cpp(void);
}
