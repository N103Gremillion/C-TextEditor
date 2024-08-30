cmake_minimum_required(VERSION 3.30.0)
project(Editor VERSION 0.1.0 LANGUAGES C CXX)

# standard can be 99 17 etc
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#Bring in fmt lib
include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.1.1
)

FetchContent_MakeAvailable(fmt)

add_executable(Editor main.c)
target_link_libraries(Editor PRIVATE fmt::fmt)