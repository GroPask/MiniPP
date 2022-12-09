#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#include "TestUtility.hpp"
#endif

////////////////////////////////////////////////////////////
// Call With Tuple
// Should not be used any more but keep it here for tests
////////////////////////////////////////////////////////////

#define MINI_PP_CALL_WITH_TUPLE(f, t) MINI_PP_ASSERT(MINI_PP_IS_TUPLE(t))MINI_PP_PRIVATE_CALL_WITH_TUPLE_IMPL(f, t)
#define MINI_PP_PRIVATE_CALL_WITH_TUPLE_IMPL(f, t) MINI_PP_EXPAND(f t)

////////////////////////////////////////////////////////////

#define A a
#define A_B a, b
#define A_CALL() a
#define A_B_CALL() a, b
#define A_B_TUPLE (a, b)
#define A_B_TUPLE_CALL (a, b)

///////////////// MINI_PP_MAKE_TUPLE /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_MAKE_TUPLE()), "()"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_MAKE_TUPLE(a)), "(a)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_MAKE_TUPLE(a, b)), "(a, b)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_MAKE_TUPLE(A)), "(a)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_MAKE_TUPLE(A_B)), "(a, b)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_MAKE_TUPLE(A_CALL())), "(a)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_MAKE_TUPLE(A_B_CALL())), "(a, b)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_MAKE_TUPLE())), "4dummy ()"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_MAKE_TUPLE(a))), "4dummy (a)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_MAKE_TUPLE(a, b))), "4dummy (a, b)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_MAKE_TUPLE(A))), "4dummy (a)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_MAKE_TUPLE(A_B))), "4dummy (a, b)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_MAKE_TUPLE(A_CALL()))), "4dummy (a)"), "MINI_PP_MAKE_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_MAKE_TUPLE(A_B_CALL()))), "4dummy (a, b)"), "MINI_PP_MAKE_TUPLE is broken");

///////////////// MINI_PP_IS_TUPLE /////////////////
static_assert(MINI_PP_IS_TUPLE(a) == 0, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_IS_TUPLE(MINI_PP_MAKE_TUPLE()) == 1, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_IS_TUPLE(MINI_PP_MAKE_TUPLE(a)) == 1, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_IS_TUPLE(MINI_PP_MAKE_TUPLE(a, b)) == 1, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_IS_TUPLE(()) == 1, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_IS_TUPLE((a)) == 1, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_IS_TUPLE((a, b)) == 1, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_IS_TUPLE(A_B_TUPLE) == 1, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_IS_TUPLE(A_B_TUPLE_CALL()) == 1, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE(a)) == 40, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE(MINI_PP_MAKE_TUPLE())) == 41, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE(MINI_PP_MAKE_TUPLE(a))) == 41, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE(MINI_PP_MAKE_TUPLE(a, b))) == 41, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE(())) == 41, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE((a))) == 41, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE((a, b))) == 41, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE(A_B_TUPLE)) == 41, "MINI_PP_IS_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_TUPLE(A_B_TUPLE_CALL())) == 41, "MINI_PP_IS_TUPLE is broken");

///////////////// MINI_PP_CALL_WITH_TUPLE /////////////////
static_assert(MINI_PP_CALL_WITH_TUPLE(MINI_PP_NB_ARGS, ()) == 0, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CALL_WITH_TUPLE(MINI_PP_EXPAND, (1)) == 1, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CALL_WITH_TUPLE(MINI_PP_CAT, (1, 2)) == 12, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CALL_WITH_TUPLE(MINI_PP_NB_ARGS, (1, 2, 3, 4)) == 4, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_CALL_WITH_TUPLE(MINI_PP_TO_TEXT, (A)), "a"), "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CALL_WITH_TUPLE(MINI_PP_NB_ARGS, (A_B)) == 2, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(stringsEqual(MINI_PP_CALL_WITH_TUPLE(MINI_PP_TO_TEXT, (A_CALL())), "a"), "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CALL_WITH_TUPLE(MINI_PP_NB_ARGS, (A_B_CALL())) == 2, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_TUPLE(MINI_PP_NB_ARGS, ())) == 40, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_TUPLE(MINI_PP_EXPAND, (1))) == 41, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_TUPLE(MINI_PP_CAT, (1, 2))) == 412, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_TUPLE(MINI_PP_NB_ARGS, (1, 2, 3, 4))) == 44, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_TUPLE(MINI_PP_NB_ARGS, (A_B))) == 42, "MINI_PP_CALL_WITH_TUPLE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_CALL_WITH_TUPLE(MINI_PP_NB_ARGS, (A_B_CALL()))) == 42, "MINI_PP_CALL_WITH_TUPLE is broken");

///////////////// MINI_PP_TUPLE_EXPAND /////////////////
static_assert(MINI_PP_TUPLE_EXPAND((1)) == 1, "MINI_PP_TUPLE_EXPAND is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_EXPAND((a)))), "a"), "MINI_PP_TUPLE_EXPAND is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_EXPAND((A)))), "a"), "MINI_PP_TUPLE_EXPAND is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_EXPAND((A_CALL())))), "a"), "MINI_PP_TUPLE_EXPAND is broken");

///////////////// MINI_PP_TUPLE_IS_EMPTY /////////////////
static_assert(MINI_PP_TUPLE_IS_EMPTY(()) == 1, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_TUPLE_IS_EMPTY((a)) == 0, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_TUPLE_IS_EMPTY((a, b)) == 0, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_TUPLE_IS_EMPTY((A)) == 0, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_TUPLE_IS_EMPTY((A_B)) == 0, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_TUPLE_IS_EMPTY((A_CALL())) == 0, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_TUPLE_IS_EMPTY((A_B_CALL())) == 0, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_IS_EMPTY(())) == 41, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_IS_EMPTY((a))) == 40, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_IS_EMPTY((a, b))) == 40, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_IS_EMPTY((A))) == 40, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_IS_EMPTY((A_B))) == 40, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_IS_EMPTY((A_CALL()))) == 40, "MINI_PP_TUPLE_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_IS_EMPTY((A_B_CALL()))) == 40, "MINI_PP_TUPLE_IS_EMPTY is broken");

///////////////// MINI_PP_TUPLE_SIZE /////////////////
static_assert(MINI_PP_TUPLE_SIZE(()) == 0, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_TUPLE_SIZE((a)) == 1, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_TUPLE_SIZE((a, b)) == 2, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_TUPLE_SIZE((A)) == 1, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_TUPLE_SIZE((A_B)) == 2, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_TUPLE_SIZE((A_CALL())) == 1, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_TUPLE_SIZE((A_B_CALL())) == 2, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_SIZE(())) == 40, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_SIZE((a))) == 41, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_SIZE((a, b))) == 42, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_SIZE((A))) == 41, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_SIZE((A_B))) == 42, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_SIZE((A_CALL()))) == 41, "MINI_PP_TUPLE_SIZE is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_SIZE((A_B_CALL()))) == 42, "MINI_PP_TUPLE_SIZE is broken");

///////////////// MINI_PP_TUPLE_PUSH_FRONT /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_FRONT((), 1)), "(1)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_FRONT((1), 2)), "(2, 1)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_FRONT((1, 2, 3, 4), 5)), "(5, 1, 2, 3, 4)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_FRONT(MINI_PP_TUPLE_PUSH_FRONT(MINI_PP_TUPLE_PUSH_FRONT((1), 2), 3), 4)), "(4, 3, 2, 1)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_FRONT((A_B), A)), "(a, a, b)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_FRONT((A_B_CALL()), A_CALL())), "(a, a, b)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_FRONT((), 1))), "4dummy (1)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_FRONT((1), 2))), "4dummy (2, 1)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_FRONT((1, 2, 3, 4), 5))), "4dummy (5, 1, 2, 3, 4)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_FRONT(MINI_PP_TUPLE_PUSH_FRONT(MINI_PP_TUPLE_PUSH_FRONT((1), 2), 3), 4))), "4dummy (4, 3, 2, 1)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_FRONT((A_B), A))), "4dummy (a, a, b)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_FRONT((A_B_CALL()), A_CALL()))), "4dummy (a, a, b)"), "MINI_PP_TUPLE_PUSH_FRONT is broken");

///////////////// MINI_PP_TUPLE_PUSH_BACK /////////////////
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_BACK((), 1)), "(1)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_BACK((1), 2)), "(1, 2)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_BACK((1, 2, 3, 4), 5)), "(1, 2, 3, 4, 5)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_BACK(MINI_PP_TUPLE_PUSH_BACK(MINI_PP_TUPLE_PUSH_BACK((1), 2), 3), 4)), "(1, 2, 3, 4)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_BACK((A_B), A)), "(a, b, a)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_TUPLE_PUSH_BACK((A_B_CALL()), A_CALL())), "(a, b, a)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_BACK((), 1))), "4dummy (1)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_BACK((1), 2))), "4dummy (1, 2)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_BACK((1, 2, 3, 4), 5))), "4dummy (1, 2, 3, 4, 5)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_BACK(MINI_PP_TUPLE_PUSH_BACK(MINI_PP_TUPLE_PUSH_BACK((1), 2), 3), 4))), "4dummy (1, 2, 3, 4)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_BACK((A_B), A))), "4dummy (a, b, a)"), "MINI_PP_TUPLE_PUSH_BACK is broken");
static_assert(stringsEqual(MINI_PP_TO_TEXT(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_PUSH_BACK((A_B_CALL()), A_CALL()))), "4dummy (a, b, a)"), "MINI_PP_TUPLE_PUSH_BACK is broken");

///////////////// MINI_PP_TUPLE_POP_FRONT /////////////////
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_POP_FRONT((1)))), "()"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_POP_FRONT((1, 2)))), "(2)"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_POP_FRONT((1, 2, 3, 4)))), "(2, 3, 4)"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_POP_FRONT(MINI_PP_TUPLE_POP_FRONT(MINI_PP_TUPLE_POP_FRONT((1, 2, 3)))))), "()"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_POP_FRONT((A_B)))), "(b)"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_POP_FRONT((A_B_CALL())))), "(b)"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_POP_FRONT((1))))), "4dummy ()"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_POP_FRONT((1, 2))))), "4dummy (2)"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_POP_FRONT((1, 2, 3, 4))))), "4dummy (2, 3, 4)"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_POP_FRONT(MINI_PP_TUPLE_POP_FRONT(MINI_PP_TUPLE_POP_FRONT((1, 2, 3))))))), "4dummy ()"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_POP_FRONT((A_B))))), "4dummy (b)"), "MINI_PP_TUPLE_POP_FRONT is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, dummy MINI_PP_TUPLE_POP_FRONT((A_B_CALL()))))), "4dummy (b)"), "MINI_PP_TUPLE_POP_FRONT is broken");

///////////////// MINI_PP_TUPLE_GET_ELEM_0 /////////////////
static_assert(MINI_PP_TUPLE_GET_ELEM_0((1, 2, 3, 4)) == 1, "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(MINI_PP_TUPLE_GET_ELEM_0((1)) == 1, "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_GET_ELEM_0((A)))), "a"), "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_GET_ELEM_0((A_B)))), "a"), "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_GET_ELEM_0((A_CALL())))), "a"), "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_GET_ELEM_0((A_B_CALL())))), "a"), "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_0((1, 2, 3, 4))) == 41, "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_0((1))) == 41, "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_0((A))))), "4a"), "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_0((A_B))))), "4a"), "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_0((A_CALL()))))), "4a"), "MINI_PP_TUPLE_GET_ELEM_0 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_0((A_B_CALL()))))), "4a"), "MINI_PP_TUPLE_GET_ELEM_0 is broken");

///////////////// MINI_PP_TUPLE_GET_ELEM_1 /////////////////
static_assert(MINI_PP_TUPLE_GET_ELEM_1((1, 2, 3, 4)) == 2, "MINI_PP_TUPLE_GET_ELEM_1 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_GET_ELEM_1((A_B)))), "b"), "MINI_PP_TUPLE_GET_ELEM_1 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_TUPLE_GET_ELEM_1((A_B_CALL())))), "b"), "MINI_PP_TUPLE_GET_ELEM_1 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_1((1, 2, 3, 4))) == 42, "MINI_PP_TUPLE_GET_ELEM_1 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_1((A_B))))), "4b"), "MINI_PP_TUPLE_GET_ELEM_1 is broken");
static_assert(stringsEqual(MINI_PP_EXPAND(MINI_PP_DEFER(MINI_PP_TO_TEXT)(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_1((A_B_CALL()))))), "4b"), "MINI_PP_TUPLE_GET_ELEM_1 is broken");

///////////////// MINI_PP_TUPLE_GET_ELEM_2 /////////////////
static_assert(MINI_PP_TUPLE_GET_ELEM_2((1, 2, 3, 4)) == 3, "MINI_PP_TUPLE_GET_ELEM_2 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_2((1, 2, 3, 4))) == 43, "MINI_PP_TUPLE_GET_ELEM_2 is broken");

///////////////// MINI_PP_TUPLE_GET_ELEM_3 /////////////////
static_assert(MINI_PP_TUPLE_GET_ELEM_3((1, 2, 3, 4)) == 4, "MINI_PP_TUPLE_GET_ELEM_3 is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_TUPLE_GET_ELEM_3((1, 2, 3, 4))) == 44, "MINI_PP_TUPLE_GET_ELEM_3 is broken");
