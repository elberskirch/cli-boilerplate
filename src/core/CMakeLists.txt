# Core library

add_library(core
    2024-01.cpp
    # Add more source files here
)

target_include_directories(core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(core
    PUBLIC
        # Add public dependencies here
    PRIVATE
        # Add private dependencies here
)