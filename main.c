#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char *full_command = NULL, *copy_command = NULL;
	size_t n = 0;
	ssize_t tchars_read;
	char *token;
	const char *delim = "\n";
	char **argv;
	int i = 0;
	int numb_tokens = 0;

	printf("$ ");

	tchars_read = getline(&full_command, &n, stdin);

	if (tchars_read == -1)
	{
		printf("Exiting shell...\n");
		return (-1);
	}

	copy_command = malloc(sizeof(char) * tchars_read);

	if (copy_command == NULL)
	{
		perror("tsh: memory allocation error");
		free(full_command);
		return (-1);
	}
	strcpy(copy_command, full_command);
	token = strtok(full_command, delim);



	while (token != NULL)
	{
		numb_tokens++;
		token = strtok(NULL, delim);
	}
	numb_tokens++;

	argv = malloc(sizeof(char *) * numb_tokens);
	
	if (argv == NULL)
	{
		perror("tsh: memory allocation error");
		free(full_command);
		free(copy_command);
		return (-1);
	}
	token = strtok(copy_command, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	for (i = 0; i < numb_tokens; i++)
	{
		free(argv[i]);
	}

	free(argv);
	free(full_command);
	free(copy_command);

	return (0);
}
