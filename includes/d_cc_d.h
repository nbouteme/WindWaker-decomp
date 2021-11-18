#pragma once
#include <ctypes.h>

#include <dCcD_Stts__vtbl.h>


namespace dCcD_GObjInf {
//[Data] Expected size is 0x000028
extern pointer __vt;

}
//[Data] Expected size is 0x00000c
extern pointer dCcD_GObjCo;

//[Data] Expected size is 0x00000c
extern pointer dCcD_GObjTg;

//[Data] Expected size is 0x00000c
extern pointer dCcD_GObjAt;

//[Data] Expected size is 0x00000c
extern pointer dCcD_GAtTgCoCommonBase;

//[Data] Expected size is 0x000028
extern pointer cCcD_GObjInf;


namespace cCcD_Obj {
//[Data] Expected size is 0x00001c
extern pointer __vt;

}
//[Data] Expected size is 0x00000c
extern pointer cCcD_ObjCo;

//[Data] Expected size is 0x00000c
extern pointer cCcD_ObjTg;

//[Data] Expected size is 0x00000c
extern pointer cCcD_ObjAt;

//[Data] Expected size is 0x00000c
extern pointer cCcD_ObjCommonBase;

//[Data] Expected size is 0x00000c
extern pointer cCcD_ObjHitInf;

//[Data] Expected size is 0x00002c
extern struct dCcD_Stts__vtbl dCcD_Stts;

//[Data] Expected size is 0x00000c
extern pointer dCcD_GStts;

//[Data] Expected size is 0x00000c
extern pointer cCcD_GStts;


namespace d_cc_d {
dCcD_GObjInf * dCcD_GetGObjInf(cCcD_Obj *pObj);
}
