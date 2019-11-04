# ft_ls
My own implementation of the famous Unix command: ls, using the C programming language.

Requirements
To be able to build and run this program you'll need a macbook, because I didn't make it portable for other systems. Sorry :(. As for software Requirements, you'll need:

GNU make
GCC
No specific versions, just update them to the latest version if you still can't build the program.

Building the program
Download/Clone the source code
cd into the root directory
Run make
Running the program
It's pretty simple, instead of calling ls, call ./ft_ls from the root directory of the source code after building it.

Supported flags
Long listing display: -l
Display recursively: -R
Display all files: -a
Reverse sort: -r
Sort by modification date: -t
Display user ID and group ID: -n
Suppress owner: -g
Display one entry per line: -1
Column display: -C (Set by default)
Sort by creation date: -U
Sort by last access date: -a
Sort by last status change date: -c
Show every entry except for current and previous directories: -A
Sort by file size: -S
Colorized output: -G (Only works in long listing display)
