#pragma once

#include <dolphin/types.h>
namespace os {

typedef struct OSFontHeader {
	u16 fontType;	// font type
	u16 firstChar;	// the first character code defined in the font
	u16 lastChar;	// the last character code defined in the font
	u16 invalChar;	// the font code to be substituted for invalid characters
	u16 ascent;		// the ascent (units above the base line) of characters
	u16 descent;	// the descent (units below the base line) of characters
	u16 width;		// the width of the widest character
	u16 leading;	// the leading (space) between rows

	u16 cellWidth;	  // the cell (a single character) width in a sheet
	u16 cellHeight;	  // the cell (a single character) height in a sheet
	u32 sheetSize;	  // the size of a sheet in bytes
	u16 sheetFormat;  // the texture format of a sheet (GX_TF_*)
	u16 sheetColumn;  // the number of characters in a raw
	u16 sheetRow;	  // the number of lines in a sheet
	u16 sheetWidth;	  // the sheet width (texture width)
	//32B

	u16 sheetHeight;  // the sheet height (texture height)
	u16 widthTable;	  // offset to character width table (const)

	u32 sheetImage;		// offset to sheet image
	u32 sheetFullSize;	// the size of all sheets

	u8 c0;	// font color table
	u8 c1;
	u8 c2;
	u8 c3;
	// 48B
} OSFontHeader;

//
// Common functions
//

// For OSGetFontEncode()
#define OS_FONT_ENCODE_ANSI 0u
#define OS_FONT_ENCODE_SJIS 1u
#define OS_FONT_ENCODE_UTF8 3u	 // UTF-8 [RFC 3629]
#define OS_FONT_ENCODE_UTF16 4u	 // UTF-16BE [RFC 2781]
#define OS_FONT_ENCODE_UTF32 5u	 // UTF-32
#define OS_FONT_ENCODE_MAX 5u
#define OS_FONT_ENCODE_VOID 0xffffu

#define OS_FONT_PROPORTIONAL FALSE
#define OS_FONT_FIXED TRUE

u16 OSGetFontEncode(void);
u16 OSSetFontEncode(u16 encode);

char* OSGetFontWidth(const char* string, s32* width);

//
// High level functions
//

// For OSInitFont(fontData)
#define OS_FONT_SIZE_ANSI (288 + 131072)	// 1 sheet
#define OS_FONT_SIZE_SJIS (3840 + 1179648)	// 9 sheets
#define OS_FONT_SIZE_UTF (OS_FONT_SIZE_ANSI + OS_FONT_SIZE_SJIS)

BOOL OSInitFont(OSFontHeader* fontData);
char* OSGetFontTexture(const char* string, void** image, s32* x, s32* y, s32* width);

//
// Low level functions
//

// For OSLoadFont(*, temp)
#define OS_FONT_ROM_SIZE_ANSI 12288	  // 0x03000
#define OS_FONT_ROM_SIZE_SJIS 315392  // 0x4D000
#define OS_FONT_ROM_SIZE_UTF OS_FONT_ROM_SIZE_SJIS

// For OSLoadFont(fontData, *)
#define OS_FONT_DATA_SIZE_ANSI 65824
#define OS_FONT_DATA_SIZE_SJIS 593636
#define OS_FONT_DATA_SIZE_UTF (OS_FONT_DATA_SIZE_ANSI + OS_FONT_DATA_SIZE_SJIS)

u32 OSLoadFont(OSFontHeader* fontData, void* temp);
char* OSGetFontTexel(const char* string, void* image, s32 pos, s32 stride, s32* width);

//
// UTF functions
//
char* OSUTF32to8(u32 utf32, char* utf8);
char* OSUTF8to32(const char* utf8, u32* utf32);

u16* OSUTF32to16(u32 utf32, u16* utf16);
u16* OSUTF16to32(const u16* utf16, u32* utf32);

u8 OSUTF32toANSI(u32 utf32);
u32 OSANSItoUTF32(u8 ansi);

u16 OSUTF32toSJIS(u32 utf32);
u32 OSSJIStoUTF32(u16 sjis);

BOOL OSSetFontWidth(BOOL fixed);
}