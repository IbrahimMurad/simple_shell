#include "main.h"


/**
 * interactive_mode - starts the interactive mode
 *
 * Return: nothing
*/

void interactive_mode(void)
{
	char *prompt = "$ ";
	char buf[4096];
	ssize_t num_of_read_bytes;
	char *argv[32];

	_environ = set_my_env();
	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		num_of_read_bytes = _getline(buf, STDIN_FILENO);
		if (num_of_read_bytes == -1)
		{
			printf("Couldn't read from user.\n");
			return;
		}
		if (num_of_read_bytes > 0)
		{
			get_argv(argv, buf);
			check_cmd(argv);
		}
	}
}
