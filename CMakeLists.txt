cmake_minimum_required(VERSION 3.26)

# Project name
project(My2DEngine VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all source files recursively for the library
file(GLOB_RECURSE ENGINE_SOURCES
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
)

# Platform-specific setup
if(WIN32)
    # Windows-specific configuration for Lua with MinGW
    set(LUA_INCLUDE_DIR "C:/lua/include" CACHE PATH "Lua include directory")
    set(LUA_LIBRARIES "C:/lua/lib/liblua.a" CACHE FILEPATH "Lua static library file")
    
    include_directories(${LUA_INCLUDE_DIR})
    link_directories("C:/lua/lib")
    
    # No additional platform-specific libraries for Windows
    set(PLATFORM_LIBS "") 

elseif(UNIX)
    # Linux/Unix-specific configuration for Lua
    find_package(Lua REQUIRED)
    
    include_directories(${LUA_INCLUDE_DIR})
    link_directories(${LUA_LIBRARY_DIR})
    
    # Add required platform-specific libraries
    set(PLATFORM_LIBS dl)  # Dynamic linker library required on Linux
endif()

# Create a static library for the engine
add_library(My2DEngine STATIC ${ENGINE_SOURCES})

# Include directories for the engine
target_include_directories(My2DEngine PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

# Add an executable for the project
add_executable(My2DGame ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Link libraries to the executable
target_link_libraries(My2DGame PRIVATE My2DEngine ${LUA_LIBRARIES} ${PLATFORM_LIBS})
