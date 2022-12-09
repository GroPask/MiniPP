#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#include "TestUtility.hpp"
#endif

////////////////////////////////////////////////////////////
// Call With Args
// Should not be used any more but keep it here for tests
////////////////////////////////////////////////////////////

#define MINI_PP_CALL_WITH_ARGS(/*func,*/ ...) MINI_PP_EXPAND(MINI_PP_COMPUTE_SWITCH_WITH_OR_WITHOUT_VA_ARGS(MINI_PP_PRIVATE_CALL_WITH_ARGS_IMPL, 1, __VA_ARGS__)(__VA_ARGS__))
#define MINI_PP_PRIVATE_CALL_WITH_ARGS_IMPL_WITHOUT_VA_ARGS(func) MINI_PP_EXPAND(func())
#define MINI_PP_PRIVATE_CALL_WITH_ARGS_IMPL_WITH_VA_ARGS(func, ...) MINI_PP_EXPAND(func(__VA_ARGS__))

////////////////////////////////////////////////////////////

#define VALUE_4 4
#define VALUE_2 2
#define VALUE_42() 42
#define ARG_SEQ_4_2 4, 2
#define ARG_SEQ_4_2_CALL() 4, 2
#define GET_FIRST(a, b) a
#define GET_SECOND(a, b) b

///////////////// MINI_PP_CALL_WITH_ARGS /////////////////
static_assert(MINI_PP_CALL_WITH_ARGS(VALUE_42) == 42, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CALL_WITH_ARGS(GET_FIRST, 4, 2) == 4, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CALL_WITH_ARGS(GET_SECOND, 4, 2) == 2, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CALL_WITH_ARGS(GET_FIRST, VALUE_4, 2) == 4, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CALL_WITH_ARGS(GET_SECOND, VALUE_4, VALUE_2) == 2, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CALL_WITH_ARGS(GET_FIRST, ARG_SEQ_4_2) == 4, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CALL_WITH_ARGS(GET_SECOND, ARG_SEQ_4_2) == 2, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_ARGS(VALUE_42)) == 442, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_ARGS(GET_FIRST, 4, 2)) == 44, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_ARGS(GET_SECOND, 4, 2)) == 42, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_ARGS(GET_FIRST, VALUE_4, 2)) == 44, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_ARGS(GET_SECOND, VALUE_4, VALUE_2)) == 42, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_ARGS(GET_FIRST, ARG_SEQ_4_2)) == 44, "MINI_PP_CALL_WITH_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_ARGS(GET_SECOND, ARG_SEQ_4_2)) == 42, "MINI_PP_CALL_WITH_ARGS is broken");

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT /////////////////
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, VALUE_42()), "42"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT is broken");

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_PARENS /////////////////
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, VALUE_42 MINI_PP_PARENS), "42"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_PARENS is broken");

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_CALL_WITH_ARGS /////////////////
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, MINI_PP_CALL_WITH_ARGS(VALUE_42)), "42"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_CALL_WITH_ARGS is broken");

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_EXPAND /////////////////
#define TO_TEXT_2(a, b) MINI_PP_TO_TEXT(a) ", " MINI_PP_TO_TEXT(b)
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, MINI_PP_TUPLE_EXPAND((a))), "a"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_EXPAND is broken");
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(TO_TEXT_2, MINI_PP_TUPLE_EXPAND((ARG_SEQ_4_2))), "4, 2"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_EXPAND is broken");
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(TO_TEXT_2, MINI_PP_TUPLE_EXPAND((ARG_SEQ_4_2_CALL()))), "4, 2"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_EXPAND is broken");

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_POP_FRONT /////////////////
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, MINI_PP_TUPLE_POP_FRONT((1, 2))), "(2)"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, MINI_PP_TUPLE_POP_FRONT((ARG_SEQ_4_2))), "(2)"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, MINI_PP_TUPLE_POP_FRONT((ARG_SEQ_4_2_CALL()))), "(2)"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_POP_FRONT is broken");

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_GET_ELEM_0 /////////////////
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, MINI_PP_TUPLE_GET_ELEM_0((ARG_SEQ_4_2))), "4"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, MINI_PP_TUPLE_GET_ELEM_0((ARG_SEQ_4_2_CALL()))), "4"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_TUPLE_GET_ELEM_0 is broken");
