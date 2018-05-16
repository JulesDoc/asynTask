set(example_SRCS
    tasksleep.h
    tasksleep.cpp
)

# Declare the library
add_library(example STATIC
    ${example_SRCS}
)

# Specify here the include directories exported
# by this library
target_include_directories(example PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

