cmake_minimum_required(VERSION 3.16)
project(ALIGN)

# Set C++ version
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Specify output directories for ALIGN project
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(include)

# Option to skip building Furnace
option(SKIP_BUILD_FURNACE "Skip building Furnace" OFF)

# Add a custom target to build Furnace only if the skip option is not set
if(NOT SKIP_BUILD_FURNACE)
    add_custom_target(BuildFurnace ALL
        COMMAND bash ${CMAKE_SOURCE_DIR}/3rdPartySoftware/Furnace.sh
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/3rdPartySoftware/furnace
        COMMENT "Building Furnace..."
        VERBATIM
    )
endif()

# Subdirectories for ALIGN project
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib)
