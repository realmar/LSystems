file(GLOB SOURCE_FILES algae.cpp binarytree.cpp)

add_library(Concretes STATIC ${SOURCE_FILES} ${Headers})
target_link_libraries(Concretes Base)