#include "main.h"

/**
 * execmd - Execute a shell command with arguments
 * @command: The command to execute
 */
void execmd(char *command)
{
	pid_t pid;
	int status;
	char *args[MAX_COMMAND_LENGTH];
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL && i < MAX_COMMAND_LENGTH - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (strcmp(args[0], "exit") == 0)
	{
		printf("Exiting shell...\n");
		exit(EXIT_SUCCESS);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			/* Command not found, display error message */
			perror("execvp");
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
