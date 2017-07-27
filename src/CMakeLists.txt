add_subdirectory(lsystem)

add_executable(${EXEC_NAME} ${Headers} main.cpp)
target_link_libraries(${EXEC_NAME} Concretes)
