#include "main.h"


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
	if (tokens == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < 32; i++)
	{
		tokens[i] = (char *) malloc(1024);
		if (tokens[i] == NULL)
		{
			return (NULL);
		}
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

char **_strtok(char *s, char *delim)
{
	char **tokens = NULL;
	int i = 0, pos = 0, numtok = 0, dellen;

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
