#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		read_command(command);
		execute_command(command);
	}

	return (0);
}
