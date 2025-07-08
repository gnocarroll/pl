#include "Constants.h"

#if defined(__linux__)
#include <unistd.h>
#elif defined(_WIN32)
#include <sysinfoapi.h>
#endif

#ifdef PAGE_SIZE
#undef PAGE_SIZE
#endif

namespace Constants {
#if defined(_POSIX_VERSION)
	size_t PAGE_SIZE = (size_t) get_page_size();
#elif defined(_WIN32)
	static size_t getPageSizeWin32() {
		SYSTEM_INFO systemInfo;

		GetNativeSystemInfo(&systemInfo);

		return (size_t) systemInfo.dwPageSize;
	}

	size_t PAGE_SIZE = getPageSizeWin32();
#endif
}