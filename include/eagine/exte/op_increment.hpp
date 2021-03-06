/**
 *  @file eagine/exte/op_increment.hpp
 *
 *  Copyright 2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_EXTE_OP_INCREMENT_1308281038_HPP
#define EAGINE_EXTE_OP_INCREMENT_1308281038_HPP

#include <eagine/exte/wrap_or_fwd.hpp>

namespace eagine {
namespace exte {

// increment_tag
template <>
struct operator_tag<meta::string<'+','+'>,-1>
{
	template <typename U>
	constexpr inline
	auto operator()(U& v) const
	{
		return ++v;
	}
};

template <>
struct operator_tag<meta::string<'+','+'>, 1>
{
	template <typename U>
	constexpr inline
	auto operator()(U& v) const
	{
		return v++;
	}
};

template <int A>
using increment_tag = operator_tag<meta::string<'+','+'>, A>;

// pre-increment
template <typename U>
static constexpr inline
unary_expression<
	increment_tag<-1>,
	typename wrap_or_fwd_result<U>::type
>
operator ++ (U&& v)
{
	return {wrap_or_fwd(std::forward<U>(v))};
}

// post-increment
template <typename U>
static constexpr inline
unary_expression<
	increment_tag<1>,
	typename wrap_or_fwd_result<U>::type
>
operator ++ (U&& v, int)
{
	return {wrap_or_fwd(std::forward<U>(v))};
}

} // namespace exte
} // namespace eagine

#endif //include guard

