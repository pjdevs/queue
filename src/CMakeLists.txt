cmake_minimum_required(VERSION 3.0)

add_library(queue SHARED ${CMAKE_CURRENT_SOURCE_DIR}/queue.c)
add_library(queue_static STATIC ${CMAKE_CURRENT_SOURCE_DIR}/queue.c)
set_target_properties(queue_static PROPERTIES OUTPUT_NAME queue)