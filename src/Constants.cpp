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
	USize PAGE_SIZE = (USize) get_page_size();
#elif defined(_WIN32)
	static USize getPageSizeWin32() {
		SYSTEM_INFO systemInfo;

		GetNativeSystemInfo(&systemInfo);

		return (USize) systemInfo.dwPageSize;
	}

	USize PAGE_SIZE = getPageSizeWin32();
#endif
}