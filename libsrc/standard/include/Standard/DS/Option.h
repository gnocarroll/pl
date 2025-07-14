#pragma once

#include <assert.h>

#include <string.h>

namespace DS {

	template <typename T>
	class Option {
		bool isSomeFlag = false;

#define ASSERT_IS_SOME assert(isSomeFlag, "To successfully dereference Option, it must contain something.");

		alignas(T) char data[sizeof(T)] = { 0 };
	public:
		constexpr Option() {}

		constexpr Option(T&& some) {
			memcpy(data, &some, sizeof(T));

			isSomeFlag = true;
		}

		const T& operator*() const {
			ASSERT_IS_SOME

				return *((T*)data);
		}

		T& operator*() {
			ASSERT_IS_SOME

				return *((T*)data);
		}

		T* operator->() {
			ASSERT_IS_SOME

				return (T*)&data;
		}

		bool isSome() const {
			return isSomeFlag;
		}

		bool isNone() const {
			return !isSomeFlag;
		}
	};

}