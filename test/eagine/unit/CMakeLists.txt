#  Copyright 2012-2015 Matus Chochlik. Distributed under the Boost
#  Software License, Version 1.0. (See accompanying file
#  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
cmake_minimum_required(VERSION 2.8)

eagine_test_dir()

eagine_exec_test(dimension)
eagine_exec_test(dim_derived)

eagine_exec_test(scales)

eagine_exec_test(unit)
eagine_exec_test(si)

eagine_exec_test(info)

eagine_exec_test(quantity)
