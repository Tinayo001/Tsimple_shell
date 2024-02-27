#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_environmen - function that hanndles the environment
 * @command: command to be checked
 */
void handle_environmen(char *command)
{
	char *operation = strtok(command, " ");
	char *variable = strtok(NULL, " ");
	char *value = strtok(NULL, " ");

	if (strcmp(operation, "setenv") == 0)
	{
		if (variable != NULL && value != NULL)
		{
			if (setenv(variable, value, 1) == -1)
			{
				perror("setenv");
			}
		}
		else
		{
			printf("Usage: setenv [variable] [value]\n");
		}
	}
	else if (strcmp(operation, "getenv") == 0)
	{
		if (variable != NULL)
		{
			char *env_value = getenv(variable);

			if (env_value == NULL)
			{
				printf("%s=%s\n", variable, env_value);
			}
			else
			{
				printf("Environment variable '%s' not found.\n", variable);
			}
		}
		else
		{
			printf("Usage: getenv [variable]\n");
		}
	}
	else if (strcmp(operation, "printfenv") == 0)
	{
		extern char **environ;
		char **env;

		for (env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env);
		}
	}
	else
	{
		printf("Unkown environment operation: %s\n", operation);
	}
}

