#include "shell.h"
#include <unistd.h>  /* for write */
#include <stdlib.h>  /* for _exit */

/**
 * display_prompt - Displays the prompt for user input.
 */
void display_prompt(void)
{
	char prompt[] = "Tshell$ ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1); /* Write prompt to stdout */
}

/**
 * read_command - Reads a command from the user.
 * @command: Buffer to store the command.
 */
void read_command(char *command)
{
	ssize_t bytes_read;

	bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
	if (bytes_read == -1)
	{
		perror("read"); /* Print error message */
		_exit(EXIT_FAILURE); /* Exit the shell with failure status */
	}
	else if (bytes_read == 0)
	{
		/* End of file condition */
		write(STDOUT_FILENO, "\n", 1); /* Print newline */
		_exit(EXIT_SUCCESS); /* Exit the shell with success status */
	}

	command[bytes_read - 1] = '\0'; /* Remove newline character */
}
