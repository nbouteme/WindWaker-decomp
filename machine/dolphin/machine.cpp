#include "machine.h"

#include <JFramework/JFWSystem.h>
#include <JFramework/JKernel/JKRAram.h>
#include <JFramework/JKernel/JKRDvdAramRipper.h>
#include <JFramework/JKernel/JKRDvdRipper.h>
#include <JFramework/JKernel/JKRHeap.h>
#include <JFramework/JKernel/JKRThread.h>
#include <JFramework/JKernel/JKRThreadSwitch.h>
#include <JFramework/JKernel/JMA/JMath.h>
#include <JFramework/JUtility/JUTAssert.h>
#include <JFramework/JUtility/JUTDbPrint.h>
#include <JFramework/JUtility/JUTException.h>
#include <JFramework/JUtility/JUTGamePad.h>
#include <SComponent/c_malloc.h>
#include <SComponent/c_math.h>
#include <dolphin/base.h>
#include <dolphin/os.h>
#include <doltypes.h>

#include "dvd.h"
#include "ext.h"
#include "mDoMemCd_Ctrl_c.h"
#include "main.h"
#include "printf.h"

gx::GXRenderModeObj *mDoMch_render_c::mRenderModeObj;

struct JKRExpHeap;

namespace mDoMch {
	char mDebugFill;
}

namespace m_Do_machine {

	int heapErrors, zeldaHeapErrors, gameHeapErrors, commandHeapErrors, archiveHeapErrors, solidHeapErrors, unknownHeapErrors;

	int key_link$4106;
	int key_ganon$4107;
	int key_zelda$4108;

	char tmpString$4003[5];

	void myHeapCheckRecursive(JKRHeap *param_1) {
		char cVar3;
		char *uVar1;
		JSUPtrLink *pJVar2;

		cVar3 = param_1->check();
		if (cVar3 == '\0') {
			uVar1 = m_Do_machine::myGetHeapTypeByString(param_1);
			m_Do_printf::OSReport_Error("error in %08x(%s)\n", param_1, uVar1);
		}
		pJVar2 = (param_1->mChildHeap).mpHead;
		if (pJVar2) {
			pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
		}
		while (pJVar2 != (JSUPtrLink *)0x0) {
			m_Do_machine::myHeapCheckRecursive((JKRHeap *)pJVar2->mpNext);
			pJVar2 = pJVar2[1].mpPrev;
			if (pJVar2) {
				pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
			}
		}
	}

	void mDoMch_HeapCheckAll() {
		m_Do_machine::myHeapCheckRecursive(JKRHeap::sRootHeap);
	}

	char *myGetHeapTypeByString(JKRHeap *param_1) {
		char *pcVar1;
		JKRHeap *pJVar2;
		int iVar3;
		undefined local_18;
		undefined uStack23;
		undefined uStack22;
		undefined uStack21;

		if (param_1 == (JKRHeap *)JKRHeap::sSystemHeap) {
			pcVar1 = "SystemHeap";
		} else {
			pJVar2 = (JKRHeap *)m_Do_ext::mDoExt_getZeldaHeap();
			if (param_1 == pJVar2) {
				pcVar1 = "ZeldaHeap";
			} else {
				pJVar2 = m_Do_ext::mDoExt_getGameHeap();
				if (param_1 == pJVar2) {
					pcVar1 = "GameHeap";
				} else {
					pJVar2 = (JKRHeap *)m_Do_ext::mDoExt_getArchiveHeap();
					if (param_1 == pJVar2) {
						pcVar1 = "ArchiveHeap";
					} else {
						pJVar2 = (JKRHeap *)m_Do_ext::mDoExt_getCommandHeap();
						if (param_1 == pJVar2) {
							pcVar1 = "CommandHeap";
						} else {
							iVar3 = param_1->getHeapType();
							if (iVar3 == 0x534c4944) {
								pcVar1 = "SLID";
							} else {
								if (iVar3 < 0x534c4944) {
									if (iVar3 == 0x41535448) {
										return "ASTH";
									}
									if (iVar3 < 0x41535448) {
										if (iVar3 == 0) {
											return "(Null)";
										}
									} else if (iVar3 == 0x45585048) {
										return "EXPH";
									}
								} else {
									if (iVar3 == 0x554e4954) {
										return "UNIT";
									}
									if ((iVar3 < 0x554e4954) && (iVar3 == 0x53544448)) {
										return "STDH";
									}
								}
								tmpString$4003[0] = (undefined)((uint)iVar3 >> 0x18);
								tmpString$4003[1] = (undefined)((uint)iVar3 >> 0x10);
								tmpString$4003[2] = (undefined)((uint)iVar3 >> 8);
								tmpString$4003[3] = (undefined)iVar3;
								tmpString$4003[4] = 0;
								pcVar1 = m_Do_machine::tmpString$4003;
							}
						}
					}
				}
			}
		}
		return pcVar1;
	}

	int developKeyCheck(int param_1, int param_2) {
		if ((param_2 == 0x74) && (param_1 == 4)) {
			if ((key_link$4106 == 3) &&
				((key_ganon$4107 == 6 && (key_zelda$4108 == 5)))) {
				mDoMain::developmentMode = '\x01';
			} else {
				key_link$4106 = 0;
				key_ganon$4107 = 0;
				key_zelda$4108 = 0;
			}
		}
		if ((param_2 == 0x42) && (param_1 == 0x40)) {
			key_link$4106 = key_link$4106 + 1;
		}
		if ((param_2 == 0x28) && (param_1 == 0x20)) {
			key_ganon$4107 = key_ganon$4107 + 1;
		}
		if ((param_2 == 0x11) && (param_1 == 0x10)) {
			key_zelda$4108 = key_zelda$4108 + 1;
		}
		return (int)mDoMain::developmentMode;
	}

	void myExceptionCallback(void) {
		ulong local_b8;
		ulong local_b4;
		JUTException *self;

		mDoMain::sHungUpTime = os::OSGetTime();
		m_Do_printf::OSReportEnable();
		JUTGamePad::clearForReset();
		m_Do_printf::OSReport("振動停止＆原点復帰\n");
		self = JUTException::sErrorManager;
		if (!JUTException::sErrorManager) {
			m_Do_printf::OSReport("例外マネージャがありません\n");
			base::PPCHalt();
		}
		if (mDoMain::developmentMode == '\0') {
			JUTGamePad JStack176(0);
			self->padidx = &JStack176;
			self->padidx2 = -1;
			if (!self) {
				base::PPCHalt();
			} else {
				os::OSEnableInterrupts();
				m_Do_printf::OSReport("キー入力を受け付けています\n");
				while (mDoMain::developmentMode == '\0') {
					// TODO
					//JUTException::readPad(self, &local_b8, &local_b4);
					m_Do_machine::developKeyCheck(local_b8, local_b4);
					JUTException::waitTime(0x1e);
					if (JUTGamePad::C3ButtonReset::sResetOccurred != '\0') {
						m_Do_printf::OSReport("リセット受け付けています\n");
						os::OSResetSystem(1, 0, 0);
					}
				}
				m_Do_printf::OSReport("JUTAssertionを可視化しました\n");
				JUTAssertion::setVisible(true);
				JUTDbPrint::sDebugPrint->uk = 1;
				JFWSystem::systemConsole->outputwhere = 3;
			}
		} else {
			m_Do_printf::OSReport("3秒間停止\n");
			JUTException::waitTime(3000);
		}
		mDoMain::sHungUpTime >>= 32;
		return;
	}

	void myMemoryErrorRoutine(JKRHeap *param_1, undefined4 param_2, undefined4 param_3) {
		int iVar1;
		uint uVar2;
		char *uVar3;
		undefined4 uVar4;
		undefined4 uVar5;
		undefined local_20;
		undefined uStack31;
		undefined uStack30;

		iVar1 = param_1->getHeapType();
		if (iVar1 != 0x534c4944) {
			m_Do_printf::OSReport_Error("Error: Cannot allocate memory %d(0x%x)byte in %d byte alignment from %08x\n", param_2, param_2, param_3, param_1);
		}
		uVar2 = param_1->getHeapType();
		if (iVar1 != 0x534c4944) {
			iVar1 = param_1->mSize;
			uVar3 = m_Do_machine::myGetHeapTypeByString(param_1);
			uVar4 = param_1->getTotalFreeSize();
			uVar5 = param_1->getFreeSize();
			local_20 = (undefined)(uVar2 >> 0x18);
			uStack31 = (undefined)(uVar2 >> 0x10);
			uStack30 = (undefined)(uVar2 >> 8);
			m_Do_printf::OSReport_Error("FreeSize=%08x TotalFreeSize=%08x HeapType=%08x(%c%c%c%c) HeapSize=%08x %s\n", uVar5,
										uVar4, uVar2, local_20, uStack31, uStack30, uVar2 & 0xff, iVar1, uVar3);
		}
		if (m_Do_machine::heapErrors == 0) {
			param_1->dump_sort();
		}
		m_Do_machine::heapErrors = m_Do_machine::heapErrors + 1;
		if (param_1 == m_Do_ext::zeldaHeap) {
			m_Do_machine::zeldaHeapErrors = m_Do_machine::zeldaHeapErrors + 1;
		} else if (param_1 == m_Do_ext::gameHeap) {
			m_Do_machine::gameHeapErrors = m_Do_machine::gameHeapErrors + 1;
		} else if (param_1 == m_Do_ext::commandHeap) {
			m_Do_machine::commandHeapErrors = m_Do_machine::commandHeapErrors + 1;
		} else if (param_1 == m_Do_ext::archiveHeap) {
			m_Do_machine::archiveHeapErrors = m_Do_machine::archiveHeapErrors + 1;
		} else {
			iVar1 = param_1->getHeapType();
			if (iVar1 == 0x534c4944) {
				m_Do_machine::solidHeapErrors = m_Do_machine::solidHeapErrors + 1;
			} else {
				m_Do_machine::unknownHeapErrors = m_Do_machine::unknownHeapErrors + 1;
			}
		}
	}

	int mDoMch_Create() {
		undefined *puVar1;
		JUTConsole *pJVar2;
		void *uVar3;
		ulong uVar4;
		void *uVar5;
		void *iVar6;
		void *iVar7;
		JFWSystem *self;
		JKRHeap *pJVar8;
		JKRThread *this_00;
		os::OSThread *pOVar9;
		char *in_r6;
		int iVar10;

		if ((mDoMain::developmentMode == '\0') ||
			(iVar10 = os::OSGetConsoleType(), (iVar10 & 0x10000000) == 0)) {
			m_Do_printf::OSReportDisable();
		}
		JKRHeap::sDefaultFillFlag = '\x01' - (mDoMch::mDebugFill == '\0');
		if (JFWSystem::sInitCalled != 0) {
			auto uVar4 = JUTAssertion::getSDevice();
			in_r6 = "sInitCalled == 0";
			uVar4->showAssert("JFWSystem.h", 0x2f, "sInitCalled == 0");
			m_Do_printf::OSPanic("JFWSystem.h", 0x2f, "Halt");
		}
		JFWSystem::CSetUpParam::maxStdHeaps = 1;
		uVar3 = os::OSGetArenaHi();
		uVar5 = os::OSGetArenaLo();
		if (((void *)0x81800000 < uVar3) && (uVar5 < uVar3 + 0xfe800000)) {
			os::OSSetArenaHi(uVar3 + 0xfe800000);
		}
		iVar6 = os::OSGetArenaHi();
		iVar7 = os::OSGetArenaLo();
		iVar10 = ((char *)iVar6 - (char *)iVar7) + -0xf0;
		uVar3 = (char *)os::OSGetConsoleSimulatedMemSize();
		if ((char *)0x2ffffff < uVar3) {
			iVar10 = ((char *)iVar6 - (char *)iVar7) + -0x10000f0;
		}
		if (mDoMain::memMargin != -1) {
			iVar10 = iVar10 + mDoMain::memMargin;
		}
		if (JFWSystem::sInitCalled != 0) {
			auto uVar4 = JUTAssertion::getSDevice();
			uVar4->showAssert("JFWSystem.h", 0x32, "sInitCalled == 0");
			m_Do_printf::OSPanic("JFWSystem.h", 0x32, "Halt");
		}
		JFWSystem::CSetUpParam::sysHeapSize = iVar10 + -0xd20c00;
		if (JFWSystem::sInitCalled != 0) {
			auto uVar4 = JUTAssertion::getSDevice();
			uVar4->showAssert("JFWSystem.h", 0x35, "sInitCalled == 0");
			m_Do_printf::OSPanic("JFWSystem.h", 0x35, "Halt");
		}
		JFWSystem::CSetUpParam::fifoBufSize = 0xa0000;
		if (JFWSystem::sInitCalled != 0) {
			auto uVar4 = JUTAssertion::getSDevice();
			uVar4->showAssert("JFWSystem.h", 0x3a, "sInitCalled == 0");
			m_Do_printf::OSPanic("JFWSystem.h", 0x3a, "Halt");
		}
		JFWSystem::CSetUpParam::aramAudioBufSize = 0xa00000;
		if (JFWSystem::sInitCalled != 0) {
			auto uVar4 = JUTAssertion::getSDevice();
			uVar4->showAssert("JFWSystem.h", 0x3d, "sInitCalled == 0");
			m_Do_printf::OSPanic("JFWSystem.h", 0x3d, "Halt");
		}
		JFWSystem::CSetUpParam::aramGraphBufSize = 0x5ce000;
		if (JFWSystem::sInitCalled != 0) {
			auto uVar4 = JUTAssertion::getSDevice();
			uVar4->showAssert("JFWSystem.h", 0x50, "sInitCalled == 0");
			m_Do_printf::OSPanic("JFWSystem.h", 0x50, "Halt");
		}
		JFWSystem::CSetUpParam::renderMode = mDoMch_render_c::mRenderModeObj;
		JFWSystem::init();
		if (mDoMain::developmentMode == '\0') {
			JUTAssertion::setVisible(false);
			JUTDbPrint::sDebugPrint->uk = 0;
		}
		JKRHeap::setErrorHandler(m_Do_machine::myMemoryErrorRoutine);
		JKRHeap::sRootHeap->setErrorFlag(true);
		JFWSystem::systemHeap->setErrorFlag(true);
		pJVar8 = JKRHeap::sRootHeap;
		m_Do_ext::mDoExt_createCommandHeap(0x1000, JKRHeap::sRootHeap);
		m_Do_ext::mDoExt_createArchiveHeap(0xa51400, pJVar8);
		m_Do_ext::mDoExt_createGameHeap(0x2ce800, pJVar8);
		pJVar8 = JKRHeap::sSystemHeap;
		auto niVar6 = JKRHeap::sSystemHeap->getFreeSize();
		if (((int)niVar6) - 0x10000U < 1) {
			auto uVar4 = JUTAssertion::getSDevice();
			uVar4->showAssert("m_Do_machine.cpp", 0x450, "size > 0");
			m_Do_printf::OSPanic("m_Do_machine.cpp", 0x450, "Halt");
		}
		pJVar8 = m_Do_ext::mDoExt_createZeldaHeap(niVar6 - 0x10000U, pJVar8);
		pJVar8->becomeCurrentHeap();
		JKRAramStream::setTransBuffer(nullptr, 0x2000, JKRHeap::sSystemHeap);
		JKRAram::sSzpBufferSize = 0x2000;
		JKRDvdAramRipper::sSzpBufferSize = 0x2000;
		JKRDvdRipper::sSzpBufferSize = 0x2000;
		JKRThreadSwitch::createManager(nullptr);
		this_00 = new JKRThread(os::OSGetCurrentThread(), 0);
		//pJVar2 = JFWSystem::systemConsole;
		JFWSystem::systemConsole->outputwhere = 3;
		JFWSystem::systemConsole->console_position_x = 0x10;
		JFWSystem::systemConsole->console_position_y = 0x2a;
		JUTException::appendMapFile("/maps/framework.map");
		JUTException::setPreUserCallback(m_Do_machine::myExceptionCallback);
		// TODO
		//JUTException::setPostUserCallback(m_Do_machine::fault_callback_scroll);
		JKernel::JMath::JMANewSinTable(0xc);
		pJVar8 = m_Do_ext::mDoExt_getZeldaHeap();
		cMl::init(pJVar8);
		SComponent::cM_initRnd(100, 100, 100);
		pOVar9 = os::OSGetCurrentThread();
		auto nniVar6 = os::OSGetThreadPriority(pOVar9);
		mDoDvdThd::create(nniVar6 + -2);
		m_Do_DVDError::mDoDvdErr_ThdInit();
		m_Do_MemCard::g_mDoMemCd_control.ThdInit();
		return 1;
	}
}