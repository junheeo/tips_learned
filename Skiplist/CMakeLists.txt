cmake_minimum_required(VERSION 3.29.4)
project(Skiplist CXX)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")
add_subdirectory(src)


set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#export CXX=/usr/local/opt/llvm/bin/clang++
#cmake -S . -B bin
#cmake --build bin

