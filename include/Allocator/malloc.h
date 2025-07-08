#pragma once

#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

	void* malloc(size_t size);

	void free(void* ptr);

	void* calloc(size_t n, size_t size);

	void* realloc(void* ptr, size_t size);

	void* aligned_alloc(size_t alignment, size_t size);

	int posix_memalign(void** memptr, size_t alignment, size_t size);

	// deprecated/obsolete below

	void* valloc(size_t size);

	void* memalign(size_t alignment, size_t size);

	void* pvalloc(size_t size);

#ifdef __cplusplus
}
#endif