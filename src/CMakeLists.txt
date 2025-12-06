# Main executable configuration

# Add core library subdirectory
add_subdirectory(core)

# Define the executable
add_executable(${PROJECT_NAME}
    main.cpp
)

# Link against CLI11 and core library
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        CLI11::CLI11
        core
)

# Include directories for project headers
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Compiler warnings
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
