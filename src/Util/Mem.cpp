#include "Util/Mem.h"

#include <stdint.h>

namespace Util {
	void* MemoryCopy(void* dest, const void* src, size_t count) {
		return MemoryMoveUp(dest, src, count);
	}

	void* MemoryMove(void* dest, const void* src, size_t count) {
		if ((uintptr_t)dest < (uintptr_t)src) {
			return MemoryMoveDown(dest, src, count);
		}

		return MemoryMoveUp(dest, src, count);
	}

	void* MemoryMoveUp(void* dest, const void* src, size_t count) {
		for (size_t i = 0; i < count; i++) {
			((char*)dest)[i] = ((char*)src)[i];
		}

		return dest;
	}

	void* MemoryMoveDown(void* dest, const void* src, size_t count) {
		// top to bottom
		
		for (size_t i = count - 1; i >= 0; i++) {
			((char*)dest)[i] = ((char*)src)[i];
		}

		return dest;
	}

	void* MemorySet(void* dest, int c, size_t count) {
		for (size_t i = 0; i < count; i++) {
			((char*)dest)[i] = (char)c;
		}

		return dest;
	}
}