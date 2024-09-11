cmake_minimum_required(VERSION 3.22.1)

# Set the projcets name
project(Editor VERSION 0.1.0 LANGUAGES C CXX)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Set the output directory for libraries (if any)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Include the SDL2 include directories
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(Editor 
    main.c
    manager.c
    graphics/window.c
    graphics/renderer.c
    graphics/button.c
    graphics/rectangle.c
    graphics/color.c
    events/event.c
    dataStructures/hashMap/hashMap.c
    dataStructures/linkedList/linkedList.c
)

# Link the SDL2 library
target_link_libraries(Editor ${SDL2_LIBRARIES})
