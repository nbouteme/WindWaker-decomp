#include <JFramework/JUtility/JUTAssert.h>
#include <machine/dolphin/printf.h>

#include "scene.h"

namespace f_op_scene_mng {
	int l_scnRqID;
	
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

	bool fopScnM_ChangeReq(scene_class *param_1, short procName, short fadeTime, ushort param_4) {
		int iVar1;
		int iVar2;

		iVar2 = f_op_scene_req::fopScnRq_Request(2, param_1, procName, (void *)0x0, fadeTime, param_4);
		iVar1 = iVar2;
		if (iVar2 == -1) {
			iVar1 = f_op_scene_mng::l_scnRqID;
		}
		f_op_scene_mng::l_scnRqID = iVar1;
		return iVar2 != -1;
	}

	int fopScnM_ReRequest(undefined4 param_1, void *param_2) {
		if (f_op_scene_mng::l_scnRqID == -1) {
			return 0;
		}
		return f_op_scene_req::fopScnRq_ReRequest(l_scnRqID, param_1, param_2);
	}
}