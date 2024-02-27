#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_exit_arg - Handles the exit command with argument
 * @command: The command entered by the user
 *
 * Description: If the command is "exit ", extracts the status integer,
 * prints debugging information, and exits the shell with the extracted status.
 */
void handle_exit_arg(char *command)
{
	int status;

	if (strncmp(command, "exit ", 5) == 0)
	{
		printf("Handling exit command with argument: %s\n", command); /* Debugging statement */

		status = atoi(command + 5);
		printf("Extracted status: %d\n", status); /* Debugging statement */

		exit(status);
	}
}
