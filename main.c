#include "main.h"

/**
 * main - Entry point of the simple shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    char command[MAX_COMMAND_LENGTH];

    if (argc == 1)
    {
        /* Interactive mode */
        while (1)
        {
            display_prompt();
            read_command(command);
            if (strcmp(command, "exit\n") == 0)
            {
                printf("Exiting shell...\n");
                break;
            }
            execmd(command);
        }
    }
    else if (argc == 2)
    {
        /* Non-interactive mode */
        FILE *file = fopen(argv[1], "r");
        if (file == NULL)
        {
            perror("Error opening file");
            return (EXIT_FAILURE);
        }

        while (fgets(command, MAX_COMMAND_LENGTH, file) != NULL)
        {
            execmd(command);
        }

        fclose(file);
    }
    else
    {
        fprintf(stderr, "Usage: %s [file]\n", argv[0]);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
