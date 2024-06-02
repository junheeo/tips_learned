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

#
