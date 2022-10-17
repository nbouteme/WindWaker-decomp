#include "mDoAud.h"

#include <JFramework/JKernel/JKRArchive.h>
#include <JFramework/JKernel/JKRExpHeap.h>
#include <JFramework/JKernel/JKRMemArchive.h>
#include <common/dComIfG_inf_c.h>

#include "dvd.h"

namespace JASystem {
	namespace Kernel {
		struct TSolidHeap {
			void *beginning;
			void *free_area_ptr;
			uint free_size;
			uint alloccount;
			void *lastallocated;

			TSolidHeap() {
				this->beginning = 0;
				this->free_area_ptr = 0;
				this->free_size = 0;
				this->alloccount = 0;
				this->lastallocated = 0;
			}

			void *alloc(long size) {
				void *iVar1;
				char *nextfree;

				if (this->beginning == 0) {
					m_Do_printf::OSReport("[Nas_HeapAlloc] ヒープが取得できません（ヒープ取得元存在せず）。\n");
					iVar1 = 0;
				} else {
					iVar1 = this->free_area_ptr;
					nextfree = (char *)(iVar1) + (size + 0x1fU & 0xffffffe0);
					if (((char *)this->beginning + this->free_size) < nextfree) {
						m_Do_printf::OSReport("[Nas_HeapAlloc] ヒープが取得できません（ヒープの取得元の残りサイズ不足）。\n");
						iVar1 = 0;
					} else {
						this->free_area_ptr = nextfree;
						this->alloccount = this->alloccount + 1;
						this->lastallocated = iVar1;
					}
				}
				return iVar1;
			}

			void freeAll() {
				this->free_area_ptr = this->beginning;
				this->alloccount = 0;
				this->lastallocated = 0;
			}

			void init(uchar *baseptr, long size) {
				this->alloccount = 0;
				if (baseptr == (uchar *)0x0) {
					m_Do_printf::OSReport("[Nas_HeapInit] アドレス０からヒープを初期化しようとしています。\n");
					this->free_size = 0;
					this->free_area_ptr = 0;
					this->lastallocated = 0;
				} else {
					this->beginning = (void *)(((u64)baseptr + 0x1f) & 0xffffffffffffffe0);
					this->free_area_ptr = this->beginning;
					this->free_size = size - ((byte *)this->beginning - baseptr);
					this->lastallocated = 0;
				}
			}

			int getRemain() {
				return this->free_size - ((byte *)this->free_area_ptr - (byte *)this->beginning);
			}
		};
	}
}

namespace mDoAud_zelAudio_c {
	byte mInitFlag;
	byte mLoadTimer;

	static void calcLoadTimer(void) {
		if (1 < mLoadTimer) {
			m_Do_audio::cLib_calcTimer(&mLoadTimer);
		}
	}
}

namespace JAIZelParam {
	uint DRAM_HEAP_SIZE;
	uint SE_REGIST_MAX = 0x20;
	uint SOUND_SCENE_MAX = 2;
	uint SEQ_CONTROL_BUF_MAX = 4;
	uint STREAM_CONTROL_BUF_MAX = 2;
	uint STREAM_DECODED_BUFFERS = 10;
	uint AUTO_HEAP_MAX = 3;
	uint STAY_HEAP_MAX = 1;
	uint AUTO_HEAP_ROOM_SIZE = 0xab00;
	uint STAY_HEAP_ROOM_SIZE = 0x1d000;
	uint PLAY_TRACK_MAX = 3;
	uint SYSTEM_TRACK_MAX = 200;
	float DISTANCE_MAX = 1667.0f;
	float MAX_VOLUME_DISTANCE = 333.0f;
	float MIN_DISTANCE_VOLUME;
	byte DOLBY_CENTER_VALUE = 0x1e;
	float DOLBY_FLONT_DISTANCE_MAX = -100;
	float DOLBY_BEHIND_DISTANCE_MAX = 500;
	ushort DISTANCE_FX_PARAM = 10;
	byte VOL_SE_SYSTEM_DEFAULT = 0x70;
	byte VOL_SE_LINK_VOICE_DEFAULT = 0x7f;
	byte VOL_SE_LINK_MOTION_DEFAULT = 0x70;
	byte VOL_SE_LINK_FOOTNOTE_DEFAULT = 0x68;
	byte VOL_SE_CHAR_VOICE_DEFAULT = 0x70;
	byte VOL_SE_CHAR_MOVE_DEFAULT = 0x70;
	byte VOL_SE_OBJECT_DEFAULT = 0x68;
	byte VOL_SE_ATMOSPHERE_DEFAULT = 0x68;
	char *INIT_DATA_FILE_NAME = "Audiores/JaiInit.aaf";
	char *WAVE_PATH = "Audiores/Banks/";
	char *SEQ_PATH = "Audiores/Seqs/";
	char *STREAM_PATH = "Audiores/Stream/";
	char *SEQ_ARCH_FILE_NAME = "JaiSeqs.arc";
	uint DUMMY_POSITION_MAX = 30;
	uint DUMMY_POSITION_LIFE_TIME = 300;
}

namespace m_Do_audio {
	JKRSolidHeap *g_mDoAud_audioHeap;

	mDoDvdThd_toMainRam_c *l_affCommand;
	mDoDvdThd_mountArchive_c *l_arcCommand;
	JAIZelBasic g_mDoAud_zelAudio;
	void *mDoAud_StreamBufferPointer;
	int mDoAud_StreamBufferBlocks;
	JKRHeap *mDoAud_audioStreamHeap;

	void mDoAud_allocStreamBuffer(void) {
		ulong size;
		ulong uVar2;
		char cVar3;

		if (mDoAud_StreamBufferPointer != (void *)0x0) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_audio.cpp", 0x62, "mDoAud_StreamBufferPointer == 0");
			m_Do_printf::OSPanic("m_Do_audio.cpp", 0x62, "Halt");
		}
		auto uVar1 = (ulong)mDoAud_StreamBufferBlocks;
		while (true) {
			JAIGlobalParameter::setParamStreamDecodedBufferBlocks(uVar1);
			size = JAInter::StreamLib::getNeedBufferSize();
			if (mDoAud_audioStreamHeap != (JKRExpHeap *)0x0) {
				auto uVar2 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar2, "m_Do_audio.cpp", 0x7c, "mDoAud_audioStreamHeap == 0");
				m_Do_printf::OSPanic("m_Do_audio.cpp", 0x7c, "Halt");
			}
			mDoAud_audioStreamHeap = m_Do_ext::archiveHeap;
			mDoAud_StreamBufferPointer =
				(void *)JKRHeap::alloc(size, 0, m_Do_ext::archiveHeap);
			if (mDoAud_StreamBufferPointer == (void *)0x0) {
				mDoAud_audioStreamHeap = m_Do_ext::gameHeap;
				mDoAud_StreamBufferPointer = JKRHeap::alloc(size, 0, m_Do_ext::gameHeap);
			}
			if (mDoAud_StreamBufferPointer == (void *)0x0) {
				mDoAud_audioStreamHeap = m_Do_ext::zeldaHeap;
				mDoAud_StreamBufferPointer =
					(void *)JKRHeap::alloc(size, 0, m_Do_ext::zeldaHeap);
			}
			if (mDoAud_StreamBufferPointer != (void *)0x0)
				break;
			if (uVar1 < 4) {
				if (true) {
					auto uVar1 = JUTAssertion::getSDevice();
					JUTAssertion::showAssert(uVar1, "m_Do_audio.cpp", 0x90, "mDoAud_StreamBufferPointer");
					m_Do_printf::OSPanic("m_Do_audio.cpp", 0x90, "Halt");
				}
				return;
			}
			uVar1 = uVar1 - 1;
		}
		cVar3 = g_mDoAud_zelAudio.allocStreamBuffer(mDoAud_StreamBufferPointer, size);
		if (cVar3 != '\0') {
			return;
		}
		auto uVar12 = JUTAssertion::getSDevice();
		JUTAssertion::showAssert(uVar12, "m_Do_audio.cpp", 0x94, "success");
		m_Do_printf::OSPanic("m_Do_audio.cpp", 0x94, "Halt");
	}

	void mDoAud_deallocStreamBuffer(void) {
		char cVar2;

		if (mDoAud_StreamBufferPointer == (void *)0x0) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_audio.cpp", 0xae, "mDoAud_StreamBufferPointer");
			m_Do_printf::OSPanic("m_Do_audio.cpp", 0xae, "Halt");
		}
		cVar2 = g_mDoAud_zelAudio.deallocStreamBuffer();
		if (cVar2 == '\0') {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_audio.cpp", 0xb6, "success");
			m_Do_printf::OSPanic("m_Do_audio.cpp", 0xb6, "Halt");
		}
		JKRHeap::free(mDoAud_StreamBufferPointer, mDoAud_audioStreamHeap);
		mDoAud_StreamBufferPointer = (void *)0x0;
		mDoAud_audioStreamHeap = (JKRHeap *)0x0;
	}

	void mDoAud_setupStreamBuffer(void) {
		JAIGlobalParameter::setParamStreamInsideBufferCut(true);
		mDoAud_StreamBufferPointer = 0;
		mDoAud_StreamBufferBlocks = 0xc;
		mDoAud_audioStreamHeap = 0;
		JAInter::StreamLib::setAllocBufferCallback(mDoAud_allocStreamBuffer);
		JAInter::StreamLib::setDeallocBufferCallback(mDoAud_deallocStreamBuffer);
	}

	int mBgmSet;

	void reset(void) {
		mBgmSet = 0;
		return;
	}

	void mDoAud_Create(void) {
		ulong uVar1;
		JKRArchive *pJVar2;
		undefined8 uVar3;
		char archivename[104];

		if ((!l_affCommand) &&
			(l_affCommand = mDoDvdThd_toMainRam_c::create("/Audiores/JaiInit.aaf", 2, (JKRHeap *)0x0),
			 !l_affCommand)) {
			return;
		}
		if (!l_arcCommand) {
			JAInter::SequenceMgr::getArchiveName(archivename);
			l_arcCommand = mDoDvdThd_mountArchive_c::create(archivename, '\0', (JKRHeap *)0x0);
			if (!l_arcCommand) {
				return;
			}
		}

		if ((l_affCommand->mStatus) && (l_arcCommand->mStatus)) {
			JAIGlobalParameter::setParamInitDataPointer(l_affCommand->mpArchiveHeader);
			JAInter::SequenceMgr::setArchivePointer(l_arcCommand->mpResult);
			mDoAud_setupStreamBuffer();
			if (g_mDoAud_audioHeap == (JKRSolidHeap *)0x0) {
				m_Do_printf::OSReport_Error("ヒープ確保失敗につきオーディオ初期化できません\n");
			} else {
				((JKRHeap *)0x0)->becomeCurrentHeap();
				g_mDoAud_zelAudio.init(g_mDoAud_audioHeap, 0xa00000);
				m_Do_ext::zeldaHeap->becomeCurrentHeap();
				g_mDoAud_audioHeap->adjustSize();
			}
			g_mDoAud_zelAudio.setEventBit(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent.mBits);
			reset();
			uVar1 = os::OSGetSoundMode();
			JAIZelBasic::zel_basic->setOutputMode(uVar1);
			JKRHeap::free(l_affCommand->mpArchiveHeader, (JKRHeap *)0x0);
			delete l_affCommand;
			delete l_arcCommand;
			mDoAud_zelAudio_c::mInitFlag = 1;
			mDoDvdThd::SyncWidthSound = 1;
		}
	}

	void mDoAud_executeStreamBuffer() {
		/*Empty*/
	}

	void mDoAud_setSceneName(char *pSceneName, long startCode, long layerNo) {
		if (mDoAud_zelAudio_c::mLoadTimer == '\0') {
			//JAIZelBasic::zel_basic->setSceneName(pSceneName, startCode, layerNo);
			mDoAud_zelAudio_c::mLoadTimer = 36;
		}
	}

	void mDoAud_Execute(void) {
		if (mDoAud_zelAudio_c::mInitFlag == 0) {
			mDoAud_Create();
		} else {
			mDoAud_executeStreamBuffer();
			g_mDoAud_zelAudio.gframeProcess();
			mDoAud_zelAudio_c::calcLoadTimer();
		}
		return;
	}
}

JAIBasic *JAIBasic::msBasic;

void JAIBasic::setSeCategoryVolume(uchar idx, uchar vol) {
	JAInter::SeMgr::seCategoryVolume[idx] = (float)vol / 127.0;
}

void JAIBasic::processFrameWork() {
	// JAInter::DummyObjectMgr::check();
	// JAInter::BankWave::loadSecondStayWave();
	JAInter::SeMgr::processGFrameSe();
	JAInter::SequenceMgr::processGFrameSequence();
	JAInter::StreamMgr::processGFrameStream();
	this->processedCount = this->processedCount + 1;
}

bool JAIBasic::allocStreamBuffer(void *param_1, long param_2) {
	uint uVar1;

	uVar1 = JAInter::StreamLib::getNeedBufferSize();
	if (uVar1 <= (uint)param_2) {
		JAInter::StreamLib::allocBuffer(param_1, param_2);
	}
	return uVar1 <= (uint)param_2;
}

int JAIBasic::deallocStreamBuffer() {
	return JAInter::StreamLib::deallocBuffer();
}

namespace JAIGlobalParameter {
	char *audioResPath = "AudioRes/";
	char *sequenceArchivesPath = "Seqs/";
	char *sequenceArchivesFileName = "JaiSeqs.arc";

	void setParamInitDataPointer(void *param_1) {
		JAInter::InitData::aafPointer = param_1;
		JAIBasic::msBasic->status = 4;
	}

	void setParamStreamInsideBufferCut(bool param_1) {
		JAIBasic::msBasic->streamparam = (param_1 & 1U) << 3 | JAIBasic::msBasic->streamparam & 0xf7;
	}

	char *getParamAudioResPath(void) {
		return audioResPath;
	}

	char *getParamSequenceArchivesPath(void) {
		return sequenceArchivesPath;
	}

	char *getParamSequenceArchivesFileName(void) {
		return sequenceArchivesFileName;
	}

	void setParamStreamDecodedBufferBlocks(ulong param_1) {
		JAInter::StreamLib::setDecodedBufferBlocks(param_1);
	}

	void setParamInitDataPointer() {
	}

	void setParamInterfaceHeapSize(uint) {}
	void setParamSeRegistMax(uint) {}
	void setParamSoundSceneMax(uint) {}
	void setParamSeqControlBufferMax(uint) {}
	void setParamStreamControlBufferMax(uint) {}
	void setParamStreamDecodedBufferBlocks(uint) {}
	void setParamAutoHeapMax(uint) {}
	void setParamStayHeapMax(uint) {}
	void setParamAutoHeapRoomSize(uint) {}
	void setParamStayHeapSize(uint) {}
	void setParamSeqPlayTrackMax(uint) {}
	void setParamSystemTrackMax(uint) {}
	void setParamDistanceMax(uint) {}
	void setParamMaxVolumeDistance(uint) {}
	void setParamMinDistanceVolume(uint) {}
	void setParamSeDolbyCenterValue(uint) {}
	void setParamSeDolbyFrontDistanceMax(uint) {}
	void setParamSeDolbyBehindDistanceMax(uint) {}
	void setParamSeDistanceFxParameter(uint) {}
	void setParamInputGainDown(float) {}
	void setParamOutputGainUp(float) {}
	void setParamAudioResPath(char *) {}
	void setParamInitDataFileName(char *) {}
	void setParamWavePath(char *) {}
	void setParamSequenceArchivesPath(char *) {}
	void setParamStreamPath(char *) {}
	void setParamSequenceArchivesFileName(char *) {}
	void setParamAudioCameraMax(uint) {}
	void setParamDummyObjectMax(uint) {}
	void setParamDummyObjectLifeTime(uint) {}

	void setParamSoundOutputMode(uint) {}
}

namespace JAInter {
	namespace InitData {
		void *aafPointer;
	}

	namespace StreamLib {
		using AllocCB = void(void);
		AllocCB *allocCallback, *deallocCallback;
		int LOOP_BLOCKS;

		void setAllocBufferCallback(AllocCB *param_1) {
			allocCallback = param_1;
		}

		void setDeallocBufferCallback(AllocCB *param_1) {
			deallocCallback = param_1;
		}

		byte allocFlag;
		int **loop_buffer, **store_buffer;
		JASystem::Kernel::TSolidHeap streamHeap;
		void *adpcm_buffer;

		void allocBuffer(void *param_1, long param_2) {
			bool bVar1;
			int *uVar2;
			uint uVar3;
			int iVar4;
			int iVar5;
			uint uVar6;

			if (allocFlag == '\0') {
				streamHeap.init((uchar *)param_1, param_2);
				loop_buffer = (int **)streamHeap.alloc(8);
				if ((!loop_buffer) &&
					(!loop_buffer)) {
					JUTAssertion::showAssert(3, "JAIStreamMgr.cpp", 0x22b, "loop_buffer");
					m_Do_printf::OSPanic("JAIStreamMgr.cpp", 0x22b, "Halt");
				}
				uVar6 = 0;
				iVar5 = 0;
				do {
					uVar2 = (int *)streamHeap.alloc(LOOP_BLOCKS * sizeof(void *));
					(loop_buffer[uVar6]) = uVar2;
					bVar1 = (loop_buffer[uVar6]) == 0;
					if ((bVar1) && (bVar1)) {
						JUTAssertion::showAssert(3, "JAIStreamMgr.cpp", 0x22f, "loop_buffer[i]");
						m_Do_printf::OSPanic("JAIStreamMgr.cpp", 0x22f, "Halt");
					}
					iVar4 = 0;
					for (uVar3 = 0; uVar3 < (uint)JAInter::StreamLib::LOOP_BLOCKS; uVar3 = uVar3 + 1) {
						uVar2 = (int *)streamHeap.alloc(0x2800);
						((loop_buffer[uVar6 + uVar3])) = uVar2;
						bVar1 = ((loop_buffer[uVar6 + uVar3])) == 0;
						if ((bVar1) && (bVar1)) {
							JUTAssertion::showAssert(3, "JAIStreamMgr.cpp", 0x233, "loop_buffer[i][j]");
							m_Do_printf::OSPanic("JAIStreamMgr.cpp", 0x233, "Halt");
						}
						iVar4 = iVar4 + 4;
					}
					uVar6 = uVar6 + 1;
					iVar5 = iVar5 + 4;
				} while (uVar6 < 2);
				store_buffer = (int **)streamHeap.alloc(2 * sizeof(void *));
				if ((!store_buffer) &&
					(!store_buffer)) {
					JUTAssertion::showAssert(3, "JAIStreamMgr.cpp", 0x238, "store_buffer");
					m_Do_printf::OSPanic("JAIStreamMgr.cpp", 0x238, "Halt");
				}
				uVar6 = 0;
				iVar5 = 0;
				do {
					uVar2 = (int *)streamHeap.alloc(0x5000);
					store_buffer[uVar6] = uVar2;
					if ((store_buffer[uVar6] == 0) &&
						(store_buffer[uVar6] == 0)) {
						JUTAssertion::showAssert(3, "JAIStreamMgr.cpp", 0x23c, "store_buffer[i]");
						m_Do_printf::OSPanic("JAIStreamMgr.cpp", 0x23c, "Halt");
					}
					uVar6 = uVar6 + 1;
					iVar5 = iVar5 + 4;
				} while (uVar6 < 2);
				if ((!loop_buffer) &&
					(!loop_buffer)) {
					JUTAssertion::showAssert(3, "JAIStreamMgr.cpp", 0x23f, "loop_buffer");
					m_Do_printf::OSPanic("JAIStreamMgr.cpp", 0x23f, "Halt");
				}
				adpcm_buffer = streamHeap.alloc(0x5000);
				if ((!adpcm_buffer) &&
					(!adpcm_buffer)) {
					JUTAssertion::showAssert(3, "JAIStreamMgr.cpp", 0x241, "adpcm_buffer");
					m_Do_printf::OSPanic("JAIStreamMgr.cpp", 0x241, "Halt");
				}
				JAInter::StreamLib::allocFlag = '\x01';
			}
			return;
		}

		byte bufferMode;
		byte playflag2;

		undefined4 deallocBuffer(void) {
			undefined4 uVar1;

			if (((bufferMode == '\0') || (allocFlag == '\0')) || (playflag2 == '\x01')) {
				uVar1 = 0;
			} else {
				streamHeap.freeAll();
				allocFlag = '\0';
				uVar1 = 1;
			}
			return uVar1;
		}

		void setDecodedBufferBlocks(ulong param_1) {
			if (param_1 < 3) {
				m_Do_printf::OSReport("setDecodedBufferBlocks : 3ブロック以上必要ですので、使用ブロックを%dから3に変更します。\n", param_1);
				param_1 = 3;
			} else if (0xc < param_1) {
				m_Do_printf::OSReport("setDecodedBufferBlocks : 13ブロック以上は設定できませんので、使用ブロックを%dから12に変更しま す。\n", param_1);
				param_1 = 0xc;
			}
			LOOP_BLOCKS = param_1;
		}

		int getNeedBufferSize(void) {
			int iVar1;
			int iVar2;
			uint uVar3;
			int iVar4;

			uVar3 = 0;
			iVar1 = 0x20;
			do {
				iVar1 = iVar1 + (LOOP_BLOCKS & 0x3ffffff8U) * 4 + 0x20;
				iVar4 = LOOP_BLOCKS;
				if (LOOP_BLOCKS != 0) {
					do {
						iVar1 = iVar1 + 0x2820;
						iVar4 = iVar4 + -1;
					} while (iVar4 != 0);
				}
				uVar3 = uVar3 + 1;
			} while (uVar3 < 2);
			iVar4 = 2;
			iVar1 = iVar1 + 0x20;
			do {
				iVar2 = iVar1;
				iVar4 = iVar4 + -1;
				iVar1 = iVar2 + 0x5020;
			} while (iVar4 != 0);
			return iVar2 + 0xa040;
		}

	}

	namespace BankWave {
		int *wsLoadStatus;
		int *wsGroupNumber;
		int SceneSetFlag;

		int getWaveLoadStatus(long param_1) {
			return wsLoadStatus[param_1];
		}

		void setSceneSetFinishCallback(long param_1, long param_2) {
			JAInter::BankWave::SceneSetFlag = -1;
			JAInter::BankWave::wsLoadStatus[param_1] = 1;
			// JASystem::Dvd::checkPassDvdT((Dvd *)(param_1 * 0x10000 + param_2), 0, (ulong *)JAInter::BankWave::finishSceneSet,
			//							 (FuncDef569 *)&DAT_00000001);
		}

		void loadGroupWave(long param_1, long param_2) {
			// JASystem::WaveBankMgr::loadWave(param_1, param_2, nullptr);
			JAInter::BankWave::setSceneSetFinishCallback(param_1, param_2);
			JAInter::BankWave::wsGroupNumber[param_1] = param_2;
		}
	}

	namespace SeMgr {
		byte *seHandle;
		float *seCategoryVolume;

		void processGFrameSe(void) {
			// checkNextFrameSe();
			// checkPlayingSe();
			// checkSeMovePara();
		}
	}

	namespace SequenceMgr {
		JKRArchive *arcPointer;

		void setArchivePointer(JKRArchive *a) {
			arcPointer = a;
		}

		void getArchiveName(char *param_1) {
			char *pcVar1;

			*param_1 = 0;
			pcVar1 = JAIGlobalParameter::getParamAudioResPath();
			if (pcVar1 != (char *)0x0) {
				pcVar1 = JAIGlobalParameter::getParamAudioResPath();
				strcat(param_1, pcVar1);
			}
			pcVar1 = JAIGlobalParameter::getParamSequenceArchivesPath();
			strcat(param_1, pcVar1);
			pcVar1 = JAIGlobalParameter::getParamSequenceArchivesFileName();
			strcat(param_1, pcVar1);
		}

		void processGFrameSequence(void) {
			// checkEntriedSeq();
			// checkFadeoutSeq();
			// checkStoppedSeq();
			// checkPlayingSeq();
			// checkStartedSeq();
			// checkReadSeq();
			// checkSeqWave();
		}
	}

	namespace StreamMgr {
		int flags;
		void processGFrameStream(void) {
			if ((flags >> 6 & 1) == 0) {
				// checkPlayingStream();
				// checkRequestStream();
				// checkWaitStream();
				// checkEntriedStream();
			}
		}
	}
}

JAIZelBasic *JAIZelBasic::zel_basic;

void JAIZelBasic::loadStaticWaves() {
	m_Do_printf::OSReport("[JAIZelBasic::loadStaticWaves] 常駐シーン波形はここでなく、gFrameProcessの一番最初で読み込まれ ます。\n");
}

void JAIZelBasic::setEventBit(void *param_1) {
	this->eventbits = (byte *)param_1;
}

void JAIZelBasic::zeldaGFrameWork() {
}

void JAIZelBasic::init(JKRSolidHeap *param_1, ulong param_2) {
	JAIGlobalParameter::setParamInterfaceHeapSize(JAIZelParam::DRAM_HEAP_SIZE);
	JAIGlobalParameter::setParamSeRegistMax(JAIZelParam::SE_REGIST_MAX);
	JAIGlobalParameter::setParamSoundSceneMax(JAIZelParam::SOUND_SCENE_MAX);
	JAIGlobalParameter::setParamSeqControlBufferMax(JAIZelParam::SEQ_CONTROL_BUF_MAX);
	JAIGlobalParameter::setParamStreamControlBufferMax(JAIZelParam::STREAM_CONTROL_BUF_MAX);
	JAIGlobalParameter::setParamStreamDecodedBufferBlocks(JAIZelParam::STREAM_DECODED_BUFFERS);
	JAIGlobalParameter::setParamAutoHeapMax(JAIZelParam::AUTO_HEAP_MAX);
	JAIGlobalParameter::setParamStayHeapMax(JAIZelParam::STAY_HEAP_MAX);
	JAIGlobalParameter::setParamAutoHeapRoomSize(JAIZelParam::AUTO_HEAP_ROOM_SIZE);
	JAIGlobalParameter::setParamStayHeapSize(JAIZelParam::STAY_HEAP_ROOM_SIZE);
	JAIGlobalParameter::setParamSeqPlayTrackMax(JAIZelParam::PLAY_TRACK_MAX);
	JAIGlobalParameter::setParamSystemTrackMax(JAIZelParam::SYSTEM_TRACK_MAX);
	JAIGlobalParameter::setParamDistanceMax(JAIZelParam::DISTANCE_MAX);
	JAIGlobalParameter::setParamMaxVolumeDistance(JAIZelParam::MAX_VOLUME_DISTANCE);
	JAIGlobalParameter::setParamMinDistanceVolume(JAIZelParam::MIN_DISTANCE_VOLUME);
	JAIGlobalParameter::setParamSeDolbyCenterValue(JAIZelParam::DOLBY_CENTER_VALUE);
	JAIGlobalParameter::setParamSeDolbyFrontDistanceMax(JAIZelParam::DOLBY_FLONT_DISTANCE_MAX);
	JAIGlobalParameter::setParamSeDolbyBehindDistanceMax(JAIZelParam::DOLBY_BEHIND_DISTANCE_MAX);
	JAIGlobalParameter::setParamSeDistanceFxParameter(JAIZelParam::DISTANCE_FX_PARAM);
	JAIGlobalParameter::setParamInputGainDown(1.0);
	JAIGlobalParameter::setParamOutputGainUp(5.999);
	JAIGlobalParameter::setParamAudioResPath((char *)0x0);
	JAIGlobalParameter::setParamInitDataFileName(JAIZelParam::INIT_DATA_FILE_NAME);
	JAIGlobalParameter::setParamWavePath(JAIZelParam::WAVE_PATH);
	JAIGlobalParameter::setParamSequenceArchivesPath(JAIZelParam::SEQ_PATH);
	JAIGlobalParameter::setParamStreamPath(JAIZelParam::STREAM_PATH);
	JAIGlobalParameter::setParamSequenceArchivesFileName(JAIZelParam::SEQ_ARCH_FILE_NAME);
	JAIGlobalParameter::setParamAudioCameraMax(1);
	JAIGlobalParameter::setParamDummyObjectMax(JAIZelParam::DUMMY_POSITION_MAX);
	JAIGlobalParameter::setParamDummyObjectLifeTime(JAIZelParam::DUMMY_POSITION_LIFE_TIME);
	JAIGlobalParameter::setParamStreamInsideBufferCut(true);
	// initDriver(param_1, param_2, '\x01');
	// initInterface('\x01');
	this->field37_0x68 = (JAISound *)0x0;
	this->bgmsound = (JAISound *)0x0;
	this->mpSound = (JAISound *)0x0;
	// initSe();
	setSeCategoryVolume('\0', JAIZelParam::VOL_SE_SYSTEM_DEFAULT);
	setSeCategoryVolume('\x01', JAIZelParam::VOL_SE_LINK_VOICE_DEFAULT);
	setSeCategoryVolume('\x02', JAIZelParam::VOL_SE_LINK_MOTION_DEFAULT);
	setSeCategoryVolume('\x03', JAIZelParam::VOL_SE_LINK_FOOTNOTE_DEFAULT);
	setSeCategoryVolume('\x04', JAIZelParam::VOL_SE_CHAR_VOICE_DEFAULT);
	setSeCategoryVolume('\x05', JAIZelParam::VOL_SE_CHAR_MOVE_DEFAULT);
	setSeCategoryVolume('\x06', JAIZelParam::VOL_SE_OBJECT_DEFAULT);
	setSeCategoryVolume('\a', JAIZelParam::VOL_SE_ATMOSPHERE_DEFAULT);
	this->channelvolumes[0] = 1.0;
	this->channelvolumes[1] = 1.0;
	this->channelvolumes[2] = 1.0;
	this->channelvolumes[3] = 1.0;
	this->channelvolumes[4] = 1.0;
	this->channelvolumes[5] = 1.0;
	this->channelvolumes[6] = 1.0;
	this->channelvolumes[7] = 1.0;
	this->mastervolume = 1.0;
}

void JAIZelBasic::setOutputMode(ulong param_1) {
	if (param_1 < 3) {
		JAIGlobalParameter::setParamSoundOutputMode(param_1);
	}
}

void JAIZelBasic::gframeProcess() {
	if (JAInter::SeMgr::seHandle) {
		if (3 < (byte)JAInter::SeMgr::seHandle[5]) {
			zeldaGFrameWork();
		}
		processFrameWork();
	}
}

int JAIZelBasic::checkFirstWaves() {
	int iVar1;

	iVar1 = JAInter::BankWave::getWaveLoadStatus(2);
	return 2 - iVar1;
}
