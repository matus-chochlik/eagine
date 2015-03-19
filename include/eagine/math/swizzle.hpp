/**
 *  @file eagine/math/swizzle.hpp
 *
 *  Copyright 2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_MATH_SWIZZLE_1308281038_HPP
#define EAGINE_MATH_SWIZZLE_1308281038_HPP

#include <eagine/math/fwd.hpp>
#include <eagine/meta/int_const.hpp>

namespace eagine {
namespace math {

template <typename C, unsigned ... I>
struct swizzle_mask
{
	C _c;

	template <typename T, typename V, unsigned J>
	static inline T _get(
		const V& v,
		meta::unsigned_constant<J>
	)
	{
		return v[J-1];
	}

	template <typename T, typename V>
	inline T _get(
		const V&,
		meta::unsigned_constant<0>
	) const
	{
		return T(_c);
	}

	template <unsigned J, typename T, typename V>
	inline T get(const V& v) const
	{
		return _get<T>(v, meta::unsigned_constant<J>());
	}

	template <typename T>
	swizzle_mask<T, I...> operator ()(T v) const
	{
		return {T(v)};
	}
};

template <typename V, unsigned ... I>
struct has_swizzle;

template <typename T, unsigned N, unsigned ...I>
struct has_swizzle<vector<T, N>, I...>
 : meta::boolean_constant<meta::max_constant<unsigned, I...>::value<=N>
{ };

template <typename T, unsigned N, unsigned ...I>
struct has_swizzle<tvec<T, N>, I...>
 : meta::boolean_constant<meta::max_constant<unsigned, I...>::value<=N>
{ };

template <typename T, typename C, unsigned ... I, typename U, unsigned M>
static inline
typename meta::enable_if<
	has_swizzle<vector<U,M>, I...>::value,
	vector<T, sizeof...(I)>
>::type
swizzle(
	const vector<U, M>& v,
	swizzle_mask<C, I...> m
)
{
	return {{m.template get<I,T>(v._v)...}};
}

template <typename T, typename C, unsigned ... I, typename U, unsigned M>
static inline
typename meta::enable_if<
	has_swizzle<vector<U,M>, I...>::value,
	tvec<T, sizeof...(I)>
>::type
swizzle(
	const tvec<U, M>& v,
	swizzle_mask<C, I...> m
)
{
	return tvec<T, sizeof...(I)>(m.template get<I,T>(v._v)...);
}

template <unsigned ... I, typename T, typename C, unsigned N>
static inline
typename meta::enable_if<
	has_swizzle<vector<T,N>, I...>::value,
	vector<T, sizeof...(I)>
>::type
operator / (const vector<T, N>& v, swizzle_mask<C, I...> m)
{
	return swizzle<T>(v, m);
}

} // namespace math
} // namespace eagine

#endif //include guard

