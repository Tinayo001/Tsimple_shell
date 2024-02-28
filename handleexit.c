#include "main.h"

/**
 * handle_exit_arg - function that handles exit of a command
 * @command: command to be checked
 */

void handle_exit_arg(char *command)
{
        char *arg = strtok(command, " ");

        arg = strtok(NULL, " ");

        if (arg != NULL)
        {
                exit(atoi(arg));
        }
        else
        {
                printf("Usage: exit [status]\n");
        }
}
   
