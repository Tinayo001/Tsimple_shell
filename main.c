#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		display_prompt();
		read_command(command);
		parse_command(command, args);
		execute_command(args);
	}

	return (0);
}
