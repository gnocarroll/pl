#include "Util/CMem.h"

#include "Util/Mem.h"

void* memcpy(void* dest, const void* src, size_t count) {
	return Util::MemoryCopy(dest, src, count);
}

void* memove(void* dest, const void* src, size_t count) {
	return Util::MemoryMove(dest, src, count);
}

void* memset(void* dest, int c, size_t count) {
	return Util::MemorySet(dest, c, count);
}