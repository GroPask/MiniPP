cmake_minimum_required(VERSION 3.21.0...3.25.0)

project(MiniPP_FetchContentTest VERSION 0.0.1 LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(miniPPUrl https://github.com/GroPask/MiniPP/archive/refs/heads/main.zip)
    if (DEFINED MINI_PP_WANTED_SHA)
        set(miniPPUrl https://github.com/GroPask/MiniPP/archive/${MINI_PP_WANTED_SHA}.zip)
    endif ()

    include(FetchContent)
    FetchContent_Declare(MiniPP URL ${miniPPUrl})
    FetchContent_MakeAvailable(MiniPP)
endif ()

add_executable(${PROJECT_NAME} FetchContentTest.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE MiniPP::MiniPP)
