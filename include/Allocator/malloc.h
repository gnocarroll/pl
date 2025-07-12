#pragma once

#include "CIntDef.h"

#ifdef __cplusplus
extern "C" {
#endif

	void* malloc(USize size);

	void free(void* ptr);

	void* calloc(USize n, USize size);

	void* realloc(void* ptr, USize size);

	void* aligned_alloc(USize alignment, USize size);

	int posix_memalign(void** memptr, USize alignment, USize size);

	// deprecated/obsolete below

	void* valloc(USize size);

	void* memalign(USize alignment, USize size);

	void* pvalloc(USize size);

#ifdef __cplusplus
}
#endif