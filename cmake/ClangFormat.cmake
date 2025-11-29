# clang-format integration for CMake
#
# Provides targets for formatting C++ source code using clang-format

# Find clang-format executable
find_program(CLANG_FORMAT_EXE
    NAMES clang-format
    DOC "Path to clang-format executable"
)

if(CLANG_FORMAT_EXE)
    message(STATUS "Found clang-format: ${CLANG_FORMAT_EXE}")

    # Get all source files
    file(GLOB_RECURSE ALL_SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/src/*.hpp
        ${CMAKE_SOURCE_DIR}/include/*.hpp
    )

    # Target to check formatting (does not modify files)
    add_custom_target(format-check
        COMMAND ${CLANG_FORMAT_EXE}
            --dry-run
            --Werror
            -style=file
            ${ALL_SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Checking code formatting with clang-format"
        VERBATIM
    )

    # Target to automatically format all files
    add_custom_target(format
        COMMAND ${CLANG_FORMAT_EXE}
            -i
            -style=file
            ${ALL_SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Formatting code with clang-format"
        VERBATIM
    )

    message(STATUS "Added clang-format targets: 'format' and 'format-check'")
else()
    message(STATUS "clang-format not found. Format targets will not be available.")
endif()
