find_package(OpenGL REQUIRED)

include_directories(${GLUT_INCLUDE_DIRS})

add_library(Renderer STATIC ${Headers} renderer.cpp)

find_package(GLUT REQUIRED)
target_link_libraries(Renderer ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} Builder GLUT::GLUT)
