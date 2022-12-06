#ifndef MINI_PP_HPP
#define MINI_PP_HPP

////////////////////////////////////////////////////////////
// Version
////////////////////////////////////////////////////////////

#define MINI_PP_VERSION_MAJOR 0
#define MINI_PP_VERSION_MINOR 0
#define MINI_PP_VERSION_PATCH 1

#define MINI_PP_VERSION (MINI_PP_VERSION_MAJOR * 10000 + MINI_PP_VERSION_MINOR * 100 + MINI_PP_VERSION_PATCH)

////////////////////////////////////////////////////////////
// Base
////////////////////////////////////////////////////////////

#define MINI_PP_PARENS ()

#define MINI_PP_CAT(a, b) MINI_PP_PRIVATE_CAT_IMPL(a, b)
#define MINI_PP_PRIVATE_CAT_IMPL(a, b) a ## b

#define MINI_PP_TO_TEXT(x) MINI_PP_PRIVATE_TO_TEXT_IMPL(x)
#define MINI_PP_PRIVATE_TO_TEXT_IMPL(x) #x

#define MINI_PP_DEFER(x) x MINI_PP_PRIVATE_DEFER_EMPTY()
#define MINI_PP_PRIVATE_DEFER_EMPTY()

#define MINI_PP_EXPAND(x) x
#define MINI_PP_PRIVATE_EXPAND(x) x // Used internally to avoid recursion problem for the user

////////////////////////////////////////////////////////////
// Boolean
////////////////////////////////////////////////////////////

#define MINI_PP_NOT(cond01) MINI_PP_CAT(MINI_PP_PRIVATE_NOT_SWITCH_, cond01)
#define MINI_PP_PRIVATE_NOT_SWITCH_0 1
#define MINI_PP_PRIVATE_NOT_SWITCH_1 0

#define MINI_PP_OR(cond01A, cond01B) MINI_PP_CAT(MINI_PP_CAT(MINI_PP_PRIVATE_OR_SWITCH_, cond01A), cond01B)
#define MINI_PP_PRIVATE_OR_SWITCH_00 0
#define MINI_PP_PRIVATE_OR_SWITCH_01 1
#define MINI_PP_PRIVATE_OR_SWITCH_10 1
#define MINI_PP_PRIVATE_OR_SWITCH_11 1

#define MINI_PP_AND(cond01A, cond01B) MINI_PP_CAT(MINI_PP_CAT(MINI_PP_PRIVATE_AND_SWITCH_, cond01A), cond01B)
#define MINI_PP_PRIVATE_AND_SWITCH_00 0
#define MINI_PP_PRIVATE_AND_SWITCH_01 0
#define MINI_PP_PRIVATE_AND_SWITCH_10 0
#define MINI_PP_PRIVATE_AND_SWITCH_11 1

#define MINI_PP_IF(cond01, x) MINI_PP_CAT(MINI_PP_PRIVATE_IF_SWITCH_, cond01)(x)
#define MINI_PP_PRIVATE_IF_SWITCH_0(x)
#define MINI_PP_PRIVATE_IF_SWITCH_1(x) x

#define MINI_PP_IF_ELSE(cond01, a, b) MINI_PP_CAT(MINI_PP_PRIVATE_IF_ELSE_SWITCH_, cond01)(a, b)
#define MINI_PP_PRIVATE_IF_ELSE_SWITCH_0(a, b) b
#define MINI_PP_PRIVATE_IF_ELSE_SWITCH_1(a, b) a

////////////////////////////////////////////////////////////
// Args Utility
////////////////////////////////////////////////////////////

#define MINI_PP_HAS_DIRECT_COMMA(...) MINI_PP_PRIVATE_EXPAND(MINI_PP_DEFER(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX)(__VA_ARGS__, MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE, dummy))

#define MINI_PP_IS_EMPTY(...) \
    MINI_PP_AND( \
        MINI_PP_AND( \
            MINI_PP_NOT(MINI_PP_HAS_DIRECT_COMMA(__VA_ARGS__)), \
            MINI_PP_HAS_DIRECT_COMMA(MINI_PP_PRIVATE_IS_EMPTY_PAREN_CHECK __VA_ARGS__ ()) \
        ), \
        MINI_PP_NOT(MINI_PP_HAS_DIRECT_COMMA(MINI_PP_PRIVATE_IS_EMPTY_PAREN_CHECK __VA_ARGS__)) \
    )
#define MINI_PP_PRIVATE_IS_EMPTY_PAREN_CHECK(...) ,

#define MINI_PP_NB_ARGS(...) MINI_PP_IF_ELSE(MINI_PP_IS_EMPTY(__VA_ARGS__), 0, MINI_PP_PRIVATE_EXPAND(MINI_PP_DEFER(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX)(__VA_ARGS__, MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0)))

#define MINI_PP_IS_PAREN(x) MINI_PP_CAT(MINI_PP_PRIVATE_IS_PAREN_SWITCH_, MINI_PP_NB_ARGS(MINI_PP_PRIVATE_IS_PAREN_CHECK_CALLABLE x))
#define MINI_PP_PRIVATE_IS_PAREN_CHECK_CALLABLE(...) dummyA, dummyB
#define MINI_PP_PRIVATE_IS_PAREN_SWITCH_1 0
#define MINI_PP_PRIVATE_IS_PAREN_SWITCH_2 1

////////////////////////////////////////////////////////////
// Is Equal
////////////////////////////////////////////////////////////

#define MINI_PP_IS_EQUAL_0(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_0_CHECK_CALLABLE_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_0_CHECK_CALLABLE_0 dummyA, dummyB

#define MINI_PP_IS_EQUAL_1(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_1_CHECK_CALLABLE_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_1_CHECK_CALLABLE_1 dummyA, dummyB

#define MINI_PP_IS_EQUAL_2(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_2_CHECK_CALLABLE_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_2_CHECK_CALLABLE_2 dummyA, dummyB

#define MINI_PP_IS_EQUAL_3(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_3_CHECK_CALLABLE_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_3_CHECK_CALLABLE_3 dummyA, dummyB

#define MINI_PP_IS_EQUAL_4(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_4_CHECK_CALLABLE_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_4_CHECK_CALLABLE_4 dummyA, dummyB

////////////////////////////////////////////////////////////
// Tuple
////////////////////////////////////////////////////////////

#define MINI_PP_MAKE_TUPLE(...) (__VA_ARGS__)

#define MINI_PP_CALL_WITH_TUPLE(f, t) MINI_PP_PRIVATE_CALL_WITH_TUPLE_IMPL(f, t)
#define MINI_PP_PRIVATE_CALL_WITH_TUPLE_IMPL(f, t) f t

#define MINI_PP_TUPLE_EXPAND(t) MINI_PP_CALL_WITH_TUPLE(MINI_PP_PRIVATE_TUPLE_EXPAND_IMPL, t)
#define MINI_PP_PRIVATE_TUPLE_EXPAND_IMPL(...) __VA_ARGS__

#define MINI_PP_TUPLE_IS_EMPTY(t) MINI_PP_IS_EMPTY(MINI_PP_TUPLE_EXPAND(t))

#define MINI_PP_TUPLE_SIZE(t) MINI_PP_NB_ARGS(MINI_PP_TUPLE_EXPAND(t))

#define MINI_PP_TUPLE_PUSH_FRONT(t, x) MINI_PP_IF_ELSE(MINI_PP_TUPLE_IS_EMPTY(t), MINI_PP_MAKE_TUPLE(x), MINI_PP_MAKE_TUPLE(x, MINI_PP_TUPLE_EXPAND(t)))

#define MINI_PP_TUPLE_PUSH_BACK(t, x) MINI_PP_IF_ELSE(MINI_PP_TUPLE_IS_EMPTY(t), MINI_PP_MAKE_TUPLE(x), MINI_PP_MAKE_TUPLE(MINI_PP_TUPLE_EXPAND(t), x))

#define MINI_PP_TUPLE_POP_FRONT(t) \
    MINI_PP_IF_ELSE( \
        MINI_PP_IS_EQUAL_1(MINI_PP_TUPLE_SIZE(t)), \
        MINI_PP_MAKE_TUPLE(), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL, t) \
    )
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL(f, ...) MINI_PP_MAKE_TUPLE(__VA_ARGS__)

#define MINI_PP_TUPLE_GET_ELEM_0(t) \
    MINI_PP_IF_ELSE( \
        MINI_PP_IS_EQUAL_1(MINI_PP_TUPLE_SIZE(t)), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_1, t), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_MORE_1, t) \
    )
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_1(a) a
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_MORE_1(a, ...) a

#define MINI_PP_TUPLE_GET_ELEM_1(t) \
    MINI_PP_IF_ELSE( \
        MINI_PP_IS_EQUAL_2(MINI_PP_TUPLE_SIZE(t)), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_2, t), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_MORE_2, t) \
    )
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_2(a, b) b
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_MORE_2(a, b, ...) b

#define MINI_PP_TUPLE_GET_ELEM_2(t) \
    MINI_PP_IF_ELSE( \
        MINI_PP_IS_EQUAL_3(MINI_PP_TUPLE_SIZE(t)), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_3, t), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_MORE_3, t) \
    )
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_3(a, b, c) c
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_MORE_3(a, b, c, ...) c

#define MINI_PP_TUPLE_GET_ELEM_3(t) \
    MINI_PP_IF_ELSE( \
        MINI_PP_IS_EQUAL_4(MINI_PP_TUPLE_SIZE(t)), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_4, t), \
        MINI_PP_DEFER(MINI_PP_CALL_WITH_TUPLE)(MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_MORE_4, t) \
    )
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_4(a, b, c, d) d
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_MORE_4(a, b, c, d, ...) d

////////////////////////////////////////////////////////////
// Call With Args
////////////////////////////////////////////////////////////

#define MINI_PP_CALL_WITH_ARGS(...) MINI_PP_CALL_WITH_TUPLE(MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_MAKE_TUPLE(__VA_ARGS__)), MINI_PP_TUPLE_POP_FRONT(MINI_PP_MAKE_TUPLE(__VA_ARGS__)))

////////////////////////////////////////////////////////////
// For Each
////////////////////////////////////////////////////////////

#define MINI_PP_FOR_EACH(...) \
    MINI_PP_IF( \
        MINI_PP_NOT(MINI_PP_IS_EQUAL_1(MINI_PP_NB_ARGS(dummy ## __VA_ARGS__))), \
        MINI_PP_DEFER(MINI_PP_PRIVATE_FOR_EACH_IMPL)(__VA_ARGS__) \
    )
#define MINI_PP_PRIVATE_FOR_EACH_IMPL(func, ...) MINI_PP_PRIVATE_EXPAND(MINI_PP_CAT(MINI_PP_PRIVATE_LOOP_UNROLL_, MINI_PP_NB_ARGS(__VA_ARGS__))(MINI_PP_PRIVATE_FOR_EACH_IMPL_CALL, func, __VA_ARGS__))
#define MINI_PP_PRIVATE_FOR_EACH_IMPL_CALL(funcAsParam, x) funcAsParam(x)

#define MINI_PP_FOR_EACH_WITH_PARAMS(func, ...) \
    MINI_PP_IF( \
        MINI_PP_NOT(MINI_PP_IS_EQUAL_1(MINI_PP_NB_ARGS(dummy ## __VA_ARGS__))), \
        MINI_PP_DEFER(MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL)(func, __VA_ARGS__) \
    )
#define MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL(func, params, ...) MINI_PP_PRIVATE_EXPAND(MINI_PP_CAT(MINI_PP_PRIVATE_LOOP_UNROLL_, MINI_PP_NB_ARGS(__VA_ARGS__))(func, params, __VA_ARGS__))

////////////////////////////////////////////////////////////
// Unroll Utility
////////////////////////////////////////////////////////////

#define MINI_PP_MAX_NB_ARGS 16

#define MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0
#define MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define MINI_PP_PRIVATE_GET_ARG_INDEX_MAX(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) _16

#define MINI_PP_PRIVATE_LOOP_UNROLL_0(...)
#define MINI_PP_PRIVATE_LOOP_UNROLL_1(   func, params, first)      func(params, first)
#define MINI_PP_PRIVATE_LOOP_UNROLL_2(   func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_1(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_3(   func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_2(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_4(   func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_3(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_5(   func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_4(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_6(   func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_5(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_7(   func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_6(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_8(   func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_7(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_9(   func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_8(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_10(  func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_9(   func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_11(  func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_10(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_12(  func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_11(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_13(  func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_12(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_14(  func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_13(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_15(  func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_14(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_16(  func, params, first, ...) func(params, first)  MINI_PP_PRIVATE_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_15(  func, params, __VA_ARGS__))

#endif
