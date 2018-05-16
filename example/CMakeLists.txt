set(example_SRCS
    tasksleep.h
    tasksleep.cpp
    taskrandom.h
    taskrandom.cpp
    taskloop.h
    taskloop.cpp
)
# Declare the library
add_library(example STATIC
    ${example_SRCS}
)



target_link_libraries(example
	libtask
)


# Specify here the include directories exported
# by this library
target_include_directories(example PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

