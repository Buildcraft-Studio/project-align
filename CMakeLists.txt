cmake_minimum_required(VERSION 3.16)
project(ALIGN)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)

# Specify output directories for ALIGN project
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(include)

# Option to build Furnace
option(BUILD_FURNACE "Build Furnace executable" ON)

if(BUILD_FURNACE)
    # Define the build directory for Furnace
    set(FURNACE_BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdPartySoftware/furnace/build)

    # Create the Furnace build directory if it doesn't exist
    file(MAKE_DIRECTORY ${FURNACE_BUILD_DIR})

    # Run cmake for Furnace
    execute_process(COMMAND ${CMAKE_COMMAND} .. 
                    WORKING_DIRECTORY ${FURNACE_BUILD_DIR}
                    RESULT_VARIABLE result)

    # Check if the CMake process was successful
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "Furnace CMake configuration failed.")
    endif()

    # Optionally, build Furnace after configuring
    execute_process(COMMAND ${CMAKE_COMMAND} --build . --parallel
                    WORKING_DIRECTORY ${FURNACE_BUILD_DIR}
                    RESULT_VARIABLE result)

    if(NOT result EQUAL 0)
        message(FATAL_ERROR "Furnace build failed.")
    endif()
endif()

# Subdirectories for ALIGN project
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib)

# Optional: External libraries (add 3rd party libraries like SDL, OpenGL, etc.)
add_subdirectory(3DPartySoftware)
