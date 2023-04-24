#include "J3DMatPacket.h"
#include "J3DShapePacket.h"

void J3DMatPacket::addShapePacket(J3DShapePacket *param_1) {
	if (!this->mpFirstShapePacket) {
		this->mpFirstShapePacket = param_1;
		return;
	}
	param_1->mpNextSibling = (J3DPacket *)this->mpFirstShapePacket;
	this->mpFirstShapePacket = param_1;
}