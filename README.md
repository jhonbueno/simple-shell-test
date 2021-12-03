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
#### Exit
  * Usage: `exit`
  * Exits the shell.

Example:
```
($) ./shell
($) exit
```

# Examples
```
$ ./shell
($) ls -l
-rw-rw-r-- 1 vagrant vagrant  2355 Dec  3 18:44 '#README.md#'
-rw-rw-r-- 1 vagrant vagrant  1586 Dec  3 17:39 '#check_command.c#'
-rw-rw-r-- 1 vagrant vagrant   164 Dec  3 17:06  AUTHORS
-rw-rw-r-- 1 vagrant vagrant  2479 Dec  3 17:09  README.md
-rw-rw-r-- 1 vagrant vagrant  1100 Dec  3 17:06  addtokens.c
-rw-rw-r-- 1 vagrant vagrant  1482 Dec  3 17:06  builtins.c
-rw-rw-r-- 1 vagrant vagrant  1566 Dec  3 18:11  check_command.c
-rw-rw-r-- 1 vagrant vagrant   427 Dec  3 17:28  frees.c
-rw-rw-r-- 1 vagrant vagrant  1033 Dec  3 17:30  hsh.h
-rw-rw-r-- 1 vagrant vagrant   951 Dec  3 17:35  main.c
-rw-rw-r-- 1 vagrant vagrant  1482 Dec  3 17:06  man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant  2482 Dec  3 17:07  re.md
-rwxrwxr-x 1 vagrant vagrant 18168 Dec  3 18:40  shell
-rw-rw-r-- 1 vagrant vagrant  1780 Dec  3 17:06  strings.c
($) pwd
/home/vagrant/simple-shell-test
($) exit
$
```
## Files and Descriptions
|  FILE  |  DESCRIPTION  |
| ------------- | ------------- |
| main.c | Main function for UNIX command line interpreter |
| hsh.h | Header file with all prototypes and imported libraries |
| builtins.c  |  It contains function for builtin commands |
| check_command.c | This file contain the functions for get environment, find path and print error |
| frees.c | It contins the functions for free the memory |
| AUTHORS | Contains authors of the project |
| man_1_simple_shell | Man page with documentation of simple shell |
| strings.c | String manipulation functions |
| addtokens.c |  Tokenize and create double pointer with command arguments |

# Authors
- Jhon Bueno
- Juan Camilo Arce.
