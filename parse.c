#include "shell.h"

/**
 * parse_command - Parse the command into arguments
 * @command: The command string
 * @args: An array of strings to store the parsed arguments
 */
void parse_command(char *command, char *args[])
{
	args[0] = command;
	args[1] = NULL;
}
