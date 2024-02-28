#include "main.h"

/**
 * execute_command - Execute a shell command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execlp(command, command, NULL) == -1)
		{
			/* Command not found, display error message */
			fprintf(stderr, "%s: command not found\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
