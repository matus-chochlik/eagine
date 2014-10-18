/**
 *  @file eagine/base/functor.hpp
 *  @brief Polymorphic functor wrapper.
 *
 *  Copyright 2012-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_BASE_FUNCTOR_1308281038_HPP
#define EAGINE_BASE_FUNCTOR_1308281038_HPP

#include <eagine/meta/mem_fn_const.hpp>
#include <eagine/meta/type_traits.hpp>
#include <cstdint>
#include <utility>
#include <cassert>

namespace EAGine {
namespace base {

template <typename FuncSig>
class functor_ref;

template <typename RV, typename ... P>
class functor_ref<RV(P...)>
{
private:
	void* _data;
	void(*_func)(void);

	typedef void(*_func_t)(void);
	typedef RV(*_func_pt)(P...);
	typedef RV(*_func_vpt)(void*, P...);

	static constexpr inline
	void* _invptr(void)
	noexcept
	{
		return (void*)(~(std::uintptr_t)(void*)nullptr);
	}

	bool _no_data(void) const
	noexcept
	{
		return _data == _invptr();
	}
public:
	functor_ref(void)
	noexcept
	 : _data(nullptr)
	 , _func(nullptr)
	{ }

	functor_ref(RV(*func)(P...))
	noexcept
	 : _data(_invptr())
	 , _func((_func_t)func)
	{ }

	template <typename T>
	functor_ref(T* data, RV(*func)(T*, P...))
	noexcept
	 : _data((void*)data)
	 , _func((_func_t)func)
	{
		assert(_data != _invptr());
	}

	template <typename T>
	functor_ref(T& data, RV(*func)(T*, P...))
	noexcept
	 : _data((void*)&data)
	 , _func((_func_t)func)
	{
		assert(_data != _invptr());
	}

	template <
		typename C,
		typename MF,
		MF Ptr,
		typename = typename meta::enable_if<
			meta::is_same<
				typename meta::member_function_constant<
					MF,
					Ptr
				>::scope, C
			>::value
		>::type
	>
	functor_ref(
		C* obj,
		meta::member_function_constant<MF, Ptr> mfc
	) noexcept
	 : _data((void*)obj)
	 , _func((_func_t)mfc.make_free())
	{
		assert(_data != nullptr);
		assert(_data != _invptr());
	}

	bool callable(void) const
	noexcept
	{
		return _func != nullptr;
	}

	explicit operator bool (void) const
	noexcept
	{
		return callable();
	}

	template <typename ... A>
	RV operator()(A&&...a) const
	{
		assert(callable());
		if(_no_data())
		{
			return ((_func_pt)(_func))(
				std::forward<A>(a)...
			);
		}
		else
		{
			return ((_func_vpt)(_func))(
				_data,
				std::forward<A>(a)...
			);
		}
	}
};

} // namespace base
} // namespace EAGine

#endif //include guard
