#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#endif

////////////////////////////////////////////////////////////
// Switch With Or Without Va Args
// Should not be used any more but keep it here for tests
////////////////////////////////////////////////////////////

#define MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(prefix, /*nbFixedArgs,*/ ...) MINI_PP_EXPAND_2_TIMES(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(MINI_PP_PRIVATE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL, 2, prefix, __VA_ARGS__)(prefix, __VA_ARGS__))
#define MINI_PP_PRIVATE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_WITHOUT_VA_ARGS(prefix, nbFixedArgs) MINI_PP_EXPAND(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(prefix, nbFixedArgs)())
#define MINI_PP_PRIVATE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_WITH_VA_ARGS(prefix, nbFixedArgs, ...) MINI_PP_EXPAND(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(prefix, nbFixedArgs, __VA_ARGS__)(__VA_ARGS__))

////////////////////////////////////////////////////////////

#define ARGS_EMPTY
#define ARGS_EMPTY_CALL()

#define TEST_0_FIXED(...) MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, __VA_ARGS__)
#define TEST_0_FIXED_WITHOUT_VA_ARGS() 0
#define TEST_0_FIXED_WITH_VA_ARGS(...) 1

#define TEST_1_FIXED(/*fixedA,*/ ...) MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, __VA_ARGS__)
#define TEST_1_FIXED_WITHOUT_VA_ARGS(fixedA) 2
#define TEST_1_FIXED_WITH_VA_ARGS(fixedA, ...) 3

#define TEST_2_FIXED(fixedA, /*fixedB,*/ ...) MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, fixedA, __VA_ARGS__)
#define TEST_2_FIXED_WITHOUT_VA_ARGS(fixedA, fixedB) 4
#define TEST_2_FIXED_WITH_VA_ARGS(fixedA, fixedB, ...) 5

#define TEST_3_FIXED(fixedA, fixedB, /*fixedC,*/ ...) MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, fixedA, fixedB, __VA_ARGS__)
#define TEST_3_FIXED_WITHOUT_VA_ARGS(fixedA, fixedB, fixedC) 6
#define TEST_3_FIXED_WITH_VA_ARGS(fixedA, fixedB, fixedC, ...) 7

///////////////// MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS TEST_0 /////////////////
static_assert(TEST_0_FIXED() == 0, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_0_FIXED(argA) == 1, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_0_FIXED(argA, argB) == 1, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_0_FIXED(ARGS_EMPTY) == 0, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_0_FIXED(ARGS_EMPTY_CALL()) == 0, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_0_FIXED()) == 40, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_0_FIXED(argA)) == 41, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_0_FIXED(argA, argB)) == 41, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_0_FIXED(ARGS_EMPTY)) == 40, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_0_FIXED(ARGS_EMPTY_CALL())) == 40, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0) == 0, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, argA) == 1, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, argA, argB) == 1, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, ARGS_EMPTY) == 0, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, ARGS_EMPTY_CALL()) == 0, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0)) == 40, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, argA)) == 41, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, argA, argB)) == 41, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, ARGS_EMPTY)) == 40, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_0_FIXED, 0, ARGS_EMPTY_CALL())) == 40, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");

///////////////// MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS TEST_1 /////////////////
static_assert(TEST_1_FIXED(argA) == 2, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_1_FIXED(argA, argB) == 3, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_1_FIXED(argA, argB, argC) == 3, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_1_FIXED(argA)) == 42, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_1_FIXED(argA, argB)) == 43, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_1_FIXED(argA, argB, argC)) == 43, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA) == 2, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA, argB) == 3, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA, argB, argC) == 3, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA)) == 42, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA, argB)) == 43, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_1_FIXED, 1, argA, argB, argC)) == 43, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");

///////////////// MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS TEST_2 /////////////////
static_assert(TEST_2_FIXED(argA, argB) == 4, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_2_FIXED(argA, argB, argC) == 5, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_2_FIXED(argA, argB, argC, argD) == 5, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_2_FIXED(argA, argB)) == 44, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_2_FIXED(argA, argB, argC)) == 45, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_2_FIXED(argA, argB, argC, argD)) == 45, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB) == 4, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB, argC) == 5, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB, argC, argD) == 5, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB)) == 44, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB, argC)) == 45, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_2_FIXED, 2, argA, argB, argC, argD)) == 45, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");

///////////////// MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS TEST_3 /////////////////
static_assert(TEST_3_FIXED(argA, argB, argC) == 6, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_3_FIXED(argA, argB, argC, argD) == 7, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(TEST_3_FIXED(argA, argB, argC, argD, argE) == 7, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_3_FIXED(argA, argB, argC)) == 46, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_3_FIXED(argA, argB, argC, argD)) == 47, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, TEST_3_FIXED(argA, argB, argC, argD, argE)) == 47, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC) == 6, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC, argD) == 7, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC, argD, argE) == 7, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC)) == 46, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC, argD)) == 47, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS(TEST_3_FIXED, 3, argA, argB, argC, argD, argE)) == 47, "MINI_PP_SWITCH_WITH_OR_WITHOUT_VA_ARGS is broken");
