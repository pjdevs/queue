cmake_minimum_required(VERSION 3.0)

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")

    add_custom_target(coverage lcov -c -d .. -o coverage.info
        COMMAND genhtml coverage.info
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

endif()