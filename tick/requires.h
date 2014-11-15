/*=============================================================================
    Copyright (c) 2014 Paul Fultz II
    requires.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef TICK_GUARD_REQUIRES_H
#define TICK_GUARD_REQUIRES_H

#include <type_traits>

#define TICK_ERROR_PARENTHESIS_MUST_BE_PLACED_AROUND_THE_RETURN_TYPE(...) __VA_ARGS__>::type
#define TICK_FUNCTION_REQUIRES(...) typename std::enable_if<(__VA_ARGS__), TICK_ERROR_PARENTHESIS_MUST_BE_PLACED_AROUND_THE_RETURN_TYPE

#define TICK_CLASS_REQUIRES(...) typename std::enable_if<(__VA_ARGS__)>::type

#define TICK_REQUIRES(...) bool TickPrivateBool ## __LINE__=true, typename std::enable_if<(TickPrivateBool##__LINE__ && __VA_ARGS__), int>::type = 0

#define TICK_MEMBER_REQUIRES(...) template<TICK_REQUIRES(__VA_ARGS__)>

#endif