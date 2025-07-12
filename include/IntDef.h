#pragma once

#include "Meta.h"

namespace IntDef {
	template <unsigned bytes, typename PrimitiveIntType, typename... OtherPrimitiveTypes>
	struct FindMatchingPrimitiveType {
		using IntType = Meta::Conditional<
			bytes == sizeof(PrimitiveIntType),
			PrimitiveIntType,
			Meta::Conditional<
				sizeof...(OtherPrimitiveTypes) == 0,
				void,
				FindMatchingPrimitiveType<bytes, OtherPrimitiveTypes...>::IntType
			>::Type
		>::Type;
	};

	template <unsigned bytes>
	struct FindNByteSigned {
		using IntType = FindMatchingPrimitiveType<bytes, char, short, int, long, long long>::IntType;
	};

	template <unsigned bytes>
	struct FindNByteUnsigned {
		using IntType = FindMatchingPrimitiveType<
			bytes,
			unsigned char,
			unsigned short,
			unsigned int,
			unsigned long,
			unsigned long long
		>::IntType;
	};
	
	template <bool isSigned, unsigned bytes>
	struct FindNByteInt {
		using IntType = Meta::Conditional<
			isSigned,
			FindNByteSigned<bytes>::IntType,
			FindNByteUnsigned<bytes>::IntType
		>::Type;
	};

	using Int8 = FindNByteSigned<1>::IntType;
	using Int16 = FindNByteSigned<2>::IntType;
	using Int32 = FindNByteSigned<4>::IntType;
	using Int64 = FindNByteSigned<8>::IntType;

	using UInt8 = FindNByteUnsigned<1>::IntType;
	using UInt16 = FindNByteUnsigned<2>::IntType;
	using UInt32 = FindNByteUnsigned<4>::IntType;
	using UInt64 = FindNByteUnsigned<8>::IntType;

	using USize = decltype(sizeof(0));
	using UIntPtr = FindNByteUnsigned<sizeof(void*)>::IntType;
}