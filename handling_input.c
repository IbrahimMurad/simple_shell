#include "main.h"


/**
 * excute_line - takes a line and excute its content
 * @running_prog: the name of the running program
 * @line: the line to be executed
 *
 * Return: 0 on success or -1 on error
*/

int excute_line(char *running_prog, char *line)
{
	char **lines, *separator[] = {"#", "\n", ";", "&&"};
	int i = 0, rtrn_value, sep_index, sep_i_str;

	sep_index = get_separator(line, &sep_i_str);
	switch (sep_index)
	{
		case 0:
			*(line + sep_i_str) = '\0';
			rtrn_value = excute_line(running_prog, line);
			break;
		case 1:
		case 2:
		case 3:
			lines = _strtok(line, separator[sep_index]);
			while (lines[i])
			{
				rtrn_value = excute_line(running_prog, lines[i]);
				i++;
			}
			break;
		default:
			rtrn_value = excute_one_cmd(running_prog, line);
			break;
	}
	return (rtrn_value);
}


/**
 * get_separator - gets the separators, #, newline, ; and &&
 * @buf: the buffer to chech into
 * @index: a pointer to a passed integer
 * so that we can change its value to the index of the separator
 * in the buffer
 *
 * Return: a string that containes one of the separators if found
 * or NULL if non found
*/
int get_separator(char *buf, int *index)
{
	char *separator[] = {"#", "\n", ";", "&&"};
	int i = 0, j;

	*index = 0;
	if (buf == NULL)
	{
		return (4);
	}
	while (buf[i])
	{
		for (j = 0; j < 4; j++)
		{
			if (buf[i] == separator[j][0])
			{
				*index = i;
				return (j);
			}
		}
		i++;
	}
	return (4);
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
	if (argv[1] == NULL)
	{
		return (0);
	}
	rtrn_value = check_cmd(argv);
	free_argv(argv + 1);
	return (rtrn_value);
}
