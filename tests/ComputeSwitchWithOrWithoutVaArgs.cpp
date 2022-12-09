#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#include "TestUtility.hpp"
#endif

#define ARGS_EMPTY
#define ARGS_EMPTY_CALL()

#define COMPUTE_TEST_0_FIXED(...) MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, __VA_ARGS__)
#define COMPUTE_TEST_1_FIXED(/*fixedA,*/ ...) MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, __VA_ARGS__)
#define COMPUTE_TEST_2_FIXED(fixedA, /*fixedB,*/ ...) MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, fixedA, __VA_ARGS__)
#define COMPUTE_TEST_3_FIXED(fixedA, fixedB, /*fixedC,*/ ...) MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, fixedA, fixedB, __VA_ARGS__)

///////////////// MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS TEST_0 /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_0_FIXED()), "TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_0_FIXED(argA)), "TEST_0_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_0_FIXED(argA, argB)), "TEST_0_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_0_FIXED(ARGS_EMPTY)), "TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_0_FIXED(ARGS_EMPTY_CALL())), "TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_0_FIXED())), "4TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_0_FIXED(argA))), "4TEST_0_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_0_FIXED(argA, argB))), "4TEST_0_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_0_FIXED(ARGS_EMPTY))), "4TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_0_FIXED(ARGS_EMPTY_CALL()))), "4TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0)), "TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, argA)), "TEST_0_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, argA, argB)), "TEST_0_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, ARGS_EMPTY)), "TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, ARGS_EMPTY_CALL())), "TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0))), "4TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, argA))), "4TEST_0_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, argA, argB))), "4TEST_0_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, ARGS_EMPTY))), "4TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, ARGS_EMPTY_CALL()))), "4TEST_0_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");

///////////////// MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS TEST_1 /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_1_FIXED(argA)), "TEST_1_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_1_FIXED(argA, argB)), "TEST_1_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_1_FIXED(argA, argB, argC)), "TEST_1_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_1_FIXED(argA))), "4TEST_1_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_1_FIXED(argA, argB))), "4TEST_1_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_1_FIXED(argA, argB, argC))), "4TEST_1_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA)), "TEST_1_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA, argB)), "TEST_1_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA, argB, argC)), "TEST_1_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA))), "4TEST_1_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA, argB))), "4TEST_1_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA, argB, argC))), "4TEST_1_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");

///////////////// MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS TEST_2 /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_2_FIXED(argA, argB)), "TEST_2_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_2_FIXED(argA, argB, argC)), "TEST_2_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_2_FIXED(argA, argB, argC, argD)), "TEST_2_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_2_FIXED(argA, argB))), "4TEST_2_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_2_FIXED(argA, argB, argC))), "4TEST_2_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_2_FIXED(argA, argB, argC, argD))), "4TEST_2_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB)), "TEST_2_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB, argC)), "TEST_2_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB, argC, argD)), "TEST_2_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB))), "4TEST_2_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB, argC))), "4TEST_2_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB, argC, argD))), "4TEST_2_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");

///////////////// MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS TEST_3 /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_3_FIXED(argA, argB, argC)), "TEST_3_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_3_FIXED(argA, argB, argC, argD)), "TEST_3_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(COMPUTE_TEST_3_FIXED(argA, argB, argC, argD, argE)), "TEST_3_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_3_FIXED(argA, argB, argC))), "4TEST_3_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_3_FIXED(argA, argB, argC, argD))), "4TEST_3_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, COMPUTE_TEST_3_FIXED(argA, argB, argC, argD, argE))), "4TEST_3_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC)), "TEST_3_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC, argD)), "TEST_3_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC, argD, argE)), "TEST_3_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC))), "4TEST_3_FIXED_WITHOUT_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC, argD))), "4TEST_3_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC, argD, argE))), "4TEST_3_FIXED_WITH_VA_ARGS"), "MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");