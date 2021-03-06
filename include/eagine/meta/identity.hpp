/**
 *  @file eagine/meta/identity.hpp
 *  @brief Identity metafunction.
 *
 *  Copyright 2012-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_META_IDENTITY_1308281038_HPP
#define EAGINE_META_IDENTITY_1308281038_HPP

namespace eagine {
namespace meta {

template <typename X>
struct identity
{
	typedef X type;
};

} // namespace meta
} // namespace eagine

#endif //include guard

