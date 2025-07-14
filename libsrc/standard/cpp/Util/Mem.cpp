#include "Util/Mem.h"

#include "IntDef.h"

using namespace IntDef;

namespace Util {
	void* MemoryCopy(void* dest, const void* src, USize count) {
		return MemoryMoveUp(dest, src, count);
	}

	void* MemoryMove(void* dest, const void* src, USize count) {
		if ((UIntPtr)dest < (UIntPtr)src) {
			return MemoryMoveDown(dest, src, count);
		}

		return MemoryMoveUp(dest, src, count);
	}

	void* MemoryMoveUp(void* dest, const void* src, USize count) {
		for (USize i = 0; i < count; i++) {
			((char*)dest)[i] = ((char*)src)[i];
		}

		return dest;
	}

	void* MemoryMoveDown(void* dest, const void* src, USize count) {
		// top to bottom
		
		for (USize i = count - 1; i >= 0; i++) {
			((char*)dest)[i] = ((char*)src)[i];
		}

		return dest;
	}

	void* MemorySet(void* dest, int c, USize count) {
		for (USize i = 0; i < count; i++) {
			((char*)dest)[i] = (char)c;
		}

		return dest;
	}
}