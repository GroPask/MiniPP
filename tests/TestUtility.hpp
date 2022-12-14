#ifndef MINI_PP_TEST_UTILITY_HPP
#define MINI_PP_TEST_UTILITY_HPP

constexpr bool stringsEqual(char const* a, char const* b)
{
    // Avoid too much compile time recursion by checking 16 characters at once

    return (* a       == * b       && (* a       == '\0' ||
           (*(a + 1)  == *(b + 1)  && (*(a + 1)  == '\0' ||
           (*(a + 2)  == *(b + 2)  && (*(a + 2)  == '\0' ||
           (*(a + 3)  == *(b + 3)  && (*(a + 3)  == '\0' ||
           (*(a + 4)  == *(b + 4)  && (*(a + 4)  == '\0' ||
           (*(a + 5)  == *(b + 5)  && (*(a + 5)  == '\0' ||
           (*(a + 6)  == *(b + 6)  && (*(a + 6)  == '\0' ||
           (*(a + 7)  == *(b + 7)  && (*(a + 7)  == '\0' ||
           (*(a + 8)  == *(b + 8)  && (*(a + 8)  == '\0' ||
           (*(a + 9)  == *(b + 9)  && (*(a + 9)  == '\0' ||
           (*(a + 10) == *(b + 10) && (*(a + 10) == '\0' ||
           (*(a + 11) == *(b + 11) && (*(a + 11) == '\0' ||
           (*(a + 12) == *(b + 12) && (*(a + 12) == '\0' ||
           (*(a + 13) == *(b + 13) && (*(a + 13) == '\0' ||
           (*(a + 14) == *(b + 14) && (*(a + 14) == '\0' ||
           (*(a + 15) == *(b + 15) && (*(a + 15) == '\0' ||
           stringsEqual(a + 16, b + 16)))))))))))))))))))))))))))))))));
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
