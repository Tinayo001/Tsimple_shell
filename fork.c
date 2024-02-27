#include "fork.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - executes commands
 * @argv: pointer to pointer of arguments
 */
void execute_command(char **argv)
{
	/* Declaration moved to the beginning of the function */
	int status;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
