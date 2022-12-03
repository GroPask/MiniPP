cmake_minimum_required(VERSION 3.21.0...3.25.0)

project(MiniPP_InstallTest VERSION 0.0.1 LANGUAGES CXX)

if (${PROJECT_IS_TOP_LEVEL})
    find_package(MiniPP 0.0.1 EXACT CONFIG REQUIRED)
endif ()

add_executable(${PROJECT_NAME} InstallTest.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE MiniPP::MiniPP)

dp_configure_target(${PROJECT_NAME}
    DP_WARNINGS
    AUTO_SOURCE_GROUP
)
