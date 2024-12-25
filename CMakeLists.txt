cmake_minimum_required(VERSION 3.26)

# Project name
project(My2DEngine VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Collect all source files recursively for the library
file(GLOB_RECURSE ENGINE_SOURCES
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
)

# Platform-specific setup
if(WIN32)
    # Windows-specific Lua configuration
    set(LUA_INCLUDE_DIR "C:/lua/include" CACHE PATH "Lua include directory")
    set(LUA_LIBRARIES "C:/lua/lib/lua54.lib" CACHE FILEPATH "Lua library file")
    include_directories(${LUA_INCLUDE_DIR})
    link_directories("C:/lua/lib")
    set(PLATFORM_LIBS "")  # No extra platform-specific libraries for Windows
elseif(UNIX)
    # Linux-specific Lua configuration
    find_package(Lua REQUIRED)
    include_directories(${LUA_INCLUDE_DIR})
    link_directories(${LUA_LIBRARY_DIR})
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
