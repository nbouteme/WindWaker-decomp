#include <d_a_mgameboard_static.h>
#include <daMgBoard_c.h>


/* __thiscall daMgBoard_c::checkClearGame(void) */

uint __thiscall daMgBoard_c::checkClearGame(daMgBoard_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros((uint)(this->mSeaFightGame).mAliveShipNum);
  return uVar1 >> 5;
}


/* __thiscall daMgBoard_c::getScore(void) */

byte __thiscall daMgBoard_c::getScore(daMgBoard_c *this)

{
  return (this->mSeaFightGame).mScore;
}


/* __thiscall daMgBoard_c::reqStartGame(void) */

void __thiscall daMgBoard_c::reqStartGame(daMgBoard_c *this)

{
  this->mbEndGame = 0;
  this->mbStartGame = 1;
  return;
}


/* __thiscall daMgBoard_c::checkEndGame(void) */

bool __thiscall daMgBoard_c::checkEndGame(daMgBoard_c *this)

{
  return this->mbEndGame != 0;
}


/* __thiscall daMgBoard_c::setGInfoDraw(void) */

void __thiscall daMgBoard_c::setGInfoDraw(daMgBoard_c *this)

{
  this->mbDraw = 1;
  return;
}


/* __thiscall daMgBoard_c::clrGInfoDraw(void) */

void __thiscall daMgBoard_c::clrGInfoDraw(daMgBoard_c *this)

{
  this->mbDraw = 0;
  return;
}

