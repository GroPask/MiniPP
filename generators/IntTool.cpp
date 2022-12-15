#include <cstdio>

int main()
{
    static constexpr int miniPpMaxInt = 1024;

    for (int i = 0; i <= miniPpMaxInt; ++i)
        std::printf("#define MINI_PP_PRIVATE_INT_TOOL_BASE_%d_%d\n", i, i);

    std::printf("\n");

    for (int i = 0; i <= miniPpMaxInt; ++i)
        std::printf("#define MINI_PP_PRIVATE_INT_TOOL_%d(repeatFunc, params) repeatFunc(params, %d, %d, %d)(repeatFunc, params)\n", i, i, i - 1, i + 1);
}
