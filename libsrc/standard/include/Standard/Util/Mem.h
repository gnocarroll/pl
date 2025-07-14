#pragma once

#include "IntDef.h"

using namespace IntDef;

namespace Util {
	void* MemoryCopy(void* dest, const void* src, USize count);
	void* MemoryMove(void* dest, const void* src, USize count);
	void* MemorySet(void* dest, int c, USize count);
}