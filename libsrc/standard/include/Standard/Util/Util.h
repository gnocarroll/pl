#pragma once

#include "IntDef.h"

using namespace IntDef;

namespace Util {
	template <typename T> struct RemoveReference { typedef T type; };
	template <typename T> struct RemoveReference<T&> { typedef T type; };
	template <typename T> struct RemoveReference<T&&> { typedef T type; };

	template<class T>
	using RemoveReferenceType = typename RemoveReference<T>::type;

	template <typename T>
	RemoveReferenceType<T>&& move(T&& t) noexcept {
		return static_cast<RemoveReferenceType<T>&&>(t);
	}

	USize roundUpToMultiple(USize number, USize roundUpTo) {
		return ((number - 1) / roundUpTo + 1) * roundUpTo;
	}
}