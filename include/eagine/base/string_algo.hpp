/**
 *  @file eagine/base/string.hpp
 *  @brief String algorithms
 *
 *  Copyright 2012-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_BASE_STRING_ALGO_1308281038_HPP
#define EAGINE_BASE_STRING_ALGO_1308281038_HPP

#include <eagine/base/string.hpp>

namespace EAGine {
namespace base {

// const_view_of
template <typename Str>
struct const_view_of
{
	typedef basic_string_ref<
		typename meta::add_const<
			typename string_container_traits<Str>::value_type
		>::type
	> type;
};

// slice
template <typename Str>
inline 
typename meta::enable_if<
	is_string_container<Str>::value,
	typename const_view_of<Str>::type
>::type
slice(const Str& str, std::size_t pos, std::size_t len)
noexcept
{
	if(pos > str.size())
	{
		pos = str.size();
	}
	if(len > str.size()-pos)
	{
		len = str.size()-pos;
	}
	return {str.data()+pos, len};
}

// slice
template <typename Str>
inline 
typename meta::enable_if<
	is_string_container<Str>::value,
	typename const_view_of<Str>::type
>::type
slice(const Str& str, std::size_t pos)
noexcept
{
	if(pos > str.size())
	{
		pos = str.size();
	}
	return {str.data()+pos, str.size()-pos};
}

// head
template <typename Str>
inline 
typename meta::enable_if<
	is_string_container<Str>::value,
	typename const_view_of<Str>::type
>::type
head(const Str& str, std::size_t len)
noexcept
{
	return slice(str, 0, len);
}

// tail
template <typename Str>
inline 
typename meta::enable_if<
	is_string_container<Str>::value,
	typename const_view_of<Str>::type
>::type
tail(const Str& str, std::size_t len)
noexcept
{
	if(len > str.size())
	{
		len = str.size();
	}
	return slice(str, str.size()-len, len);
}

// starts_with
template <typename Str1, typename Str2>
inline
typename meta::enable_if<
	is_string_container<Str1>::value &&
	is_string_container<Str2>::value,
	bool
>::type
starts_with(const Str1& str, const Str2& with)
noexcept
{
	return head(str, with.size()) == with;
}

// ends_with
template <typename Str1, typename Str2>
inline
typename meta::enable_if<
	is_string_container<Str1>::value &&
	is_string_container<Str2>::value,
	bool
>::type
ends_with(const Str1& str, const Str2& with)
noexcept
{
	return tail(str, with.size()) == with;
}

} // namespace base
} // namespace EAGine

#endif //include guard

