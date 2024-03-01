# Simple Shell

## Description
Simple Shell is a basic UNIX command line interpreter developed as part of the ALX School curriculum. It provides a minimalistic shell environment for users to execute commands.

## Features
- Displays a prompt for user input.
- Reads commands entered by the user.
- Executes commands using `execve`.
- Handles basic error conditions.

## Usage
1. Clone the repository:

git clone <repository-url>

2. Compile the shell:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


3. Run the shell:

./hsh

4. Enter commands at the prompt and press Enter to execute.

## Supported Commands
- Basic shell commands such as `ls`, `pwd`, `cd`, etc.

## Files
- `shell.h`: Header file containing function prototypes and macros.
- `prompt.c`: Contains functions for displaying the prompt and reading user input.
- `execute.c`: Contains the function for executing commands.
- `main.c`: Entry point of the shell program.
- `*.c`: Other source files containing additional functions.
- `README.md`: This file, contains information about the project.

## Authors
- [Olayinka Alawode](https://github.com/kepo402)
- [ELIJAH TINAYO](https://github.com/Tinayo001)
