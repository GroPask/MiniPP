#ifndef MINI_PP_VERSION
#include "MiniPP/MiniPP.hpp"
#endif

#define ZERO 0
#define ONE() 1

///////////////// MINI_PP_NOT /////////////////
static_assert(MINI_PP_NOT(0) == 1, "MINI_PP_NOT is broken");
static_assert(MINI_PP_NOT(1) == 0, "MINI_PP_NOT is broken");
static_assert(MINI_PP_NOT(ZERO) == 1, "MINI_PP_NOT is broken");
static_assert(MINI_PP_NOT(ONE()) == 0, "MINI_PP_NOT is broken");

///////////////// MINI_PP_OR /////////////////
static_assert(MINI_PP_OR(0, 0) == 0, "MINI_PP_OR is broken");
static_assert(MINI_PP_OR(0, 1) == 1, "MINI_PP_OR is broken");
static_assert(MINI_PP_OR(1, 0) == 1, "MINI_PP_OR is broken");
static_assert(MINI_PP_OR(1, 1) == 1, "MINI_PP_OR is broken");
static_assert(MINI_PP_OR(ZERO, ZERO) == 0, "MINI_PP_OR is broken");
static_assert(MINI_PP_OR(ZERO, ONE()) == 1, "MINI_PP_OR is broken");
static_assert(MINI_PP_OR(ONE(), ZERO) == 1, "MINI_PP_OR is broken");
static_assert(MINI_PP_OR(ONE(), ONE()) == 1, "MINI_PP_OR is broken");

///////////////// MINI_PP_AND /////////////////
static_assert(MINI_PP_AND(0, 0) == 0, "MINI_PP_AND is broken");
static_assert(MINI_PP_AND(0, 1) == 0, "MINI_PP_AND is broken");
static_assert(MINI_PP_AND(1, 0) == 0, "MINI_PP_AND is broken");
static_assert(MINI_PP_AND(1, 1) == 1, "MINI_PP_AND is broken");
static_assert(MINI_PP_AND(ZERO, ZERO) == 0, "MINI_PP_AND is broken");
static_assert(MINI_PP_AND(ZERO, ONE()) == 0, "MINI_PP_AND is broken");
static_assert(MINI_PP_AND(ONE(), ZERO) == 0, "MINI_PP_AND is broken");
static_assert(MINI_PP_AND(ONE(), ONE()) == ONE(), "MINI_PP_AND is broken");

///////////////// MINI_PP_IF /////////////////
static_assert(MINI_PP_IF(0, 4) 2 == 2, "MINI_PP_IF is broken");
static_assert(MINI_PP_IF(1, 42) == 42, "MINI_PP_IF is broken");
static_assert(MINI_PP_IF(ZERO, 4) 2 == 2, "MINI_PP_IF is broken");
static_assert(MINI_PP_IF(ONE(), 42) == 42, "MINI_PP_IF is broken");

///////////////// MINI_PP_IF_ELSE /////////////////
static_assert(MINI_PP_IF_ELSE(0, 123, 456) == 456, "MINI_PP_IF_ELSE is broken");
static_assert(MINI_PP_IF_ELSE(1, 123, 456) == 123, "MINI_PP_IF_ELSE is broken");
static_assert(MINI_PP_IF_ELSE(ZERO, 123, 456) == 456, "MINI_PP_IF_ELSE is broken");
static_assert(MINI_PP_IF_ELSE(ONE(), 123, 456) == 123, "MINI_PP_IF_ELSE is broken");
