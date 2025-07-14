#include "Util/CMem.h"

#include "CIntDef.h"
#include "Util/Mem.h"

extern "C" {

	void* memcpy(void* dest, const void* src, USize count) {
		return Util::MemoryCopy(dest, src, count);
	}

	void* memmove(void* dest, const void* src, USize count) {
		return Util::MemoryMove(dest, src, count);
	}

	void* memset(void* dest, int c, USize count) {
		return Util::MemorySet(dest, c, count);
	}

}