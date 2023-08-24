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
	if (buf[numOfBytes - 1] == '\n')
	{
		buf[numOfBytes - 1] = '\0';
	}
	else
	{
		buf[numOfBytes] = '\0';
		write(STDOUT_FILENO, "\n", 1);
	}
	return (numOfBytes);
}

/**
 * _strtok - splits a string into tokens
 * @tokens: an array to hold the tokens
 * @s: the passed string to be splitted
 * @delim: the elimiter that separates the tokens
 *
 * Return: a pointer to an array of strings
*/

char **_strtok(char *tokens[], char *s, const char *delim)
{
	char *temp_s;
	size_t i = 0;

	if (s == NULL)
	{
		tokens[0] = NULL;
		return (tokens);
	}
	temp_s = s;
	while (*temp_s)
	{
		tokens[i] = get_token(&temp_s, delim);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * get_token - gets the first encountered token
 * to give it to _strtok fun
 * @str_ptr: a passed by reference pointer to as string
 * @delim: the elimiter that separates the tokens
 *
 * Return: a pointer to an array of strings
*/

char *get_token(char **str_ptr, const char *delim)
{
	char *s = *str_ptr, *token = NULL;
	size_t dellen, i = 0, j = 0;

	dellen = _strlen(delim);
	while (s[i])
	{
		if (s[i] == delim[0])
		{
			if (_strncmp(s + i, delim, dellen) == 0)
			{
				i += (dellen - 1);
			}
		}
		else
		{
			token = (char *) malloc(1024);
			for (; s[i] != '\0' && _strncmp(s + i, delim, dellen) != 0; i++)
			{
				token[j] = s[i];
				j++;
			}
			token[j] = '\0';
			(*str_ptr) = s + i;
			return (token);
		}
		i++;
	}

	(*str_ptr) = s + i;
	return (NULL);
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
	av = _strtok(av, buf, " ");
	free(buf);
	return (av);
}
