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
	set_my_env();
	if (ac == 1)
	{
		interactive_mode(av[0]);
	}
	else
	{
		check_cmd(av);
	}
	exit(0);
}
