#include "Allocator/Allocator.h"

#include "Constants.h"

namespace Allocator {
	static size_t REQUEST_PAGES = 1;

	size_t ARENA_SIZE = REQUEST_PAGES * Constants::PAGE_SIZE;
}