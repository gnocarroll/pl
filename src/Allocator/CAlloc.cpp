#include "Allocator/malloc.h"

#include <errno.h>

#include "Allocator/Allocator.h"
#include "Constants.h"
#include "Util/Mem.h"

static Allocator cAllocator;

template <typename T>
static bool isPowerOf2(T x) {
	return x & (x - 1) == 0;
}

extern "C" void* malloc(size_t size) {
	return cAllocator.alloc(size);
}

extern "C" void free(void* ptr) {
	cAllocator.free(ptr);
}

extern "C" void* calloc(size_t n, size_t size) {
	size_t bytes = n * size;
	
	void* ret = malloc(bytes);

	if (!ret) return ret;

	Util::MemorySet(ret, 0, bytes);

	return ret;
}

extern "C" void* realloc(void* ptr, size_t size) {
	// TODO: implement
	return nullptr;
}

extern "C" void *aligned_alloc(size_t alignment, size_t size) {
	if (!isPowerOf2(alignment)) {
		errno = EINVAL;

		return nullptr;
	}

	return memalign(alignment, size);
}

extern "C" int posix_memalign(void** memptr, size_t alignment, size_t size) {
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

extern "C" void* valloc(size_t size) {
	return memalign(Constants::PAGE_SIZE, size);
}

extern "C" void* memalign(size_t alignment, size_t size) {
	return cAllocator.alignedAlloc(alignment, size);
}

extern "C" void* pvalloc(size_t size) {
	// round up to next multiple of page size

	size = ((size - 1) / Constants::PAGE_SIZE + 1) * Constants::PAGE_SIZE;

	return valloc(size);
}