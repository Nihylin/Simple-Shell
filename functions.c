#include "main.h"

/**
 * _isspace - checks if character is a space
 * @c: character to check
 * Return: 1 if true, 0 if false
*/

int _isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
	{
		return (1);
	}
	return (0);
}

/**
 * trim - removes leading and trailing whitespace from string
 * @str: string to trim
 * Return: trimmed string
*/

char *trim(char *str)
{
	/* Initialize end pointer to the end of the string */
	char *end = str + strlen(str) - 1;

	/* Skip leading whitespace */
	while (_isspace(*str))
	{
		str++;
	}

	if (*str == 0)
	{
		return (str);
	}

	/* Skip trailing whitespace */
	while (end > str && _isspace(*end))
	{
		end--;
	}

	end[1] = '\0';

	return (str);
}

/**
 * tokenize - tokenizes a string
 * @input: string to tokenize
 * Return: tokenized string
*/

char **tokenize(char *input)
{
	char **tokens = malloc(64 * sizeof(char *));
	char *token;
	int i = 0;

	if (!tokens)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	/* Get the first token */
	token = strtok(input, " \t\r\n\a");

	/* Loop over all tokens */
	while (token != NULL)
	{
		/* Add the current token to the tokens array */
		tokens[i] = token;
		i++;

		/* Get the next token */
		token = strtok(NULL, " \t\r\n\a");
	}

	/* Null-terminate the tokens array */
	tokens[i] = NULL;
	return (tokens);
}

/**
 * getPath - gets the path of a command
 * @input: command to get path of
 * Return: path of command
*/

char *getPath(char *input)
{
	char *result, *pathEnv, *pathEnvCopy, *token, fullPath[1024];

	/* Get the PATH environment variable */
	pathEnv = getenv("PATH");

	if (pathEnv == NULL)
	{
		return (NULL);
	}

	pathEnvCopy = strdup(pathEnv);

	/* Get the first directory in the PATH */
	token = strtok(pathEnvCopy, ":");

	/* Loop over all directories in the PATH */
	while (token)
	{
		/* Construct the full path to the command */
		sprintf(fullPath, "%s/%s", token, input);

		/* If the command exists and is executable, return its full path */
		if (access(fullPath, F_OK | X_OK) == 0)
		{
			result = strdup(fullPath);
			free(pathEnvCopy);
			return (result);
		}

		/* Get the next directory in the PATH */
		token = strtok(NULL, ":");
	}

	/* If the command was not found in the PATH, return NULL */
	free(pathEnvCopy);
	return (NULL);
}

/**
 * execute - executes a command
 * @input: arguments to execute
 * Return: exit status
*/

int execute(char *input)
{
	int status, exitStatus = 0;
	char **args, *path;
	pid_t pid;

	/* Tokenize the input */
	args = tokenize(input);

	if (args == NULL)
	{
		free(args);
		return (-1);
	}

	/* If the command starts with '/' or '.', it is a full path */
	if (input[0] == '/' || input[0] == '.')
	{
		path = strdup(input);
	}
	else
		path = getPath(args[0]);

	/* If getting the path failed, return -1 */
	if (path == NULL)
	{
		free(args);
		return (-1);
	}

	/* Fork a new process */
	pid = fork();

	if (pid < 0)
	{
		free(args);
		free(path);
		return (-1);
	}
	else if (pid == 0)
	{
		/* If this is the child process, execute the command */
		exitStatus = execve(path, args, environ);
	}
	else
	{
		/* If this is the parent process, wait for the child to finish */
		exitStatus = wait(&status);
		free(args);
		free(path);
	}

	return (exitStatus);
}
