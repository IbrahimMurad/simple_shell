#include "main.h"

/**
 * _getline - gets a line from stream
 * (a line is terminated by a new line or EOF)
 * @buf: a buffer to store the line
 * @fd: the file descriptor to the file to read from
 *
 * Return: the number of read bytes or -1 on fail
 * or 0 if its EOF
*/

int _getline(char buf[], int fd)
{
	int numOfBytes;

	numOfBytes = read(fd, &buf, 4096);
	buf[numOfBytes] = '\0';
	return (numOfBytes);
}
