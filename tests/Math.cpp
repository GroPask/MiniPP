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

#define DUAL_TEST_IS_INT(a, b) MINI_PP_ASSERT(MINI_PP_IS_INT(42))MINI_PP_CAT(MINI_PP_IS_INT(a), MINI_PP_IS_INT(b))

///////////////// MINI_PP_IS_INT /////////////////
static_assert(MINI_PP_IS_INT(42) == 1, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(foo) == 0, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(ZERO) == 1, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(ONE()) == 1, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(ONE) == 0, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(FOO) == 0, "MINI_PP_IS_INT is broken");
static_assert(MINI_PP_IS_INT(FOO_CALL()) == 0, "MINI_PP_IS_INT is broken");

static_assert(DUAL_TEST_IS_INT(42, 123) == 11, "MINI_PP_IS_INT is broken");

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

///////////////// MINI_PP_INC /////////////////
static_assert(MINI_PP_INC(7) == 8, "MINI_PP_INC is broken");
static_assert(MINI_PP_INC(ONE()) == 2, "MINI_PP_INC is broken");
static_assert(MINI_PP_INC(FOUR) == 5, "MINI_PP_INC is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_INC(7)) == 48, "MINI_PP_INC is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_INC(ONE())) == 42, "MINI_PP_INC is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_INC(FOUR)) == 45, "MINI_PP_INC is broken");

///////////////// MINI_PP_DEC /////////////////
static_assert(MINI_PP_DEC(7) == 6, "MINI_PP_DEC is broken");
static_assert(MINI_PP_DEC(ONE()) == 0, "MINI_PP_DEC is broken");
static_assert(MINI_PP_DEC(FOUR) == 3, "MINI_PP_DEC is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_DEC(7)) == 46, "MINI_PP_DEC is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_DEC(ONE())) == 40, "MINI_PP_DEC is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_DEC(FOUR)) == 43, "MINI_PP_DEC is broken");

///////////////// MINI_PP_IS_LESS /////////////////
static_assert(MINI_PP_IS_LESS(42, 42) == 0, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(2, 42) == 1, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(42, 2) == 0, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(41, 42) == 1, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(42, 41) == 0, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(40, 42) == 1, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(42, 40) == 0, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(0, 42) == 1, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(42, 0) == 0, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(0, 0) == 0, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(MINI_PP_MAX_NB_ARGS, 42) == 0, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(42, MINI_PP_MAX_NB_ARGS) == 1, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_IS_LESS(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS) == 0, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(42, 42)) == 40, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(2, 42)) == 41, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(42, 2)) == 40, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(41, 42)) == 41, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(42, 41)) == 40, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(40, 42)) == 41, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(42, 40)) == 40, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(0, 42)) == 41, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(42, 0)) == 40, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(0, 0)) == 40, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(MINI_PP_MAX_NB_ARGS, 42)) == 40, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(42, MINI_PP_MAX_NB_ARGS)) == 41, "MINI_PP_IS_LESS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS)) == 40, "MINI_PP_IS_LESS is broken");

///////////////// MINI_PP_IS_MORE /////////////////
static_assert(MINI_PP_IS_MORE(42, 42) == 0, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(2, 42) == 0, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(42, 2) == 1, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(41, 42) == 0, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(42, 41) == 1, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(40, 42) == 0, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(42, 40) == 1, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(0, 42) == 0, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(42, 0) == 1, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(0, 0) == 0, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(MINI_PP_MAX_NB_ARGS, 42) == 1, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(42, MINI_PP_MAX_NB_ARGS) == 0, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_IS_MORE(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS) == 0, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(42, 42)) == 40, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(2, 42)) == 40, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(42, 2)) == 41, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(41, 42)) == 40, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(42, 41)) == 41, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(40, 42)) == 40, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(42, 40)) == 41, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(0, 42)) == 40, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(42, 0)) == 41, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(0, 0)) == 40, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(MINI_PP_MAX_NB_ARGS, 42)) == 41, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(42, MINI_PP_MAX_NB_ARGS)) == 40, "MINI_PP_IS_MORE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS)) == 40, "MINI_PP_IS_MORE is broken");

///////////////// MINI_PP_IS_LESS_OR_EQUAL /////////////////
static_assert(MINI_PP_IS_LESS_OR_EQUAL(42, 42) == 1, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(2, 42) == 1, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(42, 2) == 0, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(41, 42) == 1, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(42, 41) == 0, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(40, 42) == 1, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(42, 40) == 0, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(0, 42) == 1, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(42, 0) == 0, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(0, 0) == 1, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(MINI_PP_MAX_NB_ARGS, 42) == 0, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(42, MINI_PP_MAX_NB_ARGS) == 1, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_IS_LESS_OR_EQUAL(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS) == 1, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(42, 42)) == 41, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(2, 42)) == 41, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(42, 2)) == 40, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(41, 42)) == 41, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(42, 41)) == 40, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(40, 42)) == 41, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(42, 40)) == 40, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(0, 42)) == 41, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(42, 0)) == 40, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(0, 0)) == 41, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(MINI_PP_MAX_NB_ARGS, 42)) == 40, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(42, MINI_PP_MAX_NB_ARGS)) == 41, "MINI_PP_IS_LESS_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_LESS_OR_EQUAL(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS)) == 41, "MINI_PP_IS_LESS_OR_EQUAL is broken");

///////////////// MINI_PP_IS_MORE_OR_EQUAL /////////////////
static_assert(MINI_PP_IS_MORE_OR_EQUAL(42, 42) == 1, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(2, 42) == 0, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(42, 2) == 1, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(41, 42) == 0, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(42, 41) == 1, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(40, 42) == 0, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(42, 40) == 1, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(0, 42) == 0, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(42, 0) == 1, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(0, 0) == 1, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(MINI_PP_MAX_NB_ARGS, 42) == 1, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(42, MINI_PP_MAX_NB_ARGS) == 0, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_IS_MORE_OR_EQUAL(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS) == 1, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(42, 42)) == 41, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(2, 42)) == 40, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(42, 2)) == 41, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(41, 42)) == 40, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(42, 41)) == 41, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(40, 42)) == 40, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(42, 40)) == 41, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(0, 42)) == 40, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(42, 0)) == 41, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(0, 0)) == 41, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(MINI_PP_MAX_NB_ARGS, 42)) == 41, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(42, MINI_PP_MAX_NB_ARGS)) == 40, "MINI_PP_IS_MORE_OR_EQUAL is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_MORE_OR_EQUAL(MINI_PP_MAX_NB_ARGS, MINI_PP_MAX_NB_ARGS)) == 41, "MINI_PP_IS_MORE_OR_EQUAL is broken");

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
