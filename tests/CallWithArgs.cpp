#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#include "TestUtility.hpp"
#endif

#define VALUE_4 4
#define VALUE_2 2
#define VALUE_42() 42
#define ARG_SEQ_4_2 4, 2
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

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT /////////////////
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, VALUE_42()), "42"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT is broken");

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_PARENS /////////////////
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, VALUE_42 MINI_PP_PARENS), "42"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_PARENS is broken");

///////////////// MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_CALL_WITH_ARGS /////////////////
static_assert(stringsEqual(MINI_PP_CALL_WITH_ARGS(MINI_PP_TO_TEXT, MINI_PP_CALL_WITH_ARGS(VALUE_42)), "42"), "MINI_PP_CALL_WITH_ARGS + MINI_PP_TO_TEXT + MINI_PP_CALL_WITH_ARGS is broken");
