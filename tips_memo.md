# tips_learned

## Installing a Vim that supports Python 3 - MACOS
- we get error installing vim

% brew install vim

...

Could not symlink share/man/de/man1/ex.1

/usr/local/share/man/de/man1 is not writable.


You can try again using:

  brew link vim
  
...


- then if we try

% brew link vim

Linking /usr/local/Cellar/vim/8.2.0750... 

Error: Could not symlink share/man/de/man1/ex.1

/usr/local/share/man/de/man1 is not writable.

- this is solved by

% sudo chown -R $(whoami) /usr/local/share

- also make sure that

% echo $PATH

- shows /usr/local/bin BEFORE /usr/bin

- if not, edit ~/.vimrc OR /etc/paths AND THEN reopen terminal

- to check if the downloaded vim is properly called:

% which vim

/usr/local/bin/vim

- should be the output

% vim --version

VIM - Vi IMproved 9.1 (2024 Jan 02, compiled May 30 2024 05:52:44)
macOS version - x86_64
Included patches: 1-450
Compiled by Homebrew
Huge version without GUI.  Features included (+) or not (-):
+acl               +file_in_path      +mouse_urxvt       -tag_any_white
+arabic            +find_in_path      +mouse_xterm       -tcl
+autocmd           +float             +multi_byte        +termguicolors
+autochdir         +folding           +multi_lang        +terminal
-autoservername    -footer            -mzscheme          +terminfo
-balloon_eval      +fork()            +netbeans_intg     +termresponse
+balloon_eval_term +gettext           +num64             +textobjects
-browse            -hangul_input      +packages          +textprop
++builtin_terms    +iconv             +path_extra        +timers
+byte_offset       +insert_expand     +perl              +title
+channel           +ipv6              +persistent_undo   -toolbar
+cindent           +job               +popupwin          +user_commands
-clientserver      +jumplist          +postscript        +vartabs
+clipboard         +keymap            +printer           +vertsplit
+cmdline_compl     +lambda            +profile           +vim9script
+cmdline_hist      +langmap           -python            +viminfo
+cmdline_info      +libcall           +python3           +virtualedit
+comments          +linebreak         +quickfix          +visual
+conceal           +lispindent        +reltime           +visualextra
+cryptv            +listcmds          +rightleft         +vreplace
+cscope            +localmap          +ruby              +wildignore
+cursorbind        +lua               +scrollbind        +wildmenu
+cursorshape       +menu              +signs             +windows
+dialog_con        +mksession         +smartindent       +writebackup
+diff              +modify_fname      +sodium            -X11
+digraphs          +mouse             +sound             -xattr
-dnd               -mouseshape        +spell             -xfontset
-ebcdic            +mouse_dec         +startuptime       -xim
+emacs_tags        -mouse_gpm         +statusline        -xpm
+eval              -mouse_jsbterm     -sun_workshop      -xsmp
+ex_extra          +mouse_netterm     +syntax            -xterm_clipboard
+extra_search      +mouse_sgr         +tag_binary        -xterm_save
-farsi             -mouse_sysmouse    -tag_old_static    
   system vimrc file: "$VIM/vimrc"
     user vimrc file: "$HOME/.vimrc"
 2nd user vimrc file: "~/.vim/vimrc"
 3rd user vimrc file: "~/.config/vim/vimrc"
      user exrc file: "$HOME/.exrc"
       defaults file: "$VIMRUNTIME/defaults.vim"
  fall-back for $VIM: "/usr/local/share/vim"

  

- +python3 : so our vim now has python3 support

## installing autocompleters with YouCompleteMe
at directory: /Users/username/.vim/bundle/YouCompleteMe


YouCompleteMe % python3 install.py --all

Generating ycmd build configuration...OK

Compiling ycmd target: ycm_core...OK

Building regex module...OK

Building watchdog module...OK

Installing Omnisharp for C# support...OK

Building gopls for go completion...OK

Setting up Tern for JavaScript completion...OK

Installing rust-analyzer "nightly-2023-08-18" for Rust support...OK

Installing jdt.ls for Java support...OK

Setting up TSserver for TypeScript completion...OK

Setting up Clangd completer...OK


## i7-2600K and GTX 900 series
x86-64 operating system works on i7-2700k  
Sandy Bridge (intel 2nd gen) CPUs' motherboard may have stepping issue(SATA 0,1 works fine, but not the rest, can damage entire board)
B75 chipset mainboards do not have sandy bridge chipset stepping issue from the start so no need to see if stepping is applied.  
This is a B75 chipset mainboard:  
https://mitem.gmarket.co.kr/Item?goodsCode=2381177529&PARTNERSHIP=eyJfcm1jZ3VpZCI6IjExNzE3ODkyODkyODY2MDAwNDcyMDAwMDAwIiwiX3JtcGd1aWQiOiIyMTcxNzg5Mjg5Mjg2NjAwMDQ3MjAxMDAwMCIsImphZWh1aWQiOiIyMDAwMTU0NDgifQ&appgate_guid=638535223142078475-75428d9d-034f-4102-9576-6470d7ea64da  

gtx 900 series graphics card drivers do get installed  
https://forums.developer.nvidia.com/t/drivers-for-geforce-gtx-970-installed-but-no-display-output-on-ubuntu-22-04/290969  
probably using  ubuntu-drivers autoinstall  
seems like most recent nvidia driver supports gtx 900 series:  
https://www.nvidia.co.kr/Download/driverResults.aspx/211911/kr  
how to:  
https://gist.github.com/charleslouis/088289d94023b9386799  

seems like the latest CUDA toolkit supports maxwell (gtx 900 series)  
https://docs.nvidia.com/cuda/archive/12.4.1/  
and Ubuntu version should be Ubuntu 22.04.z (z <= 3) LTS or Ubuntu 20.04.z (z <= 6) LTS  
https://docs.nvidia.com/cuda/archive/12.4.1/cuda-installation-guide-linux/index.html  

## compiling with g++
suppose the project directory:  
.  
|-main.cpp  
|-message.cpp  
|-message.h  

compiling as object(.o)file:  
    g++ -c main.cpp -o main.o  
    g++ -c message.cpp -o message.o  
  
linking objects into single executable  
    g++ main.o message.o -o my_program  

run executable  
    ./my_program  

<main.cpp>
#include <iostream>  
  
// Declaration of the function in another file  
void printMessage();  
  
int main() {  
  printMessage();  
  return 0;  
}  
__________________________  
<message.cpp>  
#include <iostream>  
  
// Definition of the function  
void printMessage() {  
  std::cout << "Hello from another file!" << std::endl;  
}  
_________________________
<message.h>  
#ifndef MESSAGE_H  
#define MESSAGE_H  
  
// Declaration of the function  
void printMessage();  
  
#endif // MESSAGE_H  
__________________________

written by Chat-GPT  

