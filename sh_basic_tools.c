#include "main.h"


/**
 * _getline - gets a line from stream
 * (a line is terminated by a new line or EOF)
 * @buf: a buffer to store the line
 * @fd: the file descriptor to the file to read from
 *
 * Return: the number of read bytes or -1 on fail
 * or 0 if its EOF
*/

ssize_t _getline(char *buf, int fd)
{
	ssize_t numOfBytes;

	numOfBytes = read(fd, buf, 4096);
	buf[numOfBytes - 1] = '\0';
	return (numOfBytes);
}

/**
 * initial_tokens - allocate the required memory for the tokens
 * @tokens: a pointer to the tokens
 *
 * Return: a pointer to the tokens (after allocating the memory)
 * or NULL on errors
*/

char **initial_tokens(char **tokens)
{
	int i;

	tokens = (char **) malloc(sizeof(char *) * 32);
	for (i = 0; i < 32; i++)
	{
		tokens[i] = (char *) malloc(1024);
	}
	return (tokens);
}


/**
 * _strtok - splits a string into tokens
 * @s: the passed string to be splitted
 * @delim: the elimiter that separates the tokens
 *
 * Return: a pointer to an array of strings
*/

char **_strtok(char *s, const char *delim)
{
	char **tokens = NULL;
	size_t i = 0, pos = 0, numtok = 0, dellen;

	if (s == NULL || delim == NULL)
	{
		return (NULL);
	}
	tokens = initial_tokens(tokens);
	if (tokens == NULL)
	{
		return (NULL);
	}
	dellen = _strlen(delim);
	while (s[i])
	{
		if (s[i] == delim[0])
		{
			if (_strncmp(s + i, delim, dellen) == 0)
			{
				numtok++;
				_strncpy(tokens[numtok - 1], s + pos, i - pos);
				tokens[numtok - 1][i - pos] = '\0';
				pos += ((i - pos) + dellen);
			}
		}
		i++;
	}
	numtok += 2;
	_strncpy(tokens[numtok - 2], s + pos, i - pos);
	tokens[numtok - 1] = NULL;
	return (tokens);
}


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
