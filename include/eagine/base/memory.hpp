/**
 *  @file eagine/base/memory.hpp
 *  @brief Smart pointers
 *
 *  Copyright 2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_BASE_MEMORY_1408161723_HPP
#define EAGINE_BASE_MEMORY_1408161723_HPP

#include <memory>

namespace eagine {
namespace base {

using ::std::weak_ptr;
using ::std::shared_ptr;
using ::std::unique_ptr;

using ::std::make_shared;
using ::std::allocate_shared;

// TODO use C++14 make_unique if available
template <typename T, typename ... P>
inline unique_ptr<T> make_unique(P&& ... p)
{
	return unique_ptr<T>(new T(std::forward<P>(p)...));
}

using std::static_pointer_cast;
using std::dynamic_pointer_cast;

} // namespace base
} // namespace eagine

#endif //include guard

