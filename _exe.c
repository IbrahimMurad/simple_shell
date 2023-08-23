#include "main.h"

/**
 * _which - looks for the passed command
 * @cmd: the command to look for
 *
 * Return: 0 if found and -1 if not
*/

char *_which(char *cmd)
{
	strset *temp, *head = NULL;
	char *full_path_cmd = NULL;
	struct stat st;

	if (stat(cmd, &st) == 0)
	{
		return (_strdup(cmd));
	}
	head = PATHset();
	if (head == NULL)
	{
		return (NULL);
	}
	temp = head;
	while (temp)
	{
		free(full_path_cmd);
		full_path_cmd = str_concat(temp->data, "/", cmd);
		if (stat(full_path_cmd, &st) == 0)
		{
			free_str_list(head);
			return (full_path_cmd);
		}
		temp = temp->next;
	}
	free(full_path_cmd);
	free_str_list(head);
	return (NULL);
}



/**
 * before_exe - uses which to find the path of the command
 * and deals with errors if command is not found
 * @argv: the array of arguments
 *
 * Return:  0 if excuted successfully
 * -1 if failed
*/

int before_exe(char *argv[])
{
	char *cmd_pathname;

	cmd_pathname = _which(argv[1]);
	if (cmd_pathname == NULL)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		print_count();
		argv[1] = _strcat(argv[1], ": not found\n");
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		free(cmd_pathname);
		return (errno);
	}
	else
	{
		errno = _exe(cmd_pathname, argv);
		return (errno);
	}
}

/**
 * _exe - excutes an array of arguments
 * @argv: the array of arguments
 * @s: a string that will work as the first arg in execve
 *
 * Return:  0 if excuted successfully
 * -1 if failed
*/

int _exe(char *s, char *argv[])
{
	pid_t mypid;
	int status, rtrn_value = 2;

	mypid = fork();
	if (mypid == 0)
	{
		if (execve(s, argv + 1, environ) == 0)
		{
			errno = 0;
			return (errno);
		}
		else
		{
			errno = 2;
			return (errno);
			free(s);
			free_strstr(argv);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			rtrn_value = WEXITSTATUS(status);
		errno = rtrn_value;
		free(s);
		return (errno);
	}
}
