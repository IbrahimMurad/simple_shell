#include "main.h"

/**
 * _which - looks for the passed command
 * @cmd: the command to look for
 *
 * Return: 0 if found and -1 if not
*/

char *_which(char *cmd)
{
	strset *temp = my_PATH;
	char *full_path_cmd;
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
		full_path_cmd = str_concat(temp->data, "/", cmd);
		if (stat(full_path_cmd, &st) == 0)
		{
			return (full_path_cmd);
		}
		temp = temp->next;
	}
	return (NULL);
}
