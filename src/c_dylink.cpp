#include "c_dylink.h"

#include <JFramework/JKernel/JKRDvdRipper.h>

#include <dlfcn.h>
#include <cstdio>
#include <cstdlib>

DynamicModuleControlBase *DynamicModuleControlBase::mFirst;
DynamicModuleControlBase *DynamicModuleControlBase::mLast;

void DynamicModuleControlBase::dump() {
}

char *DynamicModuleControlBase::getModuleName() { return nullptr; }
uint DynamicModuleControlBase::getModuleSize() { return 0; }
char *DynamicModuleControlBase::getModuleTypeString() { return "Base"; }
void DynamicModuleControlBase::dump2() {}
int DynamicModuleControlBase::do_load() { return 1; }

DynamicModuleControlBase::DynamicModuleControlBase() {
	this->mLinkCount = 0;
	this->field1_0x2 = 0;
	this->prev = nullptr;
	if (DynamicModuleControlBase::mFirst == nullptr) {
		DynamicModuleControlBase::mFirst = this;
	}
	this->next = DynamicModuleControlBase::mLast;
	if (this->next) {
		this->next->prev = this;
	}
	DynamicModuleControlBase::mLast = this;
}

undefined4 DynamicModuleControlBase::force_unlink() {
	if (this->mLinkCount != 0) {
		this->mLinkCount = 0;
		do_unlink();
	}
	return 1;
}

int DynamicModuleControlBase::load_async() {
	undefined4 uVar1;

	if (this->mLinkCount == 0) {
		return this->do_load_async();
	}
	return 1;
}

int DynamicModuleControlBase::do_load_async() {
	if (this->mLinkCount == 0) {
		return this->do_load_async();
	} else {
		return 1;
	}
}
int DynamicModuleControlBase::do_unload() { return 1; }
int DynamicModuleControlBase::do_link() { return 1; }
int DynamicModuleControlBase::do_unlink() { return 1; }

DynamicModuleControlBase::~DynamicModuleControlBase() {
	force_unlink();
	if (this->next) {
		this->next->prev = this->prev;
	}
	if (this->prev) {
		this->prev->next = this->next;
	}
	if (mFirst == this) {
		mFirst = this->prev;
	}
	if (mLast == this) {
		mLast = this->next;
	}
	this->prev = nullptr;
	this->next = nullptr;
}

int DynamicModuleControlBase::link() {
	os::OSThread *pOVar1;
	int iVar2;
	ulong uVar3;

	pOVar1 = os::OSGetCurrentThread();
	if (pOVar1 != &m_Do_main::mainThread) {
		m_Do_printf::OSReport_Error("DynamicModuleControlBase::link not mainthread %08x\n");
	}
	if (this->mLinkCount == 0) {
		do_load();
		iVar2 = do_link();
		if (iVar2 == 0) {
			return 0;
		}
		if (this->field1_0x2 != 0xffff) {
			this->field1_0x2 = this->field1_0x2 + 1;
		}
	}
	if (this->mLinkCount == 0xffff) {
		JUTAssertion::getSDevice()->showAssert("DynamicLink.cpp", 100, "mLinkCount < 65535");
		m_Do_printf::OSPanic("DynamicLink.cpp", 100, "Halt");
	}
	if (this->mLinkCount != 0xffff) {
		this->mLinkCount = this->mLinkCount + 1;
	}
	return 1;
}

int DynamicModuleControlBase::unlink() {
	os::OSThread *pOVar1;

	pOVar1 = os::OSGetCurrentThread();
	if (pOVar1 != &m_Do_main::mainThread) {
		m_Do_printf::OSReport_Error("DynamicModuleControlBase::unlink not mainthread %08x\n");
	}
	if (this->mLinkCount == 0) {
		m_Do_printf::OSReport_Warning("%08x DynamicModuleControlBase::unlink() mLinkCount id already zero.\n", this);
	} else {
		this->mLinkCount = this->mLinkCount - 1;
		if (this->mLinkCount == 0) {
			do_unlink();
			do_unload();
		}
	}
	return 1;
}

DynamicModuleControl::DynamicModuleControl(char *name) : DynamicModuleControlBase() {
	this->mModule = nullptr;
	this->mpModuleName = name;
	this->mModuleType = Invalid;
	this->mCheckSum = 0;
	this->mDecompSize = 0;
	this->bssPointer = 0;
	this->field3_0x18 = 0;
	this->field6_0x21 = 0;
	this->dvdcallback = 0;
}

char *DynamicModuleControl::getModuleName() { return mpModuleName; }
uint DynamicModuleControl::getModuleSize() {
	int iVar1;

	if (this->mModule == nullptr) {
		iVar1 = 0;
	} else {
		iVar1 = JKRHeap::getSize(this->mModule, nullptr);
		if ((void *)this->bssPointer) {
			JKRHeap::getSize((void *)this->bssPointer, nullptr);
		}
		iVar1 = iVar1 + this->mModule->mBssSize;
	}
	return iVar1;
}
char *DynamicModuleControl::getModuleTypeString() {
	return (char *[]){"????", "MEM", "ARAM", "DVD"}[mModuleType & 3];
}

void DynamicModuleControl::dump2() { /*dont care*/
}
// int DynamicModuleControl::do_load()

namespace DynamicLink {
	int calcSum2(ushort *data, ulong size) {
		int iVar1;

		iVar1 = 0;
		for (; size != 0; size = size - 2) {
			iVar1 = iVar1 + (uint)*data;
			data = data + 1;
		}
		return iVar1;
	}
}

int DynamicModuleControl::do_load() {
	bool bVar1;
	byte bVar2;
	undefined4 uVar3;
	DynamicModule *pDVar4;
	int decompSize;
	short sVar5;
	int iVar6;
	char acStack88[76];

	if (this->mModule)
		return 1;
	iVar6 = 0;
	do {
		while (true) {
			if (this->mModule) {
				JKRHeap::free(this->mModule, nullptr);
				this->mModule = nullptr;
			}
			snprintf(acStack88, 0x40, "%s.rel", this->mpModuleName);
			if ((this->mModule == nullptr) &&
				(DynamicModuleControl::sArchive)) {	 // MMEM
				this->mModule = (DynamicModule *)JKRArchive::getGlbResource(0x4d4d454d, acStack88, DynamicModuleControl::sArchive);
				if (this->mModule) {
					this->mModuleType = LoadToMainRAM;
				}
				if (this->mModule == nullptr) {	 // AMEM
					this->mModule = (DynamicModule *)JKRArchive::getGlbResource(0x414d454d, acStack88, DynamicModuleControl::sArchive);
					this->mModule = pDVar4;
					if (this->mModule) {
						this->mModuleType = LoadToARAM;
					}
				}
				if (this->mModule == nullptr) {	 // DMEM
					this->mModule = (DynamicModule *)JKRArchive::getGlbResource(0x444d454d, acStack88, DynamicModuleControl::sArchive);
					if (this->mModule) {
						this->mModuleType = LoadToDVDRAM;
					}
				}
			}
			bVar1 = this->mModule == nullptr;
			if (bVar1) {
				if (bVar1) {
					snprintf(acStack88, 0x40, "/rels/%s.rel", this->mpModuleName);
					this->mModule = (DynamicModule *)JKRDvdRipper::loadToMainRAM(acStack88, nullptr, 1, 0, m_Do_ext::archiveHeap, 1, 0, nullptr);
					if (this->mModule) {
						this->mDecompSize = 0;
						this->mModuleType = LoadFromDisk;
					}
				}
				if ((this->mModule == nullptr) && (DynamicModuleControl::sFileCache != 0)) {
					this->mModule = (DynamicModule *)sFileCache->getResource(0x72656c73, acStack88);
					if (this->mModule) {
						this->mDecompSize = 0;
						this->mModuleType = LoadFromCache;
						JKRFileLoader::detachResource(this->mModule, nullptr);
					}
				}
			} else {
				decompSize = sArchive->getExpandedResSize(this->mModule);
				this->mDecompSize = decompSize;
				JKRFileLoader::detachResource(this->mModule, nullptr);
			}
			if (this->mModule == nullptr) {
				m_Do_printf::OSReport_Error("DynamicModuleControl::do_load() リソース読み込み失敗 [%s]\n",
											this->mpModuleName);
				return 0;
			}
			if (this->mDecompSize < 1) {
				if (this->field6_0x21 != 0xff) {
					this->field6_0x21 = this->field6_0x21 + 1;
				}
				return 1;
			}
			sVar5 = DynamicLink::calcSum2((ushort *)this->mModule, this->mDecompSize);
			bVar2 = this->field6_0x21;
			if (bVar2 != 0)
				break;
			this->mCheckSum = sVar5;
			this->field6_0x21 = this->field6_0x21 + 1;
		}
		if (sVar5 == this->mCheckSum) {
			if (bVar2 == 0xff) {
				return 1;
			}
			this->field6_0x21 = bVar2 + 1;
			return 1;
		}
		m_Do_printf::OSReport_Error("DynamicModuleControl::do_load() チェックサムエラー %04x %04x[%s]\n", sVar5, this->mCheckSum, this->mpModuleName);
		this->field6_0x21 = 0;
		iVar6 = iVar6 + 1;
	} while (iVar6 < 3);
	uVar3 = 0;
	return uVar3;
}

void *DynamicModuleControl::callback(void *s) {
	((DynamicModuleControl *)s)->do_load();
	return 0;
}

int DynamicModuleControl::do_load_async() {
	mDoDvdThd_callback_c *pmVar1;
	undefined4 uVar2;

	if (this->dvdcallback == nullptr) {
		if (this->mModule) {
			return 1;
		}
		this->dvdcallback = (mDoDvdThd_callback_c *)
			mDoDvdThd_callback_c::create(DynamicModuleControl::callback, this);
		if (this->dvdcallback == nullptr) {
			m_Do_printf::OSReport_Error("DynamicModuleControl::do_load_async() 非同期読み込みコールバック登録失敗 [%s]\n", this->mpModuleName);
		}
	}
	pmVar1 = this->dvdcallback;
	if ((pmVar1 == nullptr) || (pmVar1->mStatus == 0)) {
		uVar2 = 0;
	} else {
		delete pmVar1;
		this->dvdcallback = nullptr;
		uVar2 = 1;
	}
	return uVar2;
}

int DynamicModuleControl::do_unload() {
	if (this->mModule) {
		JKRHeap::free(this->mModule, nullptr);
		this->mModule = nullptr;
	}
	return 1;
}

int DynamicModuleControl::do_link() {
	ulong uVar1;
	ulong uVar2;
	DynamicModule *rel;
	uint uVar3;
	void *iVar4;
	int iVar5;
	undefined4 uVar6;
	ulong uVar7;
	DynamicModule *rel_00;
	os::OSTime lVar8;

	lVar8 = os::OSGetTime();
	if (this->mModule == nullptr) {
		do_load();
	}
	if (this->mModule != nullptr) {
		if ((DynamicModule__SectionInfo *)0x7fffffff < this->mModule->mpSectionInfoOffset) {
			JUTAssertion::getSDevice()->showAssert("DynamicLink.cpp", 0x265, "mModule->info.sectionInfoOffset < 0x80000000");
			m_Do_printf::OSPanic("DynamicLink.cpp", 0x265, "Halt");
		}
		if (0x81ffffff < (uint)((int)&this->mModule->mModuleID + this->mModule->mFixSize)) {
			JUTAssertion::getSDevice()->showAssert("DynamicLink.cpp", 0x267, "(u32)mModule + mModule->fixSize < 0x82000000");
			m_Do_printf::OSPanic("DynamicLink.cpp", 0x267, "Halt");
		}
		os::OSGetTime();
		os::OSGetTime();
		rel = this->mModule;
		if (rel->mRELFormatVersion < 3) {
			JUTAssertion::getSDevice()->showAssert("DynamicLink.cpp", 0x2d4, "0");
			m_Do_printf::OSPanic("DynamicLink.cpp", 0x2d4, "Halt");
		LAB_80240eb0:
			lVar8 = os::OSGetTime();
			auto iVar4 = getModuleSize();
			DynamicModuleControl::sAllocBytes = DynamicModuleControl::sAllocBytes + iVar4;
			lVar8 = os::OSGetTime();
			this->field3_0x18 = ((int (*)(DynamicModule *))this->mModule->mpProlog)(this->mModule);
			os::OSGetTime();
			return 1;
		}
		uVar2 = rel->mFixSize;
		uVar1 = uVar2 + 0x1f & 0xffffffe0;
		iVar4 = (void *)(&rel->mModuleID + uVar1);
		uVar3 = JKRHeap::getSize(rel, nullptr);
		if ((int)uVar3 < 0) {
			iVar4 = JKRHeap::alloc(this->mModule->mBssSize, 0x20, nullptr);
			if (iVar4 == 0) {
				m_Do_printf::OSReport_Error("BSSメモリ確保失敗\n");
			} else {
				this->bssPointer = iVar4;
				auto iVar4 = os::OSLink((os::OSModuleInfo *)&this->mModule, this->bssPointer);
				if (iVar4 != 0)
					goto LAB_80240eb0;
				m_Do_printf::OSReport_Error("リンク失敗\n");
			}
		} else {
			rel_00 = this->mModule;
			uVar7 = uVar1 + rel_00->mBssSize;
			if (uVar7 < uVar3) {
				auto r = os::OSLinkFixed((os::OSModuleInfo *)rel_00, iVar4);
				if (r != 0) {
					r = JKRHeap::resize(this->mModule, uVar1 + this->mModule->mBssSize, nullptr);
					if (r < 0) {
						m_Do_printf::OSReport_Error("モジュールリサイズ(縮小)失敗\n");
					}
					goto LAB_80240eb0;
				}
				m_Do_printf::OSReport_Error("リンク失敗\n");
			} else {
				iVar5 = JKRHeap::resize(rel_00, uVar7, nullptr);
				if (iVar5 < 1) {
					iVar4 = JKRHeap::alloc(this->mModule->mBssSize, 0x20, nullptr);
					if (iVar4 == 0) {
						m_Do_printf::OSReport_Error("BSSメモリ確保失敗 [%x]\n", this->mModule->mBssSize);
					} else {
						auto iVar4 = os::OSLinkFixed((os::OSModuleInfo *)&this->mModule, this->bssPointer);
						if (iVar4 != 0) {
							iVar4 = JKRHeap::resize(this->mModule, uVar2, nullptr);
							if (iVar4 < 0) {
								m_Do_printf::OSReport_Error("モジュールリサイズ(縮小)失敗\n");
							}
							goto LAB_80240eb0;
						}
						m_Do_printf::OSReport_Error("リンク失敗\n");
					}
				} else {
					auto r = os::OSLinkFixed((os::OSModuleInfo *)&this->mModule, iVar4);
					if (r != 0)
						goto LAB_80240eb0;
					m_Do_printf::OSReport_Error("リンク失敗\n");
				}
			}
		}
	}
	this->field6_0x21 = 0;
	if ((void *)this->bssPointer != nullptr) {
		JKRHeap::free((void *)this->bssPointer, nullptr);
		this->bssPointer = 0;
	}
	if (this->mModule != nullptr) {
		JKRHeap::free(this->mModule, nullptr);
		this->mModule = nullptr;
	}
	return 0;
}

int DynamicModuleControl::do_unlink() {
	int iVar1;
	undefined4 uVar2;
	os::OSTime lVar3;

	lVar3 = os::OSGetTime();
	((void (*)(DynamicModule *))this->mModule->mpEpilog)(this->mModule);
	lVar3 = os::OSGetTime();
	iVar1 = os::OSUnlink(&((os::OSModuleHeader *)this->mModule)->info);
	lVar3 = os::OSGetTime();
	if (iVar1 == 0) {
		m_Do_printf::OSReport_Error("アンリンク失敗 mModule=%08x mBss=%08x\n", this->mModule, this->bssPointer);
		uVar2 = 0;
	} else {
		iVar1 = getModuleSize();
		DynamicModuleControl::sAllocBytes = DynamicModuleControl::sAllocBytes - iVar1;
		if (this->bssPointer) {
			JKRHeap::free(this->bssPointer, nullptr);
			this->bssPointer = 0;
		}
		do_unload();
		uVar2 = 1;
	}
	return uVar2;
}

JKRFileCache *DynamicModuleControl::sFileCache;
int DynamicModuleControl::sAllocBytes;

JKRArchive *DynamicModuleControl::sArchive;

JKRArchive *DynamicModuleControl::mountCallback(void *param_1) {
	JKRExpHeap *heap;

	heap = m_Do_ext::mDoExt_getArchiveHeap();
	sFileCache = JKRFileCache::mount("/rels", heap, nullptr);
	sArchive = (JKRArchive *)JKRArchive::mount("RELS.arc", 4, heap, 1);
	if (!sArchive) {
		m_Do_printf::OSReport_Error("マウント失敗ですが単にアーカイブを作ってないだけなら遅いだけです %s\n", "RELS.arc");
	}
	return sArchive;
}

int DynamicModuleControl::initialize(void) {
	sFileCache = 0;
	sAllocBytes = 0;
	sArchive = nullptr;
	mountCallback(nullptr);
	return 1;
}

namespace c_dylink {
	mDoDvdThd_callback_c *cDyl_DVD;
	byte DMC_initialized;
	DynamicNameTableEntry DynamicNameTable[430] = {
		{0x0016, "d_a_alldie"},
		{0x001c, "d_a_tag_evsw"},
		{0x001d, "d_a_obj_swpush"},
		{0x001e, "d_a_obj_swheavy"},
		{0x001f, "d_a_obj_swflat"},
		{0x0020, "d_a_obj_swlight"},
		{0x0021, "d_a_obj_swhammer"},
		{0x0022, "d_a_obj_quake"},
		{0x0023, "d_a_obj_drift"},
		{0x0024, "d_a_tag_volcano"},
		{0x0025, "d_a_tag_so"},
		{0x0026, "d_a_obj_pbco"},
		{0x0027, "d_a_seatag"},
		{0x0029, "d_a_obj_tide"},
		{0x002a, "d_a_hmlif"},
		{0x002b, "d_a_scene_change"},
		{0x002c, "d_a_obj_magmarock"},
		{0x002d, "d_a_obj_movebox"},
		{0x002e, "d_a_obj_tribox"},
		{0x002f, "d_a_obj_shelf"},
		{0x0030, "d_a_obj_hlift"},
		{0x0031, "d_a_obj_hami2"},
		{0x0032, "d_a_obj_hami3"},
		{0x0033, "d_a_obj_hami4"},
		{0x0034, "d_a_obj_hbrf1"},
		{0x0035, "d_a_obj_volcano"},
		{0x0036, "d_a_obj_vmc"},
		{0x0037, "d_a_obj_usovmc"},
		{0x0038, "d_a_obj_vfan"},
		{0x0039, "d_a_obj_iceisland"},
		{0x003a, "d_a_obj_dragonhead"},
		{0x003b, "d_a_obj_pirateship"},
		{0x003c, "d_a_obj_tousekiki"},
		{0x003d, "d_a_tag_ret"},
		{0x003e, "d_a_kaji"},
		{0x003f, "d_a_canon"},
		{0x0040, "d_a_mgameboard"},
		{0x0041, "d_a_obj_canon"},
		{0x0042, "d_a_obj_otble"},
		{0x0043, "d_a_obj_warpt"},
		{0x0045, "d_a_obj_toripost"},
		{0x0046, "d_a_obj_ikada"},
		{0x0047, "d_a_obj_majyuu_door"},
		{0x0048, "d_a_obj_pfall"},
		{0x0049, "d_a_obj_hole"},
		{0x004a, "d_a_obj_stair"},
		{0x004b, "d_a_obj_lpalm"},
		{0x004c, "d_a_obj_mtest"},
		{0x004d, "d_a_obj_mkie"},
		{0x004e, "d_a_obj_mkiek"},
		{0x004f, "d_a_obj_mknjd"},
		{0x0050, "d_a_obj_msdan"},
		{0x0051, "d_a_obj_msdan_sub"},
		{0x0052, "d_a_obj_msdan2"},
		{0x0053, "d_a_obj_msdan_sub2"},
		{0x0054, "d_a_obj_nest"},
		{0x0055, "d_a_obj_ojtree"},
		{0x0056, "d_a_obj_ospbox"},
		{0x0057, "d_a_obj_ladder"},
		{0x0058, "d_a_obj_smplbg"},
		{0x0059, "d_a_obj_akabe"},
		{0x005a, "d_a_obj_ashut"},
		{0x005b, "d_a_bridge"},
		{0x005c, "d_a_msw"},
		{0x005d, "d_a_mflft"},
		{0x005e, "d_a_klft"},
		{0x005f, "d_a_icelift"},
		{0x0060, "d_a_amiprop"},
		{0x0061, "d_a_pedestal"},
		{0x0062, "d_a_floor"},
		{0x0063, "d_a_kita"},
		{0x0064, "d_a_kokiie"},
		{0x0065, "d_a_shand"},
		{0x0066, "d_a_bita"},
		{0x0067, "d_a_sk"},
		{0x0068, "d_a_sk2"},
		{0x0069, "d_a_ssk"},
		{0x006a, "d_a_warpf"},
		{0x006b, "d_a_warpfout"},
		{0x006c, "d_a_warpls"},
		{0x006d, "d_a_warphr"},
		{0x006e, "d_a_warpdm20"},
		{0x006f, "d_a_warpgn"},
		{0x0070, "d_a_warpmj"},
		{0x0071, "d_a_obj_balancelift"},
		{0x0072, "d_a_shutter"},
		{0x0073, "d_a_shutter2"},
		{0x0074, "d_a_windmill"},
		{0x0075, "d_a_mbdoor"},
		{0x0076, "d_a_npc_de1"},
		{0x0077, "d_a_npc_nz"},
		{0x0078, "d_a_npc_so"},
		{0x0079, "d_a_fm"},
		{0x007a, "d_a_leaflift"},
		{0x007b, "d_a_obj_roten"},
		{0x007c, "d_a_toge"},
		{0x007d, "d_a_obj_ferris"},
		{0x007e, "d_a_obj_xfuta"},
		{0x007f, "d_a_obj_gaship"},
		{0x0080, "d_a_obj_rforce"},
		{0x0081, "d_a_obj_gaship2"},
		{0x0082, "d_a_obj_light"},
		{0x0083, "d_a_obj_homen"},
		{0x0084, "d_a_obj_homensmoke"},
		{0x0085, "d_a_obj_ftree"},
		{0x0086, "d_a_obj_Vds"},
		{0x0087, "d_a_obj_vyasi"},
		{0x0088, "d_a_obj_ajav"},
		{0x0089, "d_a_obj_trap"},
		{0x008a, "d_a_obj_hha"},
		{0x008b, "d_a_obj_htetu1"},
		{0x008c, "d_a_obj_gnndemotakis"},
		{0x008d, "d_a_obj_gnndemotakie"},
		{0x008e, "d_a_obj_gnnbtltaki"},
		{0x008f, "d_a_obj_rcloud"},
		{0x0090, "d_a_obj_gryw00"},
		{0x0091, "d_a_obj_AjavW"},
		{0x0092, "d_a_obj_leaves"},
		{0x0093, "d_a_obj_YLzou"},
		{0x0094, "d_a_obj_ganonbed"},
		{0x0095, "d_a_obj_Vteng"},
		{0x0096, "d_a_obj_hfuck1"},
		{0x0097, "d_a_obj_ohatch"},
		{0x0098, "d_a_obj_hcbh"},
		{0x0099, "d_a_obj_Ygush00"},
		{0x009a, "d_a_obj_bscurtain"},
		{0x009b, "d_a_obj_shmrgrd"},
		{0x009c, "d_a_obj_eayogn"},
		{0x009d, "d_a_obj_vmsms"},
		{0x009e, "d_a_obj_vmsdz"},
		{0x009f, "d_a_ygcwp"},
		{0x00a0, "d_a_obj_vgnfd"},
		{0x00a1, "d_a_obj_kanoke"},
		{0x00a2, "d_a_obj_eskban"},
		{0x00a3, "d_a_obj_ekskz"},
		{0x00a4, "d_a_obj_ebomzo"},
		{0x00a5, "d_a_obj_kanat"},
		{0x00a6, "d_a_obj_aygr"},
		{0x00a7, "d_a_ship"},
		{0x00a8, "d_a_obj_jump"},
		{0x00ab, "d_a_npc_mk"},
		{0x00ad, "d_a_sail"},
		{0x00ae, "d_a_pirate_flag"},
		{0x00af, "d_a_majuu_flag"},
		{0x00b0, "d_a_tori_flag"},
		{0x00b1, "d_a_sie_flag"},
		{0x00b2, "d_a_syan"},
		{0x00b3, "d_a_ghostship"},
		{0x00b4, "d_a_oship"},
		{0x00b5, "d_a_rectangle"},
		{0x00b6, "d_a_bb"},
		{0x00b7, "d_a_kanban"},
		{0x00b8, "d_a_hitobj"},
		{0x00b9, "d_a_kt"},
		{0x00ba, "d_a_ep"},
		{0x00bb, "d_a_lamp"},
		{0x00bc, "d_a_ff"},
		{0x00bd, "d_a_mo2"},
		{0x00be, "d_a_bk"},
		{0x00bf, "d_a_st"},
		{0x00c0, "d_a_tn"},
		{0x00c1, "d_a_mant"},
		{0x00c2, "d_a_kantera"},
		{0x00c3, "d_a_kamome"},
		{0x00c4, "d_a_npc_kamome"},
		{0x00c5, "d_a_wbird"},
		{0x00c6, "d_a_demo_kmm"},
		{0x00c7, "d_a_nz"},
		{0x00c8, "d_a_nzg"},
		{0x00c9, "d_a_kn"},
		{0x00ca, "d_a_demo_dk"},
		{0x00cb, "d_a_am"},
		{0x00cc, "d_a_am2"},
		{0x00cd, "d_a_gm"},
		{0x00ce, "d_a_ks"},
		{0x00cf, "d_a_cc"},
		{0x00d0, "d_a_bl"},
		{0x00d1, "d_a_wz"},
		{0x00d2, "d_a_ph"},
		{0x00d3, "d_a_pz"},
		{0x00d4, "d_a_bpw"},
		{0x00d5, "d_a_pw"},
		{0x00d6, "d_a_jbo"},
		{0x00d7, "d_a_bo"},
		{0x00d8, "d_a_ki"},
		{0x00d9, "d_a_mt"},
		{0x00da, "d_a_bwd"},
		{0x00db, "d_a_bwds"},
		{0x00dc, "d_a_bwdg"},
		{0x00dd, "d_a_kb"},
		{0x00df, "d_a_dr"},
		{0x00e0, "d_a_dr2"},
		{0x00e1, "d_a_rd"},
		{0x00e2, "d_a_daiocta"},
		{0x00e3, "d_a_daiocta_eye"},
		{0x00e4, "d_a_oq"},
		{0x00e5, "d_a_gy"},
		{0x00e6, "d_a_gy_ctrl"},
		{0x00e7, "d_a_gy_ctrl"},
		{0x00e8, "d_a_hot_floor"},
		{0x00e9, "d_a_beam"},
		{0x00ea, "d_a_obj_bemos"},
		{0x00eb, "d_a_btd"},
		{0x00ec, "d_a_bmd"},
		{0x00ed, "d_a_bmdhand"},
		{0x00ee, "d_a_bmdfoot"},
		{0x00ef, "d_a_dk"},
		{0x00f0, "d_a_bdk"},
		{0x00f1, "d_a_bdkobj"},
		{0x00f2, "d_a_bst"},
		{0x00f3, "d_a_fganon"},
		{0x00f4, "d_a_fgmahou"},
		{0x00f5, "d_a_bgn"},
		{0x00f6, "d_a_bgn2"},
		{0x00f7, "d_a_bgn3"},
		{0x00f8, "d_a_gnd"},
		{0x00f9, "d_a_pt"},
		{0x00fa, "d_a_swtdoor"},
		{0x00fb, "d_a_mozo"},
		{0x00fc, "d_a_kui"},
		{0x00fd, "d_a_ss"},
		{0x00fe, "d_a_sss"},
		{0x00ff, "d_a_sitem"},
		{0x0100, "d_a_machine"},
		{0x0102, "d_a_boss_item"},
		{0x0103, "d_a_demo_item"},
		{0x0104, "d_a_race_item"},
		{0x0105, "d_a_shop_item"},
		{0x0106, "d_a_deku_item"},
		{0x0108, "d_a_obj_paper"},
		{0x0109, "d_a_obj_demo_barrel"},
		{0x010a, "d_a_obj_dmgroom"},
		{0x010b, "d_a_obj_doguu"},
		{0x010c, "d_a_obj_wood"},
		{0x010d, "d_a_obj_flame"},
		{0x010e, "d_a_obj_buoyrace"},
		{0x010f, "d_a_obj_coming"},
		{0x0110, "d_a_coming2"},
		{0x0111, "d_a_coming3"},
		{0x0112, "d_a_obj_mmrr"},
		{0x0113, "d_a_obj_pbka"},
		{0x0114, "d_a_obj_plant"},
		{0x0115, "d_a_obj_gtaki"},
		{0x0116, "d_a_obj_Yboil"},
		{0x0117, "d_a_obj_rflw"},
		{0x0118, "d_a_obj_table"},
		{0x0119, "d_a_obj_tenmado"},
		{0x011a, "d_a_obj_cafelmp"},
		{0x011b, "d_a_obj_apzl"},
		{0x011c, "d_a_obj_adnno"},
		{0x011d, "d_a_obj_auzu"},
		{0x011e, "d_a_obj_gong"},
		{0x011f, "d_a_obj_barrier"},
		{0x0120, "d_a_obj_firewall"},
		{0x0121, "d_a_obj_tntrap"},
		{0x0122, "d_a_obj_monument"},
		{0x0123, "d_a_obj_tapestry"},
		{0x0124, "d_a_obj_hsehi1"},
		{0x0125, "d_a_goal_flag"},
		{0x0126, "d_a_tbox"},
		{0x0127, "d_a_sbox"},
		{0x012a, "d_a_bflower"},
		{0x012b, "d_a_acorn_leaf"},
		{0x012c, "d_a_swc00"},
		{0x012d, "d_a_fan"},
		{0x012e, "d_a_door10"},
		{0x012f, "d_a_door12"},
		{0x0130, "d_a_atdoor"},
		{0x0131, "d_a_mdoor"},
		{0x0132, "d_a_kddoor"},
		{0x0133, "d_a_knob00"},
		{0x0134, "d_a_mtoge"},
		{0x0135, "d_a_andsw0"},
		{0x0136, "d_a_andsw2"},
		{0x0137, "d_a_dai"},
		{0x0138, "d_a_swattack"},
		{0x0139, "d_a_switem"},
		{0x013a, "d_a_swtact"},
		{0x013c, "d_a_npc_os"},
		{0x013d, "d_a_npc_ym1"},
		{0x013e, "d_a_npc_ym1"},
		{0x013f, "d_a_npc_yw1"},
		{0x0140, "d_a_npc_ji1"},
		{0x0141, "d_a_npc_ko1"},
		{0x0142, "d_a_npc_ko1"},
		{0x0143, "d_a_npc_ls1"},
		{0x0144, "d_a_npc_p1"},
		{0x0145, "d_a_npc_p2"},
		{0x0146, "d_a_npc_sarace"},
		{0x0147, "d_a_npc_tc"},
		{0x0148, "d_a_npc_bm1"},
		{0x0149, "d_a_npc_bm1"},
		{0x014a, "d_a_npc_bm1"},
		{0x014b, "d_a_npc_bm1"},
		{0x014c, "d_a_npc_bm1"},
		{0x014d, "d_a_npc_ob1"},
		{0x014e, "d_a_npc_aj1"},
		{0x014f, "d_a_npc_km1"},
		{0x0150, "d_a_npc_cb1"},
		{0x0151, "d_a_npc_ba1"},
		{0x0152, "d_a_npc_bj1"},
		{0x0153, "d_a_npc_bj1"},
		{0x0154, "d_a_npc_bj1"},
		{0x0155, "d_a_npc_bj1"},
		{0x0156, "d_a_npc_bj1"},
		{0x0157, "d_a_npc_bj1"},
		{0x0158, "d_a_npc_bj1"},
		{0x0159, "d_a_npc_bj1"},
		{0x015a, "d_a_npc_bj1"},
		{0x015b, "d_a_npc_bs1"},
		{0x015c, "d_a_npc_bmcon1"},
		{0x015d, "d_a_npc_bms1"},
		{0x015e, "d_a_npc_bmsw"},
		{0x015f, "d_a_npc_btsw"},
		{0x0160, "d_a_npc_btsw2"},
		{0x0161, "d_a_npc_ds1"},
		{0x0162, "d_a_npc_rsh1"},
		{0x0163, "d_a_npc_kk1"},
		{0x0164, "d_a_npc_pm1"},
		{0x0165, "d_a_npc_kp1"},
		{0x0166, "d_a_npc_pf1"},
		{0x0167, "d_a_npc_gp1"},
		{0x0168, "d_a_npc_jb1"},
		{0x0169, "d_a_npc_kf1"},
		{0x016b, "d_a_npc_auction"},
		{0x016c, "d_a_npc_kg1"},
		{0x016d, "d_a_npc_kg2"},
		{0x016e, "d_a_npc_tt"},
		{0x016f, "d_a_npc_hr"},
		{0x0170, "d_a_npc_ho"},
		{0x0171, "d_a_npc_md"},
		{0x0172, "d_a_npc_uk"},
		{0x0173, "d_a_bigelf"},
		{0x0174, "d_a_npc_co1"},
		{0x0175, "d_a_npc_zk1"},
		{0x0176, "d_a_npc_roten"},
		{0x0177, "d_a_npc_people"},
		{0x0178, "d_a_npc_gk1"},
		{0x0179, "d_a_npc_photo"},
		{0x017a, "d_a_npc_ac1"},
		{0x017b, "d_a_npc_hi1"},
		{0x017c, "d_a_npc_sv"},
		{0x017d, "d_a_npc_mt"},
		{0x017e, "d_a_npc_mn"},
		{0x017f, "d_a_npc_ah"},
		{0x0180, "d_a_auction"},
		{0x0181, "d_a_kytag00"},
		{0x0182, "d_a_kytag01"},
		{0x0183, "d_a_kytag02"},
		{0x0184, "d_a_kytag03"},
		{0x0185, "d_a_kytag04"},
		{0x0186, "d_a_kytag05"},
		{0x0187, "d_a_kytag06"},
		{0x0188, "d_a_kytag07"},
		{0x0189, "d_a_wind_tag"},
		{0x018a, "d_a_yougan"},
		{0x018b, "d_a_mmusic"},
		{0x018c, "d_a_komore"},
		{0x018d, "d_a_tpota"},
		{0x018e, "d_a_obj_Itnak"},
		{0x018f, "d_a_obj_zouK"},
		{0x0190, "d_a_ykgr"},
		{0x0191, "d_a_saku"},
		{0x0194, "d_a_salvage"},
		{0x0195, "d_a_salvage_tbox"},
		{0x0196, "d_a_kmon"},
		{0x0197, "d_a_obj_figure"},
		{0x0198, "d_a_obj_hat"},
		{0x019a, "d_a_lwood"},
		{0x019b, "d_a_dummy"},
		{0x019c, "d_a_tag_event"},
		{0x019d, "d_a_tag_hint"},
		{0x019e, "d_a_tag_msg"},
		{0x019f, "d_a_tag_etc"},
		{0x01a0, "d_a_tag_island"},
		{0x01a1, "d_a_tag_kf1"},
		{0x01a2, "d_a_tag_kk1"},
		{0x01a3, "d_a_tag_photo"},
		{0x01a4, "d_a_tag_kb_item"},
		{0x01a5, "d_a_tag_mk"},
		{0x01a6, "d_a_tag_md_cb"},
		{0x01a7, "d_a_tag_ba1"},
		{0x01a8, "d_a_fallrock_tag"},
		{0x01a9, "d_a_fallrock"},
		{0x01aa, "d_a_steam_tag"},
		{0x01ab, "d_a_fire"},
		{0x01ac, "d_a_branch"},
		{0x01ad, "d_a_npc_zl1"},
		{0x01ae, "d_a_waterfall"},
		{0x01af, "d_a_lbridge"},
		{0x01b0, "d_a_lstair"},
		{0x01b1, "d_a_wall"},
		{0x01b2, "d_a_swpropeller"},
		{0x01b3, "d_a_ikari"},
		{0x01b6, "d_a_agbsw0"},
		{0x01b7, "d_a_magma"},
		{0x01b8, "d_a_grass"},
		{0x01bd, "d_a_obj_tower"},
		{0x01be, "d_a_obj_doguu_demo"},
		{0x01bf, "d_a_spotbox"},
		{0x01c0, "d_a_tornado"},
		{0x01c1, "d_a_title"},
		{0x01c2, "d_a_movie_player"},
		{0x01c3, "d_a_lod_bg"},
		{0x01c5, "d_a_himo3"},
		{0x01c6, "d_a_att"},
		{0x01c8, "d_a_hys"},
		{0x01c9, "d_a_swhit0"},
		{0x01ca, "d_a_tag_ghostship"},
		{0x01cb, "d_a_tsubo"},
		{0x01cc, "d_a_stone"},
		{0x01cd, "d_a_stone2"},
		{0x01ce, "d_a_obj_barrel"},
		{0x01cf, "d_a_obj_barrel2"},
		{0x01d0, "d_a_obj_try"},
		{0x01d1, "d_a_obj_vtil"},
		{0x01d2, "d_a_obj_ice"},
		{0x01d3, "d_a_obj_mshokki"},
		{0x01d5, "d_a_boko"},
		{0x01d6, "d_a_tama"},
		{0x01d7, "d_a_obj_buoyflag"},
		{0x01d8, "d_a_obj_correct"},
		{0x01d9, "d_a_obj_eff"},
		{0x01db, "d_a_tag_light"},
		{0x01dc, "d_a_tag_attention"},
		{0x01dd, "d_a_tag_waterlevel"},
		{0x01df, "d_a_arrow_iceeff"},
		{0x01e0, "d_a_arrow_lighteff"},
		{0x01e1, "d_a_obj_timer"},
		{-1, nullptr}};
	DynamicModuleControlBase *DMC[501];

	undefined4 cCc_Init(void) {
		ulong uVar1;
		JKRExpHeap *pParent;
		JKRSolidHeap *solidheap;
		JKRHeap *regheap;
		char *__s2;
		int iVar2;
		DynamicModuleControl *dmc;
		uint uVar3;
		int iVar4;
		int iVar5;
		DynamicNameTableEntry *puVar6;
		uint uVar7;

		if (DMC_initialized != '\0') {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x2a, "!DMC_initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x2a, "Halt");
		}
		pParent = m_Do_ext::mDoExt_getArchiveHeap();
		solidheap = JKRSolidHeap::create(0x5648, pParent, false);
		regheap = solidheap->becomeCurrentHeap();
		// FUN_800033a8((int)DMC, 0, 0x7d8);
		memset(DMC, 0, sizeof(DMC));
		uVar7 = 0;
		do {
			puVar6 = &DynamicNameTable[uVar7];
			if (puVar6->mRelFilename) {
				if (0x1f5 < puVar6->mPname) {
					JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x39, "d.mKey < (sizeof(DMC) / sizeof(DMC[0]))");
					m_Do_printf::OSPanic("c_dylink.cpp", 0x39, "Halt");
				}
				if (DMC[puVar6->mPname]) {
					JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x3a, "DMC[d.mKey] == 0");
					m_Do_printf::OSPanic("c_dylink.cpp", 0x3a, "Halt");
				}
				uVar3 = 0;
				iVar4 = 0;
				do {
					if (DMC[uVar3]) {
						iVar2 = strcmp(puVar6->mRelFilename, DMC[uVar3]->getModuleName());
						if (iVar2 == 0) {
							DMC[puVar6->mPname] = DMC[uVar3];
							break;
						}
					}
					uVar3 = uVar3 + 1;
					iVar4 = iVar4 + 4;
				} while (uVar3 < (sizeof(DMC) / sizeof(*DMC)));
				if (DMC[puVar6->mPname] == nullptr) {
#ifdef DOLPHIN
					dmc = new DynamicModuleControl(DynamicNameTable[uVar7].mRelFilename);
					DMC[puVar6->mPname] = dmc;
#else
					auto dmc = new LinuxDynamicModuleControl(DynamicNameTable[uVar7].mRelFilename);
					DMC[puVar6->mPname] = dmc;
#endif
				}
			}
			uVar7 = uVar7 + 1;
		} while (0x1ad < uVar7);
		// solidheap->adjustSize();
		regheap->becomeCurrentHeap();
		DMC_initialized = 1;
		return 1;
	}

	int cDyl_Initialized;

	void *cDyl_InitCallback(void *) {
		ulong uVar1;
		JKRExpHeap *heap;
		JKRFileLoader *fileloader;
		void *pvVar2;

		if (cDyl_Initialized != 0) {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x12f, "!cDyl_Initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x12f, "Halt");
		}
		heap = m_Do_ext::mDoExt_getArchiveHeap();
		fileloader = JKRFileCache::mount("/", heap, nullptr);
		DynamicModuleControl::initialize();
		pvVar2 = (void *)JKRFileLoader::getGlbResource("/dvd/framework.str");
		// JKRFileLoader::detachResource(pvVar2, fileloader);
		fileloader->detachResource(pvVar2);
		fileloader->unmount();
		os::OSSetStringTable(pvVar2);

// this links the module transiently and doesn't unlink it
#ifdef DOLPHIN
		DynamicModuleControl DStack56("f_pc_profile_lst");
#else
		LinuxDynamicModuleControl DStack56("f_pc_profile_lst");
#endif
		DStack56.link();
		cDyl_Initialized = 1;
		return (void *)1;
	}

	void cDyl_InitAsync(void) {
		ulong uVar1;

		cCc_Init();
		if (cDyl_DVD != 0) {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x145, "cDyl_DVD == 0");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x145, "Halt");
		}
		cDyl_DVD = mDoDvdThd_callback_c::create(cDyl_InitCallback, nullptr);
	}

	int cDyl_InitAsyncIsDone(void) {
		undefined4 uVar1;

		if (c_dylink::cDyl_DVD == (mDoDvdThd_callback_c *)0x0) {
			uVar1 = 1;
		} else if (cDyl_DVD->mStatus == 0) {
			uVar1 = 0;
		} else {
			if (cDyl_DVD) {
				/* class dtor */
				delete cDyl_DVD;
			}
			c_dylink::cDyl_DVD = 0;
			uVar1 = 1;
		}
		return uVar1;
	}

	int cDyl_Unlink(ushort param_1, char *param_2) {
		ulong uVar1;
		int iVar2;

		if (cDyl_Initialized == 0) {
			// uVar1 = JUTAssertion::getSDevice();
			// JUTAssertion::showAssert(uVar1, "c_dylink.cpp", 0xc5, "cDyl_Initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0xc5, "Halt");
		}
		if (0x1f5 < param_1) {
			// uVar1 = JUTAssertion::getSDevice();
			// JUTAssertion::showAssert(uVar1, "c_dylink.cpp", 0xc6, "i_ProfName < (sizeof(DMC) / sizeof(DMC[0]))");
			m_Do_printf::OSPanic("c_dylink.cpp", 0xc6, "Halt");
		}
		if (DMC[(short)param_1] == nullptr) {
			iVar2 = 0;
		} else {
			iVar2 = DMC[(short)param_1]->unlink();
		}
		return iVar2;
	}

	int cDyl_LinkASync(ushort param_1) {
		ulong uVar1;
		undefined4 uVar2;
		int iVar3;
		DynamicModuleControlBase *dmc;

		if (c_dylink::DMC_initialized == '\0') {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x101, "DMC_initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x101, "Halt");
		}
		if (c_dylink::cDyl_Initialized == 0) {
			uVar2 = 0;
		} else if (param_1 < 0x1f6) {
			if (param_1 >= 0x1f6) {
				JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x111, "i_ProfName < (sizeof(DMC) / sizeof(DMC[0]))");
				m_Do_printf::OSPanic("c_dylink.cpp", 0x111, "Halt");
			}
			dmc = c_dylink::DMC[(short)param_1];
			if (dmc == nullptr) {
				uVar2 = 4;
			} else {
				if (c_dylink::cDyl_Initialized == 0) {
					JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x115, "cDyl_Initialized");
					m_Do_printf::OSPanic("c_dylink.cpp", 0x115, "Halt");
				}
				iVar3 = dmc->load_async();
				if (iVar3 == 0) {
					uVar2 = 0;
				} else {
					iVar3 = dmc->link();
					if (iVar3 == 0) {
						m_Do_printf::OSReport_Error("cDyl_LinkASync: リンクに失敗しました。諦めます\n");
						uVar2 = 5;
					} else {
						uVar2 = 4;
					}
				}
			}
		} else {
			m_Do_printf::OSReport_Error("cDyl_Link i_ProfName=%d\n");
			uVar2 = 5;
		}
		return uVar2;
	}
}

char *LinuxDynamicModuleControl::getModuleName() {
	return mpModuleName;
}

uint LinuxDynamicModuleControl::getModuleSize() {
	return 0;
}

char *LinuxDynamicModuleControl::getModuleTypeString() {
	return "MEM";
}

void LinuxDynamicModuleControl::dump2() {
	abort();
}

#include <mcheck.h>

int LinuxDynamicModuleControl::do_load() {
	char *fn;
	asprintf(&fn, "./rels/%s/lib%s.so", mpModuleName, mpModuleName);
	mcheck_check_all();
	mModule = dlopen(fn, RTLD_NOW);
	if (!mModule) {
		perror("dlopen");
		abort();
	}
	free(fn);
}

int LinuxDynamicModuleControl::do_load_async() {
	return do_load();
}

int LinuxDynamicModuleControl::do_unload() {
	dlclose(mModule);
}

int LinuxDynamicModuleControl::do_link() {
	auto prolog = (int (*)(void *))dlsym(mModule, "prolog");
	return prolog(mModule);
}

int LinuxDynamicModuleControl::do_unlink() {
	auto epilog = (int (*)(void *))dlsym(mModule, "epilog");
	return epilog(mModule);
}

LinuxDynamicModuleControl::LinuxDynamicModuleControl(char *name) {
	this->mpModuleName = name;
}

LinuxDynamicModuleControl::~LinuxDynamicModuleControl() {}

DynamicModuleControl::~DynamicModuleControl() {}