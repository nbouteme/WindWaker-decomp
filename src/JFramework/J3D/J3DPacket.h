#pragma once

struct J3DPacket {
	J3DPacket* mpNextSibling;
	J3DPacket* mpFirstChild;
	void* unk;	// parent?

	virtual void draw() {}
	virtual int entry() { return 1; }
	virtual ~J3DPacket() {}
};

struct J3DCallBackPacket : J3DPacket {
	void* mCallBack;
};