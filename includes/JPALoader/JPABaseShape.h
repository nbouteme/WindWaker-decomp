#pragma once
#include <ctypes.h>

#include <JPABaseShapeArc__vtbl.h>

//[Data] Expected size is 0x000010
extern int JPABaseShape[4];

//[Data] Expected size is 0x000028
extern int JPABaseShape[10];

//[Data] Expected size is 0x000040
extern int JPABaseShape[16];

//[Data] Expected size is 0x000020
extern int JPABaseShape[8];

//[Data] Expected size is 0x000010
extern int JPABaseShape[4];

//[Data] Expected size is 0x000060
extern undefined1 JPABaseShapeArc;

//[Data] Expected size is 0x000020
extern undefined1 JPABaseShapeArc;

//[Data] Expected size is 0x0000fc
extern struct JPABaseShapeArc__vtbl JPABaseShapeArc;

//[Data] Expected size is 0x0000fc
extern undefined1 JPABaseShape;


namespace JPALoader {
int makeColorTable(int param_1,int param_2,int param_3,JKRHeap *param_4);
}
