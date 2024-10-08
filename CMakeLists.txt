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

# Add a custom target to build Furnace
add_custom_target(BuildFurnace ALL
    COMMAND bash ${CMAKE_SOURCE_DIR}/3rdPartySoftware/Furnace.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/3rdPartySoftware/furnace
    COMMENT "Building Furnace..."
    VERBATIM  # Use VERBATIM to avoid issues with command line parsing
)

# Subdirectories for ALIGN project
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib)

# Optional: External libraries (add 3rd party libraries like SDL, OpenGL, etc.)
# add_subdirectory(3rdPartySoftware)

# Optionally, you can find and link external libraries
# find_package(OpenGL REQUIRED)
# target_link_libraries(ALIGN PRIVATE OpenGL::GL)
