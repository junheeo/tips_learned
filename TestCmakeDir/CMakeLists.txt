cmake_minimum_required(VERSION 3.9)
project(OURPROJECT
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} main.cpp a.h a.cpp)

add_subdirectory(Lv1b)
add_subdirectory(Lv1c)
target_include_directories(${PROJECT_NAME}
                            PUBLIC Lv1b Lv2c)
target_link_libraries(${PROJECT_NAME}
                            PRIVATE B_LIBRARY C_LIBRARY)
