#include "main.h"

/**
 * check_cmd - checks the first argument of the array
 * if it is a built-in comand or a custum implemented command
 * @argv: an array consists of the command and the arguments
 *
 * Return: nothing
*/

void check_cmd(char *argv[])
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		free_myenv(_environ);
		exit(0);
	}
	else
	{
		_exe(argv);
	}
}
