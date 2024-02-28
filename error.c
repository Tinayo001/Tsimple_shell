#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * handle_error - Print an error message and exit the program.
 * @msg: The error message to print.
 */
void handle_error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
