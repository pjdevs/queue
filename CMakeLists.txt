cmake_minimum_required(VERSION 3.0)

project(queue)
message(STATUS "Build configuration is : ${CMAKE_BUILD_TYPE}")

enable_testing()

set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g")
set(CMAKE_C_FLAGS_COVERAGE "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_PROFILING "${CMAKE_C_FLAGS} -pg")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)
add_subdirectory(coverage)
add_subdirectory(profiling)
add_subdirectory(examples)

install(TARGETS queue DESTINATION lib)
install(TARGETS queue_static DESTINATION lib)
install(DIRECTORY include/queue/ DESTINATION include/queue)
install(DIRECTORY ${PROJECT_BINARY_DIR}/docs/html DESTINATION share/queue/doc/)
install(TARGETS example_queue DESTINATION share/queue/examples)