#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt(void);
void read_command(char *command);
void execute_command(char *command);
void execmd(char *command);

#endif
