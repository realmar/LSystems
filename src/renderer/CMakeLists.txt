find_package(OpenGL REQUIRED)

set(GLFW_LIBRARIES glfw)

add_library(Renderer STATIC ${Headers} renderer.cpp)
target_link_libraries(Renderer ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES} Builder)
