#include "Allocator/malloc.h"

#include <errno.h>

#include "Allocator/Allocator.h"
#include "Constants.h"
#include "Util/Mem.h"

static Allocator::BasicAllocator cAllocator;

template <typename T>
static bool isPowerOf2(T x) {
	return x & (x - 1) == 0;
}

extern "C" void* malloc(USize size) {
	return cAllocator.alloc(size);
}

extern "C" void free(void* ptr) {
	cAllocator.free(ptr);
}

extern "C" void* calloc(USize n, USize size) {
	USize bytes = n * size;
	
	void* ret = malloc(bytes);

	if (!ret) return ret;

	Util::MemorySet(ret, 0, bytes);

	return ret;
}

extern "C" void* realloc(void* ptr, USize size) {
	// TODO: implement
	return nullptr;
}

extern "C" void *aligned_alloc(USize alignment, USize size) {
	if (!isPowerOf2(alignment)) {
		errno = EINVAL;

		return nullptr;
	}

	return memalign(alignment, size);
}

extern "C" int posix_memalign(void** memptr, USize alignment, USize size) {
	if (alignment % sizeof(void*) != 0 || !isPowerOf2(alignment)) {
		errno = EINVAL;

		return EINVAL;
	}
	
	void* newMem = memalign(alignment, size);

	if (!newMem) {
		return ENOMEM;
	}

	*memptr = newMem;

	return 0;
}

// deprecated/obsolete below

extern "C" void* valloc(USize size) {
	return memalign(Constants::PAGE_SIZE, size);
}

extern "C" void* memalign(USize alignment, USize size) {
	return cAllocator.alignedAlloc(alignment, size);
}

extern "C" void* pvalloc(USize size) {
	// round up to next multiple of page size

	size = ((size - 1) / Constants::PAGE_SIZE + 1) * Constants::PAGE_SIZE;

	return valloc(size);
}