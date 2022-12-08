#ifndef MINI_PP_VERSION // Allows this file to be included from anywhere
#include "MiniPP/MiniPP.hpp"
#endif

#define ARGS_WITHOUT_COMMA a
#define ARGS_WITH_COMMA a, b
#define ARGS_WITHOUT_COMMA_CALL() a
#define ARGS_WITH_COMMA_CALL() a, b
#define ARGS_EMPTY
#define ARGS_EMPTY_CALL()
#define ARGS_EMPTY_CALL_WITH_COMMA(a, b)
#define ARGS_NOT_EMPTY_CALL_WITH_COMMA(a, b) a
#define PARENS_PROXY MINI_PP_PARENS
#define PARENS_PROXY_WITH_CALL() MINI_PP_PARENS

///////////////// MINI_PP_HAS_DIRECT_COMMA /////////////////
static_assert(MINI_PP_HAS_DIRECT_COMMA() == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(/*Comment*/) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(/*Comment with, comma*/) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(a) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(a, b) == 1, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(a, b, c, d, e, f, g, h) == 1, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA((a, b)) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA((a, b, c)) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA((a, b), c) == 1, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA((a, b, c), d) == 1, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(ARGS_WITHOUT_COMMA) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(ARGS_WITH_COMMA) == 1, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(ARGS_WITHOUT_COMMA_CALL()) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(ARGS_WITH_COMMA_CALL()) == 1, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(ARGS_WITH_COMMA_CALL) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(ARGS_EMPTY_CALL_WITH_COMMA) == 0, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_HAS_DIRECT_COMMA(,) == 1, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_HAS_DIRECT_COMMA()) == 40, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_HAS_DIRECT_COMMA(a)) == 40, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_HAS_DIRECT_COMMA(a, b)) == 41, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_HAS_DIRECT_COMMA(ARGS_WITH_COMMA)) == 41, "MINI_PP_HAS_DIRECT_COMMA is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_HAS_DIRECT_COMMA(,)) == 41, "MINI_PP_HAS_DIRECT_COMMA is broken");

///////////////// MINI_PP_IS_EMPTY /////////////////
#define ADVANCED_TEST_IS_EMPTY(a, b, c, d, e) MINI_PP_IS_EMPTY(c)

static_assert(MINI_PP_IS_EMPTY() == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(/*Comment*/) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(/*Comment with, comma*/) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(a) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(a, b) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(()) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY((a)) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY((a, b)) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , c, , e) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , (), , e) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , , , e) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , /*Comment*/, , e) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , /*Comment with, comma*/, , e) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(ARGS_EMPTY) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(ARGS_EMPTY_CALL()) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(ARGS_EMPTY_CALL_WITH_COMMA(a, b)) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , ARGS_EMPTY, , e) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , ARGS_EMPTY_CALL(), , e) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , ARGS_EMPTY_CALL_WITH_COMMA(a, b), , e) == 1, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(ARGS_WITHOUT_COMMA) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(ARGS_WITHOUT_COMMA_CALL()) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(ARGS_NOT_EMPTY_CALL_WITH_COMMA(a, b)) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , ARGS_WITHOUT_COMMA, , e) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , ARGS_WITHOUT_COMMA_CALL(), , e) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(ADVANCED_TEST_IS_EMPTY(a, , ARGS_NOT_EMPTY_CALL_WITH_COMMA(a, b), , e) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(ARGS_WITH_COMMA_CALL) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_IS_EMPTY(ARGS_EMPTY_CALL_WITH_COMMA) == 0, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EMPTY()) == 41, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EMPTY(a)) == 40, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EMPTY(ARGS_EMPTY)) == 41, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EMPTY(ARGS_WITH_COMMA_CALL)) == 40, "MINI_PP_IS_EMPTY is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_EMPTY(ARGS_WITH_COMMA_CALL())) == 40, "MINI_PP_IS_EMPTY is broken");

///////////////// MINI_PP_NB_ARGS /////////////////
static_assert(MINI_PP_NB_ARGS() == 0, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(/*Comment*/) == 0, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(/*Comment with, comma*/) == 0, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(a) == 1, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(a, b) == 2, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(a, b, c) == 3, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(a, b, c, d) == 4, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(a, b, c, d, e, f, g, h) == 8, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_EMPTY) == 0, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_EMPTY_CALL()) == 0, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_EMPTY_CALL_WITH_COMMA(a, b)) == 0, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_NOT_EMPTY_CALL_WITH_COMMA(a, b)) == 1, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_WITHOUT_COMMA) == 1, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_WITH_COMMA) == 2, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_WITHOUT_COMMA_CALL()) == 1, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_WITH_COMMA_CALL()) == 2, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_WITH_COMMA_CALL) == 1, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_NB_ARGS(ARGS_EMPTY_CALL_WITH_COMMA) == 1, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_NB_ARGS()) == 40, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_NB_ARGS(a)) == 41, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_NB_ARGS(ARGS_EMPTY)) == 40, "MINI_PP_NB_ARGS is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_NB_ARGS(ARGS_WITH_COMMA_CALL())) == 42, "MINI_PP_NB_ARGS is broken");

///////////////// MINI_PP_IS_PAREN /////////////////
static_assert(MINI_PP_IS_PAREN(()) == 1, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN(MINI_PP_PARENS) == 1, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN(PARENS_PROXY) == 1, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN(PARENS_PROXY_WITH_CALL()) == 1, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN((/*Comment*/)) == 1, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN((/*Comment with, comma*/)) == 1, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN((a)) == 1, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN((a, b)) == 1, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN(a) == 0, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_IS_PAREN(FOO()) == 0, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_PAREN(())) == 41, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_PAREN(MINI_PP_PARENS)) == 41, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_PAREN(PARENS_PROXY)) == 41, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_PAREN((a))) == 41, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_PAREN(ARGS_EMPTY)) == 40, "MINI_PP_IS_PAREN is broken");
static_assert(MINI_PP_CAT(4, MINI_PP_IS_PAREN(ARGS_WITHOUT_COMMA_CALL())) == 40, "MINI_PP_IS_PAREN is broken");
