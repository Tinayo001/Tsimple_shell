#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_COMMAND_LENGTH 100

void parse_and_execute_command(char *command);
/**
 * parse_and_execute_main - Main function to parse and execute commands
 *
 * This function continuously prompts the user for input commands,
 * executes them, and repeats until the user enters exit
 *
 * Return: 0 (Success)
 */
int parse_and_execute_main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("Tshell) $ ");
		fgets(command, sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		parse_and_execute_command(command);
	}
	return (EXIT_SUCCESS);
}
/**
 * parse_and_execute_command - function that parses and executes a command
 * @command: command to be checked
 * Return: 0 (Success)
 */

void parse_and_execute_command(char *command)
{
	char *args[MAX_ARGS + 1];
	char *token;
	int arg_count = 0;
	pid_t pid;
	int status;

	token = strtok(command, " ");
	while (token != NULL && arg_count < MAX_ARGS)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (arg_count > 0)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execvp(args[9], args) == -1)
			{
				perror("execp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
}
