/**
 *  .file devel/test19.cpp
 *
 *  Copyright 2012-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#include <eagine/math/matrix.hpp>
#include <eagine/math/io.hpp>
//------------------
#include <iostream>

int main(int argc, const char**)
{
	using namespace EAGine;
	using namespace EAGine::math;

	typedef matrix<float,4,4,true> mat4;

	mat4 m0 = identity<mat4>();
	mat4 m1 = {{
		{ 1, 2, 3, 4},
		{ 5, 6, 7, 8},
		{ 9,10,11,12},
		{13,14,15,16}
	}};

	std::cout << m0 << std::endl;
	std::cout << row<1>(m0) << std::endl;
	std::cout << m1 << std::endl;
	std::cout << transpose(m1) << std::endl;
	std::cout << reorder(m1) << std::endl;
	std::cout << column<0>(m1) << std::endl;
	std::cout << column<1>(m1) << std::endl;
	std::cout << column<2>(m1) << std::endl;
	std::cout << column<3>(m1) << std::endl;

	std::cout << std::endl;
	for(unsigned i=0; i<rows(m1); ++i)
	{
		std::cout << row(m1, i) << std::endl;
	}

	std::cout << std::endl;
	for(unsigned i=0; i<columns(m1); ++i)
	{
		std::cout << column(m1, i) << std::endl;
	}

	std::cout << multiply(m0,m1) << std::endl;
	std::cout << multiply(m1,m0) << std::endl;
	std::cout << multiply(m1,m1) << std::endl;

	for(unsigned i=0; i<20000000; ++i)
	{
		m1._v[0][0] = argc+i;
		mat4 x = multiply(m1, m1);
		if(x._v[0][0] < 0) return 1;
	}

	return 0;
}
