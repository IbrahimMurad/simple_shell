#include "main.h"

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
