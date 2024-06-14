My Hardware:  
MacBook Pro 15 2019  
macOS Sonoma 14.4.1  
  
(Assuming you have done:  
    %cp ~/.vim/bundle/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py ~/.vim  
previously right after installation of cmake  
)  
  
```
% mkdir TestCmakeDir
TestCmakeDir % cp ~/.vim/.ycm_extra_conf.py .
TestCmakeDir % vim CMakeLists.txt 
```

<CmakeLists.txt>  
cmake_minimum_required(VERSION 3.29)  #check you cmake version  
project(OURPROJECT             #create project with project name PROJECT  
        LANGUAGES CXX)  
  
 
set(CMAKE_CXX_STANDARD 11)  #set -std=c++11
  
add_executable(${PROJECT_NAME} main.cpp a.h a.cpp)  
```
TestCmakeDir % vim a.h 
```

<a.h>  
void afunction();  

```
TestCMakeDir % vim a.cpp 
```

<a.cpp>  
#include<iostream>  
void afunction () {  
  std::cout << "afunction() called" << std::endl;  
}  
```
TestCMakeDir % vim main.cpp 
```

<main.cpp>  
#include "a.h"   
int main () {  
  afunction();  
  return 0;  
}  
```
TestCMakeDir % cmake -S . -B out/build -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++ -DCMAKE_EXPORT_COMPILE_COMMAND=ON
TestCMakeDir % mkdir Lv1b
TestCMakeDir % cd Lv1b
Lv1b % vim CMakeLists.txt 
```
   
<Lv1b/CmakeLists.txt>  
add_library(B_LIBRARY b.h b.cpp)  
```
Lv1b % vim b.h 
```

<b.h>  
void bfunction();  
```
Lv1b % vim b.cpp 
```

<b.cpp>  
void bfunction () {  
  std::cout << "bfunction called" << std::endl;  
}  
```
Lv1b % cd ../
TestCmakeDir % vim CMakeLists.txt 
```

<CMakeLists.txt>  
cmake_minimum_required(VERSION 3.29)  #check you cmake version  
project(OURPROJECT             #create project with project name PROJECT  
        LANGUAGES CXX)  
  
#C: C  
#C++: CXX  
#CUDA: CUDA  
#ObjectiveC: OBJC  
#Fortran: Fortran  
  
set(CMAKE_CXX_STANDARD 11)  #set -std=c++11  
  
add_executable(${PROJECT_NAME} main.cpp a.h a.cpp)  
  
add_subdirectory(Lv1b)  
target_include_directories(${PROJECT_NAME}  
                            PUBLIC Lv1b)  
target_link_libraries_(${PROJECT_NAME}  
                        PRIVATE B_LIBRARY)  
```
TestCmakeDir % TestCMakeDir % cmake -S . -B out/build -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++ -DCMAKE_EXPORT_COMPILE_COMMAND=ON
TestCmakeDir % mkdir -p Lv1c/Lv2c
TestCmakeDir % cd Lv1c
Lv1c % vim CMakeLists.txt 
```

<Lv1c/CMakeLists.txt>  
add_subdirectory(Lv2c)  
target_include_directories(${PROJECT_NAME}  
                            PRIVATE Lv2c)
```
Lv1c % cd Lv2c
Lv2c % vim CMakeLists.txt 
```

<Lv1c/Lv2c/CMakeLists.txt>  
add_library(C_LIBRARY c.h c.cpp c_helper.cpp)  
```
Lv2c % vim c.h 
```

<Lv1c/Lv2c/c.h>  
void cfunction ();  
```
Lv2c % vim c_helper.cpp 
```

<Lv1c/Lv2c/c_helper.cpp>  
int cHelperFunction () {  
    return 1+2;  
}  
```
Lv2c % vim c.cpp 
```

<Lv1c/Lv2c/c.cpp>  
void cfunction () {  
  if (cHelperFunction () == 3) {  
     std::cout << "cHelperFunction  called" << std::endl;  
  }  
  std::cout << "cfunction called" << std::endl;  
}  
```
Lv2c % cd ../../
TestCmakeDir % vim CMakeLists.txt 
``` 

<CMakeLists.txt>
cmake_minimum_required(VERSION 3.29)  #check you cmake version  
project(OURPROJECT             #create project with project name PROJECT  
        LANGUAGES CXX)  
  
#C: C  
#C++: CXX  
#CUDA: CUDA  
#ObjectiveC: OBJC  
#Fortran: Fortran  
  
set(CMAKE_CXX_STANDARD 11)  #set -std=c++11  
  
add_executable(${PROJECT_NAME} main.cpp a.h a.cpp)  
  
add_subdirectory(Lv1b)  
add_subdirectory(Lv1c)
target_include_directories(${PROJECT_NAME}  
                            PUBLIC Lv1b Lv2c)  
target_link_libraries_(${PROJECT_NAME}  
                        PRIVATE B_LIBRARY C_LIBRARY)  
```
TestCmakeDir % vim main.cpp 
```

<main.cpp>
#include "a.h"   
#include "b.h"
#include "c.h"
int main () {  
  afunction();  
  bfunction();
  cfunction();
  return 0;  
} 
```
TestCmakeDir % cmake -S . -B out/build -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
TestCmakeDir % Make -C out/build
TestCmakeDir % ./out/build/OURPROJECT 
```

_____________________
This should print:  
  
afunction called  
bfunction called  
cHelperFunction called  
cfunction called  
_____________________
