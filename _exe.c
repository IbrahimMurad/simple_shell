#include "main.h"

/**
 * _which - looks for the passed command
 * @cmd: the command to look for
 *
 * Return: 0 if found and -1 if not
*/

char *_which(char *cmd)
{
	strset *temp;
	char *full_path_cmd = NULL;
	struct stat st;

	if (stat(cmd, &st) == 0)
	{
		return (cmd);
	}
	temp = PATHset();
	while (temp != NULL)
	{
		free(full_path_cmd);
		full_path_cmd = str_concat(temp->data, "/", cmd);
		if (stat(full_path_cmd, &st) == 0)
		{
			free_str_list(temp);
			return (full_path_cmd);
		}
		temp = temp->next;
	}
	free_str_list(temp);
	return (NULL);
}



/**
 * _exe - excutes an array of arguments
 * @argv: the array of arguments
 *
 * Return:  0 if excuted successfully
 * -1 if failed
*/

int _exe(char *argv[])
{
	pid_t mypid;
	int s, rtrn_value = -1;
	char *cmd_pathname;

	if (argv[1] == NULL)
	{
		return (-1);
	}
	cmd_pathname = _which(argv[1]);
	if (cmd_pathname == NULL)
	{
		write(STDERR_FILENO, "command not found\n", 19);
		return (-1);
	}
	mypid = fork();
	if (mypid == 0)
	{
		if (execve(cmd_pathname, argv + 1, NULL) == 0)
		{
			rtrn_value = 0;
			return (0);
		}
		else
		{
			perror(argv[1]);
			rtrn_value = -1;
			return (-1);
		}
		free(cmd_pathname);
		free_strstr(argv);
	}
	else
	{
		wait(&s);
		return (rtrn_value);
	}
}
