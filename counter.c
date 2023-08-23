#include "main.h"

/**
 * print_count - prints the count of the current error
 *
 * Return: the last status
*/

void print_count(void)
{
	static int count = -1;
	char *buf;

	if (count == -1)
	{
		count = 0;
	}
	count++;
	buf = (char *) malloc(8);
	buf[0] = '\0';
	buf = numtostr(buf, count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buf, _strlen(buf));
	write(STDERR_FILENO, ": ", 2);
	free(buf);
}
