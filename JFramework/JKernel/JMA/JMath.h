#pragma once

#include <doltypes.h>

#include <cmath>

#include "../JKernel.h"

namespace JKernel {
	namespace JMath {
		extern int jmaSinShift;
		extern ushort jmaSinTableSize;
		extern float *jmaSinTable, *jmaCosTable;

		uint JMANewSinTable(uint param_1);
	}
} 
