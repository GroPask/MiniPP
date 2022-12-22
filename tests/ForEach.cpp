#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#include "TestUtility.hpp"
#endif

#define IDENT(x) x
#define IDENT_FOR_EACH(...) MINI_PP_FOR_EACH(IDENT, __VA_ARGS__)
#define TO_TEXT_WITH_PARAMS(params, x) MINI_PP_TO_TEXT(MINI_PP_CAT(params, x))
#define IDENT_WITH_WITH_PARAMS(params, x) params x
#define IDENT_WITH_PARAMS_FOR_EACH(params, ...) MINI_PP_FOR_EACH_WITH_PARAMS(IDENT_WITH_WITH_PARAMS, params, __VA_ARGS__)

///////////////// MINI_PP_FOR_EACH /////////////////
enum class EnumForEach
{
    First = 0,

    #define DECLARE_VALUE(x) MINI_PP_CAT(Value, x),

    MINI_PP_FOR_EACH(DECLARE_VALUE)
    MINI_PP_FOR_EACH(DECLARE_VALUE, A)
    MINI_PP_FOR_EACH(DECLARE_VALUE, B, C, D)

    #define DECLARE_VALUES(...) MINI_PP_FOR_EACH(DECLARE_VALUE MINI_PP_COMMA_IF_ARG(__VA_ARGS__) __VA_ARGS__)

    DECLARE_VALUES()
    DECLARE_VALUES(E)
    DECLARE_VALUES(F, G, H)
};

static_assert(static_cast<int>(EnumForEach::ValueA) == 1, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueB) == 2, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueC) == 3, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueD) == 4, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueE) == 5, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueF) == 6, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueG) == 7, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueH) == 8, "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_FOR_EACH(MINI_PP_TO_TEXT, A), "A"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_FOR_EACH(MINI_PP_TO_TEXT, B, C, D), "BCD"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_FOR_EACH(IDENT, 2))), "42"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_FOR_EACH(IDENT, 2, 3, 4))), "42 3 4"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, IDENT_FOR_EACH(2))), "42"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, IDENT_FOR_EACH(2, 3, 4))), "42 3 4"), "MINI_PP_FOR_EACH is broken");

///////////////// MINI_PP_FOR_EACH_WITH_PARAMS /////////////////
enum class EnumForEachWithParams
{
    First = 0,

    #define DECLARE_VALUE_WITH_PARAMS(param, x) MINI_PP_CAT_3(Value, param, x),

    MINI_PP_FOR_EACH_WITH_PARAMS(DECLARE_VALUE_WITH_PARAMS, Foo)
    MINI_PP_FOR_EACH_WITH_PARAMS(DECLARE_VALUE_WITH_PARAMS, Foo, A)
    MINI_PP_FOR_EACH_WITH_PARAMS(DECLARE_VALUE_WITH_PARAMS, Foo, B, C, D)

    #define DECLARE_VALUES_WITH_PARAMS(...) MINI_PP_FOR_EACH_WITH_PARAMS(DECLARE_VALUE_WITH_PARAMS, Bar MINI_PP_COMMA_IF_ARG(__VA_ARGS__) __VA_ARGS__)

    DECLARE_VALUES_WITH_PARAMS()
    DECLARE_VALUES_WITH_PARAMS(E)
    DECLARE_VALUES_WITH_PARAMS(F, G, H)
};

static_assert(static_cast<int>(EnumForEachWithParams::ValueFooA) == 1, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueFooB) == 2, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueFooC) == 3, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueFooD) == 4, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueBarE) == 5, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueBarF) == 6, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueBarG) == 7, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueBarH) == 8, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(stringsEqual(MINI_PP_FOR_EACH_WITH_PARAMS(TO_TEXT_WITH_PARAMS, Foo, A), "FooA"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_FOR_EACH_WITH_PARAMS(TO_TEXT_WITH_PARAMS, Foo, B, C, D), "FooBFooCFooD"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_FOR_EACH_WITH_PARAMS(IDENT_WITH_WITH_PARAMS, Bar, 2))), "4Bar 2"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, MINI_PP_FOR_EACH_WITH_PARAMS(IDENT_WITH_WITH_PARAMS, Bar, 2, 3, 4))), "4Bar 2 Bar 3 Bar 4"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, IDENT_WITH_PARAMS_FOR_EACH(Bar, 2))), "4Bar 2"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, IDENT_WITH_PARAMS_FOR_EACH(Bar, 2, 3, 4))), "4Bar 2 Bar 3 Bar 4"), "MINI_PP_FOR_EACH is broken");

#define MINI_PP_WHILE(predicate, operation, endOperation, state) MINI_PP_PRIVATE_W0(predicate, operation, endOperation, state)

#define W_TEST_PRED(i, s) MINI_PP_NOT(MINI_PP_IS_EQUAL(0, MINI_PP_TUPLE_GET_ELEM_0(s)))
#define W_TEST_OP(i, s) (MINI_PP_DEC(MINI_PP_TUPLE_GET_ELEM_0(s)), MINI_PP_INC(MINI_PP_TUPLE_GET_ELEM_1(s)))
#define W_TEST_END(i, s) MINI_PP_TUPLE_GET_ELEM_1(s)

static_assert(MINI_PP_WHILE(W_TEST_PRED, W_TEST_OP, W_TEST_END, (233, 0)) == 233, "");

#define MINI_PP_HIDE_RECURSION

#define PARENT8(...) (__VA_ARGS__)(__VA_ARGS__)(__VA_ARGS__)(__VA_ARGS__)(__VA_ARGS__)(__VA_ARGS__)(__VA_ARGS__)(__VA_ARGS__)
#define PARENT64(...) PARENT8(__VA_ARGS__)PARENT8(__VA_ARGS__)PARENT8(__VA_ARGS__)PARENT8(__VA_ARGS__)PARENT8(__VA_ARGS__)PARENT8(__VA_ARGS__)PARENT8(__VA_ARGS__)PARENT8(__VA_ARGS__)
#define PARENT512(...) PARENT64(__VA_ARGS__)PARENT64(__VA_ARGS__)PARENT64(__VA_ARGS__)PARENT64(__VA_ARGS__)PARENT64(__VA_ARGS__)PARENT64(__VA_ARGS__)PARENT64(__VA_ARGS__)PARENT64(__VA_ARGS__)
#define PARENT4096(...) PARENT512(__VA_ARGS__)PARENT512(__VA_ARGS__)PARENT512(__VA_ARGS__)PARENT512(__VA_ARGS__)PARENT512(__VA_ARGS__)PARENT512(__VA_ARGS__)PARENT512(__VA_ARGS__)PARENT512(__VA_ARGS__)

//#define MINI_PP_LOOP(func, ...) MINI_PP_PRIVATE_LOOP_IMPL_MANAGE_END(MINI_PP_PRIVATE_L0 PARENT4096(func, __VA_ARGS__))
//#define MINI_PP_PRIVATE_LOOP_IMPL_MANAGE_END(...) MINI_PP_CAT(__VA_ARGS__, MINI_PP_PRIVATE_LE)

//#define MY_TEST_DO(a) + a
//#define MY_TEST(a) MINI_PP_LOOP(MY_TEST_DO, a)

//MY_TEST PARENT512(MINI_PP_INC(a))
//static_assert(0 MY_TEST(1) == 4096, "");

#define CLOSE() )
#define CLOSE_2() CLOSE()CLOSE()
#define CLOSE_4() CLOSE_2()CLOSE_2()
#define CLOSE_8() CLOSE_4()CLOSE_4()
#define CLOSE_16() CLOSE_8()CLOSE_8()
#define CLOSE_32() CLOSE_16()CLOSE_16()
#define CLOSE_64() CLOSE_32()CLOSE_32()
#define CLOSE_128() CLOSE_64()CLOSE_64()
#define CLOSE_256() CLOSE_128()CLOSE_128()
#define CLOSE_512() CLOSE_256()CLOSE_256()
#define CLOSE_1024() CLOSE_512()CLOSE_512()
#define CLOSE_2048() CLOSE_1024()CLOSE_1024()
#define CLOSE_4096() CLOSE_2048()CLOSE_2048()

#define A(f, a) B(f, f(a)
#define B(f, a) C(f, f(a)
#define C(f, a) D(f, f(a)
#define D(f, a) E(f, f(a)
#define E(f, a) a

#define MY_FOO(f, a) A(f, a) ))))
static_assert(MY_FOO(MINI_PP_INC, 0) == 4, "");

static_assert(MINI_PP_IF_ELSE(MINI_PP_IS_EQUAL(0, 3), 42, 24) == 24, "");
static_assert(MINI_PP_IF_ELSE(MINI_PP_IS_EQUAL(3, 3), 42, 24) == 42, "");

//#define MINI_PP_SEQ_GEN(min, max, params) MINI_PP_PRIVATE_SEQ_GEN_IMPL(MINI_PP_CAT(MINI_PP_PRIVATE_SG, min), MINI_PP_CAT(MINI_PP_PARENT, max), max, params)
//#define MINI_PP_PRIVATE_SEQ_GEN_IMPL(startFunc, parentFunc, max, params) MINI_PP_PRIVATE_SEQ_GEN_IMPL_END(startFunc parentFunc(max, params)MINI_PP_PARENT1(max, params))
//#define MINI_PP_PRIVATE_SEQ_GEN_IMPL_END(...) MINI_PP_CAT(__VA_ARGS__, FINISH)
//MINI_PP_SEQ_GEN(1019, 1024, dummy)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MINI_PP_PRIVATE_LOOP_WRAPPER(minLoopIndex, maxLoopIndex, predicate, /*operation,*/ ...) MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND(MINI_PP_PRIVATE_LOOP_WRAPPER_LOOP(MINI_PP_CAT(MINI_PP_PRIVATE_LOOP, minLoopIndex), MINI_PP_CAT(MINI_PP_PARENT, maxLoopIndex), predicate, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_WRAPPER_LOOP(baseLoopFunc, parentFunc, predicate, /*operation,*/ ...) MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND(baseLoopFunc parentFunc(predicate, __VA_ARGS__)MINI_PP_PARENT1(predicate, __VA_ARGS__)) ## FINISH
#define MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND(...) MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND2(__VA_ARGS__)
#define MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND2(...) __VA_ARGS__

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MINI_PP_FOR_RANGE(min, max, /*operation,*/ ...) MINI_PP_PRIVATE_FOR_RANGE_IMPL_EXPAND(MINI_PP_CAT_IS_MORE_THAN_1_ARGS(MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_, __VA_ARGS__)(min, max, __VA_ARGS__))
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_EXPAND(...) __VA_ARGS__
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0(min, max, operation) MINI_PP_PRIVATE_LOOP_WRAPPER(min, max, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_PRED, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_OP, max, operation)operation(max)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_PRED(loopIndex, max, operation) MINI_PP_NOT(MINI_PP_IS_EQUAL(loopIndex, max))
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_OP(loopIndex, max, operation) operation(loopIndex)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1(min, max, operation, ...) MINI_PP_PRIVATE_LOOP_WRAPPER(min, max, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_PRED, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_OP, max, operation, __VA_ARGS__)operation(max, __VA_ARGS__)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_PRED(loopIndex, max, operation, ...) MINI_PP_NOT(MINI_PP_IS_EQUAL(loopIndex, max))
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_OP(loopIndex, max, operation, ...) operation(loopIndex, __VA_ARGS__)

#define MY_TEST_RANGE(loopIndex) (loopIndex)
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_FOR_RANGE(0, 5, MY_TEST_RANGE)), "(0)(1)(2)(3)(4)(5)"), "");

#define MY_TEST_RANGE_PARAM(loopIndex, param) (loopIndex, param)
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_FOR_RANGE(0, 5, MY_TEST_RANGE_PARAM, dummy)), "(0, dummy)(1, dummy)(2, dummy)(3, dummy)(4, dummy)(5, dummy)"), "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MINI_PP_SEQ_GEN(min, /*max,*/ ...) MINI_PP_PRIVATE_SEQ_GEN_IMPL_EXPAND(MINI_PP_CAT_IS_MORE_THAN_1_ARGS(MINI_PP_PRIVATE_SEQ_GEN_IMPL_WITH_VA_, __VA_ARGS__)(min, __VA_ARGS__))
#define MINI_PP_PRIVATE_SEQ_GEN_IMPL_EXPAND(...) __VA_ARGS__
#define MINI_PP_PRIVATE_SEQ_GEN_IMPL_WITH_VA_0(min, max) MINI_PP_FOR_RANGE(min, max, MINI_PP_PRIVATE_SEQ_GEN_IMPL_OP)
#define MINI_PP_PRIVATE_SEQ_GEN_IMPL_WITH_VA_1(min, max, ...) MINI_PP_FOR_RANGE(min, max, MINI_PP_PRIVATE_SEQ_GEN_IMPL_OP, __VA_ARGS__)
#define MINI_PP_PRIVATE_SEQ_GEN_IMPL_OP(...) (__VA_ARGS__)

static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GEN(1022, 1024)), "(1022)(1023)(1024)"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GEN(0, 5)), "(0)(1)(2)(3)(4)(5)"), "");

static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GEN(1022, 1024, dummy)), "(1022, dummy)(1023, dummy)(1024, dummy)"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GEN(0, 5, dummy)), "(0, dummy)(1, dummy)(2, dummy)(3, dummy)(4, dummy)(5, dummy)"), "");

static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GEN(1022, 1024, foo, bar)), "(1022, foo, bar)(1023, foo, bar)(1024, foo, bar)"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GEN(0, 5, foo, bar)), "(0, foo, bar)(1, foo, bar)(2, foo, bar)(3, foo, bar)(4, foo, bar)(5, foo, bar)"), "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define W_TEST2_PRED(i, s) MINI_PP_NOT(MINI_PP_IS_EQUAL(238, i))
#define W_TEST2_OP(i, s)
#define W_TEST2_END(i, s) i

static_assert(MINI_PP_WHILE(W_TEST2_PRED, W_TEST2_OP, W_TEST2_END, dummy) == 238, "");

static_assert(MINI_PP_IS_LESS(0, 240) == 1, "");



//#define MINI_PP_SEQ_GENERATE(min, max) MINI_PP_ASSERT(MINI_PP_IS_LESS_OR_EQUAL(min, max))MINI_PP_PRIVATE_SG0(min, max)(MINI_PP_INC(min), max)

//#define MINI_PP_PRIVATE_SGE(a,b)
//#define MINI_PP_PRIVATE_SG0(a,b)(a)MINI_PP_IF_ELSE(MINI_PP_IS_EQUAL(a,b),MINI_PP_PRIVATE_SGE,MINI_PP_PRIVATE_SG1)



//#define MINI_PP_PRIVATE_W0(p,o,e,s)MINI_PP_IF_ELSE(p(s),MINI_PP_PRIVATE_W1,MINI_PP_PRIVATE_WE)(p,o,e,MINI_PP_IF(p(s),o)(s))