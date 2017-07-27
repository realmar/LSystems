cmake_minimum_required(VERSION 3.8)

set(EXEC_NAME LSystems)

project(${EXEC_NAME})
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(include)
include_directories(${LSystems_SOURCE_DIR}/include)
add_subdirectory(src)
