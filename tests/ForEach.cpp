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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if 0
#define MINI_PP_PRIVATE_LOOP_WRAPPER(minLoopIndex, maxLoopIndex, predicate, /*operation,*/ ...) MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND(MINI_PP_PRIVATE_LOOP_WRAPPER_LOOP(MINI_PP_CAT(MINI_PP_PRIVATE_LOOP, minLoopIndex), MINI_PP_CAT(MINI_PP_PARENT, maxLoopIndex), predicate, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_WRAPPER_LOOP(baseLoopFunc, parentFunc, predicate, /*operation,*/ ...) MINI_PP_CAT(MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND(baseLoopFunc parentFunc(predicate, __VA_ARGS__)MINI_PP_PARENT1(predicate, __VA_ARGS__)), FINISH)
#define MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND(...) MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND2(__VA_ARGS__)
#define MINI_PP_PRIVATE_LOOP_WRAPPER_EXPAND2(...) __VA_ARGS__
#endif

#define MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED(minLoopIndex, maxLoopIndex, /*operation,*/ ...) MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED_EXPAND(MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED_LOOP(MINI_PP_CAT(MINI_PP_PRIVATE_LF, minLoopIndex), MINI_PP_CAT(MINI_PP_PARENT, maxLoopIndex), minLoopIndex, maxLoopIndex, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED_LOOP(baseLoopFunc, parentFunc, minLoopIndex, maxLoopIndex, /*operation,*/ ...) baseLoopFunc parentFunc(minLoopIndex, maxLoopIndex, __VA_ARGS__)MINI_PP_PARENT1(minLoopIndex, maxLoopIndex, __VA_ARGS__)
#define MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED_EXPAND(...) MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED_EXPAND2(__VA_ARGS__)
#define MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED_EXPAND2(...) __VA_ARGS__

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if 0
#define MINI_PP_FOR_RANGE(min, max, /*operation,*/ ...) MINI_PP_PRIVATE_FOR_RANGE_IMPL_EXPAND(MINI_PP_CAT_IS_MORE_THAN_1_ARGS(MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_, __VA_ARGS__)(min, max, __VA_ARGS__))
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_EXPAND(...) __VA_ARGS__
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0(min, max, operation) MINI_PP_PRIVATE_LOOP_WRAPPER(min, max, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_PRED, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_OP, max, operation)operation(max)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_PRED(loopIndex, max, operation) MINI_PP_NOT(MINI_PP_IS_EQUAL(loopIndex, max))
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_OP(loopIndex, max, operation) operation(loopIndex)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1(min, max, operation, ...) MINI_PP_PRIVATE_LOOP_WRAPPER(min, max, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_PRED, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_OP, max, operation, __VA_ARGS__)operation(max, __VA_ARGS__)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_PRED(loopIndex, max, operation, ...) MINI_PP_NOT(MINI_PP_IS_EQUAL(loopIndex, max))
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_OP(loopIndex, max, operation, ...) operation(loopIndex, __VA_ARGS__)
#else
#define MINI_PP_FOR_RANGE(min, max, /*operation,*/ ...) MINI_PP_PRIVATE_FOR_RANGE_IMPL_EXPAND(MINI_PP_CAT_IS_MORE_THAN_1_ARGS(MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_, __VA_ARGS__)(min, max, __VA_ARGS__))
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_EXPAND(...) __VA_ARGS__
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0(min, max, operation) MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED(min, max, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_OP, operation)operation(max)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_0_OP(loopIndex, operation) operation(loopIndex)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1(min, max, operation, ...) MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED(min, max, MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_OP, operation, __VA_ARGS__)operation(max, __VA_ARGS__)
#define MINI_PP_PRIVATE_FOR_RANGE_IMPL_WITH_VA_1_OP(loopIndex, operation, ...) operation(loopIndex, __VA_ARGS__)
#endif

#define MY_TEST_RANGE(loopIndex) (loopIndex)
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_FOR_RANGE(0, 5, MY_TEST_RANGE)), "(0)(1)(2)(3)(4)(5)"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_FOR_RANGE(5, 6, MY_TEST_RANGE)), "(5)(6)"), "");

#define MY_TEST_RANGE_PARAM(loopIndex, param) (loopIndex, param)
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_FOR_RANGE(0, 5, MY_TEST_RANGE_PARAM, dummy)), "(0, dummy)(1, dummy)(2, dummy)(3, dummy)(4, dummy)(5, dummy)"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_FOR_RANGE(5, 6, MY_TEST_RANGE_PARAM, dummy)), "(5, dummy)(6, dummy)"), "");

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
#define MINI_PP_SEQ_GET_ELEM_AS_TUPLE(i, s) MINI_PP_PRIVATE_SEQ_GET_ELEM_AS_TUPLE_IMPL(MINI_PP_CAT(MINI_PP_PRIVATE_SGE, i) s)
#define MINI_PP_PRIVATE_SEQ_GET_ELEM_AS_TUPLE_IMPL(...) MINI_PP_TUPLE_GET_ELEM_0((__VA_ARGS__))

static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GET_ELEM_AS_TUPLE(0, (0)(1)(2)(3)(4)(5))), "(0)"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GET_ELEM_AS_TUPLE(1, (0)(1)(2)(3)(4)(5))), "(1)"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GET_ELEM_AS_TUPLE(5, (0)(1)(2)(3)(4)(5))), "(5)"), "");

#define MINI_PP_SEQ_GET_ELEM(i, s) MINI_PP_PRIVATE_SEQ_GET_ELEM_IMPL(MINI_PP_PRIVATE_SEQ_GET_ELEM_IMPL_GET MINI_PP_SEQ_GET_ELEM_AS_TUPLE(i, s))
#define MINI_PP_PRIVATE_SEQ_GET_ELEM_IMPL(...) MINI_PP_PRIVATE_SEQ_GET_ELEM_IMPL2(__VA_ARGS__)
#define MINI_PP_PRIVATE_SEQ_GET_ELEM_IMPL2(...) __VA_ARGS__
#define MINI_PP_PRIVATE_SEQ_GET_ELEM_IMPL_GET(...) __VA_ARGS__

static_assert(MINI_PP_SEQ_GET_ELEM(0, (0)(1)(2)(3)(4)(5)) == 0, "");
static_assert(MINI_PP_SEQ_GET_ELEM(1, (0)(1)(2)(3)(4)(5)) == 1, "");
static_assert(MINI_PP_SEQ_GET_ELEM(4, (0)(1)(2)(3)(4)(5)) == 4, "");
static_assert(MINI_PP_SEQ_GET_ELEM(5, (0)(1)(2)(3)(4)(5)) == 5, "");
static_assert(MINI_PP_SEQ_GET_ELEM(1020, MINI_PP_SEQ_GEN(0, 1024)) == 1020, "");

static_assert(MINI_PP_CAT(4, MINI_PP_SEQ_GET_ELEM(0, (0)(1)(2)(3)(4)(5))) == 40, "");
static_assert(MINI_PP_CAT(4, MINI_PP_SEQ_GET_ELEM(1, (0)(1)(2)(3)(4)(5))) == 41, "");
static_assert(MINI_PP_CAT(4, MINI_PP_SEQ_GET_ELEM(4, (0)(1)(2)(3)(4)(5))) == 44, "");
static_assert(MINI_PP_CAT(4, MINI_PP_SEQ_GET_ELEM(5, (0)(1)(2)(3)(4)(5))) == 45, "");
static_assert(MINI_PP_CAT(4, MINI_PP_SEQ_GET_ELEM(1020, MINI_PP_SEQ_GEN(0, 1024))) == 41020, "");
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MINI_PP_SEQ_SIZE(s) MINI_PP_CAT(MINI_PP_PRIVATE_, MINI_PP_PRIVATE_SS0 s)

static_assert(MINI_PP_SEQ_SIZE((0)) == 1, "");
static_assert(MINI_PP_SEQ_SIZE((0)(1)) == 2, "");
static_assert(MINI_PP_SEQ_SIZE(MINI_PP_SEQ_GEN(0, 1023)) == 1024, "");

static_assert(MINI_PP_CAT(4, MINI_PP_SEQ_SIZE((0))) == 41, "");
static_assert(MINI_PP_CAT(4, MINI_PP_SEQ_SIZE((0)(1))) == 42, "");
static_assert(MINI_PP_CAT(4, MINI_PP_SEQ_SIZE(MINI_PP_SEQ_GEN(0, 1023))) == 41024, "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if 0
#define MINI_PP_SEQ_FOR_EACH(func, s) MINI_PP_PRIVATE_SEQ_FOR_EACH_IMPL(func, s, MINI_PP_SEQ_SIZE(s))
#define MINI_PP_PRIVATE_SEQ_FOR_EACH_IMPL(func, s, sSize) MINI_PP_PRIVATE_LOOP_WRAPPER(0, sSize, MINI_PP_PRIVATE_SEQ_FOR_EACH_IMPL_PRED, MINI_PP_PRIVATE_SEQ_FOR_EACH_IMPL_OP, func, s, sSize)
#define MINI_PP_PRIVATE_SEQ_FOR_EACH_IMPL_PRED(loopIndex, func, s, sSize) MINI_PP_NOT(MINI_PP_IS_EQUAL(loopIndex, sSize))
#define MINI_PP_PRIVATE_SEQ_FOR_EACH_IMPL_OP(loopIndex, func, s, sSize) func MINI_PP_SEQ_GET_ELEM_AS_TUPLE(loopIndex, s)
#else
#define MINI_PP_SEQ_FOR_EACH(func, s) MINI_PP_PRIVATE_LOOP_WRAPPER_FIXED(0, MINI_PP_SEQ_SIZE(s), MINI_PP_PRIVATE_SEQ_FOR_EACH_IMPL_OP, func, s)
#define MINI_PP_PRIVATE_SEQ_FOR_EACH_IMPL_OP(loopIndex, func, s) func MINI_PP_SEQ_GET_ELEM_AS_TUPLE(loopIndex, s)
#endif

#define MYDO(x) (x + 42)
static_assert(MINI_PP_SEQ_GET_ELEM(712, MINI_PP_SEQ_FOR_EACH(MYDO, MINI_PP_SEQ_GEN(0, 712))) == 712 + 42, "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define W_TEST2_PRED(i, s) MINI_PP_NOT(MINI_PP_IS_EQUAL(238, i))
#define W_TEST2_OP(i, s)
#define W_TEST2_END(i, s) i

static_assert(MINI_PP_WHILE(W_TEST2_PRED, W_TEST2_OP, W_TEST2_END, dummy) == 238, "");

static_assert(MINI_PP_IS_LESS(0, 240) == 1, "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MY_LOOP_RECA_END
#define MY_LOOP_RECB_END
#define MY_LOOP_RECA(...) __VA_ARGS__ MY_LOOP_RECB
#define MY_LOOP_RECB(...) __VA_ARGS__ MY_LOOP_RECA

#define LOOP_REC(n, ...) LOOP_REC_END(LOOP_REC_EXPAND(MY_LOOP_RECA MINI_PP_CAT(MINI_PP_PARENT, n)(__VA_ARGS__)))
#define LOOP_REC_EXPAND(x) x
#define LOOP_REC_END(...) LOOP_REC_END2(__VA_ARGS__)
#define LOOP_REC_END2(...) LOOP_REC_END3(__VA_ARGS__ ## _END)
#define LOOP_REC_END3(...) __VA_ARGS__

#define MY_TO_TEXT(...) MY_TO_TEXT_IMPL(__VA_ARGS__)
#define MY_TO_TEXT_IMPL(...) # __VA_ARGS__

#define FUNC() foo, bar,
static_assert(stringsEqual(MY_TO_TEXT(LOOP_REC(4, FUNC())), "foo, bar, foo, bar, foo, bar, foo, bar,"), "");
static_assert(stringsEqual(MY_TO_TEXT(LOOP_REC(12, FUNC())), "foo, bar, foo, bar, foo, bar, foo, bar, foo, bar, foo, bar, foo, bar, foo, bar, foo, bar, foo, bar, foo, bar, foo, bar,"), "");

constexpr const char myString[] = MY_TO_TEXT(LOOP_REC(1024, FUNC()));
static_assert(sizeof(myString) == 9 * 1024 + 1023 + 1, "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MINI_PP_SEQ_CONSUME(n, s) MINI_PP_PRIVATE_SEQ_CONSUME_IMPL_EXPAND(MINI_PP_CAT(MINI_PP_PRIVATE_SC, n) s)
#define MINI_PP_PRIVATE_SEQ_CONSUME_IMPL_EXPAND(...) __VA_ARGS__

static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_CONSUME(5, (0)(1)(2)(3)(4)(5)(6)(7)(8)(9)(10))), "(5)(6)(7)(8)(9)(10)"), "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MINI_PP_SEQ_GET_HEAD_TUPLE(s) MINI_PP_PRIVATE_SEQ_GET_HEAD_TUPLE_IMPL(MINI_PP_PRIVATE_SEQ_GET_HEAD_TUPLE_IMPL_DO s)
#define MINI_PP_PRIVATE_SEQ_GET_HEAD_TUPLE_IMPL_DO(...) (__VA_ARGS__), MINI_PP_NIL
#define MINI_PP_PRIVATE_SEQ_GET_HEAD_TUPLE_IMPL(...) MINI_PP_TUPLE_GET_ELEM_0((__VA_ARGS__))

static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GET_HEAD_TUPLE((0))), "(0)"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_GET_HEAD_TUPLE((0)(1)(2)(3))), "(0)"), "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MINI_PP_PRIVATE_SEQ_GEN_FROM_OTHER(s, ...) MINI_PP_CAT(MINI_PP_PRIVATE_SGFO, MINI_PP_SEQ_SIZE(s))(s, __VA_ARGS__)

static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_PRIVATE_SEQ_GEN_FROM_OTHER((3)(4)(5)(6), foo)), "(foo, (3))(foo, (4))(foo, (5))(foo, (6))"), "");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_PRIVATE_SEQ_GEN_FROM_OTHER((3)(4)(5)(6), foo, bar)), "(foo, bar, (3))(foo, bar, (4))(foo, bar, (5))(foo, bar, (6))"), "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MINI_PP_SEQ_FOR_EACH2(func, s) MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_EXPAND(MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL(func, s, MINI_PP_SEQ_SIZE(s)))
#define MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL(func, s, sSize) MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_LOOP(MINI_PP_CAT(MINI_PP_PRIVATE_LF, 0), MINI_PP_CAT(MINI_PP_PRIVATE_SGFO, sSize)(s, 0, sSize, MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_OP, func)(0, sSize, MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_DUMMY, dumymArg))
#define MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_LOOP(baseLoopFunc, s2) baseLoopFunc s2
#define MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_OP(loopIndex, func, sElemAsTuple) func sElemAsTuple
#define MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_DUMMY(loopIndex, dummyArg) MINI_PP_NIL
#define MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_EXPAND(...) MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_EXPAND2(__VA_ARGS__)
#define MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_EXPAND2(...) __VA_ARGS__

#define MYDO2(x) (foooo, x, baaaar)
//MINI_PP_PRIVATE_SGFO5((0)(1)(2)(3)(4), 0, 5, MINI_PP_PRIVATE_SEQ_FOR_EACH2_IMPL_OP, MYDO2)
//MINI_PP_PRIVATE_SGFO5((0)(1)(2)(3)(4), plop)
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_SEQ_FOR_EACH2(MYDO2, (0)(1)(2)(3)(4))), "(foooo, 0, baaaar)(foooo, 1, baaaar)(foooo, 2, baaaar)(foooo, 3, baaaar)(foooo, 4, baaaar)"), "");

static_assert(MINI_PP_SEQ_GET_ELEM(712, MINI_PP_SEQ_FOR_EACH2(MYDO, MINI_PP_SEQ_GEN(0, 712))) == 712 + 42, "");
static_assert(MINI_PP_SEQ_GET_ELEM(1023, MINI_PP_SEQ_FOR_EACH2(MYDO, MINI_PP_SEQ_GEN(0, 1023))) == 1023 + 42, "");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define MINI_PP_HIDE_RECURSION

#if defined(_MSC_VER) && !defined(__clang__)
#define MINI_PP_PRIVATE_XA3(...) MINI_PP_PRIVATE_XA3_IMPL(__VA_ARGS__)
#define MINI_PP_PRIVATE_XA3_IMPL(...) __VA_ARGS__
#else
#define MINI_PP_PRIVATE_XA3(...) __VA_ARGS__
#endif

// MINI_PP_PRIVATE_XAN => means only (N - 1) expand => means 1 expand for my args + I add (N - 2) expand

//#define MINI_PP_PRIVATE_XA2 MINI_PP_PRIVATE_XA0
//#define MINI_PP_PRIVATE_XA3(...) MINI_PP_PRIVATE_XA2(__VA_ARGS__)
#define MINI_PP_PRIVATE_XA4(...) MINI_PP_PRIVATE_XA3(__VA_ARGS__)
#define MINI_PP_PRIVATE_XA5(...) MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(__VA_ARGS__))
#define MINI_PP_PRIVATE_XA6(...) MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(__VA_ARGS__)))
#define MINI_PP_PRIVATE_XA7(...) MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA8(...) MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA9(...) MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA10(...) MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA3(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA11(...) MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA12(...) MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA13(...) MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA14(...) MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA4(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA15(...) MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA16(...) MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA17(...) MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA18(...) MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA5(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA19(...) MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA20(...) MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA21(...) MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA22(...) MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA6(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA23(...) MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA24(...) MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA25(...) MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA7(MINI_PP_PRIVATE_XA7(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA26(...) MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA7(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA27(...) MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA28(...) MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA29(...) MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA8(MINI_PP_PRIVATE_XA8(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA30(...) MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA8(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA31(...) MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA9(__VA_ARGS__))))
#define MINI_PP_PRIVATE_XA32(...) MINI_PP_PRIVATE_XA10(MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA9(MINI_PP_PRIVATE_XA9(__VA_ARGS__))))

//#define MINI_PP_EXPAND_ALL_64_TIMES(...) MINI_PP_EXPAND_ALL_16_TIMES(MINI_PP_EXPAND_ALL_16_TIMES(MINI_PP_EXPAND_ALL_16_TIMES(MINI_PP_EXPAND_ALL_16_TIMES(MINI_PP_PRIVATE_BASE_EXPAND_FUNC_ALL(__VA_ARGS__)))))
//#define MINI_PP_EXPAND_ALL_256_TIMES(...) MINI_PP_EXPAND_ALL_64_TIMES(MINI_PP_EXPAND_ALL_64_TIMES(MINI_PP_EXPAND_ALL_64_TIMES(MINI_PP_EXPAND_ALL_64_TIMES(MINI_PP_PRIVATE_BASE_EXPAND_FUNC_ALL(__VA_ARGS__)))))
//#define MINI_PP_EXPAND_ALL_1024_TIMES(...) MINI_PP_EXPAND_ALL_256_TIMES(MINI_PP_EXPAND_ALL_256_TIMES(MINI_PP_EXPAND_ALL_256_TIMES(MINI_PP_EXPAND_ALL_256_TIMES(MINI_PP_PRIVATE_BASE_EXPAND_FUNC_ALL(__VA_ARGS__)))))

#define MINI_PP_EXPAND_ALL(n, ...) MINI_PP_CAT(MINI_PP_PRIVATE_XA, n)(__VA_ARGS__)

#define TEST_RECA(x) x MINI_PP_EXPAND(TEST_RECB)MINI_PP_HIDE_RECURSION(x) // Expand not mandatory: to be able to put parent and avoid space
#define TEST_RECB(x) x MINI_PP_EXPAND(TEST_RECA)MINI_PP_HIDE_RECURSION(x) // Expand not mandatory: to be able to put parent and avoid space

#if 0
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA3(TEST_RECA(a)))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(TEST_RECA(a))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(TEST_RECA(a)))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(TEST_RECA(a))))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(MINI_PP_PRIVATE_XA3(TEST_RECA(a)))))))

MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA4(TEST_RECA(b)))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(TEST_RECA(b))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(TEST_RECA(b)))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(TEST_RECA(b))))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(MINI_PP_PRIVATE_XA4(TEST_RECA(b)))))))

MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA5(TEST_RECA(c)))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(TEST_RECA(c))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(TEST_RECA(c)))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(TEST_RECA(c))))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(MINI_PP_PRIVATE_XA5(TEST_RECA(c)))))))

MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA6(TEST_RECA(d)))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(TEST_RECA(d))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(TEST_RECA(d)))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(TEST_RECA(d))))))
MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(MINI_PP_PRIVATE_XA6(TEST_RECA(d)))))))
#endif

//MINI_PP_TO_TEXT(MINI_PP_PRIVATE_XA0(TEST_RECA(a))) // 2
//MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(0, TEST_RECA(a))) // 3
//static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(2, TEST_RECA(a))), "a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 2 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(3, TEST_RECA(a))), "a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 3 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(4, TEST_RECA(a))), "a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 4 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(5, TEST_RECA(a))), "a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 5 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(6, TEST_RECA(a))), "a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 6 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(7, TEST_RECA(a))), "a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 7 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(8, TEST_RECA(a))), "a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 8 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(9, TEST_RECA(a))), "a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 9 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(10, TEST_RECA(a))), "a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 10 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(11, TEST_RECA(a))), "a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 11 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(12, TEST_RECA(a))), "a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 12 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(13, TEST_RECA(a))), "a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 13 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(14, TEST_RECA(a))), "a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 14 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(15, TEST_RECA(a))), "a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 15 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(16, TEST_RECA(a))), "a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 16 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(17, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 17 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(18, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 18 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(19, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 19 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(20, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 20 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(21, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 21 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(22, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 22 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(23, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 23 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(24, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 24 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(25, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 25 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(26, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 26 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(27, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 27 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(28, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 28 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(29, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 29 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(30, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 30 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(31, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECB(a)"), "MINI_PP_EXPAND_ALL 31 is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL(32, TEST_RECA(a))), "a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a TEST_RECA(a)"), "MINI_PP_EXPAND_ALL 32 is broken");


//static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_EXPAND_ALL_64_TIMES(TEST_REC())),
//    "a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a "
//    "TEST_REC(a)"), "MINI_PP_EXPAND_ALL_64_TIMES is broken");    

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPEAT0(...)
#define REPEAT1(...) __VA_ARGS__
#define REPEAT2(...) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__)
#define REPEAT3(...) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__)
#define REPEAT4(...) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__)
#define REPEAT5(...) REPEAT2(__VA_ARGS__) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__)
#define REPEAT6(...) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__) REPEAT1(__VA_ARGS__) REPEAT1(__VA_ARGS__)
#define REPEAT7(...) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__) REPEAT1(__VA_ARGS__)
#define REPEAT8(...) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__)
#define REPEAT9(...) REPEAT3(__VA_ARGS__) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__)
#define REPEAT10(...) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__) REPEAT2(__VA_ARGS__) REPEAT2(__VA_ARGS__)
#define REPEAT11(...) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__) REPEAT2(__VA_ARGS__)
#define REPEAT12(...) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__)
#define REPEAT13(...) REPEAT4(__VA_ARGS__) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__)
#define REPEAT14(...) REPEAT4(__VA_ARGS__) REPEAT4(__VA_ARGS__) REPEAT3(__VA_ARGS__) REPEAT3(__VA_ARGS__)
#define REPEAT15(...) REPEAT4(__VA_ARGS__) REPEAT4(__VA_ARGS__) REPEAT4(__VA_ARGS__) REPEAT3(__VA_ARGS__)
#define REPEAT16(...) REPEAT4(__VA_ARGS__) REPEAT4(__VA_ARGS__) REPEAT4(__VA_ARGS__) REPEAT4(__VA_ARGS__)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if 0
#define MINI_PP_TUPLE_FOR_EACH(f, t) MINI_PP_PRIVATE_TUPLE_FOR_EACH_IMPL(MINI_PP_TUPLE_PUSH_FRONT(t, f))
#define MINI_PP_PRIVATE_TUPLE_FOR_EACH_IMPL(tWithF) MINI_PP_PRIVATE_TUPLE_FOR_EACH_IMPL_EXPAND(MINI_PP_PRIVATE_TUPLE_FOR_EACH_IMPL_FOR_EACH tWithF)
#define MINI_PP_PRIVATE_TUPLE_FOR_EACH_IMPL_FOR_EACH(...) MINI_PP_FOR_EACH(__VA_ARGS__)
#define MINI_PP_PRIVATE_TUPLE_FOR_EACH_IMPL_EXPAND(...) __VA_ARGS__

#define MY_ENUM \
    ( \
        A, \
        B, \
        C, \
        D \
    )

#define DECLARE_ENUM_VALUE(v) v,
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_FOR_EACH(DECLARE_ENUM_VALUE, MY_ENUM)), "A, B, C, D,"), "");


MINI_PP_TUPLE_FOR_EACH(DECLARE_ENUM_VALUE, ())

enum class MyEnum
{
    First = 0,

    MINI_PP_FOR_EACH(DECLARE_ENUM_VALUE, A, B, C)
};

static_assert(static_cast<int>(MyEnum::A) == 1, "");
static_assert(static_cast<int>(MyEnum::C) == 3, "");
#endif

#if 0
#define MANAGE_TO_STRING(enumName, value) case enumName::value: return #value;
#define MANAGE_FROM_STRING(enumName, value) { std::string(#value), enumName::value },

#define DECLARE_ENUM(enumName, ...)                                                 \
    enum class enumName                                                             \
    {                                                                               \
        MINI_PP_FOR_EACH(DECLARE_ENUM_VALUE, __VA_ARGS__)                           \
    };                                                                              \
    constexpr std::string_view enumName ## ToString(enumName value) noexcept        \
    {                                                                               \
        switch (value)                                                              \
        {                                                                           \
            MINI_PP_FOR_EACH_WITH_PARAMS(MANAGE_TO_STRING, enumName, __VA_ARGS__)   \
        }                                                                           \
        return {};                                                                  \
    }                                                                               \
    std::optional<enumName> enumName ## FromString(const std::string& str)          \
    {                                                                               \
        static const std::unordered_map<std::string, enumName> map = {              \
            MINI_PP_FOR_EACH_WITH_PARAMS(MANAGE_FROM_STRING, enumName, __VA_ARGS__) \
        };                                                                          \
        if (auto it = map.find(str); it != map.end())                               \
            return it->second;                                                      \
        return std::nullopt;                                                        \
    }

#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>


DECLARE_ENUM(MyEnum2,
    ValueA,
    ValueB,
    ValueC,
    ValueD
)

static_assert(static_cast<int>(MyEnum2::ValueA) == 0, "");
static_assert(static_cast<int>(MyEnum2::ValueD) == 3, "");

static_assert(stringsEqual(MyEnum2ToString(MyEnum2::ValueA).data(), "ValueA"), "");
static_assert(stringsEqual(MyEnum2ToString(MyEnum2::ValueD).data(), "ValueD"), "");
#endif

#define OPAR (
#define CPAR )

#define BAR0(f, t) f t BAR1 OPAR f
#define BAR1(f, t) f t BAR2 OPAR f
#define BAR2(f, t) f t BAR3 OPAR f
#define BAR3(f, t) f t BAR4 OPAR f
#define BAR4(f, t) f t BAR5 OPAR f
#define BAR5(f, t) f t BAR6 OPAR f

#define FOOO0(...),(__VA_ARGS__))FOOO1
#define FOOO1(...),(__VA_ARGS__))FOOO2
#define FOOO2(...),(__VA_ARGS__))FOOO3
#define FOOO3(...),(__VA_ARGS__))FOOO4
#define FOOO4(...),(__VA_ARGS__))FOOO5
#define FOOO5(...),(__VA_ARGS__))FOOO6


//#define MY_FE(f, s) MINI_PP_EXPAND_ALL(MINI_PP_SEQ_SIZE(s), MY_FRE_IMPL1(BAR0 OPAR f FOOO0 s))
#define MY_FE(f, s) MY_FE_END(f, FOOO0 s)
#define MY_FE_END(f, ...) BAR0 OPAR f __VA_ARGS__
#define MY_FRE_IMPL1(...) __VA_ARGS__
#define MY_FRE_IMPL2(...) MY_FRE_IMPL3(__VA_ARGS__)
#define MY_FRE_IMPL3(...) MY_FRE_IMPL4(__VA_ARGS__)
#define MY_FRE_IMPL4(...) MY_FRE_IMPL5(__VA_ARGS__)
#define MY_FRE_IMPL5(...) MY_FRE_IMPL6(__VA_ARGS__)
#define MY_FRE_IMPL6(...) MY_FRE_IMPL7(__VA_ARGS__)
#define MY_FRE_IMPL7(...) MY_FRE_IMPL8(__VA_ARGS__)
#define MY_FRE_IMPL8(...) __VA_ARGS__



#define PR(x) (x + 42)

//MY_TO_TEXT
#define MY_PAREN_CONTENT1 MY_PAREN_CONTENT2
#define MY_PAREN_CONTENT2 MY_PAREN_CONTENT3
#define MY_PAREN_CONTENT3 MY_PAREN_CONTENT4
#define MY_PAREN_CONTENT4 MY_PAREN_CONTENT5
#define MY_PAREN_CONTENT5 MY_PAREN_CONTENT6
#define MY_PAREN_CONTENT6 MY_PAREN_CONTENT7
#define MY_PAREN_CONTENT7 MY_PAREN_CONTENT8
#define MY_PAREN_CONTENT8 MY_PAREN_CONTENT9
#define MY_PAREN_CONTENT9 MY_PAREN_CONTENT10
#define MY_PAREN_CONTENT10 OPAR DO,

REPEAT5(MY_PAREN_CONTENT1) FOOO0 (0)(1)(2)(3)(4)

//MY_FE(PR, (0)(1)(2)(3)(4))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(3, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(4, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(5, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(6, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(7, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(8, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(9, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(10, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(11, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MINI_PP_EXPAND_ALL(12, MY_FE(PR, (0)(1)(2)(3)(4))))
//MY_TO_TEXT(MY_FE(PR, (0)(1)(2)(3)(4)(5)(6)(7)(8)(9)(10)))
//MY_TO_TEXT(MY_FE(PR, (0)(1)(2)(3)(4)))
//BAR0 OPAR PR, FOOO0(0)(1)(2)(3)(4)
//static_assert(MINI_PP_SEQ_GET_ELEM(3, EXP(BAR0 OPAR PR, FOOO0(0)(1)(2)(3)(4))) == 3 + 42, "");

#define OPAR (
#define CPAR )

#define AA() a
#define BB OPAR
#define CC CPAR
#define T BB CC
//MINI_PP_EXPAND(AA T)
