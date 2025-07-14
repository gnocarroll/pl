#pragma once

#include "IntDef.h"
#include "Util/Mem.h"

using namespace IntDef;

namespace DS {
    template <typename T>
    class GenericString {
        struct {
            bool isDataOnHeap = false;
            USize used = 0;
            USize capacity = 0;
            T *buffer = nullptr;
        }


        T *internalBuffer() {
            return (T*) &capacity;
        }

        USize getInternalBufferSize() {
            return (UIntPtr) &buffer + (UIntPtr) sizeof(T*) - (UIntPtr) internalBuffer();
        }

		void initBufferWithCapacity(USize capacity) {
			buffer = new T[capacity];

			this->capacity = capacity;
		}

    public:

        constexpr GenericString() {}

        GenericString(const GenericString<T>& other) {
            if (!other.isDataOnHeap) {

            }

            used = other.used;
            capacity = used;

            initBufferWithCapacity(capacity);

            Util::MemoryCopy(buffer, other.buffer, used);
        }

        char *begin() const {
            return 
        }

        GenericString(GenericString<T>&& other) {
            used = other.used;
            capacity = other.capacity;
        }
    };
}