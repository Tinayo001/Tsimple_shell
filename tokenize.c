#include "main.h"

#define MAX_ARGS 20
/**
 * tokenize - function that tokenizes commands
 * @command: command to check
 * @args: arguments vector
 */

void tokenize(char *command, char **args)
{
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL && i < MAX_ARGS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
