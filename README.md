# The Gates Of Shell - 0x16. C - Simple Shell

![Gates of Shell](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

# Description

Simple Shell is a program that reads the user input from file or
terminal, make a proccess to interprets the instruction, and executes
them. This is a simple shell that has the more basic functionality for
linux commands.

# Requirements

This Simple Shell is designed to run in the `Ubuntu 20.04.3 LTS` linux
environment and cmpiled with GNU compiler using flags `-Wall -Werror
-Wextra -pedantic -std=gnu89`.

# Installation

   - Compile: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o
   - shell` Run the shell in interactive mode: `./shell`
   - Run the shell in non-interactive mode: Example `echo "ls" | ./shell`

# How to use

This simple shell program is an application that reads the input from user
from a file or the terminal, proccess the instructions and executes them.

### Signals:

The input 'Ctrl+D' EOF - end-of-file will exit the program.

User hits `Ctrl+d` in the third line.
```
($) ./shell
($) ^C
($) ^D
```
#### Env
  * Usage: `env`
  * Prints the current environment.

Example:
```
($) ./shell
($) env
SHELL=/bin/bash
...
```
#### $$
The second `$` is substitued with the current process ID.

Example:
```
$ echo "echo $$" | ./hsh
6494
```

#### Exit
  * Usage: `exit [STATUS]`
  * Exits the shell.
  * The `STATUS` argument is the integer used to exit the shell.
  
Example:
```
$ ./hsh
~> exit
```

# Examples
```
$ ./hsh 
~> ls -l
total 76
-rw-rw-r-- 1 vagrant vagrant   217 Apr 19 18:27 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  2147 Apr 19 18:27 aux_functions.c
-rw-rw-r-- 1 vagrant vagrant   737 Apr 19 18:27 built_ins.c
-rw-rw-r-- 1 vagrant vagrant   764 Apr 19 18:27 env.c
-rw-rw-r-- 1 vagrant vagrant  1766 Apr 19 18:27 _execve.c
-rw-rw-r-- 1 vagrant vagrant   935 Apr 19 18:27 free.c
-rwxrwxr-x 1 vagrant vagrant   331 Apr 19 18:27 generate_authors
-rwxrwxr-x 1 vagrant vagrant 21421 Apr 19 18:39 hsh
-rw-rw-r-- 1 vagrant vagrant  1069 Apr 19 18:27 LICENSE
-rwxrwxr-x 1 vagrant vagrant  1939 Apr 19 18:27 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant   252 Apr 19 18:27 _putchar.c
-rw-rw-r-- 1 vagrant vagrant  1559 Apr 19 18:27 README.md
-rw-rw-r-- 1 vagrant vagrant  1125 Apr 19 18:39 shell_header.h
-rw-rw-r-- 1 vagrant vagrant  1196 Apr 19 18:27 shell_main.c
~> pwd
/home/vagrant/simple_shell
~> exit
$ 
```

# Authors
Jhon Bueno & Juan Camilo Arce.
