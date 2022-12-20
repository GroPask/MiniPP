cmake_minimum_required(VERSION 3.16.0...3.25.0)

project(MiniPP VERSION 0.0.1 LANGUAGES CXX)
include(GNUInstallDirs)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(MINI_PP_TOP_LEVEL_PROJECT TRUE)
endif ()

option(MINI_PP_BUILD_TESTS "Build tests programs" ${MINI_PP_TOP_LEVEL_PROJECT})
option(MINI_PP_INSTALL "Generate the install target" ${MINI_PP_TOP_LEVEL_PROJECT})
option(MINI_PP_MAIN_GENERATOR "Generate the main generator target" ${MINI_PP_TOP_LEVEL_PROJECT})

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
    dp_target_generate_install(MiniPP
        CONFIG_IN cmake/MiniPPConfig.cmake.in
        INSTALL_INCLUDE_FOLDER
    )
endif ()

if (MINI_PP_MAIN_GENERATOR)
    dp_target_find_source(miniPPHppAbsolutePath ${PROJECT_NAME} "MiniPP.hpp")
    dp_target_find_source(mainGeneratorScriptAbsolutePath ${PROJECT_NAME} "MiniPPGenerateMain.cmake")

    add_custom_target(${PROJECT_NAME}_MainGenerator
        COMMAND ${CMAKE_COMMAND} -Ddpcmake_SOURCE_DIR=${dpcmake_SOURCE_DIR} -DminiPPMainGeneratorInOutFile=${miniPPHppAbsolutePath} -P ${mainGeneratorScriptAbsolutePath}
    )
endif ()
