#pragma once

#include <initializer_list>

#include <Alg.h>
#include <DS/Option.h>
#include <Util.h>

namespace DS {

	template <typename T>
	class List {
		constexpr static size_t GROW_FACTOR = 2;

		T* buffer = nullptr;

		size_t used = 0;
		size_t capacity = 0;

		void initBufferWithCapacity(size_t capacity) {
			buffer = new T[capacity];

			this->capacity = capacity;
		}

		void resizeIfNecessary() {
			if (used < capacity) return;

			capacity *= GROW_FACTOR;

			T* newBuffer = new T[capacity];

			for (size_t i = 0; i < used; i++) {
				newBuffer[i] = Util::move(buffer[i]);
			}

			delete[] buffer;

			buffer = newBuffer;
		}

	public:

		constexpr List() {}

		List(size_t size) {
			initBufferWithCapacity(size);

			used = size;

			// default init all

			for (auto& element : *this) {
				element = T();
			}
		}

		List(std::initializer_list<T> elements) {
			initBufferWithCapacity(elements.size());

			size_t index = 0;

			for (const auto& element : elements) {
				buffer[index] = Util::move(element);

				index++;
			}

			used = elements.size();
		}

		List(List& other) {
			initBufferWithCapacity(other.used);

			used = other.used;

			for (size_t i = 0; i < used; i++) {
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

		size_t size() const {
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

		const T& operator[](size_t index) const {
			return buffer[index];
		}

		T& operator[](size_t index) {
			return buffer[index];
		}
	};

}