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
	if (_strcmp(argv[1], "exit") == 0)
	{
		my_exit(argv);
	}
	else if (_strcmp(argv[1], "env") == 0)
	{
		_printenv();
	}
	else
	{
		_exe(argv);
	}
}
