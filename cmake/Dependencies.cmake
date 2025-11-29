# Dependencies management using CPM
#
# CPM (CMake Package Manager) documentation:
# https://github.com/cpm-cmake/CPM.cmake

# CLI11 - Command line parser for C++11
# https://github.com/CLIUtils/CLI11
CPMAddPackage(
    NAME CLI11
    GITHUB_REPOSITORY CLIUtils/CLI11
    VERSION 2.4.2
    OPTIONS
        "CLI11_BUILD_TESTS OFF"
        "CLI11_BUILD_EXAMPLES OFF"
)
