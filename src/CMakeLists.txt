add_subdirectory(lsystem)

file(GLOB SOURCE_FILES "*.cpp")

add_executable(${EXEC_NAME} ${SOURCE_FILES} ${Headers})
target_link_libraries(${EXEC_NAME} Concretes)
