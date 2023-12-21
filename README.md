# <p align="center">SIMPLE_SHELL</p>

    
## Description
This project consists of building a C program to serve as a shell interface that accepts user commands then executes each command in a separate process. Your implementation will support input and output redirection.Completing this project will involve using the UNIX fork(), execute() and wait() system calls and can be completed on Linux system.

## Requirements
### General

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded

### About Simple_Shell
## Flowchart





## File Usage

| Name File | Description |
| -------- | -------- |
| .gitignore   | File used for ignore some file when whe push into GitHub.   |
| main.h   | Header File. Lists the standard libraries used and integrates the prototypes we need to run the program properly. If one. If a necessary library or a used prototyp is missing in the file, the program will not be able to compile and therefore will not be executed.    |
| main.c   | Creates an infinit loop which displays a prompt and reads the input typed by the user.The shell will behave differently depending on what the user types: **exit**: the shell exits. **An existing command** (e.g. `ls`, `pwd`), the shell executes it and returns to the beginning of the loop. **The path of an existing command** (e.g. `/bin/ls`), the shell executes the command and returns to the start of the loop. **The command does not exist**, the shell displays an error message
| functions.c    | This file encompasses several integral functions utilized throughout the entire program. The execute() function plays a pivotal role by breaking down each word from user input, determining the command's path, and subsequently initiating a child process for execution. In the event that the command does not exist, the function gracefully handles the error.The tokenize() function serves to isolate individual words from user input, seamlessly incorporating them into a string array. This facilitates access to each word independently, and the function returns the generated array of strings.Furthermore,the trim() function modifies the string in place, removing leading and trailing spaces, then returns a pointer to the start of the resulting string.Lastly, the getPath() function proves instrumental in retrieving the complete path of a given command. It returns NULL if the specified command is not found..  |
| man_1_simple_shell    | File that recreates a man page and explains how the shell we've created works.    |

## Compilation

You can compile your program using the following command :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```


# <p align="">Testing</p>
  
Shell should work like this in interactive mode:

```

$ ./hsh

($) /bin/ls

AUTHORS
README.md
functions.c
hsh
main.c
main.h
man_1_simple_shell
testadvanced12
testadvanced12.c

($)

($)
 exit

$

```

# <p align="">MAN PAGE</p>
  
    
```
  man ./man_1_simple_shell
```
# <p align="">Exit</p>
  

    
hsh  returns  the  exit status of the last command executed, unless asyntax error occurs, with zero indicating success and non-zero  indicating failure.

## Bugs

No  known bugs.

## 🙇 Authors
#### Philippe  Wanquetin
- Github: [https://github.com/Nihylin] 
### Carmen Leila MUGISHA
- Github: [https://github.com/CarmenLeila]
### Alexis Billemont
- Github:[https://github.com/git-alexis]

License
- « Copyright © <22/12/2023>, <copyright Philippe Wanquetin & Carmen Leila MUGISHA & Alexis Billemont>