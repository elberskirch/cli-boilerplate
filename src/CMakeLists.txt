# Main executable configuration

# Define the executable
add_executable(${PROJECT_NAME}
    main.cpp
)

# Link against CLI11
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        CLI11::CLI11
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

# Future: Add core library when functionality is added
# add_subdirectory(core)
# target_link_libraries(${PROJECT_NAME} PRIVATE core)
