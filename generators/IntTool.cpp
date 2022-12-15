#include <cstdio>

int main()
{
    static constexpr int miniPpMaxNbArgs = 125;
    for (int i = 0; i <= miniPpMaxNbArgs; ++i)
    {
        std::printf("#define MINI_PP_PRIVATE_FOREACH%d(f,p", i);
        
        for (int j = 1; j <= i; ++j)
            std::printf(",_%d", j);

        std::printf(")");

        for (int j = 1; j <= i; ++j)
            std::printf("f(p,_%d)", j);

        std::printf("\n");
    }

    std::printf("\n");

    static constexpr int miniPpMaxInt = 1024;

    for (int i = 0; i <= miniPpMaxInt; ++i)
        std::printf("#define MINI_PP_PRIVATE_INT_TOOL_BASE_%d_%d\n", i, i);

    std::printf("\n");

    for (int i = 0; i <= miniPpMaxInt; ++i)
    {
        if (i == 0)
            std::printf("#define MINI_PP_PRIVATE_INT_TOOL_%d(repeatFunc, params) repeatFunc(params, %d, NONE, %d)(repeatFunc, params)\n", i, i, i + 1);
        else if (i == miniPpMaxInt)
            std::printf("#define MINI_PP_PRIVATE_INT_TOOL_%d(repeatFunc, params) repeatFunc(params, %d, %d, NONE)(repeatFunc, params)\n", i, i, i - 1);
        else
            std::printf("#define MINI_PP_PRIVATE_INT_TOOL_%d(repeatFunc, params) repeatFunc(params, %d, %d, %d)(repeatFunc, params)\n", i, i, i - 1, i + 1);
    }
}
