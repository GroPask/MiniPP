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

#define MINI_PP_CAT_3(a, b, c) MINI_PP_PRIVATE_CAT_3_IMPL(a, b, c)
#define MINI_PP_PRIVATE_CAT_3_IMPL(a, b, c) a ## b ## c

#define MINI_PP_CAT_4(a, b, c, d) MINI_PP_PRIVATE_CAT_4_IMPL(a, b, c, d)
#define MINI_PP_PRIVATE_CAT_4_IMPL(a, b, c, d) a ## b ## c ## d

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

#define MINI_PP_OR(cond01A, cond01B) MINI_PP_CAT_3(MINI_PP_PRIVATE_OR_SWITCH_, cond01A, cond01B)
#define MINI_PP_PRIVATE_OR_SWITCH_00 0
#define MINI_PP_PRIVATE_OR_SWITCH_01 1
#define MINI_PP_PRIVATE_OR_SWITCH_10 1
#define MINI_PP_PRIVATE_OR_SWITCH_11 1

#define MINI_PP_AND(cond01A, cond01B) MINI_PP_CAT_3(MINI_PP_PRIVATE_AND_SWITCH_, cond01A, cond01B)
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
// Math
////////////////////////////////////////////////////////////

#define MINI_PP_IS_INT(x) MINI_PP_IS_EMPTY(MINI_PP_CAT(MINI_PP_PRIVATE_IS_INT_IMPL_, x))

#define MINI_PP_IS_EQUAL(a, b) MINI_PP_ASSERT(MINI_PP_AND(MINI_PP_IS_INT(a), MINI_PP_IS_INT(b)))MINI_PP_IS_EMPTY(MINI_PP_CAT_4(MINI_PP_PRIVATE_IS_EQUAL_IMPL_, a, _, b))

#define MINI_PP_INC(x) MINI_PP_ASSERT(MINI_PP_IS_INT(x))MINI_PP_ASSERT(MINI_PP_NOT(MINI_PP_IS_EQUAL(0, x)))MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_CAT(MINI_PP_PRIVATE_INT_TOOL_, x)(MINI_PP_PRIVATE_INC_IMPL_REPEAT, dummyParams))
#define MINI_PP_PRIVATE_INC_IMPL_REPEAT(params, current, currentMinusOne, currentPlusOne) MINI_PP_MAKE_TUPLE(currentPlusOne)MINI_PP_PRIVATE_DEC_IMPL_DO_NOT_RECURSE
#define MINI_PP_PRIVATE_INC_IMPL_DO_NOT_RECURSE(repeatFunc, params)

#define MINI_PP_DEC(x) MINI_PP_ASSERT(MINI_PP_IS_INT(x))MINI_PP_ASSERT(MINI_PP_NOT(MINI_PP_IS_EQUAL(0, x)))MINI_PP_TUPLE_GET_ELEM_0(MINI_PP_CAT(MINI_PP_PRIVATE_INT_TOOL_, x)(MINI_PP_PRIVATE_DEC_IMPL_REPEAT, dummyParams))
#define MINI_PP_PRIVATE_DEC_IMPL_REPEAT(params, current, currentMinusOne, currentPlusOne) MINI_PP_MAKE_TUPLE(currentMinusOne)MINI_PP_PRIVATE_DEC_IMPL_DO_NOT_RECURSE
#define MINI_PP_PRIVATE_DEC_IMPL_DO_NOT_RECURSE(repeatFunc, params)

#define MINI_PP_IS_LESS(a, b) MINI_PP_ASSERT(MINI_PP_IS_INT(a))MINI_PP_ASSERT(MINI_PP_IS_INT(b))MINI_PP_CAT(MINI_PP_PRIVATE_IS_LESS_IMPL_B_IS_0_, MINI_PP_IS_EQUAL(0, b))(a, b)
#define MINI_PP_PRIVATE_IS_LESS_IMPL_B_IS_0_1(a, b) 0
#define MINI_PP_PRIVATE_IS_LESS_IMPL_B_IS_0_0(a, b) MINI_PP_CAT(MINI_PP_PRIVATE_INT_TOOL_, MINI_PP_DEC(b))(MINI_PP_PRIVATE_IS_LESS_IMPL_REPEAT, a)
#define MINI_PP_PRIVATE_IS_LESS_IMPL_REPEAT(aAsParams, current, currentMinusOne, currentPlusOne) MINI_PP_CAT(MINI_PP_PRIVATE_IS_LESS_IMPL_A_IS_EQUAL_CURRENT_, MINI_PP_IS_EQUAL(aAsParams, current))(aAsParams, current, currentMinusOne, currentPlusOne)
#define MINI_PP_PRIVATE_IS_LESS_IMPL_A_IS_EQUAL_CURRENT_1(aAsParams, current, currentMinusOne, currentPlusOne) MINI_PP_PRIVATE_IS_LESS_IMPL_DO_NOT_RECURSE_BECAUSE_A_IS_EQUAL_CURRENT
#define MINI_PP_PRIVATE_IS_LESS_IMPL_A_IS_EQUAL_CURRENT_0(aAsParams, current, currentMinusOne, currentPlusOne) MINI_PP_CAT(MINI_PP_PRIVATE_IS_LESS_IMPL_CURRENT_IS_EQUAL_0_, MINI_PP_IS_EQUAL(0, current))(aAsParams, current, currentMinusOne, currentPlusOne)
#define MINI_PP_PRIVATE_IS_LESS_IMPL_CURRENT_IS_EQUAL_0_1(aAsParams, current, currentMinusOne, currentPlusOne) MINI_PP_PRIVATE_IS_LESS_IMPL_DO_NOT_RECURSE_BECAUSE_CURRENT_IS_0
#define MINI_PP_PRIVATE_IS_LESS_IMPL_CURRENT_IS_EQUAL_0_0(aAsParams, current, currentMinusOne, currentPlusOne) MINI_PP_CAT(MINI_PP_PRIVATE_INT_TOOL_, currentMinusOne)
#define MINI_PP_PRIVATE_IS_LESS_IMPL_DO_NOT_RECURSE_BECAUSE_CURRENT_IS_0(repeatFunc, params) 0
#define MINI_PP_PRIVATE_IS_LESS_IMPL_DO_NOT_RECURSE_BECAUSE_A_IS_EQUAL_CURRENT(repeatFunc, params) 1

#define MINI_PP_IS_MORE(a, b) MINI_PP_AND(MINI_PP_NOT(MINI_PP_IS_EQUAL(a, b)), MINI_PP_IS_LESS(b, a))

#define MINI_PP_IS_LESS_OR_EQUAL(a, b) MINI_PP_NOT(MINI_PP_IS_MORE(a, b))

#define MINI_PP_IS_MORE_OR_EQUAL(a, b) MINI_PP_NOT(MINI_PP_IS_LESS(a, b))

////////////////////////////////////////////////////////////
// Compute Switch With Or Without Va Args
////////////////////////////////////////////////////////////

#define MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(prefix, /*nbFixedArgs,*/ ...) MINI_PP_ASSERT(MINI_PP_NOT(MINI_PP_IS_EQUAL(0, MINI_PP_NB_ARGS(__VA_ARGS__))))MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL(MINI_PP_IS_EQUAL(1, MINI_PP_NB_ARGS(__VA_ARGS__)), prefix, __VA_ARGS__)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL(nbArgsIs1, prefix, /*nbFixedArgs,*/ ...) MINI_PP_CAT(MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_, nbArgsIs1)(prefix, __VA_ARGS__)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_1(prefix, nbFixedArgs) MINI_PP_ASSERT(MINI_PP_IS_EQUAL(0, nbFixedArgs))MINI_PP_CAT(prefix, _WITHOUT_VA_ARGS)
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_0(prefix, /*nbFixedArgs,*/ ...) MINI_PP_EXPAND(MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_0_IMPL(prefix, __VA_ARGS__))
#define MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_NB_ARGS_IS_ONE_0_IMPL(prefix, nbFixedArgs, ...) MINI_PP_PRIVATE_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS_IMPL_SWITCH_IS_ONLY_FIXED(prefix, MINI_PP_IS_EQUAL(nbFixedArgs, MINI_PP_NB_ARGS(__VA_ARGS__)), __VA_ARGS__)
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

#define MINI_PP_TUPLE_IS_EMPTY(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_IS_EMPTY_IMPL t)
#define MINI_PP_PRIVATE_TUPLE_IS_EMPTY_IMPL(...) MINI_PP_IS_EMPTY(__VA_ARGS__)

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

#define MINI_PP_TUPLE_POP_FRONT(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL(MINI_PP_IS_EQUAL(1, MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL(sizeIs1, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_, sizeIs1)(t)
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_1(t) MINI_PP_MAKE_TUPLE()
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_0(t) MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_0_IMPL t
#define MINI_PP_PRIVATE_TUPLE_POP_FRONT_IMPL_SIZE_IS_1_0_IMPL(first, ...) MINI_PP_MAKE_TUPLE(__VA_ARGS__)

#define MINI_PP_TUPLE_GET_ELEM_0(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL(MINI_PP_IS_EQUAL(1, MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL(sizeIs1, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_, sizeIs1)(t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_1(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_0(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_MORE_1_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_1_GET(a) a
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_0_IMPL_SIZE_MORE_1_GET(a, ...) a

#define MINI_PP_TUPLE_GET_ELEM_1(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL(MINI_PP_IS_EQUAL(2, MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL(sizeIs2, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_, sizeIs2)(t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_1(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_0(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_MORE_2_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_2_GET(a, b) b
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_1_IMPL_SIZE_MORE_2_GET(a, b, ...) b

#define MINI_PP_TUPLE_GET_ELEM_2(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL(MINI_PP_IS_EQUAL(3, MINI_PP_TUPLE_SIZE(t)), t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL(sizeIs3, t) MINI_PP_CAT(MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_, sizeIs3)(t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_1(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_0(t) MINI_PP_EXPAND(MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_MORE_3_GET t)
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_3_GET(a, b, c) c
#define MINI_PP_PRIVATE_TUPLE_GET_ELEM_2_IMPL_SIZE_MORE_3_GET(a, b, c, ...) c

#define MINI_PP_TUPLE_GET_ELEM_3(t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_TUPLE_GET_ELEM_3_IMPL(MINI_PP_IS_EQUAL(4, MINI_PP_TUPLE_SIZE(t)), t)
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

#define MINI_PP_PRIVATE_IS_INT_IMPL_0
#define MINI_PP_PRIVATE_IS_INT_IMPL_1
#define MINI_PP_PRIVATE_IS_INT_IMPL_2
#define MINI_PP_PRIVATE_IS_INT_IMPL_3
#define MINI_PP_PRIVATE_IS_INT_IMPL_4
#define MINI_PP_PRIVATE_IS_INT_IMPL_5
#define MINI_PP_PRIVATE_IS_INT_IMPL_6
#define MINI_PP_PRIVATE_IS_INT_IMPL_7
#define MINI_PP_PRIVATE_IS_INT_IMPL_8
#define MINI_PP_PRIVATE_IS_INT_IMPL_9
#define MINI_PP_PRIVATE_IS_INT_IMPL_10
#define MINI_PP_PRIVATE_IS_INT_IMPL_11
#define MINI_PP_PRIVATE_IS_INT_IMPL_12
#define MINI_PP_PRIVATE_IS_INT_IMPL_13
#define MINI_PP_PRIVATE_IS_INT_IMPL_14
#define MINI_PP_PRIVATE_IS_INT_IMPL_15
#define MINI_PP_PRIVATE_IS_INT_IMPL_16
#define MINI_PP_PRIVATE_IS_INT_IMPL_17
#define MINI_PP_PRIVATE_IS_INT_IMPL_18
#define MINI_PP_PRIVATE_IS_INT_IMPL_19
#define MINI_PP_PRIVATE_IS_INT_IMPL_20
#define MINI_PP_PRIVATE_IS_INT_IMPL_21
#define MINI_PP_PRIVATE_IS_INT_IMPL_22
#define MINI_PP_PRIVATE_IS_INT_IMPL_23
#define MINI_PP_PRIVATE_IS_INT_IMPL_24
#define MINI_PP_PRIVATE_IS_INT_IMPL_25
#define MINI_PP_PRIVATE_IS_INT_IMPL_26
#define MINI_PP_PRIVATE_IS_INT_IMPL_27
#define MINI_PP_PRIVATE_IS_INT_IMPL_28
#define MINI_PP_PRIVATE_IS_INT_IMPL_29
#define MINI_PP_PRIVATE_IS_INT_IMPL_30
#define MINI_PP_PRIVATE_IS_INT_IMPL_31
#define MINI_PP_PRIVATE_IS_INT_IMPL_32
#define MINI_PP_PRIVATE_IS_INT_IMPL_33
#define MINI_PP_PRIVATE_IS_INT_IMPL_34
#define MINI_PP_PRIVATE_IS_INT_IMPL_35
#define MINI_PP_PRIVATE_IS_INT_IMPL_36
#define MINI_PP_PRIVATE_IS_INT_IMPL_37
#define MINI_PP_PRIVATE_IS_INT_IMPL_38
#define MINI_PP_PRIVATE_IS_INT_IMPL_39
#define MINI_PP_PRIVATE_IS_INT_IMPL_40
#define MINI_PP_PRIVATE_IS_INT_IMPL_41
#define MINI_PP_PRIVATE_IS_INT_IMPL_42
#define MINI_PP_PRIVATE_IS_INT_IMPL_43
#define MINI_PP_PRIVATE_IS_INT_IMPL_44
#define MINI_PP_PRIVATE_IS_INT_IMPL_45
#define MINI_PP_PRIVATE_IS_INT_IMPL_46
#define MINI_PP_PRIVATE_IS_INT_IMPL_47
#define MINI_PP_PRIVATE_IS_INT_IMPL_48
#define MINI_PP_PRIVATE_IS_INT_IMPL_49
#define MINI_PP_PRIVATE_IS_INT_IMPL_50
#define MINI_PP_PRIVATE_IS_INT_IMPL_51
#define MINI_PP_PRIVATE_IS_INT_IMPL_52
#define MINI_PP_PRIVATE_IS_INT_IMPL_53
#define MINI_PP_PRIVATE_IS_INT_IMPL_54
#define MINI_PP_PRIVATE_IS_INT_IMPL_55
#define MINI_PP_PRIVATE_IS_INT_IMPL_56
#define MINI_PP_PRIVATE_IS_INT_IMPL_57
#define MINI_PP_PRIVATE_IS_INT_IMPL_58
#define MINI_PP_PRIVATE_IS_INT_IMPL_59
#define MINI_PP_PRIVATE_IS_INT_IMPL_60
#define MINI_PP_PRIVATE_IS_INT_IMPL_61
#define MINI_PP_PRIVATE_IS_INT_IMPL_62
#define MINI_PP_PRIVATE_IS_INT_IMPL_63
#define MINI_PP_PRIVATE_IS_INT_IMPL_64
#define MINI_PP_PRIVATE_IS_INT_IMPL_65
#define MINI_PP_PRIVATE_IS_INT_IMPL_66
#define MINI_PP_PRIVATE_IS_INT_IMPL_67
#define MINI_PP_PRIVATE_IS_INT_IMPL_68
#define MINI_PP_PRIVATE_IS_INT_IMPL_69
#define MINI_PP_PRIVATE_IS_INT_IMPL_70
#define MINI_PP_PRIVATE_IS_INT_IMPL_71
#define MINI_PP_PRIVATE_IS_INT_IMPL_72
#define MINI_PP_PRIVATE_IS_INT_IMPL_73
#define MINI_PP_PRIVATE_IS_INT_IMPL_74
#define MINI_PP_PRIVATE_IS_INT_IMPL_75
#define MINI_PP_PRIVATE_IS_INT_IMPL_76
#define MINI_PP_PRIVATE_IS_INT_IMPL_77
#define MINI_PP_PRIVATE_IS_INT_IMPL_78
#define MINI_PP_PRIVATE_IS_INT_IMPL_79
#define MINI_PP_PRIVATE_IS_INT_IMPL_80
#define MINI_PP_PRIVATE_IS_INT_IMPL_81
#define MINI_PP_PRIVATE_IS_INT_IMPL_82
#define MINI_PP_PRIVATE_IS_INT_IMPL_83
#define MINI_PP_PRIVATE_IS_INT_IMPL_84
#define MINI_PP_PRIVATE_IS_INT_IMPL_85
#define MINI_PP_PRIVATE_IS_INT_IMPL_86
#define MINI_PP_PRIVATE_IS_INT_IMPL_87
#define MINI_PP_PRIVATE_IS_INT_IMPL_88
#define MINI_PP_PRIVATE_IS_INT_IMPL_89
#define MINI_PP_PRIVATE_IS_INT_IMPL_90
#define MINI_PP_PRIVATE_IS_INT_IMPL_91
#define MINI_PP_PRIVATE_IS_INT_IMPL_92
#define MINI_PP_PRIVATE_IS_INT_IMPL_93
#define MINI_PP_PRIVATE_IS_INT_IMPL_94
#define MINI_PP_PRIVATE_IS_INT_IMPL_95
#define MINI_PP_PRIVATE_IS_INT_IMPL_96
#define MINI_PP_PRIVATE_IS_INT_IMPL_97
#define MINI_PP_PRIVATE_IS_INT_IMPL_98
#define MINI_PP_PRIVATE_IS_INT_IMPL_99
#define MINI_PP_PRIVATE_IS_INT_IMPL_100
#define MINI_PP_PRIVATE_IS_INT_IMPL_101
#define MINI_PP_PRIVATE_IS_INT_IMPL_102
#define MINI_PP_PRIVATE_IS_INT_IMPL_103
#define MINI_PP_PRIVATE_IS_INT_IMPL_104
#define MINI_PP_PRIVATE_IS_INT_IMPL_105
#define MINI_PP_PRIVATE_IS_INT_IMPL_106
#define MINI_PP_PRIVATE_IS_INT_IMPL_107
#define MINI_PP_PRIVATE_IS_INT_IMPL_108
#define MINI_PP_PRIVATE_IS_INT_IMPL_109
#define MINI_PP_PRIVATE_IS_INT_IMPL_110
#define MINI_PP_PRIVATE_IS_INT_IMPL_111
#define MINI_PP_PRIVATE_IS_INT_IMPL_112
#define MINI_PP_PRIVATE_IS_INT_IMPL_113
#define MINI_PP_PRIVATE_IS_INT_IMPL_114
#define MINI_PP_PRIVATE_IS_INT_IMPL_115
#define MINI_PP_PRIVATE_IS_INT_IMPL_116
#define MINI_PP_PRIVATE_IS_INT_IMPL_117
#define MINI_PP_PRIVATE_IS_INT_IMPL_118
#define MINI_PP_PRIVATE_IS_INT_IMPL_119
#define MINI_PP_PRIVATE_IS_INT_IMPL_120
#define MINI_PP_PRIVATE_IS_INT_IMPL_121
#define MINI_PP_PRIVATE_IS_INT_IMPL_122
#define MINI_PP_PRIVATE_IS_INT_IMPL_123
#define MINI_PP_PRIVATE_IS_INT_IMPL_124
#define MINI_PP_PRIVATE_IS_INT_IMPL_125

#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_0_0
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_1_1
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_2_2
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_3_3
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_4_4
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_5_5
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_6_6
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_7_7
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_8_8
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_9_9
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_10_10
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_11_11
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_12_12
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_13_13
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_14_14
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_15_15
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_16_16
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_17_17
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_18_18
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_19_19
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_20_20
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_21_21
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_22_22
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_23_23
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_24_24
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_25_25
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_26_26
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_27_27
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_28_28
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_29_29
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_30_30
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_31_31
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_32_32
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_33_33
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_34_34
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_35_35
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_36_36
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_37_37
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_38_38
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_39_39
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_40_40
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_41_41
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_42_42
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_43_43
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_44_44
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_45_45
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_46_46
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_47_47
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_48_48
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_49_49
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_50_50
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_51_51
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_52_52
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_53_53
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_54_54
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_55_55
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_56_56
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_57_57
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_58_58
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_59_59
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_60_60
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_61_61
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_62_62
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_63_63
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_64_64
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_65_65
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_66_66
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_67_67
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_68_68
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_69_69
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_70_70
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_71_71
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_72_72
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_73_73
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_74_74
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_75_75
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_76_76
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_77_77
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_78_78
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_79_79
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_80_80
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_81_81
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_82_82
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_83_83
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_84_84
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_85_85
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_86_86
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_87_87
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_88_88
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_89_89
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_90_90
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_91_91
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_92_92
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_93_93
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_94_94
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_95_95
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_96_96
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_97_97
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_98_98
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_99_99
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_100_100
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_101_101
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_102_102
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_103_103
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_104_104
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_105_105
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_106_106
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_107_107
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_108_108
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_109_109
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_110_110
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_111_111
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_112_112
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_113_113
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_114_114
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_115_115
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_116_116
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_117_117
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_118_118
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_119_119
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_120_120
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_121_121
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_122_122
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_123_123
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_124_124
#define MINI_PP_PRIVATE_IS_EQUAL_IMPL_125_125

#define MINI_PP_PRIVATE_INT_TOOL_0(repeatFunc, params) repeatFunc(params, 0, NONE, 1)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_1(repeatFunc, params) repeatFunc(params, 1, 0, 2)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_2(repeatFunc, params) repeatFunc(params, 2, 1, 3)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_3(repeatFunc, params) repeatFunc(params, 3, 2, 4)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_4(repeatFunc, params) repeatFunc(params, 4, 3, 5)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_5(repeatFunc, params) repeatFunc(params, 5, 4, 6)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_6(repeatFunc, params) repeatFunc(params, 6, 5, 7)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_7(repeatFunc, params) repeatFunc(params, 7, 6, 8)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_8(repeatFunc, params) repeatFunc(params, 8, 7, 9)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_9(repeatFunc, params) repeatFunc(params, 9, 8, 10)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_10(repeatFunc, params) repeatFunc(params, 10, 9, 11)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_11(repeatFunc, params) repeatFunc(params, 11, 10, 12)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_12(repeatFunc, params) repeatFunc(params, 12, 11, 13)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_13(repeatFunc, params) repeatFunc(params, 13, 12, 14)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_14(repeatFunc, params) repeatFunc(params, 14, 13, 15)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_15(repeatFunc, params) repeatFunc(params, 15, 14, 16)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_16(repeatFunc, params) repeatFunc(params, 16, 15, 17)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_17(repeatFunc, params) repeatFunc(params, 17, 16, 18)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_18(repeatFunc, params) repeatFunc(params, 18, 17, 19)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_19(repeatFunc, params) repeatFunc(params, 19, 18, 20)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_20(repeatFunc, params) repeatFunc(params, 20, 19, 21)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_21(repeatFunc, params) repeatFunc(params, 21, 20, 22)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_22(repeatFunc, params) repeatFunc(params, 22, 21, 23)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_23(repeatFunc, params) repeatFunc(params, 23, 22, 24)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_24(repeatFunc, params) repeatFunc(params, 24, 23, 25)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_25(repeatFunc, params) repeatFunc(params, 25, 24, 26)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_26(repeatFunc, params) repeatFunc(params, 26, 25, 27)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_27(repeatFunc, params) repeatFunc(params, 27, 26, 28)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_28(repeatFunc, params) repeatFunc(params, 28, 27, 29)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_29(repeatFunc, params) repeatFunc(params, 29, 28, 30)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_30(repeatFunc, params) repeatFunc(params, 30, 29, 31)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_31(repeatFunc, params) repeatFunc(params, 31, 30, 32)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_32(repeatFunc, params) repeatFunc(params, 32, 31, 33)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_33(repeatFunc, params) repeatFunc(params, 33, 32, 34)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_34(repeatFunc, params) repeatFunc(params, 34, 33, 35)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_35(repeatFunc, params) repeatFunc(params, 35, 34, 36)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_36(repeatFunc, params) repeatFunc(params, 36, 35, 37)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_37(repeatFunc, params) repeatFunc(params, 37, 36, 38)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_38(repeatFunc, params) repeatFunc(params, 38, 37, 39)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_39(repeatFunc, params) repeatFunc(params, 39, 38, 40)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_40(repeatFunc, params) repeatFunc(params, 40, 39, 41)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_41(repeatFunc, params) repeatFunc(params, 41, 40, 42)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_42(repeatFunc, params) repeatFunc(params, 42, 41, 43)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_43(repeatFunc, params) repeatFunc(params, 43, 42, 44)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_44(repeatFunc, params) repeatFunc(params, 44, 43, 45)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_45(repeatFunc, params) repeatFunc(params, 45, 44, 46)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_46(repeatFunc, params) repeatFunc(params, 46, 45, 47)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_47(repeatFunc, params) repeatFunc(params, 47, 46, 48)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_48(repeatFunc, params) repeatFunc(params, 48, 47, 49)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_49(repeatFunc, params) repeatFunc(params, 49, 48, 50)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_50(repeatFunc, params) repeatFunc(params, 50, 49, 51)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_51(repeatFunc, params) repeatFunc(params, 51, 50, 52)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_52(repeatFunc, params) repeatFunc(params, 52, 51, 53)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_53(repeatFunc, params) repeatFunc(params, 53, 52, 54)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_54(repeatFunc, params) repeatFunc(params, 54, 53, 55)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_55(repeatFunc, params) repeatFunc(params, 55, 54, 56)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_56(repeatFunc, params) repeatFunc(params, 56, 55, 57)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_57(repeatFunc, params) repeatFunc(params, 57, 56, 58)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_58(repeatFunc, params) repeatFunc(params, 58, 57, 59)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_59(repeatFunc, params) repeatFunc(params, 59, 58, 60)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_60(repeatFunc, params) repeatFunc(params, 60, 59, 61)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_61(repeatFunc, params) repeatFunc(params, 61, 60, 62)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_62(repeatFunc, params) repeatFunc(params, 62, 61, 63)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_63(repeatFunc, params) repeatFunc(params, 63, 62, 64)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_64(repeatFunc, params) repeatFunc(params, 64, 63, 65)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_65(repeatFunc, params) repeatFunc(params, 65, 64, 66)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_66(repeatFunc, params) repeatFunc(params, 66, 65, 67)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_67(repeatFunc, params) repeatFunc(params, 67, 66, 68)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_68(repeatFunc, params) repeatFunc(params, 68, 67, 69)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_69(repeatFunc, params) repeatFunc(params, 69, 68, 70)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_70(repeatFunc, params) repeatFunc(params, 70, 69, 71)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_71(repeatFunc, params) repeatFunc(params, 71, 70, 72)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_72(repeatFunc, params) repeatFunc(params, 72, 71, 73)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_73(repeatFunc, params) repeatFunc(params, 73, 72, 74)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_74(repeatFunc, params) repeatFunc(params, 74, 73, 75)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_75(repeatFunc, params) repeatFunc(params, 75, 74, 76)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_76(repeatFunc, params) repeatFunc(params, 76, 75, 77)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_77(repeatFunc, params) repeatFunc(params, 77, 76, 78)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_78(repeatFunc, params) repeatFunc(params, 78, 77, 79)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_79(repeatFunc, params) repeatFunc(params, 79, 78, 80)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_80(repeatFunc, params) repeatFunc(params, 80, 79, 81)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_81(repeatFunc, params) repeatFunc(params, 81, 80, 82)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_82(repeatFunc, params) repeatFunc(params, 82, 81, 83)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_83(repeatFunc, params) repeatFunc(params, 83, 82, 84)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_84(repeatFunc, params) repeatFunc(params, 84, 83, 85)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_85(repeatFunc, params) repeatFunc(params, 85, 84, 86)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_86(repeatFunc, params) repeatFunc(params, 86, 85, 87)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_87(repeatFunc, params) repeatFunc(params, 87, 86, 88)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_88(repeatFunc, params) repeatFunc(params, 88, 87, 89)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_89(repeatFunc, params) repeatFunc(params, 89, 88, 90)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_90(repeatFunc, params) repeatFunc(params, 90, 89, 91)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_91(repeatFunc, params) repeatFunc(params, 91, 90, 92)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_92(repeatFunc, params) repeatFunc(params, 92, 91, 93)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_93(repeatFunc, params) repeatFunc(params, 93, 92, 94)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_94(repeatFunc, params) repeatFunc(params, 94, 93, 95)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_95(repeatFunc, params) repeatFunc(params, 95, 94, 96)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_96(repeatFunc, params) repeatFunc(params, 96, 95, 97)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_97(repeatFunc, params) repeatFunc(params, 97, 96, 98)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_98(repeatFunc, params) repeatFunc(params, 98, 97, 99)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_99(repeatFunc, params) repeatFunc(params, 99, 98, 100)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_100(repeatFunc, params) repeatFunc(params, 100, 99, 101)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_101(repeatFunc, params) repeatFunc(params, 101, 100, 102)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_102(repeatFunc, params) repeatFunc(params, 102, 101, 103)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_103(repeatFunc, params) repeatFunc(params, 103, 102, 104)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_104(repeatFunc, params) repeatFunc(params, 104, 103, 105)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_105(repeatFunc, params) repeatFunc(params, 105, 104, 106)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_106(repeatFunc, params) repeatFunc(params, 106, 105, 107)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_107(repeatFunc, params) repeatFunc(params, 107, 106, 108)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_108(repeatFunc, params) repeatFunc(params, 108, 107, 109)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_109(repeatFunc, params) repeatFunc(params, 109, 108, 110)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_110(repeatFunc, params) repeatFunc(params, 110, 109, 111)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_111(repeatFunc, params) repeatFunc(params, 111, 110, 112)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_112(repeatFunc, params) repeatFunc(params, 112, 111, 113)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_113(repeatFunc, params) repeatFunc(params, 113, 112, 114)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_114(repeatFunc, params) repeatFunc(params, 114, 113, 115)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_115(repeatFunc, params) repeatFunc(params, 115, 114, 116)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_116(repeatFunc, params) repeatFunc(params, 116, 115, 117)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_117(repeatFunc, params) repeatFunc(params, 117, 116, 118)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_118(repeatFunc, params) repeatFunc(params, 118, 117, 119)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_119(repeatFunc, params) repeatFunc(params, 119, 118, 120)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_120(repeatFunc, params) repeatFunc(params, 120, 119, 121)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_121(repeatFunc, params) repeatFunc(params, 121, 120, 122)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_122(repeatFunc, params) repeatFunc(params, 122, 121, 123)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_123(repeatFunc, params) repeatFunc(params, 123, 122, 124)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_124(repeatFunc, params) repeatFunc(params, 124, 123, 125)(repeatFunc, params)
#define MINI_PP_PRIVATE_INT_TOOL_125(repeatFunc, params) repeatFunc(params, 125, 124, NONE)(repeatFunc, params)

#endif
