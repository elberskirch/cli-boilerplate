# Core Headers

This directory is for public header files (.hpp) that define the interface for core functionality.

## Usage

When adding new functionality:

1. Create header files here (e.g., `myfeature.hpp`)
2. Create corresponding implementation files in `src/core/` (e.g., `myfeature.cpp`)
3. Update `src/core/CMakeLists.txt` to build the core library
4. Update `src/CMakeLists.txt` to link against the core library

## Example Structure

```
include/core/
├── calculator.hpp
└── utilities.hpp

src/core/
├── calculator.cpp
├── utilities.cpp
└── CMakeLists.txt
```
