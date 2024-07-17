cmake_minimum_required(VERSION 3.10)
project(ALIGN VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/geometry)

# Source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add subdirectories (if any, for now we don't need these lines)
# add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib)

# For macOS, link against Cocoa and CoreVideo frameworks (if necessary)
if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa -framework CoreVideo")
endif()
