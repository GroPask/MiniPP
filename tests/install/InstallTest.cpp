#include "MiniPP/MiniPP.hpp"

#include <cstdlib>

int main()
{
    if (MINI_PP_CAT(4, 2) == 42)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
