add_executable(${PROJECT_NAME}_Tests)
target_link_libraries(${PROJECT_NAME}_Tests PRIVATE ${PROJECT_NAME}::${PROJECT_NAME})

target_sources(${PROJECT_NAME}_Tests PRIVATE
    Base.cpp
    Boolean.cpp
    main.cpp
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
