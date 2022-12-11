#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#endif

////////////////////////////////////////////////////////////
// Is Equal X
// Should not be used any more but keep it here for tests
////////////////////////////////////////////////////////////

#define MINI_PP_IS_EQUAL_0(x) MINI_PP_IS_EQUAL(0, x)
#define MINI_PP_IS_EQUAL_1(x) MINI_PP_IS_EQUAL(1, x)
#define MINI_PP_IS_EQUAL_2(x) MINI_PP_IS_EQUAL(2, x)
#define MINI_PP_IS_EQUAL_3(x) MINI_PP_IS_EQUAL(3, x)
#define MINI_PP_IS_EQUAL_4(x) MINI_PP_IS_EQUAL(4, x)
#define MINI_PP_IS_EQUAL_5(x) MINI_PP_IS_EQUAL(5, x)
#define MINI_PP_IS_EQUAL_6(x) MINI_PP_IS_EQUAL(6, x)
#define MINI_PP_IS_EQUAL_7(x) MINI_PP_IS_EQUAL(7, x)

////////////////////////////////////////////////////////////

#define ZERO 0
#define ONE() 1
#define TWO 2
#define THREE() 3
#define FOUR 4
#define FIVE() 5
#define FOO foo
#define FOO_CALL() foo

///////////////// MINI_PP_IS_INT /////////////////
static_assert(MINI_PP_IS_INT(42) == 1, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(foo) == 0, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(ZERO) == 1, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(ONE()) == 1, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(ONE) == 0, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(FOO) == 0, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(FOO_CALL()) == 0, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_INT(42)) == 41, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_INT(foo)) == 40, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_INT(ZERO)) == 41, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_INT(ONE())) == 41, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_INT(ONE)) == 40, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_INT(FOO)) == 40, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_INT(FOO_CALL())) == 40, "MINI_PP_IS_INT is broken");

///////////////// MINI_PP_IS_EQUAL /////////////////
static_assert(MINI_PP_IS_EQUAL(42, 42) == 1, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_IS_EQUAL(42, 123) == 0, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_IS_EQUAL(ZERO, 0) == 1, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_IS_EQUAL(0, ZERO) == 1, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_IS_EQUAL(ZERO, ZERO) == 1, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_IS_EQUAL(1, ONE()) == 1, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_IS_EQUAL(ONE(), 42) == 0, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_IS_EQUAL(ONE(), ONE()) == 1, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_IS_EQUAL(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS) == 1, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(42, 42)) == 41, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(42, 123)) == 40, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(ZERO, 0)) == 41, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(0, ZERO)) == 41, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(ZERO, ZERO)) == 41, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(1, ONE())) == 41, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(ONE(), 42)) == 40, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(ONE(), ONE())) == 41, "MINI_PP_IS_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS)) == 41, "MINI_PP_IS_EQUAL is broken");

///////////////// MINI_PP_IS_EQUAL_0 /////////////////
static_assert(MINI_PP_IS_EQUAL_0(0) == 1, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_IS_EQUAL_0(1) == 0, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_IS_EQUAL_0(ZERO) == 1, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_IS_EQUAL_0(ONE()) == 0, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_0(0)) == 41, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_0(1)) == 40, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_0(ZERO)) == 41, "MINI_PP_IS_EQUAL_0 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_0(ONE())) == 40, "MINI_PP_IS_EQUAL_0 is broken");

///////////////// MINI_PP_IS_EQUAL_1 /////////////////
static_assert(MINI_PP_IS_EQUAL_1(1) == 1, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_IS_EQUAL_1(2) == 0, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_IS_EQUAL_1(ONE()) == 1, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_IS_EQUAL_1(TWO) == 0, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_1(1)) == 41, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_1(2)) == 40, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_1(ONE())) == 41, "MINI_PP_IS_EQUAL_1 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_1(TWO)) == 40, "MINI_PP_IS_EQUAL_1 is broken");

///////////////// MINI_PP_IS_EQUAL_2 /////////////////
static_assert(MINI_PP_IS_EQUAL_2(2) == 1, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_IS_EQUAL_2(3) == 0, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_IS_EQUAL_2(TWO) == 1, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_IS_EQUAL_2(THREE()) == 0, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_2(2)) == 41, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_2(3)) == 40, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_2(TWO)) == 41, "MINI_PP_IS_EQUAL_2 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_2(THREE())) == 40, "MINI_PP_IS_EQUAL_2 is broken");

///////////////// MINI_PP_IS_EQUAL_3 /////////////////
static_assert(MINI_PP_IS_EQUAL_3(3) == 1, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_IS_EQUAL_3(4) == 0, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_IS_EQUAL_3(THREE()) == 1, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_IS_EQUAL_3(FOUR) == 0, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_3(3)) == 41, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_3(4)) == 40, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_3(THREE())) == 41, "MINI_PP_IS_EQUAL_3 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_3(FOUR)) == 40, "MINI_PP_IS_EQUAL_3 is broken");

///////////////// MINI_PP_IS_EQUAL_4 /////////////////
static_assert(MINI_PP_IS_EQUAL_4(4) == 1, "MINI_PP_IS_EQUAL_4 is broken");
static_assert(MINI_PP_IS_EQUAL_4(5) == 0, "MINI_PP_IS_EQUAL_4 is broken");
static_assert(MINI_PP_IS_EQUAL_4(FOUR) == 1, "MINI_PP_IS_EQUAL_4 is broken");
static_assert(MINI_PP_IS_EQUAL_4(FIVE()) == 0, "MINI_PP_IS_EQUAL_4 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_4(4)) == 41, "MINI_PP_IS_EQUAL_4 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_4(5)) == 40, "MINI_PP_IS_EQUAL_4 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_4(FOUR)) == 41, "MINI_PP_IS_EQUAL_4 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EQUAL_4(FIVE())) == 40, "MINI_PP_IS_EQUAL_4 is broken");
