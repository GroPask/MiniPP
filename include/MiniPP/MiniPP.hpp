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

#define MINI_PP_DEFER(x) x MINI_PP_PRIVATE_DEFER_IMPL_EMPTY()
#define MINI_PP_PRIVATE_DEFER_IMPL_EMPTY()

#define MINI_PP_EXPAND(x) x

#define MINI_PP_EXPAND_2_TIMES(x) MINI_PP_EXPAND_2_TIMES_IMPL(x)
#define MINI_PP_EXPAND_2_TIMES_IMPL(x) x

#define MINI_PP_EXPAND_3_TIMES(x) MINI_PP_EXPAND_3_TIMES_IMPL(x)
#define MINI_PP_EXPAND_3_TIMES_IMPL(x) MINI_PP_EXPAND_3_TIMES_IMPL_IMPL(x)
#define MINI_PP_EXPAND_3_TIMES_IMPL_IMPL(x) x

#define MINI_PP_ASSERT(cond01) MINI_PP_CAT(MINI_PP_PRIVATE_ASSERT_IMPL_, cond01)(dummyTooMuchArgs)
#define MINI_PP_PRIVATE_ASSERT_IMPL_1(...)
#define MINI_PP_PRIVATE_ASSERT_IMPL_0()

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

#define MINI_PP_HAS_DIRECT_COMMA(...) MINI_PP_PRIVATE_HAS_DIRECT_COMMA_IMPL(__VA_ARGS__, MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE, dummy)
#define MINI_PP_PRIVATE_HAS_DIRECT_COMMA_IMPL(...) MINI_PP_EXPAND(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX(__VA_ARGS__))

#define MINI_PP_IS_EMPTY(...) MINI_PP_PRIVATE_IS_EMPTY_IMPL_HAS_DIRECT_COMMA_SWITCH(MINI_PP_HAS_DIRECT_COMMA(__VA_ARGS__), (__VA_ARGS__))
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_HAS_DIRECT_COMMA_SWITCH(hasDirectComma, argsTuple) MINI_PP_CAT(MINI_PP_PRIVATE_IS_EMPTY_IMPL_HAS_DIRECT_COMMA_, hasDirectComma)(argsTuple)
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_HAS_DIRECT_COMMA_1(argsTuple) 0
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_HAS_DIRECT_COMMA_0(argsTuple) MINI_PP_PRIVATE_IS_EMPTY_IMPL_IS_PAREN_CHECK_HAS_DIRECT_COMMA_SWITCH(MINI_PP_HAS_DIRECT_COMMA(MINI_PP_PRIVATE_IS_EMPTY_IMPL_MAKE_IS_PAREN_CHECK argsTuple), argsTuple)
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_IS_PAREN_CHECK_HAS_DIRECT_COMMA_SWITCH(isParenCheckHasDirectComma, argsTuple) MINI_PP_CAT(MINI_PP_PRIVATE_IS_EMPTY_IMPL_IS_PAREN_CHECK_HAS_DIRECT_COMMA_, isParenCheckHasDirectComma)(argsTuple)
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_IS_PAREN_CHECK_HAS_DIRECT_COMMA_1(argsTuple) 0
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_IS_PAREN_CHECK_HAS_DIRECT_COMMA_0(argsTuple) MINI_PP_PRIVATE_IS_EMPTY_IMPL_IS_BLOCKING_CALL_CHECK_HAS_DIRECT_COMMA_SWITCH(MINI_PP_HAS_DIRECT_COMMA(MINI_PP_PRIVATE_IS_EMPTY_IMPL_MAKE_IS_BLOCKING_CALL_CHECK argsTuple), argsTuple)
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_IS_BLOCKING_CALL_CHECK_HAS_DIRECT_COMMA_SWITCH(isBlockingCallCheckhasDirectComma, argsTuple) isBlockingCallCheckhasDirectComma
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_MAKE_IS_PAREN_CHECK(...) MINI_PP_PRIVATE_IS_EMPTY_IMPL_PAREN_CALL_CHECK __VA_ARGS__
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_MAKE_IS_BLOCKING_CALL_CHECK(...) MINI_PP_PRIVATE_IS_EMPTY_IMPL_MAKE_IS_BLOCKING_CALL_CHECK_IMPL(MINI_PP_PRIVATE_IS_EMPTY_IMPL_PAREN_CALL_CHECK ## __VA_ARGS__)
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_MAKE_IS_BLOCKING_CALL_CHECK_IMPL(toCall) toCall()
#define MINI_PP_PRIVATE_IS_EMPTY_IMPL_PAREN_CALL_CHECK(...) dummyA, dummyB

#define MINI_PP_NB_ARGS(...) MINI_PP_CAT(MINI_PP_PRIVATE_NB_ARGS_IMPL_IS_EMPTY_, MINI_PP_IS_EMPTY(__VA_ARGS__))(__VA_ARGS__)
#define MINI_PP_PRIVATE_NB_ARGS_IMPL_IS_EMPTY_1(...) 0
#define MINI_PP_PRIVATE_NB_ARGS_IMPL_IS_EMPTY_0(...) MINI_PP_PRIVATE_NB_ARGS_IMPL_IS_EMPTY_0_IMPL(__VA_ARGS__, MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0)
#define MINI_PP_PRIVATE_NB_ARGS_IMPL_IS_EMPTY_0_IMPL(...) MINI_PP_EXPAND(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX(__VA_ARGS__))

#define MINI_PP_IS_PAREN(x) MINI_PP_PRIVATE_IS_PAREN_IMPL(MINI_PP_HAS_DIRECT_COMMA(x), x)
#define MINI_PP_PRIVATE_IS_PAREN_IMPL(hasDirectComma, x) MINI_PP_CAT(MINI_PP_PRIVATE_IS_PAREN_IMPL_HAS_DIRECT_COMMA_, hasDirectComma)(x)
#define MINI_PP_PRIVATE_IS_PAREN_IMPL_HAS_DIRECT_COMMA_1(x) 0
#define MINI_PP_PRIVATE_IS_PAREN_IMPL_HAS_DIRECT_COMMA_0(...) MINI_PP_PRIVATE_IS_PAREN_IMPL_NO_COMMA(MINI_PP_HAS_DIRECT_COMMA(MINI_PP_PRIVATE_IS_PAREN_IMPL_CALL_CHECK __VA_ARGS__))
#define MINI_PP_PRIVATE_IS_PAREN_IMPL_NO_COMMA(callCheckHasDirectComma) callCheckHasDirectComma
#define MINI_PP_PRIVATE_IS_PAREN_IMPL_CALL_CHECK(...) dummyA, dummyB

////////////////////////////////////////////////////////////
// Is Equal
////////////////////////////////////////////////////////////

#define MINI_PP_IS_EQUAL_0(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_0_IMPL_CALL_CHECK_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_0_IMPL_CALL_CHECK_0 dummyA, dummyB

#define MINI_PP_IS_EQUAL_1(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_1_IMPL_CALL_CHECK_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_1_IMPL_CALL_CHECK_1 dummyA, dummyB

#define MINI_PP_IS_EQUAL_2(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_2_IMPL_CALL_CHECK_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_2_IMPL_CALL_CHECK_2 dummyA, dummyB

#define MINI_PP_IS_EQUAL_3(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_3_IMPL_CALL_CHECK_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_3_IMPL_CALL_CHECK_3 dummyA, dummyB

#define MINI_PP_IS_EQUAL_4(x) MINI_PP_HAS_DIRECT_COMMA(MINI_PP_CAT(MINI_PP_PRIVATE_IS_EQUAL_4_IMPL_CALL_CHECK_, x))
#define MINI_PP_PRIVATE_IS_EQUAL_4_IMPL_CALL_CHECK_4 dummyA, dummyB

////////////////////////////////////////////////////////////
// Compute Switch With Or Without Va Args
////////////////////////////////////////////////////////////

#define MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(prefix, /*nbFixedArgs,*/ ...) MINI_PP_ASSERT(MINI_PP_NOT(MINI_PP_IS_EQUAL_0(MINI_PP_NB_ARGS(__VA_ARGS__))))MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL(MINI_PP_IS_EQUAL_1(MINI_PP_NB_ARGS(__VA_ARGS__)), prefix, __VA_ARGS__)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL(nbArgsIs1, prefix, /*nbFixedArgs,*/ ...) MINI_PP_CAT(MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_, nbArgsIs1)(prefix, __VA_ARGS__)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_1(prefix, nbFixedArgs) MINI_PP_ASSERT(MINI_PP_IS_EQUAL_0(nbFixedArgs))MINI_PP_CAT(prefix, _WITHOUT_VA_ARGS)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_0(prefix, /*nbFixedArgs,*/ ...) MINI_PP_EXPAND(MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_0_IMPL(prefix, __VA_ARGS__))
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_0_IMPL(prefix, nbFixedArgs, ...) MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_SWITCH_IS_ONLY_FIXED(prefix, MINI_PP_CAT(MINI_PP_IS_EQUAL_, nbFixedArgs)(MINI_PP_NB_ARGS(__VA_ARGS__)), __VA_ARGS__)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_SWITCH_IS_ONLY_FIXED(prefix, isOnlyFixedArgs, ...) MINI_PP_CAT(MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_IS_ONLY_FIXED_ARGS_SWITCH_, isOnlyFixedArgs)(prefix, __VA_ARGS__)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_IS_ONLY_FIXED_ARGS_SWITCH_1(prefix, ...) MINI_PP_CAT(prefix, _WITHOUT_VA_ARGS)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_IS_ONLY_FIXED_ARGS_SWITCH_0(prefix, ...) MINI_PP_CAT(prefix, _WITH_VA_ARGS)

////////////////////////////////////////////////////////////
// Tuple
////////////////////////////////////////////////////////////

#define MINI_PP_MAKE_TUPLE(...) (__VA_ARGS__)

#define MINI_PP_IS_TUPLE(x) MINI_PP_IS_PAREN(x)

#define MINI_PP_TUPLE_EXPAND(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_EXPAND_IMPL t)
#define MINI_PP_PRIVATE_TUPLE_EXPAND_IMPL(...) __VA_ARGS__

#define MINI_PP_TUPLE_IS_EMPTY(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_IS_EMPTY(MINI_PP_TUPLE_EXPAND(t))

#define MINI_PP_TUPLE_SIZE(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_SIZE_IMPL t)
#define MINI_PP_PRIVATE_TUPLE_SIZE_IMPL(...) MINI_PP_NB_ARGS(__VA_ARGS__)

#define MINI_PP_TUPLE_PUSH_FRONT(t, x) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_PUSH_FRONT_IMPL(MINI_PP_TUPLE_IS_EMPTY(t), t, x)
#define MINI_PP_PRIVATE_TUPLE_PUSH_FRONT_IMPL(tupleIsEmpty, t, x) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_PUSH_FRONT_IMPL_IS_EMPTY_, tupleIsEmpty)(t, x)
#define MINI_PP_PRIVATE_TUPLE_PUSH_FRONT_IMPL_IS_EMPTY_1(t, x) MINI_PP_MAKE_TUPLE(x)
#define MINI_PP_PRIVATE_TUPLE_PUSH_FRONT_IMPL_IS_EMPTY_0(t, x) MINI_PP_MAKE_TUPLE(x, MINI_PP_TUPLE_EXPAND(t))

#define MINI_PP_TUPLE_PUSH_BACK(t, x) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_PUSH_BACK_IMPL(MINI_PP_TUPLE_IS_EMPTY(t), t, x)
#define MINI_PP_PRIVATE_TUPLE_PUSH_BACK_IMPL(tupleIsEmpty, t, x) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_PUSH_BACK_IMPL_IS_EMPTY_, tupleIsEmpty)(t, x)
#define MINI_PP_PRIVATE_TUPLE_PUSH_BACK_IMPL_IS_EMPTY_1(t, x) MINI_PP_MAKE_TUPLE(x)
#define MINI_PP_PRIVATE_TUPLE_PUSH_BACK_IMPL_IS_EMPTY_0(t, x) MINI_PP_MAKE_TUPLE(MINI_PP_TUPLE_EXPAND(t), x)

#define MINI_PP_TUPLE_POP_FRONT(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL(MINI_PP_IS_EQUAL_1(MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL(sizeIs1, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_, sizeIs1)(t)
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_1(t) MINI_PP_MAKE_TUPLE()
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_0(t) MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_0_IMPL t
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_0_IMPL(first, ...) MINI_PP_MAKE_TUPLE(__VA_ARGS__)

#define MINI_PP_TUPLE_GET_ELEM_0(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL(MINI_PP_IS_EQUAL_1(MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL(sizeIs1, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_, sizeIs1)(t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_1(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_0(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_MORE_1_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_GET(a) a
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_MORE_1_GET(a, ...) a

#define MINI_PP_TUPLE_GET_ELEM_1(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL(MINI_PP_IS_EQUAL_2(MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL(sizeIs2, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_, sizeIs2)(t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_1(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_0(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_MORE_2_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_GET(a, b) b
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_MORE_2_GET(a, b, ...) b

#define MINI_PP_TUPLE_GET_ELEM_2(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL(MINI_PP_IS_EQUAL_3(MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL(sizeIs3, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_, sizeIs3)(t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_1(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_0(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_MORE_3_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_GET(a, b, c) c
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_MORE_3_GET(a, b, c, ...) c

#define MINI_PP_TUPLE_GET_ELEM_3(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL(MINI_PP_IS_EQUAL_4(MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL(sizeIs4, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_SIZE_4_, sizeIs4)(t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_SIZE_4_1(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_SIZE_4_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_SIZE_4_0(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_SIZE_MORE_4_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_SIZE_4_GET(a, b, c, d) d
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL_SIZE_MORE_4_GET(a, b, c, d, ...) d

////////////////////////////////////////////////////////////
// For Each
////////////////////////////////////////////////////////////

#define MINI_PP_FOR_EACH(/*func,*/ ...) MINI_PP_EXPAND(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(MINI_PP_PRIVATE_FOR_EACH_IMPL, 1, __VA_ARGS__)(__VA_ARGS__))
#define MINI_PP_PRIVATE_FOR_EACH_IMPL_WITHOUT_VA_ARGS(func)
#define MINI_PP_PRIVATE_FOR_EACH_IMPL_WITH_VA_ARGS(func, ...) MINI_PP_PRIVATE_FOR_EACH_IMPL_WITH_VA_ARGS_IMPL(func, MINI_PP_NB_ARGS(__VA_ARGS__), __VA_ARGS__)
#define MINI_PP_PRIVATE_FOR_EACH_IMPL_WITH_VA_ARGS_IMPL(func, nbArgs, ...) MINI_PP_PRIVATE_FOR_EACH_IMPL_WITH_VA_ARGS_CALL_UNROLL(MINI_PP_CAT(MINI_PP_PRIVATE_LOOP_UNROLL_, nbArgs), func, __VA_ARGS__)
#define MINI_PP_PRIVATE_FOR_EACH_IMPL_WITH_VA_ARGS_CALL_UNROLL(unrollFunc, func, ...) MINI_PP_EXPAND(unrollFunc(MINI_PP_PRIVATE_FOR_EACH_IMPL_CALL, func, __VA_ARGS__))
#define MINI_PP_PRIVATE_FOR_EACH_IMPL_CALL(funcAsParam, x) funcAsParam(x)

#define MINI_PP_FOR_EACH_WITH_PARAMS(func, /*params,*/ ...) MINI_PP_EXPAND(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL, 2, func, __VA_ARGS__)(func, __VA_ARGS__))
#define MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL_WITHOUT_VA_ARGS(func, params)
#define MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL_WITH_VA_ARGS(func, params, ...) MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL_WITH_VA_ARGS_IMPL(func, MINI_PP_NB_ARGS(__VA_ARGS__), params, __VA_ARGS__)
#define MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL_WITH_VA_ARGS_IMPL(func, nbArgs, params, ...) MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL_WITH_VA_ARGS_IMPL_CALL_UNROLL(MINI_PP_CAT(MINI_PP_PRIVATE_LOOP_UNROLL_, nbArgs), func, params, __VA_ARGS__)
#define MINI_PP_PRIVATE_FOR_EACH_WITH_PARAMS_IMPL_WITH_VA_ARGS_IMPL_CALL_UNROLL(unrollFunc, func, params, ...) MINI_PP_EXPAND(unrollFunc(func, params, __VA_ARGS__))

////////////////////////////////////////////////////////////
// Unroll Utility
////////////////////////////////////////////////////////////

#define MINI_PP_MAX_NB_ARGS 125

#define MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0

#define MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 125, 124, 123, 122, 121, \
    120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100,  99,  98,  97,  96,  95,  94,  93,  92,  91, \
     90,  89,  88,  87,  86,  85,  84,  83,  82,  81,  80,  79,  78,  77,  76,  75,  74,  73,  72,  71,  70,  69,  68,  67,  66,  65,  64,  63,  62,  61, \
     60,  59,  58,  57,  56,  55,  54,  53,  52,  51,  50,  49,  48,  47,  46,  45,  44,  43,  42,  41,  40,  39,  38,  37,  36,  35,  34,  33,  32,  31, \
     30,  29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15,  14,  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1, \
    0

#define MINI_PP_PRIVATE_GET_ARG_INDEX_MAX(_0, \
    _001, _002, _003, _004, _005, _006, _007, _008, _009, _010, _011, _012, _013, _014, _015, _016, _017, _018, _019, _020, _021, _022, _023, _024, _025, _026, _027, _028, _029, _030, \
    _031, _032, _033, _034, _035, _036, _037, _038, _039, _040, _041, _042, _043, _044, _045, _046, _047, _048, _049, _050, _051, _052, _053, _054, _055, _056, _057, _058, _059, _060, \
    _061, _062, _063, _064, _065, _066, _067, _068, _069, _070, _071, _072, _073, _074, _075, _076, _077, _078, _079, _080, _081, _082, _083, _084, _085, _086, _087, _088, _089, _090, \
    _091, _092, _093, _094, _095, _096, _097, _098, _099, _100, _101, _102, _103, _104, _105, _106, _107, _108, _109, _110, _111, _112, _113, _114, _115, _116, _117, _118, _119, _120, \
    _121, _122, _123, _124, _125, ...) _125

#define MINI_PP_PRIVATE_LOOP_UNROLL_0(...)
#define MINI_PP_PRIVATE_LOOP_UNROLL_1(  func, params, first)      func(params, first)
#define MINI_PP_PRIVATE_LOOP_UNROLL_2(  func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_1(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_3(  func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_2(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_4(  func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_3(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_5(  func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_4(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_6(  func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_5(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_7(  func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_6(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_8(  func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_7(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_9(  func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_8(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_10( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_9(  func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_11( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_10( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_12( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_11( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_13( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_12( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_14( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_13( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_15( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_14( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_16( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_15( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_17( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_16( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_18( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_17( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_19( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_18( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_20( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_19( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_21( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_20( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_22( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_21( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_23( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_22( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_24( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_23( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_25( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_24( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_26( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_25( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_27( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_26( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_28( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_27( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_29( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_28( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_30( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_29( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_31( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_30( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_32( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_31( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_33( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_32( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_34( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_33( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_35( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_34( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_36( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_35( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_37( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_36( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_38( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_37( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_39( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_38( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_40( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_39( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_41( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_40( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_42( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_41( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_43( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_42( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_44( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_43( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_45( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_44( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_46( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_45( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_47( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_46( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_48( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_47( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_49( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_48( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_50( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_49( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_51( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_50( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_52( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_51( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_53( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_52( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_54( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_53( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_55( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_54( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_56( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_55( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_57( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_56( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_58( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_57( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_59( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_58( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_60( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_59( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_61( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_60( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_62( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_61( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_63( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_62( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_64( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_63( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_65( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_64( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_66( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_65( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_67( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_66( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_68( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_67( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_69( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_68( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_70( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_69( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_71( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_70( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_72( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_71( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_73( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_72( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_74( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_73( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_75( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_74( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_76( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_75( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_77( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_76( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_78( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_77( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_79( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_78( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_80( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_79( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_81( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_80( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_82( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_81( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_83( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_82( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_84( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_83( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_85( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_84( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_86( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_85( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_87( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_86( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_88( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_87( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_89( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_88( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_90( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_89( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_91( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_90( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_92( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_91( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_93( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_92( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_94( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_93( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_95( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_94( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_96( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_95( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_97( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_96( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_98( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_97( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_99( func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_98( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_100(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_99( func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_101(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_100(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_102(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_101(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_103(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_102(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_104(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_103(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_105(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_104(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_106(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_105(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_107(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_106(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_108(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_107(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_109(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_108(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_110(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_109(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_111(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_110(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_112(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_111(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_113(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_112(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_114(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_113(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_115(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_114(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_116(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_115(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_117(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_116(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_118(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_117(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_119(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_118(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_120(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_119(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_121(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_120(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_122(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_121(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_123(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_122(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_124(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_123(func, params, __VA_ARGS__))
#define MINI_PP_PRIVATE_LOOP_UNROLL_125(func, params, first, ...) func(params, first)  MINI_PP_EXPAND(MINI_PP_PRIVATE_LOOP_UNROLL_124(func, params, __VA_ARGS__))

#endif
