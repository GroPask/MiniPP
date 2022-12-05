#ifndef MINI_PP_VERSION
#include "MiniPP/MiniPP.hpp"
#endif

///////////////// MINI_PP_MAX_NB_ARGS /////////////////
static_assert(MINI_PP_MAX_NB_ARGS > 0, "MINI_PP_MAX_NB_ARGS is broken");

///////////////// MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE /////////////////
namespace
{
    constexpr bool checkArgSeqMaxMinusOneTrueThenFalse()
    {
        const int maxMinusOneTrueThenFalseArray[] = { MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE };

        const int size = (sizeof(maxMinusOneTrueThenFalseArray) / sizeof(*maxMinusOneTrueThenFalseArray));
        static_assert(size == MINI_PP_MAX_NB_ARGS, "MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE is broken");

        for (int i = 0; i < size - 1; ++i)
        {
            if (maxMinusOneTrueThenFalseArray[i] != 1)
                return false;
        }

        return (maxMinusOneTrueThenFalseArray[size - 1] == 0);
    }
    
}

static_assert(checkArgSeqMaxMinusOneTrueThenFalse(), "MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE is broken");

///////////////// MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 /////////////////
namespace
{
    constexpr bool checkArgSeqMaxTo0()
    {
        const int maxMinusOneTrueThenFalseArray[] = { MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 };

        const int size = (sizeof(maxMinusOneTrueThenFalseArray) / sizeof(*maxMinusOneTrueThenFalseArray));
        static_assert(size == (MINI_PP_MAX_NB_ARGS + 1), "MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 is broken");

        for (int i = 0; i < size; ++i)
        {
            if (maxMinusOneTrueThenFalseArray[i] != (MINI_PP_MAX_NB_ARGS - i))
                return false;
        }

        return true;
    }

    static_assert(checkArgSeqMaxTo0(), "MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 is broken");
}

///////////////// MINI_PP_PRIVATE_GET_ARG_INDEX_MAX /////////////////
static_assert(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX)(MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE, 42)) == 42, "MINI_PP_PRIVATE_GET_ARG_INDEX_MAX is broken");
static_assert(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_PRIVATE_GET_ARG_INDEX_MAX)(MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0)) == 0, "MINI_PP_PRIVATE_GET_ARG_INDEX_MAX is broken");
