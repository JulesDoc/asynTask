set(libtask_SRCS
    task.h
    task.cpp
)

# Declare the library
add_library(libtask STATIC
    ${libtask_SRCS}
)

target_link_libraries(libtask
)

# Specify here the include directories exported
# by this library
target_include_directories(libtask PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

