/**
 * _strncpy - copies a string
 * @dest: the new string
 * @src: the string to be copied
 * @n: the number of bytes to be copied
 *
 * Return: a pointer to the new string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
