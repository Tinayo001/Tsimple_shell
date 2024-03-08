#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * execute_command_with_path - Executes a command with PATH resolution
 * @args: Array of strings containing the command and its arguments
 */
void execute_command_with_path(char *args[])
{
	char *path_str = getenv("PATH");
	char *token;
	char command_path[MAX_COMMAND_LENGTH];

	if (path_str == NULL)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		return;
	}

	token = strtok(path_str, ":");
	while (token != NULL)
	{
		sprintf(command_path, "%s/%s", token, args[0]);
		if (access(command_path, X_OK) == 0)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execve(command_path, args, NULL) == -1)
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
				return;
			}
		}
		token = strtok(NULL, ":");
	}

	fprintf(stderr, "Command not found: %s\n", args[0]);
}
