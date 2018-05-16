file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testtask ${SRCS})

TARGET_LINK_LIBRARIES(testtask
    libtask
    libgtest
    libgmock
)

add_test(NAME testtask
         COMMAND testtask)
