#include "main.h"

/**
 * _strdup -  allocate a new space in memory,
 * and fills it with a copy of the string given as a parameter.
 * @str: the given string
 *
 * Return: a pointer to a newly allocated space in memory
 */

char *_strdup(char *str)
{
	char *ptr;
	unsigned int i;
	size_t size;

	if (str == NULL)
	{
		return (NULL);
	}
	size = _strlen(str);
	ptr = (char *) malloc(size + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';
	return (ptr);
}


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

char *str_concat(const char *s1, const char *s2, const char *s3)
{
	char *ptr;
	size_t i, size1, size2, size3, size;

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


/**
 * _strchr - locates a character in a string
 * @s: the string in which the charachter to be searched is
 * @c: the charachter to be searced
 *
 * Return: a pointer where the character is stored
 */

char *_strchr(char *s, const char c)
{
	int i;
	char *temp = NULL;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	if (c == '\0')
	{
		return (&s[i]);
	}
	return (temp);
}
