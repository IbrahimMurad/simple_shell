#include "main.h"
/**
 * _strlen - returns the length of a string.
 * @s: the string
 *
 * Return: int (the length of the string @s)
 */

unsigned int _strlen(const char *s)
{
	unsigned int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}


/**
 * _strncmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the number of bytes to be copied
 *
 * Return: an integer (equals, less than or greater than zero)
 */

int _strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n && (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		if (s1[i] - s2[i] != 0)
		{
			break;
		}
	}
	if (i == n)
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}


/**
 * _strncpy - copies a string
 * @dest: the new string
 * @src: the string to be copied
 * @n: the number of bytes to be copied
 *
 * Return: a pointer to the new string
 */

char *_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	if (i == n)
	{
		dest[i] = '\0';
	}
	return (dest);
}


/**
 * _strcat - concatenates two strings.
 * @dest: The first string
 * @src: the second string
 *
 * Return: a pointer to the new string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = src[j];
	return (dest);
}


/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: an integer (equals, less than or greater than zero)
 */

int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		if (s1[i] - s2[i] != 0)
		{
			break;
		}
	}
	return (s1[i] - s2[i]);
}

