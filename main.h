#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>


void execmd(char **argv);
void execute_command(char **argv);
char *my_getline(void);
int is_builtin_command(char *command);
void execmd(char **argv);

void handle_exit();

void handle_exit_command(char *command);
void handle_env_command(void);
int tokenize(const char *command, char *args[]);
void handle_exit_arg(char *command);

#endif
