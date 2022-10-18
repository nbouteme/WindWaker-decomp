#pragma once

#include <JFramework/JKernel/JKRArchive.h>

struct JKRSolidHeap;
struct mDoDvdThd_command_c;
struct mDoDvdThd_mountArchive_c;

namespace JAIZelParam {
	extern uint DRAM_HEAP_SIZE;
	extern uint SE_REGIST_MAX;
	extern uint SOUND_SCENE_MAX;
	extern uint SEQ_CONTROL_BUF_MAX;
	extern uint STREAM_CONTROL_BUF_MAX;
	extern uint STREAM_DECODED_BUFFERS;
	extern uint AUTO_HEAP_MAX;
	extern uint STAY_HEAP_MAX;
	extern uint AUTO_HEAP_ROOM_SIZE;
	extern uint STAY_HEAP_ROOM_SIZE;
	extern uint PLAY_TRACK_MAX;
	extern uint SYSTEM_TRACK_MAX;
	extern float DISTANCE_MAX;
	extern float MAX_VOLUME_DISTANCE;
	extern float MIN_DISTANCE_VOLUME;
	extern byte DOLBY_CENTER_VALUE;
	extern float DOLBY_FLONT_DISTANCE_MAX;
	extern float DOLBY_BEHIND_DISTANCE_MAX;
	extern ushort DISTANCE_FX_PARAM;
	extern byte VOL_SE_SYSTEM_DEFAULT;
	extern byte VOL_SE_LINK_VOICE_DEFAULT;
	extern byte VOL_SE_LINK_MOTION_DEFAULT;
	extern byte VOL_SE_LINK_FOOTNOTE_DEFAULT;
	extern byte VOL_SE_CHAR_VOICE_DEFAULT;
	extern byte VOL_SE_CHAR_MOVE_DEFAULT;
	extern byte VOL_SE_OBJECT_DEFAULT;
	extern byte VOL_SE_ATMOSPHERE_DEFAULT;
	extern char *INIT_DATA_FILE_NAME;
	extern char *WAVE_PATH;
	extern char *SEQ_PATH;
	extern char *STREAM_PATH;
	extern char *SEQ_ARCH_FILE_NAME;
	extern uint DUMMY_POSITION_MAX;
	extern uint DUMMY_POSITION_LIFE_TIME;
}

struct JAISound;

struct JAIBasic {
	static JAIBasic *msBasic;
	static JKRHeap *msCurrentHeap;

	int processedCount;
	int status;
	int streamparam;
	float channelvolumes[8];
	float mastervolume;
	JAISound *bgmsound, *mpSound, *field37_0x68;

	void setSeCategoryVolume(uchar idx, uchar vol);
	void processFrameWork();
	bool allocStreamBuffer(void *param_1, long param_2);
	int deallocStreamBuffer();
	JAIBasic();
};

namespace JAIGlobalParameter {
	extern char *audioResPath;
	extern char *sequenceArchivesPath;
	extern char *sequenceArchivesFileName;

	void setParamInitDataPointer(void *param_1);

	void setParamStreamInsideBufferCut(bool param_1);

	char *getParamAudioResPath(void);

	char *getParamSequenceArchivesPath(void);

	char *getParamSequenceArchivesFileName(void);

	void setParamStreamDecodedBufferBlocks(ulong param_1);

	void setParamInitDataPointer();

	void setParamInterfaceHeapSize(uint);
	void setParamSeRegistMax(uint);
	void setParamSoundSceneMax(uint);
	void setParamSeqControlBufferMax(uint);
	void setParamStreamControlBufferMax(uint);
	void setParamStreamDecodedBufferBlocks(uint);
	void setParamAutoHeapMax(uint);
	void setParamStayHeapMax(uint);
	void setParamAutoHeapRoomSize(uint);
	void setParamStayHeapSize(uint);
	void setParamSeqPlayTrackMax(uint);
	void setParamSystemTrackMax(uint);
	void setParamDistanceMax(uint);
	void setParamMaxVolumeDistance(uint);
	void setParamMinDistanceVolume(uint);
	void setParamSeDolbyCenterValue(uint);
	void setParamSeDolbyFrontDistanceMax(uint);
	void setParamSeDolbyBehindDistanceMax(uint);
	void setParamSeDistanceFxParameter(uint);
	void setParamInputGainDown(float);
	void setParamOutputGainUp(float);
	void setParamAudioResPath(char *);
	void setParamInitDataFileName(char *);
	void setParamWavePath(char *);
	void setParamSequenceArchivesPath(char *);
	void setParamStreamPath(char *);
	void setParamSequenceArchivesFileName(char *);
	void setParamAudioCameraMax(uint);
	void setParamDummyObjectMax(uint);
	void setParamDummyObjectLifeTime(uint);

	void setParamSoundOutputMode(uint);
}

namespace JAInter {
	namespace InitData {
		extern void *aafPointer;
	}

	namespace StreamLib {
		using AllocCB = void(void);
		extern AllocCB *allocCallback, *deallocCallback;
		extern int LOOP_BLOCKS;

		void setAllocBufferCallback(AllocCB *param_1);

		void setDeallocBufferCallback(AllocCB *param_1);

		extern byte allocFlag;
		extern int **loop_buffer, **store_buffer;
		extern void *adpcm_buffer;

		void allocBuffer(void *param_1, long param_2);

		extern byte bufferMode;
		extern byte playflag2;

		undefined4 deallocBuffer(void);

		void setDecodedBufferBlocks(ulong param_1);

		int getNeedBufferSize(void);

	}

	namespace BankWave {
		extern int *wsLoadStatus;
		extern int *wsGroupNumber;
		extern int SceneSetFlag;

		int getWaveLoadStatus(long param_1);

		void setSceneSetFinishCallback(long param_1, long param_2);

		void loadGroupWave(long param_1, long param_2);
	}

	namespace SeMgr {
		extern byte *seHandle;
		extern float *seCategoryVolume;

		void processGFrameSe(void);
	}

	namespace SequenceMgr {
		extern JKRArchive *arcPointer;

		void setArchivePointer(JKRArchive *a);

		void getArchiveName(char *param_1);

		void processGFrameSequence(void);
	}

	namespace StreamMgr {
		extern int flags;
		void processGFrameStream(void);
	}
}

struct JAIZelBasic : JAIBasic {
	static JAIZelBasic *zel_basic;

	byte *eventbits;

	void loadStaticWaves();

	void setEventBit(void *param_1);

	void zeldaGFrameWork();

	void init(JKRSolidHeap *param_1, ulong param_2);

	void setOutputMode(ulong param_1);

	void gframeProcess();

	int checkFirstWaves();
};

struct mDoDvdThd_toMainRam_c;

namespace m_Do_audio {
	extern JKRSolidHeap *g_mDoAud_audioHeap;
	extern mDoDvdThd_toMainRam_c *l_affCommand;
	extern mDoDvdThd_mountArchive_c *l_arcCommand;
	extern JAIZelBasic g_mDoAud_zelAudio;

	void mDoAud_Create(void);

	void mDoAud_executeStreamBuffer();

	void mDoAud_Execute(void);

	template <typename T>
	void cLib_calcTimer(T param_1) {
		if (*param_1) {
			param_1[0]--;
		}
	}

	void mDoAud_setSceneName(char *pSceneName, long startCode, long layerNo);
}

namespace mDoAud_zelAudio_c {
	extern byte mInitFlag;
	extern byte mLoadTimer;

	static void calcLoadTimer(void);
}
