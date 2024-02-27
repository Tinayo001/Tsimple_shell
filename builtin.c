#include "main.h"

/**
 * is_builtin_command - command that checks on builtins
 * @command: The command to check.
 * Return: 1 if the command is built-in command, 0 otherwise
 */

int is_builtin_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		return (1);
	}
	return (0);
}
/**
 * execute_builtin_command - function that executes builtins
 * @args: The arguments for the command.
 * Return: 0 on success, -1 on failure
 */

void execute_builtin_command(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
