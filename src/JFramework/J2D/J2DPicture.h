#pragma once

#include "J2DPane.h"

struct JUTPalette;
struct JUTTexture;
struct ResTLUT;
struct ResTIMG;

struct J2DPicture : J2DPane {
	JUTTexture *mpTexture[2];
	byte mNumTexture;
	float mBlendKonstColorF[4];
	float mBlendKonstAlphaF[4];
	JUTPalette *mpPalette;
	gx::GXColor mColorBase, mBgColor, mNewColor[4], mBlendKonstColor, mBlendKonstAlpha;
	int field4_0xdd;
	int binding;
	int mirror;

	using J2DBinding = int;
	using J2DMirror = int;

	virtual int getTypeID() override;

	void swap(float *param_1, float *param_2);

	void changeTexture(char *param_1, byte param_2);

	ResTIMG *changeTexture(ResTIMG *param_1, uchar param_2);

	void drawOut(float param_1, float param_2, float param_3, float param_4,
				 float param_5, float param_6, float param_7, float param_8);

	void drawOut(TBox2<float> *param_1, TBox2<float> *param_2);

	void insert(char *param_1, uchar param_2, float param_3);

	undefined4 insert(ResTIMG *param_1, uchar param_2, float param_3);

	void drawSelf(float param_1, float param_2);

	void initinfo();

	J2DPicture();

	void drawOut(float param_1, float param_2, float param_3, float param_4,
				 float param_5, float param_6);

	void private_initiate(ResTIMG *param_1, ResTLUT *param_2);

	J2DPicture(ulong param_1, TBox2<float> *param_2, ResTIMG *param_3, ResTLUT *param_4);

	~J2DPicture();

	J2DPicture(ResTIMG *param_1);

	J2DPicture(char *param_1);

	void initiate(ResTIMG *param_1, ResTLUT *param_2);

	void setBlendKonstColor();

	void setBlendKonstAlpha();

	void getNewColor(gx::GXColor *param_1);

	int remove(uchar param_1);

	void setTevMode();

	void drawSelf(MTX34 param_3, float param_1, float param_2);

	void drawSelf(MTX34 param_1, float param_2, float param_3);

	void draw(float param_1, float param_2, float param_3, float param_4,
			  bool param_5, bool param_6, bool param_7);

	void drawFullSet(float,
					 float,
					 float,
					 float,
					 J2DBinding,
					 J2DMirror,
					 bool,
					 MTX34);

	void drawTexCoord(float,
					  float,
					  float,
					  float,
					  float,
					  float,
					  float,
					  float,
					  float,
					  float,
					  float,
					  float,
					  MTX34);

	J2DPicture(J2DPane *param_1, JSURandomInputStream *param_2);
};