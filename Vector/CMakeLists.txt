cmake_minimum_required(VERSION 3.29.4)
project(Vector CXX)
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(src)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#export CXX=/usr/local/opt/llvm/bin/clang++
#cmake -S . -B bin
#cmake --build bin

#./bin/src/test/Test_Vector