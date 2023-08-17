#include "main.h"

/**
 * main - starting point
 * 
 * Return: the exit parameter if passed or 0 if not
*/

int main(int ac, char *av[], char *env[])
{
	if (ac == 1)
	{
		prompt();
	}
	else
	{
		_exe(av + 1);
	}
	exit(0);
}