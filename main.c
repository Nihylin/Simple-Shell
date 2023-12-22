#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * main - main function for shell
 * @argc: argument count
 * @argv: argument values
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	int exitStatus = 1, exitCode;
	char *line = NULL, *input = NULL;
	size_t bufsize = 0;
	ssize_t string;

	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	while (1)
	{
		/* Check if the file descriptor 0 is associated with a terminal */
		if (isatty(0))
			printf("($) ");

		string = getline(&line, &bufsize, stdin);

		/* Check if getline returned -1 */
		if (string == -1)
			break;

		input = trim(line);
		
		/* Check if input starts with "exit" */
		if (strncmp(input, "exit", 4) == 0)
		{
			free(line);

			/* Check if exit code is provided */
			if (sscanf(input, "exit %d", &exitCode) == 1)
				exit(exitCode);
			else
				exit(0);
		}

		exitStatus = execute(input);

		if (exitStatus == -1)
		{
			printf("%s: not found\n", input);
			continue;
		}
	}

	free(line);
	return (0);
}
