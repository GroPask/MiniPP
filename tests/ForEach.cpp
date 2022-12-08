#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#include "TestUtility.hpp"
#endif

#define PLUS_NUMBER(x) + x
#define TO_TEXT_WITH_PARAMS(params, x) MINI_PP_TO_TEXT(MINI_PP_CAT(params, x))
#define PLUS_NUMBER_WITH_PARAMS(params, x) + params + x

///////////////// MINI_PP_FOR_EACH /////////////////
enum class EnumForEach
{
    First = 0,

    #define DECLARE_VALUE(x) MINI_PP_CAT(Value, x),

    MINI_PP_FOR_EACH(DECLARE_VALUE)
    MINI_PP_FOR_EACH(DECLARE_VALUE, A)
    MINI_PP_FOR_EACH(DECLARE_VALUE, B, C, D)

    #define DECLARE_VALUES(...) MINI_PP_FOR_EACH(DECLARE_VALUE, __VA_ARGS__)

    DECLARE_VALUES()
    DECLARE_VALUES(E)
    DECLARE_VALUES(F, G, H)
};

static_assert(static_cast<int>(EnumForEach::ValueA) == 1, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueB) == 2, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueC) == 3, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueD) == 4, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueE) == 5, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueF) == 6, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueG) == 7, "MINI_PP_FOR_EACH is broken");
static_assert(static_cast<int>(EnumForEach::ValueH) == 8, "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_FOR_EACH(MINI_PP_TO_TEXT, A), "A"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_FOR_EACH(MINI_PP_TO_TEXT, B, C, D), "BCD"), "MINI_PP_FOR_EACH is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_FOR_EACH(PLUS_NUMBER, 2)) == 6, "MINI_PP_FOR_EACH is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_FOR_EACH(PLUS_NUMBER, 2, 3, 4)) == 13, "MINI_PP_FOR_EACH is broken");

///////////////// MINI_PP_FOR_EACH_WITH_PARAMS /////////////////
enum class EnumForEachWithParams
{
    First = 0,

    #define DECLARE_VALUE_WITH_PARAMS(param, x) MINI_PP_CAT(MINI_PP_CAT(Value, param), x),

    MINI_PP_FOR_EACH_WITH_PARAMS(DECLARE_VALUE_WITH_PARAMS, Foo)
    MINI_PP_FOR_EACH_WITH_PARAMS(DECLARE_VALUE_WITH_PARAMS, Foo, A)
    MINI_PP_FOR_EACH_WITH_PARAMS(DECLARE_VALUE_WITH_PARAMS, Foo, B, C, D)

    #define DECLARE_VALUES_WITH_PARAMS(...) MINI_PP_FOR_EACH_WITH_PARAMS(DECLARE_VALUE_WITH_PARAMS, Bar, __VA_ARGS__)

    DECLARE_VALUES_WITH_PARAMS()
    DECLARE_VALUES_WITH_PARAMS(E)
    DECLARE_VALUES_WITH_PARAMS(F, G, H)
};

static_assert(static_cast<int>(EnumForEachWithParams::ValueFooA) == 1, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueFooB) == 2, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueFooC) == 3, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueFooD) == 4, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueBarE) == 5, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueBarF) == 6, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueBarG) == 7, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(static_cast<int>(EnumForEachWithParams::ValueBarH) == 8, "MINI_PP_FOR_EACH_WITH_PARAMS is broken");
static_assert(stringsEqual(MINI_PP_FOR_EACH_WITH_PARAMS(TO_TEXT_WITH_PARAMS, Foo, A), "FooA"), "MINI_PP_FOR_EACH is broken");
static_assert(stringsEqual(MINI_PP_FOR_EACH_WITH_PARAMS(TO_TEXT_WITH_PARAMS, Foo, B, C, D), "FooBFooCFooD"), "MINI_PP_FOR_EACH is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_FOR_EACH_WITH_PARAMS(PLUS_NUMBER_WITH_PARAMS, 42, 2)) == 48, "MINI_PP_FOR_EACH is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_FOR_EACH_WITH_PARAMS(PLUS_NUMBER_WITH_PARAMS, 42, 2, 3, 4)) == 139, "MINI_PP_FOR_EACH is broken");
