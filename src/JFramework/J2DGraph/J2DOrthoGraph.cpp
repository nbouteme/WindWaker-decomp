#include "J2DOrthoGraph.h"
#include <dolphin/mtx.h>

J2DOrthoGraph::J2DOrthoGraph() : J2DGrafContext(0, 0, 0, 0) {
	setLookat();
}

void J2DOrthoGraph::setLookat() {
	C_MTXIdentity(this->mMtx);
	gx::GXLoadPosMtxImm(this->mMtx, 0);
}

void J2DOrthoGraph::scissorBounds(TBox2<float> *param_1, TBox2<float> *param_2) {
	float fVar1;
	float fVar2;
	float fVar3;
	float fVar4;
	float fVar5;
	float fVar6;
	float fVar7;
	float fVar8;
	float fVar9;

	fVar1 = (this)->mViewport.mTL[0];
	fVar2 = (this->mOrtho).mTL[0];
	fVar8 = ((this)->mViewport.mBR[0] - fVar1) / ((this->mOrtho).mBR[0] - fVar2);
	fVar3 = (this)->mViewport.mTL[1];
	fVar4 = (this->mOrtho).mTL[1];
	fVar9 = ((this)->mViewport.mBR[1] - fVar3) / ((this->mOrtho).mBR[1] - fVar4);
	fVar5 = (param_2->mBR)[0];
	fVar6 = (param_2->mTL)[1];
	fVar7 = (param_2->mBR)[1];
	(param_1->mTL)[0] = fVar1 + fVar8 * ((param_2->mTL)[0] - fVar2);
	(param_1->mTL)[1] = fVar3 + fVar9 * (fVar6 - fVar4);
	(param_1->mBR)[0] = fVar1 + fVar8 * (fVar5 - fVar2);
	(param_1->mBR)[1] = fVar3 + fVar9 * (fVar7 - fVar4);
}

J2DOrthoGraph::J2DOrthoGraph(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6) : J2DGrafContext(param_1, param_2, param_3, param_4) {
	(this->mOrtho).mTL[0] = 0.0;
	(this->mOrtho).mTL[1] = 0.0;
	(this->mOrtho).mBR[0] = param_3;
	(this->mOrtho).mBR[1] = param_4;
	this->mNearZ = param_5;
	this->mFarZ = param_6;
	setLookat();
}

void J2DOrthoGraph::setPort() {
	J2DGrafContext::setPort();
	mtx::C_MTXOrtho(this->mProj, (this->mOrtho).mTL[1], (this->mOrtho).mBR[1] + 0.5, (this->mOrtho).mTL[0],
					(this->mOrtho).mBR[0], this->mNearZ, this->mFarZ);
	gx::GXSetProjection(mProj, gx::GXProjectionType::GX_ORTHOGRAPHIC);
}

void J2DOrthoGraph::setOrtho(TBox2<float> *param_1, float param_2, float param_3) {
	this->mOrtho = *param_1;
	this->mNearZ = -param_3;
	this->mFarZ = -param_2;
}

J2DTypeID J2DOrthoGraph::getGrafType() {
	return J2DTypeID::J2DOrthoGraph;
}
