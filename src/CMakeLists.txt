# src/CMakeLists.txt

# Define the engine source files
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS *.cpp)

# Create the GameEngine library target
add_library(GameEngine STATIC ${ENGINE_SRC})

# Include directories for the GameEngine library
target_include_directories(GameEngine 
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include  # Include the include directory
)

# Optionally, set the output directory for the library
set_target_properties(GameEngine PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Define the executable target
add_executable(ALIGNGame main.cpp)  # Adjust "main.cpp" if your main file has a different name

# Link the GameEngine library with the executable
target_link_libraries(ALIGNGame PRIVATE GameEngine)

# Set the output for the executable
set_target_properties(ALIGNGame PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy files from 3rdPartySoftware/exe/ to the build/bin directory
add_custom_command(TARGET ALIGNGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/3rdPartySoftware/exe  # Source directory
        ${CMAKE_BINARY_DIR}/bin  # Destination directory
    COMMENT "Copying files from 3rdPartySoftware/exe/ to build/bin/"
)
