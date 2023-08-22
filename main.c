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
		my_hsh(av[0]);
	}
	else
	{
		excute_line(av[0], av[1]);
	}
	free_myenv();
	return (0);
}
