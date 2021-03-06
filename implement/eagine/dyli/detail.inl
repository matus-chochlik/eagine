/**
 *  @file eagine/dyli/detail.inl
 *  @brief Dynamic library implementation details
 *
 *  Copyright 2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#include <eagine/eagine_config.hpp>

#include <eagine/base/locale.hpp>
#include <eagine/dyli/error.hpp>

namespace eagine {
namespace dyli {
namespace detail {
//------------------------------------------------------------------------------
// required_lib_n_a
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void required_lib_n_a(void)
{
	throw dyli::not_loaded(base::translate(
		"Required dynamic library is not loaded."
	).str());
}
//------------------------------------------------------------------------------
// required_res_n_a
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void required_res_n_a(void)
{
	throw dyli::not_loaded(base::translate(
		"Required dynamically loaded resource is not available."
	).str());
}
//------------------------------------------------------------------------------
} // namespace detail
} // namespace dyli
} // namespace eagine


