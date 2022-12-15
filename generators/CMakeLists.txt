function(mini_pp_add_generator_executable name)
    add_executable(${PROJECT_NAME}_${name}_Generator ${name}.cpp)

    dp_configure_target(${PROJECT_NAME}_${name}_Generator
        DP_WARNINGS
        AUTO_SOURCE_GROUP
    )
endfunction()

mini_pp_add_generator_executable(IntTool)
