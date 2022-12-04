cmake_minimum_required(VERSION 3.21.0...3.25.0)

project(MiniPP_FetchContentTest VERSION 0.0.1 LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    if (DEFINED MINI_PP_WANTED_SHA)
        set(miniPPTag ${MINI_PP_WANTED_SHA})
    else ()
        set(miniPPTag main)
    endif ()

    include(FetchContent)
    FetchContent_Declare(MiniPP GIT_REPOSITORY https://github.com/GroPask/MiniPP.git GIT_TAG ${miniPPTag})
    FetchContent_MakeAvailable(MiniPP)
endif ()

add_executable(${PROJECT_NAME} FetchContentTest.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE MiniPP::MiniPP)
