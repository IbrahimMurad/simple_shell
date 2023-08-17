#include "main.h"

/**
 * prompt - starts the interactive mode
 * 
 * Return: nothing
*/

void prompt(void)
{
	char *prompt_sign = "$";
	char *buf[4096];

	while (1)
	{
		write(STDIN_FILENO, &prompt_sign, 1);
		_getline(buf, STDIN_FILENO);
	}
}