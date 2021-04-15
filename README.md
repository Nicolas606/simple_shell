# simple_shell

This repository contains our shell version programmed in the C language, it can 
be used interactively and non-interactively:

**first have complie this way**

		gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

**Interactive way**

		$ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

**Non-interactive way**

		$ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $

---------------

# Description

The ./hsh (hsh) executes a replica of the sh command in linux, which opens a
command interpreter, our version works with the user's environment, so you can 
"write" the full path of the command "/ bin / ls "or the command only "ls"and 
also allows to receive the arguments of the functions" ls -la ". The hsh 
evaluates if the command is "delivered" from the terminal (interactive way) or 
if it is given in another way (non-interactive way). Each command that the user 
writes enters as a single string that is stored in a buffer, this is divided 
into words and its existence is evaluated either as a built-in or if it is in 
the user's PATH. If the command does not exist or its arguments are not valid, 
print an error message in the standard error and start the click again from the 
promt. If the command is valid, it implements the fork function to create a child 
process that is responsible for executing the commands that the user entered, 
and the parent process will be responsible for freeing the memory and re-executing the 
process from the promt. To close our shell the user must use the CTRL + D (EOF) 
signal or write the exit command.

-------------

# Files

###  [holberton.h](https://github.com/Nicolas606/simple_shell/blob/main/holberton.h "holberton.h")

This file contains the prototypes and struct of the functions contained in the files 
and functions described below.


###  [main.c](https://github.com/Nicolas606/simple_shell/blob/main/main.c "main.c")

In this file is the main that will execute all our functions. The prototype
of our main function is the following:

**int main(int argc, char *argv[], char *env[]);**

### [build_ins.c](https://github.com/Nicolas606/simple_shell/blob/main/built_ins.c "build_ins.c")

In this file you will find the functions to know what to do in case the user 
types "exit" or "env":

- The **build_ins** function compares if what the user entered are the words 
"exit" or "env", if it does not return 0.

- The **n_exit** function frees the space that was reserved for the linked 
list of our PATH and takes us out of the shell.

- The **env** function prints the folders in the local environment one by one.

### [entorno.c](https://github.com/Nicolas606/simple_shell/blob/main/entorno.c "entorno.c")

In this file you will find the function create a variable whit 
the PATH directories:

- The **_getenv** function takes care of copying the PATH folders one by one.


### [fork.c](https://github.com/Nicolas606/simple_shell/blob/main/fork.c "fork.c")

In this file it finds the functions to check if the file exists in the PATH, if it finds it it creates a child process to execute the function.

- The **comp** function Check if command exist in directory or environment.

- The **existencia** function check if a command file exist in the PATH directories.

- The **call_fork** function Check if a command exists, and executes it.

### [printf_char.c ](https://github.com/Nicolas606/simple_shell/blob/main/printf_char.c "printf_char.c ")

In this file find the functions whit use the function _pritnf

- The **print_char** function places a character in a buffer array at the indicated position.

- The **print_string** function converts the entire string into characters and places them in an array buffer from the indicated position.

### [print_int.c](https://github.com/Nicolas606/simple_shell/blob/main/printf_int.c "print_int-c") 

In this file find the functions whit use the function _pritnf.

- The function **print_int** converts each digit of an integer into characters and places them in a buffer array from the indicated position.

- The function **len_dig** calculates the number of digits that an int data contains.

- The funcion **print_u_int** Converts each digit of an unsigned integer to characters and places them in a buffer array from the indicated position.

- The funcion **len_u_dig** calculates the number of digits that an unsigned int data contains.

### [printf.c ](https://github.com/Nicolas606/simple_shell/blob/main/printf_int.c "printf.c ")

The **_printf** function is a variatic function that receives as a formal argument a const char const pointer "fortmat", writes its characters "exactly the same" in the standard output using the write function and returns an integer, which is the number of characters that were sent. to stdout without taking null characters into account.

### [shell.c](https://github.com/Nicolas606/simple_shell/blob/main/shell.c "shell.c")

In this file you will find the functions in charge of translating the commands 
written by the user:

- The **split_input** function separates the words every time it finds a space 
and returns the number of words it found.

- The **quit_spaces** function receives the words returned by the split_input 
function and checks if saved unnecessary spaces and removes.

- The **only_spaces** function check if the buffer contains just spaces

### [string.c](https://github.com/Nicolas606/simple_shell/blob/main/string.c "string.c")

this file contains the functions pfor copy,compare, concatenate and duplicate a string.

- The **_strcpy** function that copies the string pointed to by src, including the terminating null byte (\0), to the buffer pointed to by dest

- The **_strcmp**  function that compares two strings.

- The **_strcat** function that concatenates two strings.

- The **_strdup** function that returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter.
---------------

# Function flow

![flow 1](https://imagizer.imageshack.com/img922/2969/57E739.jpg)
