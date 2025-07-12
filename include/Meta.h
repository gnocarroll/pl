#pragma once

/// <summary>
/// Metaprogramming
/// </summary>
namespace Meta {
	template <bool cond, typename T, typename F>
	struct Conditional { using Type = T; };

	template <typename T, typename F>
	struct Conditional<false, T, F> { using Type = F; };
}