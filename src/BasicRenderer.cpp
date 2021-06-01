#include "BasicRenderer.h"
#include "simpleFonts.h"
#include "Framebuffer.h"
#include "math.h"
#include "main.c"
#include "kernel.cpp"


void BasicRenderer::Print(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, const char* str)
{
	
	char* chr = (char*)str;
	while(*chr != 0){
		putChar(framebuffer, psf1_font, colour, *chr, CursorPosition.X, CursorPosition.Y);
		CursorPosition.X+=8;
		if(CursorPosition.X + 8 > framebuffer->Width)
		{
			CursorPosition.X = 0;
			CursorPosition.Y += 16;
		}
		chr++;
	}
}

void BasicRenderer::putChar(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, char chr, unsigned int x0ff, unsigned int y0ff)
{
	unsigned int* pixPtr = (unsigned int*)framebuffer->BaseAddress;
	char* fontPtr = (char*)psf1_font->glyphBuffer + (chr * psf1_font->psf1_Header->charsize);
	for (unsigned long y  = y0ff; y < y0ff + 16; y++){
		for (unsigned long x = x0ff; x < x0ff+8; x++){
			if ((*fontPtr & (0b10000000 >> (x - x0ff))) > 0){
				*(unsigned int*)(pixPtr + x + (y * framebuffer->PixelsPerScanLine)) = colour;
			}


		}
		fontPtr++;
	}
}