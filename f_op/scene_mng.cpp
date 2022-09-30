#include "scene.h"

namespace f_op_scene_mng {
	void fopScnM_Init() {}

	int fopScnM_CreateReq(short procname, short fadeTime, ushort param_3, void *param_4) {
		return f_op_scene_req::fopScnRq_Request(0, (scene_class *)0x0, procname, param_4, fadeTime, param_3);
	}

	void fopScnM_Management(void) {
		int iVar1;
		ulong uVar2;

		iVar1 = f_op_scene_req::fopScnRq_Handler();
		if (iVar1 == 0) {
			JUTAssertion::getSDevice()->showAssert("f_op_scene_mng.cpp", 0x146, "0");
			m_Do_printf::OSPanic("f_op_scene_mng.cpp", 0x146, "Halt");
		}
	}

}