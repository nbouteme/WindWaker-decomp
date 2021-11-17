#include <os/OSFont.h>


namespace os {

ushort OSGetFontEncode(void)

{
  if (fontEncode_80 < 2) {
    return fontEncode_80;
  }
  if (DAT_800000cc == 0) {
    fontEncode_80 = (ushort)((DAT_cc00206e & 2) != 0);
  }
  else {
    fontEncode_80 = 0;
  }
  return fontEncode_80;
}

