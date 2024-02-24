#include "main.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
/**
 * my_getline - function that reads characters in a string
 * Return: line (Success)
 */

char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int position;
	static int chars_read;
	char *line = &buffer[position];

	if (position == 0)
	{
		chars_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

		if (chars_read <= 0)
		{
			return (NULL);
		}
	}

	while (position < chars_read && buffer[position] != '\n')
	{
		position++;
	}
	buffer[position] = '\0';
	position++;

	if (position >= chars_read)
	{
		position = 0;
	}
	return (line);
}
