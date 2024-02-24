#include "main.h"

int is_builtin_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		return(1);
	}
	return (0);
}
void execute_builtin_command(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
