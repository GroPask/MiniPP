#ifndef MINI_PP_VERSION
#include "MiniPP/MiniPP.hpp"
#endif

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
static_assert(MINI_PP_TO_TEXT(42)[0] == '4', "MINI_PP_TO_TEXT is broken");
static_assert(MINI_PP_TO_TEXT(42)[1] == '2', "MINI_PP_TO_TEXT is broken");
static_assert(MINI_PP_TO_TEXT(42)[2] == '\0', "MINI_PP_TO_TEXT is broken");
static_assert(MINI_PP_TO_TEXT(VALUE_4)[0] == '4', "MINI_PP_TO_TEXT is broken");
static_assert(MINI_PP_TO_TEXT(VALUE_4)[1] == '\0', "MINI_PP_TO_TEXT is broken");
static_assert(MINI_PP_TO_TEXT(VALUE_42())[0] == '4', "MINI_PP_TO_TEXT is broken");
static_assert(MINI_PP_TO_TEXT(VALUE_42())[1] == '2', "MINI_PP_TO_TEXT is broken");
static_assert(MINI_PP_TO_TEXT(VALUE_42())[2] == '\0', "MINI_PP_TO_TEXT is broken");

///////////////// MINI_PP_DEFER /////////////////
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[0] == 'V', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[1] == 'A', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[2] == 'L', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[3] == 'U', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[4] == 'E', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[5] == '_', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[6] == '4', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[7] == '2', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[8] == ' ', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[9] == '(', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[10] == ')', "MINI_PP_DEFER is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_DEFER(VALUE_42)())[11] == '\0', "MINI_PP_DEFER is broken");

///////////////// MINI_PP_EXPAND /////////////////
static_assert(MINI_PP_EXPAND(42) == 42, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_4) == 4, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_42()) == 42, "MINI_PP_EXPAND is broken");
static_assert(MINI_PP_EXPAND(VALUE_42 MINI_PP_PARENS) == 42, "MINI_PP_EXPAND is broken");

///////////////// MINI_PP_TO_TEXT + MINI_PP_CAT /////////////////
static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(4, 2))[0] == '4', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(4, 2))[1] == '2', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(4, 2))[2] == '\0', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");

static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, 2))[0] == '4', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, 2))[1] == '2', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, 2))[2] == '\0', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");

static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, VALUE_2))[0] == '4', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, VALUE_2))[1] == '2', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(VALUE_4, VALUE_2))[2] == '\0', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");

static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(BEGIN, E_4))[0] == '4', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");
static_assert(MINI_PP_TO_TEXT(MINI_PP_CAT(BEGIN, E_4))[1] == '\0', "MINI_PP_TO_TEXT + MINI_PP_CAT is broken");

///////////////// MINI_PP_EXPAND + MINI_PP_DEFER + MINI_PP_TO_TEXT + MINI_PP_PARENS /////////////////
static_assert(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(VALUE_42 MINI_PP_PARENS))[0] == '4', "MINI_PP_EXPAND + MINI_PP_DEFER + MINI_PP_TO_TEXT + MINI_PP_PARENS is broken");
static_assert(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(VALUE_42 MINI_PP_PARENS))[1] == '2', "MINI_PP_EXPAND + MINI_PP_DEFER + MINI_PP_TO_TEXT + MINI_PP_PARENS is broken");
static_assert(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(VALUE_42 MINI_PP_PARENS))[2] == '\0', "MINI_PP_EXPAND + MINI_PP_DEFER + MINI_PP_TO_TEXT + MINI_PP_PARENS is broken");
