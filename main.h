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
extern char **environ;
void handle_exit(void);
void parse_and_execute_command(char *command);
void handle_exit_command(char *command);
void handle_env_command(void);
void handle_exit_arg(char *command);
void handle_environment(char *command);
void handle_error(const char *msg);
int parse_and_execute_main(void);

#endif
