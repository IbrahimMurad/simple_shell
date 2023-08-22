#include "main.h"


/**
 * interactive_mode - starts the interactive mode
 * @s: the running programme's name
 *
 * Return: nothing
*/

void interactive_mode(char *s)
{
	char *prompt = "$ ";
	char *buf = NULL;
	ssize_t num_of_read_bytes;

	buf = (char *) malloc(8192);
	while (1)
	{
		if (write(STDOUT_FILENO, prompt, 2) == -1)
		{
			perror(s);
		}
		num_of_read_bytes = _getline(buf, STDIN_FILENO);
		if (num_of_read_bytes == -1)
		{
			write(STDOUT_FILENO, "Couldn't read from user.\n", 26);
			exit(1);
		}
		if (num_of_read_bytes > 0)
		{
			excute_line(s, buf);
		}
	}
}


/**
 * excute_line - takes a line and excute its content
 * @running_prog: the name of the running program
 * @line: the line to be executed
 *
 * Return: 0 on success or -1 on error
*/

int excute_line(char *running_prog, char *line)
{
	char **lines;
	int i = 0, rtrn_value;

	if (_strchr(line, '#'))
	{
		*(_strchr(line, '#')) = '\0';
		rtrn_value = excute_line(running_prog, line);
	}
	else if (_strchr(line, ';'))
	{
		lines = _strtok(line, ";");
		while (lines[i])
		{
			rtrn_value = excute_line(running_prog, lines[i]);
			i++;
		}
	}
	else if (_strchr(line, '&'))
	{
		lines = _strtok(line, "&&");
		while (lines[i])
		{
			rtrn_value = excute_line(running_prog, lines[i]);
			i++;
		}
	}
	else
	{
		rtrn_value = excute_one_cmd(running_prog, line);
	}
	return (rtrn_value);
}


/**
 * excute_one_cmd - takes a line that holds only one command
 * and excute its content
 * @prog_name: the name of the running program
 * @command_line: the line to be executed
 *
 * Return: 0 on success or -1 on error
*/

int excute_one_cmd(char *prog_name, char *command_line)
{
	char *argv[64];
	int rtrn_value;

	argv[0] = prog_name;
	get_argv(argv + 1, command_line);
	rtrn_value = _exe(argv);
	return (rtrn_value);
}
