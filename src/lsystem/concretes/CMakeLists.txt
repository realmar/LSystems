add_library(Concretes STATIC ${Headers} cantorset.cpp algae.cpp binarytree.cpp KochCurve.cpp sierpinski.cpp sierpinski_arrowhead.cpp dragoncurve.cpp fractalplant.cpp hilbertcurve.cpp)
target_link_libraries(Concretes Base)
