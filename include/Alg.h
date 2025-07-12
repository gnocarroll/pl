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
}