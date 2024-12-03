# src/CMakeLists.txt
# Library for the engine
add_library(My2DEngine STATIC
  main.cpp
  physics/physics.cpp
  audio/audio.cpp
  utils/utils.cpp
)

# Link external libraries
target_link_libraries(My2DEngine PRIVATE ${FURNACE_PATH}/lib/libfurnace.a)

# Include directories for the engine
target_include_directories(My2DEngine PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)