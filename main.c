#include "main.h"
#include "fork.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "execmd.h"

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
void deallocate_memory_for_file(char *file_data)
{
	free(file_data);
}
void free_memory(char *lineptr)
{
	free(lineptr);
}
void handle_exit()
{
        printf("Exiting shell...\n");
        exit(EXIT_SUCCESS);
}

/**
 * main - entry point
 * @ac: number of arguments
 * @argv: argument vector
 * Return: 0 (Success)
 */

int main(int ac, char **argv)
{
	char *prompt = "(Tshell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t getline_result;
	const char *delim = " \n";
	char *token;
	int numb_tokens = 0;
	int  i;

	(void)ac;
	(void)argv;

	while (1)
	{
		printf("%s", prompt);
		getline_result = getline(&lineptr, &n, stdin);

		if (getline_result == -1)
		{
			perror("Exiting shell....\n");
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * getline_result);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr, "\t\n");

		while (token != NULL)
		{
			printf("Token: %s\n", token);
			token = strtok(NULL, " \t\n");
		}
		numb_tokens++;

		argv = malloc(sizeof(char *) * numb_tokens);
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		execmd(argv);
		for (i = 0; i < numb_tokens; i++)
		{
			free(argv[i]);
		}
		free(argv);

		deallocate_memory_for_file(lineptr_copy);
	}
	free_memory(lineptr);

	return (0);
}
