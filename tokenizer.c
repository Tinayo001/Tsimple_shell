#include "main.h"

#define MAX_ARGS 11 /* Maximum number of arguments (10 + NULL) */
#define DELIMITERS " \t\n" /* Delimiters for tokenizing */

/**
 * tokenize - Tokenize a command string into arguments.
 *
 * This function tokenizes a command string into arguments based on the
 * specified delimiters.
 *
 * @command: The command string to tokenize.
 * @args: An array to store the tokenized arguments.
 *
 * Return: The number of arguments tokenized.
 */
int tokenize(const char *command, char *args[])
{
	int argc = 0;
	char *ptr = (char *)command; /* Pointer to iterate through the command string */

	/* Skip leading whitespace characters */
	while (*ptr && strchr(DELIMITERS, *ptr))
		ptr++;

	/* Tokenize the command string */
	while (*ptr && argc < MAX_ARGS - 1)
	{
		/* Store the address of the current token */
		args[argc++] = ptr;

		/* Move the pointer to the next token */
		while (*ptr && !strchr(DELIMITERS, *ptr))
			ptr++;

		/* Replace the delimiter with NULL character to terminate the token */
		if (*ptr)
			*ptr++ = '\0';

		/* Skip trailing whitespace characters */
		while (*ptr && strchr(DELIMITERS, *ptr))
			ptr++;
	}

	/* Null-terminate the argument list */
	args[argc] = NULL;

	return (argc);
}
