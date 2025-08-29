cmake_minimum_required(VERSION 3.26)

project(My2DEngine VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recursively collect all source and header files in src/
file(GLOB_RECURSE ENGINE_SOURCES
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
  ${CMAKE_SOURCE_DIR}/src/*.hpp
)

# Platform-specific setup
if(WIN32)
    set(LUA_INCLUDE_DIR "C:/lua/include" CACHE PATH "Lua include directory")
    set(LUA_LIBRARIES "C:/lua/lib/liblua.a" CACHE FILEPATH "Lua static library file")
    
    if(EXISTS ${LUA_INCLUDE_DIR} AND EXISTS ${LUA_LIBRARIES})
        set(LUA_FOUND TRUE)
    else()
        message(FATAL_ERROR "Lua headers or libraries not found on Windows.")
    endif()

    set(PLATFORM_LIBS "")

elseif(UNIX)
    find_package(Lua REQUIRED)
    
    if(LUA_INCLUDE_DIR AND LUA_LIBRARY)
        set(LUA_LIBRARIES ${LUA_LIBRARY})
        set(LUA_FOUND TRUE)
    else()
        message(FATAL_ERROR "Lua package not found or missing paths.")
    endif()
    
    set(PLATFORM_LIBS dl)
endif()

# Include directories for all source subfolders
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)
if(LUA_FOUND)
    include_directories(${LUA_INCLUDE_DIR})
endif()
include_directories(${CMAKE_SOURCE_DIR}/lib/wwWidgets)

# Add wwWidgets library (static or interface)
file(GLOB WW_WIDGETS_SOURCES
  ${CMAKE_SOURCE_DIR}/lib/wwWidgets/*.cpp
)
file(GLOB WW_WIDGETS_HEADERS
  ${CMAKE_SOURCE_DIR}/lib/wwWidgets/*.h
)
if(WW_WIDGETS_SOURCES)
    add_library(wwWidgets STATIC ${WW_WIDGETS_SOURCES} ${WW_WIDGETS_HEADERS})
else()
    add_library(wwWidgets INTERFACE)
    target_include_directories(wwWidgets INTERFACE ${CMAKE_SOURCE_DIR}/lib/wwWidgets)
endif()

# Create engine library from all sources
add_library(My2DEngine STATIC ${ENGINE_SOURCES})

target_include_directories(My2DEngine PUBLIC
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/include
  ${LUA_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/lib/wwWidgets
)

target_link_libraries(My2DEngine PUBLIC wwWidgets)

# Main executable
add_executable(My2DGame ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_link_libraries(My2DGame PRIVATE My2DEngine ${LUA_LIBRARIES} ${PLATFORM_LIBS})