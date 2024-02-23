#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "(Tshell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t getline_result;
	const char *delim = " \n";
	char *token;
	int numb_tokens = 0;
	int  i;

	(void)ac; (void)argv;

	while (1)
	{
		printf("%s", prompt);
		getline_result = getline(&lineptr, &n, stdin);

		if (getline_result == -1)
		{
			perror("Exiting shell....\n");
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * getline_result);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr, "\t\n");

		while (token != NULL)
		{
			printf("Token: %s\n", token);
			token = strtok(NULL, " \t\n");
		}
		numb_tokens++;

		argv = malloc(sizeof(char *) * numb_tokens);
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		execmd(argv);
	}

	free(lineptr);
	lineptr = NULL;

	return (0);
}
