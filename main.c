#include "main.h"

/**
 * main - starting point
 * @ac: the number of passed arguments
 * @av: an array of strings that holds the passed arguments
 *
 * Return: the exit parameter if passed or 0 if not
*/

int main(int ac, char *av[])
{
	int fd;
	ssize_t readed;
	char *buf = NULL, *err_msg_h = NULL, *err_msg_e = NULL;

	set_my_env();
	errno = 0;
	if (ac == 1)
	{
		my_hsh(av[0]);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			err_msg_h = str_concat(av[0], ": ", "0: cannot open ");
			err_msg_e = str_concat(av[1], ": No such file\n", NULL);
			write(STDERR_FILENO, err_msg_h, _strlen(err_msg_h));
			write(STDERR_FILENO, err_msg_e, _strlen(err_msg_e));
			free(err_msg_h);
			free(err_msg_e);
			return (2);
		}
		buf = (char *) malloc(4096);
		readed = read(fd, buf, 4096);
		if (readed == 0)
		{
			free(buf);
			close(fd);
		}
		else
		{
			excute_line(av[0], buf);
			close(fd);
		}
	}
	free_myenv();
	return (0);
}
