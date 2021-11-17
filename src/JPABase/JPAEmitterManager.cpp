#include <JPABase/JPAEmitterManager.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSupport/JSUList.h>
#include <JPABase/JPAEmitterManager.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JPALoader/JPAResourceManager.h>
#include <JPABase/JPAEmitter.h>
#include <JPADraw/JPADraw.h>
#include <JPABase/JPAField.h>
#include <JMath/random.h>
#include <Demangler/JPABaseParticle.h>
#include <Demangler/JPABaseEmitter.h>
#include <JSUList<JPABaseEmitter>.h>
#include <Demangler/JPAFieldData.h>
#include <Demangler/JPAEmitterManager.h>


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JPAEmitterManager::JPAEmitterManager(JPAResourceManager *,
                                                   unsigned long,
                                                   unsigned long,
                                                   unsigned long,
                                                   JKRHeap *) */

void __thiscall
JPAEmitterManager::JPAEmitterManager
          (JPAEmitterManager *this,JPAResourceManager *param_1,ulong param_2,ulong param_3,
          ulong param_4,JKRHeap *param_5)

{
  int iVar1;
  undefined4 uVar2;
  JPABaseParticle *pPtcls;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  JKRHeap *pJVar6;
  int iVar7;
  
  JSUPtrList::initiate(&this->field_0x0);
  JSUPtrList::initiate(&this->mFreeEmitters);
  JSUPtrList::initiate(&this->field_0x18);
  Runtime.PPCEABI.H::__construct_array
            (this->mPtrLists,JSUList<JPABaseEmitter>::JSUList,JSUList<JPABaseEmitter>::_JSUList,0xc,
             0x10);
  pJVar6 = JKRHeap::sCurrentHeap;
  if (param_5 != (JKRHeap *)0x0) {
    pJVar6 = param_5;
  }
  this->field_0x24 = param_2;
  this->field_0x28 = param_3;
  this->field_0x2c = param_4;
  this->mpResMgr = param_1;
  iVar1 = 4;
  iVar7 = 7;
  do {
    *(undefined4 *)((int)this->mPtrLists + iVar1 + -0x20) = 0;
    iVar1 = iVar1 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar1 = this->field_0x24;
  uVar2 = JKernel::operator_new__(iVar1 * 0xd4 + 0x10,pJVar6,0);
  pPtcls = (JPABaseParticle *)
           Runtime.PPCEABI.H::__construct_new_array
                     (uVar2,JPABaseParticle::JPABaseParticle,JPABaseParticle::_JPABaseParticle,0xd4,
                      iVar1);
  if (pPtcls == (JPABaseParticle *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JPAEmitterManager.cpp",0x2e,"pPtclArray");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0x2e,&DAT_80366939);
  }
  iVar1 = 0;
  for (uVar5 = 0; uVar5 < (uint)this->field_0x24; uVar5 = uVar5 + 1) {
    JSUPtrList::prepend(&this->field_0x0,(JSUPtrLink *)((int)&(pPtcls->mLink).mpData + iVar1));
    iVar1 = iVar1 + 0xd4;
  }
  iVar1 = this->field_0x28;
  uVar2 = JKernel::operator_new__(iVar1 * 0x218 + 0x10,pJVar6,0);
  iVar1 = Runtime.PPCEABI.H::__construct_new_array
                    (uVar2,JPABaseEmitter::JPABaseEmitter,JPABaseEmitter::_JPABaseEmitter,0x218,
                     iVar1);
  if (iVar1 == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JPAEmitterManager.cpp",0x35,"pEmtrArray");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0x35,&DAT_80366939);
  }
  iVar7 = 0;
  for (uVar5 = 0; uVar5 < (uint)this->field_0x28; uVar5 = uVar5 + 1) {
    iVar4 = iVar1 + iVar7;
    *(JPAEmitterManager **)(iVar4 + 0x194) = this;
    *(JSUPtrList **)(iVar4 + 0x178) = &this->field_0x18;
    JSUPtrList::prepend(&this->mFreeEmitters,(JSUPtrLink *)(iVar4 + 0x90));
    iVar7 = iVar7 + 0x218;
  }
  iVar1 = this->field_0x2c;
  uVar2 = JKernel::operator_new__(iVar1 * 0x9c + 0x10,pJVar6,0);
  iVar1 = Runtime.PPCEABI.H::__construct_new_array
                    (uVar2,JPAFieldData::JPAFieldData,JPAFieldData::_JPAFieldData,0x9c,iVar1);
  if (iVar1 == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JPAEmitterManager.cpp",0x3e,"pFieldArray");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0x3e,&DAT_80366939);
  }
  iVar7 = 0;
  for (uVar5 = 0; uVar5 < (uint)this->field_0x2c; uVar5 = uVar5 + 1) {
    JSUPtrList::prepend(&this->field_0x18,(JSUPtrLink *)(iVar1 + iVar7 + 8));
    iVar7 = iVar7 + 0x9c;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall JPAEmitterManager::createSimpleEmitterID(JGeometry::TVec3<float><float> const &,
                                                       unsigned short,
                                                       unsigned char,
                                                       unsigned char,
                                                       JPACallBackBase<JPABaseEmitter *> *,
                                                       JPACallBackBase2<JPABaseEmitter
   *,JPABaseParticle *> *) */

JPABaseEmitter * __thiscall
JPAEmitterManager::createSimpleEmitterID
          (JPAEmitterManager *this,TVec3_float_ *pPos,ushort userID,uchar groupID,uchar rmID,
          JPACallBackBase *pCallBack,JPACallBackBase2 *pCallBack2)

{
  ulong uVar1;
  JPAEmitterData *pJVar2;
  JPABaseEmitter *this_00;
  JPAEmitterManager *pResMgr;
  
  if (0xf < groupID) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JPAEmitterManager.cpp",0x56,"groupID < 16");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0x56,&DAT_80366939);
  }
  if (7 < rmID) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JPAEmitterManager.cpp",0x57,"rmID < 8");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0x57,&DAT_80366939);
  }
  pResMgr = (JPAEmitterManager *)((int)this->mPtrLists + (uint)rmID * 4 + -0x50);
  if (pResMgr->mpResMgr == (JPAResourceManager *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JPAEmitterManager.cpp",0x58,"pResMgrArray[rmID] != 0");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0x58,&DAT_80366939);
  }
  this_00 = (JPABaseEmitter *)0x0;
  pJVar2 = JPAEmitterResource::getByUserIndex(pResMgr->mpResMgr->mpEmitterResource,userID);
  if (pJVar2 == (JPAEmitterData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"JPAEmitterManager.cpp",0x62,"%s",(___)"JParticle::Couldn\'t Create Emitter!");
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"JPAEmitterManager.cpp",99,"%s",
               (___)"User Index Number specification has mistaken.");
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"JPAEmitterManager.cpp",100,"Group ID (%d),EmitterManagerPtr(%x)",(uint)groupID
              );
  }
  else {
    if ((this->mFreeEmitters).mCount != 0) {
      this_00 = (JPABaseEmitter *)((this->mFreeEmitters).mpHead)->mpData;
      JSUPtrList::remove(&this->mFreeEmitters,&this_00->mLink);
      JSUPtrList::append(this->mPtrLists + groupID,&this_00->mLink);
      JPABaseEmitter::create
                (this_00,(JPADataBlockLinkInfo *)pJVar2->mpLinkInfoArray->mpDynamicsBlock);
      JPADraw::initialize(&this_00->mDraw,this_00,pResMgr->mpResMgr->mpTextureResource);
      this_00->mpEmitterCallBack = pCallBack;
      this_00->mpParticleCallBack = pCallBack2;
      this_00->mGroupID = groupID;
      this_00->mResMgrID = rmID;
      (this_00->mGlobalTranslation).x = pPos->x;
      (this_00->mGlobalTranslation).y = pPos->y;
      (this_00->mGlobalTranslation).z = pPos->z;
    }
  }
  return this_00;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPAEmitterManager::calc(unsigned char) */

void __thiscall JPAEmitterManager::calc(JPAEmitterManager *this,uchar param_1)

{
  ulong uVar1;
  char cVar3;
  JSUPtrLink *pJVar2;
  JPABaseEmitter *this_00;
  JSUPtrLink *pJVar4;
  
  if (0xf < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JPAEmitterManager.cpp",0xbb,"groupID < 16");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0xbb,&DAT_80366939);
  }
  pJVar2 = this->mPtrLists[param_1].mpHead;
  while (pJVar2 != (JSUPtrLink *)0x0) {
    pJVar4 = pJVar2->mpNext;
    this_00 = (JPABaseEmitter *)pJVar2->mpData;
    cVar3 = JPABaseEmitter::doStartFrameProcess(this_00);
    pJVar2 = pJVar4;
    if (cVar3 != '\0') {
      cVar3 = JPABaseEmitter::doTerminationProcess(this_00);
      if (cVar3 == '\0') {
        JPABaseEmitter::calc(this_00);
      }
      else {
        deleteEmitter(this,this_00);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPAEmitterManager::draw(JPADrawInfo *,
                                      unsigned char) */

void __thiscall
JPAEmitterManager::draw(JPAEmitterManager *this,JPADrawInfo *pDrawInfo,uchar groupID)

{
  ulong uVar1;
  JSUPtrLink *pJVar2;
  JPABaseEmitter *this_00;
  
  if (0xf < groupID) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JPAEmitterManager.cpp",0xde,"groupID < 16");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0xde,&DAT_80366939);
  }
  JPABaseEmitter::emtrInfo.field_0x104 = (undefined *)pDrawInfo->mFovY;
  JPABaseEmitter::emtrInfo.field_0x108 = (undefined *)pDrawInfo->mAspect;
  pJVar2 = this->mPtrLists[groupID].mpHead;
  while( true ) {
    if (pJVar2 == (JSUPtrLink *)0x0) break;
    this_00 = (JPABaseEmitter *)pJVar2->mpData;
    if ((this_00->mFlags & 4) == 0) {
      JPABaseEmitter::calcgReRDirection(this_00);
      JPADraw::draw(&this_00->mDraw,pDrawInfo->mpViewMtx);
    }
    pJVar2 = pJVar2->mpNext;
  }
  return;
}


/* __thiscall JPAEmitterManager::deleteEmitter(JPABaseEmitter *) */

void __thiscall JPAEmitterManager::deleteEmitter(JPAEmitterManager *this,JPABaseEmitter *param_1)

{
  JPAFieldManager::deleteAllField(&param_1->mFieldManager);
  JSUPtrList::remove(this->mPtrLists + param_1->mGroupID,&param_1->mLink);
  JSUPtrList::prepend(&this->mFreeEmitters,&param_1->mLink);
  return;
}


/* __thiscall JPAEmitterManager::forceDeleteEmitter(JPABaseEmitter *) */

void __thiscall
JPAEmitterManager::forceDeleteEmitter(JPAEmitterManager *this,JPABaseEmitter *param_1)

{
  JPABaseEmitter::deleteAllParticle(param_1);
  deleteEmitter(this,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPAEmitterManager::forceDeleteAllEmitter(void) */

void __thiscall JPAEmitterManager::forceDeleteAllEmitter(JPAEmitterManager *this)

{
  JSUPtrLink *pJVar1;
  byte bVar2;
  JSUPtrLink *pJVar3;
  
  for (bVar2 = 0; bVar2 < 0x10; bVar2 = bVar2 + 1) {
    pJVar1 = this->mPtrLists[bVar2].mpHead;
    while (pJVar1 != (JSUPtrLink *)0x0) {
      pJVar3 = pJVar1->mpNext;
      forceDeleteEmitter(this,(JPABaseEmitter *)pJVar1->mpData);
      pJVar1 = pJVar3;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JPAEmitterManager::clearResourceManager(unsigned char) */

void __thiscall JPAEmitterManager::clearResourceManager(JPAEmitterManager *this,uchar param_1)

{
  JPABaseEmitter **ppJVar1;
  ulong uVar2;
  JSUPtrLink *pJVar3;
  byte bVar4;
  JSUPtrLink *pJVar5;
  
  if (7 < param_1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JPAEmitterManager.cpp",0x14b,"rmID < 8");
    m_Do_printf::OSPanic("JPAEmitterManager.cpp",0x14b,&DAT_80366939);
  }
  for (bVar4 = 0; bVar4 < 0x10; bVar4 = bVar4 + 1) {
    pJVar3 = this->mPtrLists[bVar4].mpHead;
    while (pJVar3 != (JSUPtrLink *)0x0) {
      pJVar5 = pJVar3->mpNext;
      ppJVar1 = (JPABaseEmitter **)&pJVar3->mpData;
      pJVar3 = pJVar5;
      if (param_1 == (*ppJVar1)->mResMgrID) {
        forceDeleteEmitter(this,*ppJVar1);
      }
    }
  }
  *(undefined4 *)((int)this->mPtrLists + (uint)param_1 * 4 + -0x20) = 0;
  return;
}


/* __thiscall JPAFieldData::~JPAFieldData(void) */

void __thiscall JPAFieldData::_JPAFieldData(JPAFieldData *this)

{
  short in_r4;
  
  if (this != (JPAFieldData *)0x0) {
    this->vtbl = &__vt;
    if (this != (JPAFieldData *)&DAT_fffffff8) {
      JSUPtrLink::_JSUPtrLink(&this->mLink);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPAFieldData::JPAFieldData(void) */

void __thiscall JPAFieldData::JPAFieldData(JPAFieldData *this)

{
  this->vtbl = &__vt;
  JSUPtrLink::JSUPtrLink(&this->mLink,this);
  return;
}


/* __thiscall JPABaseEmitter::~JPABaseEmitter(void) */

void __thiscall JPABaseEmitter::_JPABaseEmitter(JPABaseEmitter *this)

{
  short in_r4;
  
  if (this != (JPABaseEmitter *)0x0) {
    if (this != (JPABaseEmitter *)0xfffffe78) {
      JSUPtrList::_JSUPtrList(&this->mChildParticles);
    }
    if (this != (JPABaseEmitter *)0xfffffe84) {
      JSUPtrList::_JSUPtrList(&this->mActiveParticles);
    }
    if ((this != (JPABaseEmitter *)0xfffffe94) && (this != (JPABaseEmitter *)0xfffffe94)) {
      JSUPtrList::_JSUPtrList(&(this->mFieldManager).mList);
    }
    if (this != (JPABaseEmitter *)0xffffff70) {
      JSUPtrLink::_JSUPtrLink(&this->mLink);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPABaseEmitter::JPABaseEmitter(void) */

void __thiscall JPABaseEmitter::JPABaseEmitter(JPABaseEmitter *this)

{
  float fVar1;
  
  JSUPtrLink::JSUPtrLink(&this->mLink,this);
  fVar1 = JPABase::0_0;
  this->mTick = JPABase::0_0;
  this->mTime = fVar1;
  JSUPtrList::initiate(&(this->mFieldManager).mList);
  JSUPtrList::initiate(&this->mActiveParticles);
  JSUPtrList::initiate(&this->mChildParticles);
  JKernel::JMath::TRandom_fast_::TRandom_fast_(&this->mRandomSeed,0);
  return;
}


/* __thiscall JPABaseParticle::~JPABaseParticle(void) */

void __thiscall JPABaseParticle::_JPABaseParticle(JPABaseParticle *this)

{
  short in_r4;
  
  if (this != (JPABaseParticle *)0x0) {
    if (this != (JPABaseParticle *)0x0) {
      JSUPtrLink::_JSUPtrLink(&this->mLink);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPABaseParticle::JPABaseParticle(void) */

void __thiscall JPABaseParticle::JPABaseParticle(JPABaseParticle *this)

{
  JSUPtrLink::JSUPtrLink(&this->mLink,this);
  this->mCurFrame = JPABase::0_0;
  return;
}


/* __thiscall JSUList<JPABaseEmitter>::JSUList(void) */

JSUList_JPABaseEmitter_ * __thiscall JSUList<JPABaseEmitter>::JSUList(JSUList_JPABaseEmitter_ *this)

{
  JSUPtrList::initiate((JSUPtrList *)this);
  return this;
}


/* __thiscall JSUList<JPABaseEmitter>::~JSUList(void) */

JSUList_JPABaseEmitter_ * __thiscall
JSUList<JPABaseEmitter>::_JSUList(JSUList_JPABaseEmitter_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JPABaseEmitter_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

