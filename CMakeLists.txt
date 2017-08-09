cmake_minimum_required(VERSION 3.8)

set(EXEC_NAME LSystems)
set(CMAKE_CXX_STANDARD 17)

project(${EXEC_NAME})

add_subdirectory(include)
include_directories(${LSystems_SOURCE_DIR}/include)
add_subdirectory(src)
