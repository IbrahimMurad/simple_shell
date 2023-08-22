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

	tokens = (char **) malloc(sizeof(char *) * 64);
	if (tokens == NULL)
	{
		return (NULL);
	}
	dellen = _strlen(delim);
	while (s[i])
	{
		if (s[i] == delim[0])
		{
			if (s[i + 1] == '\0')
				break;
			if (_strncmp(s + i, delim, dellen) == 0)
			{
				tokens[numtok] = (char *) malloc(1024);
				_strncpy(tokens[numtok], s + pos, i - pos);
				tokens[numtok][i - pos] = '\0';
				if ((i - pos) != 0)
				{
					numtok++;
				}
				else
				{
					free(tokens[numtok]);
				}
				pos += ((i - pos) + dellen);
				i += (dellen - 1);
			}
		}
		i++;
	}
	tokens[numtok] = (char *) malloc(1024);
	_strncpy(tokens[numtok], s + pos, i - pos);
	tokens[numtok + 1] = NULL;
	return (tokens);
}

/**
 * free_strstr - frees an array of strings allocated by strtok
 * @tokens: a pointer to the array
 *
 * Return: nothing
*/

void free_strstr(char **tokens)
{
	int i;

	for (i = 0; i < 64 && tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/**
 * get_argv - converts a string into an array of tokens
 * @av: an array of strings in which the tokens will be stored
 * @buf: the string to read from
 *
 * Return: a pointer to av
*/

char **get_argv(char **av, char *buf)
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

/**
 * free_argv - frees the memories allocated inside an array of strings
 * @argv: the array of strings
 *
 * Return: nothing
*/

void free_argv(char *argv[])
{
	int i;

	for (i = 0; i < 64 && argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
}
