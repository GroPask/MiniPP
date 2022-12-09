add_executable(${PROJECT_NAME}_Tests)
target_include_directories(${PROJECT_NAME}_Tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}_Tests PRIVATE ${PROJECT_NAME}::${PROJECT_NAME})

target_sources(${PROJECT_NAME}_Tests PRIVATE
    ArgsUtility.cpp
    Base.cpp
    Boolean.cpp
    CallWithArgs.cpp
    ComputeSwitchWithOrWithoutVaArgs.cpp
    ForEach.cpp
    IsEqual.cpp
    main.cpp
    SwitchWithOrWithoutVaArgs.cpp
    TestUtility.hpp
    Tuple.cpp
    UnrollUtility.cpp
)

dp_configure_target(${PROJECT_NAME}_Tests
    DP_WARNINGS
    AUTO_SOURCE_GROUP
)

add_subdirectory(fetchcontent)

# Configure FetchContentTest here to keep its cmake compatible to independent use
dp_configure_target(${PROJECT_NAME}_FetchContentTest
    DP_WARNINGS
    AUTO_SOURCE_GROUP
)

add_subdirectory(install)

# Configure InstallTest here to keep its cmake compatible to independent use
dp_configure_target(${PROJECT_NAME}_InstallTest
    DP_WARNINGS
    AUTO_SOURCE_GROUP
)
