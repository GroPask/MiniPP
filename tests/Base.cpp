#include "MiniPP/MiniPP.hpp"
#include "TestUtility.hpp"

#define VALUE_4 4
#define VALUE_2 2
#define VALUE_42() 42
#define BEGIN VALU
#define ARG_SEQ_4_2 4, 2
#define GET_FIRST(a, b) a
#define GET_SECOND(a, b) b

///////////////// MINI_PP_CAT /////////////////
static_assert(MINI_PP_CAT(4, 2) == 42, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(VALUE_4, 2) == 42, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(VALUE_4, VALUE_2) == 42, "MINI_PP_CAT is broken");
static_assert(MINI_PP_CAT(BEGIN, E_4) == 4, "MINI_PP_CAT is broken");

///////////////// MINI_PP_TO_TEXT /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(42), "42"), "MINI_PP_TO_TEXT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(VALUE_4), "4"), "MINI_PP_TO_TEXT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(VALUE_42()), "42"), "MINI_PP_TO_TEXT is broken");

///////////////// MINI_PP_DEFER /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)()), "VALUE_42 ()"), "MINI_PP_DEFER is broken");

///////////////// MINI_PP_EXPAND /////////////////
static_assert(MINI_PP_EXPAND(42) == 42, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_4) == 4, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_42()) == 42, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_42 MINI_PP_PARENS) == 42, "MINI_PP_EXPAND is broken");

///////////////// MINI_PP_TO_TEXT + MINI_PP_CAT /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, 2)), "42"), "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, 2)), "42"), "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, VALUE_2)), "42"), "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(BEGIN, E_4)), "4"), "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");

///////////////// MINI_PP_EXPAND + MINI_PP_DEFER + MINI_PP_TO_TEXT + MINI_PP_PARENS /////////////////
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(VALUE_42 MINI_PP_PARENS)), "42"), "MINI_PP_EXPAND + MINI_PP_DEFER + MINI_PP_TO_TEXT + MINI_PP_PARENS is broken");
