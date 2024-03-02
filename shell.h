#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64

void display_prompt(void);
void read_command(char *command);
void parse_command(char *command, char *args[]);
void execute_command(char *args[]);

#endif /* SHELL_H */
