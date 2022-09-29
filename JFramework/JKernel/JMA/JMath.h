#pragma once

#include <doltypes.h>
#include <cmath>
#include "../JKernel.h"

namespace JKernel {
	namespace JMath {
        static int jmaSinShift;
        static ushort jmaSinTableSize;
        static float *jmaSinTable, *jmaCosTable;

		uint JMANewSinTable(uint param_1)
		{
			undefined4 uVar1;
			uint uVar2;
			uint uVar3;
			undefined4 uVar4;
			double dVar5;
			undefined8 in_f30;
			double dVar6;
			undefined8 in_f31;
			double dVar7;
			undefined auStack24[16];
			undefined auStack8[8];

			uVar4 = 0;
			JKernel::JMath::jmaSinShift = 0x10 - (param_1 & 0xff);
			uVar2 = 1;
			for (uVar3 = 0; (uVar3 & 0xff) < (param_1 & 0xff); uVar3 = uVar3 + 1) {
				uVar2 = (uVar2 & 0x7fff) << 1;
			}
			JKernel::JMath::jmaSinTableSize = (ushort)uVar2;
			JKernel::JMath::jmaSinTable = (float *)new float[(uVar2 + (uVar2 >> 2))];
			if (JKernel::JMath::jmaSinTable == (float *)0x0) {
				uVar1 = 0;
			} else {
				uVar2 = 0;
				dVar6 = 6.283185482025146; // 2 * pi
				dVar7 = 4503599627370496.0;
				while (true) {
					if ((uint)JKernel::JMath::jmaSinTableSize + (uint)(JKernel::JMath::jmaSinTableSize >> 2) <=
						(uVar2 & 0xffff))
						break;
					dVar5 = sin((dVar6 / ((double)JKernel::JMath::jmaSinTableSize) * (double)(uVar2 & 0xffff)));
					JKernel::JMath::jmaSinTable[uVar2 & 0xffff] = (float)dVar5;
					uVar2 = uVar2 + 1;
				}
				JKernel::JMath::jmaCosTable =
					JKernel::JMath::jmaSinTable + (JKernel::JMath::jmaSinTableSize >> 2);
				uVar1 = 1;
			}
			return uVar1;
		}
	}
}  // namespace JKernel
