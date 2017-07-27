add_subdirectory(lsystem)
add_subdirectory(renderer)

add_executable(${EXEC_NAME} ${Headers} main.cpp)
target_link_libraries(${EXEC_NAME} Concretes Renderer)
