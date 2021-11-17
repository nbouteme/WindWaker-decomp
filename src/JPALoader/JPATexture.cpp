#include <JPALoader/JPATexture.h>
#include <JUtility/JUTTexture.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <os/OSCache.h>
#include <gx/GXTexture.h>
#include <JPATextureArc.h>
#include <JPADefaultTexture.h>
#include <JPATexture.h>


/* __thiscall JPATextureArc::JPATextureArc(unsigned char const *) */

void __thiscall JPATextureArc::JPATextureArc(JPATextureArc *this,uchar *pData)

{
  (this->parent).vtbl = &JPATexture::__vt;
  (this->parent).vtbl = &__vt;
  (this->parent).mTexture.field_0x3b = (this->parent).mTexture.field_0x3b & 2;
  (this->parent).mTexture.mpPalette = (JUTPalette *)0x0;
  this->mpData = pData;
  JUTTexture::storeTIMG(&(this->parent).mTexture,(ResTIMG *)(this->mpData + 0x20),'\0');
  return;
}


/* __thiscall JPADefaultTexture::initialize(JKRHeap *) */

void __thiscall JPADefaultTexture::initialize(JPADefaultTexture *this,JKRHeap *param_1)

{
  byte *pbVar1;
  ulong uVar2;
  double dVar3;
  
  pbVar1 = (byte *)JKRHeap::alloc(0x80,0x20,param_1);
  this->mpImgBuf = pbVar1;
  if (this->mpImgBuf == (byte *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JPATexture.cpp",0x32,"imgBuf");
    m_Do_printf::OSPanic("JPATexture.cpp",0x32,&DAT_8036660e);
  }
  *this->mpImgBuf = 0;
  this->mpImgBuf[1] = 0xff;
  this->mpImgBuf[2] = 0;
  this->mpImgBuf[3] = 0xff;
  this->mpImgBuf[4] = 0;
  this->mpImgBuf[5] = 0xff;
  this->mpImgBuf[6] = 0;
  this->mpImgBuf[7] = 0xff;
  this->mpImgBuf[8] = 0;
  this->mpImgBuf[9] = 0xff;
  this->mpImgBuf[10] = 0x1a;
  this->mpImgBuf[0xb] = 0xff;
  this->mpImgBuf[0xc] = 0x80;
  this->mpImgBuf[0xd] = 0xff;
  this->mpImgBuf[0xe] = 0xd6;
  this->mpImgBuf[0xf] = 0xff;
  this->mpImgBuf[0x10] = 0;
  this->mpImgBuf[0x11] = 0xff;
  this->mpImgBuf[0x12] = 0x80;
  this->mpImgBuf[0x13] = 0xff;
  this->mpImgBuf[0x14] = 0xff;
  this->mpImgBuf[0x15] = 0xff;
  this->mpImgBuf[0x16] = 0xff;
  this->mpImgBuf[0x17] = 0xff;
  this->mpImgBuf[0x18] = 0;
  this->mpImgBuf[0x19] = 0xff;
  this->mpImgBuf[0x1a] = 0xd6;
  this->mpImgBuf[0x1b] = 0xff;
  this->mpImgBuf[0x1c] = 0xff;
  this->mpImgBuf[0x1d] = 0xff;
  this->mpImgBuf[0x1e] = 0xff;
  this->mpImgBuf[0x1f] = 0xff;
  this->mpImgBuf[0x20] = 0;
  this->mpImgBuf[0x21] = 0xff;
  this->mpImgBuf[0x22] = 0;
  this->mpImgBuf[0x23] = 0xff;
  this->mpImgBuf[0x24] = 0;
  this->mpImgBuf[0x25] = 0xff;
  this->mpImgBuf[0x26] = 0;
  this->mpImgBuf[0x27] = 0xff;
  this->mpImgBuf[0x28] = 0xd6;
  this->mpImgBuf[0x29] = 0xff;
  this->mpImgBuf[0x2a] = 0x80;
  this->mpImgBuf[0x2b] = 0xff;
  this->mpImgBuf[0x2c] = 0x1a;
  this->mpImgBuf[0x2d] = 0xff;
  this->mpImgBuf[0x2e] = 0;
  this->mpImgBuf[0x2f] = 0xff;
  this->mpImgBuf[0x30] = 0xff;
  this->mpImgBuf[0x31] = 0xff;
  this->mpImgBuf[0x32] = 0xff;
  this->mpImgBuf[0x33] = 0xff;
  this->mpImgBuf[0x34] = 0x80;
  this->mpImgBuf[0x35] = 0xff;
  this->mpImgBuf[0x36] = 0;
  this->mpImgBuf[0x37] = 0xff;
  this->mpImgBuf[0x38] = 0xff;
  this->mpImgBuf[0x39] = 0xff;
  this->mpImgBuf[0x3a] = 0xff;
  this->mpImgBuf[0x3b] = 0xff;
  this->mpImgBuf[0x3c] = 0xd6;
  this->mpImgBuf[0x3d] = 0xff;
  this->mpImgBuf[0x3e] = 0;
  this->mpImgBuf[0x3f] = 0xff;
  this->mpImgBuf[0x40] = 0;
  this->mpImgBuf[0x41] = 0xff;
  this->mpImgBuf[0x42] = 0xd6;
  this->mpImgBuf[0x43] = 0xff;
  this->mpImgBuf[0x44] = 0xff;
  this->mpImgBuf[0x45] = 0xff;
  this->mpImgBuf[0x46] = 0xff;
  this->mpImgBuf[0x47] = 0xff;
  this->mpImgBuf[0x48] = 0;
  this->mpImgBuf[0x49] = 0xff;
  this->mpImgBuf[0x4a] = 0x80;
  this->mpImgBuf[0x4b] = 0xff;
  this->mpImgBuf[0x4c] = 0xff;
  this->mpImgBuf[0x4d] = 0xff;
  this->mpImgBuf[0x4e] = 0xff;
  this->mpImgBuf[0x4f] = 0xff;
  this->mpImgBuf[0x50] = 0;
  this->mpImgBuf[0x51] = 0xff;
  this->mpImgBuf[0x52] = 0x1a;
  this->mpImgBuf[0x53] = 0xff;
  this->mpImgBuf[0x54] = 0x80;
  this->mpImgBuf[0x55] = 0xff;
  this->mpImgBuf[0x56] = 0xd6;
  this->mpImgBuf[0x57] = 0xff;
  this->mpImgBuf[0x58] = 0;
  this->mpImgBuf[0x59] = 0xff;
  this->mpImgBuf[0x5a] = 0;
  this->mpImgBuf[0x5b] = 0xff;
  this->mpImgBuf[0x5c] = 0;
  this->mpImgBuf[0x5d] = 0xff;
  this->mpImgBuf[0x5e] = 0;
  this->mpImgBuf[0x5f] = 0xff;
  this->mpImgBuf[0x60] = 0xff;
  this->mpImgBuf[0x61] = 0xff;
  this->mpImgBuf[0x62] = 0xff;
  this->mpImgBuf[99] = 0xff;
  this->mpImgBuf[100] = 0xd6;
  this->mpImgBuf[0x65] = 0xff;
  this->mpImgBuf[0x66] = 0;
  this->mpImgBuf[0x67] = 0xff;
  this->mpImgBuf[0x68] = 0xff;
  this->mpImgBuf[0x69] = 0xff;
  this->mpImgBuf[0x6a] = 0xff;
  this->mpImgBuf[0x6b] = 0xff;
  this->mpImgBuf[0x6c] = 0x80;
  this->mpImgBuf[0x6d] = 0xff;
  this->mpImgBuf[0x6e] = 0;
  this->mpImgBuf[0x6f] = 0xff;
  this->mpImgBuf[0x70] = 0xd6;
  this->mpImgBuf[0x71] = 0xff;
  this->mpImgBuf[0x72] = 0x80;
  this->mpImgBuf[0x73] = 0xff;
  this->mpImgBuf[0x74] = 0x1a;
  this->mpImgBuf[0x75] = 0xff;
  this->mpImgBuf[0x76] = 0;
  this->mpImgBuf[0x77] = 0xff;
  this->mpImgBuf[0x78] = 0;
  this->mpImgBuf[0x79] = 0xff;
  this->mpImgBuf[0x7a] = 0;
  this->mpImgBuf[0x7b] = 0xff;
  this->mpImgBuf[0x7c] = 0;
  this->mpImgBuf[0x7d] = 0xff;
  this->mpImgBuf[0x7e] = 0;
  this->mpImgBuf[0x7f] = 0xff;
  os::DCStoreRange(this->mpImgBuf,0x80);
  gx::GXInitTexObj((GXTexObj *)&this->mTexObj,this->mpImgBuf,8,8,GX_TF_IA8,GX_REPEAT,GX_REPEAT,false
                  );
  dVar3 = (double)JPALoader::_2182;
  gx::GXInitTexObjLOD(dVar3,dVar3,dVar3,&this->mTexObj,1,1,0,0,0);
  return;
}


/* __thiscall JPATexture::~JPATexture(void) */

void __thiscall JPATexture::_JPATexture(JPATexture *this)

{
  short in_r4;
  
  if ((this != (JPATexture *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPATextureArc::~JPATextureArc(void) */

void __thiscall JPATextureArc::_JPATextureArc(JPATextureArc *this)

{
  short in_r4;
  
  if (this != (JPATextureArc *)0x0) {
    (this->parent).vtbl = &__vt;
    JUTTexture::_JUTTexture(&(this->parent).mTexture,-1);
    if (this != (JPATextureArc *)0x0) {
      (this->parent).vtbl = &JPATexture::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPATextureArc::getName(void) const */

byte * __thiscall JPATextureArc::getName(JPATextureArc *this)

{
  return this->mpData + 0xc;
}


/* __thiscall JPATextureArc::load(_GXTexMapID) */

void __thiscall JPATextureArc::load(JPATextureArc *this,_GXTexMapID texMap)

{
  JUTTexture::load(&(this->parent).mTexture,texMap);
  return;
}


/* __thiscall JPATextureArc::getJUTTexture(void) */

JUTTexture * __thiscall JPATextureArc::getJUTTexture(JPATextureArc *this)

{
  return &(this->parent).mTexture;
}

