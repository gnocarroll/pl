#pragma once

#include "Constants.h"
#include "IntDef.h"

using namespace IntDef;

namespace Allocator {
	/// <summary>
	/// size of requests made to OS for more memory
	/// </summary>
	extern USize ARENA_SIZE;

	struct MemoryRegion {
		USize size = 0;
		void* ptr = nullptr;
	};

	class BasicAllocator {
		struct BlockMetadata {
			static constexpr USize N_FLAG_BITS = 4;

			static constexpr USize FLAGS_MASK = (1 << N_FLAG_BITS) - 1;
			static constexpr USize SIZE_MASK = (~FLAGS_MASK);

			enum class BlockState {
				Free = 0,
				Allocated = 1,
			};

			enum class EdgeBlock {
				Middle = 0,
				Edge = 1,
			};

			static constexpr USize STATE_FLAG_IDX = 0;
			static constexpr USize EDGE_FLAG_IDX = 1;
		
		private:
			USize sizeAndFlags = sizeof(BlockMetadata);
			USize leftSize = 0;

		public:
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

		struct BlockHeader {
			BlockMetadata metadata;

			union {
				BlockHeader* next = nullptr;
			};

			char* data() {
				return ((char*) this) + sizeof(BlockMetadata);
			}
		};

		MemoryRegion getMemFromOS(USize bytes);

		static constexpr USize N_FREE_LISTS = 17;
		static constexpr USize MIN_ALLOCATION_POW_2 = 4;

		BlockHeader sentinels[N_FREE_LISTS];

	public:
		BasicAllocator() {}

		void* alloc(USize count);
		void* alignedAlloc(USize alignment, USize count);
		void free(void* ptr);
	};
}