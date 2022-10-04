#include <JFramework/JUtility/JUTAssert.h>

#include "overlap.h"

namespace f_op_overlap_mng {
	void fopOvlpM_Init() {}

	overlap_request_class *l_fopOvlpM_overlap;
	overlap_request_class l_fopOvlpM_Request;

	void fopOvlpM_ToldAboutID(uint param_1) {
		if (f_op_overlap_mng::l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			return;
		}
		f_op_overlap_mng::l_fopOvlpM_overlap->overlapactor->state = param_1;
		return;
	}

	int fopOvlpM_ClearOfReq(void) {
		int uVar1;

		if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			uVar1 = 0;
		} else {
			uVar1 = f_op_overlap_req::fopOvlpReq_OverlapClr(l_fopOvlpM_overlap);
		}
		return uVar1;
	}

	int fopOvlpM_IsDone(void) {
		int uVar1;

		if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			uVar1 = 0;
		} else {
			uVar1 = SComponent::cReq_Is_Done(l_fopOvlpM_overlap);
		}
		return uVar1;
	}

	int fopOvlpM_IsDoingReq(void) {
		if ((l_fopOvlpM_overlap != (overlap_request_class *)0x0) &&
			(l_fopOvlpM_overlap->mbIsDoingReq == 1)) {
			return 1;
		}
		return 0;
	}

	overlap_request_class *fopOvlpM_Request(short param_1, ushort param_2) {
		overlap_request_class *poVar1;

		if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			poVar1 = &l_fopOvlpM_Request;
			f_op_overlap_req::fopOvlpReq_Request(&l_fopOvlpM_Request, param_1, param_2);
			l_fopOvlpM_overlap = poVar1;
		} else {
			poVar1 = (overlap_request_class *)0x0;
		}
		return poVar1;
	}

	void fopOvlpM_Management(void) {
		int iVar1;

		if (((l_fopOvlpM_overlap != (overlap_request_class *)0x0) &&
			 (iVar1 = f_op_overlap_req::fopOvlpReq_Handler(l_fopOvlpM_overlap), iVar1 < 6)) &&
			(2 < iVar1)) {
			l_fopOvlpM_overlap = (overlap_request_class *)0x0;
		}
		return;
	}

	uint fopOvlpReq_Cancel(overlap_request_class *param_1) {
		uint uVar1;
		int iVar2;

		// TODO: check
		return f_op_overlap_req::fopOvlpReq_phase_Done(param_1) == 2;
	}

	undefined4 fopOvlpM_Cancel(void) {
		undefined4 uVar1;
		int iVar2;
		ulong uVar3;

		if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
			uVar1 = 1;
		} else {
			iVar2 = f_op_overlap_req::fopOvlpReq_Cancel(l_fopOvlpM_overlap);
			if (iVar2 == 1) {
				l_fopOvlpM_overlap = (overlap_request_class *)0x0;
				JUTAssertion::getSDevice()->setWarningMessage_f("f_op_overlap_mng.cpp", 0x14b, "%s", "fopOvlpM_Cancel SUCCESSED");
				uVar1 = 1;
			} else {
				uVar1 = 0;
			}
		}
		return uVar1;
	}

}