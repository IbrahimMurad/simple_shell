#include "main.h"

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
		}
	}
	return (-1);
}