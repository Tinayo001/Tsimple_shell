#include "main.h"
#include "execmd.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * execmd - executes a command
 * @argv: pointer to a pointer of arguments
 */

void execmd(char **argv)
{
        if (execvp(argv[0], argv) == -1)
        {
                perror("execvp");
                exit(EXIT_FAILURE);
        }
}
