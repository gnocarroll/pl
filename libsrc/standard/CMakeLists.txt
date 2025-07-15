add_library(Standard SHARED
    # Header files
    include/Standard/Allocator/BasicAllocator.h
    include/Standard/Allocator/malloc.h
    include/Standard/DS/List.h
    include/Standard/DS/Map.h
    include/Standard/DS/Option.h
    include/Standard/DS/String.h
    include/Standard/Util/CMem.h
    include/Standard/Util/Mem.h
    include/Standard/Util/Util.h
    include/Standard/Alg.h
    include/Standard/CIntDef.h
    include/Standard/Constants.h
    include/Standard/IntDef.h
    include/Standard/IO.h
    include/Standard/Meta.h

    # Source files
    src/Allocator/BasicAllocator.cpp
    src/Allocator/CAlloc.cpp
    src/Util/CMem.cpp
    src/Util/Mem.cpp
    src/Constants.cpp
    src/Util.cpp
)

target_include_directories(Standard PUBLIC include)