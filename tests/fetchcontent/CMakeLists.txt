cmake_minimum_required(VERSION 3.21.0...3.25.0)

project(MiniPP_FetchContentTest VERSION 0.0.1 LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(FetchContent)

    if (DEFINED MINI_PP_LOCAL_SRC)
        FetchContent_Declare(MiniPP SOURCE_DIR ${MINI_PP_LOCAL_SRC})
    else ()
        FetchContent_Declare(MiniPP URL https://github.com/GroPask/MiniPP/archive/refs/heads/main.zip)
    endif ()
        
    FetchContent_MakeAvailable(MiniPP)
endif ()

add_executable(${PROJECT_NAME} FetchContentTest.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE MiniPP::MiniPP)
