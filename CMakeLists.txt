cmake_minimum_required(VERSION 3.1)

project(myProject)

enable_testing()

add_subdirectory(main)
add_subdirectory(unit_test)
add_subdirectory(libtask)
add_subdirectory(example)

