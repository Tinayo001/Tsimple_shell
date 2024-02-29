#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[] = {command, NULL};
	pid_t pid;

	pid = fork();

	while (1)
	{
		printf("simple_shell$ ");
		fflush(stdout);


		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\nExiting shell...\n");
			break;
		}
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(command, args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
