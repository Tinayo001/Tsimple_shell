#include "shell.h"
#include <string.h>

/**
 * execute_command - Executes a command
 * @args: Array of strings containing the command and its arguments
 */
void execute_command(char *args[])
{
	pid_t pid;

	if (args[0] == NULL || strcmp(args[0], "") == 0)
	{
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
