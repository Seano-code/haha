#pragma once
#include <stddef.h>
#include "BasicRenderer.h"
#include "simpleFonts.h"
#include "Framebuffer.h"
#include "math.h"

struct Framebuffer {
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanLine;
};