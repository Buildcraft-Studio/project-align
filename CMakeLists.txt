# CMakeLists.txt
cmake_minimum_required(VERSION 3.26)

# Project name
project(My2DEngine VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(src)

# Include directories
include_directories(include)

# # External libraries
# set(FURNACE_PATH "./3rdPartySoftware/depend/furnace")
# include_directories(${FURNACE_PATH}/include)
# link_directories(${FURNACE_PATH}/lib)

# Collect all source files recursively for the library
file(GLOB_RECURSE ENGINE_SOURCES
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
)

# Create a static library for the engine
add_library(My2DEngine STATIC ${ENGINE_SOURCES})

# Include directories for the engine
target_include_directories(My2DEngine PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

# Link external libraries if needed
# Uncomment and set FURNACE_PATH correctly to link the external library
# target_link_libraries(My2DEngine PRIVATE ${FURNACE_PATH}/lib/libfurnace.a)

# Add an executable for the project
# Replace "main.cpp" with the path to your executable's main source file
add_executable(My2DGame ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Link the My2DEngine library to the executable
target_link_libraries(My2DGame PRIVATE My2DEngine)
