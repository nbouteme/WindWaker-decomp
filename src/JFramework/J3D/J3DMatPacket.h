#pragma once

#include "J3DDrawPacket.h"
#include <d_resorce.h>

struct J3DShapePacket;

struct J3DTexture {
    short mCount;
    ResTIMG *mpTexData;
    void *vtbl;
};

struct J3DMaterialAnm {
    //J3DMatColorAnm *mpMatColorAnm[2];
    //TODO: cont...
};

struct J3DMatPacket : public J3DDrawPacket {
    J3DShapePacket *mpShapePacket;
    J3DShapePacket *mpFirstShapePacket;
    //J3DMaterial mpMaterial;
    int mSortFlags;
    J3DTexture mpTexture;
    J3DMaterialAnm mpMaterialAnm;
	void addShapePacket(J3DShapePacket *param_1);
};