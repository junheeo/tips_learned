add_executable(Test_Skiplist main.cpp)

include(../../../Vector/bin/src/vector/cmake/Vector_LibTargets.cmake)



target_include_directories(Test_Skiplist PRIVATE skiplist)
target_link_libraries(Test_Skiplist PRIVATE Vector::Vector_Lib Skiplist_Lib)

#target_link_libraries(Test_Skiplist PRIVATE Skiplist_Lib)
