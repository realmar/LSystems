add_subdirectory(lsystem)
add_subdirectory(renderer)
add_subdirectory(builder)

add_executable(${EXEC_NAME} ${Headers} main.cpp)
target_link_libraries(${EXEC_NAME} Base Concretes Renderer Builder)
