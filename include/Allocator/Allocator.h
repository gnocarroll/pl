#pragma once

class Allocator {
public:
	Allocator() {}

	void* alloc(size_t count);
	void* alignedAlloc(size_t alignment, size_t count);
	void free(void* ptr);
};