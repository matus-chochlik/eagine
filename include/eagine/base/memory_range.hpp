/**
 *  @file eagine/base/memory_range.hpp
 *  @brief Memory range.
 *
 *  Copyright 2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_BASE_MEMORY_RANGE_1408161723_HPP
#define EAGINE_BASE_MEMORY_RANGE_1408161723_HPP

#include <eagine/base/memory_block.hpp>

namespace EAGine {
namespace base {

template <typename T>
class typed_memory_range
{
private:
	T* _addr;
	std::size_t _size;

	T* _cast(typename meta::add_same_constness<T, void>::type* ptr)
	{
		assert((std::size_t)ptr % alignof(T) == 0);
		return static_cast<T*>(ptr);
	}
public:
	typedef basic_memory_block<meta::is_const<T>::value> raw_block;

	typed_memory_range(T* addr_, std::size_t size_)
	 : _addr(addr_)
	 , _size(size_)
	{ }

	typed_memory_range(const raw_block& raw)
	 : _addr(_cast(raw.addr()))
	 , _size(raw.size() / sizeof(T))
	{ }

	raw_block block(void) const
	{
		return raw_block(_addr, _size*sizeof(T));
	}

	operator raw_block (void) const
	{
		return block();
	}

	typedef T* iterator;
	typedef T& reference;

	bool empty(void) const
	{
		return _size == 0;
	}

	std::size_t size(void) const
	{
		return _size;
	}

	T& at(std::size_t pos) const
	{
		assert(pos < this->_size);
		return *(this->_addr+pos);
	}

	T* begin(void) const
	{
		return this->_addr;
	}

	T* end(void) const
	{
		return this->_addr+this->_size;
	}

	typed_memory_range slice(std::size_t begin_, std::size_t size_) const
	{
		assert(begin_+size_ <= _size);
		return typed_memory_range(_addr+begin_, size_);
	}

	typed_memory_range slice(std::size_t begin_) const
	{
		return slice(begin_, _size-begin_);
	}
};

typedef typed_memory_range<byte> byte_range;
typedef typed_memory_range<const byte> const_byte_range;

} // namespace base
} // namespace EAGine

#endif //include guard
