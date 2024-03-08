#include "shell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

		setenv("PATH", "/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin", 1);

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
								break;
						}
						else
						{
								perror("fgets");
								exit(EXIT_FAILURE);
						}
				}

				command[strcspn(command, "\n")] = '\0';


				if (strcmp(command, "exit") == 0)
				{
						break;
				}

				parse_command(command, args);
				execute_command(args);
		}

		return (0);
}
