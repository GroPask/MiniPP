#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#include "TestUtility.hpp"
#endif

#define VALUE_4 4
#define VALUE_2 2
#define VALUE_42() 42
#define BEGIN VALU
#define ARG_SEQ_4_2 4, 2
#define GET_FIRST(a, b) a
#define GET_SECOND(a, b) b
#define ONE 1
#define ONE_CALL() 1
#define EMPTY
#define EMPTY_CALL()

#define NEED_2_EXPAND_CALL() VALUE_42 MINI_PP_PARENS

///////////////// MINI_PP_CAT /////////////////
static_assert(MINI_PP_CAT(4, 2) == 42, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(VALUE_4, 2) == 42, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(VALUE_4, VALUE_2) == 42, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(BEGIN, E_4) == 4, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(4, VALUE_42()) == 442, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(4, EMPTY) == 4, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(4, EMPTY_CALL()) == 4, "MINI_PP_CAT is broken");

///////////////// MINI_PP_CAT_3 /////////////////
static_assert(MINI_PP_CAT_3(4, 2, 0) == 420, "MINI_PP_CAT_3 is broken");
static_assert(MINI_PP_CAT_3(VALUE_4, 2, 0) == 420, "MINI_PP_CAT_3 is broken");
static_assert(MINI_PP_CAT_3(VALUE_4, VALUE_2, 0) == 420, "MINI_PP_CAT_3 is broken");
static_assert(MINI_PP_CAT_3(4, VALUE_42(), 0) == 4420, "MINI_PP_CAT_3 is broken");
static_assert(MINI_PP_CAT_3(4, EMPTY, 0) == 40, "MINI_PP_CAT_3 is broken");
static_assert(MINI_PP_CAT_3(4, EMPTY_CALL(), 0) == 40, "MINI_PP_CAT_3 is broken");

///////////////// MINI_PP_CAT_4 /////////////////
static_assert(MINI_PP_CAT_4(4, 2, 0, 6) == 4206, "MINI_PP_CAT_4 is broken");
static_assert(MINI_PP_CAT_4(VALUE_4, 2, 0, 6) == 4206, "MINI_PP_CAT_4 is broken");
static_assert(MINI_PP_CAT_4(VALUE_4, VALUE_2, 0, 6) == 4206, "MINI_PP_CAT_4 is broken");
static_assert(MINI_PP_CAT_4(4, VALUE_42(), 0, 6) == 44206, "MINI_PP_CAT_4 is broken");
static_assert(MINI_PP_CAT_4(4, EMPTY, 0, 6) == 406, "MINI_PP_CAT_4 is broken");
static_assert(MINI_PP_CAT_4(4, EMPTY_CALL(), 0, 6) == 406, "MINI_PP_CAT_4 is broken");

///////////////// MINI_PP_TO_TEXT /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(42), "42"), "MINI_PP_TO_TEXT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(VALUE_4), "4"), "MINI_PP_TO_TEXT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(VALUE_42()), "42"), "MINI_PP_TO_TEXT is broken");

///////////////// MINI_PP_DEFER /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)()), "VALUE_42 ()"), "MINI_PP_DEFER is broken");

///////////////// MINI_PP_EXPAND /////////////////
static_assert(MINI_PP_EXPAND(42) == 42, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_4) == 4, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_42()) == 42, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_42 MINI_PP_PARENS) == 42, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_EXPAND(2)) == 42, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_EXPAND(VALUE_42())) == 442, "MINI_PP_EXPAND is broken");

///////////////// MINI_PP_EXPAND_2_TIMES /////////////////
static_assert(MINI_PP_CAT(4, MINI_PP_EXPAND_2_TIMES(VALUE_42 MINI_PP_PARENS)) == 442, "MINI_PP_EXPAND_2_TIMES is broken");

///////////////// MINI_PP_EXPAND_3_TIMES /////////////////
static_assert(MINI_PP_CAT(4, MINI_PP_EXPAND_3_TIMES(NEED_2_EXPAND_CALL MINI_PP_PARENS)) == 442, "MINI_PP_EXPAND_3_TIMES is broken");

///////////////// MINI_PP_ASSERT /////////////////
MINI_PP_ASSERT(1)
MINI_PP_ASSERT(ONE)
MINI_PP_ASSERT(ONE_CALL())

///////////////// MINI_PP_TO_TEXT + MINI_PP_CAT /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, 2)), "42"), "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, 2)), "42"), "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, VALUE_2)), "42"), "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(BEGIN, E_4)), "4"), "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");

///////////////// MINI_PP_EXPAND + MINI_PP_DEFER + MINI_PP_TO_TEXT + MINI_PP_PARENS /////////////////
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(VALUE_42 MINI_PP_PARENS)), "42"), "MINI_PP_EXPAND + MINI_PP_DEFER + MINI_PP_TO_TEXT + MINI_PP_PARENS is broken");

#if 0
#define MY_TEST_0(...) SWITCH_WITH_OR_WITHOUT_VA_ARGS(MY_TEST_0, 0, __VA_ARGS__)
#define MY_TEST_0_WITHOUT_VA_ARGS() 42
#define MY_TEST_0_WITH_VA_ARGS(...) 42

static_assert(MY_TEST_0() == 42, "");
static_assert(MY_TEST_0(arga) == 42, "");


#define MY_TEST_1(/*a,*/ ...) SWITCH_WITH_OR_WITHOUT_VA_ARGS(MY_TEST_1, 1, __VA_ARGS__)
#define MY_TEST_1_WITHOUT_VA_ARGS(a) 42
#define MY_TEST_1_WITH_VA_ARGS(a, ...) 42

static_assert(MY_TEST_1(baaar) == 42, "");
static_assert(MY_TEST_1(baaar, arga) == 42, "");


#define MY_TEST_2(a, /*b,*/ ...) SWITCH_WITH_OR_WITHOUT_VA_ARGS(MY_TEST_2, 2, a, __VA_ARGS__)
#define MY_TEST_2_WITHOUT_VA_ARGS(a, b) 42
#define MY_TEST_2_WITH_VA_ARGS(a, b, ...) 42

static_assert(MY_TEST_2(baaar, buuuu) == 42, "");
static_assert(MY_TEST_2(baaar, buuuu, arga) == 42, "");
#endif
