settings:
  + macos Sonoma 14.4.1
  + macbook pro 15inch 2019
  + zsh shell
  + Terminal app

## install new vim
in order for YouCompleteMe to work, you need vim that supports python3.

when you try

%vim --version

and have -python3

then you need to install new vim and use that instead of vim supplied by apple:

%brew install vim

then try

%echo $PATH

if in the output /usr/local/bin does not apper before /usr/bin then you need to change PATH environment variable.

%vim ~/.zprofile

add (move cursor with hjkl, go into insert mode with i, exit insert mode with esc)

PATH="/usr/local/bin:${PATH}"

get out of vim with :wq and then update zsh settings

%source ~/.zprofile

try 

%echo $PATH

and if /usr/local/bin appears before /usr/bin, then you are good to go to the next step. 

If /usr/bin appears before /usr/local/bin then consult other sources and make it work (find other .zprofile, .zshenv, ... and edit PATH varible)


### a few tips for vim

to make vim perform syntaxcoloring, add

syntax on

to .vimrc


If backspace key doesn't work properly in vim with your keyboard(backspace on hhkb keyboard didn't work for me in brew installed vim) add

set backspace=indent,eol,start

to .vimrc


If you want vim to remember where you left last time when go open the file add

if has("autocmd")

au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

endif

to .vimrc


## install llvm
since [apple clang seems to quirky](https://www.reddit.com/r/cpp_questions/comments/moirt4/apple_clang_vs_clang/) and since apple provided ld linker seems to not work properly, we should install llvm (include clang, clang++, ...)

installing llvm has dependency python3.12. If you do

%brew list

you probably would be able to find python@3.12 so it should work. 
I also had python3.8 and python3.9 installed but installing llvm didn't destroy my other pythons at least for me.
Worst case senario IF YOUR PYTHON3.8 GETS DESTROYED, you could try sudo rm-rf /Library/Frameworks/Python.framework/Versions/3.8 and try reinstalling python3.8.
But I haven't tried it myself though.

install llvm with

$ brew install llvm

since your PATH environment variable should have /usr/local/bin before /usr/bin when you call Clang or Clang++ or anything inside llvm
you should get installed clang and clang++ instead of Apple Clang

% Clang --version

should give you something like this:

Homebrew clang version 18.1.6

Target: x86_64-apple-darwin23.4.0

Thread model: posix

InstalledDir: /usr/local/opt/llvm/bin


according to brew, you should add

LDFLAGS="-L/usr/local/opt/llvm/lib"

LDFLAGS="$LDFLAGS -L/usr/local/opt/llvm/lib/c++ -Wl, -rpath, /usr/local/opt/llvm/lib/c++"

export LDFLAGS

in your .zprofile and 

also in .zprofile add

export CC := clang

export CXX := $(CC)++

and then do %source .zprofile to update zsh settings in order for compilers to find llvm.


## install Vundle

you would be installing YouCompleteMe with Vundle so you need Vundle in the first place.
Vundle is a plugin manager for Vim.

https://github.com/VundleVim/Vundle.vim

run in shell

%git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

and then you should change your vim settings by editing .vimrc

%vim ~/.vimrc

add this to .vimrc

______________________________

set nocompatible              " be iMproved, required

filetype off                  " required

" set the runtime path to include Vundle and initialize

set rtp+=~/.vim/bundle/Vundle.vim

call vundle#begin()

" alternatively, pass a path where Vundle should install plugins

"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required

Plugin 'VundleVim/Vundle.vim'


" All of your Plugins must be added before the following line

call vundle#end()            " required

filetype plugin indent on    " required

" To ignore plugin indent changes, instead use:

"filetype plugin on

"

" Brief help

" :PluginList       - lists configured plugins

" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate

" :PluginSearch foo - searches for foo; append `!` to refresh local cache

" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal

"

" see :h vundle for more details or wiki for FAQ

" Put your non-Plugin stuff after this line

______________________________

right below Plugin 'VundleVim/Vundle.vim' add

Plugin 'ycm-core/YouCompleteMe'

exit insert mode(esc) and save(:wq)


## install YouCompleteMe and cmake

now that you have vim that supports python3, an installed youcompleteme(ycm) should work properly.

https://github.com/ycm-core/YouCompleteMe

install YouCompleteMe by getting into .vimrc

%vim ~/.vimrc

and type

:Plugin Install

if plugin install is finished, get out of it with q.

in zsh, run

%brew install cmake python go nodejs

%brew install java

%sudo ln -sfn $(brew --prefix java)/libexec/openjdk.jdk /Library/Java/JavaVirtualMachines/openjdk.jdk

%cd ~/.vim/bundle/YouCompleteMe

%python3 install.py --all

in ~/.vimrc add

let g:ycm_clangd_uses_ycmd_caching = 0

let g:ycm_clangd_binary_path = exepath("clangd")

PATH = "/usr/local/opt/llvm/bin:${PATH}"
export PATH

which the first one claims to let clangd fully control code completion
and the second one claims to make youcompleteme(ycm) use installed clangd, not ycm-bundled clangd which doesn't get updates.

but with only this, when you write c++ code, it wouldn't be able to recognize iostream in #include <iostream>.
You can make ycm recognize standard libraries just by ivoking cmake, and recognize user-defined libraries in subdirectories of the project by using .ycm_extra_conf.py and compile_commands.json

I will show how this works in an example from next chapter

## cmake example c++ project with working youcompleteme

https://www.youtube.com/watch?v=kEGQKzhciKc

(watch episode 1 too to understand episode 2)

CMake Tutorial EP 2 | Libraries and Subdirectories by Code, Tech, and Tutorials

we will follow the above tutorial.

first get to know your cmake version with

%cmake --version

My version is 3.29.4

inside a directory where you want to create our example project (I have a Code directory in ~ to keep all my programming project files.)

(you should currently be in OURLORDANDSAVIOR)

%mkdir OURLORDANDSAVIOR

%vim CMakeLists.txt

insert in CMakeLists.txt the following:

______________________

cmake_minimum_required(VERSION 3.29)

project(OLAS

    LANGUAGES CXX)

set (CMAKE__CXX_STANDARD 11)   # Enable c++11 standard, should automatically include -std=c++11 when cmake compiles my code

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Adder)

target_include_directories(${PROJECT_NAME} Public Adder)

target_link_directories(${PROJECT_NAME} PRIVATE Adder)

target_link_libraries(${PROJECT_NAME} adder)

________________________

save exit (:wq)

copy .ycm_extra_conf.py to OURLORDANDSAVIOR directory. We will first copy .ycm_extra_conf.py under 
~/.vim/ so that we can find .ycm_extra_conf.py more easily from now on.

go to OURLORDANDSAVIOR directory with cd and then do the following

%cp ~/.vim/bundle/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py ~/.vim/

(you should currently be in OURLORDANDSAVIOR)

%vim ~/.vim/.ycm_extra_conf.py

probably in line 102, it would currently be

compilation_database_folder = ''

edit this to 

compilation_database_folder = './'

and saveexit

%cp ~/.vim/.ycm_extra_conf.py .

where . stands for the current directory you are in (which should be OURLORDANDSAVIOR.)

(you should currently be in OURLORDANDSAVIOR)
%vim main.cpp

insert in main.cpp the following: (youcompleteme wouldn't be working properly but just ignore and type)

___________________

#include <iostream>

#include "adder.h"

int main () {

std::cout << "Hey Zeus!\n";

std::cout << add(72.1f, 73.8f) << std::endl;

return 0;

}

__________________

get out of main.cpp

(you should currently be in OURLORDANDSAVIOR)

%mkdir Adder

%cd Adder

(you should currently be in Adder)

%vim CMakeLists.txt

(yes, you are making another CMakeLists.txt file in subdirectory)

__________________

add_library(adder adder.cpp adder.h)

_________________

(you should currently be in Adder)

%vim adder.h

___________________

float add (float a, float b);

__________________

exit vim

(you should currently be in Adder)

% vim adder.cpp

________________

#include "adder.h"

float add (float a, float b) {

    return a + b;

}

_______________

exit vim

(you should currently be in Adder)

%cd ../

You should currently be in OURLORDANDSAVIOR.

then run commands

%cmake -S . -B out/build -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

-DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++ is to force cmake to compile with our brew installed clang++ instead of Apple Clang (location of our installed clang++)

-DCMAKE_EXPORT_COMPILE_COMMANDS=ON is to force cmake generate database for this build.

it turns out that on macos adding set( CMAKE_EXPORT_COMPILE_COMMANDS ON ) to CMakeLists.txt or whatever cmake setting file is ignored so we need to directly add this to cmake building command

this would create compile_commands.json inside out/build which is the database for this project.

we need to link this compile_commands.json file to right under the OURLORDANDSAVIOR directory.

(You should currently be in OURLORDANDSAVIOR)

%ln -s out/build/compile_commands.json .

where . stands for current directory(OURLORDANDSAVIOR)

now if you %vim main.cpp it would recognize <iostream> and "adder.h" perfectly well.

then to compile code, run

%make -C out/build

if you look at %ls out/build/Adder you will find libadder.a which is the compiled library.

to run the code, 

% ./out/build/OLAS

Hey Zeus!

145.9

should be printed as accordingly to our main() function.

OLAS is the project name that we defined in the CMakeLists.txt previously hence the executable name is OLAS. This is due to setting add_executable(${PROJECT_NAME} main.cpp) in CMakeLists.

_________________________________
HOW TO INCLUDE .H AND .CPP FILES IN THE TOP DIRECTORY PARALLEL TO MAIN.CPP

Let's say 

OURLORDANDSAVIOR % ls

Adder                 main.cpp              tester.h

CMakeLists.txt        out

compile_commands.json tester.cpp

you are at OURLORDANDSAVIOR directory and you have tester.h and tester.cpp that you want to include in main.cpp file. Suppose

tester.h
_______________________________
void tester ();
_______________________________
tester.cpp
_______________________________
#include <iostream>

#include tester.h

void tester () {

std::cout << "tester check" << std::endl;

}
_______________________________

and change the main file:

main.cpp
_______________________________
#include <iostream>

#include "adder.h"

#include "tester.h"

int main () {

std::cout << "Hey, Zeus" << std::endl;

std::cout << add(72.1f, 73.8f << std::endl;

tester();

return 0;

}
_______________________________

then in CMakeLists.txt (right below the OURLORDANDSAVIOR directory), change 

add_executable(${PROJECT_NAME} main.cpp)

to

add_executable(${PROJECT_NAME} main.cpp tester.h tester.cpp)

then use the same cmake and make comamnds as above

cmake -S . -B out/build -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

make -C out/build

and run code with

% ./out/build/OLAS
