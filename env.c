#include <unistd.h>
#include "main.h"

/**
 * handle_env_command - Handles the env command
 *
 * Description: Prints out the current environment variables.
 */
void handle_env_command(void)
{
	char **environ;
	char **env;

	environ = __environ;
	env = environ; /* environ is defined in unistd.h */

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
