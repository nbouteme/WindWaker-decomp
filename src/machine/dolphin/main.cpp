#include "machine/dolphin/main.h"

#define _GNU_SOURCE /* See feature_test_macros(7) */
#include <JFramework/JFWSystem.h>
#include <JFramework/JKernel/JKRAram.h>
#include <JFramework/JKernel/JKRAramHeap.h>
#include <JFramework/JKernel/JKRExpHeap.h>
#include <JFramework/JUtility/JUTAssert.h>
#include <c_dylink.h>
#include <common/dComIfG_inf_c.h>
#include <d_resorce.h>
#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <doltypes.h>
#include <f_ap/game.h>
#include <fenv.h>
#include <machine/dolphin/ext.h>
#include <machine/dolphin/graphic.h>
#include <machine/dolphin/machine.h>
#include <machine/dolphin/printf.h>
#include <machine/dolphin/rst.h>

#include <cstring>

#include "dvd.h"
#include "mDoAud.h"
#include "m_Do_controller_pad.h"

void write_volatile_1(uint, ...) {
	puts("writing 1");
}

void write_volatile_2(uint, ...) {
	puts("writing 2");
}

void write_volatile_4(uint, ...) {
	puts("writing 4");
}

namespace mDoMain {
	unsigned long long sPowerOnTime = 0;
	int developmentMode = 0;
	char COPYDATE_STRING[] = "??/??/?? ??:??:??";
	int memMargin;
	os::OSTime sHungUpTime;
}

extern "C" void copy_bytes(byte *d, byte *s, uint n) {
	memcpy(d, s, n);
}

struct HeapCheck {
	char *name;
	JKRExpHeap *heap;
	int maxUsedSizeObserved;
	int minFreeSizeObserved;
	int unused[3];
	uint usedCount;
	uint totalUsedSize;

	int getUsedCount() {
		return m_Do_main::countUsed(this->heap);
	}

	void CheckHeap1() {
		int iVar1;
		int iVar2;

		iVar1 = this->heap->getTotalUsedSize();
		iVar2 = this->heap->getFreeSize();
		if (this->maxUsedSizeObserved < iVar1) {
			this->maxUsedSizeObserved = iVar1;
		}
		if (iVar2 < this->minFreeSizeObserved) {
			this->minFreeSizeObserved = iVar2;
		}
	}

	void heapDisplay() {
		int totalUsed;
		int totalFree;
		int freesize;

		totalUsed = this->heap->getTotalUsedSize();
		totalFree = this->heap->getTotalFreeSize();
		freesize = this->heap->getFreeSize();
		JUtility::JUTReport(100, 0xd4, "[%sName]", this->name);
		JUtility::JUTReport(100, 0xe3, "HeapSize         %8ld", this->heap->mSize);
		JUtility::JUTReport(100, 0xf0, "TargetHeapSize   %8ld");
		JUtility::JUTReport(100, 0xfd, "TotalFree        %8ld", totalFree);
		JUtility::JUTReport(100, 0x10a, "FreeSize         %8ld", freesize);
		JUtility::JUTReport(100, 0x117, "TotalUsedSize    %8ld", totalUsed);
		JUtility::JUTReport(100, 0x124, "TotalUsedRate        %3ld%%", (totalUsed * 100) / totalFree);
		JUtility::JUTReport(100, 0x131, "MaxTotalUsedSize %8ld", this->maxUsedSizeObserved);
		JUtility::JUTReport(100, 0x13e, "MaxTotalUsedRate     %3ld%%", (this->maxUsedSizeObserved * 100) / totalUsed);
		JUtility::JUTReport(100, 0x14b, "MinFreeSize      %8ld", this->minFreeSizeObserved);
		JUtility::JUTReport(100, 0x158, "MinFreeRate          %3ld%%", ((this->minFreeSizeObserved) * 100) / totalUsed);
		JUtility::JUTReport(100, 0x165, "UsedCount             %3ld%", m_Do_main::countUsed(this->heap));
	}
};

namespace m_Do_main {

	os::OSThread mainThread;

	int fillcheck_check_frame = 0;
	byte mCheckHeap;
	byte mHeapBriefType;

	void version_check() {
		int iVar1;

		iVar1 = strcmp("05Sep2002", "05Sep2002");
		if ((iVar1 == 0) && (iVar1 = strcmp("", ""), iVar1 == 0)) {
			return;
		}
		m_Do_printf::OSReport_Error("SDKのバージョンが一致しません。停止します\n");
		do {
			/* WARNING: Do nothing block with infinite loop */
		} while (true);
	}

	JKRExpHeap *sRootHeap;
	JKRExpHeap *sSystemHeap,
		*sZeldaHeap,
		*sGameHeap,
		*sArchiveHeap,
		*sCommandHeap;

	int mDisplayHeapSize;

	void *LOAD_COPYDATE(void *) {
		byte abStack96[32];
		dvd::DVDFileInfo auStack64;

		if (dvd::DVDOpen("/COPYDATE", &auStack64)) {
			dvd::DVDReadPrio(&auStack64, abStack96, 0x20, 0, 2);
			copy_bytes((byte *)mDoMain::COPYDATE_STRING, abStack96, 0x11);
			dvd::DVDClose(&auStack64);
		}
		return (void *)1;
	}

	int countUsed(JKRExpHeap *param_1) {
		JKRExpHeap::CMemBlock *pCVar1;
		int iVar2;

		os::OSDisableScheduler();
		iVar2 = 0;
		for (pCVar1 = param_1->head; pCVar1; pCVar1 = pCVar1->next) {
			iVar2 = iVar2 + 1;
		}
		os::OSEnableScheduler();
		return iVar2;
	}

	HeapCheck RootHeapCheck,
		SystemHeapCheck,
		ZeldaHeapCheck,
		GameHeapCheck,
		ArchiveHeapCheck,
		CommandHeapCheck;
	HeapCheck *HeapCheckTable[6] = {&RootHeapCheck, &SystemHeapCheck, &ZeldaHeapCheck, &GameHeapCheck, &ArchiveHeapCheck, &CommandHeapCheck};

	float console_position_x$4105;
	byte init$4106;
	float console_position_y$4108;
	byte init$4109;
	float console_scroll$4111;
	byte init$4112;

	void CheckHeap(JUTGamePad *param_1) {
		bool bVar1;
		undefined4 uVar2;
		uint pJVar3;
		int iVar4;
		HeapCheck *self;

		m_Do_machine::mDoMch_HeapCheckAll();
		os::OSCheckActiveThreads();
		bVar1 = false;
		if ((((param_1->mButton).mButtonDown & 0xffffffef) == 0x60) &&
			(((param_1->mButton).mButtonReleased & 0x10) != 0)) {
			bVar1 = true;
		}
		iVar4 = 0;
		do {
			m_Do_main::HeapCheckTable[iVar4]->CheckHeap1();
			if (bVar1) {
				self = m_Do_main::HeapCheckTable[iVar4];
				self->usedCount = self->getUsedCount();
				self->totalUsedSize = self->heap->getTotalUsedSize();
			}
			iVar4 = iVar4 + 1;
		} while (iVar4 < 6);
		return;
	}

	uint mSelectHeapBar;

	char *desc1$4076[] = {
		nullptr,
		"TotalFree",
		"MaxUsed  ",
		"Used     ",
		"RelUsed  "};

	char *desc2$4077[] = {
		nullptr,
		"/ MaxFree",
		"/HeapSize",
		"Blk/Bytes",
		"Blk/Bytes",
		nullptr};

	undefined4 Debug_console(JUTGamePad *param_1) {
		int iVar1;
		uint uVar2;
		uint uVar3;
		undefined4 uVar4;
		JKRAramHeap *aramheap;
		undefined4 uVar5;
		undefined8 in_f30;
		double dVar6;
		undefined8 in_f31;
		double dVar7;
		double local_38;
		undefined auStack24[16];
		undefined auStack8[8];
		JUTConsole *console;

		console = JFWSystem::systemConsole;
		uVar5 = 0;
		if (JFWSystem::systemConsole) {
			if (m_Do_main::init$4106 == 0) {
				m_Do_main::console_position_x$4105 = 20.0;
				m_Do_main::init$4106 = 1;
			}
			if (m_Do_main::init$4109 == 0) {
				m_Do_main::console_position_y$4108 = 30.0;
				m_Do_main::init$4109 = 1;
			}
			if (m_Do_main::init$4112 == 0) {
				m_Do_main::console_scroll$4111 = 0.0;
				m_Do_main::init$4112 = 1;
			}
			if ((((param_1->mButton).mButtonReleased & 0x10) != 0) &&
				(((param_1->mButton).mButtonDown & 0xffffffef) == 0)) {
				JFWSystem::systemConsole->candisplay = !JFWSystem::systemConsole->candisplay;
				JUTAssertion::setMessageCount(0);
			}
			if (console->candisplay != 0) {
				uVar2 = (param_1->mButton).mButtonDown;
				if ((((uVar2 & 0x40) == 0) || ((uVar2 & 0x20) == 0)) &&
					(((param_1->mButton).mTriggerLeftRaw == 0 || ((param_1->mButton).mTriggerRightRaw == 0)))) {
					if (((param_1->mButton).mButtonReleased & 4) != 0) {
						f_ap_game::g_HIO.forceprocessbar = f_ap_game::g_HIO.forceprocessbar ^ 1;  // 1 byte at offset 6
					}
					if (((param_1->mButton).mButtonReleased & 1) != 0) {
						aramheap = JKRAram::sAramObject->mpHeap;
						if (aramheap) {
							aramheap->dump();
						}
						DynamicModuleControlBase::dump();
						d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.dump();
					}
					if (((param_1->mButton).mButtonReleased & 2) != 0) {
						JKRHeap::sSystemHeap->dump_sort();
					}
					if (((param_1->mButton).mButtonReleased & 8) != 0) {
						m_Do_ext::zeldaHeap->dump_sort();
						m_Do_ext::gameHeap->dump_sort();
						m_Do_ext::archiveHeap->dump_sort();
					}
					JUtility::JUTReport(0x1e, 0x1b8, 1, "Press L+R trigger to control console.");
					JUtility::JUTReport(0x1e, 0x1c2, 1, "Press [Z] trigger to close this window.");
				} else {
					dVar7 = (double)(param_1->mStickMain).mPosX;
					dVar6 = (double)(param_1->mStickMain).mPosY;
					if ((((uVar2 & 0x400) != 0) && ((uVar2 & 0x800) != 0)) &&
						(((param_1->mButton).mButtonReleased & 0x1000) != 0)) {
						console->clear();
					}
					uVar3 = (param_1->mButton).mButtonDown;
					uVar2 = uVar3 & 0x400;
					if ((uVar2 == 0) && ((uVar3 & 0x800) == 0)) {
						dVar7 = (double)m_Do_main::console_scroll$4111;
						m_Do_main::console_scroll$4111 = (float)(dVar7 - dVar6);
						if (m_Do_main::console_scroll$4111 <= 1.0) {
							if (-1.0 <= m_Do_main::console_scroll$4111) {
								uVar2 = 0;
							} else {
								uVar2 = -(int)-m_Do_main::console_scroll$4111;
							}
						} else {
							uVar2 = (uint)(dVar7 - dVar6);
						}
						if (uVar2 != 0) {
							m_Do_main::console_scroll$4111 = m_Do_main::console_scroll$4111 - uVar2;
							console->scroll(uVar2);
						}
					} else {
						if (uVar2 != 0) {
							m_Do_main::console_position_x$4105 =
								(float)((double)m_Do_main::console_position_x$4105 + dVar7);
						}
						if (((param_1->mButton).mButtonDown & 0x800) != 0) {
							m_Do_main::console_position_y$4108 =
								(float)((double)m_Do_main::console_position_y$4108 - dVar6);
						}
					}
					if (((param_1->mButton).mButtonReleased & 0x100) != 0) {
						console->dumpToTerminal(0xffffffff);
						console->outputwhere = 3;
					}
					JUtility::JUTReport(0x1e, 0x186, 1, "Press X+Y+START to CLEAR console.");
					JUtility::JUTReport(0x1e, 400, 1, "3DStick UP/Down to scroll");
					JUtility::JUTReport(0x1e, 0x19a, 1, "Press A to output terminal from console.");
					uVar4 = console->getLineOffset();
					JUtility::JUTReport(0x1e, 0x1a4, 1, "SCROLL：%3d %3d %3d Output=%1x", uVar4,
										console->console_position_x, console->console_position_y,
										console->outputwhere);
				}
				iVar1 = (int)m_Do_main::console_position_y$4108;
				console->console_position_x = (int)m_Do_main::console_position_x$4105;
				console->console_position_y = iVar1;
				return 1;
			}
		}
		uVar4 = 0;
		return uVar4;
	}

	void debugDisplay(void) {
		uint uVar1;
		undefined4 uVar2;
		ulong uVar3;
		int iVar4;
		JKRAramHeap *aramheap;
		int iVar5;
		int iVar6;
		int unaff_r28;	// my guess is that these unaffs are from ghidra decompiler that can't prove they're not being used before assignment because of complex control flow? see below
		int unaff_r29;
		int iVar7;
		HeapCheck *heapcheck;

		uVar1 = (uint)m_Do_main::mSelectHeapBar;
		if ((uVar1 != 0) && (uVar1 < 7)) {
			HeapCheckTable[uVar1]->heapDisplay();
		}
		if (m_Do_main::mHeapBriefType == 5) {
			aramheap = JKRAram::sAramObject->mpHeap;
			if (aramheap) {
				JUtility::JUTReport(500, 100, "ARAM Free");
				JUtility::JUTReport(500, 0x72, "%d", aramheap->getFreeSize());
				JUtility::JUTReport(500, 0x80, "TotalFree");
				JUtility::JUTReport(500, 0x8e, "%d", aramheap->getTotalFreeSize());
			}
		} else if (m_Do_main::mHeapBriefType != 0) {
			if (5 < m_Do_main::mHeapBriefType) {
				JUTAssertion::getSDevice()->showAssert("m_Do_main.cpp", 0x213, "mHeapBriefType < HeapCheckTableNum");
				m_Do_printf::OSPanic("m_Do_main.cpp", 0x213, "Halt");
			}
			JUtility::JUTReport(500, 100, "%s", desc1$4076[mHeapBriefType]);
			JUtility::JUTReport(500, 0x72, "%s", desc2$4077[mHeapBriefType]);
			iVar7 = 0;
			iVar6 = 0;
			iVar5 = 0;
			do {
				heapcheck = HeapCheckTable[iVar5];
				if (m_Do_main::mHeapBriefType == 3) {
					unaff_r29 = heapcheck->getUsedCount();
					unaff_r28 = heapcheck->heap->getTotalUsedSize();
				} else if (m_Do_main::mHeapBriefType < 3) {
					if (m_Do_main::mHeapBriefType == 1) {
						unaff_r29 = heapcheck->heap->getTotalFreeSize();
						unaff_r28 = heapcheck->heap->getFreeSize();
					} else if (m_Do_main::mHeapBriefType != 0) {
						unaff_r29 = heapcheck->maxUsedSizeObserved;
						unaff_r28 = heapcheck->heap->mSize;
					}
				} else if (m_Do_main::mHeapBriefType < 5) {
					iVar4 = heapcheck->getUsedCount();
					unaff_r29 = iVar4 - heapcheck->usedCount;
					iVar4 = heapcheck->heap->getTotalUsedSize();
					unaff_r28 = iVar4 - (int)heapcheck->totalUsedSize;
				}
				// if mHeapBriefType is outside the ranges, these values end up unaffected
				JUtility::JUTReport(500, iVar6 + 0x96, " [%s]", heapcheck->name);
				JUtility::JUTReport(500, iVar6 + 0xa4, "%10d", unaff_r29);
				JUtility::JUTReport(500, iVar6 + 0xb2, "%10d", unaff_r28);
				iVar7 = iVar7 + 1;
				iVar6 = iVar6 + 0x2c;
				iVar5 = iVar5 + 4;
			} while (iVar7 < 6);
		}
	}

	void debug() {
		if (mDoMain::developmentMode) {
			if (m_Do_main::mCheckHeap) {
				m_Do_main::CheckHeap(m_Do_controller_pad::g_mDoCPd_gamePad[2]);
			}
			if ((((m_Do_controller_pad::g_mDoCPd_gamePad[2]->mButton).mButtonDown & 0xffffffef) == 0x20) &&
				(((m_Do_controller_pad::g_mDoCPd_gamePad[2]->mButton).mButtonReleased & 0x10) != 0)) {
				m_Do_main::mDisplayHeapSize = m_Do_main::mDisplayHeapSize ^ 1;
			}
			if (m_Do_main::mDisplayHeapSize != 0) {
				if ((((m_Do_controller_pad::g_mDoCPd_gamePad[2]->mButton).mButtonDown & 0xffffffef) == 0x40) && (((m_Do_controller_pad::g_mDoCPd_gamePad[2]->mButton).mButtonReleased & 0x10) != 0)) {
					if (m_Do_main::mHeapBriefType < 5) {
						m_Do_main::mHeapBriefType = m_Do_main::mHeapBriefType + 1;
					} else {
						m_Do_main::mHeapBriefType = 1;
					}
				}
				m_Do_main::debugDisplay();
			}
			m_Do_main::Debug_console(m_Do_controller_pad::g_mDoCPd_gamePad[2]);
		}
	}

	void *main01(void *ign) {
		static int frame = 0;
		JUTConsole *sysConsole;
		undefined4 uVar2;
		uint uVar3;

		m_Do_machine::mDoMch_Create();	// somewhat done
		m_Do_graphic::mDoGph_Create();	// somewhat done
		m_Do_controller_pad::mDoCPd_Create();  // somewhat done
		RootHeapCheck.heap = JKRHeap::sRootHeap;
		SystemHeapCheck.heap = JKRHeap::sSystemHeap;
		ZeldaHeapCheck.heap = m_Do_ext::mDoExt_getZeldaHeap();
		GameHeapCheck.heap = m_Do_ext::mDoExt_getGameHeap();
		ArchiveHeapCheck.heap = m_Do_ext::mDoExt_getArchiveHeap();
		CommandHeapCheck.heap = m_Do_ext::mDoExt_getCommandHeap();
		sysConsole = JFWSystem::systemConsole;
		JFWSystem::systemConsole->outputwhere = mDoMain::developmentMode ? 3 : 0;
		sysConsole->console_position_x = 0x20;
		sysConsole->console_position_y = 0x2a;
		mDoDvdThd_callback_c::create(m_Do_main::LOAD_COPYDATE, nullptr);
		f_ap_game::fapGm_Create();	// somewhat done
		m_Do_main::mDisplayHeapSize = 0;
		c_dylink::cDyl_InitAsync();	 //
		m_Do_audio::g_mDoAud_audioHeap = JKRSolidHeap::create(0x166800, JKRHeap::sCurrentHeap, false);	//
		do {

			frame++;
			uVar3 = (uint)m_Do_main::fillcheck_check_frame;	 //
			if ((uVar3 != 0) && (frame == (frame / uVar3) * uVar3)) {
				m_Do_machine::mDoMch_HeapCheckAll();  //
			}
			if (mDoDvdThd::SyncWidthSound) {
				// mDoMemCd_Ctrl_c::update(&m_Do_MemCard::g_mDoMemCd_control);	 //
			}
			m_Do_controller_pad::mDoCPd_Read();	 //
			m_Do_audio::mDoAud_Execute();		 //

			f_ap_game::fapGm_Execute();	 //
			m_Do_main::debug();			 //
		} while (true);
		return 0;
	}

	int main(int ac, int *av) {
		os::OSThread *uVar1;
		int iVar2;
		undefined4 uVar3;
		undefined auStack56[48];

		//feenableexcept(FE_DIVBYZERO | FE_INVALID);
		//fedisableexcept(FE_DIVBYZERO | FE_INEXACT | FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW);
		fedisableexcept(-1);

		uVar1 = os::OSGetCurrentThread();		  //
		mDoMain::sPowerOnTime = os::OSGetTime();  //
		m_Do_printf::OSReportInit();			  //
		m_Do_main::version_check();
		mDoRst::mResetData = (int *)os::OSAllocFromArenaLo(0x10, 4);  // called before OSInitAlloc?
		if (!mDoRst::mResetData) {
			do {
				/* WARNING: Do nothing block with infinite loop */
			} while (true);
		}
		iVar2 = os::OSGetResetCode();  //
		if (iVar2 == 0) {
			*mDoRst::mResetData = 0;
			mDoRst::mResetData[1] = 0;
			mDoRst::mResetData[1] = 0;
			mDoRst::mResetData[2] = 0;
			mDoRst::mResetData[3] = 0xffffffff;
		}
		d_com_inf_game::g_dComIfG_gameInfo.ct();
		if ((char)mDoMain::developmentMode < 0) {
			auto iVar2 = dvd::DVDGetCurrentDiskID();  //
			if (iVar2->gameVersion < 0x91) {
				if (iVar2->gameVersion < 0x81) {
					mDoMain::developmentMode = 0;
				} else {
					auto iVar2 = os::OSGetConsoleType();
					mDoMain::developmentMode = (byte)((uint)iVar2 >> 0x1c) & 1;
				}
			} else {
				mDoMain::developmentMode = 1;
			}
		}
		uVar3 = os::OSGetThreadPriority(uVar1);	 //
// on gamecube, this uses the real current stack as a stack for main01, but let's just use a separate one
#ifdef DOLPHIN
		os::OSCreateThread(&m_Do_main::mainThread, m_Do_main::main01, 0, auStack56, 0xf000, uVar3, 0);	//
#else
		void *stk = calloc(1, 0x40000);
		//printf("Initial stack allocated at %p\n", stk);
		os::OSCreateThread(&m_Do_main::mainThread, m_Do_main::main01, 0, (void *)((char *)stk + 0xf000), 0xf000, uVar3, 0);	 //
#endif
		os::OSResumeThread(&m_Do_main::mainThread);	 //
		os::OSSetThreadPriority(uVar1, 0x1f);		 //
		os::OSSuspendThread(uVar1);					 // stop self? //
	}
}