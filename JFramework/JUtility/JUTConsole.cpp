#include "JUTConsole.h"

#include "JUTDirectPrint.h"
#include "JUTVideo.h"
#include "JUTAssert.h"
#include <machine/dolphin/printf.h>

uint JUTConsole::getObjectSizeFromBufferSize(uint param_1, uint param_2) {
	return (param_1 + 2) * param_2 + 0x68;
}

JUTConsole::JUTConsole(uint param_1, uint param_2, bool own) {
	this->color = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->color2 = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
	this->ownmem = own;
	this->beginning_of_line_x = param_1;
	this->lines = param_2;
	this->console_position_x = 0x1e;
	this->console_position_y = 0x32;
	this->maxlines = 0x14;
	if (this->lines < this->maxlines) {
		this->maxlines = this->lines;
	}
	this->font = nullptr;
	this->candisplay = 1;
	this->osreportdebug = 0;
	this->shouldwrap = 0;
	this->outputwhere = 1;
	this->color = (gx::GXColor){0xff, 0xff, 0xff, 100};
	this->color2 = (gx::GXColor){0xff, 0xff, 0xff, 0xe6};
}

JUTConsole::~JUTConsole() {
	if (!JUTConsoleManager::sManager) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x96, "JUTConsoleManager::getManager()");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x96, "Halt");
	}
	JUTConsoleManager::sManager->removeConsole(this);
}

void JUTConsole::doDraw(JUTConsole::EConsoleType param_1) {
	uint uVar1;
	gx::GXColor *colorptr;
	size_t stringlen;
	int iVar2;
	JUTFont *fontptr;
	uint uVar3;
	char *stringtoprint;
	undefined4 uVar4;
	undefined8 in_f27;
	double scaley;
	undefined8 in_f28;
	double scalex;
	undefined8 in_f29;
	double dVar5;
	undefined8 in_f30;
	double dVar6;
	undefined8 in_f31;
	double lspacemargin;
	gx::GXColor local_284;
	undefined4 local_280;
	gx::GXColor local_27c;
	undefined4 local_278;
	gx::GXColor local_274;
	undefined4 local_270;
	gx::GXColor local_26c;
	TColor color;
	struct J2DOrthoGraph local_264;
	struct J2DOrthoGraph local_190;
	float local_b8;
	uint uStack180;
	undefined4 local_b0;
	uint uStack172;
	long long local_a8;
	undefined4 local_a0;
	uint uStack156;
	undefined4 local_98;
	uint uStack148;
	long long local_90;
	undefined4 local_88;
	uint uStack132;
	double local_80;
	double local_78;
	undefined4 uStack112;
	uint maxlinesfloat;
	undefined auStack72[16];
	undefined auStack56[16];
	undefined auStack40[16];
	undefined auStack24[16];
	undefined auStack8[8];

	uVar4 = 0;
	if ((this->candisplay != '\0') &&
		(((this->font != (JUTFont *)0x0 || (param_1 == 2)) &&
		  (maxlinesfloat = this->maxlines, maxlinesfloat != 0)))) {
		lspacemargin = (double)(this->linespacing + 2.0);
		if (param_1 == 2) {
			uStack112 = 0x43300000;
			iVar2 = (int)(lspacemargin * maxlinesfloat);
			local_78 = iVar2;
			JUTDirectPrint::sDirectPrint->erase(this->console_position_x + -3,
												this->console_position_y + -2, this->beginning_of_line_x * 6 + 6, iVar2 + 4);
		} else {
			if (JUTVideo::sManager == (JUTVideo *)0x0) {
				struct J2DOrthoGraph local_190(0.0, 0.0, 640.0, 480.0, -1.0, 1.0);
				local_190.setPort();
				//local_190.parent.vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
			} else {
				uStack180 = (uint)JUTVideo::sManager->mpRenderMode->fbWidth;
				local_b8 = 176.0;
				uStack172 = (uint)JUTVideo::sManager->mpRenderMode->efbHeight;
				local_b0 = 0x43300000;
				struct J2DOrthoGraph local_264(0.0, 0.0, uStack180, uStack172, -1.0, 1.0);
				local_264.setPort();
				//local_264.parent.vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
			}
			if (param_1 == 0) {
				colorptr = &this->color;
			} else {
				colorptr = &this->color2;
			}
			color = (TColor)colorptr;
			local_b8 = 176.0;
			uStack156 = this->console_position_y - lspacemargin;
			maxlinesfloat = (uint)(lspacemargin * this->maxlines);
			J2DGraph::J2DFillBox((float)this->console_position_x - 2,
								 (float)(this->console_position_y - lspacemargin),
								 (float)(this->charspacing * beginning_of_line_x) + 4.0f, (float)maxlinesfloat,
								 color);
			this->font->setGX();
			if (param_1) {
				local_284 = (gx::GXColor){0xe6, 0xe6, 0xe6, 0xff};
				this->font->setCharColor(&local_284);
			} else {
				iVar2 = this->totalavailabl - this->caretheight;
				if (iVar2 < 0) {
					iVar2 = iVar2 + this->lines;
				}
				if ((int)((iVar2 - this->maxlines) + 1) < 1) {
					local_270 = 0xffffffff;
					local_26c = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
					this->font->setCharColor(&local_26c);
				} else if (this->caretheight == this->totalused) {
					local_278 = 0xffe6e6ff;
					local_274 = (gx::GXColor){0xff, 0xe6, 0xe6, 0xff};
					this->font->setCharColor(&local_274);
				} else {
					local_280 = 0xe6e6ffff;
					local_27c = (gx::GXColor){0xe6, 0xe6, 0xff, 0xff};
					this->font->setCharColor(&local_27c);
				}
			}
		}
		uVar1 = this->caretheight;
		uVar3 = 0;
		while (stringtoprint = this->consolefreebuffer + (this->beginning_of_line_x + 2) * uVar1 + 1,
			   stringtoprint[-1] != '\0') {
			if (param_1 == 2) {
				maxlinesfloat = this->console_position_y;
				local_78 = uVar3;
				iVar2 = maxlinesfloat + uVar3 * lspacemargin;
				JUTDirectPrint::sDirectPrint->drawString((ushort)this->console_position_x, (ushort)iVar2, stringtoprint);
			} else {
				scaley = (double)this->linespacing;
				scalex = (double)this->charspacing;
				maxlinesfloat = this->console_position_y;
				local_80 = this->console_position_x;
				fontptr = this->font;
				stringlen = strlen(stringtoprint);
				fontptr->drawString_size_scale((float)console_position_x, (float)maxlinesfloat + uVar3 * lspacemargin, (float)scalex, (float)scaley, stringtoprint,
											   stringlen, true);
			}
			uVar1 = uVar1 + 1;
			uVar3 = uVar3 + 1;
			if ((this->maxlines <= uVar3) || (uVar1 == this->totalused))
				break;
		}
	}
	return;
}

void JUTConsole::clear() {
	uint uVar1;

	this->caretheight = 0;
	this->totalused = 0;
	this->totalavailabl = 0;
	this->caret_x = 0;
	for (uVar1 = 0; uVar1 < this->lines; uVar1 = uVar1 + 1) {
		this->consolefreebuffer[(this->beginning_of_line_x + 2) * uVar1] = 0;
	}
	*this->consolefreebuffer = 0xff;
	this->consolefreebuffer[1] = 0;
	return;
}

void JUTConsole::print_f(char *param_1, ...) {
	va_list ap;
	va_start(ap, param_1);

	JUtility::JUTConsole_print_f_va_(this, param_1, ap);
	va_end(ap);
}

void JUTConsole::print(char *param_1) {
	char cVar1;
	uint uVar2;
	char *pcVar3;

	if ((this->outputwhere & 2) != 0) {
		m_Do_printf::OSReport("%s");
	}
	if ((this->outputwhere & 1) != 0) {
		pcVar3 = this->consolefreebuffer +
				 this->caret_x + (this->beginning_of_line_x + 2) * this->totalavailabl + 1;
		while ((cVar1 = *param_1, cVar1 != '\0' &&
									  ((this->shouldwrap == '\0' ||
										(uVar2 = this->totalavailabl + 1,
										 this->totalused != uVar2))))) {
			if (cVar1 == '\n') {
				this->caret_x = this->beginning_of_line_x;
				param_1 = param_1 + 1;
			} else if (cVar1 == '\t') {
				param_1 = param_1 + 1;
				do {
					if (this->beginning_of_line_x <= (uint)this->caret_x)
						break;
					*pcVar3 = ' ';
					this->caret_x = this->caret_x + 1;
					uVar2 = this->caret_x >> 0x1f;
					pcVar3 = pcVar3 + 1;
				} while ((uVar2 * 8 | this->caret_x * 0x20000000 + uVar2 >> 0x1d) != uVar2);
			} else if ((this->font) ||
					   (cVar1 = (this->font->isLeadByte(cVar1), cVar1 == '\0'))) {
				*pcVar3 = *param_1;
				this->caret_x = this->caret_x + 1;
				param_1 = param_1 + 1;
				pcVar3 = pcVar3 + 1;
			} else if (this->caret_x + 1U < this->beginning_of_line_x) {
				*pcVar3 = *param_1;
				pcVar3[1] = param_1[1];
				this->caret_x = this->caret_x + 1;
				this->caret_x = this->caret_x + 1;
				param_1 = param_1 + 2;
				pcVar3 = pcVar3 + 2;
			} else {
				*pcVar3 = '\0';
				this->caret_x = this->caret_x + 1;
				pcVar3 = pcVar3 + 1;
			}
			if (this->beginning_of_line_x <= (uint)this->caret_x) {
				*pcVar3 = '\0';
				uVar2 = this->totalavailabl + 1;
				this->totalavailabl = uVar2;
				this->caret_x = 0;
				this->consolefreebuffer[(this->beginning_of_line_x + 2) * this->totalavailabl] = 0xff;
				pcVar3 = this->consolefreebuffer + (this->beginning_of_line_x + 2) * this->totalavailabl + 1;
				*pcVar3 = '\0';
				uVar2 = this->totalavailabl - this->caretheight;
				if ((int)uVar2 < 0) {
					uVar2 = uVar2 + this->lines;
				}
				if (uVar2 == this->maxlines) {
					uVar2 = this->caretheight + 1;
					this->caretheight = uVar2;
				}
				if (this->totalavailabl == this->totalused) {
					uVar2 = this->totalused + 1;
					this->totalused = uVar2;
				}
				if (this->totalavailabl == this->caretheight) {
					uVar2 = this->caretheight + 1;
					this->caretheight = uVar2;
				}
			}
		}
		*pcVar3 = '\0';
	}
	return;
}

void JUTConsole::dumpToTerminal(uint param_1) {
	uint uVar1;
	uint uVar2;
	int iVar3;

	if (param_1 != 0) {
		uVar1 = this->totalused;
		if (param_1 != 0xffffffff) {
			uVar1 = this->totalavailabl;
			if (param_1 != 0) {
				do {
					uVar2 = uVar1 - 1;
					if ((int)uVar2 < 0) {
						uVar2 = this->lines - 1;
					}
				} while (((this->consolefreebuffer[(this->beginning_of_line_x + 2) * uVar2] != '\0') &&
						  (uVar1 = uVar2, uVar2 != this->totalused)) &&
						 (param_1 = param_1 - 1, param_1 != 0));
			}
		}
		iVar3 = 0;
		m_Do_printf::OSReport("\n:::dump of console[%x]--------------------------------\n", this);
		do {
			if ((this->consolefreebuffer + (this->beginning_of_line_x + 2) * uVar1 + 1)[-1] == '\0')
				break;
			if (this->osreportdebug == '\0') {
				m_Do_printf::OSReport("%s\n", this->consolefreebuffer + (this->beginning_of_line_x + 2) * uVar1 + 1);
			} else {
				m_Do_printf::OSReport("[%03d] %s\n", iVar3);
			}
			uVar1++;
			iVar3++;
		} while (uVar1 != this->totalused);
		m_Do_printf::OSReport(":::dump of console[%x] END----------------------------\n", this);
	}
	return;
}

void JUTConsole::scroll(int param_1) {
	int iVar1;

	if (param_1 < 0) {
		iVar1 = this->caretheight - this->totalused;
		if (iVar1 < 0) {
			iVar1 = iVar1 + this->lines;
		}
		if (param_1 < -iVar1) {
			param_1 = -iVar1;
		}
	} else if (0 < param_1) {
		iVar1 = this->totalavailabl - this->totalused;
		if (iVar1 < 0) {
			iVar1 = iVar1 + this->lines;
		}
		if (this->maxlines < iVar1 + 1U) {
			iVar1 = this->totalavailabl - this->caretheight;
			if (iVar1 < 0) {
				iVar1 = iVar1 + this->lines;
			}
			iVar1 = (iVar1 - this->maxlines) + 1;
			if (iVar1 < param_1) {
				param_1 = iVar1;
			}
		} else {
			param_1 = 0;
		}
	}
	this->caretheight = this->caretheight + param_1;
	if (this->caretheight < 0) {
		this->caretheight = this->caretheight + this->lines;
	}
	if (this->lines <= (uint)this->caretheight) {
		this->caretheight = this->caretheight - this->lines;
		return;
	}
	return;
}

int JUTConsole::getUsedLine() {
	int iVar1;

	iVar1 = this->totalavailabl - this->totalused;
	if (-1 < iVar1) {
		return iVar1;
	}
	return iVar1 + this->lines;
}

int JUTConsole::getLineOffset() {
	int iVar1;

	iVar1 = this->caretheight - this->totalused;
	if (-1 < iVar1) {
		return iVar1;
	}
	return iVar1 + this->lines;
}

JUTConsole *JUTConsole::create(uint param_1, uint param_2, JKRHeap *param_3) {
	ulong uVar1;
	JUTConsole *selft;
	JUTConsole *self3;
	char *pcVar2;
	JUTConsoleManager *self;

	self = JUTConsoleManager::sManager;
	pcVar2 = (char *)param_3;
	if (JUTConsoleManager::sManager == (JUTConsoleManager *)0x0) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x21, "pManager != 0");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x21, "Halt");
	}
	uVar1 = JUTConsole::getObjectSizeFromBufferSize(param_2, (uint)pcVar2);
	selft = (JUTConsole *)JKRHeap::alloc(uVar1, 0, param_3);
	self3 = selft;
	self3 = new (selft) JUTConsole(param_1, param_2, true);
	self3->consolefreebuffer = (undefined *)(selft + 1);
	self3->clear();
	self->appendConsole(self3);
	return self3;
}

uint JUTConsole::getLineFromObjectSize(ulong param_1, uint param_2) {
	return (param_1 - 0x68) / (param_2 + 2);
}

JUTConsole *JUTConsole::create(uint rsize, void *buffer, ulong param_3) {
	ulong uVar1;
	uint uVar2;
	JUTConsole *self2;
	JUTConsoleManager *self;

	self = JUTConsoleManager::sManager;
	if (JUTConsoleManager::sManager == (JUTConsoleManager *)0x0) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x3b, "pManager != 0");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x3b, "Halt");
	}
	if (((uint)buffer & 3) != 0) {
		JUTAssertion::getSDevice()->showAssert("JUTConsole.cpp", 0x3e, "( (u32)buffer & 0x3 ) == 0");
		m_Do_printf::OSPanic("JUTConsole.cpp", 0x3e, "Halt");
	}
	uVar2 = JUTConsole::getLineFromObjectSize(param_3, rsize);
	self2 = (JUTConsole *)buffer;
	new (buffer) JUTConsole(rsize, uVar2, false);
	self2->consolefreebuffer = (undefined *)((int)buffer + 0x68);
	self2->clear();
	self->appendConsole(self2);
	return self2;
}
