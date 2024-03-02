#include "shell.h"

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
}
