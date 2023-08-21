#include "main.h"

/**
 * _setenv - adds a variable to the environment (NAME=VALUE)
 * @argv: an array of strings that holds the running program's name
 * the command and its argumens
 *
 * Return: an address to the new variable, or NULL if it failed
 */

myenv *_setenv(char *argv[])
{
	myenv *VAR;
	myenv *temp = my_environ;

	while (temp)
	{
		if (_strcmp(argv[2], temp->name) == 0)
		{
			free(temp->value);
			temp->value = _strdup(argv[3]);
		}
		temp = temp->next;
	}
	VAR = (myenv *) malloc(sizeof(myenv));
	if (VAR == NULL)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		perror(argv[1]);
		return (NULL);
	}
	VAR->name = _strdup(argv[2]);
	VAR->value = _strdup(argv[3]);
	VAR->next = NULL;
	temp = VAR;
	return (VAR);
}

/**
 * _unsetenv - removes a variable from the current environment
 * @argv: an array of strings that holds the running program's name
 * the command and its argumens
 * (where the third argument is the variable's name)
 *
 * Return: an address to the new variable, or NULL if it failed
 */

int _unsetenv(char *argv[])
{
	myenv *current, *before;

	current = my_environ;
	if (argv[2] == NULL)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "no pased vaiables\n", 18);
	}
	before = current;
	current = current->next;
	while (current)
	{
		if (_strcmp(argv[2], current->name) == 0)
		{
			before->next = current->next;
			free(current->name);
			free(current->value);
			free(current);
			return (0);
		}
		current = current->next;
	}
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv[1], _strlen(argv[1]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv[2], _strlen(argv[2]));
	write(STDERR_FILENO, "vaiable is not in the current environment\n", 42);
	return (-1);
}
