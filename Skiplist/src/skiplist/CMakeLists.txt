#include(/Users/junheeoh/Code/cpp_tutorial/cmake_practice/Vector/bin/src/vector/cmake/Vector_LibTargets.cmake)

include(../../../Vector/bin/src/vector/cmake/Vector_LibTargets.cmake)
# add_library(Vector::Vector_Lib STATIC IMPORTED) # already included by above line


add_library(Skiplist_Lib INTERFACE)
target_include_directories(Skiplist_Lib INTERFACE .)

