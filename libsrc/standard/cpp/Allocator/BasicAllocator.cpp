#include "Allocator/BasicAllocator.h"

#if defined(_WIN32)
#include <heapapi.h>
#else

#endif

#include "Constants.h"
#include "Util/Util.h"

namespace Allocator {
	static USize REQUEST_PAGES = 1;

	USize ARENA_SIZE = REQUEST_PAGES * Constants::PAGE_SIZE;

	MemoryRegion BasicAllocator::getMemFromOS(USize bytes) {
		MemoryRegion ret;

		bytes = Util::roundUpToMultiple(bytes, ARENA_SIZE);

#if defined(_WIN32)
		// WIN32 implementation
		static HANDLE processHeap = GetProcessHeap();

		LPVOID newMem = HeapAlloc(
			processHeap,
			0,
			bytes
		);

		if (newMem != NULL) {
			ret.size = bytes;
			ret.ptr = (void*)newMem;
		}
#else
		// other

#endif


		return ret;
	}
}