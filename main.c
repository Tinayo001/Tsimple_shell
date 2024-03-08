#include "shell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* Main function */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	bool interactive = isatty(STDIN_FILENO);
	int last_command_status = 0;

	setenv("PATH", "/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin", 1);

	while (1)
	{
		pid_t pid;

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

		if (strcmp(args[0], "exit") == 0)
		{
			if (args[1] == NULL)
				return (last_command_status);
			else
				return (atoi(args[1]));
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
			last_command_status = WIFEXITED(status) ? WEXITSTATUS(status) : 127;
		}
	}

	return (0);
}
