#include <stdbool.h>
#include <stdio.h>
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
		parse_command(command, args);
		execute_command(args);
	}

	return (0);
}
