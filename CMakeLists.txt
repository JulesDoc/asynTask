cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

project(myProject C CXX)
find_package(Threads REQUIRED)

enable_testing()

add_subdirectory(main)
add_subdirectory(unit_tests)
add_subdirectory(libtask)
add_subdirectory(example)

