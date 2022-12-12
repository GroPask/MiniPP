#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#endif

#define CALL_IS_MORE_THAN_1_ARGS(...) MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4, __VA_ARGS__)

///////////////// MINI_PP_CAT_IS_MORE_THAN_1_ARGS /////////////////
//static_assert(MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4) == 40, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken"); Should be called with at least one argument
static_assert(MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4, a) == 40, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
static_assert(MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4, a, b) == 41, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
static_assert(MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4, a, b, c) == 41, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
//static_assert(CALL_IS_MORE_THAN_1_ARGS() == 40, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken"); Should be called with at least one argument
static_assert(CALL_IS_MORE_THAN_1_ARGS(a) == 40, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
static_assert(CALL_IS_MORE_THAN_1_ARGS(a, b) == 41, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
static_assert(CALL_IS_MORE_THAN_1_ARGS(a, b, c) == 41, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
//static_assert(MINI_PP_CAT(4, MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4)) == 440, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken"); Should be called with at least one argument
static_assert(MINI_PP_CAT(4, MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4, a)) == 440, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4, a, b)) == 441, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CAT_IS_MORE_THAN_1_ARGS(4, a, b, c)) == 441, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
//static_assert(MINI_PP_CAT(4, CALL_IS_MORE_THAN_1_ARGS()) == 440, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken"); Should be called with at least one argument
static_assert(MINI_PP_CAT(4, CALL_IS_MORE_THAN_1_ARGS(a)) == 440, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
static_assert(MINI_PP_CAT(4, CALL_IS_MORE_THAN_1_ARGS(a, b)) == 441, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
static_assert(MINI_PP_CAT(4, CALL_IS_MORE_THAN_1_ARGS(a, b, c)) == 441, "MINI_PP_CAT_IS_MORE_THAN_1_ARGS is broken");
