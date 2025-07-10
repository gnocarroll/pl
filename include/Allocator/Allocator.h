#pragma once

#include <stddef.h>

#include "Constants.h"

namespace Allocator {
	/// <summary>
	/// size of requests made to OS for more memory
	/// </summary>
	extern size_t ARENA_SIZE;

	class BasicAllocator {
		struct BlockHeader {
			static constexpr size_t FLAGS_MASK = 0b1111;
			static inline size_t SIZE_MASK = ~FLAGS_MASK;

			size_t sizeAndFlags;
			size_t leftSize;

			union {
				BlockHeader* nextHeader;
				char marker;
			};

			char* data() {
				return &marker;
			}

			size_t getSize() {
				return sizeAndFlags & SIZE_MASK;
			}
			size_t getFlags() {
				return sizeAndFlags & FLAGS_MASK;
			}
			size_t getLeftSize() {
				return leftSize;
			}
			void setLeftSize(size_t leftSize) {
				this->leftSize = leftSize;
			}
			void setSize(size_t size) {
				sizeAndFlags &= (size & SIZE_MASK);
			}
			void setFlags(size_t flags) {
				sizeAndFlags &= (flags & FLAGS_MASK);
			}
			
		};

		

	public:
		BasicAllocator() {}

		void* alloc(size_t count);
		void* alignedAlloc(size_t alignment, size_t count);
		void free(void* ptr);
	};
}