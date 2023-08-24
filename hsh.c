#include "main.h"


/**
 * my_hsh - starts the shell in interactive and non-interactive modes
 * @s: the running programme's name
 *
 * Return: nothing
*/

int my_hsh(char *s)
{
	int rtrn_value;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			rtrn_value = interactive_mode(s);
		}
		else
		{
			rtrn_value = non_interactive_mode(s);
			return (rtrn_value);
		}
	}
}

/**
 * interactive_mode - starts the interactive mode
 * @s: the running programme's name
 *
 * Return: nothing
*/

int interactive_mode(char *s)
{
	char *prompt = "#cisfun$ ";
	char *buf = NULL;
	ssize_t num_of_read_bytes;
	int rtrn_value = 0;

	if (write(STDOUT_FILENO, prompt, 9) == -1)
	{
		perror(s);
		return (errno);
	}
	buf = (char *) malloc(4096);
	num_of_read_bytes = _getline(buf, STDIN_FILENO);
	if (num_of_read_bytes == -1)
	{
		write(STDOUT_FILENO, "Couldn't read from user.\n", 26);
		free(buf);
		exit(2);
	}
	if (num_of_read_bytes > 0)
	{
		rtrn_value = excute_line(s, buf);
		return (rtrn_value);
	}
	return (rtrn_value);
}


/**
 * non_interactive_mode - starts the non-interactive mode
 * @s: the running programme's name
 *
 * Return: nothing
*/

int non_interactive_mode(char *s)
{
	char *buf = NULL;
	ssize_t num_of_read_bytes;
	int rtrn_value = 0;

	buf = (char *) malloc(4096);
	num_of_read_bytes = _getline(buf, STDIN_FILENO);
	if (num_of_read_bytes == -1)
	{
		write(STDOUT_FILENO, "Couldn't read from user.\n", 26);
		free(buf);
		exit(1);
	}
	if (num_of_read_bytes > 0)
	{
		rtrn_value = excute_line(s, buf);
		return (rtrn_value);
	}
	return (rtrn_value);
}
