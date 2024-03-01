#include "shell.h"
#include <stdio.h>

/**
 * display_prompt - Displays the prompt for user input.
 */
void display_prompt(void)
{
	printf("Tshell$ ");
	fflush(stdout);
}

/**
 * read_command - Reads a command from the user.
 * @command: Buffer to store the command.
 */
void read_command(char *command)
{
	fgets(command, MAX_COMMAND_LENGTH, stdin);
	if (feof(stdin))
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	command[strcspn(command, "\n")] = '\0';
}
