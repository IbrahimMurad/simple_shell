#include "main.h"





/**
 * _which - looks for the passed command
 * @cmd: the command to look for
 *
 * Return: 0 if found and -1 if not
*/

char *_which(char *cmd)
{
	strset *temp = PATHset();
	char *full_path_cmd = NULL;
	struct stat st;

	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
		{
			return (cmd);
		}
		else
		{
			return (NULL);
		}
	}
	while (temp != NULL)
	{
		free(full_path_cmd);
		full_path_cmd = str_concat(temp->data, "/", cmd);
		if (stat(full_path_cmd, &st) == 0)
		{
			return (full_path_cmd);
		}
		temp = temp->next;
	}
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
	int s;

	argv[0] = _which(argv[0]);
	if (argv[0] == NULL)
	{
		perror("./hsh");
		return (-1);
	}
	else
	{
		mypid = fork();
		if (mypid == 0)
		{
			if (execve(argv[0], argv, NULL) == 0)
			{
				return (0);
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			wait(&s);
			return (0);
		}
	}
	return (-1);
}
