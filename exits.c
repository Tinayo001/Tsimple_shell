#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_exit_command - Handles the exit command
 * @command: The command entered by the user
 *
 * Description: If the command is "exit", prints a message
 * indicating the shell is exiting and terminates the program.
 */
void handle_exit_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		printf("Exiting shell...\n");
		exit(EXIT_SUCCESS);
	}
}
