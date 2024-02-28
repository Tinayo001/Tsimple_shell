#include "main.h"

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
    printf("#Tshell$ ");
}

/**
 * read_command - Read a command from the user.
 * @command: Buffer to store the command.
 */
void read_command(char *command)
{
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    if (feof(stdin))
    {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    command[strcspn(command, "\n")] = '\0'; /* Remove newline character */
}
