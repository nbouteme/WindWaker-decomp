#pragma once

#include "J3DDrawPacket.h"

struct J3DShapePacket : public J3DDrawPacket {
    //J3DShape *mpShape;
    float *mpMtxBuffer;

};