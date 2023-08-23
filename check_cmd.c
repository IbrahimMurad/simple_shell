#include "main.h"


#define EXIT 0
#define ENV 1
#define SETENV 2
#define UNSETENV 3
#define CD 4

/**
 * which_command - checks the passed command to see
 * if it is a buit-in command or else.
 * @s: the passed command
 *
 * Return: an integer indicating to the command
*/
int which_command(char *s)
{
	int i;
	char *my_Builtin_cmd[] = {"exit", "env", "setenv", "unsetenv", "cd"};

	for (i = 0; i < 5; i++)
	{
		if (_strcmp(s, my_Builtin_cmd[i]) == 0)
		{
			return (i);
		}
	}
	return (6);
}


/**
 * check_cmd - checks the first argument of the array
 * if it is a built-in comand or a custum implemented command
 * @argv: an array consists of the command and the arguments
 *
 * Return: nothing
*/

int check_cmd(char *argv[])
{
	int curr_cmd, rtrn_value;

	curr_cmd = which_command(argv[1]);
	switch (curr_cmd)
	{
		case EXIT:
			rtrn_value = my_exit(argv);
			break;
		case ENV:
			rtrn_value = _env(argv);
			break;
		case SETENV:
			rtrn_value = excute_setenv(argv);
			break;
		case UNSETENV:
			rtrn_value = excute_unsetenv(argv);
			break;
		case CD:
			rtrn_value = _cd(argv);
			break;
		default:
			rtrn_value = before_exe(argv);
			break;
	}
	return (rtrn_value);
}
