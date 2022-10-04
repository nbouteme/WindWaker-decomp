#pragma once

struct mDoAud_zelAudio_c {
	static int mInitFlag;
};

struct JKRSolidHeap;
struct mDoDvdThd_command_c;
struct mDoDvdThd_mountArchive_c;

namespace m_Do_audio {
	extern JKRSolidHeap *g_mDoAud_audioHeap;
	extern mDoDvdThd_command_c *l_affCommand;
	extern mDoDvdThd_mountArchive_c *l_arcCommand;

	void mDoAud_Create(void);

	void mDoAud_Execute(void);
}