cmake_minimum_required(VERSION 3.0)

add_executable(example_queue ${CMAKE_CURRENT_SOURCE_DIR}/example_queue.c)
target_link_libraries(example_queue LINK_PUBLIC queue_static)
add_executable(example_queue_profiling ${CMAKE_CURRENT_SOURCE_DIR}/example_queue_profiling.c)
target_link_libraries(example_queue_profiling LINK_PUBLIC queue_static)
