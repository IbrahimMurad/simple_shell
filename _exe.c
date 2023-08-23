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
	int rtrn_value = -1;
	char *cmd_pathname, *err_msg;

	err_msg = (char *) malloc(1024);
	err_msg[0] = '\0';
	err_msg = _strcat(_strcat(_strcat(err_msg, argv[0]), ": "), argv[1]);
	if (argv[1] == NULL)
	{
		return (-1);
	}
	cmd_pathname = _which(argv[1]);
	if (cmd_pathname == NULL)
	{
		err_msg = _strcat(err_msg, ": not found\n");
		write(STDERR_FILENO, err_msg, _strlen(err_msg));
		free(err_msg);
		return (-1);
	}
	else
	{
		rtrn_value = _exe(cmd_pathname, argv);
		free(err_msg);
		return (rtrn_value);
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
	int status;
	char *err_msg;

	err_msg = (char *) malloc(1024);
	err_msg[0] = '\0';
	err_msg = _strcat(_strcat(_strcat(err_msg, argv[0]), ": "), argv[1]);
	mypid = fork();
	if (mypid == 0)
	{
		if (execve(s, argv + 1, environ) == 0)
		{
			return (0);
		}
		else
		{
			perror(err_msg);
			return (-1);
		}
		free(s);
		free_strstr(argv);
	}
	else
	{
		wait(&status);
		free(err_msg);
		free(s);
		return (status);
	}
}
