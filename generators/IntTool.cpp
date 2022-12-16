#include <string>

#include <cassert>
#include <cstdio>

std::string shortArgName(int argIndex)
{
    assert(argIndex >= 0);

    static constexpr int symbolCountFirst = 1 + 'z' - 'a' + 1 + 'Z' - 'A' + 1;
    static constexpr int symbolCount = 1 + 'z' - 'a' + 1 + 'Z' - 'A' + 1 + '9' - '0' + 1;

    auto symbol = [](int symbolIndex, bool isFirst)
    {
        assert(symbolIndex >= 0);
        assert(!isFirst || symbolIndex < symbolCountFirst);
        assert(isFirst || symbolIndex < symbolCount);

        if (symbolIndex == 0)
            return '_';
        symbolIndex -= 1;

        if (symbolIndex < 'z' - 'a' + 1)
            return char(symbolIndex + 'a');
        symbolIndex -= ('z' - 'a' + 1);

        if (symbolIndex < 'Z' - 'A' + 1)
            return char(symbolIndex + 'A');
        symbolIndex -= ('Z' - 'A' + 1);

        return char(symbolIndex + '0');
    };

    std::string argName;

    if (argIndex < symbolCountFirst)
    {
        argName = symbol(argIndex, /*isFirst*/ true);
        return argName;
    }
    
    argIndex -= symbolCountFirst;

    const int firstSymbolIndex =  1 + argIndex / symbolCount;
    assert(firstSymbolIndex > 0);

    if (firstSymbolIndex > 1)
        argIndex -= (firstSymbolIndex - 1) * symbolCount;

    argName += symbol(firstSymbolIndex - 1, /*isFirst*/ true);

    while (argIndex >= symbolCount)
    {
        const int symbolIndex = argIndex / symbolCount;
        assert(symbolIndex > 0);

        argIndex -= symbolIndex * symbolCount;
        argName += symbol(symbolIndex - 1, /*isFirst*/ false);
    }

    argName += symbol(argIndex, /*isFirst*/ false);

    return argName;
}

int main()
{

    static constexpr int miniPpMaxNbArgs = 125;
    for (int i = 0; i <= miniPpMaxNbArgs; ++i)
    {
        std::printf("#define MINI_PP_PRIVATE_FOREACH%d(%s,%s", i, shortArgName(0).c_str(), shortArgName(1).c_str());
        
        for (int j = 0; j < i; ++j)
            std::printf(",%s", shortArgName(j + 2).c_str());

        std::printf(")");

        for (int j = 0; j < i; ++j)
        {
            if (j != 0)
                std::printf(" ");

            std::printf("%s(%s,%s)", shortArgName(0).c_str(), shortArgName(1).c_str(), shortArgName(j + 2).c_str());
        }

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
