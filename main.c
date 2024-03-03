#include "shell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	bool interactive = isatty(STDIN_FILENO);
	char *trimmed_command;
	size_t len;

	while (1)
	{
		if (interactive)
			display_prompt();

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				if (interactive)
					write(STDOUT_FILENO, "\n", 1);
				continue;
			}
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
		}

		trimmed_command = command;
		while (*trimmed_command && strchr(" \t\n", *trimmed_command))
			trimmed_command++;
		len = strlen(trimmed_command);
		while (len > 0 && strchr(" \t\n", trimmed_command[len - 1]))
			trimmed_command[--len] = '\0';

		if (strlen(trimmed_command) == 0)
			continue;

		parse_command(trimmed_command, args);
		execute_command(args);
	}

	return (0);
}
