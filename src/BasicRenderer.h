#pragma once
#include "math.h"
#include "Framebuffer.h"
#include "BasicRenderer.cpp"
#include "simpleFonts.h"
#include "math.h"
#include "main.c"
#include "kernel.cpp"


class BasicRenderer{
    public:
    Point CursorPosition;
    void Print(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, const char* str
    void putChar(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int x0ff, unsigned int y0ff);
};