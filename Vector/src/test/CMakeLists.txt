add_executable(Test_Vector main.cpp)
target_include_directories(Test_Vector PRIVATE vector)
target_link_libraries(Test_Vector PRIVATE Vector_Lib)
