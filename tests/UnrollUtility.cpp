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





#define FOR_EACH_WITH_ARGS2(func, args, ...) MINI_PP_EXPAND(MINI_PP_CAT(DO_FOR_EACH_WITH_ARGS_IMPL_, MINI_PP_NB_ARGS(__VA_ARGS__))(func, args, __VA_ARGS__))

#define DO_FOR_EACH_WITH_ARGS_IMPL_0( func, args, ...)
#define DO_FOR_EACH_WITH_ARGS_IMPL_1( func, args, first)      func(args, first)
#define DO_FOR_EACH_WITH_ARGS_IMPL_2( func, args, first, ...) func(args, first) MINI_PP_EXPAND(DO_FOR_EACH_WITH_ARGS_IMPL_1( func, args, __VA_ARGS__))
#define DO_FOR_EACH_WITH_ARGS_IMPL_3( func, args, first, ...) func(args, first) MINI_PP_EXPAND(DO_FOR_EACH_WITH_ARGS_IMPL_2( func, args, __VA_ARGS__))
#define DO_FOR_EACH_WITH_ARGS_IMPL_4( func, args, first, ...) func(args, first) MINI_PP_EXPAND(DO_FOR_EACH_WITH_ARGS_IMPL_3( func, args, __VA_ARGS__))
#define DO_FOR_EACH_WITH_ARGS_IMPL_5( func, args, first, ...) func(args, first) MINI_PP_EXPAND(DO_FOR_EACH_WITH_ARGS_IMPL_4( func, args, __VA_ARGS__))
#define DO_FOR_EACH_WITH_ARGS_IMPL_6( func, args, first, ...) func(args, first) MINI_PP_EXPAND(DO_FOR_EACH_WITH_ARGS_IMPL_5( func, args, __VA_ARGS__))
#define DO_FOR_EACH_WITH_ARGS_IMPL_7( func, args, first, ...) func(args, first) MINI_PP_EXPAND(DO_FOR_EACH_WITH_ARGS_IMPL_6( func, args, __VA_ARGS__))


#define FOR_EACH_WITH_ARGS(func, args, ...) MINI_PP_CAT(REPEAT_IMPL_, MINI_PP_NB_ARGS(__VA_ARGS__))(FOR_EACH_WITH_ARGS_IMPL, MINI_PP_MAKE_TUPLE(func, args), __VA_ARGS__)
#define FOR_EACH_WITH_ARGS_IMPL(tupleFuncArgs, first, ...) MINI_PP_TUPLE_GET_ELEM_0(tupleFuncArgs)

#define REPEAT_IMPL_0( func)
#define REPEAT_IMPL_1( func, ...) MINI_PP_CALL_WITH_ARGS(func, MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_MAKE_TUPLE(__VA_ARGS__)))
#define REPEAT_IMPL_2( func, ...) MINI_PP_CALL_WITH_ARGS(func, MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_MAKE_TUPLE(__VA_ARGS__))) REPEAT_IMPL_1 MINI_PP_TUPLE_POP_FRONT(MINI_PP_MAKE_TUPLE(__VA_ARGS__))
#define REPEAT_IMPL_3( func, ...) MINI_PP_CALL_WITH_ARGS(func, MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_MAKE_TUPLE(__VA_ARGS__))) REPEAT_IMPL_2 MINI_PP_TUPLE_POP_FRONT(MINI_PP_MAKE_TUPLE(__VA_ARGS__))
#define REPEAT_IMPL_4( func, ...) MINI_PP_CALL_WITH_ARGS(func, MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_MAKE_TUPLE(__VA_ARGS__))) REPEAT_IMPL_3 MINI_PP_TUPLE_POP_FRONT(MINI_PP_MAKE_TUPLE(__VA_ARGS__))
#define REPEAT_IMPL_5( func, ...) MINI_PP_CALL_WITH_ARGS(func, MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_MAKE_TUPLE(__VA_ARGS__))) REPEAT_IMPL_4 MINI_PP_TUPLE_POP_FRONT(MINI_PP_MAKE_TUPLE(__VA_ARGS__))
#define REPEAT_IMPL_6( func, ...) MINI_PP_CALL_WITH_ARGS(func, MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_MAKE_TUPLE(__VA_ARGS__))) REPEAT_IMPL_5 MINI_PP_TUPLE_POP_FRONT(MINI_PP_MAKE_TUPLE(__VA_ARGS__))
#define REPEAT_IMPL_7( func, ...) MINI_PP_CALL_WITH_ARGS(func, MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_MAKE_TUPLE(__VA_ARGS__))) REPEAT_IMPL_6 MINI_PP_TUPLE_POP_FRONT(MINI_PP_MAKE_TUPLE(__VA_ARGS__))

enum class EnumDoForEach
{
    First = 0,

    #define DECLARE_FIELD(arg, x) MINI_PP_CAT(Field, x),
    #define DECLARE_FIELDS(...) FOR_EACH_WITH_ARGS(DECLARE_FIELD, dummy, __VA_ARGS__)

    //DECLARE_FIELDS()
    DECLARE_FIELDS(A, B, C, D)

    //DO_FOR_EACH(DECLARE_FIELD, E, F, G, H)
};

static_assert(static_cast<int>(EnumDoForEach::FieldB) == 2, "'DO_FOR_EACH' Broken");
static_assert(static_cast<int>(EnumDoForEach::FieldD) == 4, "'DO_FOR_EACH' Broken");
static_assert(static_cast<int>(EnumDoForEach::FieldH) == 8, "'DO_FOR_EACH' Broken");