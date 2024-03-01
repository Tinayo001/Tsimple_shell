#include "shell.h"

/**
 * read_command - Read a command from the user
 * @command: Pointer to a buffer where the command will be stored
 */
void read_command(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}

	command[strcspn(command, "\n")] = '\0';
}
