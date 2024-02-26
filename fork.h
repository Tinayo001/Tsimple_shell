#ifndef FORK_H
#define FORK_H

void execute_command(char **argv);
void fork_and_exec(char **argv);
int search_command(char *command);

#endif
