cmake_minimum_required( VERSION 3.16)
project(ALIGN)

# Set C++ version
set(CMAKE_CXX_STANDARD 23)

# Specify output directories for ALIGN project
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(include)


# Subdirectories for ALIGN project
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib)

# # Optional: External libraries (add 3rd party libraries like SDL, OpenGL, etc.)
# add_subdirectory(3rdPartySoftware)
