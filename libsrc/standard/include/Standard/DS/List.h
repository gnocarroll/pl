#pragma once

#include "Alg.h"
#include "DS/Option.h"
#include "IntDef.h"
#include "Util/Util.h"

namespace DS {

	template <typename T>
	class List {
		constexpr static USize GROW_FACTOR = 2;

		T* buffer = nullptr;

		USize used = 0;
		USize capacity = 0;

		void initBufferWithCapacity(USize capacity) {
			buffer = new T[capacity];

			this->capacity = capacity;
		}

		void resizeIfNecessary() {
			if (used < capacity) return;

			capacity *= GROW_FACTOR;

			T* newBuffer = new T[capacity];

			for (USize i = 0; i < used; i++) {
				newBuffer[i] = Util::move(buffer[i]);
			}

			delete[] buffer;

			buffer = newBuffer;
		}

	public:

		constexpr List() {}

		List(USize size) {
			initBufferWithCapacity(size);

			used = size;

			// default init all

			for (auto& element : *this) {
				element = T();
			}
		}

		List(List& other) {
			initBufferWithCapacity(other.used);

			used = other.used;

			for (USize i = 0; i < used; i++) {
				buffer[i] = other[i];
			}
		}
		List(List&& other) {
			buffer = other.buffer;
			used = other.used;
			capacity = other.capacity;

			other.buffer = nullptr;
			other.used = 0;
			other.capacity = 0;
		}

		T* begin() const {
			return buffer;
		}
		T* end() const {
			return buffer + used;
		}

		USize size() const {
			return used;
		}

		void push(T&& newElement) {
			resizeIfNecessary();

			buffer[used] = Util::move(newElement);

			used++;
		}

		void pushCopy(T newElement) {
			resizeIfNecessary();

			buffer[used] = Util::move(newElement);

			used++;
		}

		Option<T> pop() {
			if (used == 0) return {};

			used--;
			
			return Util::move(buffer[used]);
		}

		const T& operator[](USize index) const {
			return buffer[index];
		}

		T& operator[](USize index) {
			return buffer[index];
		}
	};

}