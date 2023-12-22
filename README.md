![image](https://apply.holbertonschool.com/holberton-logo.png)


# Simple Shell

### Introduction

This repository is a Holberton School project. Simple shell is a UNIX command interpreter that replicates the functionalities of the sh shell. It can execute commands, handle file operations and display the contents of files. The shell also includes basic error handling for invalid commands.

### General

* Learn how to code a simple UNIX command interpreter.
* Learn how to provide interactive interface for users to interact with the operating system kernel and execute programs.
* Get to know how to manipulate the environment of the current process
* How to execute commands with or without arguments.

## Features

* Display a prompt and wait for user input.
* Parse the user's input into individual words (tokens).
* Execute commands with or without arguments.
* Implement basic shell builtins like `cd`, `pwd` and `echo`.
* Handle built-in commands: `exit` and `env`.
* Handle the "end of file" condition (Ctrl+D).
* Basic PATH handling to locate executables.
* Free allocated memory to avoid memory leaks.

## List of Allowed Functions and System Calls+

- All functions from `string.h`
- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `printf` (man 3 printf)
- `fprintf` (man 3 fprintf)
- `vfprintf` (man 3 vfprintf)
- `sprintf` (man 3 sprintf)
- `putchar` (man 3 putchar)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

## Flowchart

![Alt text](flowchart.PNG)

## Getting Started

1. Open your terminal.
2. Clone this repository:

```bash
    git clone https://github.com/sachihiroo/holbertonschool-simple_shell
   ```

3. Navigate to the directory containing the project files.

4. Compile the source files using the provided compilation command:

   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
      ```


5. Run the compiled executable:

   ```bash
   ./hsh
   ```

6. The shell will display a prompt ($) where you can enter commands. Type `exit` to exit the shell.













