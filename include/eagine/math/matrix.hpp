/**
 *  @file eagine/math/matrix.hpp
 *
 *  Copyright 2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_MATH_MATRIX_1308281038_HPP
#define EAGINE_MATH_MATRIX_1308281038_HPP

#include <eagine/math/vector.hpp>
#include <eagine/meta/type_traits.hpp>
#include <eagine/meta/int_sequence.hpp>

namespace EAGine {
namespace math {

// matrix
template <typename T, unsigned R, unsigned C, bool RowMajor>
struct matrix;

// matrix Row-Major
template <typename T, unsigned R, unsigned C>
struct matrix<T,R,C,true>
{
	typedef typename vect::data<T, C>::type _vT;

	_vT _v[R];
};

// matrix Column-Major
template <typename T, unsigned R, unsigned C>
struct matrix<T,R,C,false>
{
	typedef typename vect::data<T, R>::type _vT;

	_vT _v[C];
};

// equality
template <typename T, unsigned R, unsigned C, bool RM>
static constexpr inline
bool
operator == (const matrix<T,R,C,RM>& a, const matrix<T,R,C,RM>& b)
{
	for(unsigned i=0;i<(RM?R:C); ++i)
		if(!vect::equal<T, (RM?C:R)>::apply(a._v[i], b._v[i]))
			return false;
	return true;
}

// non-eqality
template <typename T, unsigned R, unsigned C, bool RM>
static constexpr inline
bool
operator != (const matrix<T,R,C,RM>& a, const matrix<T,R,C,RM>& b)
{
	for(unsigned i=0;i<(RM?R:C); ++i)
		if(!vect::equal<T, (RM?C:R)>::apply(a._v[i], b._v[i]))
			return true;
	return false;
}

// transpose_tpl helper 4x4 matrix
template <bool DstRM, typename T>
static constexpr inline
matrix<T,4,4,DstRM> transpose_tpl_hlp(
	const typename vect::data<T, 4>::type& q0,
	const typename vect::data<T, 4>::type& q1,
	const typename vect::data<T, 4>::type& q2,
	const typename vect::data<T, 4>::type& q3
)
{
	return {{
		vect::shuffle2<T,4>::template apply<0,2,4,6>(q0, q2),
		vect::shuffle2<T,4>::template apply<1,3,5,7>(q0, q2),
		vect::shuffle2<T,4>::template apply<0,2,4,6>(q1, q3),
		vect::shuffle2<T,4>::template apply<1,3,5,7>(q1, q3)
	}};
}

// transpose_tpl 4x4 matrix
template <bool DstRM, bool SrcRM, typename T>
static inline
matrix<T,4,4,DstRM> transpose_tpl(const matrix<T,4,4,SrcRM>& m)
{
	return transpose_tpl_hlp<DstRM, T>(
		vect::shuffle2<T,4>::template apply<0,1,4,5>(m._v[0], m._v[1]),
		vect::shuffle2<T,4>::template apply<2,3,6,7>(m._v[0], m._v[1]),
		vect::shuffle2<T,4>::template apply<0,1,4,5>(m._v[2], m._v[3]),
		vect::shuffle2<T,4>::template apply<2,3,6,7>(m._v[2], m._v[3])
	);
}

// transpose
template <typename T, unsigned R, unsigned C, bool RM>
static inline
matrix<T,R,C,RM> transpose(const matrix<T,R,C,RM>& m)
{
	return transpose_tpl<RM, RM, T>(m);
}

// reorder
template <typename T, unsigned R, unsigned C, bool RM>
static inline
matrix<T,R,C,!RM> reorder(const matrix<T,R,C,RM>& m)
{
	return transpose_tpl<!RM, RM, T>(m);
}

// major_vector
template <unsigned I, typename T, unsigned R, unsigned C, bool RM>
static constexpr inline
typename meta::enable_if<(I<(RM?R:C)), vector<T, (RM?C:R)>>::type
major_vector(const matrix<T,R,C,RM>& m)
{
	return {m._v[I]};
}

// minor_vector mat4x4
template <unsigned I, typename T, bool RM>
static constexpr inline
typename meta::enable_if<(I<4), vector<T, 4>>::type
minor_vector(const matrix<T,4,4,RM>& m)
{
	return {vect::shuffle2<T,4>::template apply<0,1,4,5>(
		vect::shuffle2<T,4>::template apply<0+I,4+I,-1,-1>(m._v[0], m._v[1]),
		vect::shuffle2<T,4>::template apply<0+I,4+I,-1,-1>(m._v[2], m._v[3])
	)};
}

// row (Row-Major)
template <unsigned I, typename T, unsigned R, unsigned C>
static constexpr inline
vector<T, C>
row(const matrix<T,R,C,true>& m)
{
	return major_vector<I>(m);
}

// row (Column-Major)
template <unsigned I, typename T, unsigned R, unsigned C>
static constexpr inline
vector<T, R>
row(const matrix<T,R,C,false>& m)
{
	return minor_vector<I>(m);
}

// column (Column-Major)
template <unsigned I, typename T, unsigned R, unsigned C>
static constexpr inline
vector<T, R>
column(const matrix<T,R,C,false>& m)
{
	return major_vector<I>(m);
}

// column (Row-Major)
template <unsigned I, typename T, unsigned R, unsigned C>
static constexpr inline
vector<T, R>
column(const matrix<T,R,C,true>& m)
{
	return minor_vector<I>(m);
}

// _multiply_hlp2
template <
	unsigned I,
	unsigned ... J,
	typename T,
	unsigned M,
	unsigned N,
	unsigned K
>
static constexpr inline
typename vect::data<T, N>::type
_multiply_hlp2(
	meta::integer_sequence<unsigned, J...>,
	const matrix<T, M, K, true>& m1,
	const matrix<T, K, N,false>& m2
)
{
	return {dot(row<I>(m1), column<J>(m2))...};
}

// multiply hlp
template <
	unsigned ... I,
	typename T,
	unsigned M,
	unsigned N,
	unsigned K,
	bool RM
>
static constexpr inline
matrix<T, M, N, RM>
_multiply_hlp(
	meta::integer_sequence<unsigned, I...>,
	const matrix<T, M, K, RM>& m1,
	const matrix<T, K, N,!RM>& m2
)
{
	typedef typename meta::make_integer_sequence<
		unsigned, N
	>::type is;
	return {{_multiply_hlp2<I>(is(), m1, m2)...}};
}

// multiply
template <typename T, unsigned M, unsigned N, unsigned K, bool RM>
static constexpr inline
matrix<T, M, N, RM> multiply(
	const matrix<T, M, K, RM>& m1,
	const matrix<T, K, N,!RM>& m2
)
{
	typedef typename meta::make_integer_sequence<
		unsigned, M
	>::type is;
	return _multiply_hlp(is(), m1, m2);
}

// multiply
template <typename T, unsigned M, unsigned N, unsigned K, bool RM>
static constexpr inline
matrix<T, M, N, RM> multiply(
	const matrix<T, M, K, RM>& m1,
	const matrix<T, K, N, RM>& m2
)
{
	return multiply(m1, reorder(m2));
}

// identity
template <typename X>
struct identity;

// identity Matrix
template <typename T, unsigned R, unsigned C, bool RM>
struct identity<matrix<T,R,C,RM>>
{
	template <unsigned ... I>
	static constexpr inline matrix<T,R,C,RM>
	_identity(meta::integer_sequence<unsigned, I...>)
	{
		return {{vect::axis<T, C, I>::apply(1)...}};
	}

	constexpr inline operator matrix<T,R,C,RM> (void) const
	{
		typedef typename meta::make_integer_sequence<
			unsigned, R
		>::type _riS;
		return _identity(_riS());
	}
};

} // namespace math
} // namespace EAGine

#endif //include guard

