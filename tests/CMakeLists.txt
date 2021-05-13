cmake_minimum_required(VERSION 3.0)

add_executable(queue_tests ${CMAKE_CURRENT_SOURCE_DIR}/queue_tests.c)
target_link_libraries(queue_tests LINK_PUBLIC queue)

add_test(queue_tests queue_tests)