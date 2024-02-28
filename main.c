#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_COMMAND_LENGTH 100

void tokenize(char *command, char **args);
void handle_exit_arg(char *command);
void handle_environment(char *command);

/**
 * allocate_memory_for_file - function that allocates memory to a file
 * @size: size of memory to allocate
 * Return: returns file_data on success
 */

char *allocate_memory_for_file(size_t size)
{
	char *file_data = malloc(size);

	if (file_data == NULL)
	{
		perror("Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	return (file_data);
}
/**
 * deallocate_memory_for_file - function that dealloactes memory on a file
 * @file_data: file to check
 */

void deallocate_memory_for_file(char *file_data)
{
	free(file_data);
}
/**
 * free_memory - function that frees memory
 * @lineptr: pointer to check
 */

void free_memory(char *lineptr)
{
	free(lineptr);
}
/**
 * handle_exit - function that handles file exit
 * Return: 0 (Success)
 */

void handle_exit(void)
{
	printf("\tExiting shell...\n");
	exit(EXIT_SUCCESS);
}

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t pid;
	char *args[MAX_ARGS + 1];
	int status;

	while (1)
	{
		printf("(Tshell) $ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		command[MAX_COMMAND_LENGTH - 1] = '\0';

		if (strncmp(command, "exit ", strlen("exit ")) == 0)
		{
			printf("Exiting shell...\n");
			handle_exit_arg(command);
			break;
		}
		tokenize(command, args);
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execvp(args[0], args);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				printf("Exit status: %d\n", WEXITSTATUS(status));
			}
		}
	}
	return (EXIT_SUCCESS);
}
