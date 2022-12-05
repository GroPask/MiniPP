#ifndef MINI_PP_TEST_UTILITY_HPP
#define MINI_PP_TEST_UTILITY_HPP

constexpr bool stringsEqual(char const* a, char const* b)
{
    return (*a == *b && (*a == '\0' || stringsEqual(a + 1, b + 1)));
}

static_assert(stringsEqual("", ""), "stringsEqual is broken");
static_assert(stringsEqual("x", "x"), "stringsEqual is broken");
static_assert(stringsEqual("foo", "foo"), "stringsEqual is broken");
static_assert(!stringsEqual("foo", ""), "stringsEqual is broken");
static_assert(!stringsEqual("", "bar"), "stringsEqual is broken");
static_assert(!stringsEqual("foo", "bar"), "stringsEqual is broken");
static_assert(!stringsEqual("x", "bar"), "stringsEqual is broken");
static_assert(!stringsEqual("foo", "x"), "stringsEqual is broken");

#endif
