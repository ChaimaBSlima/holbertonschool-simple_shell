<h1><p align="center"> A simple shell </h1></p></font>

The simple shell is a simple command line prompt that takes the most basics of commands that are present in the bash shell and runs them. This shell was built as a project for Holberton School.

`the shell` works like the bash and other basic shells.

The shell works by being compiled using GCC 4.8.5 compiler or later versions. The shell can compile using `gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o shell`.


# Example of how to launch the shell after compiling
`./shell`

* Output: prompt to terminal: `$ 

# Syntax
The shell works by using commands given by the user input. The shell commands take in the following syntax: `command name {arguments}`. The shell executes a command after it is written by user using the command followed by the arguments.

`cat simple_shell.h`
The above example takes in a command by the user followed with the arguments. In this case the command is `cat` (to view file without opening file) followed by argument the file name in this case `simple_shell.h`.

For more information on cat, you can use the `man` command which will show a manual of the given command or any command you wish to know more information on. It contains system calls, libraries and other important files.

The shell also contains two builtins which are commands that are within the shell itself. The two builtins are `exit` and `env`. 

# Compilation
All files will be compiled with the following: `$ gcc -Wall -Werror -Wextra -pedantic *.c`

# List of useful commands
| Commands |  Description                |
| :-------- |  :------------------------- |
| `cat` | prints and concatenates files to the standard output.|
| `cp` | copies a file into another file.|
| `grep` | helps to search for a file in a specific pattern.|
| `less` | will let you go backward and forward in the files.|
| `ls` | will list all files and directories in current working directory.|
| `mv` | helps to move one file into another file.|
| `pwd` | given you the current working directory.|

# Builtins
|Builtins  |  Description                |
| :-------- |  :------------------------- |
|`env` | The env command is a command that tells the shell program to display all of the environment variables with their values. It is a    way to access those values through the shell.|
| `exit` | If you wish to exit out of the shell the user can use the builtin `exit`.|

# Exiting commands and the shell
To exit out of a command or process the user can use `ctrl c`. `Control c` stops a process and causes it to abort.
The user can also utilize the command `ctrl D` which will just exit. When the command `ctrl D` is used an exit status of 0 is given. Using exit, you can input its exit status or it is defaulted to the status of the last command executed.

# Files
| Files |  Description                |
| :-------- |  :------------------------- |
| `simple_shell.h` | it's the header file that contain the prototypes of all the functions and all the useful libraries .|
| `00-exec.c` | contain the main function : The entry point of the code. |
| `01-execute_commands.c` | contain the three functions that handeles the typed command which are : read_line, read_command and execute_command.  |
| `02-frees_functions.c` | contain a function that frees a 2D array which is: freestring.|
|`03-getenv_function.c` |contain a function that takes the value of a key from the environ .|
|`04-getpath_function.c` |contain a function that split the value of the PATH (as a key) to find the right path of the command.|
|`05-errors_functions.c` |contain 2 error functions which are: PrintNotFoundError, PrintIllegalNumberError.|
|`06-functions_to_use.c` |contain  some useful functions like : ConvertIntToStr,reverse_str .|
|`07-functions_builtin.c` |contain the 2 new commands exit and env in builtin functions: exit_shell, print_env. |
|`08-my_strtok.c` |contain my_strtok function that do the same exact job as strtok function. |



# Authors

- [@ChaimaBSlima](https://github.com/ChaimaBSlima)


# 🚀 About Me
I'm a Machine Learning developer...

