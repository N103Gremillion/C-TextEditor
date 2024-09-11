cmake_minimum_required(VERSION 3.22.1)

# Set the project's name
project(Editor VERSION 0.1.0 LANGUAGES C)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find the SDL2 and SDL2_ttf packages
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

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

# Include the SDL2 and SDL2_ttf include directories
target_include_directories(Editor PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

# Link the SDL2 and SDL2_ttf libraries
target_link_libraries(Editor PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf)

