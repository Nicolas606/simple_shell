# simple_shell

this repository contains our shell version programmed in the C language, it can 
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

-----------

# Files

###  holberton.h

This file contains the environment structure to create the linked list of the 
PATH, it also contains the prototypes of the functions contained in the files 
and functions described below.


### main.c 

In this file is the main that will execute all our functions. The prototype
of our main function is the following:

int main(int argc \__ attribute \__((unused)), char *argv[]  \__ attribute __ ((unused)));

### shell.c

In this file you will find the functions in charge of translating the commands 
written by the user:

- The ** split_input ** function separates the words every time it finds a space 
and returns the number of words it found.

- The ** quit_spaces ** function receives the words returned by the split_input 
function and checks if saved unnecessary spaces and removes.

- The ** existence ** function checks if the word the user entered is a system 
function, if not, it returns "command not found".

- The ** call_fork ** function creates a child function where the function that 
the user wants will be executed.

### entorno.c

In this file you will find the functions that together create and return a 
linked list with the PATH directories to check the existence of the commands 
written by the user:

- The ** path_directories ** function creates a linked list of the folders in 
the PATH.

- The ** _getenv ** function takes care of copying the PATH folders one by one.

- The ** add_node ** function adds each folder in the PATH to a new node.

- The ** free_list ** function frees the memory that we have allocated to the 
linked list of directories.

### build_ins.c

In this file you will find the functions to know what to do in case the user 
types "exit" or "env":

- The ** build_ins ** function compares if what the user entered are the words 
"exit" or "env", if it does not return 0.

- The ** n_exit ** function frees the space that was reserved for the linked 
list of our PATH and takes us out of the shell.

- The ** env ** function prints the folders in the local environment one by one.

---------------

# Function flow
