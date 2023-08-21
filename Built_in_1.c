#include "main.h"


/**
 * is_anumber - checks if the passed string is a legal number
 * @s: the string to be checked
 *
 * Return: 0 if it is a legal number
 * -1 if is an illigal number
*/

int is_anumber(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return (-1);
		}
	}
	return (0);
}


/**
 * sh_atoi - convets a string into a number
 * @s: the string to be converted into a number
 *
 * Return: the number
*/
int sh_atoi(char *s)
{
	int i, num = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		num *= 10;
		num += (s[i] - '0');
	}
	return (num);
}


/**
 * my_exit - exits the simple shell
 * @argv: the array of strings that holds
 * the exit command and its arguments
 *
 * Return: nothing
*/

void my_exit(char *argv[])
{
	int status;
	char newline = '\n';

	if (argv[2] == NULL)
	{
		status = 0;
	}
	else
	{
		if (is_anumber(argv[2]) == 0)
		{
			status = sh_atoi(argv[2]);
		}
		else
		{
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, argv[1], _strlen(argv[1]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, ": Illegal number: ", 18);
			write(STDERR_FILENO, argv[2], _strlen(argv[2]));
			write(STDERR_FILENO, &newline, 1);
			return;
		}
	}
	free_myenv(my_environ);
	exit(status);
}

/**
 * _env - prints the current environment to the screen
 *
 * Return: nothing
*/

void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
