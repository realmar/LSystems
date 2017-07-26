cmake_minimum_required(VERSION 3.8)

set(EXEC_NAME LSystems)

file(GLOB Headers ${LSystems_SOURCE_DIR}/include/lsystem/*.hpp)
include_directories(${LSystems_SOURCE_DIR}/include/lsystem)

project(${EXEC_NAME})
set(CMAKE_CXX_STANDARD 17)

subdirs(src)