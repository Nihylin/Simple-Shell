<p align="center">
	<img src="https://assets-global.website-files.com/64107f65f30b69371e3d6bfa/6480d9b63a806a1b35fec007_Holberton-p-500.png" style="margin:50px;"/>
</p>

# <p align="center">SIMPLE_SHELL</p>
This project consists of building a C program to serve as a shell interface that accepts user commands then executes each command in a separate process. Your implementation will support input and output redirection. Completing this project will involve using the UNIX fork(), execute() and wait() system calls and can be completed on Linux system.

## ⚠️ Requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded

## 🧑‍💻 Installation
Clone the Github repository using this command:
```
git clone https://github.com/Nihylin/holbertonschool-simple_shell.git
```

## ▶️ Compilation
You can compile your program using the following command :
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## ⚙️ Testing
Shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
AUTHORS README.md LICENSE.md functions.c hsh main.c main.h man_1_simple_shell
($)
($) exit
$
```
And like this in non-interactive mode:
```
$ echo "qwerty" | ./hsh
qwerty: not found
$ echo "/bin/ls" | ./hsh
AUTHORS README.md LICENSE.md functions.c hsh main.c main.h man_1_simple_shell
```

## ⛔️ Exit
When you want to exit the shell, you can use one of the following methods:

1: Type the command "exit" (followed by a specified Exit Status or not)

2: Press Ctrl + D

hsh returns the exit status of the last command executed, unless a syntax error occurs, with zero indicating success and non-zero indicating failure.

## ⬇️ Flowchart
![](https://i.imgur.com/8MgtiU6.jpg)

## 🗃️ File Usage
| Name File | Description |
| -------- | -------- |
| .gitignore | File used to ignore unnecessary files and avoiding pushing them on the GitHub repository. |
| AUTHORS | This is a text file that lists the names and contact details of the people who have contributed to the project. |
| README.md | The file you are currently reading ! |
| LICENSE.md | This file is a document that contains the licensing details for the Simple Shell software project. It informs users about their legal rights and restrictions when using, modifying, or distributing the software. |
| main.h | Header File. Lists the standard libraries used and integrates the prototypes we need to run the program properly. If a necessary library or a used prototyp is missing in the file, the program will not be able to compile and therefore will not be executed. |
| main.c | The main.c file contains the main function for a shell program. It reads user input, trims leading and trailing whitespaces, and executes the command. It also handles the 'exit' command with an optional exit code. If the command is not found, it prints an error message and continues to the next iteration.
| functions.c | This file encompasses several integral functions utilized throughout the entire program:<ul style="margin-top:20px"><li>The _isspace function in C checks if a given character (represented by its ASCII value) is a whitespace character. It returns 1 for whitespace characters and 0 otherwise.</li><li>The trim function in C removes leading and trailing whitespace characters from a given string. It returns the trimmed string.</li><li>The tokenize function splits a given string into tokens based on specified delimiters (spaces, tabs, newlines, etc.). It returns an array of these tokens.</li><li>The getPath function retrieves the full path of a given command by searching through the system's PATH environment variable. It returns the full path if found, or NULL if the command is not found in any of the directories listed in PATH.</li><li>The execute function takes a command as input, tokenizes it into arguments, determines the full path of the command, and then executes it using a child process. It returns the exit status of the command.</li></ul>|| man_1_simple_shell | File that recreates a man page and explains how the shell we've created works. |
| man_1_simple_shell | File that contains software documentations and gives the user comprehensive details about commands, system calls, libraries... |

## 📄 Man page
A man page is a form of software documentation. It provides comprehensive details about commands, system calls, libraries, and other aspects of the system. Users can access these man pages using the man command followed by the name of the command or library they want to learn about, as this one for the simple shell program :
```
man ./man_1_simple_shell
```

## 🪰 Bugs
<ul><li>Some unauthorized functions are used in this program: strdup, getenv, sscanf.</li><li>When using an empty command, the program prints ": not found". It should print nothing.</li></ul>

## ✏️ Authors
### Philippe Wanquetin
- Github: [@nihylin](https://github.com/nihylin)
### Carmen Leila MUGISHA
- Github: [@CarmenLeila](https://github.com/CarmenLeila)
### Alexis Billemont
- Github:[@git-alexis](https://github.com/git-alexis)