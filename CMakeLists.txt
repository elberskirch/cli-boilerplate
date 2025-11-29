cmake_minimum_required(VERSION 3.14...3.28)

project(
    cli-boilerplate
    VERSION 0.1.0
    DESCRIPTION "A CLI application boilerplate with CLI11"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for IDE integration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include CPM for dependency management
include(cmake/CPM.cmake)

# Include dependencies
include(cmake/Dependencies.cmake)

# Include clang-format integration
include(cmake/ClangFormat.cmake)

# Add source directory
add_subdirectory(src)
