add_subdirectory(concretes)

file(GLOB SOURCE_FILES base.cpp)
add_library(Base STATIC ${SOURCE_FILES} ${Headers})