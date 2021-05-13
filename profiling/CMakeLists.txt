cmake_minimum_required(VERSION 3.0)

if (CMAKE_BUILD_TYPE STREQUAL "Profiling")

    add_custom_target(profiling ./../examples/example_queue_profiling
        COMMAND gprof ../examples/example_queue_profiling gmon.out
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

endif()