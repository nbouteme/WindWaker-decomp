#pragma once

#include <doltypes.h>
#include <machine/dolphin/HIO.h>

struct fapGm_HIO_c : public JORReflexible {
	byte HIOLoaded;
	byte forceprocessbar, debugdisp;

	u16 fbWidth, efbHeight;
};

namespace f_ap_game {
	extern fapGm_HIO_c g_HIO;

	void fapGm_After(void);

	void fapGm_Create();

	void fapGm_Execute();
};