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
