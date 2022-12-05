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

#define MINI_PP_HAS_DIRECT_COMMA(...) MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX)(__VA_ARGS__, MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE, dummy))

#define MINI_PP_IS_EMPTY(...) \
    MINI_PP_AND( \
        MINI_PP_AND( \
            MINI_PP_NOT(MINI_PP_HAS_DIRECT_COMMA(__VA_ARGS__)), \
            MINI_PP_HAS_DIRECT_COMMA(MINI_PP_PRIVATE_IS_EMPTY_PAREN_CHECK __VA_ARGS__ ()) \
        ), \
        MINI_PP_NOT(MINI_PP_HAS_DIRECT_COMMA(MINI_PP_PRIVATE_IS_EMPTY_PAREN_CHECK __VA_ARGS__)) \
    )
#define MINI_PP_PRIVATE_IS_EMPTY_PAREN_CHECK(...) ,

#define MINI_PP_NB_ARGS(...) MINI_PP_IF_ELSE(MINI_PP_IS_EMPTY(__VA_ARGS__), 0, MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX)(__VA_ARGS__, MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0)))

#define MINI_PP_IS_PAREN(x) MINI_PP_CAT(MINI_PP_PRIVATE_IS_PAREN_SWITCH_, MINI_PP_NB_ARGS(MINI_PP_PRIVATE_IS_PAREN_CHECK_CALLABLE x))
#define MINI_PP_PRIVATE_IS_PAREN_CHECK_CALLABLE(...) dummyA, dummyB
#define MINI_PP_PRIVATE_IS_PAREN_SWITCH_1 0
#define MINI_PP_PRIVATE_IS_PAREN_SWITCH_2 1

////////////////////////////////////////////////////////////
// Call With Args
////////////////////////////////////////////////////////////
#define MINI_PP_CALL_WITH_ARGS(f, ...) MINI_PP_EXPAND(MINI_PP_DEFER(f)(__VA_ARGS__))

////////////////////////////////////////////////////////////
// Unroll Utility
////////////////////////////////////////////////////////////

#define MINI_PP_MAX_NB_ARGS 16

#define MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0
#define MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define MINI_PP_PRIVATE_GET_ARG_INDEX_MAX(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) _16

#endif
