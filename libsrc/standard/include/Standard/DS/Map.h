#pragma once

namespace DS {
	template <typename T>
	USize hash(const T& value) {
		static_assert(false, "hash not implemented for type");

		return 0;
	}

	template <typename Key, typename Value>
	class Map {

	};
}