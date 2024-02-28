#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * read_command - Read a command from the user.
 * @command: Buffer to store the command.
 */
void read_command(char *command)
{
	fgets(command, MAX_COMMAND_LENGTH, stdin);
	if (feof(stdin))
	{
		printf("\n");  /* Print a newline if end of file (Ctrl+D) is encountered */
		exit(EXIT_SUCCESS);
	}
	command[strcspn(command, "\n")] = '\0'; /* Remove newline character */
}

/**
 * execute_command - Execute the given command.
 * @command: The command to execute.
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
			perror(command);
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
