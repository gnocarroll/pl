#pragma once

#include "Constants.h"
#include "IntDef.h"

using namespace IntDef;

namespace Allocator {
	/// <summary>
	/// size of requests made to OS for more memory
	/// </summary>
	extern USize ARENA_SIZE;

	class BasicAllocator {
		struct BlockHeader {
			static constexpr USize N_FLAG_BITS = 4;

			static constexpr USize FLAGS_MASK = (1 << N_FLAG_BITS) - 1;
			static constexpr USize SIZE_MASK = (~FLAGS_MASK);

			enum BlockFlags {
				Free
			};

			USize sizeAndFlags = sizeof(BlockHeader);
			USize leftSize = 0;

			union {
				BlockHeader* nextHeader = nullptr;
				char marker;
			};

			char* data() {
				return &marker;
			}

			USize getSize() {
				return sizeAndFlags & SIZE_MASK;
			}
			USize getFlags() {
				return sizeAndFlags & FLAGS_MASK;
			}
			USize getLeftSize() {
				return leftSize;
			}
			void setLeftSize(USize leftSize) {
				this->leftSize = leftSize;
			}
			void setSize(USize size) {
				sizeAndFlags &= (size & SIZE_MASK);
			}
			void setFlags(USize flags) {
				sizeAndFlags &= (flags & FLAGS_MASK);
			}
		};

		

	public:
		BasicAllocator() {}

		void* alloc(USize count);
		void* alignedAlloc(USize alignment, USize count);
		void free(void* ptr);
	};
}