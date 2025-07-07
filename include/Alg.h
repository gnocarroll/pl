#pragma once

#include <initializer_list>

namespace Alg {
	template <typename T>
	const T& minOf(const T& lhs, const T& rhs) {
		if (lhs < rhs) {
			return lhs;
		}

		return rhs;
	}

	template <typename T>
	const T& minOf(std::initializer_list<T> ilist) {
		const T* ret = nullptr;

		for (const auto& elem : ilist) {
			if (ret == nullptr || elem < *ret) {
				ret = &elem;
			}
		}

		return *ret;
	}
}