find_package(GLEW REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS})

set(GLFW_LIBRARIES glfw)

add_library(Renderer STATIC ${Headers} renderer.cpp)
target_link_libraries(Renderer ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})

message(${GLEW_INCLUDE_DIRS})
message(${GLFW_LIBRARIES})
