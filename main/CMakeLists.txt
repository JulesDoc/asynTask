set(Main_SRCS
    main.cpp
)

add_executable(myTaskApp
    ${Main_SRCS}
)

# Specify here the libraries this program depends on
target_link_libraries(myTaskApp 
    ${CMAKE_THREAD_LIBS_INIT}
    libtask
    example
)

install(TARGETS myTaskApp DESTINATION bin)

