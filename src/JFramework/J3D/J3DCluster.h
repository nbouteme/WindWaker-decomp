#pragma once

#include <doltypes.h>
// TODO: looks unused in regular gameplay, so stub it for now
struct J3DClusterLoader_v15;
struct J3DModelData;

namespace J3DClusterLoaderDataBase {
	J3DClusterLoader_v15 *load(void *param_1) {
		// TODO: looks unused in regular gameplay, so stub it for now
		return 0;
	}
}

namespace J3DModelLoaderDataBase {
	J3DModelData *load(void *param_1, uint param_2) {
		return 0;
	}

	J3DModelData *loadBinaryDisplayList(void *, uint) {
	}
}