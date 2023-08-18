#include "main.h"


/**
 * main - starting point
 * @ac: the number of passed arguments
 * @av: an array of strings that holds the passed arguments
 *
 * Return: the exit parameter if passed or 0 if not
*/

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		interactive_mode();
	}
	else
	{
		_exe(av + 1);
	}
	exit(0);
}
