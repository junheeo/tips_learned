cmake_minimum_required(VERSION 3.29.4)
project(Anna CXX)
add_subdirectory(src)


include(GNUInstallDirs)
#set(CMAKE_INSTALL_PREFIX
#    "/Users/junheeoh/Code/cpp_tutorial/cmake_practice/Anna/lv1a")
#install(
#    TARGETS alib
#    ARCHIVE DESTINATION ${CMAKE_INSTALL_BINDIR}
#)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#export CXX=/usr/local/opt/llvm/bin/clang++
#cmake -S . -B bin
#cmake --build bin
