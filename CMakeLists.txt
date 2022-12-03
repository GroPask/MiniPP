cmake_minimum_required(VERSION 3.21.0...3.25.0)

project(MiniPP VERSION 0.0.1 LANGUAGES CXX)

option(MINI_PP_BUILD_TESTS "Build tests programs" ${PROJECT_IS_TOP_LEVEL})
option(MINI_PP_INSTALL "Generate the install target" ${PROJECT_IS_TOP_LEVEL})

include(FetchContent)
FetchContent_Declare(dpCMake URL https://github.com/GroPask/dpCMake/archive/refs/heads/main.zip)
FetchContent_MakeAvailable(dpCMake)
include(${dpcmake_SOURCE_DIR}/dpCMake.cmake)

dp_configure_global(
    USE_FOLDERS
    DEFAULT_CONFIGURATIONS Debug Release
)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_subdirectory(cmake)
add_subdirectory(include/MiniPP)

dp_configure_target(${PROJECT_NAME}
    AUTO_SOURCE_GROUP
)

if (MINI_PP_BUILD_TESTS)
    add_subdirectory(tests)
endif ()

if (MINI_PP_INSTALL)
    dp_generate_install_for_target(MiniPP)
endif ()
