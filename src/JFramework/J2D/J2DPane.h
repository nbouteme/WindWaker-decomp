#pragma once

#include <JFramework/JSupport/JSUPtrLink.h>
#include <JFramework/JSupport/JSUPtrList.h>
#include "../J2DGraph/J2DGrafContext.h"

struct JSURandomInputStream;

struct J2DPane {
	using J2DBasePosition = int;

	int mMagic;
	int mName;
	TBox2<float> mPos;
	TBox2<float> mScreenPos, mBox;
	MTX34 mMtx, mDrawMtx;
	cXy mBasePosition;
	float mRotation;
	char mRotationAxis;
	byte m2DBasePosition, mbDraw, mCullMode, mAlpha, mDrawAlpha, mBlendMode, mConnectParent;
	JSUPtrList mChildList;
	JSUPtrLink mParentLink;

	virtual void update();
	virtual void drawSelf(float, float);
	virtual void drawSelf(MTX34, float, float);
	virtual int getTypeID();
	virtual void setConnectParent(bool);
	virtual void resize(float xd, float yd);

	virtual void add(float a, float b);

	virtual void calcMtx();

	void initiate();

	void move(float param_1, float param_2);

	void clip(TBox2<float> *param_1);

	J2DPane();

	J2DPane(ulong param_1, TBox2<float> *param_2);

	uint insertChild(J2DPane *param_1, J2DPane *param_2);

	J2DPane(J2DPane *pParentPane, JSURandomInputStream *pStream);

	J2DPane(J2DPane *param_1, bool param_2, ulong param_3, TBox2<float> *param_4);

	void setBasePosition(J2DBasePosition param_1);

	~J2DPane();

	void makeMatrix(float x, float y);

	void makePaneStream(J2DPane *pParentPane, JSURandomInputStream *pStream);

	void draw(float param_1, float param_2, struct J2DGrafContext *pCtx, bool bClip);
};