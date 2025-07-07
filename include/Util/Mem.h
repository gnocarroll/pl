#pragma once

namespace Util {
	void* MemoryCopy(void* dest, const void* src, size_t count);
	void* MemoryMove(void* dest, const void* src, size_t count);
	void* MemorySet(void* dest, int c, size_t count);
}