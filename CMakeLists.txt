cmake_minimum_required(VERSION 3.10)
project(ALIGN VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib/glad/include)    # glad.h directory
include_directories(${PROJECT_SOURCE_DIR}/lib/imgui)           # ImGui directory
include_directories(${PROJECT_SOURCE_DIR}/lib/imgui/backends)  # ImGui backends directory

# Set OpenGL preference to GLVND (modern OpenGL)
set(OpenGL_GL_PREFERENCE "GLVND")

# Link against glad
add_library(glad STATIC ${PROJECT_SOURCE_DIR}/lib/glad/src/glad.c)

# Include directories for glad headers
target_include_directories(glad PUBLIC ${PROJECT_SOURCE_DIR}/lib/glad/include)

# Source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries (imgui, OpenGL, GLFW, glad)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/imgui)  # ImGui library
target_link_libraries(${PROJECT_NAME} imgui)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

find_package(glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

# Link against glad library
target_link_libraries(${PROJECT_NAME} glad)

# Ensure GLAD and GLFW are linked properly
target_link_libraries(${PROJECT_NAME} dl)  # For Linux, link against dl

# For macOS, link against Cocoa and CoreVideo frameworks
if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa -framework CoreVideo")
endif()
