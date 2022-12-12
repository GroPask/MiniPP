#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#endif

///////////////// MINI_PP_MAX_NB_ARGS /////////////////
static_assert(MINI_PP_MAX_NB_ARGS > 0, "MINI_PP_MAX_NB_ARGS is broken");

///////////////// MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE /////////////////
namespace ArgSeqMaxMinusOneTrueThenFalse
{
    template <class... T>
    struct Check;

    template <class F, class... T>
    struct Check<F, T...>
    {
        static constexpr bool doCheck(F first, T... tail)
        {
            return (first == 1 && Check<T...>::doCheck(tail...));
        }
    };

    template <class F>
    struct Check<F>
    {
        static constexpr bool doCheck(F first)
        {
            return (first == 0);
        }
    };

    template <class... T>
    constexpr bool doCheck(T... args)
    {
        static_assert(sizeof...(args) == MINI_PP_MAX_NB_ARGS, "MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE is broken");

        return Check<T...>::doCheck(args...);
    }
}

static_assert(ArgSeqMaxMinusOneTrueThenFalse::doCheck(MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE), "MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE is broken");

///////////////// MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 /////////////////
namespace ArgSeqMaxTo0
{
    template <class... T>
    struct Check;

    template <class F, class... T>
    struct Check<F, T...>
    {
        static constexpr bool doCheck(F first, T... tail)
        {
            return ((first == sizeof...(tail)) && Check<T...>::doCheck(tail...));;
        }
    };

    template <class F>
    struct Check<F>
    {
        static constexpr bool doCheck(F first)
        {
            return (first == 0);
        }
    };

    template <class... T>
    constexpr bool doCheck(T... args)
    {
        static_assert(sizeof...(args) == (MINI_PP_MAX_NB_ARGS + 1), "MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 is broken");

        return Check<T...>::doCheck(args...);
    }
}

static_assert(ArgSeqMaxTo0::doCheck(MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0), "MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 is broken");

///////////////// MINI_PP_PRIVATE_GET_ARG_INDEX_MAX /////////////////
static_assert(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX)(MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE, 42, dummy)) == 42, "MINI_PP_PRIVATE_GET_ARG_INDEX_MAX is broken");
static_assert(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX)(MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0, dummy)) == 0, "MINI_PP_PRIVATE_GET_ARG_INDEX_MAX is broken");

///////////////// MINI_PP_PRIVATE_LOOP_UNROLL_ /////////////////
#define MY_FUNC(params, x) + x
#define CALL_UNROLL(unrollFunc, ...) MINI_PP_EXPAND(unrollFunc(__VA_ARGS__))
static_assert(42 CALL_UNROLL(MINI_PP_CAT(MINI_PP_PRIVATE_LOOP_UNROLL_, MINI_PP_MAX_NB_ARGS), MY_FUNC, dummyParams, MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE) == 42 + MINI_PP_MAX_NB_ARGS - 1, "MINI_PP_PRIVATE_LOOP_UNROLL_ is broken");

///////////////// MINI_PP_PRIVATE_INT_TOOL_BASE_ /////////////////
#define CHECK_IS_EQUAL(params, x) + MINI_PP_CAT(0, MINI_PP_CAT_4(MINI_PP_PRIVATE_INT_TOOL_BASE_, x, _, x))
static_assert(42 CALL_UNROLL(MINI_PP_CAT(MINI_PP_PRIVATE_LOOP_UNROLL_, MINI_PP_MAX_NB_ARGS), CHECK_IS_EQUAL, /*dummyParams,*/ MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0) == 42, "MINI_PP_PRIVATE_IS_EQUAL_IMPL_ is broken");
static_assert(42 CHECK_IS_EQUAL(dummyParams, MINI_PP_MAX_NB_ARGS) == 42, "MINI_PP_PRIVATE_IS_EQUAL_IMPL_ is broken");

///////////////// MINI_PP_PRIVATE_INT_TOOL_ /////////////////
#define TEST_INT_TOOL_REPEAT(params, current, currentMinusOne, currentPlusOne) + params MINI_PP_IF_ELSE(MINI_PP_IS_EQUAL(0, current), TEST_INT_TOOL_DO_NOT_RECURSE, MINI_PP_CAT(MINI_PP_PRIVATE_INT_TOOL_, currentMinusOne))
#define TEST_INT_TOOL_DO_NOT_RECURSE(repeatFunc, params)
static_assert(4 MINI_PP_CAT(MINI_PP_PRIVATE_INT_TOOL_, MINI_PP_MAX_NB_ARGS)(TEST_INT_TOOL_REPEAT, 2) == 4 + 2 * (MINI_PP_MAX_NB_ARGS + 1), "MINI_PP_PRIVATE_INT_TOOL_ is broken");
