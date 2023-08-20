#include "main.h"


/**
 * interactive_mode - starts the interactive mode
 *
 * Return: nothing
*/

void interactive_mode(char *s)
{
	char *prompt = "$ ";
	char buf[4096];
	ssize_t num_of_read_bytes, written;
	char *argv[32];

	while (1)
	{
		argv[0] = s;
		written = write(STDOUT_FILENO, prompt, 2);
		if (written == -1)
		{
			perror(s);
		}
		num_of_read_bytes = _getline(buf, STDIN_FILENO);
		if (num_of_read_bytes == -1)
		{
			printf("Couldn't read from user.\n");
			return;
		}
		if (num_of_read_bytes > 0)
		{
			get_argv(argv + 1, buf);
			check_cmd(argv);
		}
	}
}
