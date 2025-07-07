#pragma once

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

	void *memcpy(void* dest, const void* src, size_t count);
	void* memset(void* ptr, int c, size_t n);
	void* memmove(void* dest, const void* src, size_t count);
}