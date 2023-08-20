#include "main.h"

/**
 * str_concat - concatenates three strings.
 * @s1: the first string
 * @s2: the second string
 * @s3: the third string
 *
 * Return: a pointer to the newly allocated space in memory
 * which contains the contents of s1, followed by the contents of s2
 * and null terminated
 */

char *str_concat(char *s1, char *s2, char *s3)
{
	char *ptr;
	unsigned int i, size1, size2, size3, size;

	if (s1 == NULL)
		size1 = 0;
	else
		size1 = _strlen(s1);
	if (s2 == NULL)
		size2 = 0;
	else
		size2 = _strlen(s2);
	if (s3 == NULL)
		size3 = 0;
	else
		size3 = _strlen(s3);
	size = size1 + size2 + size3;
	ptr = (char *) malloc(size + 1);
	for (i = 0; i < size1; i++)
	{
		ptr[i] = s1[i];
	}
	for (; i < size1 + size2; i++)
	{
		ptr[i] = s2[i - size1];
	}
	for (; i < size; i++)
	{
		ptr[i] = s3[i - size1 - size2];
	}
	ptr[i] = '\0';
	return (ptr);
}
