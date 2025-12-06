# Core library (header-only)

# Create an INTERFACE library for header-only files
add_library(core INTERFACE)

# Include directories for the INTERFACE library
target_include_directories(core
    INTERFACE
        ${CMAKE_SOURCE_DIR}/include
)

# If you add .cpp files later, change to:
# add_library(core
#     2025-01.cpp
#     util.cpp
#     # Add more source files here
# )
# target_include_directories(core
#     PUBLIC
#         ${CMAKE_SOURCE_DIR}/include
# )
# target_link_libraries(core
#     PUBLIC
#         # Add public dependencies here
#     PRIVATE
#         # Add private dependencies here
# )