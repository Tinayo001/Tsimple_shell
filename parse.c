#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * parse_command - Parse the command into arguments
 * @command: The command string
 * @args: An array of strings to store the parsed arguments
 */
void parse_command(char *command, char *args[])
{
        const char delim[] = " \t\n";
        char *token;
        int i = 0;

        token = strtok(command, delim);
        while (token != NULL && i < MAX_ARGS - 1)
        {
                args[i++] = token;
                token = strtok(NULL, delim);
        }
        args[i] = NULL;

        
        if (args[0][0] != '/') {
                char *path_env = getenv("PATH");
                char *path = strdup(path_env);
                char *dir = strtok(path, ":");
                while (dir != NULL) {
                        char command_path[MAX_COMMAND_LENGTH];
                        snprintf(command_path, MAX_COMMAND_LENGTH, "%s/%s", dir, args[0]);
                        if (access(command_path, X_OK) == 0) {
                                
                                strcpy(args[0], command_path);
                                free(path);
                                return;
                        }
                        dir = strtok(NULL, ":");
                }
                
                fprintf(stderr, "Command not found: %s\n", args[0]);
                free(path);
                exit(EXIT_FAILURE);
        }
}
