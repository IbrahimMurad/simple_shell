#include "main.h"

/**
 * get_argv - converts a string into an array of tokens
 * @av: an array of strings in which the tokens will be stored
 * @buf: the string to read from
 *
 * Return: a pointer to av
*/

char **get_argv(char *av[], char *buf)
{
	char **tokens;
	int i = 0;

	tokens = _strtok(buf, " ");
	while (tokens[i])
	{
		av[i] = tokens[i];
		i++;
	}
	av[i] = tokens[i];
	free(tokens);
	return (av);
}
