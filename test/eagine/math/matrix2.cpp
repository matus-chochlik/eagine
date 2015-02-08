/**
 *  .file test/eagine/math/matrix2.cpp
 *
 *  .author Matus Chochlik
 *
 *  Copyright 2012-2015 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE eagine_math_matrix2
#include <boost/test/unit_test.hpp>

#include <eagine/math/matrix.hpp>
#include <cstdlib>
#include <cmath>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(math_matrix2)

template <typename T, unsigned R, unsigned C, bool RM>
void test_math_matrix_rows_TRC(void)
{
	eagine::math::matrix<T,R,C,RM> m;

	using eagine::math::rows;

	BOOST_ASSERT(rows(m) == R);
}

template <typename T, bool RM>
void test_math_matrix_rows(void)
{
	test_math_matrix_rows_TRC<T, 1, 1, RM>();
	test_math_matrix_rows_TRC<T, 1, 2, RM>();
	test_math_matrix_rows_TRC<T, 1, 3, RM>();
	test_math_matrix_rows_TRC<T, 1, 4, RM>();
	test_math_matrix_rows_TRC<T, 1, 5, RM>();

	test_math_matrix_rows_TRC<T, 2, 1, RM>();
	test_math_matrix_rows_TRC<T, 2, 2, RM>();
	test_math_matrix_rows_TRC<T, 2, 3, RM>();
	test_math_matrix_rows_TRC<T, 2, 4, RM>();
	test_math_matrix_rows_TRC<T, 2, 5, RM>();

	test_math_matrix_rows_TRC<T, 3, 1, RM>();
	test_math_matrix_rows_TRC<T, 3, 2, RM>();
	test_math_matrix_rows_TRC<T, 3, 3, RM>();
	test_math_matrix_rows_TRC<T, 3, 4, RM>();
	test_math_matrix_rows_TRC<T, 3, 5, RM>();

	test_math_matrix_rows_TRC<T, 4, 1, RM>();
	test_math_matrix_rows_TRC<T, 4, 2, RM>();
	test_math_matrix_rows_TRC<T, 4, 3, RM>();
	test_math_matrix_rows_TRC<T, 4, 4, RM>();
	test_math_matrix_rows_TRC<T, 4, 5, RM>();

	test_math_matrix_rows_TRC<T, 5, 1, RM>();
	test_math_matrix_rows_TRC<T, 5, 2, RM>();
	test_math_matrix_rows_TRC<T, 5, 3, RM>();
	test_math_matrix_rows_TRC<T, 5, 4, RM>();
	test_math_matrix_rows_TRC<T, 5, 5, RM>();
}

BOOST_AUTO_TEST_CASE(math_matrix_rows)
{
	test_math_matrix_rows<float, true>();
	test_math_matrix_rows<float,false>();
	test_math_matrix_rows<double, true>();
	test_math_matrix_rows<double,false>();
}

template <typename T, unsigned R, unsigned C, bool RM>
void test_math_matrix_cols_TRC(void)
{
	eagine::math::matrix<T,R,C,RM> m;

	using eagine::math::columns;

	BOOST_ASSERT(columns(m) == C);
}

template <typename T, bool RM>
void test_math_matrix_cols(void)
{
	test_math_matrix_cols_TRC<T, 1, 1, RM>();
	test_math_matrix_cols_TRC<T, 1, 2, RM>();
	test_math_matrix_cols_TRC<T, 1, 3, RM>();
	test_math_matrix_cols_TRC<T, 1, 4, RM>();
	test_math_matrix_cols_TRC<T, 1, 5, RM>();

	test_math_matrix_cols_TRC<T, 2, 1, RM>();
	test_math_matrix_cols_TRC<T, 2, 2, RM>();
	test_math_matrix_cols_TRC<T, 2, 3, RM>();
	test_math_matrix_cols_TRC<T, 2, 4, RM>();
	test_math_matrix_cols_TRC<T, 2, 5, RM>();

	test_math_matrix_cols_TRC<T, 3, 1, RM>();
	test_math_matrix_cols_TRC<T, 3, 2, RM>();
	test_math_matrix_cols_TRC<T, 3, 3, RM>();
	test_math_matrix_cols_TRC<T, 3, 4, RM>();
	test_math_matrix_cols_TRC<T, 3, 5, RM>();

	test_math_matrix_cols_TRC<T, 4, 1, RM>();
	test_math_matrix_cols_TRC<T, 4, 2, RM>();
	test_math_matrix_cols_TRC<T, 4, 3, RM>();
	test_math_matrix_cols_TRC<T, 4, 4, RM>();
	test_math_matrix_cols_TRC<T, 4, 5, RM>();

	test_math_matrix_cols_TRC<T, 5, 1, RM>();
	test_math_matrix_cols_TRC<T, 5, 2, RM>();
	test_math_matrix_cols_TRC<T, 5, 3, RM>();
	test_math_matrix_cols_TRC<T, 5, 4, RM>();
	test_math_matrix_cols_TRC<T, 5, 5, RM>();
}

BOOST_AUTO_TEST_CASE(math_matrix_cols)
{
	test_math_matrix_cols<float, true>();
	test_math_matrix_cols<float,false>();
	test_math_matrix_cols<double, true>();
	test_math_matrix_cols<double,false>();
}

template <typename T, unsigned R, unsigned C, bool RM>
void test_math_matrix_row_major_TRC(void)
{
	eagine::math::matrix<T,R,C,RM> m;

	using eagine::math::row_major;

	BOOST_ASSERT(row_major(m) == RM);
}

template <typename T, bool RM>
void test_math_matrix_row_major(void)
{
	test_math_matrix_row_major_TRC<T, 1, 1, RM>();
	test_math_matrix_row_major_TRC<T, 1, 2, RM>();
	test_math_matrix_row_major_TRC<T, 1, 3, RM>();
	test_math_matrix_row_major_TRC<T, 1, 4, RM>();
	test_math_matrix_row_major_TRC<T, 1, 5, RM>();

	test_math_matrix_row_major_TRC<T, 2, 1, RM>();
	test_math_matrix_row_major_TRC<T, 2, 2, RM>();
	test_math_matrix_row_major_TRC<T, 2, 3, RM>();
	test_math_matrix_row_major_TRC<T, 2, 4, RM>();
	test_math_matrix_row_major_TRC<T, 2, 5, RM>();

	test_math_matrix_row_major_TRC<T, 3, 1, RM>();
	test_math_matrix_row_major_TRC<T, 3, 2, RM>();
	test_math_matrix_row_major_TRC<T, 3, 3, RM>();
	test_math_matrix_row_major_TRC<T, 3, 4, RM>();
	test_math_matrix_row_major_TRC<T, 3, 5, RM>();

	test_math_matrix_row_major_TRC<T, 4, 1, RM>();
	test_math_matrix_row_major_TRC<T, 4, 2, RM>();
	test_math_matrix_row_major_TRC<T, 4, 3, RM>();
	test_math_matrix_row_major_TRC<T, 4, 4, RM>();
	test_math_matrix_row_major_TRC<T, 4, 5, RM>();

	test_math_matrix_row_major_TRC<T, 5, 1, RM>();
	test_math_matrix_row_major_TRC<T, 5, 2, RM>();
	test_math_matrix_row_major_TRC<T, 5, 3, RM>();
	test_math_matrix_row_major_TRC<T, 5, 4, RM>();
	test_math_matrix_row_major_TRC<T, 5, 5, RM>();
}

BOOST_AUTO_TEST_CASE(math_matrix_row_major)
{
	test_math_matrix_row_major<float, true>();
	test_math_matrix_row_major<float,false>();
	test_math_matrix_row_major<double, true>();
	test_math_matrix_row_major<double,false>();
}

template <typename T, unsigned P, unsigned Q, unsigned R>
void test_math_matrix_multiply_TPQR(void)
{
	T d1[P*Q];
	T d2[Q*R];

	for(unsigned k=0; k<P*Q; ++k)
	{
		d1[k] = std::rand() / T(3);
	}

	for(unsigned k=0; k<Q*R; ++k)
	{
		d2[k] = std::rand() / T(3);
	}

	auto m1 = eagine::math::matrix<T,P,Q, true>::from(d1, P*Q);
	auto m2 = eagine::math::matrix<T,Q,R,false>::from(d2, Q*R);

	eagine::math::matrix<T,P,R,true> m3 = m1*m2;

	for(unsigned i=0; i<P; ++i)
	for(unsigned j=0; j<R; ++j)
	{
		T s = T(0);

		for(unsigned k=0; k<Q; ++k)
		{
			s += m1[i][k]*m2[j][k];
		}
		BOOST_ASSERT(test_math_close(m3[i][j], s));
	}
}

template <typename T>
void test_math_matrix_multiply_T(void)
{
	test_math_matrix_multiply_TPQR<T, 1, 1, 1>();
	test_math_matrix_multiply_TPQR<T, 1, 1, 5>();
	test_math_matrix_multiply_TPQR<T, 1, 1, 5>();
	test_math_matrix_multiply_TPQR<T, 1, 1, 5>();
	test_math_matrix_multiply_TPQR<T, 1, 1, 5>();

	test_math_matrix_multiply_TPQR<T, 1, 2, 1>();
	test_math_matrix_multiply_TPQR<T, 1, 2, 2>();
	test_math_matrix_multiply_TPQR<T, 1, 2, 3>();
	test_math_matrix_multiply_TPQR<T, 1, 2, 4>();
	test_math_matrix_multiply_TPQR<T, 1, 2, 5>();

	test_math_matrix_multiply_TPQR<T, 1, 3, 1>();
	test_math_matrix_multiply_TPQR<T, 1, 3, 2>();
	test_math_matrix_multiply_TPQR<T, 1, 3, 3>();
	test_math_matrix_multiply_TPQR<T, 1, 3, 4>();
	test_math_matrix_multiply_TPQR<T, 1, 3, 5>();

	test_math_matrix_multiply_TPQR<T, 1, 4, 1>();
	test_math_matrix_multiply_TPQR<T, 1, 4, 2>();
	test_math_matrix_multiply_TPQR<T, 1, 4, 3>();
	test_math_matrix_multiply_TPQR<T, 1, 4, 4>();
	test_math_matrix_multiply_TPQR<T, 1, 4, 5>();

	test_math_matrix_multiply_TPQR<T, 1, 5, 1>();
	test_math_matrix_multiply_TPQR<T, 1, 5, 2>();
	test_math_matrix_multiply_TPQR<T, 1, 5, 3>();
	test_math_matrix_multiply_TPQR<T, 1, 5, 4>();
	test_math_matrix_multiply_TPQR<T, 1, 5, 5>();

	test_math_matrix_multiply_TPQR<T, 2, 1, 1>();
	test_math_matrix_multiply_TPQR<T, 2, 1, 2>();
	test_math_matrix_multiply_TPQR<T, 2, 1, 3>();
	test_math_matrix_multiply_TPQR<T, 2, 1, 4>();
	test_math_matrix_multiply_TPQR<T, 2, 1, 5>();

	test_math_matrix_multiply_TPQR<T, 2, 2, 1>();
	test_math_matrix_multiply_TPQR<T, 2, 2, 2>();
	test_math_matrix_multiply_TPQR<T, 2, 2, 3>();
	test_math_matrix_multiply_TPQR<T, 2, 2, 4>();
	test_math_matrix_multiply_TPQR<T, 2, 2, 5>();

	test_math_matrix_multiply_TPQR<T, 2, 3, 1>();
	test_math_matrix_multiply_TPQR<T, 2, 3, 2>();
	test_math_matrix_multiply_TPQR<T, 2, 3, 3>();
	test_math_matrix_multiply_TPQR<T, 2, 3, 4>();
	test_math_matrix_multiply_TPQR<T, 2, 3, 5>();

	test_math_matrix_multiply_TPQR<T, 2, 4, 1>();
	test_math_matrix_multiply_TPQR<T, 2, 4, 2>();
	test_math_matrix_multiply_TPQR<T, 2, 4, 3>();
	test_math_matrix_multiply_TPQR<T, 2, 4, 4>();
	test_math_matrix_multiply_TPQR<T, 2, 4, 5>();

	test_math_matrix_multiply_TPQR<T, 2, 5, 1>();
	test_math_matrix_multiply_TPQR<T, 2, 5, 2>();
	test_math_matrix_multiply_TPQR<T, 2, 5, 3>();
	test_math_matrix_multiply_TPQR<T, 2, 5, 4>();
	test_math_matrix_multiply_TPQR<T, 2, 5, 5>();

	test_math_matrix_multiply_TPQR<T, 3, 1, 1>();
	test_math_matrix_multiply_TPQR<T, 3, 1, 2>();
	test_math_matrix_multiply_TPQR<T, 3, 1, 3>();
	test_math_matrix_multiply_TPQR<T, 3, 1, 4>();
	test_math_matrix_multiply_TPQR<T, 3, 1, 5>();

	test_math_matrix_multiply_TPQR<T, 3, 2, 1>();
	test_math_matrix_multiply_TPQR<T, 3, 2, 2>();
	test_math_matrix_multiply_TPQR<T, 3, 2, 3>();
	test_math_matrix_multiply_TPQR<T, 3, 2, 4>();
	test_math_matrix_multiply_TPQR<T, 3, 2, 5>();

	test_math_matrix_multiply_TPQR<T, 3, 3, 1>();
	test_math_matrix_multiply_TPQR<T, 3, 3, 2>();
	test_math_matrix_multiply_TPQR<T, 3, 3, 3>();
	test_math_matrix_multiply_TPQR<T, 3, 3, 4>();
	test_math_matrix_multiply_TPQR<T, 3, 3, 5>();

	test_math_matrix_multiply_TPQR<T, 3, 4, 1>();
	test_math_matrix_multiply_TPQR<T, 3, 4, 2>();
	test_math_matrix_multiply_TPQR<T, 3, 4, 3>();
	test_math_matrix_multiply_TPQR<T, 3, 4, 4>();
	test_math_matrix_multiply_TPQR<T, 3, 4, 5>();

	test_math_matrix_multiply_TPQR<T, 3, 5, 1>();
	test_math_matrix_multiply_TPQR<T, 3, 5, 2>();
	test_math_matrix_multiply_TPQR<T, 3, 5, 3>();
	test_math_matrix_multiply_TPQR<T, 3, 5, 4>();
	test_math_matrix_multiply_TPQR<T, 3, 5, 5>();

	test_math_matrix_multiply_TPQR<T, 4, 1, 1>();
	test_math_matrix_multiply_TPQR<T, 4, 1, 2>();
	test_math_matrix_multiply_TPQR<T, 4, 1, 3>();
	test_math_matrix_multiply_TPQR<T, 4, 1, 4>();
	test_math_matrix_multiply_TPQR<T, 4, 1, 5>();

	test_math_matrix_multiply_TPQR<T, 4, 2, 1>();
	test_math_matrix_multiply_TPQR<T, 4, 2, 2>();
	test_math_matrix_multiply_TPQR<T, 4, 2, 3>();
	test_math_matrix_multiply_TPQR<T, 4, 2, 4>();
	test_math_matrix_multiply_TPQR<T, 4, 2, 5>();

	test_math_matrix_multiply_TPQR<T, 4, 3, 1>();
	test_math_matrix_multiply_TPQR<T, 4, 3, 2>();
	test_math_matrix_multiply_TPQR<T, 4, 3, 3>();
	test_math_matrix_multiply_TPQR<T, 4, 3, 4>();
	test_math_matrix_multiply_TPQR<T, 4, 3, 5>();

	test_math_matrix_multiply_TPQR<T, 4, 4, 1>();
	test_math_matrix_multiply_TPQR<T, 4, 4, 2>();
	test_math_matrix_multiply_TPQR<T, 4, 4, 3>();
	test_math_matrix_multiply_TPQR<T, 4, 4, 4>();
	test_math_matrix_multiply_TPQR<T, 4, 4, 5>();

	test_math_matrix_multiply_TPQR<T, 4, 5, 1>();
	test_math_matrix_multiply_TPQR<T, 4, 5, 2>();
	test_math_matrix_multiply_TPQR<T, 4, 5, 3>();
	test_math_matrix_multiply_TPQR<T, 4, 5, 4>();
	test_math_matrix_multiply_TPQR<T, 4, 5, 5>();

	test_math_matrix_multiply_TPQR<T, 5, 1, 1>();
	test_math_matrix_multiply_TPQR<T, 5, 1, 2>();
	test_math_matrix_multiply_TPQR<T, 5, 1, 3>();
	test_math_matrix_multiply_TPQR<T, 5, 1, 4>();
	test_math_matrix_multiply_TPQR<T, 5, 1, 5>();

	test_math_matrix_multiply_TPQR<T, 5, 2, 1>();
	test_math_matrix_multiply_TPQR<T, 5, 2, 2>();
	test_math_matrix_multiply_TPQR<T, 5, 2, 3>();
	test_math_matrix_multiply_TPQR<T, 5, 2, 4>();
	test_math_matrix_multiply_TPQR<T, 5, 2, 5>();

	test_math_matrix_multiply_TPQR<T, 5, 3, 1>();
	test_math_matrix_multiply_TPQR<T, 5, 3, 2>();
	test_math_matrix_multiply_TPQR<T, 5, 3, 3>();
	test_math_matrix_multiply_TPQR<T, 5, 3, 4>();
	test_math_matrix_multiply_TPQR<T, 5, 3, 5>();

	test_math_matrix_multiply_TPQR<T, 5, 4, 1>();
	test_math_matrix_multiply_TPQR<T, 5, 4, 2>();
	test_math_matrix_multiply_TPQR<T, 5, 4, 3>();
	test_math_matrix_multiply_TPQR<T, 5, 4, 4>();
	test_math_matrix_multiply_TPQR<T, 5, 4, 5>();

	test_math_matrix_multiply_TPQR<T, 5, 5, 1>();
	test_math_matrix_multiply_TPQR<T, 5, 5, 2>();
	test_math_matrix_multiply_TPQR<T, 5, 5, 3>();
	test_math_matrix_multiply_TPQR<T, 5, 5, 4>();
	test_math_matrix_multiply_TPQR<T, 5, 5, 5>();
}

BOOST_AUTO_TEST_CASE(math_matrix_multiply)
{
	for(int i=0; i<1000; ++i)
	{
		test_math_matrix_multiply_T<float>();
		test_math_matrix_multiply_T<double>();
	}
}

BOOST_AUTO_TEST_SUITE_END()
