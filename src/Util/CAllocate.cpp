#include "CAllocate.h"


extern "C" void* malloc(size_t size) {
	return nullptr;
}

extern "C" void free(void* ptr) {

}

extern "C" void* calloc(size_t n, size_t size) {
	void* ret = malloc(n * size);

	if (!ret) return ret;


}

extern "C" void* realloc(void* ptr, size_t size) {
	return nullptr;
}

extern "C" void *aligned_alloc(size_t alignment, size_t size) {
	return nullptr;
}

extern "C" int posix_memalign(void** memptr, size_t alignment, size_t size) {
	return 0;
}

// deprecated/obsolete below

extern "C" void* valloc(size_t size) {
	return nullptr;
}

extern "C" void* memalign(size_t alignment, size_t size) {
	return nullptr;
}

extern "C" void* pvalloc(size_t size) {
	return nullptr;
}