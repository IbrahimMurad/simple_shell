#include "main.h"

/**
 * prompt - starts the interactive mode
 *
 * Return: nothing
*/

void prompt(void)
{
	char *prompt_sign = "$";
	char buf[4096];
	int num_of_read_bytes;
	char *argv[32];

	while (1)
	{
		write(STDIN_FILENO, &prompt_sign, 1);
		num_of_read_bytes = _getline(buf, STDIN_FILENO);
		if (num_of_read_bytes == -1)
		{
			printf("Couldn't read from user.\n");
			return;
		}
		if (num_of_read_bytes == 0)
		{
			return;
		}
		get_argv(argv, buf);
	}
}
