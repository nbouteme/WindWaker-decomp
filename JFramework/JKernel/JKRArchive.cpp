#include "JKRArchive.h"
#include "JKRMemArchive.h"
#include "JKRDvdArchive.h"

JKRArchive *JKRArchive::mount(long param_1, EMountMode mountMode, JKRHeap *param_3, EMountDirection param_4) {
	JKRArchive *pJVar1;
	int iVar2;
	undefined4 align;
	JKRArchive *arc = 0;

	iVar2 = mountMode;
	pJVar1 = JKRArchive::check_mount_already(param_1);
	if (pJVar1 == nullptr) {
		align = 0xfffffffc;
		if (param_4 == 1) {
			align = 4;
		}
		if (iVar2 == 3) {
			pJVar1 = new (param_3, align) JKRDvdArchive(param_1, param_4);
		} else {
			pJVar1 = arc;
			if (iVar2 < 3) {
				if (iVar2 == 1) {
					pJVar1 = new (param_3, align) JKRMemArchive(param_1, param_4);
				} else if ((0 < iVar2)) {
					pJVar1 = new (param_3, align) JKRAramArchive(param_1, param_4);
				}
			} else if ((iVar2 < 5)) {
				pJVar1 = new (param_3, align) JKRCompArchive(param_1, param_4);
			}
		}
		if ((pJVar1) && (pJVar1->mMountMode == 0)) {
			if (pJVar1) { // call delete?
				pJVar1->~JKRArchive();
			}
			pJVar1 = nullptr;
		}
	}
	return pJVar1;
}