#include "main.h"

/**
 * numtostr - prints an integer according to the base number
 * @buf: the buffer where the number is written
 * @num: the number to be printed
 *
 * Return: the number of printed bytes
 */

char *numtostr(char *buf, int num)
{
	char c[] = "0123456789";
	char cstr[2];

	if (num < 10)
	{
		cstr[0] = c[num];
		cstr[1] = '\0';
		buf = _strcat(buf, cstr);
	}
	else
	{
		buf = numtostr(buf, num / 10);
		cstr[0] = c[num % 10];
		cstr[1] = '\0';
		buf = _strcat(buf, cstr);
	}
	return (buf);
}
