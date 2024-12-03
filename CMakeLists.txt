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
