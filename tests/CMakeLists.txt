# Tests configuration

# Create test executable
add_executable(tests
    test_2025-01.cpp
)

# Link against Catch2, core library
target_link_libraries(tests
    PRIVATE
        Catch2::Catch2WithMain
        core
)

# Include directories
target_include_directories(tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Discover tests for CTest
include(CTest)
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(tests)
