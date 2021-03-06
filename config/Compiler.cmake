#  Copyright 2010-2015 Matus Chochlik. Distributed under the Boost
#  Software License, Version 1.0. (See accompanying file
#  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# enable warnings on gcc
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_definitions(
		-pedantic
		-Wall
		-Weverything
		-Werror
		-Wno-c++98-compat
		-Wno-global-constructors
		-Wno-exit-time-destructors
		-Wno-date-time
		-Wno-weak-vtables
		-Wno-padded
		-Wno-missing-prototypes
		-Wno-float-equal
	)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	add_definitions(-pedantic -Werror -Wall -Wextra -Wshadow)
endif()

add_definitions(-D_USE_MATH_DEFINES)

