#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#endif

#define ZERO 0
#define ONE() 1
#define TWO 2
#define THREE() 3
#define FOUR 4

///////////////// MINI_PP_IS_EQUAL_0 /////////////////
static_assert(MINI_PP_IS_EQUAL_0(0) == 1, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_IS_EQUAL_0(1) == 0, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_IS_EQUAL_0(ZERO) == 1, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_IS_EQUAL_0(ONE()) == 0, "MINI_PP_IS_EQUAL_0 is broken");

///////////////// MINI_PP_IS_EQUAL_1 /////////////////
static_assert(MINI_PP_IS_EQUAL_1(1) == 1, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_IS_EQUAL_1(2) == 0, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_IS_EQUAL_1(ONE()) == 1, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_IS_EQUAL_1(TWO) == 0, "MINI_PP_IS_EQUAL_1 is broken");

///////////////// MINI_PP_IS_EQUAL_2 /////////////////
static_assert(MINI_PP_IS_EQUAL_2(2) == 1, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_IS_EQUAL_2(3) == 0, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_IS_EQUAL_2(TWO) == 1, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_IS_EQUAL_2(THREE()) == 0, "MINI_PP_IS_EQUAL_2 is broken");

///////////////// MINI_PP_IS_EQUAL_3 /////////////////
static_assert(MINI_PP_IS_EQUAL_3(3) == 1, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_IS_EQUAL_3(4) == 0, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_IS_EQUAL_3(THREE()) == 1, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_IS_EQUAL_3(FOUR) == 0, "MINI_PP_IS_EQUAL_3 is broken");
