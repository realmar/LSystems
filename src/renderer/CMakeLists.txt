find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)
set(GLUT_LIBRARIES freeglut)

include_directories(${GLUT_INCLUDE_DIRS})

add_library(Renderer STATIC ${Headers} renderer.cpp)
target_link_libraries(Renderer ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} Builder)
