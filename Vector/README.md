If you want to use youcompleteme on vim and have copied .ycm_extra_config.py to ~/.vim, run on the comand line
```
cp ~/.vim/.ycm_extra_conf.py ./
```

If you are using macOs and you want to use Homebrew LLVM Clang++, run on the command line
```
export CXX=/usr/local/opt/llvm/bin/clang++
```

When creating CMake build file for the first time, run on the command line
```
cmake -S . -B bin -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
ln -s ./bin/compile_commands.json ./
```

Whenever rebuilding CMake files and recompiling the code, run on the command line
```
export CXX=/usr/local/opt/llvm/bin/clang++
cmake -S . -B bin
cmake --build bin
```
